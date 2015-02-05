#!/usr/bin/perl
#############################################################################################
#
#  By:		Steven Buznitsky
#  Date:	3/8/2005
#
#  Purpose:  This script will be used to consume SNORT/Honeypot logs and produce very
#  simple NSM Messages.  The intention is then to have the output sent into the breaknsmstream.pl
#  script to create seperate files which will eventually be sent to Middletown and Secaucus
#  Event Collectors.
#
#############################################################################################
use POSIX;
while (defined($nread = <STDIN>)) {
	chomp($nread);
	$_=$nread;
	$ORIG_MESSAGE=$nread;

	if ( /(\w+) (\d+) (\d+:\d+:\d+) (\d+.\d+.\d+.\d+) (\w+): (.*)/ ) {
	$MESSAGE=$6;
#	$MESSAGE=$';
	$MONTH=$1;
	$DAY=$2;
	$TIME=$3;
	$FACILITY_IP=$4;
	$PROCESS=$5;
	$YEAR=strftime('%Y',localtime());
	$ORIG_MESSAGE=$_;
	print STDOUT "syslog\n";
	print STDOUT "orig_message $ORIG_MESSAGE\n";
	print STDOUT "message $MESSAGE\n";
	print STDOUT "facility 4\n";
	print STDOUT "facility_ip $FACILITY_IP\n";
	print STDOUT "process $PROCESS\n";
	print STDOUT "d_date $YEAR-$MONTH-$DAY\n";
	print STDOUT "d_time $TIME\n";
	print STDOUT "endsyslog\n";
	$|=1;
	}
}
