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
#include "angular.h"
#include "direction.h"
#include "unit.h"

namespace shp {

class Potential : protected Quantity {
    float low;
    Angular origin;
public:
    // Constructors
    Potential();
    Potential(const Angular& origin);
    Potential(float high);
    Potential(float high, const Angular& origin);
    Potential(float high, float low);
    Potential(float high, float low, const Angular& origin);
    Potential(const std::string unit);
    Potential(const Unit& unit);
    Potential(const Unit& unit, const Angular& origin);
    Potential(short int scaling, const std::string unit);
    Potential(short int scaling, const Unit& unit);
    Potential(short int scaling, const Unit& unit, const Angular& origin);
    Potential(float high, const std::string unit, const Angular& origin);
    Potential(float high, float low, const std::string unit);
    Potential(float high, float low, const std::string unit, const Angular& origin);
    Potential(float high, float low, const Unit& unit);
    Potential(float high, float low, const Unit& unit, const Angular& origin);
    Potential(float high, float low, short int scaling);
    Potential(float high, float low, short int scaling, const std::string unit);
    Potential(float high, float low, short int scaling, const Unit& unit);
    Potential(float high, float low, short int scaling, const Unit& unit, const Angular& origin);

    // Destructors
    ~Potential();

    // Operator overloading
    bool operator==(const Potential& peer) const;
    Potential operator+(const Potential& peer) const;
    Potential operator-(const Potential& peer) const;
    Potential operator*(const Potential& peer) const;
    Potential operator/(const Potential& peer) const;
    Potential operator%(const Potential& peer) const;

    // Access operator
    Quantity operator()(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Quantity operator()(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    float getHigh() const { return this->getValue(); }
    float getLow() const { return low; }
    Angular getOrigin() const { return origin; }

    // Setters
    void setHigh(const float value) { this->setValue(value); }
    void setLow(const float value) { this->low = value; }
    void setOrigin(const Angular& position) { this->origin = position; }

    // Additional methods
    Direction getPolar() const;
    void setPolar(const Direction& angle);
    Direction getAzimuthal() const;
    void setAzimuthal(const Direction& angle);
    Quantity getDifference() const;
    Quantity getRelative(const Distance& location, const float angle) const;
    Quantity getPolarComponent(const Distance& location) const;
    Quantity getAzimuthalComponent(const Distance& location) const;
    Potential copy();
    void clear();
    std::string print();
};

typedef std::vector<Potential > PotentialArray;

} // namespace shp

#endif //SHP_POTENTIAL_H