Punion choice(:Pint32 w:){
  Pint64_FW(:4:) f;
  Pint64_FW(:w-6:) g;
}

Pstruct foo{
  choice(:10:)    alt;
  Pint32_FW(:4:) paramy;
};


Pselect paramy(:foo a:){a.paramy}; /* offset 4 */
