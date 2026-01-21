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

Signal::Signal(const float quantity, const std::string unit)
		: Quantity(quantity, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, const Unit& unit)
		: Quantity(quantity, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, const short int scaling)
		: Quantity(quantity, scaling), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, const short int scaling, const std::string unit)
		: Quantity(quantity, scaling, unit), orientation(shp::Direction::DEFAULT_RADIANS) {

}

Signal::Signal(const float quantity, const short int scaling, const Unit& unit)
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

Signal::Signal(const Azimuth& orientation, const float quantity, const Unit& unit)
        : Quantity(quantity, unit), orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity, const short int scaling)
        : Quantity(quantity, scaling), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, const short int scaling)
        : Quantity(quantity, scaling), orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity, const short int scaling,
		const std::string unit)
        : Quantity(quantity, scaling, unit), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, const short int scaling,
		const std::string unit)
        : Quantity(quantity, scaling, unit), orientation(orientation.toRadians()) {

}

Signal::Signal(const float orientation, const float quantity, const short int scaling,
		const Unit& unit)
        : Quantity(quantity, scaling, unit), orientation(orientation) {

}

Signal::Signal(const Azimuth& orientation, const float quantity, const short int scaling,
		const Unit& unit)
        : Quantity(quantity, scaling, unit), orientation(orientation.toRadians()) {

}

Signal::~Signal() {

}

bool Signal::operator==(const Signal& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (orientation == peer.orientation);
}

bool Signal::operator<(const Signal& peer) const {
    return (static_cast<const Quantity&>(*this) < static_cast<const Quantity&>(peer))
        && (orientation < peer.orientation);
}

bool Signal::operator>(const Signal& peer) const {
    return (static_cast<const Quantity&>(*this) > static_cast<const Quantity&>(peer))
        && (orientation < peer.orientation);
}

bool Signal::operator<=(const Signal& peer) const {
    Signal self = *this;
    return (self < peer) || (self == peer);
}

bool Signal::operator>=(const Signal& peer) const {
    Signal self = *this;
    return (self > peer) || (self == peer);
}

Signal Signal::operator+(const Signal& peer) const {
    Quantity self = *this, other = peer;
    short int exponent = (self.getScaling() - other.getScaling());
    float mantissa_x = self.getMagnitude();
    float mantissa_y = (other.getMagnitude() / std::pow(DECIMAL_SCALE, exponent));
    std::complex<float> a = self.getComplex(mantissa_x, this->orientation);
    std::complex<float> b = other.getComplex(mantissa_y, peer.orientation);
    std::complex<float> result = (a + b);
    return Signal(result.imag(), result.real(), self.getScaling(), self.getUnit());
}

Signal Signal::operator-(const Signal& peer) const {
    Quantity self = *this, other = peer;
    short int exponent = (self.getScaling() - other.getScaling());
    float mantissa_x = self.getMagnitude();
    float mantissa_y = (other.getMagnitude() / std::pow(DECIMAL_SCALE, exponent));
    std::complex<float> a = self.getComplex(mantissa_x, this->orientation);
    std::complex<float> b = other.getComplex(mantissa_y, peer.orientation);
    std::complex<float> result = (a - b);
    return Signal(result.imag(), result.real(), self.getScaling(), self.getUnit());
}

Signal Signal::operator*(const Signal& peer) const {
    Quantity self = *this, other = peer;
    short int exponent = (self.getScaling() + other.getScaling());
    float mantissa_x = self.getMagnitude();
    float mantissa_y = other.getMagnitude();
    std::complex<float> a = self.getComplex(mantissa_x, this->orientation);
    std::complex<float> b = other.getComplex(mantissa_y, peer.orientation);
    std::complex<float> result = (a * b);
    return Signal(result.imag(), result.real(), exponent, self.getUnit());
}

