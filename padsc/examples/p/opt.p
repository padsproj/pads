/* Popt Pstring_ME(:"/[[:alpha:]]+/":) foo(:Puint32 x:); */
Popt Pstring(:x:) foo(:Pchar x:);
/*  This form currently parses, but is not supported. 
    Popt Puint32 bar : {tag == some_bar ? val.some_bar % 2 == 0 : 1}; */

Popt Puint32 baz : Psome i => {i % 2 == 0} ;

/*
Punion foo (:Puint32 x:){
  Pstring_FW(:3 + x:) some_foo;
  Pcompute Pomit Puint32 none_foo = 0;
};
*/

Precord Pstruct entry{
  foo(:'|':) x;
  '|';
  baz f;
  Popt Puint32 biz : Psome b => {b % 2 != 0}; 
  '|';
  Popt Puint32 zot /* : 1 (parses, but not supported) */;
  '_';
  Popt Puint32_FW(: zot.tag == some_zot_t ? zot.val.some_zot_t : 3 :) zig;
};


