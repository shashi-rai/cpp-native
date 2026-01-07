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
        displacement(UNIT), direction() {

}

Velocity::Velocity(std::string name) : name(name),
        displacement(UNIT), direction() {

}

Velocity::Velocity(const float displacement) : name(),
        displacement(displacement, UNIT), direction() {

}

Velocity::Velocity(const float displacement, const std::string unit)
        : name(), displacement(displacement, unit), direction() {

}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit)
        : name(), displacement(displacement, scaling, unit), direction() {

}

Velocity::Velocity(const float displacement, const float direction)
        : name(), displacement(displacement, UNIT), direction(direction) {

}

Velocity::Velocity(const float displacement, const float direction, const std::string unit)
        : name(),  displacement(displacement, unit), direction(direction) {

}

Velocity::Velocity(const float displacement, const float direction, const short int scaling)
        : name(), displacement(displacement, scaling, UNIT), direction(direction) {

}

Velocity::Velocity(const float displacement, const float direction,
        const short int scaling, const std::string unit)
        : name(), displacement(displacement, scaling, unit), direction(direction) {

}

Velocity::Velocity(const shp::Distance& displacement, const shp::Direction& direction)
        : name(), displacement(displacement), direction(direction) {

}

Velocity::Velocity(std::string name, const shp::Unit& unit)
        : name(name), displacement(unit), direction() {

}

Velocity::Velocity(std::string name, const float displacement)
        : name(name), displacement(displacement, UNIT), direction() {

}

Velocity::Velocity(std::string name, const float displacement, const shp::Unit& unit)
        : name(name), displacement(displacement, unit), direction() {

}

Velocity::Velocity(std::string name, const float displacement, const float direction)
        : name(name), displacement(displacement, UNIT), direction(direction) {

}

Velocity::Velocity(std::string name, const float displacement, const float direction,
        const std::string unit)
        : name(name), displacement(displacement, unit), direction(direction) {

}

Velocity::Velocity(std::string name, const float displacement, const float direction,
        const short int scaling)
        : name(name), displacement(displacement, scaling, UNIT), direction(direction) {

}

Velocity::Velocity(std::string name, const float displacement, const float direction,
        const short int scaling, const std::string unit)
        : name(name), displacement(displacement, scaling, unit), direction(direction) {

}

Velocity::Velocity(std::string name, const shp::Distance& displacement, const shp::Direction& direction)
        : name(name), displacement(displacement), direction(direction) {

}

Velocity::~Velocity() {

}

bool Velocity::operator==(const Velocity& peer) const {
    return (displacement == peer.displacement) && (direction == peer.direction);
}

Velocity Velocity::operator+(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.displacement.getMagnitude(), direction.toRadians()),
        ap2 = other.toComplex((other.displacement.getMagnitude() / std::pow(shp::Quantity::DECIMAL_SCALE, (displacement.getScaling() - other.displacement.getScaling()))),
			other.direction.toRadians());
    std::complex<float> a_phasor = ap1 + ap2;
    return Velocity("+", shp::Distance(std::abs(a_phasor), displacement.getScaling(), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator-(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.displacement.getMagnitude(), direction.toRadians()),
        ap2 = other.toComplex((other.displacement.getMagnitude() / std::pow(shp::Quantity::DECIMAL_SCALE, (displacement.getScaling() - other.displacement.getScaling()))),
			other.direction.toRadians());
    std::complex<float> a_phasor = ap1 - ap2;
    return Velocity("-", shp::Distance(std::abs(a_phasor), displacement.getScaling(), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator*(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.displacement.getMagnitude(), direction.toRadians()),
        ap2 = other.toComplex(other.displacement.getMagnitude(), other.direction.toRadians());
    std::complex<float> a_phasor = ap1 * ap2;
    return Velocity("*", shp::Distance(std::abs(a_phasor),
			(displacement.getScaling() + peer.displacement.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator/(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.displacement.getMagnitude(), direction.toRadians()),
        ap2 = other.toComplex(other.displacement.getMagnitude(), other.direction.toRadians());
    std::complex<float> a_phasor = ap1 / ap2;
    return Velocity("/", shp::Distance(std::abs(a_phasor),
			(displacement.getScaling() - peer.displacement.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

Velocity Velocity::operator%(const Velocity& peer) const {
    Velocity self = *this, other = peer;
    std::complex<float>
		ap1 = self.toComplex(self.displacement.getMagnitude(), direction.toRadians()),
        ap2 = other.toComplex(other.displacement.getMagnitude(), other.direction.toRadians());
	std::complex<float> a_phasor;
	if (ap2 == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		a_phasor = std::complex<float>(NAN, NAN);
	} else {
		std::complex<float> quotient = (ap1 / ap2);
    	std::complex<float> cycles(std::trunc(quotient.real()), std::trunc(quotient.imag()));
    	a_phasor = (ap1 - (cycles * ap2));
	}
    return Velocity("%", shp::Distance(std::abs(a_phasor),
			(displacement.getScaling() - peer.displacement.getScaling()), getUnit()),
		shp::Direction(std::arg(a_phasor)));
}

void Velocity::changeSpeed(const float motion) {
	if (motion != shp::Quantity::DEFAULT_VALUE) {
		float speed = displacement.getMagnitude() + motion;
		displacement.setMagnitude(speed); displacement.adjustScaling();
	}
}

void Velocity::changeDirection(const float degree) {
    if (degree != shp::Quantity::DEFAULT_VALUE) {
        float rotation = direction.toRadians() + (shp::Direction::DEGREE_001 * degree);
        direction = shp::Direction(rotation);
    }
}

shp::Quantity Velocity::getTotal() const {
    shp::Quantity result(displacement.getMagnitude(), displacement.getScaling(), getUnit());
    return result;
}

shp::Quantity Velocity::getLinear(const Time& slice) {
	shp::Quantity frequency = slice.getFrequency();
	float magnitude = (displacement.getMagnitude() * frequency.getMagnitude());
	short int scaling = (displacement.getScaling() + frequency.getScaling());
    shp::Quantity result(magnitude, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Quantity Velocity::getAngular(const Time& theta) {
	shp::Quantity rotation = theta.getAngular();
    shp::Quantity result(rotation.getMagnitude(), rotation.getScaling(), rotation.getUnit());
    return result;
}

void Velocity::adjustScaling() {
    displacement.adjustScaling();
}

bool Velocity::checkNonZero() const {
	return displacement.checkNonZero();
}

Velocity Velocity::copy() {
    Velocity fresh(name, displacement, direction);
    return fresh;
}

void Velocity::clear() {
	name.clear();
    displacement.clear();
    direction.clear();
    return;
}

std::string Velocity::print() {
    std::stringstream result;
    result << "(v:";
	result << name << ",";
    result << displacement.print() << ",";
	result << direction.print() << ")";
	return result.str();
}

shp::Quantity Velocity::getComponent(float phase) const {
	shp::Quantity velocity = getTotal();
	return shp::Quantity((velocity.getMagnitude() * cos(phase)), velocity.getScaling(), velocity.getUnit());
}

std::complex<float> Velocity::toComplex(float coefficient, float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

} // namespace qft