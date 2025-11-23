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
LIBNAME	 = libphy.a
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
		$(OBJFOLDR)/body.o \
		$(OBJFOLDR)/charge.o \
		$(OBJFOLDR)/direction.o \
		$(OBJFOLDR)/energy.o \
		$(OBJFOLDR)/event.o \
		$(OBJFOLDR)/force.o \
		$(OBJFOLDR)/mass.o \
		$(OBJFOLDR)/momentum.o \
		$(OBJFOLDR)/space.o \
		$(OBJFOLDR)/time.o \
		$(OBJFOLDR)/unit.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/body.o \
		$(OBJFOLDR)/charge.o \
		$(OBJFOLDR)/direction.o \
		$(OBJFOLDR)/energy.o \
		$(OBJFOLDR)/event.o \
		$(OBJFOLDR)/force.o \
		$(OBJFOLDR)/mass.o \
		$(OBJFOLDR)/momentum.o \
		$(OBJFOLDR)/space.o \
		$(OBJFOLDR)/time.o \
		$(OBJFOLDR)/unit.o

$(OBJFOLDR)/body.o: body.cpp
	$(CPPTOOL) -c body.cpp -o $(OBJFOLDR)/body.o $(CXXFLAGS)

$(OBJFOLDR)/charge.o: charge.cpp
	$(CPPTOOL) -c charge.cpp -o $(OBJFOLDR)/charge.o $(CXXFLAGS)

$(OBJFOLDR)/direction.o: direction.cpp
	$(CPPTOOL) -c direction.cpp -o $(OBJFOLDR)/direction.o $(CXXFLAGS)

$(OBJFOLDR)/energy.o: energy.cpp
	$(CPPTOOL) -c energy.cpp -o $(OBJFOLDR)/energy.o $(CXXFLAGS)

$(OBJFOLDR)/event.o: event.cpp
	$(CPPTOOL) -c event.cpp -o $(OBJFOLDR)/event.o $(CXXFLAGS)

$(OBJFOLDR)/force.o: force.cpp
	$(CPPTOOL) -c force.cpp -o $(OBJFOLDR)/force.o $(CXXFLAGS)

$(OBJFOLDR)/mass.o: mass.cpp
	$(CPPTOOL) -c mass.cpp -o $(OBJFOLDR)/mass.o $(CXXFLAGS)

$(OBJFOLDR)/momentum.o: momentum.cpp
	$(CPPTOOL) -c momentum.cpp -o $(OBJFOLDR)/momentum.o $(CXXFLAGS)

$(OBJFOLDR)/space.o: space.cpp
	$(CPPTOOL) -c space.cpp -o $(OBJFOLDR)/space.o $(CXXFLAGS)

$(OBJFOLDR)/time.o: time.cpp
	$(CPPTOOL) -c time.cpp -o $(OBJFOLDR)/time.o $(CXXFLAGS)

$(OBJFOLDR)/unit.o: unit.cpp
	$(CPPTOOL) -c unit.cpp -o $(OBJFOLDR)/unit.o $(CXXFLAGS)