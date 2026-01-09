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

#ifndef SHP_AZIMUTH_H
#define SHP_AZIMUTH_H

#include <cmath>
#include <sstream>
#include <vector>
#include "direction.h"

namespace shp {

class Azimuth : public Direction {
    Direction change;
public:
    // Constructors
    Azimuth();
    Azimuth(const float radians);
    Azimuth(const short int degrees);
    Azimuth(const short int degrees, const short int minutes);
    Azimuth(const short int degrees, const short int minutes, const short int seconds);
    Azimuth(const Direction& change);
    Azimuth(const float radians, const Direction& change);
    Azimuth(const short int degrees, const Direction& change);
    Azimuth(const short int degrees, const short int minutes, const Direction& change);
    Azimuth(const short int degrees, const short int minutes, const short int seconds, const Direction& change);

    // Destructors
    ~Azimuth();

    // Operator overloading
    bool operator==(const Azimuth& peer) const;
    Azimuth operator+(const Direction& peer) const;
    Azimuth operator-(const Direction& peer) const;
    Azimuth operator*(const Direction& peer) const;
    Azimuth operator/(const Direction& peer) const;
    Azimuth operator%(const Direction& peer) const;

    // Getters
    Direction getChange() const { return change; }

    // Setters
    void setChange(const Direction& orientation) { this->change = orientation; }

    // Additional methods
    virtual Direction copy() const;
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Azimuth > AzimuthArray;

} // namespace shp

#endif //SHP_AZIMUTH_H