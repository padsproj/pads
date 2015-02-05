#!/usr/bin/env perl

my $found = ();
my $res = "";
while (<>) {
  s/:/ /g;
  for my $elt ( split(/\s/) ) {
    if ($elt =~ /\S/) {
      if ($found{$elt}++ == 0) {
	$res = $res . ":" . $elt;
      }
    }
  }
}
$res =~ s/^[:]//;

print "$res\n";