Signal Signal::operator/(const Signal& peer) const {
    Quantity self = *this, other = peer;
    short int exponent = (self.getScaling() - other.getScaling());
    float mantissa_x = self.getMagnitude();
    float mantissa_y = other.getMagnitude();
    std::complex<float> a = self.getComplex(mantissa_x, this->orientation);
    std::complex<float> b = other.getComplex(mantissa_y, peer.orientation);
    std::complex<float> result;
	if (b == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		result = std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE);
	} else {
		result = (a / b); 
	}
    return Signal(result.imag(), result.real(), exponent, self.getUnit());
}

Signal Signal::operator%(const Signal& peer) const {
    Quantity self = *this, other = peer;
    short int exponent = (self.getScaling() - other.getScaling());
    float mantissa_x = self.getMagnitude();
    float mantissa_y = (other.getMagnitude() / std::pow(DECIMAL_SCALE, exponent));
    std::complex<float>
        a = self.getComplex(mantissa_x, this->orientation),
        b = other.getComplex(mantissa_y, peer.orientation);
    std::complex<float> result;
	if (b == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		result = std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE);
	} else {
		std::complex<float> quotient = (a / b);
    	std::complex<float> cycles(std::trunc(quotient.real()), std::trunc(quotient.imag()));
    	result = (a - (cycles * b));
	}
    return Signal(result.imag(), result.real(), self.getScaling(), self.getUnit());
}

Signal Signal::operator()(const float scaleup) const {
    Quantity self = *this;
    Quantity product = self.getMultiple(scaleup);
    return Signal(this->orientation, product.getMagnitude(), product.getScaling(), self.getUnit());
}

Signal Signal::getRotation(const short int degree) const {
    Quantity self = *this; Azimuth direction(orientation);
    Azimuth phase = direction.getRotation(degree);
    return Signal(phase, self.getMagnitude(), self.getScaling(), self.getUnit());
}

Signal Signal::getLinearAmplified(const Quantity& peer) const {
    Quantity self = *this, other = peer;
    Quantity field = (self * other); field.adjustScaling();
    return Signal(this->orientation, field.getMagnitude(), field.getScaling(), self.getUnit());
}

Signal Signal::getSquareAmplified(const Quantity& peer) const {
    Quantity self = *this, other = peer;
    Quantity field = (self * other.getSquare()); field.adjustScaling();
    return Signal(this->orientation, field.getMagnitude(), field.getScaling(), self.getUnit());
}

Signal Signal::getLinearDivergence(const Quantity& peer) const {
    Quantity self = *this, other = peer;
    Quantity field = (self / other); field.adjustScaling();
    return Signal(this->orientation, field.getMagnitude(), field.getScaling(), self.getUnit());
}

Signal Signal::getSquareDivergence(const Quantity& peer) const {
    Quantity self = *this, other = peer;
    Quantity field = (self / other.getSquare()); field.adjustScaling();
    return Signal(this->orientation, field.getMagnitude(), field.getScaling(), self.getUnit());
}

Signal Signal::getDotProduct(const Signal& peer) const {
    Quantity self = *this, other = peer;
    Quantity product = (self * other); product.adjustScaling();
    return Signal(this->orientation, product.getMagnitude(), product.getScaling(), self.getUnit());
}

Signal Signal::getCrossProduct(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity product; Azimuth normal;
    float difference = (peer.orientation - this->orientation);
    if (difference != Direction::DEFAULT_RADIANS && difference != Direction::DEGREE_180) {
        Direction angle = Direction::getDifference(this->orientation, peer.orientation);
        float radians = angle.toRadians(); normal = Azimuth(radians);
        product = (self * other).getSinComponent(radians);
    } else if (difference == Direction::DEGREE_090 || difference == Direction::DEGREE_270) {
        product = (self * other);
    }
    product.adjustScaling();
    return Signal(normal.toRadians(), product.getMagnitude(), product.getScaling(), self.getUnit());
}

Signal Signal::getDotFraction(const Signal& peer) const {
    Quantity self = *this, other = peer;
    Quantity fraction = (self / other); fraction.adjustScaling();
    return Signal(this->orientation, fraction.getMagnitude(), fraction.getScaling(), self.getUnit());
}

