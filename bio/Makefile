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
LIBNAME	 = libbio.a
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
		$(OBJFOLDR)/base.o \
		$(OBJFOLDR)/cell.o \
		$(OBJFOLDR)/chromosome.o \
		$(OBJFOLDR)/gate.o \
		$(OBJFOLDR)/gene.o \
		$(OBJFOLDR)/membrane.o \
		$(OBJFOLDR)/nucleotide.o \
		$(OBJFOLDR)/phosphate.o \
		$(OBJFOLDR)/protein.o \
		$(OBJFOLDR)/sugar.o \
		$(OBJFOLDR)/tissue.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/base.o \
		$(OBJFOLDR)/cell.o \
		$(OBJFOLDR)/chromosome.o \
		$(OBJFOLDR)/gate.o \
		$(OBJFOLDR)/gene.o \
		$(OBJFOLDR)/membrane.o \
		$(OBJFOLDR)/nucleotide.o \
		$(OBJFOLDR)/phosphate.o \
		$(OBJFOLDR)/protein.o \
		$(OBJFOLDR)/sugar.o \
		$(OBJFOLDR)/tissue.o

$(OBJFOLDR)/base.o: base.cpp
	$(CPPTOOL) -c base.cpp -o $(OBJFOLDR)/base.o $(CXXFLAGS)

$(OBJFOLDR)/cell.o: cell.cpp
	$(CPPTOOL) -c cell.cpp -o $(OBJFOLDR)/cell.o $(CXXFLAGS)

$(OBJFOLDR)/chromosome.o: chromosome.cpp
	$(CPPTOOL) -c chromosome.cpp -o $(OBJFOLDR)/chromosome.o $(CXXFLAGS)

$(OBJFOLDR)/gate.o: gate.cpp
	$(CPPTOOL) -c gate.cpp -o $(OBJFOLDR)/gate.o $(CXXFLAGS)

$(OBJFOLDR)/gene.o: gene.cpp
	$(CPPTOOL) -c gene.cpp -o $(OBJFOLDR)/gene.o $(CXXFLAGS)

$(OBJFOLDR)/membrane.o: membrane.cpp
	$(CPPTOOL) -c membrane.cpp -o $(OBJFOLDR)/membrane.o $(CXXFLAGS)

$(OBJFOLDR)/nucleotide.o: nucleotide.cpp
	$(CPPTOOL) -c nucleotide.cpp -o $(OBJFOLDR)/nucleotide.o $(CXXFLAGS)

$(OBJFOLDR)/phosphate.o: phosphate.cpp
	$(CPPTOOL) -c phosphate.cpp -o $(OBJFOLDR)/phosphate.o $(CXXFLAGS)

$(OBJFOLDR)/protein.o: protein.cpp
	$(CPPTOOL) -c protein.cpp -o $(OBJFOLDR)/protein.o $(CXXFLAGS)

$(OBJFOLDR)/sugar.o: sugar.cpp
	$(CPPTOOL) -c sugar.cpp -o $(OBJFOLDR)/sugar.o $(CXXFLAGS)

$(OBJFOLDR)/tissue.o: tissue.cpp
	$(CPPTOOL) -c tissue.cpp -o $(OBJFOLDR)/tissue.o $(CXXFLAGS)