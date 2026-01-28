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

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
		const std::string unit)
        : shp::Distance(displacement, scaling, unit), name(name) {
	setTemporal(nullptr);
}

Velocity::Velocity(const std::string name, const float displacement, const short int scaling,
		const shp::Unit& unit)
        : shp::Distance(displacement, scaling, unit), name(name) {
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
    shp::Distance self = *this, other = peer, velocity = (self + other);
    return Velocity("+", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator-(const Velocity& peer) const {
    shp::Distance self = *this, other = peer, velocity = (self - other);
    return Velocity("-", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator*(const Velocity& peer) const {
    shp::Distance self = *this, other = peer, velocity = (self * other);
    return Velocity("*", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator/(const Velocity& peer) const {
    shp::Distance self = *this, other = peer, velocity = (self / other);
    return Velocity("/", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator%(const Velocity& peer) const {
    shp::Distance self = *this, other = peer, velocity = (self % other);
    return Velocity("%", velocity.getMagnitude(), velocity.getScaling(), self.getUnit(),
		velocity.getAzimuth(), this->temporal);
}

Velocity Velocity::operator+(const float distance) const {
    Velocity self = *this; shp::Distance displacement = (self + distance);
    return Velocity("+", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator-(const float distance) const {
    Velocity self = *this; shp::Distance displacement = (self - distance);
    return Velocity("-", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator*(const float distance) const {
    Velocity self = *this; shp::Distance displacement = (self * distance);
    return Velocity("*", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator/(const float distance) const {
    Velocity self = *this; shp::Distance displacement = (self / distance);
    return Velocity("/", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator%(const float distance) const {
    Velocity self = *this; shp::Distance displacement = (self % distance);
    return Velocity("%", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator+(const shp::Quantity& distance) const {
    Velocity self = *this; shp::Distance displacement = (self + distance);
    return Velocity("+", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator-(const shp::Quantity& distance) const {
    Velocity self = *this; shp::Distance displacement = (self - distance);
    return Velocity("-", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator*(const shp::Quantity& distance) const {
    Velocity self = *this; shp::Distance displacement = (self * distance);
    return Velocity("*", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator/(const shp::Quantity& distance) const {
    Velocity self = *this; shp::Distance displacement = (self / distance);
    return Velocity("/", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator%(const shp::Quantity& distance) const {
    Velocity self = *this; shp::Distance displacement = (self % distance);
    return Velocity("%", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator+(const shp::Distance& distance) const {
    Velocity self = *this; shp::Distance displacement = (self + distance);
    return Velocity("+", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator-(const shp::Distance& distance) const {
    Velocity self = *this; shp::Distance displacement = (self - distance);
    return Velocity("-", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator*(const shp::Distance& distance) const {
    Velocity self = *this; shp::Distance displacement = (self * distance);
    return Velocity("*", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator/(const shp::Distance& distance) const {
    Velocity self = *this; shp::Distance displacement = (self / distance);
    return Velocity("/", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator%(const shp::Distance& distance) const {
    Velocity self = *this; shp::Distance displacement = (self % distance);
    return Velocity("%", displacement.getMagnitude(), displacement.getScaling(), displacement.getUnit(),
		displacement.getAzimuth(), self.temporal);
}

Velocity Velocity::operator+(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth newAzimuth = (self.getAzimuth() + orientation);
    return Velocity("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newAzimuth, self.temporal);
}

Velocity Velocity::operator-(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth newAzimuth = (self.getAzimuth() - orientation);
    return Velocity("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newAzimuth, self.temporal);
}

Velocity Velocity::operator*(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth newAzimuth = (self.getAzimuth() * orientation);
    return Velocity("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newAzimuth, self.temporal);
}

Velocity Velocity::operator/(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth newAzimuth = (self.getAzimuth() / orientation);
    return Velocity("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newAzimuth, self.temporal);
}

Velocity Velocity::operator%(const shp::Azimuth& orientation) const {
    Velocity self = *this; shp::Azimuth newAzimuth = (self.getAzimuth() % orientation);
    return Velocity("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newAzimuth, self.temporal);
}

Velocity Velocity::operator+(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getModulation() + curvature);
    Velocity result("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getAzimuth(), self.temporal);
	result.setModulation(newCurvature);
	return result;
}

Velocity Velocity::operator-(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getModulation() - curvature);
    Velocity result("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getAzimuth(), self.temporal);
	result.setModulation(newCurvature);
	return result;
}

Velocity Velocity::operator*(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getModulation() * curvature);
    Velocity result("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getAzimuth(), self.temporal);
	result.setModulation(newCurvature);
	return result;
}

Velocity Velocity::operator/(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getModulation() / curvature);
    Velocity result("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getAzimuth(), self.temporal);
	result.setModulation(newCurvature);
	return result;
}

Velocity Velocity::operator%(const shp::Polar& curvature) const {
    Velocity self = *this; shp::Polar newCurvature = (self.getModulation() % curvature);
    Velocity result("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getAzimuth(), self.temporal);
	result.setModulation(newCurvature);
	return result;
}

shp::Distance Velocity::getDisplacement() const {
	shp::Distance result = *this;
	return result;
}

void Velocity::setDisplacement(const shp::Quantity& distance, const shp::Azimuth& direction) {
	shp::Distance::setMagnitude(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
	shp::Distance::setAzimuth(direction);
}

void Velocity::setDisplacement(const shp::Quantity& distance, const shp::Polar& curvature) {
	shp::Distance::setMagnitude(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
	shp::Distance::setModulation(curvature);
}

void Velocity::setDisplacement(const shp::Distance& distance) {
	shp::Distance::setMagnitude(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
	shp::Distance::setAzimuth(distance.getAzimuth());
	shp::Distance::setModulation(distance.getModulation());
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

short int Velocity::getScaling() const {
    return shp::Distance::getScaling();
}

void Velocity::setScaling(const short int factor) {
    shp::Distance::setScaling(factor);
}

shp::Unit Velocity::getUnit() const {
	return shp::Distance::getUnit();
}

void Velocity::setUnit(const shp::Unit& unit) {
	shp::Distance::setUnit(unit);
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

shp::Polar Velocity::getFieldCurvature() const {
	return shp::Distance::getModulation();
}

void Velocity::setFieldCurvature(const shp::Polar& curvature) {
	shp::Distance::setModulation(curvature);
}

void Velocity::setChangeMagnitude(const float motion) {
	shp::Distance::setChangeMagnitude(motion);
}

void Velocity::setChangeMagnitude(const float motion, const short int scale) {
	shp::Distance::setChangeMagnitude(motion, scale);
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

shp::Signal Velocity::getLinear() {
	const float timeperiod = 1.0f;
	return this->getLinear(timeperiod);
}

shp::Signal Velocity::getLinear(const Time& slice) {
	shp::Distance self = *this; shp::Frequency frequency(shp::Quantity::DEFAULT_VALUE);
	float magnitude = shp::Quantity::DEFAULT_VALUE; short int scaling = shp::Quantity::DEFAULT_SCALE;
	if (isTimeBound()) {
		frequency = temporal->getFrequency();
		magnitude = ((self.getAmplitude() * frequency.getMagnitude()) / slice.getMagnitude());
		scaling = (self.getScaling() + frequency.getScaling());
	}
    shp::Signal result(shp::Direction::DEFAULT_RADIANS, magnitude, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Signal Velocity::getAngular() {
	return this->getAngular(shp::Direction::DEFAULT_RADIANS);
}

shp::Signal Velocity::getAngular(const shp::Direction& theta) {
	shp::Distance self = *this; shp::Quantity rotation;
	shp::Azimuth displacement = self.getAzimuth();
	if (isTimeBound()) {
		rotation = temporal->getCurvature();
		displacement.setRotation(rotation.getMagnitude() + theta.toRadians());
	}
	std::string unit = rotation.getUnit().getName() + '/' + shp::Unit::getBaseSymbol(shp::Unit::TIME);
    shp::Signal result(displacement, rotation.getMagnitude(), rotation.getScaling(), unit);
    return result;
}

void Velocity::adjustNumeric() {
    shp::Distance::adjustNumeric();
}

void Velocity::adjustScaling() {
    shp::Distance::adjustScaling();
}

bool Velocity::checkNonZero() const {
	return shp::Distance::checkNonZero();
}

bool Velocity::checkInfinity() const {
    return shp::Distance::checkInfinity();
}

short int Velocity::checkScaling(const float amount) const {
    return shp::Distance::checkScaling(amount);
}

shp::Signal Velocity::getScalarNegative() const {
    return shp::Distance::getScalarNegative();
}

shp::Signal Velocity::getVectorNegative() const {
    return shp::Distance::getVectorNegative();
}

shp::Signal Velocity::getScalarInverse() const {
    return shp::Distance::getScalarInverse();
}

shp::Signal Velocity::getVectorInverse() const {
    return shp::Distance::getVectorInverse();
}

shp::Signal Velocity::getScalarSquare() const {
    return shp::Distance::getScalarSquare();
}

shp::Signal Velocity::getVectorSquare() const {
    return shp::Distance::getVectorSquare();
}

shp::Signal Velocity::getScalarFraction(const float length) const {
    return shp::Distance::getScalarFraction(length);
}

shp::Signal Velocity::getScalarFraction(const float length, const short int scale) const {
    return shp::Distance::getScalarFraction(length, scale);
}

shp::Signal Velocity::getScalarSquareFraction(const float length) const {
    return shp::Distance::getScalarSquareFraction(length);
}

shp::Signal Velocity::getScalarSquareFraction(const float length, const short int scale) const {
    return shp::Distance::getScalarSquareFraction(length, scale);
}

bool Velocity::isTimeBound() const {
    return (temporal != nullptr);
}

shp::Distance Velocity::copy() {
	shp::Distance self = *this;
    Velocity fresh(getName(), self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getAzimuth(), this->temporal);
    return fresh;
}

void Velocity::clear() {
	shp::Distance::clear();
	name.clear();
    return;
}

std::string Velocity::print() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::print();
	result << ")";
	return result.str();
}

std::string Velocity::printTemporal() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::print() << ",";
	result << (isTimeBound() ? temporal->print() : "");
	result << ")";
	return result.str();
}

std::string Velocity::printRadians() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::printRadians();
	result << ")";
	return result.str();
}

std::string Velocity::printTemporalRadians() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::printRadians() << ",";
	result << (isTimeBound() ? temporal->printRadians() : "");
	result << ")";
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

shp::Direction Velocity::getAngularVelocity(const Time& interval) const {
	float rate = (shp::Distance::getAzimuth().toRadians() / interval.getMagnitude());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Velocity::getCurvedSpaceTime(const Time& interval) const {
	float rate = (shp::Distance::getModulation().toRadians() / interval.getMagnitude());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Velocity::getAngularShiftRate() const {
	shp::Direction result(shp::Distance::getAzimuth().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Velocity::getCurvatureShiftRate() const {
	shp::Direction result(shp::Distance::getModulation().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

std::complex<float> Velocity::toComplex(const float coefficient, const float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

} // namespace qft