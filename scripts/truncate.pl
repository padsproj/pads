#!/usr/bin/env perl

goto usage if ($#ARGV != 1);
goto usage if ($ARGV[1] !~ /^\d+$/);
print "truncate($ARGV[0], $ARGV[1])\n";
truncate($ARGV[0], $ARGV[1]) || die("truncate failed\n");
exit(0);

usage:
print "usage: truncate <file> <bytes>\n";
exit(-1);
