Punion branches(:Pa_uint32 a, int line_number:) {
  Pswitch (a) {
    // included fields
    Pcase  1 : Pa_int32                         inc_normal_static_w_check : inc_normal_static_w_check % 2 == 0;
    Pcase  2 : Pa_int32                         inc_normal_static;
    Pcase  3 : Pa_string_ME(:"/(.*)X$/":)       inc_normal_dynamic_w_check : inc_normal_dynamic_w_check.len > 4;
    Pcase  4 : Pa_string_ME(:"/(.*)X$/":)       inc_normal_dynamic;
    Pcase  5 : Pcompute int                inc_computed_static_w_check = line_number : inc_computed_static_w_check % 2 == 1;
    Pcase  6 : Pcompute Pa_int32                inc_computed_static         = line_number;

    // omitted fields
    Pcase 11 : Pomit Pa_int32                   omit_normal_static_w_check : omit_normal_static_w_check % 2 == 0;
    Pcase 12 : Pomit Pa_int32                   omit_normal_static;
    Pcase 13 : Pomit Pa_string_ME(:"/(.*)X$/":) omit_normal_dynamic_w_check : omit_normal_dynamic_w_check.len > 4;
    Pcase 14 : Pomit Pa_string_ME(:"/(.*)X$/":) omit_normal_dynamic;
    Pcase 15 : Pcompute Pomit Pa_int32          omit_computed_static_w_check = line_number : omit_computed_static_w_check % 2 == 1;
    Pcase 16 : Pcompute Pomit Pa_int32          omit_computed_static         = line_number;
  }
} 

Precord Pstruct choice{
  Pcompute  int                line_number = position.num;
  Pa_uint32                    a; ' ';
  branches(:a,line_number:)    b;
};
