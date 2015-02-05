#!/usr/bin/env perl

my @line;
my ($inq, $qt, $backslash, $backslash_prev, $cur, $char, $len, $i);

goto usage if ($#ARGV != -1);

while (<>) {
  @line = split(//);
  $len = $#line;
  $inq = $backslash = 0;
 INNER: for ($cur = 0; $cur <= $len; $cur++) {
    $char = $line[$cur];
    $backslash_prev = $backslash;
    $backslash = ($char eq "\\") ? 1 : 0;
    $qt = ($char eq "\"") ? 1 : 0;
    if ($inq) { # in a quote
      if ($qt && !$backslash_prev) {
	# exiting quote, peek ahead
	$i = $cur+1;
	while ($line[$i] =~ /\s/) { $i++; } # skip spaces
	if ($line[$i] eq "\"") { # new quote starts right away
	  $cur = $i; # skip over chars from end quote to the new start quote
	  next INNER;
	}
	# exit quote
	$inq = 0;
      }
    } else { # not in a quote
      if ($qt && !$backslash_prev) { 
	# enter a quote
	$inq = 1;
      }
    }
    print $char;
  }
}
