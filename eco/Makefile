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
LIBNAME	 = libeco.a
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
		$(OBJFOLDR)/demand.o \
		$(OBJFOLDR)/economy.o \
		$(OBJFOLDR)/freight.o \
		$(OBJFOLDR)/growth.o \
		$(OBJFOLDR)/industry.o \
		$(OBJFOLDR)/labour.o \
		$(OBJFOLDR)/market.o \
		$(OBJFOLDR)/material.o \
		$(OBJFOLDR)/population.o \
		$(OBJFOLDR)/supply.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/demand.o \
		$(OBJFOLDR)/economy.o \
		$(OBJFOLDR)/freight.o \
		$(OBJFOLDR)/growth.o \
		$(OBJFOLDR)/industry.o \
		$(OBJFOLDR)/labour.o \
		$(OBJFOLDR)/market.o \
		$(OBJFOLDR)/material.o \
		$(OBJFOLDR)/population.o \
		$(OBJFOLDR)/supply.o

$(OBJFOLDR)/demand.o: demand.cpp
	$(CPPTOOL) -c demand.cpp -o $(OBJFOLDR)/demand.o $(CXXFLAGS)

$(OBJFOLDR)/economy.o: economy.cpp
	$(CPPTOOL) -c economy.cpp -o $(OBJFOLDR)/economy.o $(CXXFLAGS)

$(OBJFOLDR)/freight.o: freight.cpp
	$(CPPTOOL) -c freight.cpp -o $(OBJFOLDR)/freight.o $(CXXFLAGS)

$(OBJFOLDR)/growth.o: growth.cpp
	$(CPPTOOL) -c growth.cpp -o $(OBJFOLDR)/growth.o $(CXXFLAGS)

$(OBJFOLDR)/industry.o: industry.cpp
	$(CPPTOOL) -c industry.cpp -o $(OBJFOLDR)/industry.o $(CXXFLAGS)

$(OBJFOLDR)/labour.o: labour.cpp
	$(CPPTOOL) -c labour.cpp -o $(OBJFOLDR)/labour.o $(CXXFLAGS)

$(OBJFOLDR)/market.o: market.cpp
	$(CPPTOOL) -c market.cpp -o $(OBJFOLDR)/market.o $(CXXFLAGS)

$(OBJFOLDR)/material.o: material.cpp
	$(CPPTOOL) -c material.cpp -o $(OBJFOLDR)/material.o $(CXXFLAGS)

$(OBJFOLDR)/population.o: population.cpp
	$(CPPTOOL) -c population.cpp -o $(OBJFOLDR)/population.o $(CXXFLAGS)

$(OBJFOLDR)/supply.o: supply.cpp
	$(CPPTOOL) -c supply.cpp -o $(OBJFOLDR)/supply.o $(CXXFLAGS)