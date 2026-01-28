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

Acceleration::Acceleration(const std::shared_ptr<Time> domain)
        : qft::Velocity(domain), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const shp::Unit& unit)
        : qft::Velocity(), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(domain), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(changeAngle), domain), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const std::string unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(changeAngle), domain), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(changeAngle), domain), changeSpeed(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(changeSpeed),
        unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(changeAngle), domain), changeSpeed(changeSpeed),
        unit(UNIT) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const std::string unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(changeAngle), domain), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeAngle, const float changeSpeed,
        const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(changeAngle), domain), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeSpeed, const Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeSpeed, const Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const std::string name)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, domain), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const std::string unit)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, domain), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Unit& unit)
        : qft::Velocity(name), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, domain), changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle)
        : qft::Velocity(name, shp::Azimuth(changeAngle)),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(changeAngle), domain),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const std::string unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(changeAngle), domain),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const shp::Unit& unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(changeAngle), domain),
		changeSpeed(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const float changeSpeed)
        : qft::Velocity(name, shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle, const float changeSpeed, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(changeAngle), domain), changeSpeed(changeSpeed), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle,
        const float changeSpeed, const std::string unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle,
        const float changeSpeed, const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(changeAngle), domain), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle,
        const float changeSpeed, const shp::Unit& unit)
        : qft::Velocity(name, shp::Azimuth(changeAngle)), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float changeAngle,
        const float changeSpeed, const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(changeAngle), domain), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const float changeSpeed, const qft::Velocity& velocity)
        : qft::Velocity(velocity), changeSpeed(changeSpeed), unit(UNIT) {

}

Acceleration::Acceleration(const std::string name, const float displacement, const short int scale,
        const std::string unit, const shp::Azimuth& orientation, const std::shared_ptr<Time> domain,
        const float changeSpeed)
        : qft::Velocity(name, displacement, scale), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::Acceleration(const std::string name, const float displacement, const short int scale,
        const shp::Unit& unit, const shp::Azimuth& orientation, const std::shared_ptr<Time> domain,
        const float changeSpeed)
        : qft::Velocity(name, displacement, scale), changeSpeed(changeSpeed), unit(unit) {

}

Acceleration::~Acceleration() {

}

bool Acceleration::operator==(const Acceleration& peer) const {
    return (static_cast<const Velocity&>(*this) == static_cast<const Velocity&>(peer))
        && (changeSpeed == peer.changeSpeed) && (unit == peer.unit);
}

bool Acceleration::operator<(const Acceleration& peer) const {
	Acceleration self = *this; bool result = false;
    if (static_cast<const qft::Velocity&>(*this) < static_cast<const qft::Velocity&>(peer)) {
		result = true;
	} else if (changeSpeed < peer.changeSpeed) {
        result = true;
    }
	return result;
}

bool Acceleration::operator>(const Acceleration& peer) const {
	Acceleration self = *this; bool result = false;
    if (static_cast<const qft::Velocity&>(*this) > static_cast<const qft::Velocity&>(peer)) {
		result = true;
	} else if (changeSpeed > peer.changeSpeed) {
        result = true;
    }
	return result;
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
    Velocity newVelocity = (self + other);
    return Acceleration((changeSpeed + peer.changeSpeed), newVelocity, unit);
}

Acceleration Acceleration::operator-(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self - other);
    return Acceleration((changeSpeed - peer.changeSpeed), newVelocity, unit);
}

Acceleration Acceleration::operator*(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self * other);
    return Acceleration((changeSpeed * peer.changeSpeed), newVelocity, unit);
}

Acceleration Acceleration::operator/(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self / other);
    return Acceleration((changeSpeed / peer.changeSpeed), newVelocity, unit);
}

Acceleration Acceleration::operator%(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self % other);
    return Acceleration(fmod(changeSpeed, peer.changeSpeed), newVelocity, unit);
}

