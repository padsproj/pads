#!/usr/bin/env perl

$prev_empty = 0;
$pragma_prototyped = 0;
while (<>) {
  if (/^\s*$/) {
    if ($prev_empty == 1) {
      next;
    }
    $prev_empty = 1;
    print;
    next;
  }
  if (/\#pragma prototyped/) {
    if ($pragma_prototyped == 1) {
      next;
    }
    $pragma_prototyped = 1;
    print;
    next;
  }
  print;
  $prev_empty = 0;
}
