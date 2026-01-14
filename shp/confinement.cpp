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

#include "confinement.h"

namespace shp {

Confinement::Confinement()
        : Potential() {

}

Confinement::Confinement(const Angular& closure)
        : Potential(closure) {

}

Confinement::Confinement(const float high)
        : Potential(high, Quantity::DEFAULT_VALUE) {

}

Confinement::Confinement(const float high, const Angular& closure)
        : Potential(high, Quantity::DEFAULT_VALUE, closure) {
}

Confinement::Confinement(const float high, const float low)
        : Potential(high, low) {

}

Confinement::Confinement(const float high, const float low, const Angular& closure)
        : Potential(high, low, closure) {

}

Confinement::Confinement(const std::string unit)
        : Potential(unit) {

}

Confinement::Confinement(const Unit& unit)
        : Potential(unit) {
}

Confinement::Confinement(const Unit& unit, const Angular& closure)
        : Potential(unit, closure) {
}

Confinement::Confinement(const short int scaling, const std::string unit)
        : Potential(scaling, unit) {

}

Confinement::Confinement(const short int scaling, const Unit& unit)
        : Potential(scaling, unit) {

}

Confinement::Confinement(const short int scaling, const Unit& unit, const Angular& closure)
        : Potential(scaling, unit, closure) {

}

Confinement::Confinement(const float high, const std::string unit, const Angular& closure)
        : Potential(high, Quantity::DEFAULT_VALUE, unit, closure) {

}

Confinement::Confinement(const float high, const float low, const std::string unit)
        : Potential(high, low, unit) {

}

Confinement::Confinement(const float high, const float low, const std::string unit, const Angular& closure)
        : Potential(high, low, unit, closure) {

}

Confinement::Confinement(const float high, const float low, const Unit& unit)
        : Potential(high, low, unit) {

}

Confinement::Confinement(const float high, const float low, const Unit& unit, const Angular& closure)
        : Potential(high, low, unit, closure) {

}

Confinement::Confinement(const float high, const float low, const short int scaling)
        : Potential(high, low, scaling) {

}

Confinement::Confinement(const float high, const float low, const short int scaling, const std::string unit)
        : Potential(high, low, scaling, unit) {

}

Confinement::Confinement(const float high, const float low, const short int scaling, const Unit& unit)
        : Potential(high, low, scaling, unit) {

}

Confinement::Confinement(const float high, const float low, const short int scaling, const Unit& unit,
        const Angular& closure)
        : Potential(high, low, scaling, unit, closure) {

}

Confinement::~Confinement() {

}

bool Confinement::operator==(const Confinement& peer) const {
    return (static_cast<const Potential&>(*this) == static_cast<const Potential&>(peer));
}

Confinement Confinement::operator+(const Confinement& peer) const {
	Potential self = *this;
    float newhigh = (self.getHigh() + (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() + (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Confinement(newlow, newhigh, self.getScaling(), self.getUnit());
}

Confinement Confinement::operator-(const Confinement& peer) const {
	Potential self = *this;
    float newhigh = (self.getHigh() - (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() - (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Confinement(newlow, newhigh, self.getScaling(), self.getUnit());
}

Confinement Confinement::operator*(const Confinement& peer) const {
	Potential self = *this;
    float newhigh = (self.getHigh() * peer.getHigh());
    float newlow = (self.getLow() * peer.getLow());
    return Confinement(newlow, newhigh, (self.getScaling() + peer.getScaling()), self.getUnit());
}

Confinement Confinement::operator/(const Confinement& peer) const {
	Potential self = *this;
    float newhigh = Quantity::DEFAULT_VALUE, newlow = Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != Quantity::DEFAULT_VALUE) {
		newhigh = (self.getHigh() / peer.getHigh());
	}
	if (peer.getLow() != Quantity::DEFAULT_VALUE) {
		newlow = (self.getLow() / peer.getLow());
	}
    return Confinement(newlow, newhigh, (self.getScaling() - peer.getScaling()), self.getUnit());
}

Confinement Confinement::operator%(const Confinement& peer) const {
	Potential self = *this;
    float newhigh = Quantity::DEFAULT_VALUE, newlow = Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != Quantity::DEFAULT_VALUE) {
    	newhigh = fmod(self.getHigh(), (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
	if (peer.getLow() != Quantity::DEFAULT_VALUE) {
		newlow = fmod(self.getLow(), (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
    return Confinement(newlow, newhigh, self.getScaling(), self.getUnit());
}

Quantity Confinement::operator()(const Confinement& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; Quantity distribution = getConvergence().getInverse();
    shp::Angular closure = self.getOrigin();
	Quantity coefficient = (closure(peer.getClosure(), separation, position) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
        (coefficient.getScaling() + distribution.getScaling()), self.getUnit());
    result.adjustScaling();
    return result;
}

Quantity Confinement::operator()(const Confinement& peerX, const Confinement& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Potential self = *this; Quantity distribution = getConvergence().getInverse();
    shp::Angular closure = self.getOrigin();
    Quantity coefficient = (closure(peerX.getClosure(), peerY.getClosure(), separationX, separationY) * distribution.getMagnitude());
    Quantity result(coefficient.getMagnitude(),
        (coefficient.getScaling() + distribution.getScaling()), self.getUnit());
    result.adjustScaling();
    return result;
}

float Confinement::getHigh() const {
    return Potential::getHigh();
}

void Confinement::setHigh(const float value) {
	Potential::setHigh(value); 
}

float Confinement::getLow() const {
	return Potential::getLow();
}

void Confinement::setLow(const float value) {
	Potential::setLow(value);
}

Angular Confinement::getClosure() const {
	return Potential::getOrigin();
}

void Confinement::setClosure(const Angular& position) {
	Potential::setOrigin(position);
}

Polar Confinement::getPolar() const {
	Potential self = *this;
    return self.getOrigin().getPolar();
}

void Confinement::setPolar(const Polar& angle) {
	Potential self = *this;
	Angular origin = self.getOrigin();
	origin.setPolar(angle);
}

Azimuth Confinement::getAzimuth() const {
	Potential self = *this;
    return self.getOrigin().getAzimuth();
}

void Confinement::setAzimuth(const Azimuth& angle) {
	Potential self = *this;
	Angular origin = self.getOrigin();
    origin.setAzimuth(angle);
}

Quantity Confinement::getConvergence() const {
	Potential self = *this;
    Quantity result((self.getLow() - self.getHigh()), self.getScaling(), self.getUnit());
    return result;
}

Quantity Confinement::getRelative(const Distance& location, const float angle) const {
	return Potential::getRelative(location, angle);
}

Quantity Confinement::getPolarComponent(const Distance& location) const {
    Potential self = *this;
	Angular closure = self.getOrigin();
    return self.getRelative(location, closure.getPolar().toRadians());
}

Quantity Confinement::getAzimuthComponent(const Distance& location) const {
    Potential self = *this;
	Angular closure = self.getOrigin();
    return self.getRelative(location, closure.getAzimuth().toRadians());
}

Potential Confinement::copy() const {
	Potential self = *this;
    Confinement fresh(self.getHigh(), self.getLow(), self.getScaling(), self.getUnit());
    return fresh;
}

void Confinement::clear() {
    Potential::clear();
    return;
}

std::string Confinement::print() {
    std::stringstream result;
	result << "⊙";
    result << Potential::print();
	return result.str();
}

} // namespace shp