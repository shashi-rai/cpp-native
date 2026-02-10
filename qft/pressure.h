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

#include "density.h"
#include "force.h"

namespace qft {

class Pressure : protected Density {
    qft::Force force;
    shp::Unit unit;
public:
    // Constructors
    Pressure();
    Pressure(const std::string name);
    Pressure(const float force);
    Pressure(const float force, const float length, const float breadth);
    Pressure(const qft::Force& force, const shp::Area& area);
    Pressure(const std::string name, const shp::Unit& unit);
    Pressure(const std::string name, const float force, const float length, const float breadth);
    Pressure(const std::string name, const qft::Force& force, const shp::Area& area);
    Pressure(const std::string name, const qft::Force& force, const shp::Area& area, const shp::Unit& unit);

    // Destructors
    ~Pressure();

    // Operator overloading
    bool operator==(const Pressure& peer) const;
    Pressure operator+(const Pressure& peer) const;
    Pressure operator-(const Pressure& peer) const;
    Pressure operator*(const Pressure& peer) const;
    Pressure operator/(const Pressure& peer) const;
    Pressure operator%(const Pressure& peer) const;

    // Getters
    qft::Force getForce() const { return force; }
    shp::Unit getUnit() const { return unit; }

    // Setters
    void setForce(const qft::Force& magnitude) { this->force = magnitude; }
    void setUnit(const shp::Unit& object) { this->unit = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    shp::Area getArea() const;
    void setArea(const shp::Area& planar);
    shp::Distance getHeight() const;
    void setHeight(const shp::Distance& height);
    shp::Volume getVolume() const;
    void setVolume(const shp::Volume& volume);
    shp::Signal getTotal() const;
    Density getDensity(const shp::Volume& volume) const;
    Pressure copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Pressure > PressureArray;

} // namespace qft

#endif //QFT_PRESSURE_H