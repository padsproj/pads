#!/usr/bin/env python

# $Id: grasp.py,v 1.1 2003/05/08 17:23:29 gruber Exp $

# $Log: grasp.py,v $
# Revision 1.1  2003/05/08 17:23:29  gruber
# changed array elts member name to elts, added copybook scripts-examples-tests, changed e_string read functions to always copy so that underlying data is not munged
#
# Revision 1.7  2003/03/12 20:15:59  ark
# Restored the log comments from earlier versions.
#
# Note that "Group" was changed back to "Token" in an earlier version
# but not mentioned.
#
# Revision 1.6  2003/03/12 19:58:10  ark
# Added "Id" and "Log" comments to the beginning of the file.
#
# Revision 1.5  2003/02/19 19:56:00  ark
# Major overhaul, including fixing the bug that was causing parsing to
# fail in odd ways; allowing the right operand of % to take a
# non-callable, etc.
# This is probably the first version that's usable for anything serious.
#
# Revision 1.4  2002/11/13 21:59:18  ark
# Continued refactoring; changed Token to Group (and similarly for token)
#
# Revision 1.3  2002/10/17 21:57:58  ark
# Major refactoring -- introduced Match structure to hold result of a
# match, reworked the internals to always take begin as part of the
# input and return end.
# 
# Added Token class and associated bookkeeping.
#
# Revision 1.2  2002/09/04 01:12:53  ark
# Factored out the traversal code from the explanation code
#
# Revision 1.1  2002/09/01 20:09:49  ark
# Initial revision
#

from __future__ import generators
import sys, operator, re

if sys.hexversion < 0x02020000:
    print "I'm sorry, but this program requires Python version 2.2 or later."
    print "You appear to be running version", sys.version
    sys.exit(1)

__all__ = [
    # "PatternBase",
    "Alt", "Any", "Arb", "Arbno", "Both", "Call", "Cat", "Delimseq",
    "Len", "Lit", "Match", "Notany", "Pattern", "Pos",
    "Regexp", "Rpos", "Subseq", "Token", "arb" ]

class Subseq(object):
    """A subsequence of a given sequence.
    Subseq(x, begin, end) represents x[begin:end] but without copying
    any elements from x.  It is the user's responsibility to ensure
    that the value of x does not change while a Subseq is referring to it."""

    def __init__(self, seq, begin, end):
        """Initialize a representation of seq[begin:end]."""
        assert 0 <= begin <= end <= len(seq)
        self.seq, self.begin, self.end = seq, begin, end

class Match(object):
    """The result returned by match and search.

    A Match m represents the range [m.begin:m.end] of its sequence.
    The pat member is the pattern that was matched.

    """

    def __init__(self, seq, begin, end, data, pat):
        self.begin, self.end, self.data, self.seq, self.pat = begin, end, data, seq, pat

    def explain(self):
        """Create a detailed data structure that describes the match"""
        data, end = \
               self.pat.traverse(lambda obj, *args: obj.explain(*args),
                                  self.begin, self.data)
        return data

    def evaluate(self):
        """Transform the match data structure in a user-specified way."""
        data, end = \
               self.pat.traverse(lambda obj, *args: obj.evaluate(self.seq, *args),
                                  self.begin, self.data)
        return data

    def expand(self):
        """Create a compact data structure that describes the match"""
        data, end = \
               self.pat.traverse(lambda obj, *args: args,
                                  self.begin, self.data)
        return data

    def tokens(self):
        """Compute a list of (begin, end) pairs representing the
        tokens encountered during matching."""
        data, end = \
               self.pat.traverse(lambda obj, *args: obj.tokens(*args),
                                  self.begin, self.data)
        return data

