#!/usr/common/bin/python
#!/usr/bin/env python

# $Id: cb.py,v 1.1 2003/08/13 17:41:23 gruber Exp $

# $Log: cb.py,v $
# Revision 1.1  2003/08/13 17:41:23  gruber
# modified copybook to pads script
#
# Revision 1.1  2003/05/08 17:23:29  gruber
# changed array elts member name to elts, added copybook scripts-examples-tests, changed e_string read functions to always copy so that underlying data is not munged
#
# Revision 1.6  2003/03/18 17:50:44  ark
# Complain on stderr when encountering an undefined or ambiguous identifier.
#
# Revision 1.5  2003/03/12 20:08:48  ark
# Reduced the amount of noise in the initial output.
#
# Revision 1.4  2003/03/12 20:02:28  ark
# Program now prints its name and revision level on stderr when it starts.
#
# Revision 1.3  2003/03/12 19:56:52  ark
# Changed "ID" to "Id" in header comment.
#
# Revision 1.2  2003/03/12 19:56:06  ark
# Implemented a symbol table, via the Idnode and Idmap classes, so that
# names are found in the right place in the hierarchy, and ambiguities
# are detected as appropriate.
#
# Revision 1.1  2003/03/10 22:58:49  ark
# Initial revision
#

from grasp import *
import operator, re, string, sys

def tag(t):
   return lambda x: (t, x)

# A pattern to match a keyword.  Keywords can potentially take more
# than one form, and in any event, we care only about the fact that we
# matched them.  This code is equivalent to:
#
#    r = Lit(first)
#    for i in rest:
#       r = r | Lit(i)
#    return r
#
def keyword(first, *rest):
   return reduce(Alt, map(Lit, rest), Lit(first))

# A pattern to match an optional element  We try the pattern first.
def opt(pat):
   return pat | Len(0)

number = Token(Regexp(r"\d+")) % int
blank = Regexp(r"[ \t]+")               # not a token
optblank = Regexp(r"[ \t]*")            # also not a token

# Cobol identifiers.  We allow lowercase even though we shouldn't,
# because some of the code uses it.  Ditto embedded underscores, colons,
# and ampersands!
ident = Token(Regexp(r"[-a-zA-Z0-9_:&]*[a-zA-Z][-A-Za-z0-9_:&]*"))

# "usage" clause
usage_kw = (
    keyword("COMPUTATIONAL", "COMP", "BINARY")     % 'c'  |
    keyword("COMPUTATIONAL-1", "COMP-1") % 'c1' |
    keyword("COMPUTATIONAL-2", "COMP-2") % 'c2' |
    keyword("COMPUTATIONAL-3", "COMP-3", "PACKED-DECIMAL") % 'c3' |
    keyword("DISPLAY")                   % 'd'  )

usage = opt(keyword("USAGE") + blank) + usage_kw % tag('usage')

# "redefines" clause
redefines = keyword("REDEFINES", "REDEFINED") + blank + ident % tag('redef')

# "picture" clause
picture = keyword("PICTURE", "PIC") + blank + \
          Token(Regexp(r"[0-9A-Z()]+")) % tag('pic')

# "value" clause
simplevalue = Token(Regexp(r"[+-]?\d+")) | \
              "'" + Token(Regexp(r"[^']*") / "''") + "'" | \
              Token(keyword("ZERO", "ZEROS", "ZEROES", "SPACE", "SPACES",
                            "HIGH-VALUE", "HIGH-VALUES", "LOW-VALUE", "LOW-VALUES"))
singlevalue = simplevalue | \
              simplevalue + blank + keyword("THRU", "THROUGH") + blank + simplevalue
valdelim = optblank + "," + optblank | blank
value = "VALUE" + opt("S") + blank + (singlevalue / valdelim) % \
        (lambda *args: ('value', args))

# "occurs" clause
occurs = "OCCURS" + blank + \
         (number % tag('hi') |
          number % tag('lo') + blank + "TO" + blank + number % tag('hi')) + \
          opt(blank + "TIMES") + \
          opt(blank + "DEPENDING" + blank + "ON" + blank + ident % tag('dep')) + \
          opt(blank + "INDEXED" + blank + "BY" + blank + ident % tag('index'))

clause = usage | redefines | picture | value | occurs

stmtpat = optblank + (number % tag('level')) + blank + (ident % tag('id')) + \
       Arbno(blank + clause) + optblank + "." + optblank + Rpos(0)


