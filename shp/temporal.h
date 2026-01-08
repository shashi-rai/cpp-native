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

#ifndef SHP_TEMPORAL_H
#define SHP_TEMPORAL_H

#include <sstream>
#include <string>
#include <vector>
#include "direction.h"
#include "quantity.h"

namespace shp {

class Temporal : public Quantity {
    Direction change;
public:
    // Constructors
    Temporal();
    Temporal(const std::string unit);
    Temporal(const shp::Unit& unit);
    Temporal(const float timeslice);
    Temporal(const float timeslice, const std::string unit);
    Temporal(const float timeslice, const shp::Unit& unit);
    Temporal(const float timeslice, const short int scaling);
    Temporal(const float timeslice, const short int scaling, const std::string unit);
    Temporal(const float timeslice, const short int scaling, const shp::Unit& unit);
    Temporal(const Direction& change);
    Temporal(const Direction& change, const Quantity& timeslice);
    Temporal(const float change, const float timeslice);
    Temporal(const float change, const float timeslice, const std::string unit);
    Temporal(const float change, const float timeslice, const shp::Unit& unit);
    Temporal(const Direction& change, const float timeslice);
    Temporal(const float change, const float timeslice, short int scaling);
    Temporal(const Direction& change, const float timeslice, short int scaling);
    Temporal(const float change, const float timeslice, short int scaling, std::string unit);
    Temporal(const Direction& change, const float timeslice, short int scaling, std::string unit);
    Temporal(const float change, const float timeslice, short int scaling, const Unit& unit);
    Temporal(const Direction& change, const float timeslice, short int scaling, const Unit& unit);

    // Destructors
    ~Temporal();

    // Operator overloading
    bool operator==(const Temporal& peer) const;
    Temporal operator+(const Temporal& peer) const;
    Temporal operator-(const Temporal& peer) const;
    Temporal operator*(const Temporal& peer) const;
    Temporal operator/(const Temporal& peer) const;
    Temporal operator%(const Temporal& peer) const;

    // Getters
    Direction getChange() const { return change; }

    // Setters
    void setChange(const Direction& orientation) { this->change = orientation; }

    // Additional methods
    virtual Quantity getPhaseShift() const;
    virtual Quantity getTimePeriod() const;
    virtual Quantity getFrequency() const;
    virtual Temporal copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Temporal > TemporalArray;

} // namespace shp

#endif //SHP_TEMPORAL_H