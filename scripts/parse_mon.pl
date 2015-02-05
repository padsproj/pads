#!/usr/bin/env perl

# First stab at a perl script that parses the mon.p format.
# A lot of error cases are not handled.
# You would get a shorter program if you removed the
# normal-case printing and just printed error messages.

# you may have to comment out this line and the ParseDate test
# if your Perl installation does not have Date::Manip
use Date::Manip;  # for parsing dates

# primary parts
my ($code, $severity, $timestamp, $addr, $info, $comment);

# parts of info when code is RTE
my ($num);
my @route;

my $line = 0;
while (<>) {
  chomp;
  $line++;
  print "\nline $line\n";
  if (/^(RTE|CPU) (\d+)\|([^\|]+)?\|([\d\.]+)__([^\|]+)\|(.*)$/) {
    ($code, $severity, $timestamp, $addr, $info, $comment)
      = ($1, $2, $3, $4, $5, $6);
    print "code = $code\n";
    print "severity = $severity\n";
    if ($timestamp ne "") {
      my $date = ParseDate($timestamp);
      if (!$date) {
	print "timestamp [$timestamp] not a valid date and time\n";
      } else {
	print "timestamp = $timestamp\n";
      }
    }
    print "addr = $addr\n";
    if ($code eq 'CPU') {
      if ($info !~ /^\d+$/) {
	print "[line $line] for CPU, info must be uint, found $info\n";
      } else {
	print "info = $info\n";
      }
    } else { # code is 'RTE'
      my $rest;
      if ($info =~ /^(\d+):((?:[\d\.]+;)*(?:[\d\.]+)?)$/) {
	($num, $rest) = ($1, $2);
	print "info breakdown...\n";
	print "    num = $num\n";
	@route = split(/;/, $rest);
	foreach $r (@route) {
	  print "    route part = $r\n";
	} 
      } else {
	print "Syntax error for line [$_] in info part\n";
      }
    }
    print "comment = $comment\n";
  } else {
    print "Syntax error for line [$_], missing separators or digits...\n";
  }
}