class PatternBase(object):
    """Abstract base class for the pattern hierarchy.

    Users normally don't see this class directly; instead, they see
    classes derived from this class, particularly including class
    Pattern, which is a surrogate for some other kind of class.

    So, for example, Pattern("Foo") maps internally into Pattern(Lit("Foo")),
    where Pattern and Lit are both derived from PatternBase."""

    def __init__(*args):
        raise TypeError, "PatternBase is an abstract base class"
    
    def _exprep(self, context):
        """The representation of a pattern as an operand of an operator
        with a given precedence (context).  Only patterns that represent
        infix operators care about the context, so the default is just
        to return the canonical representation."""
        return `self`

    # All patterns support +, &, |, and % operators.  Perhaps others later.
    def __add__(self, other):
        return Cat(self, _makePattern(other))
    def __radd__(self, other):
        return Cat(_makePattern(other), self)
    def __or__(self, other):
        return Alt(self, _makePattern(other))
    def __ror__(self, other):
        return Alt(_makePattern(other), self)
    def __and__(self, other):
        return Both(self, _makePattern(other))
    def __rand__(self, other):
        return Both(_makePattern(other), self)
    def __div__(self, other):
        return Delimseq(self, _makePattern(other))
    def __rdiv__(self, other):
        return Delimseq(_makePattern(other), self)
    def __mod__(self, other):
        return Bind(self, other)

    def match(self, seq, begin=0, end=None):
        if end == None:
            end = len(seq)
        for d, e in self.gen_matches(Subseq(seq, begin, end), begin):
            yield Match(seq, begin, e, d, self)

    def search(self, seq, begin=0, end=None):
        if end == None:
            end = len(seq)
        subject = Subseq(seq, begin, end);
        for i in range(begin, end+1):
            for d, e in self.gen_matches(subject, i):
                yield Match(seq, i, e, d, self)

    def gen_matches(self, subseq, startpos):
        """Every class derived from PatternBase is expected to override this
        function with one that takes the subseqence to match as its first
        argument and the starting position in that subsequence as its second.
        It returns a generator that represents a sequence of (result, end)
        pairs, where "result" describes the result of the match in a way
        that depends on the type of the derived class and "end" is the
        position one past the last symbol matched."""
        
        raise TypeError, "PatternBase is an abstract base class"
        
    def traverse(self, fun, begin, data):
        """Traverse the "data" data structure, applying "fun" to each
        node along the way.  The format of the match depends on the particular
        kind of pattern being traversed.  Therefore, part of the job of
        "traverse" is to decode that data structure.

        The argument that "fun" gets is not the actual "data" data
        structure at each step, but rather a canonical data structure
        consisting of (self, begin, end, *args), where *args depends
        on the type of the pattern.

        Traverse returns a pair that contains the result of calling fun
        and the computed value of end.  Computing end is not always trivial."""
        raise TypeError, "PatternBase is an abstract base class"
    
    def explain(self, begin, end):
        return self.makenote(begin, end)

    def tokens(self, begin, end, *args):
        return reduce(operator.add, args, [])

    def evaluate(self, seq, begin, end, *args):
        """By default, calling evaluate on a pattern returns the concatenation
        of the results of evaluating all of its subpatterns, if any."""
        return reduce(operator.add, args, [])

    def makenote(self, begin, end, **init):
        """Internal function to build uniform parts of an annotation"""
        # end is either the actual end or an (info, end) pair
        if isinstance(end, tuple):
            assert len(end) == 2
            end = end[1]
        init['type'] = self.__class__.__name__
        init['begin'] = begin
        init['end'] = end
        return init

class Pattern(PatternBase):
    """A generic stand-in for another kinds of pattern"""
    def __init__(self, pat = None):
        self.pat = _makePattern(pat)
    def __repr__(self):
        return `self.pat`
    def gen_matches(self, subj, pos):
        return self.pat.gen_matches(subj, pos)
    def traverse(self, fun, begin, data):
        return self.pat.traverse(fun, begin, data)

