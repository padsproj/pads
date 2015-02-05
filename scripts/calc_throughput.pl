#!/usr/bin/perl -w
#
# calc_throughput.pl - calculate size of input / execution time
#
# [see time_execution.pl, and check_performance.pl]
# 
use Getopt::Std;

our $opt_e;

$usage="Usage:
	$0 [-k|-m] [-e] [-v] <program> <input>

	 	-k|-m	report in kilobytes|megabytes per second
		-e	use elapsed time instead of user + system cpu
		-v	verbose\n\n";
#
# Validate options and arguments
#
die $usage if !getopts('ekmv');
die $usage if defined $opt_k && defined $opt_m;
die $usage if $opt_k && $opt_m;
die $usage if scalar(@ARGV) != 2;
  
$program="$ARGV[0]";
$input="$ARGV[1]";

die "$0: program $program not executable\n" if (! -x $program);
die "$0: input $input not readable\n" if (! -r $input);

#
# Measure size of input
#
# nl count, word count, byte count,  file name
( $_,       $_,         $byte_count, $_) = split(" ", `wc "$input"`);
print "$0: size of input $input = $byte_count bytes\n" if defined $opt_v;

#
# Measure execution time
#
open CMD_OUTPUT, "/usr/bin/time -p @ARGV 2>&1 | tail -3 |";
while (<CMD_OUTPUT>) {
  if (/^real\s+(\d+.\d+)$/) {
    $real_time = $1;
  } elsif (/^user\s+(\d+.\d+)$/) {
    $user_time = $1;
  } elsif (/^sys\s+(\d+.\d+)$/) {
    $sys_time = $1;
  }
}
close CMD_OUTPUT;
printf "$0: real %f user: %f sys: %f\n", $real_time, $user_time, $sys_time if defined $opt_v;

#
# Report result
#
$seconds = defined $opt_e ? $real_time : ($user_time + $sys_time);
$throughput = $byte_count / $seconds;
printf "$0: throughput=%f bytes/second\n", $throughput if defined $opt_v;

$one_k=1024;
if (defined $opt_k) {
  $scale = $one_k;
} elsif (defined $opt_m) {
  $scale = $one_k * $one_k;
} else {
  $len = length(sprintf("%d",int($throughput)));
  if ($len > 6) {
    $scale = $one_k * $one_k;
  } else {
    $scale = $one_k;
  }
}
$throughput /= $scale;
$size_unit = ($scale == $one_k) ?  "kilobytes" : "megabytes";

$fractional_figs=2;
printf "%.${fractional_figs}f %s per second\n", $throughput, $size_unit;
exit 0;
