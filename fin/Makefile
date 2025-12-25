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
LIBNAME	 = libfin.a
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
		$(OBJFOLDR)/commodity.o \
		$(OBJFOLDR)/future.o \
		$(OBJFOLDR)/index.o \
		$(OBJFOLDR)/option.o \
		$(OBJFOLDR)/securities.o \
		$(OBJFOLDR)/stock.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/commodity.o \
		$(OBJFOLDR)/future.o \
		$(OBJFOLDR)/index.o \
		$(OBJFOLDR)/option.o \
		$(OBJFOLDR)/securities.o \
		$(OBJFOLDR)/stock.o

$(OBJFOLDR)/commodity.o: commodity.cpp
	$(CPPTOOL) -c commodity.cpp -o $(OBJFOLDR)/commodity.o $(CXXFLAGS)

$(OBJFOLDR)/future.o: future.cpp
	$(CPPTOOL) -c future.cpp -o $(OBJFOLDR)/future.o $(CXXFLAGS)

$(OBJFOLDR)/index.o: index.cpp
	$(CPPTOOL) -c index.cpp -o $(OBJFOLDR)/index.o $(CXXFLAGS)

$(OBJFOLDR)/option.o: option.cpp
	$(CPPTOOL) -c option.cpp -o $(OBJFOLDR)/option.o $(CXXFLAGS)

$(OBJFOLDR)/securities.o: securities.cpp
	$(CPPTOOL) -c securities.cpp -o $(OBJFOLDR)/securities.o $(CXXFLAGS)

$(OBJFOLDR)/stock.o: stock.cpp
	$(CPPTOOL) -c stock.cpp -o $(OBJFOLDR)/stock.o $(CXXFLAGS)
