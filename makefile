SRCDIR  	:= src/
OBJDIR  	:= obj/
BINDIR  	:= bin/
FONTSDIR  	:= fonts/
CONFSDIR  	:= config/
TPDIR 		:= ThirdParty/ 
NAME    	:= cobra
EXE     	:= $(BINDIR)$(NAME)

SFILES  	:= cpp
HFILES  	:= hpp
OFILES  	:= o
JSONFILES  	:= json
FFILES  	:= ttf
CC      	:= g++
CFLAGS  	:= -c -Wall
LFLAGS 		:= -lsfml-graphics -lsfml-window -lsfml-system

FONTSF 		:= $(shell find $(FONTSDIR) -name "*.$(FFILES)")
CONFIGSF	:= $(shell find $(CONFSDIR) -name "*.$(JSONFILES)")
FOBJECTS 	:= $(patsubst $(FONTSDIR)%.$(FFILES), $(BINDIR)$(FONTSDIR)%.$(FFILES), $(FONTSF))
COBJECTS 	:= $(patsubst $(CONFSDIR)%.$(JSONFILES), $(BINDIR)$(CONFSDIR)%.$(JSONFILES), $(CONFIGSF))

SOURCES 	:= $(shell find $(SRCDIR) -name "*.$(SFILES)")
HEADERS 	:= $(shell find $(SRCDIR) -name "*.$(HFILES)")
TPH 		:= $(shell find $(TPDIR) -name "*.$(HFILES)")
OBJECTS 	:= $(patsubst $(SRCDIR)%.$(SFILES), $(OBJDIR)%.$(OFILES), $(SOURCES))

ALLFILES := $(SOURCES)

.PHONY: all clean

all: check_folders $(FOBJECTS) $(COBJECTS) $(EXE)

$(EXE): $(OBJECTS) $(TPH)
	$(CC) $^ -o $@ $(LFLAGS)

$(BINDIR)$(CONFSDIR)%$(JSONFILES): $(CONFSDIR)%$(JSONFILES)
	@rm -f $@
	@mkdir -p $(@D)
	cp -r $^ -t $(@D)
$(BINDIR)$(FONTSDIR)%$(FFILES): $(FONTSDIR)%$(FFILES)
	@rm -f $@
	@mkdir -p $(@D)
	cp -r $< -t $(@D)

$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES) $(SRCDIR)%$(HFILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

check_folders:
	@mkdir -p $(SRCDIR) $(OBJDIR) $(BINDIR)

clean:
	rm -fr $(OBJECTS) $(EXE)
	@rm -fr $(OBJDIR) $(BINDIR)