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
LIBNAME	 = libcon.a
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
		$(OBJFOLDR)/behaviour.o \
		$(OBJFOLDR)/feedback.o \
		$(OBJFOLDR)/memory.o \
		$(OBJFOLDR)/pattern.o \
		$(OBJFOLDR)/response.o \
		$(OBJFOLDR)/self.o \
		$(OBJFOLDR)/stimulus.o \
		$(OBJFOLDR)/strategy.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/behaviour.o \
		$(OBJFOLDR)/feedback.o \
		$(OBJFOLDR)/memory.o \
		$(OBJFOLDR)/pattern.o \
		$(OBJFOLDR)/response.o \
		$(OBJFOLDR)/self.o \
		$(OBJFOLDR)/stimulus.o \
		$(OBJFOLDR)/strategy.o

$(OBJFOLDR)/behaviour.o: behaviour.cpp
	$(CPPTOOL) -c behaviour.cpp -o $(OBJFOLDR)/behaviour.o $(CXXFLAGS)

$(OBJFOLDR)/feedback.o: feedback.cpp
	$(CPPTOOL) -c feedback.cpp -o $(OBJFOLDR)/feedback.o $(CXXFLAGS)

$(OBJFOLDR)/memory.o: memory.cpp
	$(CPPTOOL) -c memory.cpp -o $(OBJFOLDR)/memory.o $(CXXFLAGS)

$(OBJFOLDR)/pattern.o: pattern.cpp
	$(CPPTOOL) -c pattern.cpp -o $(OBJFOLDR)/pattern.o $(CXXFLAGS)

$(OBJFOLDR)/response.o: response.cpp
	$(CPPTOOL) -c response.cpp -o $(OBJFOLDR)/response.o $(CXXFLAGS)

$(OBJFOLDR)/self.o: self.cpp
	$(CPPTOOL) -c self.cpp -o $(OBJFOLDR)/self.o $(CXXFLAGS)

$(OBJFOLDR)/stimulus.o: stimulus.cpp
	$(CPPTOOL) -c stimulus.cpp -o $(OBJFOLDR)/stimulus.o $(CXXFLAGS)

$(OBJFOLDR)/strategy.o: strategy.cpp
	$(CPPTOOL) -c strategy.cpp -o $(OBJFOLDR)/strategy.o $(CXXFLAGS)
