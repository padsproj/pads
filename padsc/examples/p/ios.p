/*
 * TODO
 *  router ospf ...
 *  router bgp ...
 *  ip route ...
 *  ip flow-export ...
 *  ip flow-cache ...
 *  ip access-list ...
 *  ip community-list ...
 *  ip default-access-group ...
 *  ip name-server ...
 *  ip domain-lookup
 *  line vty ...
 *  line console ...
 *
 *  + various places are supposed to record the current line number
 */

/*
 * ios.p: PADS ios declarations
 *
 * Notes: 
 *
 *  (1) input munging: the following substitutions on each input line could
 *      to be done outside of PADS at the moment:
 *
 *    # escape bad characters
 *    $_ =~ s/&/&amp;/g;
 *    $_ =~ s/</&lt;/g;
 *
 *    # watch out for some specific crap
 *    $_ =~ s/\x8|\x7f//g;
 *
 *    #convert any true ctrl-c to ^C
 *    $_ =~ s/\cC/\^C/g;
 *
 *    $_ =~ s/[\x80-\xFF]/~/g if $ascii;
 *
 * 
 *  (2) Penum is supposed to support a couple of things that I am not sure
 *      are working.  One is the ability to specify a suffix to add to each
 *      enum value... I want to add _e to each one, so that clock -> clock_e.
 *      Another is the ability to give a string that the enum value 
 *      comes from, as in
 *          package_file Pfrom "package-file"
 *      so that you can convert external values that are not legal C 
 *      identifiers (package-file) into the specied C enum value (package_file).
 *      XXX Once Penum can do the above, the following are not needed
 *
 *   $_ =~ s/^(\s*(not\s+)?)aaa/\1aaa_e/;
 *   $_ =~ s/^(\s*(not\s+)?)banner/\1banner_e/;
 *   $_ =~ s/^(\s*(not\s+)?)bay/\1bay_e/;
 *   $_ =~ s/^(\s*(not\s+)?)clock/\1clock_e/;
 *   $_ =~ s/^(\s*(not\s+)?)crashdump/\1crashdump_e/;
 *   $_ =~ s/^(\s*(not\s+)?)end/\1end_e/;
 *   $_ =~ s/^(\s*(not\s+)?)enable/\1enable_e/;
 *   $_ =~ s/^(\s*(not\s+)?)default-te-metric/\1default_te_metric_e/;
 *   $_ =~ s/^(\s*(not\s+)?)fabric/\1fabric_e/;
 *   $_ =~ s/^(\s*(not\s+)?)hostname/\1hostname_e/;
 *   $_ =~ s/^(\s*(not\s+)?)interface/\1interface_e/;
 *   $_ =~ s/^(\s*(not\s+)?)logging/\1logging_e/;
 *   $_ =~ s/^(\s*(not\s+)?)module/\1module_e/;
 *   $_ =~ s/^(\s*(not\s+)?)mpls/\1mpls_e/;
 *   $_ =~ s/^(\s*(not\s+)?)package-file/\1package_file_e/;
 *   $_ =~ s/^(\s*(not\s+)?)sample/\1sample_e/;
 *   $_ =~ s/^(\s*(not\s+)?)server-id/\1server_id_e/;
 *   $_ =~ s/^(\s*(not\s+)?)server-location/\1server_location_e/;
 *   $_ =~ s/^(\s*(not\s+)?)snmp-server/\1snmp_server_e/;
 *   $_ =~ s/^(\s*(not\s+)?)sntp/\1sntp_e/;
 *   $_ =~ s/^(\s*(not\s+)?)system-password/\1system_password_e/;
 *   $_ =~ s/^(\s*(not\s+)?)user/\1user_e/;
 *   $_ =~ s/^(\s*(not\s+)?)watchdog/\1watchdog_e/;
 */

////////////////////////////////////////////////////////////////////////////////
// HELPER MACROS

// A regexp that matches and eats zero or more spaces
#define EAT_SPACES Pre "/\A\s*/"

// A regexp for 'rest of line starts with a word on good list glist'
#define GOODLIST_RE(glist)                 "/(" glist ").*$/"

// A regexp for 'rest of line does not start with a word on stop list slist'
#define NOT_STOPLIST_RE(slist)             "/(?!(" slist ")).*$/"

