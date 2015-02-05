TRULES_MK = 1
include $(PADS_HOME)/mk/rules.mk

DEBUG_TRULES_MK = 1

$(GEN_DIR)/%.c: $(PPATH)/%.p $(PADSC) $(PADSC_REAL)
ifdef DEBUG_TRULES_MK
	@echo "Using trules.mk rule TMP_P_NOACCUM"
endif
	$(PADSC) $< $(PADSC_EXTRA) -r $(GEN_DIR) -anone

tmp_rwxml_%: $(GEN_DIR)/%.c tmp_rwxml_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_TRULES_MK
	@echo "Using trules.mk rule TMP_RWXML_O"
endif
	@$(CCExec_DYNAMIC_O)

tmp_rwxml_%_d: $(GEN_DIR)/%.c tmp_rwxml_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_TRULES_MK
	@echo "Using trules.mk rule TMP_RWXML_D"
endif
	@$(CCExec_DYNAMIC_D)

tmp_rwxml_%_dd: $(GEN_DIR)/%_expanded.c tmp_rwxml_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_TRULES_MK
	@echo "Using trules.mk rule TMP_RWXML_DD"
endif
	@$(CCExec_DYNAMIC_D)
