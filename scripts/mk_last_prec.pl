#!/usr/bin/env perl

my $last_recline = "";
my $saved_lines  = "";

while (<>) {
  if (/Pstruct/) {
      print "$last_recline$saved_lines";
      $last_recline = $_;
      $saved_lines  = "";
  } else {
      $saved_lines .= $_;
  }
}
$last_recline =~ s/Pstruct/Precord Pstruct/;
print "$last_recline$saved_lines";