// A combination of the above
#define GOOD_NOT_STOPLIST_RE(glist, slist) "/(?!(" slist ")).*(" glist ").*$/"

// Pstring_ME types for the above regexps
#define GOODLIST_ME(slist) \
  Pstring_ME(: NOT_STOPLIST_RE(slist) :)
#define NOT_STOPLIST_ME(slist) \
  Pstring_ME(: NOT_STOPLIST_RE(slist) :)
#define GOOD_NOT_STOPLIST_ME(glist, slist) \
  Pstring_ME(: GOOD_NOT_STOPLIST_RE(slist, glist) :)

// stoplist used for, e.g., ELEMENT interface 
#define D_stoplist \
"aaa|" \
"banner|" \
"boot|" \
"cdp|" \
"class-map|" \
"controller|" \
"dial-peer|" \
"enable|" \
"end|" \
"hostname|" \
"interface|" \
"ipc|" \
"line|" \
"map-list|" \
"memory-size|" \
"menu|" \
"module|" \
"mpls|" \
"policy-map|" \
"redundancy|" \
"router|" \
"route-map|" \
"service|" \
"slottablecos|" \
"snmp-server|" \
"tacacs-server|" \
"tag-switching|" \
"username|" \
"vlan"

////////////////////////////////////////////////////////////////////////////////
// HELPER TYPES

// XXX Note: Ptypedef is currently broken; so each Ptypedef (commented out)
// is replaced with a Pstruct definition.  This adds an extra level of
// stuctural nesting (an extra '.v') that is not necessary, and will go away.

// a single item (or 'word' in Perl-speak)
// Ptypedef Pstring_ME(: "/\w+/" :) item;
Pstruct item {
  Pstring_ME(: "/\w+/" :) v;
};

// remain reads the rest of the current line into a string
// Precord Ptypedef Pstring_SE(: "/$/" :) remain;
Precord Pstruct remain {
  Pstring_SE(: "/$/" :) v;
};

// An optional "no ":
Punion opt_no {
  Pstring_ME(: "/no\s+/" :)             no_found;
  Pcompute Pint8                        no_not_found = 1;
};

// An optional item
Punion opt_item {
  item                                  item_found;
  Pcompute Pint8                        item_not_found = 1;
};

////////////////////////////////////////////////////////////////////////////////
// ELEMENT skip_elt
// ELEMENT blank_elt
// ELEMENT comment_elt

// D: skip all elements that begin with (\s*)[!], %, :, or "show running"
//    also skip blank lines (lines with just spaces)
// Precord Ptypedef Pstring_ME(: "/^(\s*[!]|[%:]|show running)(.*)$/" :) D_skip_elt;
Precord Pstruct D_skip_elt {
  Pstring_ME(: "/(^(\s*[!]|[%:]|show running)(.*)$)|(^\s*$)/" :) v;
};

// Both J and D need to match blank lines, for different reasons
// J: each blank line is recorded
// D: blank lines are skipped

// Precord Ptypedef Pstring_ME(: "/^\s*$/" :) C_blank_line;
Precord Pstruct C_blank_line           { Pstring_ME(: "/^\s*$/" :)                  v; };

// J: each comment section (set of lines) is recorded.  A comment is ...

////////////////////////////////////////////////////////////////////////////////
// NAME-VALUE ELEMENTS : <name> <value>

