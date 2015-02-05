#include "vanilla.p"
Popt Pstring_ME(:"/:/":)  Opt_10;
Pstruct Struct_17 {
	Opt_10 var_10;
	PPwhite var_15;
};
Popt Struct_17 Opt_18;
Popt Pstring_ME(:"/\\;/":)  Opt_26;
Pstruct Struct_31 {
	PPstring var_21;
	Opt_26 var_26;
};
Pstruct Struct_45 {
	Pint8 var_41 : var_41 == -9;
	':';
};
Punion Switch_50(:Pint64  var_35:) {
  Pswitch (var_35) {
	Pcase 1 : 	Struct_45 var_45_0;
	Pcase 1992 : 	var_47_1 Pfrom(';');
  }
};
Pstruct Struct_33 {
	Pint64 var_35;
	Switch_50(:var_35:) var_50;
};
Punion Union_32 {
	Struct_31 var_31;
	Struct_33 var_33;
	var_52 Pfrom('-');
	var_56 Pfrom('/');
	var_60 Pfrom('=');
};
Pstruct Struct_66 {
	Union_32 var_32;
	PPwhite var_64;
};
Parray Array_5 {
	Struct_66[] : Plongest;
};
Pstruct Struct_87 {
	'(';
	PPstring var_81;
	')';
};
Punion Union_71 {
	Struct_87 var_87;
	PPstring var_68;
	Pcompute Pint8 var_72 = 0;
};
Pstruct Struct_0 {
	PPstring var_2;
	Opt_18 var_18;
	Array_5 var_5;
	Union_71 var_71;
};
Pstruct Struct_154 {
	PPstring var_103;
	PPwhite var_105;
	PPstring var_107;
	PPwhite var_109;
	Puint16 var_112 : var_112 == 2002;
	PPwhite var_114;
	PPstring var_116;
	PPwhite var_118;
	PPstring var_120;
	PPwhite var_122;
	PPstring var_124;
	PPwhite var_126;
	PPstring var_128;
	PPwhite var_130;
	PPstring var_132;
	PPwhite var_134;
	PPstring var_136;
	'.';
	PPwhite var_141;
	PPstring var_143;
	PPwhite var_145;
	PPstring var_147;
	PPwhite var_149;
	Puint16 var_152 : var_152 == 2002;
};
Pstruct Struct_185 {
	PPstring var_172;
	PPwhite var_175;
	PPstring var_177;
	PPwhite var_180;
	PPstring var_182;
};
Punion Union_155 {
	Struct_154 var_154;
	Struct_185 var_185;
	PPstring var_188;
};
Penum Enum_199 {
	the199 Pfrom("the"),
	Inc199 Pfrom("Inc")
};
Pstruct Struct_657 {
	' ';
	PPstring var_230;
};
Parray Array_232 {
	Struct_657[6] : Plongest;
};
Popt Array_232 Opt_206;
Popt PPwhite  Opt_238;
Pstruct Struct_244 {
	PPwhite var_97;
	PPstring var_99;
	PPwhite var_101;
	Union_155 var_155;
	',';
	PPwhite var_194;
	Enum_199 var_199;
	Opt_206 var_206;
	'.';
	Opt_238 var_238;
};
Pstruct Struct_361 {
	'.';
	PPstring var_248;
	'.';
	PPwhite var_252;
	PPstring var_254;
	PPwhite var_256;
	PPstring var_258;
	PPwhite var_260;
	PPstring var_262;
	',';
	PPwhite var_266;
	PPstring var_268;
	PPwhite var_270;
	PPstring var_272;
	PPwhite var_274;
	PPstring var_276;
	',';
	PPwhite var_280;
	PPstring var_282;
	PPwhite var_284;
	PPstring var_286;
	PPwhite var_288;
	PPstring var_290;
	PPwhite var_292;
	'(';
	PPstring var_297;
	',';
	PPwhite var_301;
	PPstring var_303;
	':';
	PPwhite var_307;
	PPstring var_309;
	PPwhite var_311;
	PPstring var_313;
	"),";
	PPwhite var_321;
	PPstring var_323;
	PPwhite var_325;
	Puint8 var_327 : var_327 == 21;
	',';
	PPwhite var_331;
	PPstring var_333;
	PPwhite var_335;
	PPstring var_337;
	PPwhite var_339;
	PPurl var_341;
	PPstring var_343;
	PPwhite var_345;
	PPstring var_347;
	PPwhite var_349;
	PPstring var_351;
	PPwhite var_353;
	PPdate var_355;
	Puint8 var_357 : var_357 == 4;
	'.';
};
Punion Union_362 {
	Struct_244 var_244;
	Struct_361 var_361;
};
Pstruct Struct_367 {
	'\"';
	PPstring var_93;
	Union_362 var_362;
	'\"';
};
Punion Union_369 {
	Struct_0 var_0;
	Struct_367 var_367;
	Pcompute Pint8 var_368 = 0;
};
Popt Pstring_ME(:"/\\./":)  Opt_388;
Penum Enum_395 {
	Francisco395 Pfrom("Francisco"),
	Orleans395 Pfrom("Orleans"),
	Angeles395 Pfrom("Angeles"),
	Worth395 Pfrom("Worth"),
	Louis395 Pfrom("Louis"),
	Haven395 Pfrom("Haven"),
	Diego395 Pfrom("Diego"),
	York395 Pfrom("York"),
	Lake395 Pfrom("Lake"),
	Jose395 Pfrom("Jose")
};
Pstruct Struct_406 {
	PPwhite var_402;
	PPstring var_404;
};
Popt Struct_406 Opt_400;
Pstruct Struct_407 {
	Opt_388 var_388;
	' ';
	Enum_395 var_395;
	Opt_400 var_400;
};
Popt Struct_407 Opt_383;
Popt Pstring_ME(:"/ /":)  Opt_415;
Pstruct Struct_424 {
	'\"';
	PPstring var_376;
	Opt_383 var_383;
	',';
	Opt_415 var_415;
	PPstring var_412;
	'\"';
};
Pstruct Struct_442 {
	PPstring var_432;
	PPwhite var_434;
	PPstring var_436;
	PPwhite var_438;
	PPstring var_440;
};
Punion Union_425 {
	Struct_424 var_424;
	Struct_442 var_442;
	Pcompute Pint8 var_426 = 0;
};
Pstruct Struct_470 {
	PPstring var_460;
	PPwhite var_462;
	PPstring var_464;
	PPwhite var_466;
	PPstring var_468;
};
Penum Enum_455 {
	NA455 Pfrom("NA"),
	U455 Pfrom("U")
};
Punion Union_448 {
	Struct_470 var_470;
	Enum_455 var_455;
	Pint64 var_445;
	Pcompute Pint8 var_449 = 0;
};
Penum Enum_478 {
	NA478 Pfrom("NA"),
	U478 Pfrom("U")
};
Punion Union_476 {
	Enum_478 var_478;
	Pint64 var_473;
	Pcompute Pint8 var_482 = 0;
};
Penum Enum_490 {
	NA490 Pfrom("NA"),
	U490 Pfrom("U")
};
Punion Union_488 {
	Enum_490 var_490;
	Pint64 var_485;
	Pcompute Pint8 var_494 = 0;
};
Penum Enum_502 {
	NA502 Pfrom("NA"),
	U502 Pfrom("U")
};
Punion Union_500 {
	Enum_502 var_502;
	Pint64 var_497;
	Pcompute Pint8 var_506 = 0;
};
Penum Enum_514 {
	NA514 Pfrom("NA"),
	U514 Pfrom("U")
};
Punion Union_512 {
	Enum_514 var_514;
	Pint64 var_509;
	Pcompute Pint8 var_517 = 0;
};
Punion Union_524 {
	'U';
	Pint64 var_521;
	Pcompute Pint8 var_529 = 0;
};
Punion Union_536 {
	Pint64 var_533;
	PPstring var_543;
	Pcompute Pint8 var_537 = 0;
};
Parray Array_577 {
	PPstring [4] : Psep(' ') && Plongest;
};
Penum Enum_558 {
	NA558 Pfrom("NA"),
	U558 Pfrom("U")
};
Punion Union_551 {
	Array_577 var_577;
	Enum_558 var_558;
	Pint64 var_548;
	Pcompute Pint8 var_552 = 0;
};
Penum Enum_585 {
	NA585 Pfrom("NA"),
	U585 Pfrom("U")
};
Punion Union_583 {
	Enum_585 var_585;
	Pint64 var_580;
	Pcompute Pint8 var_589 = 0;
};
Penum Enum_597 {
	NA597 Pfrom("NA"),
	U597 Pfrom("U")
};
Punion Union_595 {
	Enum_597 var_597;
	Pint64 var_592;
	Pcompute Pint8 var_601 = 0;
};
Penum Enum_609 {
	NA609 Pfrom("NA"),
	U609 Pfrom("U")
};
Punion Union_607 {
	Enum_609 var_609;
	Pint64 var_604;
	Pcompute Pint8 var_613 = 0;
};
Penum Enum_621 {
	NA621 Pfrom("NA"),
	U621 Pfrom("U")
};
Punion Union_619 {
	Enum_621 var_621;
	Pint64 var_616;
	Pcompute Pint8 var_624 = 0;
};
Punion Union_631 {
	'U';
	Pint64 var_628;
	Pcompute Pint8 var_636 = 0;
};
Punion Union_643 {
	Pint64 var_640;
	PPstring var_650;
	Pcompute Pint8 var_644 = 0;
};
Precord Pstruct Struct_653 {
	Union_369 var_369;
	',';
	Union_425 var_425;
	',';
	Union_448 var_448;
	',';
	Union_476 var_476;
	',';
	Union_488 var_488;
	',';
	Union_500 var_500;
	',';
	Union_512 var_512;
	',';
	Union_524 var_524;
	',';
	Union_536 var_536;
	',';
	Union_551 var_551;
	',';
	Union_583 var_583;
	',';
	Union_595 var_595;
	',';
	Union_607 var_607;
	',';
	Union_619 var_619;
	',';
	Union_631 var_631;
	',';
	Union_643 var_643;
};
Psource Parray entries_t {
	Struct_653[];
};