class Alt(PatternBase):
    """A pattern that matches anything matched by either of its operands"""
    def __init__(self, left, right):
        self.left, self.right = left, right
    def __repr__(self):
        return self._exprep(0)
    def _exprep(self, context):
        return _binop(self, "|", 1, context)
    def gen_matches(self, subj, pos):
        for r, i in self.left.gen_matches(subj, pos):
            yield (False, r), i
        for r, i in self.right.gen_matches(subj, pos):
            yield (True, r), i
    def traverse(self, fun, begin, (pred, r)):
        if pred:
            pat = self.right
        else:
            pat = self.left
        data, end = pat.traverse(fun, begin, r)
        return fun(self, begin, end, pred, data), end
    def explain(self, begin, end, pred, data):
        if pred:
            side = 'right'
        else:
            side = 'left'
        return self.makenote(begin, end, side=side, data=data)
    def evaluate(self, seq, begin, end, pred, data):
        # We have already evaluated the data of the side that matched,
        # so all we have to do is pass that data along to our caller.
        return data

class Any(PatternBase):
    """A pattern that matches any element of its argument sequence"""
    def __init__(self, seq):
        self.seq = seq
    def __repr__(self):
        return "Any(%s)" % `self.seq`
    def gen_matches(self, subj, pos):
        if pos < subj.end and subj.seq[pos] in self.seq:
            yield None, pos + 1
    def traverse(self, fun, begin, data):
        assert data == None
        end = begin + 1
        return fun(self, begin, end), end

class Arb(PatternBase):
    """A pattern that matches anything at all"""
    def __init__(self):
        pass
    def __repr__(self):
        return "arb"
    def gen_matches(self, subj, pos):
        assert pos >= subj.begin
        for end in range(pos, subj.end+1):
            yield end, end
    def traverse(self, fun, begin, data):
        end = data
        return fun(self, begin, end), end

arb = Arb()            

class Arbno(PatternBase):
    """A pattern that matches zero or more repetitions of its argument"""
    def __init__(self, pat):
        self.pat = _makePattern(pat)
    def __repr__(self):
        return "Arbno(" + `self.pat` + ")"
    # yield ((data0, data1, ...), end)
    def gen_matches(self, subj, pos):
        assert pos >= subj.begin and pos <= subj.end
        yield (), pos                   # the null sequence matches
        for match in self.match1(subj, pos, ()):
            yield match
    def match1(self, subj, pos, prefix):
        """Internal function to match one or more instances of the argument"""
        for data, end in self.pat.gen_matches(subj, pos):
            assert end <= subj.end
            newprefix = prefix + (data,)
            yield newprefix, end
            for x in self.match1(subj, end, newprefix):
                assert x[1] <= subj.end
                yield x
    def traverse(self, fun, begin, data):
        # data is of the form (data0, data1, ...)
        r = []
        end = b = begin
        for d in data:
            t, end = self.pat.traverse(fun, b, d)
            r += [t]
            b = end
        return fun(self, begin, end, *r), end
    def explain(self, begin, end, *data):
        return self.makenote(begin, end, data=data)

class Bind(PatternBase):
    """A pattern that invokes a user-specified function
    on what its operand matches"""
    def __init__(self, pat, fun):
        self.pat = pat
        if isinstance(fun, dict):
            self.fun = lambda data: [fun[data[0]]]
        elif callable(fun):
            self.fun = lambda data: [fun(*data)]
        elif fun is None:
            self.fun = lambda data: []
        else:
            self.fun = lambda data: [fun]
    def __repr__(self):
        return "Bind(%s)" % self.pat
    def gen_matches(self, subj, pos):
        return self.pat.gen_matches(subj, pos)
    def traverse(self, fun, begin, data):
        data, end = self.pat.traverse(fun, begin, data)
        return fun(self, begin, end, data), end
    def evaluate(self, seq, begin, end, data):
        return self.fun(data)

