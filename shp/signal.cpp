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

#include "signal.h"
#include "frequency.h"

namespace shp {

Signal::Signal()
        : Quantity(), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const std::string unit)
        : Quantity(unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const Unit& unit)
        : Quantity(unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity)
		: Quantity(quantity), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, std::string unit)
		: Quantity(quantity, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, const Unit& unit)
		: Quantity(quantity, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, short int scaling)
		: Quantity(quantity, scaling), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, short int scaling, const std::string unit)
		: Quantity(quantity, scaling, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, short int scaling, const Unit& unit)
		: Quantity(quantity, scaling, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const Quantity& quantity)
		: Quantity(quantity.getMagnitude(), quantity.getScaling(), quantity.getUnit()),
        orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const Azimuth& orientation)
        : Quantity(), orientation(orientation.toRadians()) {

}

Signal::Signal(const Azimuth& orientation, const Quantity& quantity)
        : Quantity(quantity.getMagnitude(), quantity.getScaling(), quantity.getUnit()),
        orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity)
        : Quantity(quantity), orientation(orientation) {

}

Signal::Signal(const float orientation, const float quantity, const std::string unit)
        : Quantity(quantity, unit), orientation(orientation) {

}

Signal::Signal(const float orientation, const float quantity, const Unit& unit)
        : Quantity(quantity, unit), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity)
        : Quantity(quantity), orientation(orientation.toRadians()) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, const std::string unit)
        : Quantity(quantity, unit), orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity, short int scaling)
        : Quantity(quantity, scaling), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, short int scaling)
        : Quantity(quantity, scaling), orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity, short int scaling,
		std::string unit)
        : Quantity(quantity, scaling, unit), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, short int scaling,
		std::string unit)
        : Quantity(quantity, scaling, unit), orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity, short int scaling,
		const Unit& unit)
        : Quantity(quantity, scaling, unit), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, short int scaling,
		const Unit& unit)
        : Quantity(quantity, scaling, unit), orientation(orientation.toRadians()) {

}

Signal::~Signal() {

}

bool Signal::operator==(const Signal& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (orientation == peer.orientation);
}

Signal Signal::operator+(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity quantity = (self + other);
    std::complex<float> a = self.getComplex(this->orientation);
    std::complex<float> b = other.getComplex(peer.orientation);
    std::complex<float> result = (a + b);
    return Signal(result.imag(), result.real(), quantity.getScaling(), quantity.getUnit());
}

Signal Signal::operator-(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity quantity = (self - other);
    std::complex<float> a = self.getComplex(this->orientation);
    std::complex<float> b = other.getComplex(peer.orientation);
    std::complex<float> result = (a - b);
    return Signal(result.imag(), result.real(), quantity.getScaling(), quantity.getUnit());
}

Signal Signal::operator*(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity quantity = (self * other);
    std::complex<float> a = self.getComplex(this->orientation);
    std::complex<float> b = other.getComplex(peer.orientation);
    std::complex<float> result = (a * b);
    return Signal(result.imag(), result.real(), quantity.getScaling(), quantity.getUnit());
}

Signal Signal::operator/(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity quantity = (self / other);
    std::complex<float> a = self.getComplex(this->orientation);
    std::complex<float> b = other.getComplex(peer.orientation);
    std::complex<float> result;
	if (a == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		result = std::complex<float>(NAN, NAN);
	} else {
		result = (a / b);
	}
    return Signal(result.imag(), result.real(), quantity.getScaling(), quantity.getUnit());
}

Signal Signal::operator%(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity quantity = (self % other);
    std::complex<float> a = self.getComplex(this->orientation), b = other.getComplex(peer.orientation);
    std::complex<float> result;
	if (a == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		result = std::complex<float>(NAN, NAN);
	} else {
		std::complex<float> quotient = (a / b);
    	std::complex<float> cycles(std::trunc(quotient.real()), std::trunc(quotient.imag()));
    	result = (a - (cycles * b));
	}
    return Signal(result.imag(), result.real(), quantity.getScaling(), quantity.getUnit());
}

Frequency Signal::getFrequency() const {
    Quantity wave = Quantity::getInverse();
    Frequency result(Direction::DEFAULT_RADIANS, orientation, std::abs(wave.getMagnitude()),
        wave.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY));
    return result;
}

float Signal::getAmplitude() const {
    return Quantity::getCosComponent(orientation);
}

void Signal::setAmplitude(const float value) {
    Quantity::setMagnitude(value);
}

Direction Signal::getPhase() const {
    return Direction(orientation);
}

void Signal::setPhase(const Direction& direction) {
    this->orientation = direction.toRadians();
}

short int Signal::getScaling() const {
    return Quantity::getScaling();
}

void Signal::setScaling(const short int factor) {
    Quantity::setScaling(factor);
}

Unit Signal::getUnit() const {
    return Quantity::getUnit();
}

void Signal::setUnit(const Unit& object) {
    Quantity::setUnit(object);
}

Quantity Signal::getAbsolute() const {
    Quantity self = *this;
    std::complex<float> result = Quantity::getComplex(this->orientation);
    return Quantity(std::abs(result), self.getScaling(), self.getUnit());
}

Signal Signal::getInverse() const {
    Signal self = *this;
    std::complex<float> result = Quantity::getComplex(-this->orientation);
    return Signal(std::imag(result), -std::real(result), self.getScaling(), self.getUnit());
}

Quantity Signal::getPercent() const {
    return Quantity::getPercent();
}

Quantity Signal::getSquare() const {
    return Quantity::getSquare();
}

Quantity Signal::getSquareRoot() const {
    return Quantity::getSquareRoot();
}

Quantity Signal::getCube() const {
    return Quantity::getCube();
}

Quantity Signal::getCubeRoot() const {
    return Quantity::getCubeRoot();
}

bool Signal::isConvergent() const {
    return Quantity::isConvergent();
}

bool Signal::isDivergent() const {
    return Quantity::isDivergent();
}

bool Signal::checkNonZero() const {
    return Quantity::checkNonZero();
}

bool Signal::checkInfinity() const {
    return Quantity::checkInfinity();
}

short int Signal::checkScaling(const float amount) const {
    return Quantity::checkScaling(amount);
}

void Signal::adjustNumeric() {
    return Quantity::adjustNumeric();
}

void Signal::adjustScaling() {
    Quantity::adjustScaling();
}

Signal Signal::copy() const {
    Quantity self = *this;
    Signal fresh(orientation, self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Signal::clear() {
    Quantity::clear();
    orientation = Quantity::DEFAULT_VALUE;
    return;
}

std::string Signal::print() {
    std::stringstream result;
    result << "∿";
    result << Quantity::print() << ",φ";
    result << Direction(orientation).print();
	return result.str();
}

} // namespace shp