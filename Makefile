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

# GNU C++ Compiler Settings
CPPTOOL	 = g++
CXXINCS  = -I"./inc" 
CXXFLAGS = $(CXXINCS) -std=c++11
LIBS     = -L"$(LIBFOLDR)"

# General File/Folder Paths
OBJFOLDR = ./obj
OBJFILES = $(OBJFOLDR)/*.o
LIBFOLDR = ./lib
LIBFILES = $(LIBFOLDR)/*.a

# Main Application
APPPROG	 = bhojpur.app
LINKOBJ  = $(OBJFOLDR)/main.o

# Test Application
TESTPROG = bhojpur.app
TESTOBJ  = $(OBJFOLDR)/suite.o
TESTFOLDR = ./test
TESTFILES = $(OBJFOLDR)/*.o

# Test Application
DATAPROG = bhojpur.app
DATAOBJ  = $(OBJFOLDR)/logger.o
DATAFOLDR = ./dsa
DATAFILES = $(OBJFOLDR)/*.o

# Shell Commands
RMCLEAN	 = rm -f

# General Make Settings
.PHONY: all all-before all-after clean clean-custom

# To build all the libraries
all: all-before subdirs $(APPPROG) all-after

# To build only main application
app: all-before $(APPPROG) all-after

# Sequence of sub-folders to built
SUBDIRS = dsa web shp img qft phy che bio bit ecn gis grt doc law act eco fin con

# Repeat make command in all specified sub-folders
subdirs:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

# To build only testing application
test: all-before testing $(TESTPROG) all-after

# Sequence of sub-folders to built
TESTDIRS = shp img qft con test

# Repeat make command in specified test folder
testing:
	for dir in $(TESTDIRS); do \
		$(MAKE) -C $$dir; \
	done

# To build only dsa application
data: all-before dataengg $(DATAPROG) all-after

# Sequence of sub-folders to built
DATADIRS = dsa

# Repeat make command in specified test folder
dataengg:
	for dir in $(DATADIRS); do \
		$(MAKE) -C $$dir; \
	done

# Repeat cleanup command in all specified sub-folders
clean: clean-custom clean-objs clean-libs clean-apps
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

# Remove only object files
clean-objs: clean-custom
	${RMCLEAN} $(OBJFILES)

# Remove only library files
clean-libs: clean-custom
	${RMCLEAN} $(LIBFILES)

# Remove only main application
clean-apps: clean-custom
	${RMCLEAN} $(APPPROG)

# Remove only test application
clean-tests: clean-custom
	${RMCLEAN} $(TESTFOLDR)/$(TESTPROG)

# Publish modiefied source code to repository
repo:
	git commit -m "."
	git push origin main

# Dependencies to build main application
$(APPPROG): $(LINKOBJ)
	$(CPPTOOL) $(LINKOBJ) $(LIBFILES) -o $(APPPROG) $(LIBS)

$(OBJFOLDR)/main.o: main.cpp
	$(CPPTOOL) -c main.cpp -o $(OBJFOLDR)/main.o $(CXXFLAGS)
