#!/usr/bin/perl -w
#
# check_performance.pl <baseline_fn> <current_test_fn> <delta_threshold_pct>
#
# Compares the performance metric in file named <current_test_fn> to that
# found in <baseline_fn> and reports findings.  Knowledge about measurement
# accuracy is embedded within this script.  If the measurement is deemed
# sufficiently accurate AND the current performance metric is larger than
# the baseline one by <delta_threshold_pct>, then a "DIFFERS" message is
# triggered (i.e. the performance test is deemed to have failed).
#
# To assist with constructing the baseline database, the tests may be run
# with the environment variable PADS_PERF_REGRESS_BASELINE set to:
# - "AUTO" to have this script automatically create missing baseline files.
# - "FORCE" to have this script overwrite baseline files.
# - an empty string (or unset) for normal operation 
#
# Don't forget to check in updated baseline files!
#
$usage="Usage:\n\tcheck_performance.pl <baseline_fn> <current_test_fn> <delta_threshold_pct>\n";

die $usage if (scalar(@ARGV) != 3);

$baseline_fn="$ARGV[0]";			# file containing baseline
$current_test_fn="$ARGV[1]";			# file containing current
$delta_threshold_pct="$ARGV[2]";		# reporting threshold
$report="$current_test_fn";			# report string
$action=$ENV{"PADS_PERF_REGRESS_BASELINE"};	# what to do if no baseline
$action="" if !defined $action;

#
# Retrieve current measurement
#
if (-r "$current_test_fn") {
  chomp($current=`cat "$current_test_fn"`);
} else {
  print "**** ERROR: $0: Missing current performance file: $current_test_fn\n";
  exit 1;	# trigger a "DIFFERS" message
}
 
#
# Retrieve baseline measurement.  If absent, then provide if action is AUTO or
# FORCE, error otherwise.
#
if (-r "$baseline_fn") {
  chomp($baseline=`cat "$baseline_fn"`);
} else {
  $baseline=$current;
  if ($action eq "AUTO") {
    `echo "$baseline" > "$baseline_fn"`;
    print "**** WARNING: $0: Added missing performance baseline file: $baseline_fn with baseline: $baseline\n";
  } elsif ($action ne "FORCE") {
    print "**** ERROR: $0: Add missing performance baseline file: $baseline_fn with baseline value: $baseline\n";
    exit 1;	# trigger a "DIFFERS" message
  } 
}

#
# Regardless of whether there is a baseline or not, if action is FORCE,
# overwrite baseline with the current value.
#
if ($action eq "FORCE") {
  $baseline=$current;
  `echo "$baseline" > "$baseline_fn"`;
  print "**** WARNING: $0: Forced performance baseline file: $baseline_fn to have value: $baseline\n";
}

#
# Update report string
#
$report=sprintf("%s current=%.3f baseline=%.3f", $report,$current,$baseline);

#
# Compute percent delta
#
if ($baseline == 0) {
  print "**** WARNING: $0: baseline time too brief -> measurement too inaccurate -- not compared\n";
  print $report, "\n";
  exit 0;
}
$normalized_delta_pct=$current * 100 / $baseline - 100;

#
# Update report string
#
$report=sprintf("%s delta=%.2f%% threshold=%d%%",$report,$normalized_delta_pct,$delta_threshold_pct);

#
# Estimate error.
#
if ($current <= 0.1) { 
  print "**** WARNING: $0: execution time too brief -> measurement too inaccurate -- not compared\n";
  print $report, "\n";
  exit 0;
} elsif ($current <= 1.0) {
  $error=20 - (10 * ($current - 0.1) / 0.9);	# for times 0.1 .. 1s, error is 20% .. 10%
} elsif ($current <= 10.0) {
  $error=10 - (8 * ($current - 1) / 9);		# for times 1 .. 10s, error is 10% .. 2%
} else {
  $error=2;					# for times >= 10s, error is 2%
}

#
# Report result taking into account error and threshold 
#
if ($baseline == $current) {
  print "$report: SAME (identical)\n";
  exit 0;
} elsif (abs($normalized_delta_pct) < $error) {
  printf "%s: SAME (within error of %.1f%%)\n", $report, $error;
  exit 0;
} elsif ($delta_threshold_pct < $error) {
  printf "**** WARNING: $0: reporting threshold (%d%%) is within error (%d%%)\n", 
         $delta_threshold_pct, $error;
  exit 0;
} else {
  # the abs percentage difference between current and baseline exceeds 
  # the error estimate and the threshold is set above the error. Now the 
  # comparison of the diff to the threshold is meaningful.
  if ($current > $baseline) {
    if ($normalized_delta_pct > $delta_threshold_pct) {
      print "$report: significantly WORSE (exceeds threshold)\n";
      exit 1;	# trigger a "DIFFERS" message
    }
    print "$report: moderately WORSE (within threshold)\n";
    exit 0;
  } else {
    if ($normalized_delta_pct < -$delta_threshold_pct) {
      print "$report: significantly BETTER (exceeds threshold)\n";
      exit 0;
    }
    print "$report: moderately BETTER (within threshold)\n";
    exit 0;
  }
}
exit 1 	# should not fall through, trigger a "DIFFERS" message.
