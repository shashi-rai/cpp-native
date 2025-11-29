# Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

CPPTOOL	 = g++
CXXINCS  = -I"../inc" 
CXXFLAGS = $(CXXINCS) -std=c++11
RMCLEAN	 = rm -f

LIBMAKR	 = ar
LIBFOLDR = ../lib
LIBNAME	 = libche.a
LIBFILES = $(LIBFOLDR)/$(LIBNAME)
OBJFOLDR = ../obj
OBJFILES = $(OBJFOLDR)/*.o

.PHONY: all all-before all-after clean clean-custom

all: all-before \
	$(LIBFOLDR)/$(LIBNAME) \
	all-after

clean: clean-custom clean-objs clean-libs

clean-objs: clean-custom
	${RMCLEAN} $(OBJFILES)

clean-libs: clean-custom
	${RMCLEAN} $(LIBFILES)

$(LIBFOLDR)/$(LIBNAME): \
		$(OBJFOLDR)/atom.o \
		$(OBJFOLDR)/bond.o \
		$(OBJFOLDR)/electron.o \
		$(OBJFOLDR)/molecule.o \
		$(OBJFOLDR)/nucleus.o \
		$(OBJFOLDR)/orbital.o \
		$(OBJFOLDR)/period.o \
		$(OBJFOLDR)/photon.o \
		$(OBJFOLDR)/polymer.o \
		$(OBJFOLDR)/reaction.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/atom.o \
		$(OBJFOLDR)/bond.o \
		$(OBJFOLDR)/electron.o \
		$(OBJFOLDR)/molecule.o \
		$(OBJFOLDR)/nucleus.o \
		$(OBJFOLDR)/orbital.o \
		$(OBJFOLDR)/period.o \
		$(OBJFOLDR)/photon.o \
		$(OBJFOLDR)/polymer.o \
		$(OBJFOLDR)/reaction.o

$(OBJFOLDR)/atom.o: atom.cpp
	$(CPPTOOL) -c atom.cpp -o $(OBJFOLDR)/atom.o $(CXXFLAGS)

$(OBJFOLDR)/bond.o: bond.cpp
	$(CPPTOOL) -c bond.cpp -o $(OBJFOLDR)/bond.o $(CXXFLAGS)

$(OBJFOLDR)/electron.o: electron.cpp
	$(CPPTOOL) -c electron.cpp -o $(OBJFOLDR)/electron.o $(CXXFLAGS)

$(OBJFOLDR)/molecule.o: molecule.cpp
	$(CPPTOOL) -c molecule.cpp -o $(OBJFOLDR)/molecule.o $(CXXFLAGS)

$(OBJFOLDR)/nucleus.o: nucleus.cpp
	$(CPPTOOL) -c nucleus.cpp -o $(OBJFOLDR)/nucleus.o $(CXXFLAGS)

$(OBJFOLDR)/orbital.o: orbital.cpp
	$(CPPTOOL) -c orbital.cpp -o $(OBJFOLDR)/orbital.o $(CXXFLAGS)

$(OBJFOLDR)/period.o: period.cpp
	$(CPPTOOL) -c period.cpp -o $(OBJFOLDR)/period.o $(CXXFLAGS)

$(OBJFOLDR)/photon.o: photon.cpp
	$(CPPTOOL) -c photon.cpp -o $(OBJFOLDR)/photon.o $(CXXFLAGS)

$(OBJFOLDR)/polymer.o: polymer.cpp
	$(CPPTOOL) -c polymer.cpp -o $(OBJFOLDR)/polymer.o $(CXXFLAGS)

$(OBJFOLDR)/reaction.o: reaction.cpp
	$(CPPTOOL) -c reaction.cpp -o $(OBJFOLDR)/reaction.o $(CXXFLAGS)
