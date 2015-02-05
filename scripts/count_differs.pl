#!/usr/bin/env perl

my ($differs, $perftests, $same, $better, $worse) = (0, 0, 0, 0, 0);
while (<>) {
  print;
  if (/DIFFERS/) {
    $differs++;
  }
  if (/ SAME /) {
    $same++; $perftests++;
  }
  if (/ BETTER /) {
    $better++; $perftests++;
  }
  if (/ WORSE /) {
    $worse++; $perftests++;
  }
  if (/WARNING: .*not compared$/) {
    $perftests++;
  }
}
print "\n\nNumber of regression tests with differences: $differs\n";
if ($perftests > 0) {
  print "Number of performance tests: $perftests, same: $same, better: $better, worse: $worse\n";
}
print "\n";
