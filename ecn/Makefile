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
LIBNAME	 = libecn.a
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
		$(OBJFOLDR)/capacitance.o \
		$(OBJFOLDR)/capacitor.o \
		$(OBJFOLDR)/circuit.o \
		$(OBJFOLDR)/coil.o \
		$(OBJFOLDR)/conductor.o \
		$(OBJFOLDR)/core.o \
		$(OBJFOLDR)/diode.o \
		$(OBJFOLDR)/element.o \
		$(OBJFOLDR)/inductance.o \
		$(OBJFOLDR)/inductor.o \
		$(OBJFOLDR)/parallel.o \
		$(OBJFOLDR)/reluctance.o \
		$(OBJFOLDR)/resistance.o \
		$(OBJFOLDR)/resistor.o \
		$(OBJFOLDR)/series.o \
		$(OBJFOLDR)/source.o \
		$(OBJFOLDR)/transistor.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/capacitance.o \
		$(OBJFOLDR)/capacitor.o \
		$(OBJFOLDR)/circuit.o \
		$(OBJFOLDR)/coil.o \
		$(OBJFOLDR)/conductor.o \
		$(OBJFOLDR)/core.o \
		$(OBJFOLDR)/diode.o \
		$(OBJFOLDR)/element.o \
		$(OBJFOLDR)/inductance.o \
		$(OBJFOLDR)/inductor.o \
		$(OBJFOLDR)/parallel.o \
		$(OBJFOLDR)/reluctance.o \
		$(OBJFOLDR)/resistance.o \
		$(OBJFOLDR)/resistor.o \
		$(OBJFOLDR)/series.o \
		$(OBJFOLDR)/source.o \
		$(OBJFOLDR)/transistor.o

$(OBJFOLDR)/capacitance.o: capacitance.cpp
	$(CPPTOOL) -c capacitance.cpp -o $(OBJFOLDR)/capacitance.o $(CXXFLAGS)

$(OBJFOLDR)/capacitor.o: capacitor.cpp
	$(CPPTOOL) -c capacitor.cpp -o $(OBJFOLDR)/capacitor.o $(CXXFLAGS)

$(OBJFOLDR)/circuit.o: circuit.cpp
	$(CPPTOOL) -c circuit.cpp -o $(OBJFOLDR)/circuit.o $(CXXFLAGS)

$(OBJFOLDR)/coil.o: coil.cpp
	$(CPPTOOL) -c coil.cpp -o $(OBJFOLDR)/coil.o $(CXXFLAGS)

$(OBJFOLDR)/core.o: core.cpp
	$(CPPTOOL) -c core.cpp -o $(OBJFOLDR)/core.o $(CXXFLAGS)

$(OBJFOLDR)/conductor.o: conductor.cpp
	$(CPPTOOL) -c conductor.cpp -o $(OBJFOLDR)/conductor.o $(CXXFLAGS)

$(OBJFOLDR)/diode.o: diode.cpp
	$(CPPTOOL) -c diode.cpp -o $(OBJFOLDR)/diode.o $(CXXFLAGS)

$(OBJFOLDR)/element.o: element.cpp
	$(CPPTOOL) -c element.cpp -o $(OBJFOLDR)/element.o $(CXXFLAGS)

$(OBJFOLDR)/inductance.o: inductance.cpp
	$(CPPTOOL) -c inductance.cpp -o $(OBJFOLDR)/inductance.o $(CXXFLAGS)

$(OBJFOLDR)/inductor.o: inductor.cpp
	$(CPPTOOL) -c inductor.cpp -o $(OBJFOLDR)/inductor.o $(CXXFLAGS)

$(OBJFOLDR)/parallel.o: parallel.cpp
	$(CPPTOOL) -c parallel.cpp -o $(OBJFOLDR)/parallel.o $(CXXFLAGS)

$(OBJFOLDR)/reluctance.o: reluctance.cpp
	$(CPPTOOL) -c reluctance.cpp -o $(OBJFOLDR)/reluctance.o $(CXXFLAGS)

$(OBJFOLDR)/resistance.o: resistance.cpp
	$(CPPTOOL) -c resistance.cpp -o $(OBJFOLDR)/resistance.o $(CXXFLAGS)

$(OBJFOLDR)/resistor.o: resistor.cpp
	$(CPPTOOL) -c resistor.cpp -o $(OBJFOLDR)/resistor.o $(CXXFLAGS)

$(OBJFOLDR)/series.o: series.cpp
	$(CPPTOOL) -c series.cpp -o $(OBJFOLDR)/series.o $(CXXFLAGS)

$(OBJFOLDR)/source.o: source.cpp
	$(CPPTOOL) -c source.cpp -o $(OBJFOLDR)/source.o $(CXXFLAGS)

$(OBJFOLDR)/transistor.o: transistor.cpp
	$(CPPTOOL) -c transistor.cpp -o $(OBJFOLDR)/transistor.o $(CXXFLAGS)