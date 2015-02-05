Penum states{
    NJ,
    NY,
    CA
};

Punion choice(:Pint32 w:){
  Pint64_FW(:w+4:) f;
  Pint64_FW(:w+4:) g;
}

Pstruct base(:Pint32 w:){
  Pint64_FW(:w+4:) f;           /* size = w + 4 */
}

Ptypedef base(:s + 2:) newBase(:Pint32 s:) : newBase b => {b.f > 100};

Parray seq(:Pint32 z:){
  base(:z:) [z+2] : Psep('a') && Pterm('b');  /* size = (z + 5) * (z + 2) + 1  = z*z + 7z + 11*/
};

Pstruct foo(:Pint32 y:){
  "good";                       /* 4 */
  choice(:y:) unionField;       /* y + 4 */
  states      state;            /* 2 */
  seq(:y - 2:) arrayField;      /* y*y + 3y + 1 */
  Pint32_FW(:y:) paramy;        /* offset = 1 + 4 + 4 + 10 + 4 + 2 + 10*10 + 3 * 10 + 1 = 156, size = y */
  newBase(:y:)  tydef;          /* offset = 166, size = 16 */
  Pint32_FW(:4 + paramy:) param4py;
  Pbcd_uint8(:11:) paramSize6;
};

Pstruct bar{
  '|';                            /* 1 */
  Pb_uint32  x;                   /* 4 */
  foo(:10:) structSize;           
  Pb_uint16  y;
};

Pselect choiceT(:bar z:){z.structSize.unionField.g};    /* param 14, offset 9,   size 14 */
Pselect enumT(:bar z:){z.structSize.state};            /* param 02, offset 23,  size 2 */
Pselect Farray(:bar e:){e.structSize.arrayField[0].f}  /* param 12, offset 25,  size 12 */
Pselect paramy(:bar a:){a.structSize.paramy};          /* param 10, offset 156, size 10 */
Pselect typdef(:bar a:){a.structSize.tydef.f}          /* param 16, offset 166, size 16 */
Pselect paramSize(:bar b:){b.structSize.paramSize6};   /* depends on data */
Pselect param4(:bar c:){c.structSize.param4py};        /* depends on data */

Pselect basic(:Pb_uint8 d:){d};

Pselect array(:bar e:){e.structSize.arrayField[2]}  /* ill-formed */
