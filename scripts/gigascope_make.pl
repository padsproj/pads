#!/usr/bin/env perl

use Getopt::Long;

my @include_dirs = ();

# =========================
sub readFile
{
    my( $name ) = @_;
    my $data = "";
    undef $/; # set to read to EOF
    open( IN_FILE, "<$name" ) || return "";
    $data = <IN_FILE>;
    $/ = "\n";
    close( IN_FILE );
    return $data;
}

# =========================
sub expandFile
{
    my( $name ) = @_;
    my $incs = "";
    my $incs = "-I" . join(" -I", @include_dirs) if @include_dirs;
    my $data = `cc -x c -E $name $incs` || "";
    if ($data eq "") {
      print "\nUnexpected error: use of cc as preprocessor failed\n\n";
      exit -1;
    }
    $data =~ s/^\#\s+\d+\s+(.*)$//mg;
    while ($data =~ m/\n\n\n/) {
      $data =~ s/\n\n\n/\n\n/;
    }
    return $data;
}

# =========================
sub cleanupStr
{
    my( $txt ) = @_;
    chomp($txt);
    $txt =~ s/\s//g;
    return $txt;
}

# =========================
# main program

my $dbg=1;

print "\n";
my $pads_home = $ENV{"PADS_HOME"};
if ($pads_home eq "") {
  # try to find PADS_HOME from script path
  if ($0 =~ m|/gigascope_make.pl$|) {
    my $path = $0;
    $path =~ s|/gigascope_make.pl$||;
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
my $padsc_cmd = "$pads_home/scripts/padsc";
my $template_dir = "$pads_home/scripts/templates";

push(@include_dirs, $template_dir);
push(@include_dirs, ".");

my %opt = ();
GetOptions( "usage"      => \$usage,
            "demodir:s"  => \$demodir,
            "gigdir:s"   => \$gigdir,
            "pspec:s"    => \$pspec,
            "base:s"     => \$base,
	    "template:s" => \$template,
	    "rectype:s"  => \$rectype,
	    "hdrtype:s"  => \$hdrtype,
	    "nrec:s"     => \$nrec,
	    "maxrecs:i"  => \$maxrecs,
	    "iodisc:s"   => \$iodisc,
            "wspace_ok"  => \$wspace_ok  );

if ($ARGV[0]) {
  print "The following command line arguments were not valid: " . join(' ', @ARGV) . "\n";
  goto usage;
}
goto usage if $usage;

my @missing = ();
push(@missing, "pspec")     if (!defined($pspec));
push(@missing, "template")  if (!defined($template));
push(@missing, "rectype")   if (!defined($rectype));
push(@missing, "hdrtype")   if (!defined($hdrtype) && ($template eq "hdr_recs_repeat" || $template eq "hdr_recs"));
push(@missing, "nrec")      if (!defined($nrec)    && ($template eq "hdr_recs_repeat"));

if (@missing) {
  print "  The following required options are missing: " . join(", ", @missing) . "\n";
  goto usage;
}

my @extra = ();
push(@extra, "hdrtype") if ($hdrtype && $template eq "recs");
push(@extra, "nrec")    if ($nrec    && $template eq "recs");
if (@extra) {
  print "  The following options cannot be used with template $template: " . join(", ", @extra) . "\n";
  goto usage;
}

goto usage if ($template !~ /^(recs|hdr_rec|hdr_recs_repeat)$/);

$base = "udp" if (!defined($base));
goto usage if ($base !~ /^(udp|file)$/);
my $base_suffix = "";
$base_suffix = "_filebase" if ($base eq "file");

if (!defined($iodisc)) {
  $iodisc = "norec";
}

if ($dbg) {
  print "  demodir  = $demodir\n"  if $demodir;
  print "  gigdir   = $gigdir\n"   if $gigdir;
  print "  pspec    = $pspec\n"    if $pspec;
  print "  template = $template\n" if $template;
  print "  rectype  = $rectype\n"  if $rectype;
  print "  hdrtype  = $hdrtype\n"  if $hdrtype;
  print "  maxrecs  = $maxrecs\n"  if $maxrecs;
  print "  iodisc   = $iodisc\n"   if $iodisc;
  print "  nrec     = $nrec\n"     if $nrec;
  print "  wspace_ok set"          if $wpace_ok;
  print "\n";
}

if (!defined($maxrecs)) {
  $maxrecs = 0;
}
if (!defined($demodir)) {
  $demodir = ".";
}
if ($demodir !~ m|/$|) {
  $demodir .= "/";
}
if (!defined($gigdir)) {
  $gigdir = $demodir . "../../";
}
if ($gigdir !~ m|/$|) {
  $gigdir .= "/";
}
my $make_includes = "-I$gigdir" . "include";

if ($iodisc !~ /(norec|nlrec)/) {
  print "  Error: invalid iodisc\n\n" ;
  goto usage;
}

if (!(-e $pspec)) {
  print "  Error: pspec $pspec not found\n\n" ;
  exit -1;
}

my $ptext = &expandFile($pspec);
if ($ptext eq "") {
  print "  Could not open pspec file $pspec for reading\n\n";
  exit -1;
}

if ($ptext !~ /Pstruct\s+$rectype/) {
  print "  Could not find Pstruct $rectype in pspec file $pspec\n\n";
  exit -1;
}

if ($hdrtype && $ptext !~ /Pstruct\s+$hdrtype/) {
  print "  Could not find Pstruct $rectype in pspec file $pspec\n\n";
  exit -1;
}

my %io_disc_mk =
  ( "norec" => "#define IO_DISC_MK P_norec_make(0)",
    "nlrec" => "#define IO_DISC_MK P_nlrec_make(0)"
);

my $pads_ty_define = "#define PADS_TY(suf) $rectype ## suf";
my $template_define = "#define TEMPLATE_$template 1";
my $max_recs_define = "#define MAX_RECS $maxrecs";

my $pads_hdr_ty_define = "";
if ($hdrtype) {
  $pads_hdr_ty_define = "#define PADS_HDR_TY(suf) $hdrtype ## suf";
}

my $wspace_ok_define = "";
if ($wspace_ok) {
  $wspace_ok_define = "#define WSPACE_OK 1";
}

my $pspec_nopath = $pspec;
$pspec_nopath =~ s|^(.*)/||g;
$pspec_nopath =~ s/.p$//;
my $pspec_h_file = "$pspec_nopath" . ".h";

# temp files
my $schema_trans_file  = "$demodir$pspec_nopath" . "_schema.transform";
my $funs_h_trans_file  = "$demodir$pspec_nopath" . "_funs_h.transform";
my $funs_c_trans_file  = "$demodir$pspec_nopath" . "_funs_c.transform";
my $funs_h_tmp_file    = "$demodir$pspec_nopath" . "_funs_tmp.h";
my $funs_c_tmp_file    = "$demodir$pspec_nopath" . "_funs_tmp.c";

my $temp_files = "$schema_trans_file $funs_h_trans_file $funs_c_trans_file $funs_h_tmp_file $funs_c_tmp_file";

# gen target files
my $schema_file        = "$demodir$pspec_nopath" . ".schema";
my $funs_h_file        = "$demodir$pspec_nopath" . "_funs.h";
my $funs_c_file        = "$demodir$pspec_nopath" . "_funs.c";
my $make_file          = "$demodir$pspec_nopath" . ".mk";

my $funs_h_file_nopath = $funs_h_file;
$funs_h_file_nopath =~ s|^(.*)/||g;
my $funs_h_guard = "_" . $funs_h_file_nopath . "_";
$funs_h_guard =~ s/[-]/_/g;
$funs_h_guard =~ s/[.]/_/g;
$funs_h_guard =~ tr/a-z/A-Z/;

my $tfile = "$template_dir/tr_schema_$template$base_suffix";
my $ttext = &expandFile($tfile);
if ($ttext eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}

sub doSubs
{
  my ( $text ) = @_;

  $text =~ s/=PSPEC_NOPATH=/$pspec_nopath/g;
  $text =~ s/=PSPEC_H_FILE=/$pspec_h_file/g;
  $text =~ s/=PSPEC_FILE=/$pspec/g;
  $text =~ s/=SCHEMA_FILE=/$schema_file/g;
  $text =~ s/=FUNS_H_FILE_NOPATH=/$funs_h_file_nopath/g;
  $text =~ s/=FUNS_H_GUARD=/$funs_h_guard/g;
  $text =~ s/=FUNS_H_FILE=/$funs_h_tmp_file/g;
  $text =~ s/=FUNS_C_FILE=/$funs_c_tmp_file/g;
  $text =~ s/=MAKE_FILE=/$make_file/g;
  $text =~ s/=REC_TYPE=/$rectype/g;
  $text =~ s/=HDR_TYPE=/$hdrtype/g if $hdrtype;
  $text =~ s/=NREC_EXPR=/$nrec/;
  $text =~ s/=MAX_RECS_DEFINE=/$max_recs_define/;
  $text =~ s/=IO_DISC_MK_DEFINE=/$io_disc_mk{$iodisc}/;
  $text =~ s/=PADS_TY_DEFINE=/$pads_ty_define/;
  $text =~ s/=PADS_HDR_TY_DEFINE=/$pads_hdr_ty_define/;
  $text =~ s/=TEMPLATE_DEFINE=/$template_define/;
  $text =~ s/=WSPACE_OK_DEFINE=/$wspace_ok_define/;
  $text =~ s/=PADS_HOME=/$pads_home/g;
  $text =~ s/=MAKE_INCLUDES=/$make_includes/g;

  $text =~ s/^\#add_include/\#include/mg;

  return $text;
}

$ttext = &doSubs($ttext);

print "\nCreating $schema_trans_file\n" if ($dbg);
open (TRF, ">$schema_trans_file") or die "\nCould not open temporary file $schema_trans_file for writing\n\n";
print TRF $ttext;
close (TRF);
print "\nDone creating $schema_trans_file\n" if ($dbg);

my $incs = "-I" . join(" -I", @include_dirs) if @include_dirs;

print "\nInvoking padsc on $schema_trans_file\n" if ($dbg);
my $res = `$padsc_cmd -T $schema_trans_file $incs $pspec`;
print "\nDone invoking padsc on $schema_trans_file\n\nres=[$res]\n\n" if ($dbg);

$tfile = "$template_dir/tr_funs_h_$template";
$ttext = &expandFile($tfile);
if ($ttext eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}
$ttext = &doSubs($ttext);

print "\nCreating $funs_h_trans_file\n" if ($dbg);
open (TRF, ">$funs_h_trans_file") or die "\nCould not open temporary file $funs_h_trans_file for writing\n\n";
print TRF $ttext;
close (TRF);
print "\nDone creating $funs_h_trans_file\n" if ($dbg);

print "\nInvoking padsc on $funs_h_trans_file\n" if ($dbg);
$res = `$padsc_cmd -T $funs_h_trans_file $incs $pspec`;
print "\nDone invoking padsc on $funs_h_trans_file\n\nres=[$res]\n\n" if ($dbg);

$tfile = "$template_dir/tr_funs_c_$template";
$ttext = &expandFile($tfile);
if ($ttext eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}
$ttext = &doSubs($ttext);

print "\nCreating $funs_c_trans_file\n" if ($dbg);
open (TRF, ">$funs_c_trans_file") or die "\nCould not open temporary file $funs_c_trans_file for writing\n\n";
print TRF $ttext;
close (TRF);
print "\nDone creating $funs_c_trans_file\n" if ($dbg);

print "\nInvoking padsc on $funs_c_trans_file\n" if ($dbg);
$res = `$padsc_cmd -T $funs_c_trans_file $incs $pspec`;
print "\nDone invoking padsc on $funs_c_trans_file\n\nres=[$res]\n\n" if ($dbg);


$tfile = "$template_dir/funs_h_pre_inc";
my $pre = &readFile($tfile);
if ($pre eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}
$pre = &doSubs($pre);

$tfile = "$funs_h_tmp_file";
my $mid = &readFile($tfile);
if ($mid eq "") {
  print "  Could not read temp file $tfile\n\n";
  exit -1;
}
# $mid = &doSubs($mid);  # do not need to do subs again

$tfile = "$template_dir/funs_h_post_inc";
my $post = &readFile($tfile);
if ($post eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}
$post = &doSubs($post);

print "\nCreating $funs_h_file\n" if ($dbg);
open (TRF, ">$funs_h_file") or die "\nCould not open file $funs_h_file for writing\n\n";
print TRF $pre;
print TRF $mid;
print TRF $post;
close (TRF);
print "\nDone creating $funs_h_file\n" if ($dbg);

$tfile = "$template_dir/funs_c_pre_inc";
$pre = &readFile($tfile);
if ($pre eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}
$pre = &doSubs($pre);

$tfile = "$funs_c_tmp_file";
$mid = &readFile($tfile);
if ($mid eq "") {
  print "  Could not read temp file $tfile\n\n";
  exit -1;
}
# $mid = &doSubs($mid);  # do not need to do subs again

$tfile = "$template_dir/funs_c_post_inc";
$post = &readFile($tfile);
if ($post eq "") {
  print "  Could not find template file $tfile\n\n";
  exit -1;
}
$post = &doSubs($post);

print "\nCreating $funs_c_file\n" if ($dbg);
open (TRF, ">$funs_c_file") or die "\nCould not open file $funs_c_file for writing\n\n";
print TRF $pre;
print TRF $mid;
print TRF $post;
close (TRF);
print "\nDone creating $funs_c_file\n" if ($dbg);

my $tfile = "$template_dir/GNUmakefile.gigascope";
$ttext = &readFile($tfile);
if ($ttext eq "") {
  print "  Could not read template file $tfile\n\n";
  exit -1;
}
$ttext = &doSubs($ttext);

print "\nCreating $make_file\n" if ($dbg);
open (TRF, ">$make_file") or die "\nCould not open file $make_file for writing\n\n";
print TRF $ttext;
close (TRF);
print "\nDone creating $make_file\n" if ($dbg);

$res = `/bin/rm -f $temp_files > /dev/null 2>&1`;

exit 0;

usage:
$tfile = "$template_dir/gig_mk_usage";
$ttext = &readFile($tfile);
if ($ttext eq "") {
  print "  Could not find usage file $tfile\n\n";
  exit -1;
}
print $ttext;
exit -1;
