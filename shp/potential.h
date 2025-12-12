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

#ifndef SHP_POTENTIAL_H
#define SHP_POTENTIAL_H

#include <cmath>
#include <sstream>
#include <vector>
#include "quantity.h"
#include "unit.h"

namespace shp {

class Potential : protected Quantity {
    float low;
public:
    // Constructors
    Potential();
    Potential(float low);
    Potential(float high, float low);
    Potential(const std::string unit);
    Potential(short int scaling, const std::string unit);
    Potential(const Unit& unit);
    Potential(short int scaling, const Unit& unit);
    Potential(float high, float low, const std::string unit);
    Potential(float high, float low, const Unit& unit);
    Potential(float high, float low, short int scaling);
    Potential(float high, float low, short int scaling, const std::string unit);
    Potential(float high, float low, short int scaling, const Unit& unit);

    // Destructors
    ~Potential();

    // Operator overloading
    bool operator==(const Potential& peer) const;
    Potential operator+(const Potential& peer) const;
    Potential operator-(const Potential& peer) const;
    Potential operator*(const Potential& peer) const;
    Potential operator/(const Potential& peer) const;
    Potential operator%(const Potential& peer) const;

    // Getters
    float getHigh() const { return this->getValue(); }
    float getLow() const { return low; }

    // Setters
    void setHigh(const float value) { this->setValue(value); }
    void setLow(const float value) { this->low = value; }

    // Additional methods
    Quantity getDifference() const;
    Potential copy();
    void clear();
    std::string print();
};

typedef std::vector<Potential > PotentialArray;

} // namespace shp

#endif //SHP_POTENTIAL_H