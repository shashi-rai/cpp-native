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
LIBNAME	 = libgrt.a
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
		$(OBJFOLDR)/asteroid.o \
		$(OBJFOLDR)/celestial.o \
		$(OBJFOLDR)/comet.o \
		$(OBJFOLDR)/galaxy.o \
		$(OBJFOLDR)/orbit.o \
		$(OBJFOLDR)/planet.o \
		$(OBJFOLDR)/satellite.o \
		$(OBJFOLDR)/star.o \
		$(OBJFOLDR)/universe.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/asteroid.o \
		$(OBJFOLDR)/celestial.o \
		$(OBJFOLDR)/comet.o \
		$(OBJFOLDR)/galaxy.o \
		$(OBJFOLDR)/orbit.o \
		$(OBJFOLDR)/planet.o \
		$(OBJFOLDR)/satellite.o \
		$(OBJFOLDR)/star.o \
		$(OBJFOLDR)/universe.o

$(OBJFOLDR)/asteroid.o: asteroid.cpp
	$(CPPTOOL) -c asteroid.cpp -o $(OBJFOLDR)/asteroid.o $(CXXFLAGS)

$(OBJFOLDR)/celestial.o: celestial.cpp
	$(CPPTOOL) -c celestial.cpp -o $(OBJFOLDR)/celestial.o $(CXXFLAGS)

$(OBJFOLDR)/comet.o: comet.cpp
	$(CPPTOOL) -c comet.cpp -o $(OBJFOLDR)/comet.o $(CXXFLAGS)

$(OBJFOLDR)/galaxy.o: galaxy.cpp
	$(CPPTOOL) -c galaxy.cpp -o $(OBJFOLDR)/galaxy.o $(CXXFLAGS)

$(OBJFOLDR)/orbit.o: orbit.cpp
	$(CPPTOOL) -c orbit.cpp -o $(OBJFOLDR)/orbit.o $(CXXFLAGS)

$(OBJFOLDR)/planet.o: planet.cpp
	$(CPPTOOL) -c planet.cpp -o $(OBJFOLDR)/planet.o $(CXXFLAGS)

$(OBJFOLDR)/satellite.o: satellite.cpp
	$(CPPTOOL) -c satellite.cpp -o $(OBJFOLDR)/satellite.o $(CXXFLAGS)

$(OBJFOLDR)/star.o: star.cpp
	$(CPPTOOL) -c star.cpp -o $(OBJFOLDR)/star.o $(CXXFLAGS)

$(OBJFOLDR)/universe.o: universe.cpp
	$(CPPTOOL) -c universe.cpp -o $(OBJFOLDR)/universe.o $(CXXFLAGS)