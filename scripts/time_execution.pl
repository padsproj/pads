#!/usr/bin/perl -w
#
# time_execution.pl - /usr/bin/time a program and output sum of user and sys.
#
# The user and sys times reported by /usr/bin/time are based on counting
# ticks which are somewhat coarse (typically 10 ms).  Error arises from
# quantization (the entire tick is charged -- or not -- to the process
# when the tick interrupt occurs), software overhead (processing tick and
# other interrupts, etc) and other sources.  While running longer reduces 
# the contribution of quantization at the start and finish, it gives more 
# opportunity for other sources, especially when the system load rises.  
# In general /usr/bin/time's sensitivity to system load is moderately low
# provided the load is compute bound.
# 
# Recommendation: disregard anything not >> precision reported by
# /usr/bin/time (typically 0.01 s).  Treat times around 0.1 second as having
# errors around 20%, times of 1 s as having errors around 10% and times of
# 10 s or more as having errors of 2%.

$sig_figs=2;
$cmd="/usr/bin/time -p @ARGV 2>&1";

open CMD_OUTPUT, "$cmd |";
while (<CMD_OUTPUT>) {
  if (/^(user|sys)\s+(\d+.\d+)$/) {
    $cpu_total += $2;
  }
}
close CMD_OUTPUT;

printf "%.${sig_figs}f\n",$cpu_total;
