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

#ifndef QFT_ACCELERATION_H
#define QFT_ACCELERATION_H

#include <string>
#include <vector>
#include "velocity.h"
#include "../shp/change.h"

namespace qft {

class Acceleration {
    shp::Unit unit;
    qft::Velocity velocity;
    shp::Change change;
public:
    // Constructors
    Acceleration();
    Acceleration(std::string name);
    Acceleration(const float change);
    Acceleration(const float velocity, const float change);
    Acceleration(const qft::Velocity& velocity, const shp::Change& change);
    Acceleration(const shp::Unit& unit);
    Acceleration(std::string name, const shp::Unit& unit);
    Acceleration(std::string name, const float change);
    Acceleration(std::string name, const float velocity, const float change);
    Acceleration(const qft::Velocity& velocity, const shp::Change& change, const shp::Unit& unit);

    // Destructors
    ~Acceleration();

    // Operator overloading
    bool operator==(const Acceleration& peer) const;
    Acceleration operator+(const Acceleration& peer) const;
    Acceleration operator-(const Acceleration& peer) const;
    Acceleration operator*(const Acceleration& peer) const;
    Acceleration operator/(const Acceleration& peer) const;

    // Getters
    std::string getName() const { return velocity.getName(); }
    shp::Unit getUnit() const { return unit; }
    qft::Velocity getVelocity() const { return velocity; }
    shp::Change getChange() const { return change; }

    // Setters
    void setName(const std::string& name) { this->velocity.setName(name); }
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setVelocity(const qft::Velocity& quantity) { this->velocity = quantity; }
    void setChange(const shp::Change& rate) { this->change = rate; }

    // Additional methods
    shp::Quantity getTotal() const;
    void adjustScaling();
    virtual Acceleration copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Acceleration > AccelerationArray;

} // namespace qft

#endif //QFT_ACCELERATION_H