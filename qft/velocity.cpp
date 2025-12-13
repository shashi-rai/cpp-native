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

#include "velocity.h"

namespace qft {

const std::string Velocity::UNIT = "m/s";   // System International

Velocity::Velocity() : name(),
        magnitude(UNIT), direction() {

}

Velocity::Velocity(std::string name) : name(name),
        magnitude(UNIT), direction() {

}

Velocity::Velocity(const float magnitude) : name(),
        magnitude(magnitude, UNIT), direction() {

}

Velocity::Velocity(const float magnitude, const std::string unit)
        : name(), magnitude(magnitude, unit), direction() {

}

Velocity::Velocity(const float magnitude, short int scaling, const std::string unit)
        : name(), magnitude(magnitude, scaling, unit), direction() {

}

Velocity::Velocity(const float magnitude, const float direction)
        : name(), magnitude(magnitude, UNIT), direction(direction) {

}

Velocity::Velocity(const float magnitude, const float direction, const std::string unit)
        : name(),  magnitude(magnitude, unit), direction(direction) {

}

Velocity::Velocity(const float magnitude, const float direction, short int scaling)
        : name(), magnitude(magnitude, scaling, UNIT), direction(direction) {

}

Velocity::Velocity(const float magnitude, const float direction,
        short int scaling, const std::string unit)
        : name(), magnitude(magnitude, scaling, unit), direction(direction) {

}

Velocity::Velocity(const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(), magnitude(magnitude), direction(direction) {

}

Velocity::Velocity(std::string name, const shp::Unit& unit)
        : name(name), magnitude(unit), direction() {

}

Velocity::Velocity(std::string name, const float magnitude)
        : name(name), magnitude(magnitude, UNIT), direction() {

}

Velocity::Velocity(std::string name, const float magnitude, const shp::Unit& unit)
        : name(name), magnitude(magnitude, unit), direction() {

}

Velocity::Velocity(std::string name, const float magnitude, const float direction)
        : name(name), magnitude(magnitude, UNIT), direction(direction) {

}

Velocity::Velocity(std::string name, const float magnitude, const float direction,
        const std::string unit)
        : name(name), magnitude(magnitude, unit), direction(direction) {

}

Velocity::Velocity(std::string name, const float magnitude, const float direction,
        short int scaling)
        : name(name), magnitude(magnitude, scaling, UNIT), direction(direction) {

}

Velocity::Velocity(std::string name, const float magnitude, const float direction,
        short int scaling, const std::string unit)
        : name(name), magnitude(magnitude, scaling, unit), direction(direction) {

}

Velocity::Velocity(std::string name, const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(name), magnitude(magnitude), direction(direction) {

}

Velocity::~Velocity() {

}

bool Velocity::operator==(const Velocity& peer) const {
    return (magnitude == peer.magnitude) && (direction == peer.direction);
}

Velocity Velocity::operator+(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex((other.magnitude.getValue() / std::pow(10, (magnitude.getScaling() - other.magnitude.getScaling()))),
			other.direction.toRadians());
    std::complex<float> a_phasor = ap1 + ap2;
    return Velocity("+", shp::Quantity(std::abs(a_phasor), magnitude.getScaling(), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator-(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex((other.magnitude.getValue() / std::pow(10, (magnitude.getScaling() - other.magnitude.getScaling()))),
			other.direction.toRadians());
    std::complex<float> a_phasor = ap1 - ap2;
    return Velocity("-", shp::Quantity(std::abs(a_phasor), magnitude.getScaling(), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator*(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex(other.magnitude.getValue(), other.direction.toRadians());
    std::complex<float> a_phasor = ap1 * ap2;
    return Velocity("*", shp::Quantity(std::abs(a_phasor),
			(magnitude.getScaling() + peer.magnitude.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator/(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex(other.magnitude.getValue(), other.direction.toRadians());
    std::complex<float> a_phasor = ap1 / ap2;
    return Velocity("/", shp::Quantity(std::abs(a_phasor),
			(magnitude.getScaling() - peer.magnitude.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

shp::Quantity Velocity::getTotal() const {
    shp::Quantity result(magnitude.getValue(), magnitude.getScaling(), getUnit());
    return result;
}

void Velocity::adjustScaling() {
    magnitude.adjustScaling();
}

Velocity Velocity::copy() {
    Velocity fresh(name, magnitude, direction);
    return fresh;
}

void Velocity::clear() {
	name = "";
    magnitude.clear();
    direction.clear();
    return;
}

std::string Velocity::print() {
    std::stringstream result;
    result << "(v:";
	result << name << ",";
    result << magnitude.print() << ",";
	result << direction.print() << ")";
	return result.str();
}

shp::Quantity Velocity::getComponent(float phase) const {
	shp::Quantity velocity = getTotal();
	return shp::Quantity((velocity.getValue() * cos(phase)), velocity.getScaling(), velocity.getUnit());
}

std::complex<float> Velocity::toComplex(float coefficient, float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

} // namespace qft