// D name-value elements
Precord Pstruct D_aaa_elt               { /* already parsed "aaa " */                remain v; };
Precord Pstruct D_bay_elt               { /* already parsed "bay " */                remain v; };
Precord Pstruct D_clock_elt             { /* already parsed "clock " */              remain v; };
Precord Pstruct D_crashdump_elt         { /* already parsed "crashdump " */          remain v; };
Precord Pstruct D_end_elt               { /* already parsed "end " */                remain v; }; // v should be empty?
Precord Pstruct D_enable_elt            { /* already parsed "enable " */             remain v; };
Precord Pstruct D_default_te_metric_elt { /* already parsed "default-te-metric " */  remain v; };
Precord Pstruct D_fabric_elt            { /* already parsed "fabric " */             remain v; };
Precord Pstruct D_logging_elt           { /* already parsed "logging " */            remain v; };
Precord Pstruct D_package_file_elt      { /* already parsed "package-file " */       remain v; };
Precord Pstruct D_sample_elt            { /* already parsed "sample " */             remain v; };
Precord Pstruct D_server_id_elt         { /* already parsed "server-id " */          remain v; };
Precord Pstruct D_server_location_elt   { /* already parsed "server-location " */    remain v; };
Precord Pstruct D_snmp_server_elt       { /* already parsed "snmp-server " */        remain v; };
Precord Pstruct D_sntp_elt              { /* already parsed "sntp " */               remain v; };
Precord Pstruct D_system_password_elt   { /* already parsed "system-password " */    remain v; };
Precord Pstruct D_user_elt              { /* already parsed "user " */               remain v; };
Precord Pstruct D_watchdog_elt          { /* already parsed "watchdog " */           remain v; };

// common name-value elements
Precord Pstruct C_hostname_elt          { /* already parsed "hostname " */           remain v; };

////////////////////////////////////////////////////////////////////////////////
// NAME-TYPE-VALUE ELEMENTS   <name> <type> <value>

// D name-type-value elements
Precord Pstruct D_mpls_elt              { /* already parsed "mpls " */  item type;   remain v; };

////////////////////////////////////////////////////////////////////////////////
// ELEMENT banner_elt

// J: A banner add-on line is any line that does not begin with ! or control-C.
//    A banner begins with "banner exec", ignore the rest of that line
//    then it includes the following banner add-on lines.

// Precord Ptypedef Pstring_ME(: "/(?!(^[!]|^\^C))(.*)$/" :) J_banner_line;
Precord Pstruct J_banner_line {
  Pstring_ME(: "/(?!(^[!]|^\^C))(.*)$/" :) v;
};
Parray J_banner_lines { J_banner_line []; };
Pstruct J_banner_elt {
  "exec";
  Pomit remain                          junked;
  J_banner_lines                        banner_lines;
};

// D: A banner add-on line does not begin with control-C (or banner),
//      where comment lines (pattern /[!]\s*[a-z]/) are skipped over.
//      A banner begins with "banner ", append the rest of the current line
//      plus all the add-on lines.

// Precord Ptypedef Pstring_ME(: "/(?!(^\^C|^banner))(.*)$/" :) D_banner_line;
Precord Pstruct D_banner_line {
  Pstring_ME(: "/(?!(^\^C|^banner))(.*)$/" :) v;
};

Parray D_banner_lines {
  D_banner_line [] /* : Pskip(elt =~ Pre "/[!]\s*[a-z]/") */ ;
  // XXX Pskip not supported yet 
};

Pstruct D_banner_elt {
  /* already parsed: [no] banner */
  remain                                line1;
  D_banner_lines                        rest;
};

////////////////////////////////////////////////////////////////////////////////
// ELEMENT line
//
// D: a line element L starts with line <tag> <rest>
//    L.name = <rest>
//    L._lineno = current line number 
// For remaining lines, terminates when finds line
//     with just bang ( /^[!]$/ ) OR a line with first word in stoplist
// Included lines:
//     . Skip over comment lines that have /[!]\s*[a-z]/ (not left-pinned, why not?)
//     . Ignore leading spaces
//     . Remember whether first thing is 'no', consider rest
//     . if you see "description (.*)", record the (.*) part as description for L
//     . if line now matches /access-class/  (not left-pinned)
//          . add line to list L.access_class
//          . line is access_class <rest>,
//               updates global ::declarations table, _access_class entry, pushing <rest>
//     . otherwise add the line to a set of features for the line
//

// TODO

////////////////////////////////////////////////////////////////////////////////
// ELEMENT route_map
//
// D: a route map line starts with route-map <tag> <name> <act> <rest>
//    rmap.name = <name>
//    rmap.action = <act>
//    rmap.seq = <rest>
//    rmap._lineno = current line number 
// For remaining lines, terminates when finds line
//     with just bang ( /^[!]$/ ) OR a line whose cmd is not one of description|match|set
// Included lines:
//     . Skip over comment lines that have /[!]\s*[a-z]/ (not left-pinned, why not?)
//     . Ignore leading spaces
//     . Remember whether first thing is 'no', consider rest
//     . if you see "description (.*)", record the (.*) part as description for the route_map
//     . otherwise add the line to a set of features for the route_map
//        (the only cases that fall through to here are match and set)

