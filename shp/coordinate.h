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

#ifndef SHP_COORDINATE_H
#define SHP_COORDINATE_H

#include <iostream>
#include <sstream>
#include <vector>

namespace shp {

class Coordinate {
    int x;
    int y;
    int z;
public:
    // Constructors
    Coordinate();
    Coordinate(const int x);
    Coordinate(const int x, const int y);
    Coordinate(const int x, const int y, const int z);

    // Destructors
    ~Coordinate();

    // Operator overloading
    bool operator==(const Coordinate& peer) const;
    Coordinate operator+(const Coordinate& peer) const;
    Coordinate operator-(const Coordinate& peer) const;
    Coordinate operator*(const Coordinate& peer) const;
    Coordinate operator/(const Coordinate& peer) const;
    Coordinate operator%(const Coordinate& peer) const;

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

    // Setters
    void setX(const int value) { this->x = value; }
    void setY(const int value) { this->y = value; }
    void setZ(const int value) { this->z = value; }

    // Additional methods
    Coordinate shiftX(const int step) const;
    Coordinate shiftY(const int step) const;
    Coordinate shiftZ(const int step) const;
    Coordinate copy();
    void clear();
    std::string print();

public:
    static const int ORIGIN;
};

typedef std::vector<Coordinate > CoordinateArray;

} // namespace shp

#endif //SHP_COORDINATE_H