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

const std::string Pressure::UNIT = shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE);

Pressure::Pressure() : name(), unit(UNIT), force(), area() {

}

Pressure::Pressure(std::string name) : name(name), unit(UNIT),
        force(), area() {

}

Pressure::Pressure(const qft::Force& force, const shp::Area& area)
        : name(), unit(UNIT), force(force), area(area) {

}

Pressure::Pressure(std::string name, const shp::Unit& unit) : name(name), unit(unit),
        force(), area() {

}

Pressure::Pressure(std::string name, const shp::Unit& unit,
        const qft::Force& force, const shp::Area& area)
        : name(name), unit(unit), force(force), area(area) {

}

Pressure::Pressure(std::string name,
        const qft::Force& force, const shp::Area& area)
        : name(name), unit(UNIT), force(force), area(area) {

}

Pressure::~Pressure() {

}

bool Pressure::operator==(const Pressure& peer) const {
    return (force == peer.force) && (area == peer.area);
}

Pressure Pressure::operator+(const Pressure& peer) const {
    return Pressure("+", (force + peer.force), (area + peer.area));
}

Pressure Pressure::operator-(const Pressure& peer) const {
    return Pressure("-", (force - peer.force), (area - peer.area));
}

Pressure Pressure::operator*(const Pressure& peer) const {
    return Pressure("*", (force * peer.force), (area * peer.area));
}

Pressure Pressure::operator/(const Pressure& peer) const {
    return Pressure("/", (force / peer.force), (area / peer.area));
}

Pressure Pressure::operator%(const Pressure& peer) const {
    return Pressure("%", (force % peer.force), (area % peer.area));
}

float Pressure::getTotal() const {
    float result = (force.getTotal() / area.getTotal());
    return result;
}

Pressure Pressure::copy() {
    Pressure fresh(name, unit, force, area);
    return fresh;
}

void Pressure::clear() {
	name = "";
    unit.clear();
    force.clear();
    area.clear();
    return;
}

std::string Pressure::print() {
    std::stringstream result;
    result << "[p:";
	result << name << ",";
    result << force.print() << ",";
	result << area.print() << " ";
    result << unit.print() << "]";
	return result.str();
}

} // namespace qft