class Idnode(object):
   # Objects of this class represent identifiers.
   # At present, they are concrete datatypes -- i.e., no access functions.
   # Members:
   #
   #    level:    the level that appears in the Cobol declaration
   #    id:       the identifier
   #    new_id:   the identifier after mapping
   #    children: a list of the identifiers subsidiary to this one.
   def __init__(self, level, id, new_id):
      self.level, self.id, self.new_id = level, id, new_id
      self.children = []

   def add_child(self, child):
      assert isinstance(child, Idnode)
      assert child.level > self.level
      if self.children:
         if child.level != self.children[0].level:
            # I think the only way this can happen is with a data structure such as
            #
            #   01 A.
            #         03 B.
            #      02 C.
            #
            # We treat this as if it were
            #
            #   01 A.
            #      02 (dummy).
            #         03 B.
            #      02 C.
            #
            # We do this by creating a new node, making all of our present children
            # children of the new node, and then making this node our (only) child.
            assert child.level < self.children[0].level
            newnode = Idnode(child.level, "(dummy)", "(dummy)")
            newnode.children = self.children
            self.children = [newnode]
            assert child.level == self.children[0].level
      self.children.append(child)

   def treesearch(self, id):
      """Return a list of all the nodes that represent a given identifier"""
      if self.id == id:
         result = [self]
      else:
         result = []
      for i in self.children:
         result += i.treesearch(id)
      return result

   def childsearch(self, id):
      """Return a list of all the direct children of this node that represent
      a given identifier"""
      return [n for n in self.children if n.id == id]
  
class Idmap(object):

   table = string.maketrans("-", "_") # map Cobol identifiers to C identifiers

   def __init__(self):
      self.forest = Idnode(-1, "(root)", "(root)")
      self.trail = [self.forest]    # trail from root to current level
      self.stmt_count = 0

   def incr(self):
      """Increment the statement number"""
      self.stmt_count += 1

   def decr(self):
      """Decrement the statement number.  This sounds weird, but it is
      useful to have around in case we find a statement (such as an
      88-level declaration) that we are presently ignoring."""
      self.stmt_count -= 1

   def define(self, m):
      """The argument, m, is a match representing a statement.  This function
      defines the identifier represented by m['id'] at the level represented
      by m['level']."""

      id, level = m['id'], m['level']
      new_id = string.translate(id, self.table, ':&') + '_' + `self.stmt_count`

      # An Idnode that represents the element being defined.
      newnode = Idnode(level, id, new_id)

      # Walk back toward the root, discarding items from the trail,
      # until we find a node with level <= ours
      while level < self.trail[-1].level:
         self.trail.pop()

      # If the level is < ours, the new node is a child of the one we found
      if self.trail[-1].level != level:
         self.trail[-1].add_child(newnode)
         self.trail.append(newnode)
      # Otherwise, the new node is a sibling of the one we found
      else:
         self.trail[-2].add_child(newnode)
         self.trail[-1] = newnode

      # Now, self.trail[-1] represents a node at our level
      assert level == self.trail[-1].level

      return new_id

   def map(self, id):
      """Search the whole tree for a unique occurrence of an identifier"""
      global errors
      for i in range(len(self.trail) - 1, -1, -1):
         r = self.trail[i].treesearch(id)
         if len(r) == 1:
            return r[0].new_id
         if len(r) > 1:
            print >>sys.stderr, "Identifier", id, "is ambiguous"
            errors += 1
            return "?ambiguous?" + id
      print >>sys.stderr, "Identifier", id, "not found"
      errors += 1
      return "??" + id

   def map_sibling(self, id):
      """Search our siblings for a unique occurrence of an identifier"""
      global errors
      r = self.trail[-2].childsearch(id)
      if len(r) == 1:
         return r[0].new_id
      if len(r) > 1:
         print >>sys.stderr, "Identifier", id, "is ambiguous"
         errors += 1
         return "?ambiguous?" + id
      print >>sys.stderr, "Identifier", id, "not found"
      errors += 1
      return "??" + id

def dumpmap(im, file = sys.stdout):
   dumpnode(im.forest, im.trail, file)

def dumpnode(node, trail, file):
   print >>file, " "*(node.level + 1), node.level, node.id, node.new_id,
   if node in trail:
      print >>file, "[%d]" % trail.index(node),
   print
   for n in node.children:
      dumpnode(n, trail, file)
   
# Code to unravel the internal representation of a line
def unravel(idm, rep, startline, lineno):
   m = dict(rep)                        # Simplify searching
   # We ignore 88-level clauses at present
   if m['level'] == 88:
      idm.decr()
      return None
   
   # Put the name in the symbol table, and find its new representation
   mapped_name = idm.define(m)

   # If there's a 'redefines' clause, we handle it by creating a prefix
   # ('rp' for "redefines prefix") that describes it.  We will then append
   # the rest of the description to this prefix, if any
   rp = ""
   if 'redef' in m:
      rp = `startline` + ' r %s %s\n' % (mapped_name, idm.map_sibling(m['redef']))

   # Is there an "occurs" clause?
   sz = 1
   if 'hi' in m:
      sz = m['hi']
      # Is there a "depending" clause?
      if 'dep' in m:
         lo = 0
         if 'lo' in m:
            lo = m['lo']
         sz = `sz` + "!" + `lo` + "!" + idm.map(m['dep'])
      
   # clause with no picture
   if 'pic' not in m:
      return rp + `startline` + ' %02d %s %s none' % (m['level'], mapped_name, sz)

   # Otherwise, there is a picture
   return rp + `startline` + ' %02d %s %s %s' % (m['level'], mapped_name, sz, decode_pic(m))
   

