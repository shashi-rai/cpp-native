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
#include "direction.h"
#include "quantity.h"

namespace shp {

class Distance : public Quantity {
    Direction change;
public:
    // Constructors
    Distance();
    Distance(const std::string unit);
    Distance(const Unit& unit);
    Distance(const float length);
    Distance(const float length, const std::string unit);
    Distance(const float length, const Unit& unit);
    Distance(const float length, const short int scaling);
    Distance(const float length, const short int scaling, const std::string unit);
    Distance(const float length, const short int scaling, const Unit& unit);
    Distance(const Direction& change);
    Distance(const std::string unit, const Direction& change);
    Distance(const Unit& unit, const Direction& change);
    Distance(const float length, const Direction& change);
    Distance(const float length, const std::string unit, const Direction& change);
    Distance(const float length, const Unit& unit, const Direction& change);
    Distance(const float length, const short int scaling, const Direction& change);
    Distance(const float length, const short int scaling, const std::string unit, const Direction& change);
    Distance(const float length, const short int scaling, const Unit& unit, const Direction& change);

    // Destructors
    ~Distance();

    // Operator overloading
    bool operator==(const Distance& peer) const;
    Distance operator+(const Distance& peer) const;
    Distance operator-(const Distance& peer) const;
    Distance operator*(const Distance& peer) const;
    Distance operator/(const Distance& peer) const;
    Distance operator%(const Distance& peer) const;

    // Direction operator
    Distance operator+(const Direction& rotation) const;
    Distance operator-(const Direction& rotation) const;
    Distance operator*(const Direction& rotation) const;
    Distance operator/(const Direction& rotation) const;
    Distance operator%(const Direction& rotation) const;

    // Access operator
    Distance operator()(const Distance& peer) const;

    // Getters
    Direction getChange() const { return change; }

    // Setters
    void setChange(const Direction& orientation) { this->change = orientation; }

    // Additional methods
    Direction getDeviation(const Direction& peer) const;
    Distance getFactorX(const Distance& peer) const;
    Distance getFactorY(const Distance& peer) const;
    Quantity getTotal() const;
    Quantity getRadial() const;
    Quantity getRadialX() const;
    Quantity getRadialY() const;
    Quantity getSquareX() const;
    Quantity getSquareY() const;
    virtual Distance copy();
    virtual void clear();
    virtual std::string print() const;
public:
    static const std::string UNIT;
};

typedef std::vector<Distance > DistanceArray;

} // namespace shp

#endif //SHP_DISTANCE_H