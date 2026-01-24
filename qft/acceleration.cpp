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
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const Velocity& velocity)
        : qft::Velocity(velocity), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const shp::Unit& unit)
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const std::string unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(changeSpeed),
        unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const std::string unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeSpeed, const Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeSpeed, const Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(std::string name)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const shp::Unit& unit)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle)
        : qft::Velocity(name, shp::Azimuth(changeAngle)),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const float changeAngle, const std::string unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle, const shp::Unit& unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle, const float changeSpeed)
        : qft::Velocity(name, shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const std::string unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeAngle,
        const float changeSpeed, const shp::Unit& unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeSpeed,
		const qft::Velocity& velocity)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(UNIT) {

}

Acceleration::Acceleration(std::string name, const float changeSpeed,
		const qft::Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(std::string name, const float changeSpeed,
		const qft::Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::~Acceleration() {

}

bool Acceleration::operator==(const Acceleration& peer) const {
    return (static_cast<const Velocity&>(*this) == static_cast<const Velocity&>(peer))
        && (changeSpeed == peer.changeSpeed) && (unit == peer.unit);
}

bool Acceleration::operator<(const Acceleration& peer) const {
    return (static_cast<const Velocity&>(*this) < static_cast<const Velocity&>(peer))
        && (changeSpeed < peer.changeSpeed);
}

bool Acceleration::operator>(const Acceleration& peer) const {
    return (static_cast<const Velocity&>(*this) > static_cast<const Velocity&>(peer))
        && (changeSpeed > peer.changeSpeed);
}

bool Acceleration::operator<=(const Acceleration& peer) const {
    Acceleration self = *this;
    return (self < peer) || (self == peer);
}

bool Acceleration::operator>=(const Acceleration& peer) const {
    Acceleration self = *this;
    return (self > peer) || (self == peer);
}

Acceleration Acceleration::operator+(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self + other);
    return Acceleration( (changeSpeed + peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator-(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self - other);
    return Acceleration((changeSpeed - peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator*(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self * other);
    return Acceleration((changeSpeed * peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator/(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self / other);
    return Acceleration((changeSpeed / peer.changeSpeed), velocity, unit);
}

Acceleration Acceleration::operator%(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity velocity = (self % other);
    return Acceleration(fmod(changeSpeed, peer.changeSpeed), velocity, unit);
}

void Acceleration::applyChangeTogether() {
    this->applyChangeDirection();
	this->applyChangeMagnitude();
}

void Acceleration::applyChangeDirection() {
    Velocity::setChangeDirection(Velocity::getDirection().toRadians());
}

void Acceleration::applyChangeMagnitude() {
    Velocity::setChangeMagnitude(changeSpeed);
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
	shp::Signal rotation = invariant.getAngular((Velocity::getDirection().toRadians() + theta.getMagnitude()));
    shp::Signal result(rotation.getMagnitude(), rotation.getScaling(), rotation.getUnit());
    return result;
}

shp::Direction Acceleration::getAngularVelocity(const Time& interval) const {
	float rate = (Velocity::getDirection().toRadians() / interval.getMagnitude());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Acceleration::getAngularShiftRate() const {
	shp::Direction result(Velocity::getDirection().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

bool Acceleration::checkNonZero() const {
	return Velocity::checkNonZero() && (changeSpeed != shp::Quantity::DEFAULT_VALUE);
}

Velocity Acceleration::copy() {
    Velocity self = *this;
    Acceleration fresh(this->changeSpeed, self, unit);
    return fresh;
}

void Acceleration::clear() {
    Velocity::clear();
    changeSpeed = shp::Quantity::DEFAULT_VALUE;
    unit.clear();
    return;
}

std::string Acceleration::print() const {
    std::stringstream result;
    result << "a";
    result << Velocity::print() << ",Δ{";
	result << changeSpeed  << ",⌒";
    result << getAngularShiftRate().print() << "}";
    result << unit.print();
	return result.str();
}

std::string Acceleration::printRadians() const {
    std::stringstream result;
    result << "a";
    result << Velocity::printRadians() << ",Δ{";
	result << changeSpeed << ",⌒";
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