TOP=..

include $(TOP)/configure/CONFIG

install:
	$(ECASYN)/etc/scripts/expandChain.py vcs_chain.xml > scanner-vcs.xml
	#$(ECASYN)/etc/scripts/expandChain.py chain-ni.xml > scanner-ni.xml

clean:
	-rm scanner.xml scanner-ni.xml

uninstall:

