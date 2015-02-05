#!/usr/bin/env perl

# these should be command line arguments or ENV vars (or a combination)
my $dbg=1;
my $targdir="./";
my $ver="0.1";
my $cvsroot = ":ext:raptor.research.att.com:/home/padsproj/cvsroot";
my $export_arg = "-D '" . `date`. "'"; # export as of 'now'
# (will probably want to use tag based export)

my $tmpdir = $targdir . "tmp_pads_$ver";
my $topdir = $targdir . "pads_$ver";

my $pads_home = $ENV{"PADS_HOME"};
if ($pads_home eq "") {
  # try to find PADS_HOME from script path
  if ($0 =~ m|/[a-zA-Z0-9_\.]+.pl$|) {
    my $path = $0;
    $path =~ s|/[a-zA-Z0-9_\.]+.pl$||;
    $path .= "/..";
    $pads_home = `(cd $path; pwd)` || "";
    $pads_home = &cleanupStr($pads_home);
    print "\n*** Guessing PADS_HOME = [$pads_home]\n\n" if ($dbg);
  }
}
if ($pads_home eq "") {
  print "\n    Error: either env variable PADS_HOME must be set
           OR the invocation of this script must have a path component
           so that the script can figure out PADS_HOME

    Set PADS_HOME or use a relative or absolute path to the script and try again\n\n";
  exit -1;
}

&docmd("mkdir -p $tmpdir");
&docmd("cd $tmpdir; cvs -d $cvsroot export $export_arg pads");

&docmd("/bin/rm -rf $topdir");
&docmd("mv $tmpdir/pads $topdir");
&docmd("/bin/rm -rf $tmpdir");

# Replace the checked in ast-zip and INIT packages
# with alternate ast-ast and INIT packages.
# This is to avoid building the compression libraries.

&docmd("/bin/rm -rf $topdir/ast-ast/lib/package/tgz/*.tgz");
&docmd("cp $pads_home/scripts/release/*.tgz $topdir/ast-ast/lib/package/tgz/");

my $release_tfiles = &docmd("cat $topdir/padsc/examples/tests/RELEASE_TESTS");
my $all_tfiles = &docmd("cd $topdir/padsc/examples/tests; ls -d *.c");
my $all_dfiles = &docmd("cd $topdir/padsc/examples/data; ls -d *");
my $all_rfiles = &docmd("cd $topdir/padsc/examples/regress; ls -d *");

my $release_sfiles = &docmd("cat $topdir/scripts/RELEASE_SCRIPTS");
my $all_sfiles = &docmd("cd $topdir/scripts; ls -d *");

my $release_pfiles = &docmd("cat $topdir/padsc/examples/p/RELEASE_PFILES");
my $all_pfiles = &docmd("cd $topdir/padsc/examples/p; ls -d *.p");

my ($f1, $f2);

my %rel_tfile = ();
my %rel_dfile = ();
my %rel_rfile = ();
my %rel_sfile = ();
my %rel_pfile = ();

# init dfile with some special cases
$rel_dfile{"endian.delenn"} = 1;
$rel_dfile{"endian.raptor"} = 1;

foreach $f1 (split(/\s/, $release_tfiles)) {
    $rel_tfile{$f1} = 1;
    $f2 = $f1;
    $f2 =~ s/\.c$//;
    $f2 =~ s/^(test_|rwxml_|rw_)//;
    $rel_dfile{$f2} = 1;
    $f2 = $f1;
    $f2 =~ s/\.c$/\.regress/;
    $rel_rfile{$f2} = 1;
}
foreach $f1 (split(/\s/, $release_sfiles)) {
    $rel_sfile{$f1} = 1;
}
foreach $f1 (split(/\s/, $release_pfiles)) {
    $rel_pfile{$f1} = 1;
}

foreach $f1 (split(/\s/, $all_tfiles)) {
    next if ($f1 eq "CVS");
    if (!defined($rel_tfile{$f1})) {
	&docmd("/bin/rm -f $topdir/padsc/examples/tests/$f1");
    }
}
foreach $f1 (split(/\s/, $all_dfiles)) {
    next if ($f1 eq "CVS");
    if (!defined($rel_dfile{$f1})) {
	&docmd("/bin/rm -rf $topdir/padsc/examples/data/$f1");
    }
}
foreach $f1 (split(/\s/, $all_rfiles)) {
    next if ($f1 eq "CVS");
    if (!defined($rel_rfile{$f1})) {
	&docmd("/bin/rm -f $topdir/padsc/examples/regress/$f1");
    }
}
foreach $f1 (split(/\s/, $all_sfiles)) {
    next if ($f1 eq "CVS");
    next if ($f1 eq "templates");
    if (!defined($rel_sfile{$f1})) {
	&docmd("/bin/rm -f $topdir/scripts/$f1");
    }
}
foreach $f1 (split(/\s/, $all_pfiles)) {
    next if ($f1 eq "CVS");
    if (!defined($rel_pfile{$f1})) {
	&docmd("/bin/rm -f $topdir/padsc/examples/p/$f1");
    }
}

# remove other unwanted dirs
&docmd("/bin/rm -rf $topdir/documents $topdir/Notes $topdir/padsc/examples/xml $topdir/padsc/libpglx $topdir/padsc/cmd $topdir/padsc/examples/NOTES $topdir/padsc/examples/cbtests $topdir/padsc/examples/copybook");

# remove other unwanted files
# need to keep pglx-codegen-macros.h, possibly some others
# &docmd("cd $topdir/padsc/include; mv pglx-codegen-macros.h foo.h; /bin/rm -f *pglx*; mv foo.h pglx-codegen-macros.h");

# other fixups
&docmd("cd $topdir/padsc/examples/tests; mv GNUmakefile.release GNUmakefile");

# make the tarball
&docmd("cd $topdir/..; gtar cfz $topdir.tar.gz $topdir");

exit 0;

usage:
    print "\n\nUsage: release.pl [options]\n\n";
    exit -1;

# =========================
sub cleanupStr
{
    my( $txt ) = @_;
    chomp($txt);
    $txt =~ s/\s//g;
    return $txt;
}

# =========================
sub docmd {
    my ($cmd) = @_;
    my $res = `$cmd` || "";
    chomp($res);
    print "CMD [$cmd] RES [$res]\n" if ($dbg);
    return $res;
}

# =========================