Signal Signal::getCrossFraction(const Signal& peer) const {
    Quantity self = *this, other = peer; Quantity fraction; Azimuth infinitesimal;
    float difference = (peer.orientation - this->orientation);
    if (difference != Direction::DEFAULT_RADIANS && difference != Direction::DEGREE_180) {
        Direction delta = Direction::getFraction(this->orientation, peer.orientation);
        float radians = delta.toRadians(); infinitesimal = Azimuth(radians);
        fraction = (self / other).getSinComponent(radians);
    } else if (difference == Direction::DEGREE_090 || difference == Direction::DEGREE_270) {
        fraction = (self / other);
    }
    fraction.adjustScaling();
    return Signal(infinitesimal.toRadians(), fraction.getMagnitude(), fraction.getScaling(), self.getUnit());
}

Frequency Signal::getFrequency() const {
    Quantity wave = Quantity::getInverse();
    Frequency result(Direction::DEFAULT_RADIANS, orientation, std::abs(wave.getMagnitude()),
        wave.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY));
    return result;
}

float Signal::getCyclingRate() const {
    return Direction(orientation).getCyclingRate();
}

float Signal::getTimePerCycle() const {
    return Direction(orientation).getTimePerCycle();
}

float Signal::getMagnitude() const {
    return Quantity::getMagnitude();
}

void Signal::setMagnitude(const float value) {
    Quantity::setMagnitude(value);
}

void Signal::setMagnitude(const float value, const short int scale) {
    Quantity::setMagnitude(value, scale);
}

void Signal::setMagnitude(const float value, const short int scale, const std::string unit) {
    Quantity::setMagnitude(value, scale, unit);
}

void Signal::setMagnitude(const float value, const short int scale, const Unit& unit) {
    Quantity::setMagnitude(value, scale, unit);
}

