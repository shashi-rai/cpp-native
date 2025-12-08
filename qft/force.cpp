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

#include "force.h"

namespace qft {

const std::string Force::UNIT = "N";    // System International

Force::Force()
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(), direction() {

}

Force::Force(std::string name)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(), direction() {

}

Force::Force(const float magnitude)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(magnitude), direction() {

}

Force::Force(const float magnitude, const float direction)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(magnitude), direction(direction) {

}

Force::Force(const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(magnitude), direction(direction) {

}

Force::Force(std::string name, const shp::Unit& unit)
        : name(name), unit(unit), magnitude(), direction() {

}

Force::Force(std::string name, const float magnitude, const float direction)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(magnitude), direction(direction) {

}

Force::Force(std::string name, const shp::Unit& unit,
        const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(name), unit(unit), magnitude(magnitude), direction(direction) {

}

Force::Force(std::string name,
        const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        magnitude(magnitude), direction(direction) {

}

Force::~Force() {

}

bool Force::operator==(const Force& peer) const {
    return (magnitude == peer.magnitude) && (direction == peer.direction);
}

Force Force::operator+(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float> ap1 = self.toComplex(direction.toRadians()),
        ap2 = other.toComplex(peer.direction.toRadians());
    std::complex<float> a_phasor = ap1 + ap2;
    return Force("+", std::abs(a_phasor), std::arg(a_phasor));
}

Force Force::operator-(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float> ap1 = self.toComplex(direction.toRadians()),
        ap2 = other.toComplex(peer.direction.toRadians());
    std::complex<float> a_phasor = ap1 - ap2;
    return Force("-", std::abs(a_phasor), std::arg(a_phasor));
}

Force Force::operator*(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float> ap1 = self.toComplex(direction.toRadians()),
        ap2 = other.toComplex(peer.direction.toRadians());
    std::complex<float> a_phasor = ap1 * ap2;
    return Force("*", std::abs(a_phasor), std::arg(a_phasor));
}

Force Force::operator/(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float> ap1 = self.toComplex(direction.toRadians()),
        ap2 = other.toComplex(peer.direction.toRadians());
    std::complex<float> a_phasor = ap1 / ap2;
    return Force("/", std::abs(a_phasor), std::arg(a_phasor));
}

float Force::getTotal() const {
    float result = (magnitude.getValue() * cos(direction.toRadians()));
    return result;
}

Force Force::copy() {
    Force fresh(name, unit, magnitude, direction);
    return fresh;
}

void Force::clear() {
	name = "";
    unit.clear();
    magnitude.clear();
    direction.clear();
    return;
}

std::string Force::print() {
    std::stringstream result;
    result << "{f:";
	result << name << ",";
    result << magnitude.print() << ",";
	result << direction.print();
    result << unit.print() << "}";
	return result.str();
}

float Force::getComponent(float change) const {
    return magnitude.getValue() * cos(direction.toRadians() + change);
}

std::complex<float> Force::toComplex(float change) {
    return std::complex<float>(
        magnitude.getValue() * std::cos(change),
        magnitude.getValue() * std::sin(change));
}

} // namespace qft