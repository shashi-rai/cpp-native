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

#ifndef QFT_POWER_H
#define QFT_POWER_H

#include "time.h"

namespace qft {

class Power {
    std::string name;
    shp::Unit unit;
    shp::Quantity energy;
    qft::Time interval;
public:
    // Constructors
    Power();
    Power(const std::string name);
    Power(const float energy);
    Power(const float energy, const float interval);
    Power(const shp::Quantity& energy, const Time& interval);
    Power(const shp::Quantity& energy, const Time& interval, const shp::Unit& unit);
    Power(const std::string name, const shp::Unit& unit);
    Power(const std::string name, const float energy, const float interval);
    Power(const std::string name, const float energy, const float interval, const std::string unit);
    Power(const std::string name, const shp::Quantity& energy, const qft::Time& interval);
    Power(const std::string name, const shp::Quantity& energy, const qft::Time& interval, const shp::Unit& unit);

    // Destructors
    ~Power();

    // Operator overloading
    bool operator==(const Power& peer) const;
    Power operator+(const Power& peer) const;
    Power operator-(const Power& peer) const;
    Power operator*(const Power& peer) const;
    Power operator/(const Power& peer) const;
    Power operator%(const Power& peer) const;

    // Getters
    std::string getName() const { return name; }
    shp::Unit getUnit() const { return unit; }
    shp::Quantity getEnergy() const { return energy; }
    qft::Time getInterval() const { return interval; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setEnergy(const shp::Quantity& magnitude) { this->energy = magnitude; }
    void setInterval(const qft::Time& delta) { this->interval = delta; }

    // Additional methods
    shp::Signal getTotal() const;
    virtual Power copy();
    virtual void clear();
    virtual std::string print();
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Power > PowerArray;

} // namespace qft

#endif //QFT_POWER_H