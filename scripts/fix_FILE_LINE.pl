#!/usr/bin/env perl

my $foo_c = "";
$foo_c = $ARGV[0];
$foo_c =~ s|[^\/]*\/||g;
if ($foo_c eq "") {
  print "fix_FILE_LINE.pl: argument should be a file name with optional leading path\n";
  exit -1; 
}
my $pat = "[,]\\s*\\\"[^,]*$foo_c\\\"\\s*[,]\\s*\\d+";

while (<STDIN>) {
  # replace things that look like this:
  #     , <path_to>foo.c, <digits>
  # with
  #     , __FILE__, __LINE__
  # because we want the expanded file name and line number.
  s|$pat|, __FILE__, __LINE__|;
  print;
}
