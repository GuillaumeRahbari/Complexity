#=======================================================================
# Basic C++11: Default definitions for makefiles
#-----------------------------------------------------------------------
# Jean-Paul Rigault --- Copyright 2003
#=======================================================================

# Miscellaneous paths (do not forget that this file is included 
# two levels and sometimes three levels below) 

#-----------------------------------------------------------------------
# General variables
#-----------------------------------------------------------------------

DOXYGEN = doxygen

#-----------------------------------------------------------------------
# Compilation and link variables for C and C++
#-----------------------------------------------------------------------

INCL_DIR = .
INCL = -I$(INCL_DIR) 
DEFS = -D_DEBUG_

CXXFLAGS = -g -Wall -std=c++11 
CXX = g++ 
CXX_COMPILE = $(CXX) $(CXXFLAGS) $(INCL) $(DEFS)

CFLAGS = -g -Wall -std=c++11 
CC = g++ 
CC_COMPILE = $(CC) $(CXXFLAGS) $(INCL) $(DEFS)

CXX_LIBS = 
CC_LIBS = 
CXX_LINK = $(CXX)
CC_LINK = $(CC)

#-----------------------------------------------------------------------
# Current directory files
#-----------------------------------------------------------------------

SOURCES = $(wildcard *.c) $(wildcard *.cpp) $(wildcard *.h) 

#-----------------------------------------------------------------------
# Default C/C++ compilation and link rules
#-----------------------------------------------------------------------

%.o :	%.cpp
	$(CXX_COMPILE) -c $*.cpp

% :	%.cpp
	$(CXX_COMPILE) -o $@ $*.cpp

%.o :	%.c
	$(CC_COMPILE) -c $*.c

% :	%.c
	$(CC_COMPILE) -o $@ $*.c

#-----------------------------------------------------------------------
# Targets common to all subordinate Makefiles
# 	Variable ALL must be defined in specific (subordinate) makefiles
#-----------------------------------------------------------------------

# Build everything
all :
	$(MAKE) $(ALL)
	-$(MAKE) extra_all

# Build doc only
doc : .FORCE
	$(DOXYGEN) Doxyfile

# Clean up but keep executables and doc (if any)
clean :
	-rm -f *.o a.out *.ps \#* *~
	-rm -f *.stackdump core
	-$(MAKE) extra_clean

# Clean up all 
full_clean : clean
	-rm -f $(ALL) 
	-rm -rf doc/*

.FORCE :

#-----------------------------------------------------------------------
# Generation of the students initial code
# 	Variable BASEDIR must be defined in specific (subordinate) 
# 	makefiles (relative to $(INITIAL_ROOT)) as well as INITIAL_FILES
#	and SOLUTION_FILES
#-----------------------------------------------------------------------

# Command to remove #ifdef'ed code

UNIFDEF = unifdef

# Current directory

PWD = $(shell pwd)
BASEDIR = $(notdir $(PWD))

# Installation director

INSTALL_DIR = ../../Install

# Install everything

install : install_initial install_solution

# Initial student code

INITIAL_ROOT = $(INSTALL_DIR)/initial
INITIAL_DIR = $(INITIAL_ROOT)/$(BASEDIR)
INITIAL_DEFS = -USOLUTION

install_initial : .FORCE
	-mkdir -p $(INITIAL_DIR)
	-for file in $(INITIAL_FILES); do \
	     $(UNIFDEF) $(INITIAL_DEFS) $$file > $(INITIAL_DIR)/$$file; \
	 done
	cp makefile.initial $(INITIAL_DIR)/makefile
	cp ../default.mk $(INITIAL_DIR)
	cd $(INITIAL_DIR)/..; tar cvzf $(BASEDIR)-initial.tgz $(BASEDIR)
	$(MAKE) extra_initial

# Solution code

SOLUTION_ROOT = $(INSTALL_DIR)/solution
SOLUTION_DIR = $(SOLUTION_ROOT)/$(BASEDIR)
SOLUTION_DEFS = -DSOLUTION

install_solution : .FORCE
	-mkdir -p $(SOLUTION_DIR)
	-for file in $(SOLUTION_FILES); do \
	     $(UNIFDEF) $(SOLUTION_DEFS) $$file > $(SOLUTION_DIR)/$$file; \
	 done
	make doc
	cp -r doc $(SOLUTION_DIR)
	cp makefile.solution $(SOLUTION_DIR)/makefile
	cp ../default.mk $(SOLUTION_DIR)
	cd $(SOLUTION_DIR)/..; tar cvzf $(BASEDIR)-solution.tgz $(BASEDIR)
	$(MAKE) extra_solution

# Clean up install directories

install_clean : 
	-rm -rf $(INITIAL_ROOT)/$(BASEDIR)-initial.tgz $(INITIAL_DIR)
	-rm -rf $(SOLUTION_ROOT)/$(BASEDIR)-solution.tgz $(SOLUTION_DIR)
