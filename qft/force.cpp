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
#include "acceleration.h"
#include "mass.h"

namespace qft {

const std::string Force::UNIT = "N";                    // System International
const float Force::COULOMB_CONSTANT = 8.99f;            // 8.99 x 10^9 N.m^2.C^2
const short int Force::COULOMB_SCALE = 9;               // 10^9 N.m^2.C^2
const float Force::GRAVITATIONAL_CONSTANT = 6.6743f;    // 6.6743 x 10^-11 m^3.kg^-1.s^-2
const short int Force::GRAVITATIONAL_SCALE = -11;       // 10^-11 m^3.kg^-1.s^-2

Force::Force() : name(),
        magnitude(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)), direction() {

}

Force::Force(std::string name) : name(name),
        magnitude(shp::Unit::getDerivedSymbol(shp::Unit::FORCE)), direction() {

}

Force::Force(const float magnitude) : name(),
        magnitude(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        direction() {

}

Force::Force(const float magnitude, const std::string unit)
        : name(), magnitude(magnitude, unit), direction() {

}

Force::Force(const float magnitude, short int scaling, const std::string unit)
        : name(), magnitude(magnitude, scaling, unit), direction() {

}

Force::Force(const float magnitude, const float direction)
        : name(), magnitude(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        direction(direction) {

}

Force::Force(const float magnitude, const float direction, const std::string unit)
        : name(),  magnitude(magnitude, unit), direction(direction) {

}

Force::Force(const float magnitude, const float direction, short int scaling)
        : name(), magnitude(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        direction(direction) {

}

Force::Force(const float magnitude, const float direction,
        short int scaling, const std::string unit)
        : name(), magnitude(magnitude, scaling, unit), direction(direction) {

}

Force::Force(const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(), magnitude(magnitude), direction(direction) {

}

Force::Force(std::string name, const shp::Unit& unit)
        : name(name), magnitude(unit), direction() {

}

Force::Force(std::string name, const float magnitude)
        : name(name),
        magnitude(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        direction() {

}

Force::Force(std::string name, const float magnitude, const shp::Unit& unit)
        : name(name), magnitude(magnitude, unit),
        direction() {

}

Force::Force(std::string name, const float magnitude, const float direction)
        : name(name),
        magnitude(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        direction(direction) {

}

Force::Force(std::string name, const float magnitude, const float direction,
        const std::string unit)
        : name(name), magnitude(magnitude, unit), direction(direction) {

}

Force::Force(std::string name, const float magnitude, const float direction,
        short int scaling)
        : name(name),
        magnitude(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FORCE)),
        direction(direction) {

}

Force::Force(std::string name, const float magnitude, const float direction,
        short int scaling, const std::string unit)
        : name(name), magnitude(magnitude, scaling, unit), direction(direction) {

}

Force::Force(std::string name, const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(name), magnitude(magnitude), direction(direction) {

}

Force::~Force() {

}

bool Force::operator==(const Force& peer) const {
    return (magnitude == peer.magnitude) && (direction == peer.direction);
}

Force Force::operator+(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex((other.magnitude.getValue() / std::pow(10, (magnitude.getScaling() - other.magnitude.getScaling()))),
			other.direction.toRadians());
    std::complex<float> a_phasor = ap1 + ap2;
    return Force("+", shp::Quantity(std::abs(a_phasor), magnitude.getScaling(), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Force Force::operator-(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex((other.magnitude.getValue() / std::pow(10, (magnitude.getScaling() - other.magnitude.getScaling()))),
			other.direction.toRadians());
    std::complex<float> a_phasor = ap1 - ap2;
    return Force("-", shp::Quantity(std::abs(a_phasor), magnitude.getScaling(), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Force Force::operator*(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex(other.magnitude.getValue(), other.direction.toRadians());
    std::complex<float> a_phasor = ap1 * ap2;
    return Force("*", shp::Quantity(std::abs(a_phasor),
			(magnitude.getScaling() + peer.magnitude.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Force Force::operator/(const Force& peer) const {
    Force self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.magnitude.getValue(), direction.toRadians()),
        ap2 = other.toComplex(other.magnitude.getValue(), other.direction.toRadians());
    std::complex<float> a_phasor = ap1 / ap2;
    return Force("/", shp::Quantity(std::abs(a_phasor),
			(magnitude.getScaling() - peer.magnitude.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Acceleration Force::getAcceleration(const Mass& mass) const {
	shp::Quantity quantum = (magnitude / mass.getMagnitude());
	Acceleration result(quantum.getValue(), quantum.getScaling(), quantum.getUnit());
	result.adjustScaling();
    return result;
}

shp::Quantity Force::getTotal() const {
    shp::Quantity result(magnitude.getValue(), magnitude.getScaling(), getUnit());
    return result;
}

void Force::adjustScaling() {
    magnitude.adjustScaling();
}

Force Force::copy() {
    Force fresh(name, magnitude, direction);
    return fresh;
}

void Force::clear() {
	name = "";
    magnitude.clear();
    direction.clear();
    return;
}

std::string Force::print() {
    std::stringstream result;
    result << "𝐹:";
	result << name << ",";
    result << magnitude.print() << ",";
	result << direction.print();
	return result.str();
}

shp::Quantity Force::getComponent(float phase) const {
	shp::Quantity force = getTotal();
	return shp::Quantity((force.getValue() * cos(phase)), force.getScaling(), force.getUnit());
}

std::complex<float> Force::toComplex(float coefficient, float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

const shp::Quantity Force::getGavitationLimit() {
    return shp::Quantity(GRAVITATIONAL_CONSTANT, GRAVITATIONAL_SCALE, UNIT);
}

} // namespace qft