# Picture elements -- when evaluated, they yield the corresponding length
def picseq(c):
   element = Token(c) % 1 | Lit(c) + "(" + number + ")"
   return (element + Arbno(element)) % \
          (lambda *seq: reduce(operator.add, seq, 0))

# Figure out what kind of picture we have
pic_pat = (
   Len(0) % "X" + picseq('X') |
   (Len(0) % "i" | Lit("S") % "is") + picseq('9') |
   (Len(0) % "f" | Lit("S") % "fs") +
     (picseq('9') + 'V' + picseq('9') |
      picseq('9') + 'V' + Len(0) % 0 |
      Len(0) % 0 + 'V' + picseq('9'))
   ) + Rpos(0)

# Decode the picture corresponding to a given descriptor
# A picture clause is assumed to exist.
def decode_pic(desc):
   p = list(pic_pat.match(desc['pic']))
   if len(p) != 1:
      return "??" + p
   type = p[0].evaluate()    # the "type" corresponding to the picture
   if 'usage' in desc:
      u = desc['usage']
      # If it's a computational field, the type will be a list
      # of the form [type, precision].
      if u == 'c3':                     # decimal field?
         t = type[0]
         t = t[0].upper() + t[1:]
         # The documentation suggests that signed decimal fixed point
         # should be represented as type "Fs".  In fact, however, it
         # is "F".
         if t == "Fs":
            t = "F"
         type[0] = t
      elif u == 'c':                    # binary field?
         t = type[0]
         if t[0] == 'i':                # integer without radix point
            t = 'b' + t[1:]
         elif t[0] == 'f':              # integer with radix point
            t = 'B' + t[1:]
         type[0] = t
   return ' '.join(map(str, type))


# Map all the characters in a string to their uppercase equivalents
# except for characters within single quotes.  This is needed because
# some of the input copybooks have lower- or mixed-case contents.
def foldcase(s):
   s = s.split("'")
   for i in range(0, len(s), 2):
      s[i] = s[i].upper()
   return "'".join(s)


# The driver stuff starts here.  When this program gets too big, the
# logical next step will be to make the parsing code into a separate
# module.


print >>sys.stderr, "copybook.py", "$Revision: 1.1 $".split()[1], \
      "$Date: 2003/08/13 17:41:23 $".split()[1]

errors = 0

def complain(startline, lineno, stmt, message):
   global errors
   if lineno == startline:
      print >>sys.stderr, "Line", `lineno` + ":", message
   else:
      print >>sys.stderr, "Lines", `startline` + '-' + `lineno` + ":", message
   print >>sys.stderr, stmt
   errors += 1

# A regular expression to check for end of statement
endstmt = re.compile(r"([^.']|'[^']*')*\.")

# Keep track of the state of identifiers
idm = Idmap()
   
lineno = 0
stmt = ''
for rawline in sys.stdin:
   lineno += 1

   # The following heuristics deal with tabs.  I wish I could figure out
   # an easier way of doing so.

   # If the line has no tabs at all in it, we assume it's an old-style
   # Cobol statement and discard positions 1-6 and 73-80.
   if rawline.find('\t') < 0:
      line = rawline[6:72]
   else:
      # We have at least one tab.  Convert all tabs to spaces.
      line = string.expandtabs(rawline)
   
      # If the first six characters are neither blanks nor tabs,
      # we assume that they're Cobol identification numbers and delete them,
      # along with any sequence numbers in positions 73-80.
      if line.find(' ', 0, 6) < 0:
         line = line[6:72]

   # Finally, we cut leading and trailing blanks
   line = string.strip(line)

   # check for empty line, "SKIP" line, or comment
   if line != "" and line[0] != "*" and line[0:4] != "SKIP":
      # OK, it's real -- tack it onto our statement
      if stmt:
         stmt += " " + line
      else:
         startline = lineno
         stmt = line
      # Have we reached the end of the statement?
      # Ideally, we would like to check if the last character is a period,
      # which we would do by writing     if line[-1:] == ".":    here.
      # However, some of these files have junk after the period, so we'll just
      # look for a period (outside quotes, of course) and use that as our end marker.
      # We'll trash everything after the period.
      match = endstmt.match(stmt)
      if match:
         idm.incr()
         stmt = foldcase(match.group())
         foundmatch = False
         for m in stmtpat.match(stmt):
            if foundmatch:
               complain(startline, lineno, stmt, "Ambiguous statement")
            else:
               foundmatch = True
               result = unravel(idm, m.evaluate(), startline, lineno)
               if result is not None:
                  print result
         # end of for loop
         if not foundmatch:
            complain(startline, lineno, stmt, "Cannot parse statement")
         stmt = ""

if stmt:
   complain(startline, lineno, stmt, "Last statement does not end with a period")

sys.exit(errors)
