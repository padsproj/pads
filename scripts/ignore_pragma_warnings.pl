#!/usr/bin/env perl

LINE: while (<STDIN>) {
  if ($#ARGV == 0) {
    if (/ast_common[.]h:\s+No/) {
      open(TmpFile, ">$ARGV[0]") or die "Could not open: $ARGV[0]\n";
      close(TmpFile);
      exit 0;
    }
  }
  next LINE if (/ignoring pragma/);
  if (/In file included from/) {
    my @ermsgs = ();
    push (@ermsgs, $_);
    ERLINE: while (<STDIN>) {
      if (/^\s+from\s/) {
	push (@ermsgs, $_);
	next ERLINE;
      } elsif (/ignoring pragma/) {
	next LINE; # drops everything pushed to ermsgs
      }
      # another kind of error
      push (@ermsgs, $_);
      for $ln ( @ermsgs ) {
	print $ln;
      }
      next LINE;
    }
  }
  print $_;
}