Acceleration Acceleration::operator+(const float distance) const {
    Velocity self = *this, newVelocity = (self + distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator-(const float distance) const {
    Velocity self = *this, newVelocity = (self - distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator*(const float distance) const {
    Velocity self = *this, newVelocity = (self * distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator/(const float distance) const {
    Velocity self = *this, newVelocity = (self / distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator%(const float distance) const {
    Velocity self = *this, newVelocity = (self % distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator+(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self + distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator-(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self - distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator*(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self * distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator/(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self / distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator%(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self % distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator+(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self + distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator-(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self - distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator*(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self * distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator/(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self / distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator%(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self % distance);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator+(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self + velocity);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator-(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self - velocity);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator*(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self * velocity);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator/(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self / velocity);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator%(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self % velocity);
    return Acceleration(this->changeSpeed, newVelocity, unit);
}

Acceleration Acceleration::operator+(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() + orientation);
    return Acceleration("+", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->changeSpeed);
}

Acceleration Acceleration::operator-(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() - orientation);
    return Acceleration("-", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->changeSpeed);
}

Acceleration Acceleration::operator*(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() * orientation);
    return Acceleration("*", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->changeSpeed);
}

Acceleration Acceleration::operator/(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() / orientation);
    return Acceleration("/", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->changeSpeed);
}

Acceleration Acceleration::operator%(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() % orientation);
    return Acceleration("%", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->changeSpeed);
}

Acceleration Acceleration::operator+(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() + curvature);
    Acceleration result("+", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->changeSpeed);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator-(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() - curvature);
    Acceleration result("-", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->changeSpeed);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator*(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() * curvature);
    Acceleration result("*", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->changeSpeed);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator/(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() / curvature);
    Acceleration result("/", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->changeSpeed);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator%(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() % curvature);
    Acceleration result("%", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->changeSpeed);
    result.setFieldCurvature(newCurvature);
    return result;
}

shp::Distance Acceleration::getDisplacement() const {
	return Velocity::getDisplacement();
}

void Acceleration::setDisplacement(const shp::Quantity& distance, const shp::Azimuth& direction) {
    Velocity::setDisplacement(distance, direction);
}

void Acceleration::setDisplacement(const shp::Quantity& distance, const shp::Polar& curvature) {
    Velocity::setDisplacement(distance, curvature);
}

void Acceleration::setDisplacement(const shp::Distance& distance) {
	Velocity::setDisplacement(distance);
}

void Acceleration::setDisplacement(const float distance) {
	Velocity::setMagnitude(distance);
}

void Acceleration::setDisplacement(const float distance, const short int scale) {
	Velocity::setMagnitude(distance, scale);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const std::string unit) {
	Velocity::setMagnitude(distance, scale, unit);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const shp::Unit& unit) {
	Velocity::setMagnitude(distance, scale, unit);
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

float Acceleration::getChangeMagnitude() const {
    return changeSpeed;
}

void Acceleration::setChangeMagnitude(const float speed) {
    this->changeSpeed = speed; Velocity::setChangeMagnitude(speed);
}

void Acceleration::setChangeMagnitude(const float speed, const short int scale) {
	Velocity::setChangeMagnitude(speed, scale);
}

void Acceleration::setChangeDirection(const float degree) {
	Velocity::setChangeDirection(degree);
}

shp::Signal Acceleration::getTotal() const {
	Velocity invariant = *this;     // non-accelerating component only
    shp::Signal velocity = (invariant.getTotal() +
        shp::Quantity(changeSpeed, getDisplacement().getScaling(), getUnit()));
    shp::Direction change = (invariant.getDirection() + Velocity::getAngularShiftRate());
    float acceleration = (velocity.getMagnitude() * cos(change.toRadians()));
    shp::Signal result(acceleration, getDisplacement().getScaling(), getUnit());
    return result;
}

shp::Signal Acceleration::getLinear() {
	const float timeperiod = 1.0f;
	return this->getLinear(timeperiod);
}

shp::Signal Acceleration::getLinear(const Time& slice) {
	Velocity invariant = *this;     // non-accelerating component only
    shp::Signal velocity = (invariant.getLinear(slice) +
        shp::Quantity(changeSpeed, invariant.getDisplacement().getScaling(), invariant.getUnit()));
    shp::Signal result(velocity.getMagnitude(), velocity.getScaling(), UNIT); result.adjustScaling();
    return result;
}

shp::Signal Acceleration::getAngular() {
	return this->getAngular(shp::Direction::DEFAULT_RADIANS);
}

shp::Signal Acceleration::getAngular(const shp::Direction& theta) {
	Velocity invariant = *this;     // non-accelerating component only
	shp::Signal rotation = invariant.getAngular(theta);
    shp::Signal result(rotation.getOrientation(),
        rotation.getMagnitude(), rotation.getScaling(), rotation.getUnit());
    return result;
}

void Acceleration::adjustNumeric() {
    Velocity::adjustNumeric();
}

void Acceleration::adjustScaling() {
    Velocity::adjustScaling();
}

bool Acceleration::checkNonZero() const {
	return Velocity::checkNonZero() && (changeSpeed != shp::Quantity::DEFAULT_VALUE);
}

bool Acceleration::checkInfinity() const {
    return Velocity::checkInfinity();
}

short int Acceleration::checkScaling(const float amount) const {
    return Velocity::checkScaling(amount);
}

shp::Signal Acceleration::getScalarNegative() const {
    return Velocity::getScalarNegative();
}

shp::Signal Acceleration::getVectorNegative() const {
    return Velocity::getVectorNegative();
}

shp::Signal Acceleration::getScalarInverse() const {
    return Velocity::getScalarInverse();
}

shp::Signal Acceleration::getVectorInverse() const {
    return Velocity::getVectorInverse();
}

shp::Signal Acceleration::getScalarSquare() const {
    return Velocity::getScalarSquare();
}

shp::Signal Acceleration::getVectorSquare() const {
    return Velocity::getVectorSquare();
}

shp::Signal Acceleration::getScalarFraction(const float length) const {
    return Velocity::getScalarFraction(length);
}

shp::Signal Acceleration::getScalarFraction(const float length, const short int scale) const {
    return Velocity::getScalarFraction(length, scale);
}

shp::Signal Acceleration::getScalarSquareFraction(const float length) const {
    return Velocity::getScalarSquareFraction(length);
}

shp::Signal Acceleration::getScalarSquareFraction(const float length, const short int scale) const {
    return Velocity::getScalarSquareFraction(length, scale);
}

shp::Distance Acceleration::copy() {
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
    result << Velocity::print() << ",Δ:";
	result << changeSpeed;
    result << unit.print();
	return result.str();
}

std::string Acceleration::printRadians() const {
    std::stringstream result;
    result << "a";
    result << Velocity::printRadians() << ",Δ:";
	result << changeSpeed;
    result << unit.print();
	return result.str();
}

shp::Signal Acceleration::getCosComponent(const float phase) const {
	shp::Signal acceleration = this->getTotal();
	return shp::Signal((acceleration.getCosComponent(phase)),
        acceleration.getScaling(), acceleration.getUnit());
}

shp::Signal Acceleration::getSinComponent(const float phase) const {
	shp::Signal acceleration = this->getTotal();
	return shp::Signal((acceleration.getSinComponent(phase)),
        acceleration.getScaling(), acceleration.getUnit());
}

shp::Direction Acceleration::getAngularVelocity(const Time& interval) const {
	return Velocity::getAngularVelocity(interval);
}

shp::Direction Acceleration::getCurvedSpaceTime(const Time& interval) const {
	return Velocity::getCurvedSpaceTime(interval);
}

} // namespace qft