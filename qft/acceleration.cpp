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
        : qft::Velocity(), change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const Velocity& velocity)
        : qft::Velocity(velocity), change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::shared_ptr<Time> domain)
        : qft::Velocity(domain), change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const shp::Unit& unit)
        : qft::Velocity(unit), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(unit, domain), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const float orientation)
        : qft::Velocity(shp::Azimuth(orientation)),
        change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation)
        : qft::Velocity(orientation), change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const float orientation, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(orientation), domain),
        change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const std::shared_ptr<Time> domain)
        : qft::Velocity(orientation, domain),
        change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const float orientation, const std::string unit)
        : qft::Velocity(unit, shp::Azimuth(orientation)),
        change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const std::string unit)
        : qft::Velocity(unit, orientation), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const float orientation, const std::string unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(unit, shp::Azimuth(orientation), domain),
        change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const std::string unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(unit, orientation, domain), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const float orientation, const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(orientation)),
        change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(orientation)),
        change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const float orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(orientation), domain),
        change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(orientation, domain),
        change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const float orientation, const shp::Signal& change)
        : qft::Velocity(shp::Azimuth(orientation)),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Signal& change)
        : qft::Velocity(orientation),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const float orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(orientation), domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(orientation, domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const float orientation, const shp::Signal& change,
        const std::string unit)
        : qft::Velocity(unit, shp::Azimuth(orientation)),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Signal& change,
        const std::string unit)
        : qft::Velocity(unit, orientation),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const float orientation, const shp::Signal& change,
        const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(unit, shp::Azimuth(orientation), domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Signal& change,
        const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(unit, orientation, domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const float orientation, const shp::Signal& change,
        const shp::Unit& unit)
        : qft::Velocity(shp::Azimuth(orientation)),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Signal& change,
        const shp::Unit& unit)
        : qft::Velocity(orientation),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const float orientation, const shp::Signal& change,
        const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(shp::Azimuth(orientation), domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const shp::Azimuth& orientation, const shp::Signal& change,
        const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(orientation, domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const float change, const Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity), change(change, unit) {

}

Acceleration::Acceleration(const shp::Signal& change, const Velocity& velocity, const std::string unit)
        : qft::Velocity(velocity),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const float change, const Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity), change(change, unit) {

}

Acceleration::Acceleration(const shp::Signal& change, const Velocity& velocity, const shp::Unit& unit)
        : qft::Velocity(velocity),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name)
        : qft::Velocity(name), change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::string name, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, domain), change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::string name, const std::string unit)
        : qft::Velocity(name, unit), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const std::string unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, unit, domain), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Unit& unit)
        : qft::Velocity(name, unit), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Unit& unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, unit, domain), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation)
        : qft::Velocity(name, shp::Azimuth(orientation)),
		change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation)
        : qft::Velocity(name, orientation),
        change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::string name, const float orientation,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(orientation), domain),
		change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, orientation, domain),
        change(shp::Quantity::DEFAULT_VALUE, qft::Velocity::UNIT) {

}

Acceleration::Acceleration(const std::string name, const float orientation, const std::string unit)
        : qft::Velocity(name, shp::Azimuth(orientation)),
		change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation, const std::string unit)
        : qft::Velocity(name, orientation), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation, const std::string unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(orientation), domain),
		change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation, const std::string unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, orientation, domain), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation, const shp::Unit& unit)
        : qft::Velocity(name, shp::Azimuth(orientation)),
		change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Unit& unit)
        : qft::Velocity(name, orientation), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(orientation), domain),
		change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, orientation, domain), change(shp::Quantity::DEFAULT_VALUE, unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation, const shp::Signal& change)
        : qft::Velocity(name, shp::Azimuth(orientation)),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change)
        : qft::Velocity(name, orientation),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const std::string name, const float orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(orientation), domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain)
        : qft::Velocity(name, orientation, domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const std::string name, const float orientation,
        const shp::Signal& change, const std::string unit)
        : qft::Velocity(name, shp::Azimuth(orientation)),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation,
        const shp::Signal& change, const std::string unit)
        : qft::Velocity(name, orientation),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation,
        const shp::Signal& change, const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(orientation), domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation,
        const shp::Signal& change, const std::string unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, orientation, domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation,
        const shp::Signal& change, const shp::Unit& unit)
        : qft::Velocity(name, shp::Azimuth(orientation)),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation,
        const shp::Signal& change, const shp::Unit& unit)
        : qft::Velocity(name, orientation),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const float orientation,
        const shp::Signal& change, const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, shp::Azimuth(orientation), domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const shp::Azimuth& orientation,
        const shp::Signal& change, const shp::Unit& unit, const std::shared_ptr<Time> domain)
        : qft::Velocity(name, orientation, domain),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const shp::Signal& change, const qft::Velocity& velocity)
        : qft::Velocity(velocity),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), change.getUnit()) {

}

