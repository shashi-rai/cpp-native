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

#ifndef QFT_VELOCITY_H
#define QFT_VELOCITY_H

#include <string>
#include <vector>
#include "../shp/direction.h"
#include "../shp/quantity.h"
#include "../shp/unit.h"

namespace qft {

class Velocity {
    std::string name;
    shp::Unit unit;
    shp::Quantity magnitude;
    shp::Direction direction;
public:
    // Constructors
    Velocity();
    Velocity(std::string name);
    Velocity(const shp::Quantity& magnitude, const shp::Direction& direction);
    Velocity(std::string name, const shp::Unit& unit);
    Velocity(std::string name, const shp::Quantity& magnitude, const shp::Direction& direction);
    Velocity(std::string name, const shp::Unit& unit, const shp::Quantity& magnitude, const shp::Direction& direction);

    // Destructors
    ~Velocity();

    // Operator overloading
    bool operator==(const Velocity& peer) const;
    Velocity operator+(const Velocity& peer) const;
    Velocity operator-(const Velocity& peer) const;
    Velocity operator*(const Velocity& peer) const;
    Velocity operator/(const Velocity& peer) const;
    Velocity operator%(const Velocity& peer) const;

    // Getters
    std::string getName() const { return name; }
    shp::Unit getUnit() const { return unit; }
    shp::Quantity getMagnitude() const { return magnitude; }
    shp::Direction getDirection() const { return direction; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setMagnitude(const shp::Quantity& magnitude) { this->magnitude = magnitude; }
    void setDirection(const shp::Direction& direction) { this->direction = direction; }

    // Additional methods
    float getTotal() const;
    virtual Velocity copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string UNIT;
};

typedef std::vector<Velocity > VelocityArray;

} // namespace qft

#endif //QFT_VELOCITY_H