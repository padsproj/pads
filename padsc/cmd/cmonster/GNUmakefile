
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../../..; pwd)
endif

ifndef AST_ARCH
  export AST_ARCH=$(shell $(PADS_HOME)/ast-ast/bin/package.cvs)
endif

CURDIR := $(shell pwd)
ifneq ($(AST_ARCH),$(notdir $(CURDIR)))
include $(PADS_HOME)/mk/redirect.mk
else

 # The following rules are run from the arch directory

GEN_DIR = .
GEN_WRITE = 1
INCLUDE_DEPS_ADD = ../*.h
include $(PADS_HOME)/mk/rules.mk
# the following indicates that generated .c files should not be removed
.PRECIOUS: $(GEN_DIR)/%.c 

VPATH = ..

GEN_SRC = $(GEN_DIR)/cmdline.c
GEN_OBJ_O = $(GEN_SRC:$(GEN_DIR)/%.c=%.o)
GEN_OBJ_D = $(GEN_SRC:$(GEN_DIR)/%.c=%_d.o)

LOC_SRC = rw_fn.c sval_fn.c tmap.c iodisc.c helpers.c cmonster.c
LOC_OBJ_O = $(LOC_SRC:%.c=%.o)
LOC_OBJ_D = $(LOC_SRC:%.c=%_d.o)

SRC = $(GEN_SRC) $(LOC_SRC)
OBJ_O = $(GEN_OBJ_O) $(LOC_OBJ_O)
OBJ_D = $(GEN_OBJ_D) $(LOC_OBJ_D)

CM_O = cmonster
CM_D = cmonster_d

ALL_PROGS = $(CM_O) $(CM_D)

all: sanity_check $(ALL_PROGS)

sanity_check:
	@$(LibSanityCheck)

clean:
	$(RM) $(ALL_PROGS) mk_rec1vlr_d *.o *~ tmp/*

veryclean: clean
	$(RM) cmdline.h cmdline.c rec1.h rec1.c

cmonster: $(OBJ_O) $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

cmonster_d: $(OBJ_D) $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

mk_rec1vlr_d: mk_rec1vlr.c rec1.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

do_mk: mk_rec1vlr_d
	./mk_rec1vlr_d < ../rec1nl.dat > ../rec1vlr.dat

print_test2out_d: print_test2out.c test2out.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

test_many: cmonster_d
	./cmonster_d -d 'fwrec(:0,8,1:)'         -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat
	./cmonster_d -d 'fwrec_noseek(:0,8,1:)'  -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat
	./cmonster_d -d 'nlrec(:0:)'             -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat
	./cmonster_d -d 'nlrec_noseek(:0:)'      -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat
	./cmonster_d -d 'ctrec(:10,0:)'          -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat
	./cmonster_d -d 'ctrec_noseek(:10,0:)'   -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat
	./cmonster_d -d 'vlrec(:0,0:)'           -c 'c{qy1=Pe_string_FW(:8:)[0]}' < ../rec1vlr.dat 
	./cmonster_d -d 'vlrec_noseek(:0,0:)'    -c 'c{qy1=Pe_string_FW(:8:)[0]}' < ../rec1vlr.dat 

test1: cmonster_d
	./cmonster_d -d 'fwrec(:0,8,1:)'         -c 'c{qy1=Pa_string_FW(:8:)[0]}' -o test1.dat < ../strfw8nl.dat

test2: cmonster_d
	./cmonster_d -d 'fwrec(:0,11,1:)'         -c 's+{qyswitch=Pa_int32_FW(:3:)[0]/-1:c{qy1=Pa_string_FW(:8:)[3]}/0:c{qy2=Pa_string_FW(:7:)[4]}/1:c{qy3=Pa_string_FW(:2:)[5]|qy4=Pa_string_FW(:4:)[7]}}' -o test2.dat < ../sw_aintfw3_astrfw8_nl.dat

 #  An error case: not a legal number of dpsec params 
ertest1: cmonster_d
	./cmonster_d -d 'fwrec(:0,8:)'         -c 'c{qy1=Pa_string_FW(:8:)[0]}' < ../strfw8nl.dat

 #  An error case: not a legal number of ipsec params 
ertest2: cmonster_d
	./cmonster_d -d 'fwrec(:0,8,1:)'         -c 'c{qy1=Pa_string_FW(:8,10:)[0]}' < ../strfw8nl.dat

 #  An error case: not a legal switch type
ertest3: cmonster_d
	./cmonster_d -d 'fwrec(:0,11,1:)'         -c 's-{qyswitch=Pa_string_FW(:3:)[0]/-1:c{qy1=Pa_string_FW(:8:)[3]}/0:c{qy2=Pa_string_FW(:7:)[4]}/1:c{qy3=Pa_string_FW(:6:)[3]}}' -o test3.dat < ../sw_aintfw3_astrfw8_nl.dat

 # End of rules that are run from the arch directory
endif