Acceleration::Acceleration(const std::string name, const float displacement, const short int scale,
        const std::string unit, const shp::Azimuth& orientation, const std::shared_ptr<Time> domain,
        const shp::Signal& change)
        : qft::Velocity(name, displacement, scale),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::Acceleration(const std::string name, const float displacement, const short int scale,
        const shp::Unit& unit, const shp::Azimuth& orientation, const std::shared_ptr<Time> domain,
        const shp::Signal& change)
        : qft::Velocity(name, displacement, scale),
        change(change.getOrientation(), change.getMagnitude(), change.getScaling(), unit) {

}

Acceleration::~Acceleration() {

}

bool Acceleration::operator==(const Acceleration& peer) const {
    return (static_cast<const Velocity&>(*this) == static_cast<const Velocity&>(peer))
        && (change == peer.change);
}

bool Acceleration::operator<(const Acceleration& peer) const {
	Acceleration self = *this; bool result = false;
    if (static_cast<const qft::Velocity&>(*this) < static_cast<const qft::Velocity&>(peer)) {
		result = true;
	} else if (change < peer.change) {
        result = true;
    }
	return result;
}

bool Acceleration::operator>(const Acceleration& peer) const {
	Acceleration self = *this; bool result = false;
    if (static_cast<const qft::Velocity&>(*this) > static_cast<const qft::Velocity&>(peer)) {
		result = true;
	} else if (change > peer.change) {
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
    return Acceleration((change + peer.change), newVelocity, UNIT);
}

Acceleration Acceleration::operator-(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self - other);
    return Acceleration((change - peer.change), newVelocity, UNIT);
}

Acceleration Acceleration::operator*(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self * other);
    return Acceleration((change * peer.change), newVelocity, UNIT);
}

Acceleration Acceleration::operator/(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self / other);
    return Acceleration((change / peer.change), newVelocity, UNIT);
}

Acceleration Acceleration::operator%(const Acceleration& peer) const {
    Velocity self = *this, other = peer;
    Velocity newVelocity = (self % other);
    return Acceleration((change % peer.change), newVelocity, UNIT);
}

