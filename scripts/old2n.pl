#!/usr/bin/env perl

while (<>) {
  s/PDC_/P_/g;
  s/P_(error|errCode|disc|loc_s|loc_t|pos_s|pos_t)/P\1/g; # matches P_errorRep, P_errorf, P_error_t
  s/P_(byte|char|a_char|e_char)/P\1/g; # matches P_charset*
  s/P_(string|a_string|e_string)/P\1/g;
  s/P_(date|a_date|e_date)/P\1/g;
  s/P_(count|a_count|e_count)/P\1/g;
  s/P_(dummy)/P\1/g;
  s/P_(int|a_int|e_int|b_int|bcd_int|ebc_int|sbl_int|sbh_int)/P\1/g;
  s/P_(uint|a_uint|e_uint|b_uint|bcd_uint|ebc_uint|sbl_uint|sbh_uint)/P\1/g;
  s/P_(fpoint|bcd_fpoint|ebc_fpoint|sbl_fpoint|sbh_fpoint)/P\1/g;
  s/P_(ufpoint|bcd_ufpoint|ebc_ufpoint|sbl_ufpoint|sbh_ufpoint)/P\1/g;
  s/pdc_out_macros.h/out_macros.h/g;
  s/P_IO_disc/Pio_disc/g;
  s/P_IO_elt/Pio_elt/g;
  s/_IO_([^A-Z])/_io_\1/g;  # rest are functions, leave as P_ but change IO case, e .g., P_IO_set => P_io_set
  s/at_EOR/at_eor/g;
  s/at_EOF/at_eof/g;
  s/or_EOF/or_eof/g;
  s/P_(default_|inv_|flags_|base_|endian|regexp_|littleE|bigE)/P\1/g;
  s/Cstr/cstr/g;
  s/P_(cstr_|a_cstr_|e_cstr_)/P\1/g;
  s/P_(str_|a_str_|e_str_)/P\1/g;
  s/_RE_/_re_/g;
  s/P_(re_|a_re_|e_re_)/P\1/g;
  s/padsc.h/pads.h/g;
  s/([^b])padsc.h/\1pads.h/g;
  s/padsc-(.+)([.]h)/pads-\1\2/g;
  s/([, \t*&(!>\[]\s*)pdc(\s*[\]=,;:)|?])/\1pads\2/g;
  s/pdc([-][>])/pads\1/g;
  s/pdc(\s+[&][&])/pads\1/g;
  s/pdc_out/pads_out/g;
  s/using pdc/using pads/g;
  s/pdc handle/pads handle/g;
  s=pdc/disc=pads/disc=g;
  s/pdc_io_disc.h/io_disc.h/g;
  s/pdc_string/pads_string/g;
  s/null pdc/null pads/g;
  s/pdc and/pads and/g;
  s/"pdc"/"pads"/g;
  s/pdcIN/padsIN/g;
  print;
}
