#!/usr/bin/env perl

my $pads_home = $ENV{"PADS_HOME"};
if ($pads_home eq "") {
  print "\n    env variable PADS_HOME must be set";
  print "\n    set PADS_HOME and try again\n\n";
  exit(-1);
}
my $ptest_dbg = 0;
my $expanded = 0;
my $maxrecs = 0;
my $skippre = 0;
my $skippost = 0;
my $readmask = "P_CheckAndSet";
my $iodiscmk = "P_nlrec_make(0)";
my $parsing_opt_args = 1;
ARG: while ($parsing_opt_args) {
  if ($#ARGV > 0 && ($ARGV[0] eq "-m" || $ARGV[0] eq "--maxrecs")) {
    shift(@ARGV);
    $maxrecs = shift(@ARGV);
    next ARG;
  }
  if ($#ARGV > 0 && ($ARGV[0] eq "-s" || $ARGV[0] eq "--skip-pre")) {
    shift(@ARGV);
    $skippre = shift(@ARGV);
    next ARG;
  }
  if ($#ARGV > 0 && ($ARGV[0] eq "-S" || $ARGV[0] eq "--skip-post")) {
    shift(@ARGV);
    $skippost = shift(@ARGV);
    next ARG;
  }
  if ($#ARGV > 0 && ($ARGV[0] eq "-i" || $ARGV[0] eq "--iodisc")) {
    shift(@ARGV);
    my $idisc = shift(@ARGV);
    if ($idisc eq "norec") {
      $iodiscmk = "P_norec_make(0)";
    } else {
      print "\n    Did not recognize IO discipline $idisc\n";
      goto usage;
    }
    next ARG;
  }
  if ($#ARGV >= 0 && ($ARGV[0] eq "-p" || $ARGV[0] eq "--ptest-debug")) {
    shift(@ARGV);
    $ptest_dbg = 1;
    next ARG;
  }
  if ($#ARGV >= 0 && ($ARGV[0] eq "-e" || $ARGV[0] eq "--expanded-debug")) {
    shift(@ARGV);
    $expanded = 1;
    next ARG;
  }
  if ($#ARGV >= 0 && ($ARGV[0] eq "-d" || $ARGV[0] eq "--debug")) {
    shift(@ARGV);
    $readmask = "P_CheckAndSet|P_DbgRead";
    next ARG;
  }
  if ($ARGV[0] =~ /^[-]/) {
    print "\n    Unknown option: $ARGV[0]\n";
    goto usage;
  }
  $parsing_opt_args = 0;
}
goto usage if ($#ARGV != 1);
my $package = "$pads_home/ast-ast/bin/package.cvs";
my $arch = `$package` || die "\n    Could not execute $package\n\n";
chomp($arch);
my $mtmplf = "$pads_home/scripts/templates/GNUmakefile.ptest";
open (MTMPL, "$mtmplf") || die "\n    Could not open template file $mtmpl\n\n";
my $mtmpl = "";
while (<MTMPL>) {
  $mtmpl .= $_;
}
my $pspec = $ARGV[0];
$pspec =~ s|.*[\/\\]||g;
my $ppath = $ARGV[0];
$ppath =~ s|[\/\\]?[^\/\\]*$||;
if ($ppath eq "") {
  $ppath = ".";
}
if (! ($pspec =~ /.[.]p$/)) {
  print "\n    pspec must have the form [<dirpath>]foo.p\n";
  goto usage;
}
if (! (-e "$ppath/$pspec")) {
  print "\n    pspec $ppath/$pspec does not exist\n";
  goto usage;
}
my $pname = $pspec;
$pname =~ s/[.]p$//;
my $pspec_c = "$pname.c";
my $pspec_h = "$pname.h";
my $pty = $ARGV[1];
my $mfile = "tmp_GNUmakefile.ptest";
my $efile = "tmp_rwxml_$pname";
my $efile_d;
if ($expanded) {
  $efile_d = $efile . "_dd";
} else {
  $efile_d = $efile . "_d";
}
my $cfile = "$efile.c";
my $cfile_tmp = "$efile.c.tmp";
my $gendir = ".";

# print "XXX_REMOVE pspec = $pspec\n";
# print "XXX_REMOVE ppath = $ppath\n";
# print "XXX_REMOVE pname = $pname\n";
# print "XXX_REMOVE pspec_c = $pspec_c\n";
# print "XXX_REMOVE pspec_h = $pspec_h\n";
# print "XXX_REMOVE pty = $pty\n";
# print "XXX_REMOVE maxrecs = $macrecs\n";
# print "XXX_REMOVE mfile = $mfile\n";
# print "XXX_REMOVE efile = $efile\n";
# print "XXX_REMOVE efile_d = $efile_d\n";
# print "XXX_REMOVE cfile = $cfile\n";
# print "\n";

$mtmpl =~ s/=GENDIR=/$gendir/g;
$mtmpl =~ s/=PPATH=/$ppath/g;
$mtmpl =~ s/=EFILE=/$efile_d/g;


open (MOUT, ">$mfile") || die "\n    Could not open $mfile for output\n\n";
print MOUT $mtmpl;
close (MOUT);

open (COUT, ">$arch/$cfile_tmp") || die "\n    Could not open $cfile_tmp for output\n\n";
if ($skippre) { print COUT "#define PRE_SKIP_BYTES $skippre\n"; }
if ($skippost) { print COUT "#define POST_SKIP_BYTES $skippost\n"; }
print COUT "#define PADS_TY(suf) $pty ## suf
#define MAX_RECS $maxrecs
#define READ_MASK $readmask
#define IO_DISC_MK $iodiscmk
#include \"$pspec_h\"
#include \"template/read_orig_write_xml.h\"

";
close(COUT);

my $tres1 = `(cmp $arch/$cfile_tmp $arch/$cfile || echo " DIFFERS") 2>&1`;
if ($tres1 =~ /DIFFERS/) {
  my $tres2 = `mv $arch/$cfile_tmp $arch/$cfile 2>&1`;
  print "PTEST_DBG: cfile did not exist or changed\ncmp result = $tres1\nmv result = $tres2\n\n" if ($ptest_dbg);
} else {
  print "PTEST_DBG: cfile same as last time\ncmp result = $tres1\n" if ($ptest_dbg);
}

print "\nBuilding test program\n";
my $res = `gmake -f $mfile 2>&1` || die "\n    Build of test program failed\n\n";
print "PTEST_DBG: gmake res = \n$res" if ($ptest_dbg);
if ($res =~ /\`?$pty\'?\s+undeclared/is) {
  print "\nBuild of test program failed, ptype $pty not found\n\n";
  exit(-1);
}
if ($res =~ /error/is || $res =~ /no rule/is) {
  print "\n$res\n\nBuild of test program failed, see error(s) above\n\n";
  exit(-1);
}
print "\nRunning test program.\nInput is stdin, you must hit ^D to terminate input and get results.\n\n";
my $res2 = `$arch/$efile_d 2>&1`;
$res2 =~ s|Input file = /dev/stdin||s;
$res2 =~ s|Output file = /dev/stdout||s;
while ($res2 =~ m|\n\n|) {
  $res2 =~ s|\n\n|\n|sg;
}
print "\nResult:\n$res2\n";
my $res3 = `mv $mfile $arch/ 2>&1`;
exit(0);

usage:
print "\n    usage:  ptest.pl [options] <pspec> <ptype>

    where options are:

     -m/--maxrecs #         : specify max # of record to process
     -i/--iodisc <iodisc>   : specify IO discipline, default is nlrec, other choices: norec
     -s/--skip-pre #        : skip specified # of bytes prior to each read call
     -S/--skip-post #       : skip specified # of bytes after each reach call
     -d/--debug             : enable read debugging (init read mask with P_CheckAndSet|P_DbgRead)
     -e/--expanded-debug    : use the _dd build rule (expands macros prior to compilation step)

    Notes: for a record-based discipline, bytes can only be skipped within a given record

";
exit(-1);
