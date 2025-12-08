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

#ifndef QFT_PRESSURE_H
#define QFT_PRESSURE_H

#include <string>
#include <vector>
#include "force.h"
#include "../shp/area.h"
#include "../shp/unit.h"

namespace qft {

class Pressure {
    std::string name;
    shp::Unit unit;
    qft::Force force;
    shp::Area area;
public:
    // Constructors
    Pressure();
    Pressure(std::string name);
    Pressure(const float force);
    Pressure(const float force, const float length, const float breadth);
    Pressure(const qft::Force& force, const shp::Area& area);
    Pressure(std::string name, const shp::Unit& unit);
    Pressure(std::string name, const float force, const float length, const float breadth);
    Pressure(std::string name, const qft::Force& force, const shp::Area& area);
    Pressure(std::string name, const shp::Unit& unit, const qft::Force& force, const shp::Area& area);

    // Destructors
    ~Pressure();

    // Operator overloading
    bool operator==(const Pressure& peer) const;
    Pressure operator+(const Pressure& peer) const;
    Pressure operator-(const Pressure& peer) const;
    Pressure operator*(const Pressure& peer) const;
    Pressure operator/(const Pressure& peer) const;

    // Getters
    std::string getName() const { return name; }
    shp::Unit getUnit() const { return unit; }
    qft::Force getForce() const { return force; }
    shp::Area getArea() const { return area; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setForce(const qft::Force& magnitude) { this->force = magnitude; }
    void setArea(const shp::Area& amount) { this->area = amount; }

    // Additional methods
    float getTotal() const;
    virtual Pressure copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string UNIT;
};

typedef std::vector<Pressure > PressureArray;

} // namespace qft

#endif //QFT_PRESSURE_H