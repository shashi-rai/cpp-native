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
LIBNAME	 = libqft.a
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
		$(OBJFOLDR)/action.o \
		$(OBJFOLDR)/charge.o \
		$(OBJFOLDR)/energy.o \
		$(OBJFOLDR)/field.o \
		$(OBJFOLDR)/mass.o \
		$(OBJFOLDR)/particle.o \
		$(OBJFOLDR)/temperature.o \
		$(OBJFOLDR)/time.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/action.o \
		$(OBJFOLDR)/charge.o \
		$(OBJFOLDR)/energy.o \
		$(OBJFOLDR)/field.o \
		$(OBJFOLDR)/mass.o \
		$(OBJFOLDR)/particle.o \
		$(OBJFOLDR)/temperature.o \
		$(OBJFOLDR)/time.o

$(OBJFOLDR)/action.o: action.cpp
	$(CPPTOOL) -c action.cpp -o $(OBJFOLDR)/action.o $(CXXFLAGS)

$(OBJFOLDR)/charge.o: charge.cpp
	$(CPPTOOL) -c charge.cpp -o $(OBJFOLDR)/charge.o $(CXXFLAGS)

$(OBJFOLDR)/energy.o: energy.cpp
	$(CPPTOOL) -c energy.cpp -o $(OBJFOLDR)/energy.o $(CXXFLAGS)

$(OBJFOLDR)/field.o: field.cpp
	$(CPPTOOL) -c field.cpp -o $(OBJFOLDR)/field.o $(CXXFLAGS)

$(OBJFOLDR)/mass.o: mass.cpp
	$(CPPTOOL) -c mass.cpp -o $(OBJFOLDR)/mass.o $(CXXFLAGS)

$(OBJFOLDR)/particle.o: particle.cpp
	$(CPPTOOL) -c particle.cpp -o $(OBJFOLDR)/particle.o $(CXXFLAGS)

$(OBJFOLDR)/temperature.o: temperature.cpp
	$(CPPTOOL) -c temperature.cpp -o $(OBJFOLDR)/temperature.o $(CXXFLAGS)

$(OBJFOLDR)/time.o: time.cpp
	$(CPPTOOL) -c time.cpp -o $(OBJFOLDR)/time.o $(CXXFLAGS)