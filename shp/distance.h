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

#ifndef SHP_DISTANCE_H
#define SHP_DISTANCE_H

#include <sstream>
#include <string>
#include <vector>
#include "quantity.h"
#include "unit.h"

namespace shp {

class Distance {
    Quantity magnitude;
public:
    // Constructors
    Distance();
    Distance(const float magnitude);
    Distance(const float magnitude, const std::string unit);
    Distance(const float magnitude, short int scaling, const std::string unit);
    Distance(const Quantity& length);

    // Destructors
    ~Distance();

    // Operator overloading
    bool operator==(const Distance& peer) const;
    Distance operator+(const Distance& peer) const;
    Distance operator-(const Distance& peer) const;
    Distance operator*(const Distance& peer) const;
    Distance operator/(const Distance& peer) const;
    Distance operator%(const Distance& peer) const;

    // Getters
    Quantity getMagnitude() const { return magnitude; }

    // Setters
    void setMagnitude(const Quantity& length) { this->magnitude = length; }

    // Additional methods
    float getTotal() const;
    std::string getUnit() const;
    virtual Distance copy();
    virtual void clear();
    virtual std::string print();
    float getComponent(float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Distance > DistanceArray;

} // namespace shp

#endif //SHP_DISTANCE_H