#!/usr/bin/env perl

$prev_empty = 0;
$pragma_prototyped = 0;

my $foo_c = "";
if ($ARGV[0] =~ /^((?:.+)[.]c)$/) {
  $foo_c = $1;
  $foo_c = s|[^\/]*\/||g;
  print "XXX foo_c = $foo_c\n";
}

while (<>) {
  # If there is a foo.c argument, then replace things that look like this:
  #     , <path_to>foo.c, <digits>
  # with
  #     , __FILE__, __LINE__
  # because we want the expanded file name and line number.
  if ($foo_c ne "") {
    s|[,]\s*[^,]*\/?$foo_c\s*[,]\s*\d+|, __FILE__, __LINE__|g
  }
  if (/^\s*$/) {
    if ($prev_empty == 1) {
      next;
    }
    $prev_empty = 1;
    print;
    next;
  }
  if (/\#pragma prototyped/) {
    if ($pragma_prototyped == 1) {
      next;
    }
    $pragma_prototyped = 1;
    print;
    next;
  }
  if ((/\# /) || (/\#line/)) { # do not emit source file info
    next;
  }
  foreach $part (split(/\"([^\"]|[\\][\"])*\"/)) {
    my $origpart = quotemeta($part);
    my $modpart = $part;
    $modpart =~ s/;([^\"])/;\n\1/g;
    $modpart =~ s/([\{\}])/\1\n/g;
    s/$origpart/$modpart/g;
  }
  while (/\n\n/) {
    s/\n\n/\n/g;
  }
  s/\}\s*;/\};/g;
  print;
  $prev_empty = 0;
}
