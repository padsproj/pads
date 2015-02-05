#!/bin/tcsh

set arch = `$PADS_HOME/ast-ast/bin/package.cvs`

#set fname = ~/knb/perl/data/head50K
set fname = /tmp/head1M
#set fname = /fs/dibblerd/los/data/out_sum

set tname = tmp$$

foreach test (`myrand 7 10`)
/bin/rm -f $tname
echo " "
switch ($test)
case 0:
  echo "test0: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib_mod $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib_mod $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 1:
  echo "test1: /bin/time runon 23 ~/knb/perl/countFirstEq21.pl $fname"
  /bin/time runon 23 ~/knb/perl/countFirstEq21.pl $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 2:
  echo "test2: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 3:
  echo "test3: /bin/time runon 23 ~/knb/perl/countFirstEq21_nums.pl $fname"
  /bin/time runon 23 ~/knb/perl/countFirstEq21_nums.pl $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 4:
  echo "test4: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1_mod $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1_mod $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 5:
  echo "test5: /bin/time runon 23 ~/knb/perl/countFirstEq21_split.pl $fname"
  /bin/time runon 23 ~/knb/perl/countFirstEq21_split.pl $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 6:
  echo "test6: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1 $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1 $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
endsw
end

set fname = /fs/dibblerd/los/data/out_sum

foreach test (0 1 2 3 4 5 6)
/bin/rm -f $tname
echo " "
switch ($test)
case 0:
  echo "test0: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib_mod $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib_mod $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 1:
  echo "test1: /bin/time runon 23 ~/knb/perl/countFirstEq21.pl $fname"
  /bin/time runon 23 ~/knb/perl/countFirstEq21.pl $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 2:
  echo "test2: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_fast_dib $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 3:
  echo "test3: /bin/time runon 23 ~/knb/perl/countFirstEq21_nums.pl $fname"
  /bin/time runon 23 ~/knb/perl/countFirstEq21_nums.pl $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 4:
  echo "test4: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1_mod $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1_mod $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 5:
  echo "test5: /bin/time runon 23 ~/knb/perl/countFirstEq21_split.pl $fname"
  /bin/time runon 23 ~/knb/perl/countFirstEq21_split.pl $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
case 6:
  echo "test6: /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1 $fname"
  /bin/time runon 23 ~/knb/padsc/examples/$arch/test_dibbler1 $fname >& $tname
  set res = `cat $tname`
  echo $res
  breaksw
endsw
end

/bin/rm -f $tname
echo " "
