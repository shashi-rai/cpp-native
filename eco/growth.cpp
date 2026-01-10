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

#include "growth.h"

namespace eco {

Growth::Growth()
        : shp::Potential() {

}

Growth::Growth(const shp::Angular& closure)
        : shp::Potential(closure) {

}

Growth::Growth(const float high)
        : shp::Potential(shp::Quantity::DEFAULT_VALUE, high) {

}

Growth::Growth(const float high, const shp::Angular& closure)
        : shp::Potential(shp::Quantity::DEFAULT_VALUE, high, closure) {
}

Growth::Growth(const float high, const float low)
        : shp::Potential(low, high) {

}

Growth::Growth(const float high, const float low, const shp::Angular& closure)
        : shp::Potential(low, high, closure) {

}

Growth::Growth(const std::string unit)
        : shp::Potential(unit) {

}

Growth::Growth(const shp::Unit& unit)
        : shp::Potential(unit) {
}

Growth::Growth(const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(unit, closure) {
}

Growth::Growth(const short int scaling, const std::string unit)
        : shp::Potential(scaling, unit) {

}

Growth::Growth(const short int scaling, const shp::Unit& unit)
        : shp::Potential(scaling, unit) {

}

Growth::Growth(const short int scaling, const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(scaling, unit, closure) {

}

Growth::Growth(const float high, const std::string unit, const shp::Angular& closure)
        : shp::Potential(shp::Quantity::DEFAULT_VALUE, high, unit, closure) {

}

Growth::Growth(const float high, const float low, const std::string unit)
        : shp::Potential(low, high, unit) {

}

Growth::Growth(const float high, const float low, const std::string unit, const shp::Angular& closure)
        : shp::Potential(low, high, unit, closure) {

}

Growth::Growth(const float high, const float low, const shp::Unit& unit)
        : shp::Potential(low, high, unit) {

}

Growth::Growth(const float high, const float low, const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(low, high, unit, closure) {

}

Growth::Growth(const float high, const float low, const short int scaling)
        : shp::Potential(low, high, scaling) {

}

Growth::Growth(const float high, const float low, const short int scaling, const std::string unit)
        : shp::Potential(low, high, scaling, unit) {

}

Growth::Growth(const float high, const float low, const short int scaling, const shp::Unit& unit)
        : shp::Potential(low, high, scaling, unit) {

}

Growth::Growth(const float high, const float low, const short int scaling, const shp::Unit& unit,
        const shp::Angular& closure)
        : shp::Potential(low, high, scaling, unit, closure) {

}

Growth::~Growth() {

}

bool Growth::operator==(const Growth& peer) const {
    return (static_cast<const shp::Potential&>(*this) == static_cast<const shp::Potential&>(peer));
}

Growth Growth::operator+(const Growth& peer) const {
	shp::Potential self = *this;
    float newhigh = (self.getHigh() + (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() + (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Growth(newlow, newhigh, self.getScaling(), self.getUnit());
}

Growth Growth::operator-(const Growth& peer) const {
	shp::Potential self = *this;
    float newhigh = (self.getHigh() - (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() - (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Growth(newlow, newhigh, self.getScaling(), self.getUnit());
}

Growth Growth::operator*(const Growth& peer) const {
	shp::Potential self = *this;
    float newhigh = (self.getHigh() * peer.getHigh());
    float newlow = (self.getLow() * peer.getLow());
    return Growth(newlow, newhigh, (self.getScaling() + peer.getScaling()), self.getUnit());
}

Growth Growth::operator/(const Growth& peer) const {
	shp::Potential self = *this;
    float newhigh = (self.getHigh() / peer.getHigh());
    float newlow = (self.getLow() / peer.getLow());
    return Growth(newlow, newhigh, (self.getScaling() - peer.getScaling()), self.getUnit());
}

Growth Growth::operator%(const Growth& peer) const {
	shp::Potential self = *this;
    float newhigh = fmod(self.getHigh(), (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = fmod(self.getLow(), (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Growth(newlow, newhigh, self.getScaling(), self.getUnit());
}

shp::Quantity Growth::operator()(const Growth& peer,
        const shp::Distance& separation, const shp::Distance& position) const {
    shp::Potential self = *this; shp::Quantity distribution = getConvergence().getInverse();
    shp::Angular closure = self.getOrigin();
    Quantity coefficient = (closure(peer.getClosure(), separation, position) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
		(coefficient.getScaling() + distribution.getScaling()), self.getUnit());
	result.adjustScaling();
    return result;
}

shp::Quantity Growth::operator()(const Growth& peerX, const Growth& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const {
    shp::Potential self = *this; shp::Quantity distribution = getConvergence().getInverse();
    shp::Angular closure = self.getOrigin();
    Quantity coefficient = (closure(peerX.getClosure(), peerY.getClosure(), separationX, separationY) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
		(coefficient.getScaling() + distribution.getScaling()), self.getUnit());
	result.adjustScaling();
    return result;
}

float Growth::getHigh() const {
    return shp::Potential::getHigh();
}

void Growth::setHigh(const float value) {
	shp::Potential::setHigh(value); 
}

float Growth::getLow() const {
	return shp::Potential::getLow();
}

void Growth::setLow(const float value) {
	shp::Potential::setLow(value);
}

shp::Angular Growth::getClosure() const {
	return shp::Potential::getOrigin();
}

void Growth::setClosure(const shp::Angular& position) {
	shp::Potential::setOrigin(position);
}

shp::Polar Growth::getPolar() const {
	shp::Potential self = *this;
    return self.getOrigin().getPolar();
}

void Growth::setPolar(const shp::Polar& angle) {
	shp::Potential self = *this;
	shp::Angular origin = self.getOrigin();
	origin.setPolar(angle);
}

shp::Azimuth Growth::getAzimuth() const {
	shp::Potential self = *this;
    return self.getOrigin().getAzimuth();
}

void Growth::setAzimuth(const shp::Azimuth& angle) {
	Potential self = *this;
	shp::Angular origin = self.getOrigin();
    origin.setAzimuth(angle);
}

shp::Quantity Growth::getConvergence() const {
	shp::Potential self = *this;
    shp::Quantity result((self.getLow() - self.getHigh()), self.getScaling(), self.getUnit());
    return result;
}

shp::Quantity Growth::getRelative(const shp::Distance& location, const float angle) const {
	return shp::Potential::getRelative(location, angle);
}

shp::Quantity Growth::getPolarComponent(const shp::Distance& location) const {
    shp::Potential self = *this;
	shp::Angular closure = self.getOrigin();
    return self.getRelative(location, closure.getPolar().toRadians());
}

shp::Quantity Growth::getAzimuthComponent(const shp::Distance& location) const {
    shp::Potential self = *this;
	shp::Angular closure = self.getOrigin();
    return self.getRelative(location, closure.getAzimuth().toRadians());
}

shp::Potential Growth::copy() const {
	shp::Potential self = *this;
    Growth fresh(self.getHigh(), self.getLow(), self.getScaling(), self.getUnit());
    return fresh;
}

void Growth::clear() {
    shp::Potential::clear();
    return;
}

std::string Growth::print() {
    std::stringstream result;
	result << "↑";
    result << shp::Potential::print();
	return result.str();
}

} // namespace eco