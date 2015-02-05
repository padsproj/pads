#!/usr/bin/env perl

top: while (<>) {
  if (/BEGIN_SRCGEN\((.*)\)/) {
    if ($
    $srcgenfile = ">$1";
    open (SFILE, $srcgenfile) || die "could not open $srcgenfile\n";
    $in_srcgen = 1;
    while (<>) {
      if (/END_HEADER/) {
	goto end_srcgen_hdr;
      }
      print SFILE;
    }
    die "END_HEADER not found while writing $srcgenfile header";
  end_srcgen_hdr:
    while (<>) {
    }
  }
  if (/END_SRCGEN/) {
    close(SFILE);
    $in_srcgen = 0;
    next;
  }
  if (/BEGIN_MACROS\((.*)\)/) {
    $macrofile = ">$1";
    if ($in_macros == 1) {
      close(MFILE);
    }
    open (MFILE, $macrofile) || die "could not open $macrofile\n";
    $in_macros = 1;
    while (<>) {
      if (/END_HEADER/) {
	next top;
      }
      print MFILE;
    }
    die "END_HEADER not found while writing $macrofile header";
  }
  if (/END_MACROS/) {
    close(MFILE);
    $in_macros = 0;
    next;
  }
  if ($in_macros == 1) {
    chomp;
    if (/\#define/) {
      print MFILE "\n$_ \\\n";
    } else {
      print MFILE "$_ \\\n";
    }
  } else {
    
  }

  if (!(/\# /)) { # do not emit source file info
    if (/\#define/) {
      print "\n$_ ";
    }
    s/;/;\n/g;
    s/{/{\n/g;
    s/}/}\n/g;
    while (/\n\n/) {
      s/\n\n/\n/g;
    }
    print;
  }
}
