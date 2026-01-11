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
LIBNAME	 = libshp.a
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
		$(OBJFOLDR)/angular.o \
		$(OBJFOLDR)/area.o \
		$(OBJFOLDR)/axis.o \
		$(OBJFOLDR)/azimuth.o \
		$(OBJFOLDR)/cellular.o \
		$(OBJFOLDR)/change.o \
		$(OBJFOLDR)/confinement.o \
		$(OBJFOLDR)/coordinate.o \
		$(OBJFOLDR)/curvature.o \
		$(OBJFOLDR)/direction.o \
		$(OBJFOLDR)/distance.o \
		$(OBJFOLDR)/frame.o \
		$(OBJFOLDR)/frequency.o \
		$(OBJFOLDR)/linear.o \
		$(OBJFOLDR)/phase.o \
		$(OBJFOLDR)/planar.o \
		$(OBJFOLDR)/point.o \
		$(OBJFOLDR)/polar.o \
		$(OBJFOLDR)/polygon.o \
		$(OBJFOLDR)/potential.o \
		$(OBJFOLDR)/proportion.o \
		$(OBJFOLDR)/quantity.o \
		$(OBJFOLDR)/shape.o \
		$(OBJFOLDR)/shell.o \
		$(OBJFOLDR)/signal.o \
		$(OBJFOLDR)/temporal.o \
		$(OBJFOLDR)/unit.o \
		$(OBJFOLDR)/volume.o \
		$(OBJFOLDR)/wave.o
	$(LIBMAKR) rcs $(LIBFOLDR)/$(LIBNAME) \
		$(OBJFOLDR)/angular.o \
		$(OBJFOLDR)/area.o \
		$(OBJFOLDR)/axis.o \
		$(OBJFOLDR)/azimuth.o \
		$(OBJFOLDR)/cellular.o \
		$(OBJFOLDR)/change.o \
		$(OBJFOLDR)/confinement.o \
		$(OBJFOLDR)/coordinate.o \
		$(OBJFOLDR)/curvature.o \
		$(OBJFOLDR)/direction.o \
		$(OBJFOLDR)/distance.o \
		$(OBJFOLDR)/frame.o \
		$(OBJFOLDR)/frequency.o \
		$(OBJFOLDR)/linear.o \
		$(OBJFOLDR)/phase.o \
		$(OBJFOLDR)/planar.o \
		$(OBJFOLDR)/point.o \
		$(OBJFOLDR)/polar.o \
		$(OBJFOLDR)/polygon.o \
		$(OBJFOLDR)/potential.o \
		$(OBJFOLDR)/proportion.o \
		$(OBJFOLDR)/quantity.o \
		$(OBJFOLDR)/shape.o \
		$(OBJFOLDR)/shell.o \
		$(OBJFOLDR)/signal.o \
		$(OBJFOLDR)/temporal.o \
		$(OBJFOLDR)/unit.o \
		$(OBJFOLDR)/volume.o \
		$(OBJFOLDR)/wave.o

$(OBJFOLDR)/angular.o: angular.cpp
	$(CPPTOOL) -c angular.cpp -o $(OBJFOLDR)/angular.o $(CXXFLAGS)

$(OBJFOLDR)/area.o: area.cpp
	$(CPPTOOL) -c area.cpp -o $(OBJFOLDR)/area.o $(CXXFLAGS)

$(OBJFOLDR)/axis.o: axis.cpp
	$(CPPTOOL) -c axis.cpp -o $(OBJFOLDR)/axis.o $(CXXFLAGS)

$(OBJFOLDR)/azimuth.o: azimuth.cpp
	$(CPPTOOL) -c azimuth.cpp -o $(OBJFOLDR)/azimuth.o $(CXXFLAGS)

$(OBJFOLDR)/cellular.o: cellular.cpp
	$(CPPTOOL) -c cellular.cpp -o $(OBJFOLDR)/cellular.o $(CXXFLAGS)

$(OBJFOLDR)/change.o: change.cpp
	$(CPPTOOL) -c change.cpp -o $(OBJFOLDR)/change.o $(CXXFLAGS)

$(OBJFOLDR)/confinement.o: confinement.cpp
	$(CPPTOOL) -c confinement.cpp -o $(OBJFOLDR)/confinement.o $(CXXFLAGS)

