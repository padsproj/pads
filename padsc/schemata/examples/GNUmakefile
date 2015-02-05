include $(PADS_HOME)/mk/rules.mk

all: 
	$(GALAX_HOME)/bin/galax-parse -validate -xmlschema ../pads-xml.xsd ai.p.xml
	$(GALAX_HOME)/bin/galax-parse -validate -xmlschema ../pads-xml.xsd sirius.p.xml
	$(GALAX_HOME)/bin/galax-parse -validate -xmlschema ../pads-accum.xsd ai.accum.xml