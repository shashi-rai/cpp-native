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

#include "potential.h"

namespace shp {

Potential::Potential()
        : Quantity(), low(), origin() {

}

Potential::Potential(const Angular& origin)
        : Quantity(), low(), origin(origin) {

}

Potential::Potential(const float high)
        : Quantity(high), low(), origin() {

}

Potential::Potential(const float high, const Angular& origin)
        : Quantity(high), low(), origin(origin) {
}

Potential::Potential(const float high, const float low)
        : Quantity(high), low(low), origin() {

}

Potential::Potential(const float high, const float low, const Angular& origin)
        : Quantity(high), low(low), origin(origin) {

}

Potential::Potential(const std::string unit)
        : Quantity(unit), low(), origin() {

}

Potential::Potential(const Unit& unit)
        : Quantity(unit), low(), origin() {
}

Potential::Potential(const Unit& unit, const Angular& origin)
        : Quantity(unit), low(), origin(origin) {
}

Potential::Potential(const short int scaling, const std::string unit)
        : Quantity(scaling, unit), low(), origin() {

}

Potential::Potential(const short int scaling, const Unit& unit)
        : Quantity(scaling, unit), low(), origin() {

}

Potential::Potential(const short int scaling, const Unit& unit, const Angular& origin)
        : Quantity(scaling, unit), low(), origin(origin) {

}

Potential::Potential(const float high, const std::string unit, const Angular& origin)
        : Quantity(high, unit), low(), origin(origin) {

}

Potential::Potential(const float high, const float low, const std::string unit)
        : Quantity(high, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low, const std::string unit, const Angular& origin)
        : Quantity(high, unit), low(low), origin(origin) {

}

Potential::Potential(const float high, const float low, const Unit& unit)
        : Quantity(high, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low, const Unit& unit, const Angular& origin)
        : Quantity(high, unit), low(low), origin(origin) {

}

Potential::Potential(const float high, const float low, const short int scaling)
        : Quantity(high, scaling), low(low), origin() {

}

Potential::Potential(const float high, const float low, const short int scaling, const std::string unit)
        : Quantity(high, scaling, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low, const short int scaling, const Unit& unit)
        : Quantity(high, scaling, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low, const short int scaling, const Unit& unit,
        const Angular& origin)
        : Quantity(high, scaling, unit), low(low), origin(origin) {

}

Potential::~Potential() {

}

bool Potential::operator==(const Potential& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (low == peer.low) && (origin == peer.origin);
}

Potential Potential::operator+(const Potential& peer) const {
	Potential self = *this;
    float newhigh = (self.getHigh() + (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() + (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Potential(newhigh, newlow, self.getScaling(), self.getUnit());
}

Potential Potential::operator-(const Potential& peer) const {
	Potential self = *this;
    float newhigh = (self.getHigh() - (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() - (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Potential(newhigh, newlow, self.getScaling(), self.getUnit());
}

Potential Potential::operator*(const Potential& peer) const {
	Potential self = *this;
    float newhigh = (self.getHigh() * peer.getHigh());
    float newlow = (self.getLow() * peer.getLow());
    return Potential(newhigh, newlow, (self.getScaling() + peer.getScaling()), self.getUnit());
}

Potential Potential::operator/(const Potential& peer) const {
	Potential self = *this;
	float newhigh = Quantity::DEFAULT_VALUE, newlow = Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != Quantity::DEFAULT_VALUE) {
		newhigh = (self.getHigh() / peer.getHigh());
	}
	if (peer.getLow() != Quantity::DEFAULT_VALUE) {
		newlow = (self.getLow() / peer.getLow());
	}
    return Potential(newhigh, newlow, (self.getScaling() - peer.getScaling()), self.getUnit());
}

Potential Potential::operator%(const Potential& peer) const {
	Potential self = *this;
	float newhigh = Quantity::DEFAULT_VALUE, newlow = Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != Quantity::DEFAULT_VALUE) {
    	newhigh = fmod(self.getHigh(), (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
	if (peer.getLow() != Quantity::DEFAULT_VALUE) {
		newlow = fmod(self.getLow(), (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
    return Potential(newhigh, newlow, self.getScaling(), self.getUnit());
}

Quantity Potential::operator()(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; Quantity distribution = self.getDivergence();
    Quantity coefficient = (self.origin(peer.origin, separation, position) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
		(coefficient.getScaling() + distribution.getScaling()), self.getUnit());
	result.adjustScaling();
    return result;
}

Quantity Potential::operator()(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; Quantity distribution = self.getDivergence();
    Quantity coefficient = (self.origin(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
		(coefficient.getScaling() + distribution.getScaling()), self.getUnit());
	result.adjustScaling();
    return result;
}

short int Potential::getScaling() const {
	return Quantity::getScaling();
}

void Potential::setScaling(const short int factor) {
	Quantity::setScaling(factor);
}

Unit Potential::getUnit() const {
	return Quantity::getUnit();
}

void Potential::setUnit(const Unit& object) {
	Quantity::setUnit(object);
}

Polar Potential::getPolar() const {
    return origin.getPolar();
}

void Potential::setPolar(const Polar& angle) {
    this->origin.setPolar(angle);
}

Azimuth Potential::getAzimuth() const {
    return origin.getAzimuth();
}

void Potential::setAzimuth(const Azimuth& angle) {
    this->origin.setAzimuth(angle);
}

Quantity Potential::getDifference() const {
	Potential self = *this;
    Quantity result((self.getHigh() - self.getLow()), self.getScaling(), self.getUnit());
    return result;
}

Quantity Potential::getDivergence() const {
    return Potential::getDifference();
}

Quantity Potential::getRelative(const Distance& location, const float angle) const {
    Potential self = *this; Quantity distribution = self.getDivergence();
    Quantity coefficient = (origin.getRelative(location, angle) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
		(coefficient.getScaling() + distribution.getScaling()), self.getUnit());
	result.adjustScaling();
    return result;
}

Quantity Potential::getPolarComponent(const Distance& location) const {
    Potential self = *this;
    return getRelative(location, self.origin.getPolar().toRadians());
}

Quantity Potential::getAzimuthComponent(const Distance& location) const {
	Potential self = *this;
    return getRelative(location, self.origin.getAzimuth().toRadians());
}

Potential Potential::copy() const {
	Potential self = *this;
    Potential fresh(self.getHigh(), self.getLow(), self.getScaling(), self.getUnit());
    return fresh;
}

void Potential::clear() {
    Quantity::clear();
    origin.clear();
    low = Quantity::DEFAULT_VALUE;
    return;
}

std::string Potential::print() {
    std::stringstream result;
    result << origin.print() << ",‖";
    result << getHigh() << "~";
    result << getLow() << "ₑ";
    result << getScaling();
    result << getUnit().print();
	return result.str();
}

} // namespace shp