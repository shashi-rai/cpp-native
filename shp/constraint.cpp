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

#include "constraint.h"

namespace shp {

Constraint::Constraint()
        : Signal() {

}

Constraint::Constraint(const Unit& unit)
        : Signal(unit) {

}

Constraint::Constraint(const float magnitude)
		: Signal(magnitude) {

}

Constraint::Constraint(const float magnitude, const std::string unit)
		: Signal(magnitude, unit) {

}

Constraint::Constraint(const float magnitude, const Unit& unit)
		: Signal(magnitude, unit) {

}

Constraint::Constraint(const float magnitude, const short int scaling)
		: Signal(magnitude, scaling) {

}

Constraint::Constraint(const float magnitude, const short int scaling, const std::string unit)
		: Signal(magnitude, scaling, unit) {

}

Constraint::Constraint(const float magnitude, const short int scaling, const Unit& unit)
		: Signal(magnitude, scaling, unit) {

}

Constraint::Constraint(const Intrinsic& phase)
        : Signal(phase) {

}

Constraint::Constraint(const Intrinsic& phase, const std::string unit)
        : Signal(phase, unit) {

}

Constraint::Constraint(const Intrinsic& phase, const Unit& unit)
        : Signal(phase, unit) {

}

Constraint::Constraint(const Intrinsic& phase, const float magnitude)
        : Signal(phase, magnitude) {

}

Constraint::Constraint(const Intrinsic& phase, const float magnitude, const std::string unit)
        : Signal(phase, magnitude, unit) {

}

Constraint::Constraint(const Intrinsic& phase, const float magnitude, const Unit& unit)
        : Signal(phase, magnitude, unit) {

}

Constraint::Constraint(const Intrinsic& phase, const float magnitude, const short int scaling)
        : Signal(phase, magnitude, scaling) {

}

Constraint::Constraint(const Intrinsic& phase, const float magnitude, const short int scaling,
        const std::string unit)
        : Signal(phase, magnitude, scaling, unit) {

}

Constraint::Constraint(const Intrinsic& phase, const float magnitude, const short int scaling,
        const Unit& unit)
        : Signal(phase, magnitude, scaling, unit) {

}

Constraint::~Constraint() {

}

bool Constraint::operator==(const Constraint& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer));
}

bool Constraint::operator<(const Constraint& peer) const {
    return (static_cast<const Signal&>(*this) < static_cast<const Signal&>(peer));
}

bool Constraint::operator>(const Constraint& peer) const {
    return (static_cast<const Signal&>(*this) > static_cast<const Signal&>(peer));
}

bool Constraint::operator<=(const Constraint& peer) const {
    Constraint self = *this;
    return (self < peer) || (self == peer);
}

bool Constraint::operator>=(const Constraint& peer) const {
    Constraint self = *this;
    return (self > peer) || (self == peer);
}

Constraint Constraint::operator+(const Constraint& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self + other); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator-(const Constraint& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self - other); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator*(const Constraint& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self * other); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator/(const Constraint& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self / other); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator%(const Constraint& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self % other); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator+(const shp::Quantity& peer) const {
    Signal self = *this, signal = (self + peer); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator-(const shp::Quantity& peer) const {
    Signal self = *this, signal = (self - peer); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator*(const shp::Quantity& peer) const {
    Signal self = *this, signal = (self * peer); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator/(const shp::Quantity& peer) const {
    Signal self = *this, signal = (self / peer); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

Constraint Constraint::operator%(const shp::Quantity& peer) const {
    Signal self = *this, signal = (self % peer); signal.adjustScaling();
    return Constraint(signal.getOrientation(),
        signal.getMagnitude(), signal.getScaling(), signal.getUnit());
}

float Constraint::getAmplitude() const {
    return Signal::getAmplitude();
}

float Constraint::getMagnitude() const {
    return Signal::getMagnitude();
}

void Constraint::setMagnitude(const float value) {
    Signal::setMagnitude(value);
}

void Constraint::setMagnitude(const float value, const short int scale) {
    Signal::setMagnitude(value, scale);
}

void Constraint::setMagnitude(const float value, const short int scale, const std::string unit) {
    Signal::setMagnitude(value, scale, unit);
}

void Constraint::setMagnitude(const float value, const short int scale, const Unit& unit) {
    Signal::setMagnitude(value, scale, unit);
}

float Constraint::getIntensity() const {
    return Signal::getAmplitude();
}

float Constraint::getIntensityDrift() const {
    return Signal::getOrientation();
}

void Constraint::setIntensityDrift(const float shift) {
    Signal::setOrientation(shift);
}

void Constraint::setIntensityDrift(const Intrinsic& shift) {
    Signal::setOrientation(shift.toRadians());
}

short int Constraint::getScaling() const {
    return Signal::getScaling();
}

void Constraint::setScaling(const short int factor) {
    Signal::setScaling(factor);
}

Unit Constraint::getUnit() const {
    return Signal::getUnit();
}

void Constraint::setUnit(const Unit& object) {
    Signal::setUnit(object);
}

bool Constraint::checkNonZero() const {
    return Signal::checkNonZero();
}

bool Constraint::checkInfinity() const {
    return Signal::checkInfinity();
}

short int Constraint::checkScaling(const float amount) const {
    return Signal::checkScaling(amount);
}

void Constraint::adjustNumeric() {
    return Signal::adjustNumeric();
}

void Constraint::adjustScaling() {
    Signal::adjustScaling();
}

Signal Constraint::getFrequency() const {
    return Signal::getFrequency();
}

Signal Constraint::getTotal() const {
    Signal self = *this;
    Constraint fresh(self.getOrientation(), self.getMagnitude(), self.getScaling(), self.getUnit());
    fresh.setUpperBound(this->upperBound);
    fresh.setLowerBound(this->lowerBound);
    return fresh;
}

Signal Constraint::copy() const {
    Signal self = *this;
    Constraint fresh(self.getOrientation(), self.getMagnitude(), self.getScaling(), self.getUnit());
    fresh.setUpperBound(this->upperBound);
    fresh.setLowerBound(this->lowerBound);
    return fresh;
}

void Constraint::clear() {
    Signal::clear();
    this->upperBound.clear();
    this->lowerBound.clear();
    return;
}

std::string Constraint::print() const {
    std::stringstream result;
    result << Signal::print() << ",u:";
    result << this->upperBound.print() << ",l:";
    result << this->lowerBound.print();
	return result.str();
}

std::string Constraint::printRadians() const {
    std::stringstream result;
    result << Signal::printRadians() << ",u:";
    result << this->upperBound.print() << ",l:";
    result << this->lowerBound.print();
	return result.str();
}

shp::Bound Constraint::getIncluded(const shp::Bound& value) const {
    shp::Bound result = shp::Bound::DEFAULT_VALUE;
    if (value >= this->lowerBound) {
        result = value;
    }
    if (value <= this->upperBound) {
        result = value;
    }
    return result;
}

shp::Bound Constraint::getExcluded(const shp::Bound& value) const {
    shp::Bound result = shp::Bound::DEFAULT_VALUE;
    if (value <= this->lowerBound) {
        result = value;
    }
    if (value >= this->upperBound) {
        result = value;
    }
    return result;
}

} // namespace shp