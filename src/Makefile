PROGRAM = main.out
SRCDIRS = 
CPPFLAGS = -Wall -Wextra -Wshadow -pedantic
SRCEXTS = .c .C .cc .cpp .CPP .c++ .cxx .cp
HDREXTS = .h .H .hh .hpp .HPP .h++ .hxx .hp
CFLAGS = -g -O2 -std=c++20
CXXFLAGS = -g -O2 -std=c++20
CC = g++
CXX = g++
RM = rm -f
DELETES = *.d *.o *.exe *.out *.app 
SHEll = /bin/sh 
EMPTY = 
SPACE = $(EMPTY) $(EMPTY)

ifeq ($(PROGRAM),)
  CUR_PATH_NAMES = $(subst /,$(SPACE),$(subst $(SPACE),_,$(CURDIR)))
  PROGRAM = $(word $(words $(CUR_PATH_NAMES)),$(CUR_PATH_NAMES))
  ifeq ($(PROGRAM),)
    PROGRAM = a.out
  endif
endif
ifeq ($(SRCDIRS),)
  SRCDIRS = .
endif
SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
HEADERS = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(HDREXTS))))
SRC_CXX = $(filter-out %.c,$(SOURCES))
OBJS    = $(addsuffix .o, $(basename $(SOURCES)))
DEPS    = $(OBJS:.o=.d)

DEP_OPT = $(shell if `$(CC) --version | grep "GCC" >/dev/null`; then \
                  echo "-MM -MP"; else echo "-M"; fi )
DEPEND      = $(CC)  $(DEP_OPT)  $(CFLAGS) $(CPPFLAGS)
DEPEND.d    = $(subst -g ,,$(DEPEND))
COMPILE.c   = $(CC)  $(CFLAGS)   $(CPPFLAGS) -c
COMPILE.cxx = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
LINK.c      = $(CC)  $(CFLAGS)   $(CPPFLAGS)
LINK.cxx    = $(CXX) $(CXXFLAGS) $(CPPFLAGS)

.PHONY: all objs clean help show

.SUFFIXES:

all: $(PROGRAM)
objs:$(OBJS)

%.o:%.c
	$(COMPILE.c) $< -o $@
%.o:%.C
	$(COMPILE.cxx) $< -o $@
%.o:%.cc
	$(COMPILE.cxx) $< -o $@
%.o:%.cpp
	$(COMPILE.cxx) $< -o $@
%.o:%.CPP
	$(COMPILE.cxx) $< -o $@
%.o:%.c++
	$(COMPILE.cxx) $< -o $@
%.o:%.cp
	$(COMPILE.cxx) $< -o $@
%.o:%.cxx
	$(COMPILE.cxx) $< -o $@

$(PROGRAM):$(OBJS)
ifeq ($(SRC_CXX),)              # C program
	$(LINK.c)   $(OBJS)  -o $@
	@echo Type ./$@ to execute the program.
else                            # C++ program
	$(LINK.cxx) $(OBJS)  -o $@
	@echo Type ./$@ to execute the program.
endif

ifndef NODEP
ifneq ($(DEPS),)
  sinclude $(DEPS)
endif
endif

clean:
	$(RM) $(DELETES)

help:
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  all       (=make) compile and link.'
	@echo '  objs      compile only (no linking).'
	@echo '  clean     clean objects and the executable file.'
	@echo '  show      show variables (for debug use only).'
	@echo '  help      print this message.'

show:
	@echo 'PROGRAM     :' $(PROGRAM)
	@echo 'SRCDIRS     :' $(SRCDIRS)
	@echo 'HEADERS     :' $(HEADERS)
	@echo 'SOURCES     :' $(SOURCES)
	@echo 'SRC_CXX     :' $(SRC_CXX)
	@echo 'OBJS        :' $(OBJS)
	@echo 'COMPILE.c   :' $(COMPILE.c)
	@echo 'COMPILE.cxx :' $(COMPILE.cxx)
	@echo 'link.c      :' $(LINK.c)
	@echo 'link.cxx    :' $(LINK.cxx)