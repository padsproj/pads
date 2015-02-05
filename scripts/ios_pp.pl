#!/usr/bin/env perl

$ascii = 1;

while (<>) {
  # escape bad characters
  $_ =~ s/&/&amp;/g;
  $_ =~ s/</&lt;/g;
  # watch out for some specific crap
  $_ =~ s/\x8|\x7f//g;
  #convert any true ctrl-c to ^C
  $_ =~ s/\cC/\^C/g;
  $_ =~ s/[\x80-\xFF]/~/g if $ascii;

  # these will go away
  $_ =~ s/^(\s*(not\s+)?)aaa/\1aaa_e/;
  $_ =~ s/^(\s*(not\s+)?)banner/\1banner_e/;
  $_ =~ s/^(\s*(not\s+)?)bay/\1bay_e/;
  $_ =~ s/^(\s*(not\s+)?)clock/\1clock_e/;
  $_ =~ s/^(\s*(not\s+)?)crashdump/\1crashdump_e/;
  $_ =~ s/^(\s*(not\s+)?)end/\1end_e/;
  $_ =~ s/^(\s*(not\s+)?)enable/\1enable_e/;
  $_ =~ s/^(\s*(not\s+)?)default-te-metric/\1default_te_metric_e/;
  $_ =~ s/^(\s*(not\s+)?)fabric/\1fabric_e/;
  $_ =~ s/^(\s*(not\s+)?)hostname/\1hostname_e/;
  $_ =~ s/^(\s*(not\s+)?)interface/\1interface_e/;
  $_ =~ s/^(\s*(not\s+)?)logging/\1logging_e/;
  $_ =~ s/^(\s*(not\s+)?)module/\1module_e/;
  $_ =~ s/^(\s*(not\s+)?)mpls/\1mpls_e/;
  $_ =~ s/^(\s*(not\s+)?)package-file/\1package_file_e/;
  $_ =~ s/^(\s*(not\s+)?)sample/\1sample_e/;
  $_ =~ s/^(\s*(not\s+)?)server-id/\1server_id_e/;
  $_ =~ s/^(\s*(not\s+)?)server-location/\1server_location_e/;
  $_ =~ s/^(\s*(not\s+)?)snmp-server/\1snmp_server_e/;
  $_ =~ s/^(\s*(not\s+)?)sntp/\1sntp_e/;
  $_ =~ s/^(\s*(not\s+)?)system-password/\1system_password_e/;
  $_ =~ s/^(\s*(not\s+)?)user/\1user_e/;
  $_ =~ s/^(\s*(not\s+)?)watchdog/\1watchdog_e/;

  print;
};

