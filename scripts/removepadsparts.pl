#!/usr/bin/env perl

# this script removes duplicate entries from a path
# it also removes all entries with the string 'pads/ast-ast/arch'
# (i.e., paths that look like pads install dirs)

my $found = ();
my $res = "";
while (<>) {
  s/:/ /g;
  for my $elt ( split(/\s/) ) {
    if ($elt =~ /\S/ && $elt !~ m|pads/|) {
      if ($found{$elt}++ == 0) {
	$res = $res . ":" . $elt;
      }
    }
  }
}
$res =~ s/^[:]//;

print "$res\n";
