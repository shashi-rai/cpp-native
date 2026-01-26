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

Velocity::Velocity()
        : shp::Distance(UNIT), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::shared_ptr<Time> domain)
        : shp::Distance(UNIT), name() {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name)
        : shp::Distance(UNIT), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name,
		const std::shared_ptr<Time> domain)
        : shp::Distance(UNIT), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const shp::Unit& unit)
        : shp::Distance(unit), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const shp::Unit& unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(unit), name() {
	setTemporal(domain);
}

Velocity::Velocity(const shp::Azimuth& direction)
        : shp::Distance(UNIT, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(UNIT, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement)
        : shp::Distance(displacement, UNIT), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, UNIT), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const std::string unit)
        : shp::Distance(displacement, unit), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const std::string unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const shp::Unit& unit)
        : shp::Distance(displacement, unit), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const shp::Unit& unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling)
        : shp::Distance(displacement, scaling, UNIT), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const float direction)
        : shp::Distance(displacement, UNIT, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const float direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, UNIT, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const shp::Azimuth& direction)
        : shp::Distance(displacement, UNIT, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, UNIT, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const std::string unit, const float direction)
        : shp::Distance(displacement, unit, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const std::string unit, const float direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const std::string unit, const shp::Azimuth& direction)
        : shp::Distance(displacement, unit, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const std::string unit, const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const shp::Unit& unit, const shp::Azimuth& direction)
        : shp::Distance(displacement, unit, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const shp::Unit& unit, const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit)
        : shp::Distance(displacement, scaling, unit), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling, const shp::Unit& unit)
        : shp::Distance(displacement, scaling, unit), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const short int scaling, const shp::Unit& unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling, const float direction)
        : shp::Distance(displacement, scaling, UNIT, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const short int scaling, const float direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, UNIT, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling, const shp::Azimuth& direction)
        : shp::Distance(displacement, scaling, UNIT, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const short int scaling, const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, UNIT, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit,
        const float direction)
        : shp::Distance(displacement, scaling, unit, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit,
        const float direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit,
        const shp::Azimuth& direction)
        : shp::Distance(displacement, scaling, unit, direction), name() {
	setTemporal(nullptr);
}

Velocity::Velocity(const float displacement, const short int scaling, const std::string unit,
        const shp::Azimuth& direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit, direction), name() {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const std::string unit)
        : shp::Distance(unit), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const std::string unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(unit), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const shp::Unit& unit)
        : shp::Distance(unit), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const shp::Unit& unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(unit), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const shp::Azimuth& direction)
        : shp::Distance(UNIT, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(UNIT, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement)
        : shp::Distance(displacement, UNIT), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, UNIT), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const std::string unit)
        : shp::Distance(displacement, unit), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const std::string unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Unit& unit)
        : shp::Distance(displacement, unit), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Unit& unit,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling)
        : shp::Distance(displacement, scaling, UNIT), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const float direction)
        : shp::Distance(displacement, UNIT, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const float direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, UNIT, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Azimuth& direction)
        : shp::Distance(displacement, UNIT, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Azimuth& direction,
		const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, UNIT, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const std::string unit,
        const float direction)
        : shp::Distance(displacement, unit), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const std::string unit,
        const float direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Unit& unit,
        const float direction)
        : shp::Distance(displacement, unit, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Unit& unit,
        const float direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Unit& unit,
        const shp::Azimuth& direction)
        : shp::Distance(displacement, unit, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const shp::Unit& unit,
        const shp::Azimuth& direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, unit, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const float direction)
        : shp::Distance(displacement, scaling, UNIT, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const float direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, UNIT, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const shp::Azimuth& direction)
        : shp::Distance(displacement, scaling, UNIT, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const shp::Azimuth& direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, UNIT, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const std::string unit, const float direction)
        : shp::Distance(displacement, scaling, unit, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const std::string unit, const float direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const shp::Unit& unit, const float direction)
        : shp::Distance(displacement, scaling, unit, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const shp::Unit& unit, const float direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit, direction), name(name) {
	setTemporal(domain);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const shp::Unit& unit, const shp::Azimuth& direction)
        : shp::Distance(displacement, scaling, unit, direction), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
        const shp::Unit& unit, const shp::Azimuth& direction, const std::shared_ptr<Time> domain)
        : shp::Distance(displacement, scaling, unit, direction), name(name) {
	setTemporal(domain);
}

Velocity::~Velocity() {
	setTemporal(nullptr);
}

bool Velocity::operator==(const Velocity& peer) const {
	return (static_cast<const shp::Distance&>(*this) == static_cast<const shp::Distance&>(peer))
		&& (temporal == peer.temporal);
}

bool Velocity::operator<(const Velocity& peer) const {
	Velocity self = *this; bool result = false;
    if (static_cast<const shp::Distance&>(*this) < static_cast<const shp::Distance&>(peer)) {
		result = true;
	}
	return result;
}

bool Velocity::operator>(const Velocity& peer) const {
	Velocity self = *this; bool result = false;
    if (static_cast<const shp::Distance&>(*this) > static_cast<const shp::Distance&>(peer)) {
		result = true;
	}
	return result;
}

bool Velocity::operator<=(const Velocity& peer) const {
    Velocity self = *this;
    return (self < peer) || (self == peer);
}