//TODO

////////////////////////////////////////////////////////////////////////////////
// ELEMENT interface_elt (not done)
// ELEMENT avici_interface_elt

// D: avici interface
//  First line is "interface <name> <rest>" where:
//     the full name of the interface is "<name> <rest>"
//     if <name> is Loopback or Ethernet, then
//        add <rest> to a set of features for the interface
//     else
//        the interface pos = <rest>
//  The rest of the lines are terminated by a line in a stoplist.
//  For included lines:
//     . Skip over comment lines that have /[!]\s*[a-z]/ (not left-pinned, why not?)
//     . Ignore leading spaces
//     . Remember whether first thing is 'no', consider rest
//     . if you see "ip address (.*)", add this line to set of address for the interface
//     . if you see "description (.*)", record the (.*) part as description for the interface
//     . otherwise add the line to a set of features for the interface
//
// The PADS version of the above records all the lines that follow the interface line
// in 'iflines', classifying each line as one of three kinds: if_addr, if_descr, if_feature.
// Later on we will look at whether we can mimic the exact behavior of D's Perl script.

Precord Pstruct D_avici_if_addr_line {
  Pomit Pstring_ME(: "\s*" :)           leading_sp;
  opt_no                                no;
  "ip address ";
  remain                                v;
};

Precord Pstruct D_avici_if_descr_line {
  Pomit Pstring_ME(: "\s*" :)           leading_sp;
  opt_no                                no;
  "description ";
  remain                                v;
};

Precord Pstruct D_avici_if_feature_line {
  Pstring_ME(: "\s*" :)                 leading_sp;
  opt_no                                no;
  NOT_STOPLIST_ME(D_stoplist)           v;
};

Punion D_avici_if_line {
  C_blank_line                          if_blank;
  D_avici_if_addr_line                  if_addr;
  D_avici_if_descr_line                 if_descr;
  D_avici_if_feature_line               if_feature;
};
Parray D_avici_if_lines {
  D_avici_if_line [] /* : Pskip(elt.tag == if_blank) */ ;
  // XXX Pskip not supported yet
};

int fixname(item* name, remain *rest) {  /* Pstring_append(name, rest); */ return 1; } 
// XXX Pstring_append not implemented yet

Pstruct D_avici_interface_elt {
  /* already parsed: [no] interface */
  item                                  name;
  remain                                rest : fixname(&name, &rest);
  D_avici_if_lines                      iflines;
};

////////////////////////////////////////////////////////////////////////////////
// ELEMENT avici_module_elt

// D: avici module
// 
// first line has form module <pos> <rest>
//   module.pos    = pos
//   module._lineno = current line number
//   module.attr   = rest
//
//  The rest of the lines are terminated by a line in a stoplist, or
//  by an empty/spaces-only line (emtpy line results in a warning).
//  For included lines:
//     . Skip over comment lines that begin with /[!]\s*[a-z]/ (not left-pinned, why not?)
//     . Ignore leading spaces
//     . Remember whether first thing is 'no', consider rest
//     . if you see "ip address [address] [mask]",
//                if exists address
//                  fatal error if module.address already defined
//                  else module.address = address
//                if exists mask,
//                  fatal error if module.mask already defined
//                  else module.mask = mask
//     . if you see "description <rest>"
//             fatal error if module.descr already defined
//             else module.descr = rest
//     . otherwise add the line to a set of features for the module
//
// The PADS version of the above records all the lines that follow the interface line
// in 'mlines', classifying each line as one of three kinds: m_addr, m_descr, m_feature.
// Later on we will look at whether we can mimic the exact behavior of D's Perl script.

Precord Pstruct D_avici_m_addr_line {
  Pomit Pstring_ME(: "\s*" :)           leading_sp;
  opt_no                                no;
  "ip address ";
  opt_item                              addr;
  EAT_SPACES;
  opt_item                              mask;
  remain                                rest; // expected to be emtpy string
};

