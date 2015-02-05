#!/usr/bin/env perl

while (<>) {
  s/PDC_char_lit_read\s*\(/PDC_char_lit_read_internal\(/g;
  s/PDC_str_lit_read\s*\(/PDC_str_lit_read_internal\(/g;
  s/PDC_countX\s*\(/PDC_countX_internal\(/g;
  s/PDC_countXtoY\s*\(/PDC_countXtoY_internal\(/g;
  s/PDC_adate_read\s*\(/PDC_adate_read_internal\(/g;
  s/PDC_astring_read\s*\(/PDC_astring_read_internal\(/g;
  s/PDC_astringFW_read\s*\(/PDC_astringFW_read_internal\(/g;
  s/PDC_astringSE_read\s*\(/PDC_astringSE_read_internal\(/g;
  s/PDC_astringCSE_read\s*\(/PDC_astringCSE_read_internal\(/g;
  s/int8_read\s*\(/int8_read_internal\(/g;
  s/int16_read\s*\(/int16_read_internal\(/g;
  s/int32_read\s*\(/int32_read_internal\(/g;
  s/int64_read\s*\(/int64_read_internal\(/g;
  s/int8FW_read\s*\(/int8FW_read_internal\(/g;
  s/int16FW_read\s*\(/int16FW_read_internal\(/g;
  s/int32FW_read\s*\(/int32FW_read_internal\(/g;
  s/int64FW_read\s*\(/int64FW_read_internal\(/g;
  print;
}
