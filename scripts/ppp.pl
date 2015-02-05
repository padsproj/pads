#!/usr/bin/env perl

goto usage if ($#ARGV != 0);
my $ifilename = $ARGV[0];

my $int_basetype = "(?:(?:Pint|Puint|Pa_int|Pa_uint|Pe_int|Pe_uint|Pb_int|Pb_uint|Pebc_int|Pebc_uint|Pbcd_int|Pbcd_uint|Psbl_int|Psbl_uint|Psbh_int|Psbh_uint|Pebc_fpoint|Pebc_ufpoint|Pbcd_fpoint|Pbcd_ufpoint|Psbl_fpoint|Psbl_ufpoint|Psbh_fpoint|Psbh_ufpoint)(?:8|16|32|64))";
my $int_FW_basetype = "(?:(?:Pint|Puint|Pa_int|Pa_uint|Pe_int|Pe_uint)(?:8|16|32|64)_FW)";
my $other_basetype = "(:?Pchar|Pa_char|Pe_char|Pstring|Pa_string|Pe_string|Pstring_FW|Pa_string_FW|Pe_string_FW|Pstring_ME|Pa_string_ME|Pe_string_ME|Pstring_CME|Pa_string_CME|Pe_string_CME|Pstring_SE|Pa_string_SE|Pe_string_SE|Pstring_CSE|Pa_string_CSE|Pe_string_CSE|Pdate|Pa_date|P_edate|Pipaddr|Pa_ipaddr|Pe_ipaddr|PcountX|Pa_countX|Pe_countX)";
my $basetype = "(?:$int_basetype|$int_FW_basetype|$other_basetype)";

my $lws_pat = &qmeta('\s*');

my $tfmt = "%-30s";
my %pads_ty =
  (
   d => "Pint",
   u => "Puint",
   s => "Pstring"
  );
my %stop_re =
  (
   d => "/[+-]?\\d/",
   u => "/[+]?\\d/",
   s => undef
  );

my ($after, $comment, $d, $elt, $expr, $first_follow, $follow_re);
my ($has_re, $i, $indent, $litpre, $ll, $parsed, $pty);
my ($rest, $toparse, $ty, $w);

open(IFILE, $ifilename) || die "Could not open input file $ifilename\n";

my $line         = 0;
my $emit_lineno  = 1;
my $just_emitted = 0;

my @lines = "";

LINE: while (<IFILE>) {
  $line++;
  if ($emit_lineno) {
    $lines .= "# $line \"$ifilename\"\n";
    $just_emitted = 1;  $emit_lineno  = 0;
  } else {
    $just_emitted = 0;
  }
  if (/^(.*?)\/\/(.*)$/) {
    ($_, $comment) = ($1, $2);
  } elsif (/^(.*?)\/\*(.*?)\*\/\s*$/) {
    ($_, $comment) = ($1, $2);
  } else {
    $comment = "";
  }
  $indent = ""; $rest = "";
  if (/^(\s*)((.*?){(\s*Pre\s*)?:(.+?):}(\s*[;])?(.*))$/) {
    # found a line with >= 1 {: ... :} element
    ($indent, $rest) = ($1, $2);
    $lines .= "# $line \"$ifilename\"\n" if (!$just_emitted);
    $lines .= "// BEGIN PADS pre-processor translation of ${ifilename}:$line\n";
    $lines .= "//   $rest\n";
    $lines .= "// USER_COMMENT: $comment\n" if ($comment);

  ELT: while ($rest =~ /^(.*?){(\s*Pre\s*)?:(.+?):}(\s*[;])?(.*)$/) {
      ($before, $has_re, $toparse, $rest) = ($1, $2, $3, $5);
      $before =~ s/^\s+//;
      $lines .= "$indent$before\n" if ($before);

      $litpre = ($has_re) ? "${indent}Pre \"/" : "${indent}\"";
      $litpost = ($has_re) ? "/\"" : "\"";
      $parsed = "";
      $follow_re = undef;

      while (1) { # parse each %<expr> in the elt
	if (!$toparse) {
	  # done with entire {: ... :} elt
	  $lines .= $parsed;
	  next ELT;
	}
	# look at %<expr> forms one at a time, right to left 
	if ($toparse =~ /^(.*[^\\]%|%)(.*?)$/) {
	  ($toparse, $expr) = ($1, $2);
	  $toparse =~ s/%$//;
	  if ($expr =~ /^(\d*)I(\d+)([du])[(](\w+)[)](.*?)$/) {
	    # handle %Id, %Iu forms
	    ($w, $d, $ty, $id, $after) = ($1, $2, $3, $4, $5);
	    $i = 8;
	    if ($d == 64) {
	      $i = 64;
	    } else {
	      die "Illegal value for <sz> ($d) in %I<sz>$ty, largest legal value is 8, at ${ifilename}:$line\n" if ($d > 8);
	      $i = $d * 8;
	    }
	    $pty = "$pads_ty{$ty}$i";
	    $pty .= "_FW(:${w}:)" if ($w);
	  } elsif ($expr =~ /^(\d*)(l|ll)?(d|u)[(](\w+)[)](.*?)$/) {
	    # handle %d, %u, %ld, %lu, %lld, %llu forms
	    ($w, $ll, $ty, $id, $after) = ($1, $2, $3, $4, $5);
	    $i = ($ll eq "ll") ? 64 : 32;
	    $pty = "$pads_ty{$ty}$i";
	    $pty .= "_FW(:${w}:)" if ($w);
	  } elsif ($expr =~ /^(\d*)(s)[(](\w+)[)](.*?)$/) {
	    # handle %s forms
	    ($w, $ty, $id, $after) = ($1, $2, $3, $4);
	    $pty = $pads_ty{$ty};
	    if ($w) {
	      $pty .= "_FW(:${w}:)";
	    } else {
	      # need a stop re
	      if ($after) {
		$first_follow = substr($after, 0, 1);
		# XXX need to deal with case where $first_follow is a special char XXX
		$follow_re = "/[$first_follow]/";
	      }
	      die "Cannot automatically determine what follows the %s($id) at ${ifilename}:$line\n"
		if (!defined($follow_re));
	      $pty .= "_SE(:\"$follow_re\":)";
	    }
	  } else {
	    # Did not understand %<expr> form
	    die "Did not understand this %<expr> expression: %$expr on ${ifilename}:$line\n";
	  }
	  # determined pty, id, after
	  $elt = sprintf("$indent$tfmt %s;\n", $pty, $id);
	  $elt .= "$litpre$after$litpost;\n" if ($after);
	  $parsed = "$elt$parsed";
	  $follow_re = $stop_re{$ty};
	} else {
	  # last case is to match a leading non %<expr>
	  $parsed = "$litpre$toparse$litpost;\n$parsed";
	  $toparse = "";
	}
      } # end while (1) for each %<expr> in an elt
    } # end while loop over each elt
    # emit rest of line, if any
    $rest =~ s/^\s+//;
    $lines .= "$indent$rest\n" if ($rest);
    $lines .= "// END PADS pre-precessor translation of ${ifilename}:$line\n";
    $emit_lineno = 1;
    next LINE;
  } # end if the line contains >= 1 elt
  # the line does not contain an elt, emit as-is
  if ($comment) {
    chomp;
    $lines .= "$_//$comment\n";
  } else {
    $lines .= $_;
  }
}
$line++;
$lines .= "# $line \"$ifilename\"\n";
$lines .= "_Pdone\n";

$lws_region = 0;
OLINE: foreach $line (split(/\n/, $lines)) {
  $line =~ s/Pre(\s+)\"((?:[^\"]|[\\][\"])*)\"/"Pre$1\"" . &qmeta($2) . "\""/ge;
  if ($line =~ m|//LWS_ON|) {
    $line =~ s|//LWS_ON|// LWS_ON|;
    $lws_region = 1;
  }
  if ($line =~ m|//LWS_OFF|) {
    $line =~ s|//LWS_OFF|// LWS_OFF|;
    $lws_region = 0;
  }
  if ($lws_region) {
    for ($line) {
      1 while s@((?:^|[;])\s*)[\"]((?:[^\"]|[\\][\"])*)[\"](\s*[;])@$1 . "Pre \"/$lws_pat(?:" . quotemeta($2) . ")$lws_pat/\"" . $3@ge;
      1 while s@((?:^|[;])\s*)[\']((?:[^\']|[\\][\'])*)[\'](\s*[;])@$1 . "Pre \"/$lws_pat(?:" . quotemeta($2) . ")$lws_pat/\"" . $3@ge;
      1 while s@((?:^|[;])\s*)($basetype(?:\s+|\(\:(.*?)\:\)\s+)[a-zA-Z]+)@$1 . "Pre \"/$lws_pat/\"__S_E_M_I__ " . $2@ge;
      s@(Psep\s*\(\s*)[\"]((?:[^\"]|[\\][\"])*)[\"](\s*\))@$1 . "Pre \"/$lws_pat(?:" . quotemeta($2) . ")$lws_pat/\"" . $3@e;
    }
    $line =~ s/__S_E_M_I__/;/g
  }
  print "$line\n";
}

exit 0;

usage:
die "Usage: ppp.pl <infile>\n";

sub qmeta
{
  my ($arg) = @_;
  # return quotemeta($arg);
  return $arg;
}
