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
		$(OBJFOLDR)/acceleration.o \
		$(OBJFOLDR)/action.o \
		$(OBJFOLDR)/charge.o \
		$(OBJFOLDR)/density.o \
		$(OBJFOLDR)/electric.o \
		$(OBJFOLDR)/electron.o \
		$(OBJFOLDR)/energy.o \
		$(OBJFOLDR)/field.o \
		$(OBJFOLDR)/force.o \
		$(OBJFOLDR)/gravity.o \
		$(OBJFOLDR)/magnetic.o \
		$(OBJFOLDR)/mass.o \
		$(OBJFOLDR)/momentum.o \
		$(OBJFOLDR)/neutrino.o \
		$(OBJFOLDR)/neutron.o \
		$(OBJFOLDR)/particle.o \
		$(OBJFOLDR)/photon.o \
		$(OBJFOLDR)/pressure.o \
		$(OBJFOLDR)/proton.o \
		$(OBJFOLDR)/quark.o \
		$(OBJFOLDR)/spin.o \
		$(OBJFOLDR)/strong.o \
		$(OBJFOLDR)/temperature.o \
		$(OBJFOLDR)/time.o \
		$(OBJFOLDR)/velocity.o \
		$(OBJFOLDR)/weak.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/acceleration.o \
		$(OBJFOLDR)/action.o \
		$(OBJFOLDR)/charge.o \
		$(OBJFOLDR)/density.o \
		$(OBJFOLDR)/electric.o \
		$(OBJFOLDR)/electron.o \
		$(OBJFOLDR)/energy.o \
		$(OBJFOLDR)/field.o \
		$(OBJFOLDR)/force.o \
		$(OBJFOLDR)/gravity.o \
		$(OBJFOLDR)/magnetic.o \
		$(OBJFOLDR)/mass.o \
		$(OBJFOLDR)/momentum.o \
		$(OBJFOLDR)/neutrino.o \
		$(OBJFOLDR)/neutron.o \
		$(OBJFOLDR)/particle.o \
		$(OBJFOLDR)/photon.o \
		$(OBJFOLDR)/pressure.o \
		$(OBJFOLDR)/proton.o \
		$(OBJFOLDR)/quark.o \
		$(OBJFOLDR)/spin.o \
		$(OBJFOLDR)/strong.o \
		$(OBJFOLDR)/temperature.o \
		$(OBJFOLDR)/time.o \
		$(OBJFOLDR)/velocity.o \
		$(OBJFOLDR)/weak.o

$(OBJFOLDR)/acceleration.o: acceleration.cpp
	$(CPPTOOL) -c acceleration.cpp -o $(OBJFOLDR)/acceleration.o $(CXXFLAGS)

$(OBJFOLDR)/action.o: action.cpp
	$(CPPTOOL) -c action.cpp -o $(OBJFOLDR)/action.o $(CXXFLAGS)

$(OBJFOLDR)/charge.o: charge.cpp
	$(CPPTOOL) -c charge.cpp -o $(OBJFOLDR)/charge.o $(CXXFLAGS)

$(OBJFOLDR)/density.o: density.cpp
	$(CPPTOOL) -c density.cpp -o $(OBJFOLDR)/density.o $(CXXFLAGS)

$(OBJFOLDR)/electric.o: electric.cpp
	$(CPPTOOL) -c electric.cpp -o $(OBJFOLDR)/electric.o $(CXXFLAGS)

$(OBJFOLDR)/electron.o: electron.cpp
	$(CPPTOOL) -c electron.cpp -o $(OBJFOLDR)/electron.o $(CXXFLAGS)

$(OBJFOLDR)/energy.o: energy.cpp
	$(CPPTOOL) -c energy.cpp -o $(OBJFOLDR)/energy.o $(CXXFLAGS)

$(OBJFOLDR)/field.o: field.cpp
	$(CPPTOOL) -c field.cpp -o $(OBJFOLDR)/field.o $(CXXFLAGS)

$(OBJFOLDR)/force.o: force.cpp
	$(CPPTOOL) -c force.cpp -o $(OBJFOLDR)/force.o $(CXXFLAGS)

$(OBJFOLDR)/gravity.o: gravity.cpp
	$(CPPTOOL) -c gravity.cpp -o $(OBJFOLDR)/gravity.o $(CXXFLAGS)

$(OBJFOLDR)/magnetic.o: magnetic.cpp
	$(CPPTOOL) -c magnetic.cpp -o $(OBJFOLDR)/magnetic.o $(CXXFLAGS)

$(OBJFOLDR)/mass.o: mass.cpp
	$(CPPTOOL) -c mass.cpp -o $(OBJFOLDR)/mass.o $(CXXFLAGS)

$(OBJFOLDR)/momentum.o: momentum.cpp
	$(CPPTOOL) -c momentum.cpp -o $(OBJFOLDR)/momentum.o $(CXXFLAGS)

$(OBJFOLDR)/neutrino.o: neutrino.cpp
	$(CPPTOOL) -c neutrino.cpp -o $(OBJFOLDR)/neutrino.o $(CXXFLAGS)

$(OBJFOLDR)/neutron.o: neutron.cpp
	$(CPPTOOL) -c neutron.cpp -o $(OBJFOLDR)/neutron.o $(CXXFLAGS)

$(OBJFOLDR)/particle.o: particle.cpp
	$(CPPTOOL) -c particle.cpp -o $(OBJFOLDR)/particle.o $(CXXFLAGS)

$(OBJFOLDR)/photon.o: photon.cpp
	$(CPPTOOL) -c photon.cpp -o $(OBJFOLDR)/photon.o $(CXXFLAGS)

$(OBJFOLDR)/pressure.o: pressure.cpp
	$(CPPTOOL) -c pressure.cpp -o $(OBJFOLDR)/pressure.o $(CXXFLAGS)

$(OBJFOLDR)/proton.o: proton.cpp
	$(CPPTOOL) -c proton.cpp -o $(OBJFOLDR)/proton.o $(CXXFLAGS)

$(OBJFOLDR)/quark.o: quark.cpp
	$(CPPTOOL) -c quark.cpp -o $(OBJFOLDR)/quark.o $(CXXFLAGS)

$(OBJFOLDR)/spin.o: spin.cpp
	$(CPPTOOL) -c spin.cpp -o $(OBJFOLDR)/spin.o $(CXXFLAGS)

$(OBJFOLDR)/strong.o: strong.cpp
	$(CPPTOOL) -c strong.cpp -o $(OBJFOLDR)/strong.o $(CXXFLAGS)

$(OBJFOLDR)/temperature.o: temperature.cpp
	$(CPPTOOL) -c temperature.cpp -o $(OBJFOLDR)/temperature.o $(CXXFLAGS)

$(OBJFOLDR)/time.o: time.cpp
	$(CPPTOOL) -c time.cpp -o $(OBJFOLDR)/time.o $(CXXFLAGS)

$(OBJFOLDR)/velocity.o: velocity.cpp
	$(CPPTOOL) -c velocity.cpp -o $(OBJFOLDR)/velocity.o $(CXXFLAGS)

$(OBJFOLDR)/weak.o: weak.cpp
	$(CPPTOOL) -c weak.cpp -o $(OBJFOLDR)/weak.o $(CXXFLAGS)