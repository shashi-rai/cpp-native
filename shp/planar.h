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

#ifndef SHP_PLANAR_H
#define SHP_PLANAR_H

#include "linear.h"

namespace shp {

class Planar : public Point {
    LinearArray lines;
public:
    // Constructors
    Planar();
    Planar(const float gradient);
    Planar(const Azimuth& gradient);
    Planar(const std::string name);
    Planar(const std::string name, const float gradient);
    Planar(const std::string name, const Azimuth& gradient);
    Planar(const std::string name, const LinearArray& lines);
    Planar(const std::string name, const LinearArray& lines, const float gradient);
    Planar(const std::string name, const LinearArray& lines, const Azimuth& gradient);

    // Destructors
    ~Planar();

    // Operator overloading
    bool operator==(const Planar& peer) const;
    Planar operator+(const Planar& peer) const;
    Planar operator-(const Planar& peer) const;

    // Access operator
    Linear operator()(int x) { return lines[x]; }
    const Linear operator()(int x) const { return lines[x]; }
    Point operator()(int x, int y) { return lines[x](y); }
	const Point operator()(int x, int y) const { return lines[x](y); }

    // Getters
    LinearArray getLines() const { return lines; }

    // Setters
    void setLines(const LinearArray& objects) { this->lines = objects; }

    // Additional methods
    int getLineCount() const;
    Linear get(const int index) const;
    void set(const int index, const Linear& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print() const;
};

typedef std::vector<Planar > PlanarArray;

} // namespace shp

#endif //SHP_PLANAR_H