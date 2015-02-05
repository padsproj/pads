include $(PADS_HOME)/mk/rules.mk

# A sanity check on the XML Schema definitions
all: 
	$(GALAX_HOME)/bin/galax-mapschema pads.xsd > pads.xq
	$(GALAX_HOME)/bin/galax-mapschema pads-xml.xsd > pads-xml.xq
	$(GALAX_HOME)/bin/galax-mapschema pads-accum.xsd > pads-accum.xq
