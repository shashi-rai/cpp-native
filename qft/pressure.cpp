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
        : Density(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force() {

}

Pressure::Pressure(const std::string name)
        : Density(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force() {

}

Pressure::Pressure(const float force)
        : Density(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force) {

}

Pressure::Pressure(const float force, const float length, const float breadth)
        : Density(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force) {
    Density::setArea(length, breadth);
}

Pressure::Pressure(const qft::Force& force, const shp::Area& area)
        : Density(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force) {
    Density::setArea(area);
}

Pressure::Pressure(const std::string name, const shp::Unit& unit)
        : Density(name), unit(unit),
        force() {

}

Pressure::Pressure(const std::string name, const float force, const float length, const float breadth)
        : Density(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force) {
    Density::setArea(length, breadth);
}

Pressure::Pressure(const std::string name, const qft::Force& force, const shp::Area& area)
        : Density(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        force(force) {
    Density::setArea(area);
}

Pressure::Pressure(const std::string name,
        const qft::Force& force, const shp::Area& area, const shp::Unit& unit)
        : Density(name), unit(unit), force(force) {
    Density::setArea(area);
}

Pressure::~Pressure() {

}

bool Pressure::operator==(const Pressure& peer) const {
    return (static_cast<const qft::Density&>(*this) == static_cast<const qft::Density&>(peer))
        && (force == peer.force);
}

Pressure Pressure::operator+(const Pressure& peer) const {
    return Pressure("+", (force + peer.force), unit);
}

Pressure Pressure::operator-(const Pressure& peer) const {
    return Pressure("-", (force - peer.force), unit);
}

Pressure Pressure::operator*(const Pressure& peer) const {
    return Pressure("*", (force * peer.force), unit);
}

Pressure Pressure::operator/(const Pressure& peer) const {
    return Pressure("/", (force / peer.force), unit);
}

Pressure Pressure::operator%(const Pressure& peer) const {
    return Pressure("%", (force % peer.force), unit);
}

std::string Pressure::getName() const {
    return Density::getName();
}

void Pressure::setName(const std::string name) {
    Density::setName(name);
}

shp::Area Pressure::getArea() const {
    return Density::getArea();
}

void Pressure::setArea(const shp::Area& planar) {
    Density::setArea(planar);
}

shp::Distance Pressure::getHeight() const {
    return Density::getHeight();
}

void Pressure::setHeight(const shp::Distance& height) {
    Density::setHeight(height);
}

shp::Volume Pressure::getVolume() const {
    return Density::getVolume();
}

void Pressure::setVolume(const shp::Volume& volume) {
    Density::setVolume(volume);
}

shp::Signal Pressure::getTotal() const {
    shp::Area area = Density::getArea();
    float pressure = (force.getTotal().getMagnitude() / area.getRealScalar().getMagnitude());
    short int scaling = (force.getTotal().getScaling() - area.getRealScalar().getScaling());
    shp::Signal result(pressure, scaling, getUnit());
    return result;
}

Density Pressure::getDensity(const shp::Volume& volume) const {
    shp::Signal total = Density::getScalarFlux(); 
    Density result(total.getMagnitude(), total.getScaling(), total.getUnit(), volume);
    return result;
}

Pressure Pressure::copy() {
    Pressure fresh(Density::getName(), force, Density::getArea(), unit);
    return fresh;
}

void Pressure::clear() {
	Density::clear();
    force.clear();
    unit.clear();
    return;
}

std::string Pressure::print() const {
    std::stringstream result;
    result << "P:";
	result << Density::print() << ",";
    result << force.print() << ",";
    result << unit.print();
	return result.str();
}

std::string Pressure::printRadians() const {
    std::stringstream result;
    result << "P:";
	result << Density::printRadians() << ",";
    result << force.printRadians() << ",";
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