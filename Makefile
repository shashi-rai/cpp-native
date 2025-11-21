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
CXXINCS  = -I"./inc" 
CXXFLAGS = $(CXXINCS) -std=c++11
LIBS     = -L"$(LIBFOLDR)"
RMCLEAN	 = rm -f

APPPROG	 = bhojpur.app
LINKOBJ  = $(OBJFOLDR)/main.o

OBJFOLDR = ./obj
OBJFILES = $(OBJFOLDR)/*.o
LIBFOLDR = ./lib
LIBFILES = $(LIBFOLDR)/*.a

.PHONY: all all-before all-after clean clean-custom

all: all-before $(APPPROG) all-after

clean: clean-custom clean-objs clean-libs clean-apps

clean-objs: clean-custom
	${RMCLEAN} $(OBJFILES)

clean-libs: clean-custom
	${RMCLEAN} $(LIBFILES)

clean-apps: clean-custom
	${RMCLEAN} $(APPPROG)

$(APPPROG): $(LINKOBJ) $(LIBFILES)
	$(CPPTOOL) $(LINKOBJ) $(LIBFILES) -o $(APPPROG) $(LIBS)

$(OBJFOLDR)/main.o: main.cpp
	$(CPPTOOL) -c main.cpp -o $(OBJFOLDR)/main.o $(CXXFLAGS)