Precord Pstruct D_avici_m_descr_line {
  Pomit Pstring_ME(: "\s*" :)           leading_sp;
  opt_no                                no;
  "description ";
  remain                                v;
};

Precord Pstruct D_avici_m_feature_line {
  Pstring_ME(: "\s*" :)                 leading_sp;
  opt_no                                no;
  NOT_STOPLIST_ME(D_stoplist)           v;
};

Punion D_avici_m_line {
  C_blank_line                          m_blank;
  D_avici_m_addr_line                   m_addr;
  D_avici_m_descr_line                  m_descr;
  D_avici_m_feature_line                m_feature;
};
Parray D_avici_m_lines {
  D_avici_m_line [] /* : Pskip(elts[current].tag == m_blank) */ ;
  // XXX Pskip not supported yet
};

Pstruct D_avici_module_elt {
  /* already parsed: [no] module */
  item                                  name;
  EAT_SPACES;
  remain                                rest;
  D_avici_m_lines                       mlines;
};

////////////////////////////////////////////////////////////////////////////////
// ELT  : top-level elements

Penum D_elt_kind {
  aaa_e,
  banner_e,
  bay_e,
  clock_e,
  crashdump_e,
  end_e,
  enable_e,
  default_te_metric_e,
  fabric_e,
  hostname_e,
  interface_e,
  module_e,
  mpls_e,
  package_file_e,
  sample_e,
  server_id_e,
  server_location_e,
  snmp_server_e,
  sntp_e,
  system_password_e,
  user_e,
  watchdog_e
};

Punion D_elt_switch(: D_elt_kind kind :) {
  Pswitch (kind) {
    Pcase aaa_e:                D_aaa_elt                aaa_k;
    Pcase banner_e:             D_banner_elt             banner_k;
    Pcase bay_e:                D_bay_elt                bay_k;
    Pcase clock_e:              D_clock_elt              clock_k;
    Pcase crashdump_e:          D_crashdump_elt          crashdump_k;
    Pcase end_e:                D_end_elt                end_k;
    Pcase enable_e:             D_enable_elt             enable_k;
    Pcase default_te_metric_e:  D_default_te_metric_elt  default_te_metric_k;
    Pcase fabric_e:             D_fabric_elt             fabric_k;
    Pcase hostname_e:           C_hostname_elt           hostname_k;
    Pcase interface_e:          D_avici_interface_elt    interface_k;
    Pcase module_e:             D_avici_module_elt       module_k;
    Pcase mpls_e:               D_mpls_elt               mpls_k;
    Pcase package_file_e:       D_package_file_elt       package_file_k;
    Pcase sample_e:             D_sample_elt             sample_k;
    Pcase server_id_e:          D_server_id_elt          server_id_k;
    Pcase server_location_e:    D_server_location_elt    server_location_k;
    Pcase snmp_server_e:        D_snmp_server_elt        snmp_server_k;
    Pcase sntp_e:               D_sntp_elt               sntp_k;
    Pcase system_password_e:    D_system_password_elt    system_password_k;
    Pcase user_e:               D_user_elt               user_k;
    Pcase watchdog_e:           D_watchdog_elt           watchdog_k;
  }
};
// XXX Pswitch: should be able to pass D_elt_kind as the param, and
//              should be able to omit the (int) casts above

Pstruct D_known_elt {
  opt_no                                no;
  D_elt_kind                            kind;
  EAT_SPACES;
  D_elt_switch(: kind :)           elt;
};

Punion D_elt {
  // skip case -- check this first
  D_skip_elt                            skip;
  // known element
  D_known_elt                           known;
  // everything else
  remain                                unknown;
};

////////////////////////////////////////////////////////////////////////////////
// SOURCE

// D: A source (file or stream) is just a sequence of top-level elts, in any order.
//    If an end element is found, we're done.
//
// Note: some elements are supposed to be singletons.
// The PADS description does not check this at the moment.

Parray D_elts { D_elt [] : Plast(elts[current].tag == known && elts[current].val.known.kind == end_e); };

Psource Pstruct D_router {
  D_elts                                cisco_router;
};

// J: a file starts with [certain things] and then has a sequence of commands
// ...


////////////////////////////////////////////////////////////////////////////////

