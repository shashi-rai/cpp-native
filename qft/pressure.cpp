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

#include "pressure.h"

namespace qft {

const std::string Pressure::UNIT = "Pa";    // System International

Pressure::Pressure()
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(), area() {

}

Pressure::Pressure(std::string name)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(), area() {

}

Pressure::Pressure(const float force)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force), area() {

}

Pressure::Pressure(const float force, const float length, const float breadth)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force), area(length, breadth) {

}

Pressure::Pressure(const qft::Force& force, const shp::Area& area)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force), area(area) {

}

Pressure::Pressure(std::string name, const shp::Unit& unit) : name(name), unit(unit),
        force(), area() {

}

Pressure::Pressure(std::string name, const float force, const float length, const float breadth)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force), area(length, breadth) {

}

Pressure::Pressure(std::string name, const qft::Force& force, const shp::Area& area)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force), area(area) {

}

Pressure::Pressure(std::string name,
        const qft::Force& force, const shp::Area& area, const shp::Unit& unit)
        : name(name), unit(unit), force(force), area(area) {

}

Pressure::~Pressure() {

}

bool Pressure::operator==(const Pressure& peer) const {
    return (force == peer.force) && (area == peer.area) && (unit == peer.unit);
}

Pressure Pressure::operator+(const Pressure& peer) const {
    return Pressure("+", (force + peer.force), (area + peer.area), unit);
}

Pressure Pressure::operator-(const Pressure& peer) const {
    return Pressure("-", (force - peer.force), (area - peer.area), unit);
}

Pressure Pressure::operator*(const Pressure& peer) const {
    return Pressure("*", (force * peer.force), (area * peer.area), unit);
}

Pressure Pressure::operator/(const Pressure& peer) const {
    return Pressure("/", (force / peer.force), (area / peer.area), unit);
}

Pressure Pressure::operator%(const Pressure& peer) const {
    return Pressure("%", (force % peer.force), (area % peer.area), unit);
}

shp::Signal Pressure::getTotal() const {
    float pressure = (force.getTotal().getMagnitude() / area.getScalarTotal().getMagnitude());
    short int scaling = (force.getTotal().getScaling() - area.getScalarTotal().getScaling());
    shp::Signal result(pressure, scaling, getUnit());
    return result;
}

Density Pressure::getDensity(const shp::Volume& volume) const {
    shp::Signal total = this->getTotal(); 
    Density result(total.getMagnitude(), total.getScaling(), total.getUnit(), volume);
    return result;
}

Pressure Pressure::copy() {
    Pressure fresh(name, force, area, unit);
    return fresh;
}

void Pressure::clear() {
	name.clear();
    unit.clear();
    force.clear();
    area.clear();
    return;
}

std::string Pressure::print() {
    std::stringstream result;
    result << "P:";
	result << name << ",";
    result << force.print() << ",";
	result << area.print();
    result << unit.print();
	return result.str();
}

shp::Signal Pressure::getCosComponent(const float phase) const {
	shp::Signal pressure = this->getTotal();
	return shp::Signal(pressure.getCosComponent(phase), pressure.getScaling(), pressure.getUnit());
}

shp::Signal Pressure::getSinComponent(const float phase) const {
	shp::Signal pressure = this->getTotal();
	return shp::Signal(pressure.getSinComponent(phase), pressure.getScaling(), pressure.getUnit());
}

} // namespace qft