class Both(PatternBase):
    """A pattern that matches anything matched by both its operands"""
    def __init__(self, left, right):
        self.left, self.right = left, right
    def __repr__(self):
        return self._exprep(0)
    def _exprep(self, context):
        return _binop(self, "&", 2, context)
    def gen_matches(self, subj, pos):
        for rl, i in self.left.gen_matches(subj, pos):
            for rr, j in self.right.gen_matches(subj, pos):
                if i == j:
                    yield (rl, rr), i
    def traverse(self, fun, begin, (rl, rr)):
        ldata, lend = self.left.traverse(fun, begin, rl)
        rdata, rend = self.right.traverse(fun, begin, rr)
        assert lend == rend
        return fun(self, begin, lend, ldata, rdata), lend
    def explain(self, begin, end, ldata, rdata):
        return self.makenote(begin, end, left=ldata, right=rdata)
    def evaluate(self, seq, begin, end, ldata, rdata):
        return [(ldata, rdata)]

class Cat(PatternBase):
    """The concatenation (usually via +) of two patterns"""
    def __init__(self, left, right):
        self.left, self.right = left, right
    def __repr__(self):
        return self._exprep(0)
    def _exprep(self, context):
        return _binop(self, "+", 3, context)
    def gen_matches(self, subj, pos):
        for rl, mid in self.left.gen_matches(subj, pos):
            for rr, end in self.right.gen_matches(subj, mid):
                yield (rl, mid, rr), end
    def traverse(self, fun, begin, (rl, mid, rr)):
        (ldata, lend) = self.left.traverse(fun, begin, rl)
        assert lend == mid
        (rdata, end) = self.right.traverse(fun, lend, rr)
        return fun(self, begin, end, ldata, rdata), end
    def explain(self, begin, end, ldata, rdata):
        return self.makenote(begin, end, left=ldata, right=rdata)

class Call(PatternBase):
    """The pattern yielded by calling the argument during matching"""
    def __init__(self, pat):
        self.pat = pat
    def __repr__(self):
        return "Call(%s)" % `self.pat`
    def gen_matches(self, subj, pos):
        return self.pat().gen_matches(subj, pos)
    def traverse(self, fun, begin, data):
        data, end = self.pat().traverse(fun, begin, data)
        return fun(self, begin, end, data), end
    def explain(self, begin, end, data):
        return self.makenote(begin, end, data=data)

class Delimseq(PatternBase):
    """A pattern that, given p1 and p2, matches a (nonempty) sequence of
       p1 separated by p2"""
    def __init__(self, left, right):
        self.left, self.right = left, right
    def __repr__(self):
        return self._exprep(0)
    def _exprep(self, context):
        return _binop(self, "/", 4, context)
    def gen_matches(self, subj, pos):
        assert pos >= subj.begin and pos <= subj.end
        for data, end in self.left.gen_matches(subj, pos):
            yield (data,), end
            for match in self.match1(subj, end, (data,)):
                yield match
    def match1(self, subj, pos, prefix):
        """Internal function to match one or more instances of the argument pair"""
        for rdata, rend in self.right.gen_matches(subj, pos):
            for ldata, end in self.left.gen_matches(subj, rend):
                newprefix = prefix + (rdata, ldata)
                yield newprefix, end
                for x in self.match1(subj, end, newprefix):
                    yield x
    def traverse(self, fun, begin, data):
        # data is of the form (data0, data1, ...)
        # data0, data2, etc. represent left-side patterns;
        # data1, data3, etc. represent right-side patterns
        r = []
        end = b = begin
        left = True
        for d in data:
            if left:
                pat = self.left
            else:
                pat = self.right
            t, end = pat.traverse(fun, b, d)
            r += [t]
            b = end
            left = not left
        return fun(self, begin, end, *r), end
    def explain(self, begin, end, *data):
        return self.makenote(begin, end, data=data)

class Len(PatternBase):
    """A pattern that matches a sequence of a given length"""
    def __init__(self, n):
        self.n = n
    def __repr__(self):
        return "Len(%d)" % self.n
    def gen_matches(self, subj, pos):
        end = pos + self.n
        if end <= subj.end:             # yes, I meant <=, not <
            yield None, end
    def traverse(self, fun, begin, data):
        assert data == None
        end = begin + self.n
        return fun(self, begin, end), end
        
