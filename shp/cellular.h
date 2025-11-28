// Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef SHP_CELLULAR_H
#define SHP_CELLULAR_H

#include <string>
#include <vector>
#include "shell.h"
#include "point.h"

namespace shp {

class Cellular : public Point {
    ShellArray shells;
public:
    // Constructors
    Cellular();
    Cellular(float gradient);
    Cellular(std::string name);
    Cellular(std::string name, float gradient);
    Cellular(std::string name, ShellArray& shells);
    Cellular(std::string name, ShellArray& shells, float gradient);

    // Destructors
    ~Cellular();

    // Operator overloading
    bool operator==(const Cellular& peer) const;
    Cellular operator+(const Cellular& peer) const;
    Cellular operator-(const Cellular& peer) const;

    // Access operator
    Shell& operator()(int x) { return shells[x]; }
    const Shell& operator()(int x) const { return shells[x]; }
    Polygon& operator()(int x, int y) { return shells[x](y); }
	const Polygon& operator()(int x, int y) const { return shells[x](y); }
    Wave& operator()(int x, int y, int z) { return shells[x](y)(z); }
	const Wave& operator()(int x, int y, int z) const { return shells[x](y)(z); }

    // Getters
    ShellArray getShells() const { return shells; }

    // Setters
    void setShells(const ShellArray& objects) { this->shells = objects; }

    // Additional methods
    int getShellCount() const;
    Shell get(int index) const;
    void set(int index, const Shell& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Cellular > CellularArray;

} // namespace shp

#endif //SHP_CELLULAR_H