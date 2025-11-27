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
#include "planar.h"
#include "point.h"

namespace shp {

class Cellular : public Point {
    PlanarArray planes;
public:
    // Constructors
    Cellular();
    Cellular(float gradient);
    Cellular(std::string name);
    Cellular(std::string name, float gradient);
    Cellular(std::string name, PlanarArray& planes);
    Cellular(std::string name, PlanarArray& planes, float gradient);

    // Destructors
    ~Cellular();

    // Operator overloading
    bool operator==(const Cellular& peer) const;
    Cellular operator+(const Cellular& peer) const;
    Cellular operator-(const Cellular& peer) const;

    // Access operator
    Planar& operator()(int x) { return planes[x]; }
    const Planar& operator()(int x) const { return planes[x]; }
    Linear& operator()(int x, int y) { return planes[x](y); }
	const Linear& operator()(int x, int y) const { return planes[x](y); }
    Point& operator()(int x, int y, int z) { return planes[x](y)(z); }
	const Point& operator()(int x, int y, int z) const { return planes[x](y)(z); }

    // Getters
    PlanarArray getPlanes() const { return planes; }

    // Setters
    void setPlanes(const PlanarArray& objects) { this->planes = objects; }

    // Additional methods
    int getPlaneCount() const;
    Planar get(int index) const;
    void set(int index, const Planar& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Cellular > CellularArray;

} // namespace shp

#endif //SHP_CELLULAR_H