class Lit(PatternBase):
    """A pattern that matches a literal sequence"""
    def __init__(self, seq):
        self.seq = seq
    def __repr__(self):
        # We don't bother marking literal patterns as such
        # i.e. Lit("Foo") will print as '"Foo"' rather than 'Lit("Foo")'
        return `self.seq`
    def gen_matches(self, subj, pos):
        begin = pos
        end = begin + len(self.seq)
        if end <= subj.end and subj.seq[begin:end] == self.seq:   # <=, not <
            yield None, end
    def traverse(self, fun, begin, data):
        assert data == None
        end = begin + len(self.seq)
        return fun(self, begin, end), end

_re_type = type(re.compile(""))
    
def _makePattern(x):
    if isinstance(x, PatternBase):
        return x
    if callable(x):
        return Call(x)
    if isinstance(x, _re_type):
        return Regexp(x)
    return Lit(x)

class Notany(PatternBase):
    """A pattern that matches any element that is not in its argument sequence"""
    def __init__(self, seq):
        self.seq = seq
    def __repr__(self):
        return "Notany(%s)" % `self.seq`
    def gen_matches(self, subj, pos):
        if pos < subj.end and subj.seq[pos] not in self.seq:
            yield None, pos + 1
    def traverse(self, fun, begin, data):
        assert data == None
        end = begin + 1
        return fun(self, begin, end), end

class Pos(PatternBase):
    """A pattern that matches a null string at a given position"""
    def __init__(self, n):
        self.n = n
    def __repr__(self):
        return "Pos(%d)" % self.n
    def gen_matches(self, subj, pos):
        if self.n + subj.begin == pos:
            yield None, pos
    def traverse(self, fun, begin, data):
        assert data == None
        # begin == end
        return fun(self, begin, begin), begin

class Regexp(PatternBase):
    """A pattern that matches a given regular expression"""
    def __init__(self, expr):
        if isinstance(expr, str):
            expr = re.compile(expr)
        self.expr = expr
    def __repr__(self):
        return "Regexp(%s)" % `self.expr.pattern`
    def gen_matches(self, subj, pos):
        match = self.expr.match(subj.seq, pos, subj.end)
        if match:
            end = match.end()
            yield end, end
    def traverse(self, fun, begin, data):
        end = data
        return fun(self, begin, end), end

class Rpos(PatternBase):
    """A pattern that matches a null string at a given offset from the end"""
    def __init__(self, n):
        self.n = n
    def __repr__(self):
        return "Rpos(%d)" % self.n
    def gen_matches(self, subj, pos):
        if subj.end - self.n == pos:
            yield None, pos
    def traverse(self, fun, begin, data):
        assert data == None
        # begin == end
        return fun(self, begin, begin), begin

class Token(PatternBase):
    """A Token matches whatever its base pattern matches, but when evaluated,
    yields the substring matched rather than the concatenation of the
    evaluations of its constituents."""
    def __init__(self, pat):
        self.pat = _makePattern(pat)
    def __repr__(self):
        return "Token(%s)" % `self.pat`
    def gen_matches(self, subj, pos):
        return self.pat.gen_matches(subj, pos)
    def traverse(self, fun, begin, data):
        data, end = self.pat.traverse(fun, begin, data)
        return fun(self, begin, end, data), end
    def tokens(self, begin, end, args):
        return [(begin, end)] + args
    def explain(self, begin, end, data):
        return self.makenote(begin, end, data=data)
    def evaluate(self, seq, begin, end, *args):
        # This function returns a 1-element list because of the convention
        # that evaluate returns a list of all of the current tokens.
        return [seq[begin: end]]
    
# auxiliary function for creating a human-readable representation for
# expressions that concern binary operators
def _binop(pat, op, prec, context):
    result = pat.left._exprep(prec) + " " + op + " " + pat.right._exprep(prec+1)
    if prec < context:
        result = "(" + result + ")"
    return result

if __name__ == "__main__":
    import grasptest
    grasptest.main()
