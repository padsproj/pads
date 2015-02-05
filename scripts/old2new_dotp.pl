#!/usr/bin/env perl

while (<>) {
  s/achar/a_char/g;
  s/astr/a_str/g;

  s/echar/e_char/g;
  s/estr/e_str/g;

  s/aint/a_int/g;
  s/auint/a_uint/g;

  s/eint/e_int/g;
  s/euint/e_uint/g;

  s/bint/b_int/g;
  s/buint/b_uint/g;

  s/adate/a_date/g;
  s/edate/e_date/g;

  s/stringFW/string_FW/g;
  s/stringSE/string_SE/g;
  s/stringCSE/string_CSE/g;

  s/8FW/8_FW/g;
  s/16FW/16_FW/g;
  s/32FW/32_FW/g;
  s/64FW/64_FW/g;

  s/INVALID_AUINT/INVALID_A_NUM/g;
  s/INVALID_AINT/INVALID_A_NUM/g;
  s/INVALID_EUINT/INVALID_E_NUM/g;
  s/INVALID_EINT/INVALID_E_NUM/g;

  print;
}
