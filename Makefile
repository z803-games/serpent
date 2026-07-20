PROJECTNAME = serpent

BINS = $(PROJECTNAME).gb

ifndef GBDK_HOME
	$(error GBDK_HOME is not set.)
endif

LCC = $(GBDK_HOME)/bin/lcc

ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif

CSOURCES := $(wildcard src/*.c)
ASMSOURCES := $(wildcard src/*.s)

all: $(BINS)

$(BINS): $(CSOURCES) $(ASMSOURCES)
	$(LCC) $(LCCFLAGS) -o $@ $(CSOURCES) $(ASMSOURCES)

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.noi *.rst
