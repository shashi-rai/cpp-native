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

#ifndef SHP_SHELL_H
#define SHP_SHELL_H

#include <string>
#include <vector>
#include "point.h"
#include "polygon.h"

namespace shp {

class Shell : public Point {
    int limit;
    OrbitalArray orbitals;
public:
    // Constructors
    Shell();
    Shell(float gradient);
    Shell(std::string name);
    Shell(std::string name, int limit);
    Shell(std::string name, float gradient);
    Shell(std::string name, float gradient, int limit);
    Shell(std::string name, OrbitalArray& orbitals);
    Shell(std::string name, OrbitalArray& orbitals, float gradient);
    Shell(std::string name, OrbitalArray& orbitals, float gradient, int limit);

    // Destructors
    ~Shell();

    // Operator overloading
    bool operator==(const Shell& peer) const;
    Shell operator+(const Shell& peer) const;
    Shell operator-(const Shell& peer) const;

    // Access operator
    Polygon& operator()(int x) { return orbitals[x]; }
	const Polygon& operator()(int x) const { return orbitals[x]; }
    Wave& operator()(int x, int y) { return orbitals[x](y); }
	const Wave& operator()(int x, int y) const { return orbitals[x](y); }

    // Getters
    int getLimit() const { return limit; }
    OrbitalArray getOrbitals() const { return orbitals; }

    // Setters
    void setLimit(int value) { this->limit = value; }
    void setOrbitals(const OrbitalArray& objects) { this->orbitals = objects; }

    // Additional methods
    int getOrbitalCount() const;
    Polygon get(int index) const;
    void set(int index, const Polygon& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Shell > ShellArray;

} // namespace shp

#endif //SHP_SHELL_H