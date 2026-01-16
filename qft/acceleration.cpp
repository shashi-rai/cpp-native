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

#include "acceleration.h"

namespace qft {

const std::string Acceleration::UNIT = "m/s²";          // System International

Acceleration::Acceleration()
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const Velocity& velocity)
        : qft::Velocity(velocity), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const shp::Unit& unit)
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle)
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(changeAngle), unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const std::string unit)
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const shp::Unit& unit)
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed)
        : qft::Velocity(), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const std::string unit)
        : qft::Velocity(), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const shp::Unit& unit)
        : qft::Velocity(), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const Velocity& velocity)
        : qft::Velocity(velocity), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(std::string name)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const shp::Unit& unit)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(changeAngle), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const std::string unit)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const shp::Unit& unit)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed)
        : qft::Velocity(name), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const std::string unit)
        : qft::Velocity(name), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const shp::Unit& unit)
        : qft::Velocity(name), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const qft::Velocity& velocity)
        : qft::Velocity(velocity), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const qft::Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const qft::Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed),
        changeAngle(changeAngle), unit(unit) {

}

Acceleration::~Acceleration() {

}

bool Acceleration::operator==(const Acceleration& peer) const {
    return (static_cast<const Velocity&>(*this) == static_cast<const Velocity&>(peer))
        && (changeSpeed == peer.changeSpeed) && (changeAngle == peer.changeAngle)
        && (unit == peer.unit);
}

Acceleration Acceleration::operator+(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self + other);
    return Acceleration((changeAngle + peer.changeAngle),
        (changeSpeed + peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator-(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self - other);
    return Acceleration((changeAngle - peer.changeAngle),
        (changeSpeed - peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator*(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self * other);
    return Acceleration((changeAngle * peer.changeAngle),
        (changeSpeed * peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator%(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self % other);
    return Acceleration((fmod(changeAngle, peer.changeAngle)),
        fmod(changeSpeed, peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator/(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self / other);
    return Acceleration((changeAngle / peer.changeAngle),
        (changeSpeed / peer.changeSpeed), velocity, unit);
}

void Acceleration::applyChangeTogether() {
    this->applyChangeDirection();
	this->applyChangeMagnitude();
}

void Acceleration::applyChangeDirection() {
    Velocity::changeDirection(changeAngle);
}

void Acceleration::applyChangeMagnitude() {
    Velocity::changeSpeed(changeSpeed);
}

shp::Signal Acceleration::getTotal() const {
	qft::Velocity invariant = *this;		// non-accelerating component only
    shp::Signal velocity = (invariant.getTotal() + shp::Quantity(changeSpeed,
			getDisplacement().getScaling(), getUnit()));
    shp::Direction change = (invariant.getDirection() + getAngularShiftRate());
    float acceleration = (velocity.getMagnitude() * cos(change.toRadians()));
    shp::Signal result(acceleration, getDisplacement().getScaling(), getUnit());
    return result;
}

shp::Signal Acceleration::getLinear(const Time& slice) {
	qft::Velocity invariant = *this;		// non-accelerating component only
	shp::Frequency frequency = slice.getFrequency();
    shp::Signal velocity = (invariant.getTotal() + shp::Quantity(changeSpeed,
			getDisplacement().getScaling(), getUnit()));
	float magnitude = (velocity.getMagnitude() * frequency.getMagnitude());
	short int scaling = (velocity.getScaling() + frequency.getScaling());
    shp::Signal result(magnitude, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Signal Acceleration::getAngular(const Time& theta) {
	qft::Velocity invariant = *this;		// non-accelerating component only
	shp::Signal rotation = invariant.getAngular((changeAngle + theta.getMagnitude()));
    shp::Signal result(rotation.getMagnitude(), rotation.getScaling(), rotation.getUnit());
    return result;
}

shp::Direction Acceleration::getAngularVelocity(const Time& interval) const {
	float rate = (changeAngle / interval.getMagnitude());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Acceleration::getAngularShiftRate() const {
	shp::Direction result(changeAngle * shp::Direction::DEGREE_001);
	return result;
}

bool Acceleration::checkNonZero() const {
	return Velocity::checkNonZero()
		&& (changeSpeed != shp::Quantity::DEFAULT_VALUE)
		&& (changeAngle != shp::Quantity::DEFAULT_VALUE);
}

Velocity Acceleration::copy() {
    Velocity self = *this;
    Acceleration fresh(changeAngle, changeSpeed, self, unit);
    return fresh;
}

void Acceleration::clear() {
    Velocity::clear();
    changeAngle = shp::Quantity::DEFAULT_VALUE;
    changeSpeed = shp::Quantity::DEFAULT_VALUE;
    unit.clear();
    return;
}

std::string Acceleration::print() {
    std::stringstream result;
    result << "a";
    result << Velocity::print() << ",Δ{";
	result << changeSpeed  << ",⌒";
    result << getAngularShiftRate().print() << "}";
    result << unit.print();
	return result.str();
}

shp::Signal Acceleration::getCosComponent(float phase) const {
	shp::Signal acceleration = this->getTotal();
	return shp::Signal((acceleration.getCosComponent(phase)),
        acceleration.getScaling(), acceleration.getUnit());
}

shp::Signal Acceleration::getSinComponent(float phase) const {
	shp::Signal acceleration = this->getTotal();
	return shp::Signal((acceleration.getSinComponent(phase)),
        acceleration.getScaling(), acceleration.getUnit());
}

} // namespace qft