float Signal::getAmplitude() const {
    return Quantity::getCosComponent(orientation);
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

Signal Signal::getScalarAbsolute() const {
    Quantity self = *this;
    return Signal(this->orientation, std::abs(self.getMagnitude()), self.getScaling(), self.getUnit());
}

Signal Signal::getVectorAbsolute() const {
    Signal self = *this;
    std::complex<float> result = Quantity::getComplex(Quantity::getMagnitude(), self.orientation);
    return Signal(std::imag(result), std::abs(result), self.getScaling(), self.getUnit());
}

Signal Signal::getScalarNegative() const {
    Quantity self = *this; Quantity negative = self.getNegative();
    std::complex<float> result = Quantity::getComplex(negative.getMagnitude(), this->orientation);
    return Signal(std::imag(result), std::real(result), negative.getScaling(), negative.getUnit());
}

Signal Signal::getVectorNegative() const {
    Signal self = *this;
    std::complex<float> result = Quantity::getComplex(Quantity::getMagnitude(), -self.orientation);
    return Signal(std::imag(result), -std::real(result), self.getScaling(), self.getUnit());
}

Signal Signal::getScalarInverse() const {
    Quantity self = *this; Quantity inverse = self.getInverse();
    std::complex<float> result = Quantity::getComplex(inverse.getMagnitude(), this->orientation);
    return Signal(std::imag(result), std::real(result), inverse.getScaling(), inverse.getUnit());
}

Signal Signal::getVectorInverse() const {
    Signal self = *this;
    std::complex<float> result = Quantity::getComplex(Quantity::getMagnitude(), -self.orientation);
    return Signal(std::imag(result), -std::real(result), self.getScaling(), self.getUnit());
}

Signal Signal::getScalarPercent() const {
    Quantity self = *this, percent = Quantity::getPercent();
    Signal result(this->orientation, percent.getMagnitude(), percent.getScaling(), percent.getUnit());
    return result;
}

Signal Signal::getVectorPercent() const {
    Signal self = *this;
    Signal result(self.orientation, self.getAmplitude(), self.getScaling(), self.getUnit().getPercent()); 
    return result;
}

Signal Signal::getDotProductSquare() const {
    Quantity self = *this, square = Quantity::getSquare();
    Signal result(this->orientation, square.getMagnitude(), square.getScaling(), square.getUnit());
    return result;
}

Signal Signal::getDotFractionSquare() const {
    Quantity self = *this, inverse = Quantity::getInverse();
    Quantity square = inverse.getSquare();
    Signal result(this->orientation, square.getMagnitude(), square.getScaling(), square.getUnit());
    return result;
}

Signal Signal::getCrossProductSquare() const {
    Signal self = *this;
    std::complex<float> component = Quantity::getComplex(Quantity::getMagnitude(), self.orientation);
    std::complex<float> total = (component * component);
    Signal result(total.imag(), total.real(), (self.getScaling() * 2), self.getUnit().getSquare()); 
    return result;
}

Signal Signal::getCrossFractionSquare() const {
    Signal self = *this; Quantity inverse = Quantity::getInverse();
    std::complex<float> component = Quantity::getComplex(inverse.getMagnitude(), self.orientation);
    std::complex<float> total = (component * component);
    Signal result(total.imag(), total.real(), (self.getScaling() * 2), self.getUnit().getSquare()); 
    return result;
}

Signal Signal::getDotProductSquareRoot() const {
    Quantity self = *this, root = Quantity::getSquareRoot();
    Signal result(this->orientation, root.getMagnitude(), root.getScaling(), root.getUnit());
    return result;
}

Signal Signal::getDotProductCube() const {
    Quantity self = *this, cube = Quantity::getCube();
    Signal result(this->orientation, cube.getMagnitude(), cube.getScaling(), cube.getUnit());
    return result;
}

Signal Signal::getDotFractionCube() const {
    Quantity self = *this; Quantity inverse = Quantity::getInverse();
    Quantity cube = inverse.getCube();
    Signal result(this->orientation, cube.getMagnitude(), cube.getScaling(), cube.getUnit());
    return result;
}

Signal Signal::getCrossProductCube() const {
    Signal self = *this;
    std::complex<float> factor = Quantity::getComplex(Quantity::getMagnitude(), self.orientation);
    std::complex<float> total = ((factor * factor) * factor);
    Signal result(total.imag(), total.real(), (self.getScaling() * 3), self.getUnit().getCube()); 
    return result;
}

Signal Signal::getCrossFractionCube() const {
    Signal self = *this; Quantity inverse = Quantity::getInverse();
    std::complex<float> factor = Quantity::getComplex(inverse.getMagnitude(), self.orientation);
    std::complex<float> total = ((factor * factor) * factor);
    Signal result(total.imag(), total.real(), (self.getScaling() * 3), self.getUnit().getCube()); 
    return result;
}

Signal Signal::getDotProductCubeRoot() const {
    Quantity self = *this, root = Quantity::getCubeRoot();
    Signal result(this->orientation, root.getMagnitude(), root.getScaling(), root.getUnit());
    return result;
}

Signal Signal::getScalarRemainder(const float coefficient) const {
    Quantity self = *this, remainder = self.getRemainder(coefficient);
    return Signal(this->orientation, remainder.getMagnitude(), remainder.getScaling(), self.getUnit());
}

Signal Signal::getScalarLeftOver(const float coefficient) const {
    Quantity self = *this, leftover = self.getLeftOver(coefficient);
    return Signal(this->orientation, leftover.getMagnitude(), leftover.getScaling(), self.getUnit());
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
    orientation = Direction::DEFAULT_RADIANS;
    return;
}

std::string Signal::print() const {
    std::stringstream result;
    result << "∿";
    result << Quantity::print() << ",φ";
    result << Direction(orientation).print();
	return result.str();
}

std::string Signal::printRadians() const {
    std::stringstream result;
    result << "∿";
    result << Quantity::print() << ",φ";
    result << std::setfill('0') <<  std::setprecision(8)
        << orientation << shp::Unit::getDerivedSymbol(shp::Unit::PLANE_ANGLE);
	return result.str();
}

float Signal::getCosComponent(const float phase) const {
    return Quantity::getCosComponent(phase);
}

float Signal::getSinComponent(const float phase) const {
    return Quantity::getSinComponent(phase);
}

const std::complex<float> Signal::getComplex(const float value, const float direction) {
    return Quantity::getComplex(value, direction);
}

} // namespace shp