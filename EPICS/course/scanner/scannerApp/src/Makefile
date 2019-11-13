TOP=../..

include $(TOP)/configure/CONFIG

DATA += scanner.xml

include $(TOP)/configure/RULES

#----------------------------------------
#  ADD RULES AFTER THIS LINE

#.PHONY chainsrc: $(TOP)/scannerApp/src/chain.xml
#	cp  $< .
#
#scanner.xml: chainsrc
#	/dls_sw/prod/R3.14.12.3/support/ethercat/2-0/etc/scripts/expandChain.py chain.xml > scanner.xml

scanner.xml:
	$(ETHERCAT)/bin/$(T_A)/slaveinfo > chain.xml
	$(ETHERCAT)/etc/scripts/expandChain.py chain.xml > scanner.xml