bool Velocity::operator>=(const Velocity& peer) const {
    Velocity self = *this;
    return (self > peer) || (self == peer);
}

Velocity Velocity::operator+(const Velocity& peer) const {
    shp::Distance self = *this, other = peer;
	shp::Distance velocity = (self + other);
    return Velocity("+", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator-(const Velocity& peer) const {
    shp::Distance self = *this, other = peer;
	shp::Distance velocity = (self - other);
    return Velocity("-", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator*(const Velocity& peer) const {
    shp::Distance self = *this, other = peer;
	shp::Distance velocity = (self * other);
    return Velocity("*", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator/(const Velocity& peer) const {
    shp::Distance self = *this, other = peer;
	shp::Distance velocity = (self / other);
    return Velocity("/", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator%(const Velocity& peer) const {
    shp::Distance self = *this, other = peer;
	shp::Distance velocity = (self % other);
    return Velocity("%", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

shp::Unit Velocity::getUnit() const {
	return shp::Distance::getUnit();
}

void Velocity::setUnit(const shp::Unit& unit) {
	shp::Distance::setUnit(unit);
}

shp::Distance Velocity::getDisplacement() const {
	shp::Distance result = *this;
	return result;
}

void Velocity::setDisplacement(const shp::Distance& distance) {
	shp::Distance::setMagnitude(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
}

void Velocity::setDisplacement(const float distance) {
	shp::Distance::setMagnitude(distance);
}

void Velocity::setDisplacement(const float distance, const short int scale) {
	shp::Distance::setMagnitude(distance, scale);
}

void Velocity::setDisplacement(const float distance, const short int scale, const std::string unit) {
	shp::Distance::setMagnitude(distance, scale, unit);
}

void Velocity::setDisplacement(const float distance, const short int scale, const shp::Unit& unit) {
	shp::Distance::setMagnitude(distance, scale, unit);
}

shp::Azimuth Velocity::getDirection() const {
	return shp::Distance::getAzimuth();
}

void Velocity::setDirection(const float orientation) {
	shp::Distance::setAzimuth(orientation);
}

void Velocity::setDirection(const shp::Azimuth& orientation) {
	shp::Distance::setAzimuth(orientation);
}

void Velocity::setChangeMagnitude(const float motion) {
	shp::Distance::setChangeMagnitude(motion);
}

void Velocity::setChangeDirection(const float degree) {
	shp::Distance::setChangeDirection(degree);
}

/*
 * Its impossible to calculate linear velocity without referring to a time domain
 */
shp::Signal Velocity::getTotal() const {
	shp::Signal displacement = shp::Distance::getTotal(), interval, velocity;
	if (isTimeBound()) {	// timeless domain cannot have a linear velocity
		interval = temporal->getTotal();
		velocity = (displacement / interval);
	}
    shp::Signal result(velocity.getOrientation(),
		velocity.getMagnitude(), velocity.getScaling(), UNIT);
    return result;
}

shp::Signal Velocity::getLinear(const float slice) {
	shp::Distance self = *this; shp::Frequency frequency(shp::Quantity::DEFAULT_VALUE);
	float magnitude; short int scaling = shp::Quantity::DEFAULT_SCALE;
	if (isTimeBound()) {
		frequency = temporal->getFrequency();
		magnitude = ((self.getAmplitude() * frequency.getMagnitude()) / slice);
		scaling = (self.getScaling() + frequency.getScaling());
	}
    shp::Signal result(self.getAzimuth(), magnitude, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Signal Velocity::getAngular(const float theta) {
	shp::Distance self = *this; shp::Quantity rotation;
	if (isTimeBound()) {
		rotation = temporal->getPhaseShift();
		rotation = rotation.getMultiple(theta);
	}
    shp::Signal result(self.getAzimuth(), rotation.getMagnitude(), rotation.getScaling(), rotation.getUnit());
    return result;
}

void Velocity::adjustScaling() {
    shp::Distance::adjustScaling();
}

bool Velocity::checkNonZero() const {
	return shp::Distance::checkNonZero();
}

bool Velocity::isTimeBound() const {
    return (temporal != nullptr);
}

shp::Distance Velocity::copy() {
	shp::Distance self = *this;
    Velocity fresh(getName(), self.getMagnitude(), self.getScaling(), self.getUnit(), self.getAzimuth());
    return fresh;
}

void Velocity::clear() {
	shp::Distance::clear();
	name.clear();
    return;
}

std::string Velocity::print() const {
    std::stringstream result;
    result << "(v:";
	result << name << ",";
    result << shp::Distance::print() << ")";
	return result.str();
}

std::string Velocity::printRadians() const {
    std::stringstream result;
    result << "(v:";
	result << name << ",";
    result << shp::Distance::printRadians() << ")";
	return result.str();
}

shp::Signal Velocity::getCosComponent(const float phase) const {
	shp::Signal velocity = this->getTotal();
	return shp::Signal(velocity.getCosComponent(phase), velocity.getScaling(), velocity.getUnit());
}

shp::Signal Velocity::getSinComponent(const float phase) const {
	shp::Signal velocity = this->getTotal();
	return shp::Signal(velocity.getSinComponent(phase), velocity.getScaling(), velocity.getUnit());
}

std::complex<float> Velocity::toComplex(const float coefficient, const float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

} // namespace qft