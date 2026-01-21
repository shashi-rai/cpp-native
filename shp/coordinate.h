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

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

namespace shp {

class Coordinate {
    float x;
    float y;
    float z;
public:
    // Constructors
    Coordinate();
    Coordinate(const float x);
    Coordinate(const float x, const float y);
    Coordinate(const float x, const float y, const float z);

    // Destructors
    ~Coordinate();

    // Operator overloading
    bool operator==(const Coordinate& peer) const;
    bool operator<(const Coordinate& peer) const;
    bool operator>(const Coordinate& peer) const;
    bool operator<=(const Coordinate& peer) const;
    bool operator>=(const Coordinate& peer) const;
    Coordinate operator+(const Coordinate& peer) const;
    Coordinate operator-(const Coordinate& peer) const;
    Coordinate operator*(const Coordinate& peer) const;
    Coordinate operator/(const Coordinate& peer) const;
    Coordinate operator%(const Coordinate& peer) const;

    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Setters
    void setX(const float value) { this->x = value; }
    void setY(const float value) { this->y = value; }
    void setZ(const float value) { this->z = value; }

    // Additional methods
    float getMagnitude() const;
    Coordinate getNormalize() const;
    Coordinate getField(const float intensity, const float conservable,
        const Coordinate& source, const Coordinate& target) const;
    Coordinate shiftX(const float step) const;
    Coordinate shiftY(const float step) const;
    Coordinate shiftZ(const float step) const;
    Coordinate copy();
    void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;

public:
    static const float ORIGIN;
    static const float DEFAULT_VALUE;
    static const float UNIT_MAGNITUDE;
};

typedef std::vector<Coordinate > CoordinateArray;

} // namespace shp

#endif //SHP_COORDINATE_H