$(OBJFOLDR)/coordinate.o: coordinate.cpp
	$(CPPTOOL) -c coordinate.cpp -o $(OBJFOLDR)/coordinate.o $(CXXFLAGS)

$(OBJFOLDR)/curvature.o: curvature.cpp
	$(CPPTOOL) -c curvature.cpp -o $(OBJFOLDR)/curvature.o $(CXXFLAGS)

$(OBJFOLDR)/direction.o: direction.cpp
	$(CPPTOOL) -c direction.cpp -o $(OBJFOLDR)/direction.o $(CXXFLAGS)

$(OBJFOLDR)/distance.o: distance.cpp
	$(CPPTOOL) -c distance.cpp -o $(OBJFOLDR)/distance.o $(CXXFLAGS)

$(OBJFOLDR)/frame.o: frame.cpp
	$(CPPTOOL) -c frame.cpp -o $(OBJFOLDR)/frame.o $(CXXFLAGS)

$(OBJFOLDR)/frequency.o: frequency.cpp
	$(CPPTOOL) -c frequency.cpp -o $(OBJFOLDR)/frequency.o $(CXXFLAGS)

$(OBJFOLDR)/linear.o: linear.cpp
	$(CPPTOOL) -c linear.cpp -o $(OBJFOLDR)/linear.o $(CXXFLAGS)

$(OBJFOLDR)/phase.o: phase.cpp
	$(CPPTOOL) -c phase.cpp -o $(OBJFOLDR)/phase.o $(CXXFLAGS)

$(OBJFOLDR)/planar.o: planar.cpp
	$(CPPTOOL) -c planar.cpp -o $(OBJFOLDR)/planar.o $(CXXFLAGS)

$(OBJFOLDR)/point.o: point.cpp
	$(CPPTOOL) -c point.cpp -o $(OBJFOLDR)/point.o $(CXXFLAGS)

$(OBJFOLDR)/polar.o: polar.cpp
	$(CPPTOOL) -c polar.cpp -o $(OBJFOLDR)/polar.o $(CXXFLAGS)

$(OBJFOLDR)/polygon.o: polygon.cpp
	$(CPPTOOL) -c polygon.cpp -o $(OBJFOLDR)/polygon.o $(CXXFLAGS)

$(OBJFOLDR)/potential.o: potential.cpp
	$(CPPTOOL) -c potential.cpp -o $(OBJFOLDR)/potential.o $(CXXFLAGS)

$(OBJFOLDR)/proportion.o: proportion.cpp
	$(CPPTOOL) -c proportion.cpp -o $(OBJFOLDR)/proportion.o $(CXXFLAGS)

$(OBJFOLDR)/quantity.o: quantity.cpp
	$(CPPTOOL) -c quantity.cpp -o $(OBJFOLDR)/quantity.o $(CXXFLAGS)

$(OBJFOLDR)/shape.o: shape.cpp
	$(CPPTOOL) -c shape.cpp -o $(OBJFOLDR)/shape.o $(CXXFLAGS)

$(OBJFOLDR)/shell.o: shell.cpp
	$(CPPTOOL) -c shell.cpp -o $(OBJFOLDR)/shell.o $(CXXFLAGS)

$(OBJFOLDR)/signal.o: signal.cpp
	$(CPPTOOL) -c signal.cpp -o $(OBJFOLDR)/signal.o $(CXXFLAGS)

$(OBJFOLDR)/temporal.o: temporal.cpp
	$(CPPTOOL) -c temporal.cpp -o $(OBJFOLDR)/temporal.o $(CXXFLAGS)

$(OBJFOLDR)/unit.o: unit.cpp
	$(CPPTOOL) -c unit.cpp -o $(OBJFOLDR)/unit.o $(CXXFLAGS)

$(OBJFOLDR)/volume.o: volume.cpp
	$(CPPTOOL) -c volume.cpp -o $(OBJFOLDR)/volume.o $(CXXFLAGS)

$(OBJFOLDR)/wave.o: wave.cpp
	$(CPPTOOL) -c wave.cpp -o $(OBJFOLDR)/wave.o $(CXXFLAGS)