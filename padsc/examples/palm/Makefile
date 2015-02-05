CC=/usr/bin/cc
PADSC=padsc

all: rwxml_palm

palmtoxml: rwxml_palm

rwxml_palm: ../gen/palm.c ../tests/rwxml_palm.c
	$(CC)  -Wall -O2 -DNDEBUG  -I. -I.. -I/home/yitzhak/pads/ast-ast/arch/linux.i386/include/ast -I../gen \
	-I/home/yitzhak/pads/padsc/include $^ -L/home/yitzhak/pads/ast-ast/arch/linux.i386/lib -lpads \
	/home/yitzhak/pads/ast-ast/arch/linux.i386/lib/libast.a  -o ../tests/$@
palm.c: palm.p
	$(PADSC) $<

palm.h: palm.p
	$(PADSC) $<


