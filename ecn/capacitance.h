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

#ifndef ECN_CAPACITANCE_H
#define ECN_CAPACITANCE_H

#include <sstream>
#include <string>
#include <vector>
#include "conductor.h"
#include "../shp/potential.h"

namespace ecn {

class Capacitance : public shp::Quantity {
    Conductor positive;
    Conductor negative;
public:
    // Constructors
    Capacitance();
    Capacitance(const Conductor& positive, const Conductor& negative);
    Capacitance(const float magnitude);
    Capacitance(const short int scaling);
    Capacitance(const std::string unit);
    Capacitance(const short int scaling, const std::string unit);
    Capacitance(const shp::Unit& unit);
    Capacitance(const short int scaling, const shp::Unit& unit);
    Capacitance(const float magnitude, const std::string unit);
    Capacitance(const float magnitude, const shp::Unit& unit);
    Capacitance(const float magnitude, const short int scaling);
    Capacitance(const float magnitude, const short int scaling, const std::string unit);
    Capacitance(const float magnitude, const short int scaling, const shp::Unit& unit);
    Capacitance(const float magnitude, const short int scaling, const shp::Unit& unit,
        const Conductor& positive, const Conductor& negative);

    // Destructors
    ~Capacitance();

    // Operator overloading
    bool operator==(const Capacitance& peer) const;
    Capacitance operator+(const Capacitance& peer) const;
    Capacitance operator-(const Capacitance& peer) const;
    Capacitance operator*(const Capacitance& peer) const;
    Capacitance operator/(const Capacitance& peer) const;
    Capacitance operator%(const Capacitance& peer) const;

    // Getters
    Conductor getPositive() const { return positive; }
    Conductor getNegative() const { return negative; }

    // Setters
    void setPositive(const Conductor& potential) { this->positive = potential; }
    void setNegative(const Conductor& potential) { this->negative = potential; }

    // Additional methods
    shp::Potential getThreshold() const;
    Capacitance copy();
    virtual void clear();
    virtual std::string print();
public:
    static const std::string UNIT;
};

typedef std::vector<Capacitance > CapacitanceArray;

} // namespace ecn

#endif //ECN_CAPACITANCE_H