Acceleration Acceleration::operator+(const float distance) const {
    Velocity self = *this, newVelocity = (self + distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator-(const float distance) const {
    Velocity self = *this, newVelocity = (self - distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator*(const float distance) const {
    Velocity self = *this, newVelocity = (self * distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator/(const float distance) const {
    Velocity self = *this, newVelocity = (self / distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator%(const float distance) const {
    Velocity self = *this, newVelocity = (self % distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator+(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self + distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator-(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self - distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator*(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self * distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator/(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self / distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator%(const shp::Quantity& distance) const {
    Velocity self = *this, newVelocity = (self % distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator+(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self + distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator-(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self - distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator*(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self * distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator/(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self / distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator%(const shp::Distance& distance) const {
    Velocity self = *this, newVelocity = (self % distance);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator+(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self + velocity);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator-(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self - velocity);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator*(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self * velocity);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator/(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self / velocity);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator%(const Velocity& velocity) const {
    Velocity self = *this, newVelocity = (self % velocity);
    return Acceleration(this->change, newVelocity, UNIT);
}

Acceleration Acceleration::operator+(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() + orientation);
    return Acceleration("+", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->change);
}

Acceleration Acceleration::operator-(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() - orientation);
    return Acceleration("-", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->change);
}

Acceleration Acceleration::operator*(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() * orientation);
    return Acceleration("*", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->change);
}

Acceleration Acceleration::operator/(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() / orientation);
    return Acceleration("/", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->change);
}

Acceleration Acceleration::operator%(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth azimuth = (self.getDirection() % orientation);
    return Acceleration("%", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		azimuth, self.getTemporal(), this->change);
}

Acceleration Acceleration::operator+(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() + curvature);
    Acceleration result("+", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->change);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator-(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() - curvature);
    Acceleration result("-", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->change);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator*(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() * curvature);
    Acceleration result("*", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->change);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator/(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() / curvature);
    Acceleration result("/", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->change);
    result.setFieldCurvature(newCurvature);
    return result;
}

Acceleration Acceleration::operator%(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getFieldCurvature() % curvature);
    Acceleration result("%", self.getDisplacement().getMagnitude(), self.getScaling(), self.getUnit(),
		self.getDirection(), self.getTemporal(), this->change);
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

void Acceleration::setDisplacement(const float distance, const short int scale,
        const shp::Azimuth& direction) {
	Velocity::setMagnitude(distance, scale);
    Velocity::setDirection(direction);
}

void Acceleration::setDisplacement(const float distance, const short int scale,
        const shp::Polar& curvature) {
	Velocity::setMagnitude(distance, scale);
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setDisplacement(const float distance, const short int scale,
        const shp::Azimuth& direction, const shp::Polar& curvature) {
	Velocity::setMagnitude(distance, scale);
    Velocity::setDirection(direction);
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const std::string unit) {
	Velocity::setMagnitude(distance, scale, unit);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const std::string unit,
        const shp::Azimuth& direction) {
	Velocity::setMagnitude(distance, scale, unit);
    Velocity::setDirection(direction);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const std::string unit,
        const shp::Polar& curvature) {
	Velocity::setMagnitude(distance, scale, unit);
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const std::string unit,
        const shp::Azimuth& direction, const shp::Polar& curvature) {
	Velocity::setMagnitude(distance, scale, unit);
    Velocity::setDirection(direction);
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const shp::Unit& unit) {
	Velocity::setMagnitude(distance, scale, unit);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& direction) {
	Velocity::setMagnitude(distance, scale, unit);
    Velocity::setDirection(direction);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const shp::Unit& unit,
        const shp::Polar& curvature) {
	Velocity::setMagnitude(distance, scale, unit);
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setDisplacement(const float distance, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& direction, const shp::Polar& curvature) {
	Velocity::setMagnitude(distance, scale, unit);
    Velocity::setDirection(direction);
    Velocity::setFieldCurvature(curvature);
}

short int Acceleration::getScaling() const {
    return Velocity::getScaling();
}

void Acceleration::setScaling(const short int factor) {
    Velocity::setScaling(factor);
}

shp::Azimuth Acceleration::getDirection() const {
	return Velocity::getDirection();
}

void Acceleration::setDirection(const float direction) {
    Velocity::setDirection(direction);
}

void Acceleration::setDirection(const shp::Azimuth& direction) {
    Velocity::setDirection(direction);
}

void Acceleration::setChangeDirection(const float degree) {
	Velocity::setChangeDirection(degree);
}

shp::Polar Acceleration::getFieldCurvature() const {
	return Velocity::getFieldCurvature();
}

void Acceleration::setFieldCurvature(const float curvature) {
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setFieldCurvature(const shp::Polar& curvature) {
    Velocity::setFieldCurvature(curvature);
}

void Acceleration::setChangeFieldCurvature(const float degree) {
	Velocity::setChangeFieldCurvature(degree);
}

shp::Unit Acceleration::getUnit() const {
    return change.getUnit();
}

void Acceleration::setUnit(const shp::Unit& unit) {
    this->change.setUnit(unit);
}

void Acceleration::applyChangeTogether() {
    this->applyChangeDirection();
	this->applyChangeSpeed();
}

void Acceleration::applyChangeDirection() {
    Velocity::setChangeDirection(change.getOrientation());
}

void Acceleration::applyChangeSpeed() {
    Velocity::setChangeMagnitude(change.getMagnitude(), change.getScaling());
}

float Acceleration::getChangeSpeed() const {
    return change.getMagnitude();
}

void Acceleration::setChangeSpeed(const shp::Signal& modulation) {
    this->change = modulation;
}

void Acceleration::setChangeSpeed(const float motion) {
    this->change.setMagnitude(motion, Velocity::getScaling());
}

void Acceleration::setChangeSpeed(const float motion, const short int scale) {
	this->change.setMagnitude(motion, scale);
}

void Acceleration::setChangeDivergence(const float degree) {
    if (degree != shp::Quantity::DEFAULT_VALUE) {
        float direction = (this->change.getOrientation() + (shp::Direction::DEGREE_001 * degree));
        this->change.setOrientation(direction);
    }
}

shp::Signal Acceleration::getTotal() const {
	Velocity invariant = *this;     // non-accelerating component only
    shp::Signal velocity = invariant.getTotal().getDotProduct(change);
    shp::Signal result(velocity.getOrientation(),
        velocity.getMagnitude(), velocity.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Acceleration::getLinear() {
	const float timeperiod = 1.0f;
	return this->getLinear(timeperiod);
}

shp::Signal Acceleration::getLinear(const Time& slice) {
	Velocity invariant = *this;     // non-accelerating component only
    shp::Signal velocity = invariant.getLinear(slice).getDotProduct(change);
    shp::Signal result(shp::Direction::DEFAULT_RADIANS,
        velocity.getMagnitude(), velocity.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Acceleration::getAngular() {
	return this->getAngular(shp::Direction::DEFAULT_RADIANS);
}

shp::Signal Acceleration::getAngular(const shp::Direction& theta) {
	Velocity invariant = *this;     // non-accelerating component only
	shp::Signal rotation = invariant.getAngular(theta).getCrossProduct(change);
    shp::Signal result(rotation.getOrientation(),
        rotation.getMagnitude(), rotation.getScaling(), rotation.getUnit());
    result.adjustScaling();
    return result;
}

void Acceleration::adjustNumeric() {
    Velocity::adjustNumeric();
}

void Acceleration::adjustScaling() {
    Velocity::adjustScaling();
}

bool Acceleration::checkNonZero() const {
	return Velocity::checkNonZero() && (change.getMagnitude() != shp::Quantity::DEFAULT_VALUE);
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
    Velocity velocity = *this;
    Acceleration fresh(this->change, velocity, UNIT);
    return fresh;
}

void Acceleration::clear() {
    Velocity::clear();
    change.clear();
    return;
}

std::string Acceleration::print() const {
    std::stringstream result;
    result << "a";
    result << Velocity::print() << ",Δ:";
	result << change.print();
	return result.str();
}

std::string Acceleration::printRadians() const {
    std::stringstream result;
    result << "a";
    result << Velocity::printRadians() << ",Δ:";
	result << change.printRadians();
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