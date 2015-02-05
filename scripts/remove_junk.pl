#!/usr/bin/env perl

while (<>) {
  if (/^\s*$/) {
    next;
  }
  if (/XXX_REMOVE/) {
    next;
  }
  if (/fname\s*=/) {
    next;
  }
  if (/<note>(.*)<\/note>/) {
    next;
  }
  print;
}
