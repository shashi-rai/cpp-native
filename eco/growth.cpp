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

Growth::Growth(const shp::Azimuth& phase)
        : shp::Potential(phase) {

}

Growth::Growth(const shp::Angular& closure)
        : shp::Potential(closure) {

}

Growth::Growth(const shp::Azimuth& phase, const shp::Angular& closure)
        : shp::Potential(phase, closure) {

}

Growth::Growth(const float high)
        : shp::Potential(high, shp::Quantity::DEFAULT_VALUE) {

}

Growth::Growth(const float high, const shp::Angular& closure)
        : shp::Potential(high, shp::Quantity::DEFAULT_VALUE, closure) {
}

Growth::Growth(const shp::Azimuth& phase, const float high,
        const shp::Angular& closure)
        : shp::Potential(phase, high, closure) {
}

Growth::Growth(const float high, const float low)
        : shp::Potential(high, low) {

}

Growth::Growth(const float high, const float low,
        const shp::Angular& closure)
        : shp::Potential(high, low, closure) {

}

Growth::Growth(const shp::Azimuth& phase, const float high, const float low,
        const shp::Angular& closure)
        : shp::Potential(phase, high, low, closure) {

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

Growth::Growth(const shp::Azimuth& phase, const shp::Unit& unit,
        const shp::Angular& closure)
        : shp::Potential(phase, unit, closure) {
}

Growth::Growth(const short int scaling, const std::string unit)
        : shp::Potential(scaling, unit) {

}

Growth::Growth(const short int scaling, const shp::Unit& unit)
        : shp::Potential(scaling, unit) {

}

Growth::Growth(const short int scaling, const shp::Unit& unit,
        const shp::Angular& closure)
        : shp::Potential(scaling, unit, closure) {

}

Growth::Growth(const shp::Azimuth& phase, const short int scaling,
        const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(phase, scaling, unit, closure) {

}

Growth::Growth(const float high,
        const std::string unit, const shp::Angular& closure)
        : shp::Potential(high, shp::Quantity::DEFAULT_VALUE, unit, closure) {

}

Growth::Growth(const float high,
        const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(high, shp::Quantity::DEFAULT_VALUE, unit, closure) {

}

Growth::Growth(const shp::Azimuth& phase, const float high,
        const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(phase, high, shp::Quantity::DEFAULT_VALUE, unit, closure) {

}

Growth::Growth(const float high, const float low,
        const std::string unit)
        : shp::Potential(high, low, unit) {

}

Growth::Growth(const float high, const float low,
        const std::string unit, const shp::Angular& closure)
        : shp::Potential(high, low, unit, closure) {

}

Growth::Growth(const float high, const float low, const shp::Unit& unit)
        : shp::Potential(high, low, unit) {

}

Growth::Growth(const float high, const float low, const shp::Unit& unit,
        const shp::Angular& closure)
        : shp::Potential(high, low, unit, closure) {

}

Growth::Growth(const shp::Azimuth& phase, const float high, const float low,
        const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(phase, high, low, unit, closure) {

}

Growth::Growth(const float high, const float low,
        const short int scaling)
        : shp::Potential(high, low, scaling) {

}

Growth::Growth(const float high, const float low,
        const short int scaling, const std::string unit)
        : shp::Potential(high, low, scaling, unit) {

}

Growth::Growth(const float high, const float low,
        const short int scaling, const shp::Unit& unit)
        : shp::Potential(high, low, scaling, unit) {

}

Growth::Growth(const shp::Azimuth& phase, const float high, const float low,
        const short int scaling, const shp::Unit& unit)
        : shp::Potential(phase, high, low, scaling, unit) {

}

Growth::Growth(const float high, const float low,
        const short int scaling, const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(high, low, scaling, unit, closure) {

}

Growth::Growth(const shp::Azimuth& phase, const float high, const float low,
        const short int scaling, const shp::Unit& unit, const shp::Angular& closure)
        : shp::Potential(phase, high, low, scaling, unit, closure) {

}

Growth::~Growth() {

}

bool Growth::operator==(const Growth& peer) const {
    return (static_cast<const shp::Potential&>(*this) == static_cast<const shp::Potential&>(peer));
}

bool Growth::operator<(const Growth& peer) const {
    return (static_cast<const shp::Potential&>(*this) < static_cast<const shp::Potential&>(peer));
}

bool Growth::operator>(const Growth& peer) const {
    return (static_cast<const shp::Potential&>(*this) > static_cast<const shp::Potential&>(peer));
}

bool Growth::operator<=(const Growth& peer) const {
    Growth self = *this;
    return (self < peer) || (self == peer);
}

bool Growth::operator>=(const Growth& peer) const {
    Growth self = *this;
    return (self > peer) || (self == peer);
}

Growth Growth::operator+(const Growth& peer) const {
	shp::Potential self = *this;
    shp::Direction phase = (this->getPhase() + peer.getPhase());
    float newhigh = (self.getHigh() + (peer.getHigh() /
        std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() + (peer.getLow() /
        std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Growth(phase.toRadians(), newlow, newhigh, self.getScaling(), self.getUnit());
}

Growth Growth::operator-(const Growth& peer) const {
	shp::Potential self = *this;
    shp::Direction phase = (this->getPhase() - peer.getPhase());
    float newhigh = (self.getHigh() - (peer.getHigh() /
        std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() - (peer.getLow() /
        std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Growth(phase.toRadians(), newlow, newhigh, self.getScaling(), self.getUnit());
}

Growth Growth::operator*(const Growth& peer) const {
	shp::Potential self = *this;
    shp::Direction phase = (this->getPhase() * peer.getPhase());
    float newhigh = (self.getHigh() * peer.getHigh());
    float newlow = (self.getLow() * peer.getLow());
    return Growth(phase.toRadians(), newlow, newhigh,
        (self.getScaling() + peer.getScaling()), self.getUnit());
}

Growth Growth::operator/(const Growth& peer) const {
	shp::Potential self = *this;
    shp::Direction phase = (this->getPhase() / peer.getPhase());
    float newhigh = shp::Quantity::DEFAULT_VALUE, newlow = shp::Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != shp::Quantity::DEFAULT_VALUE) {
		newhigh = (self.getHigh() / peer.getHigh());
	}
	if (peer.getLow() != shp::Quantity::DEFAULT_VALUE) {
		newlow = (self.getLow() / peer.getLow());
	}
    return Growth(phase.toRadians(), newlow, newhigh,
        (self.getScaling() - peer.getScaling()), self.getUnit());
}

Growth Growth::operator%(const Growth& peer) const {
	shp::Potential self = *this;
    shp::Direction phase = (this->getPhase() % peer.getPhase());
    float newhigh = shp::Quantity::DEFAULT_VALUE, newlow = shp::Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != shp::Quantity::DEFAULT_VALUE) {
    	newhigh = fmod(self.getHigh(), (peer.getHigh() /
            std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
	if (peer.getLow() != shp::Quantity::DEFAULT_VALUE) {
		newlow = fmod(self.getLow(), (peer.getLow() /
            std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
    return Growth(phase.toRadians(), newlow, newhigh, self.getScaling(), self.getUnit());
}

shp::Signal Growth::operator()(const Growth& peer,
        const shp::Distance& separation, const shp::Distance& position) const {
    shp::Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Angular closure = self.getOrigin();
    shp::Quantity coefficient = closure(peer.getClosure(), separation, position);
    shp::Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    shp::Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

shp::Signal Growth::operator()(const Growth& peerX, const Growth& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const {
	shp::Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Angular closure = self.getOrigin();
    shp::Quantity coefficient = closure(peerX.getClosure(),  peerY.getClosure(), separationX, separationY);
    shp::Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    shp::Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
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

void Growth::setRange(const float high, const float low) {
	Potential::setHigh(high); Potential::setLow(low);
}

void Growth::setRange(const float high, const float low, const short int scale) {
	Potential::setHigh(high); Potential::setLow(low); Potential::setScaling(scale);
}

short int Growth::getScaling() const {
	return Signal::getScaling();
}

void Growth::setScaling(const short int factor) {
	Signal::setScaling(factor);
}

shp::Unit Growth::getUnit() const {
	return Signal::getUnit();
}

void Growth::setUnit(const shp::Unit& object) {
	Signal::setUnit(object);
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

shp::Signal Growth::getConvergence() const {
	shp::Potential self = *this;
    shp::Signal result((self.getLow() - self.getHigh()), self.getScaling(), self.getUnit());
    return result;
}

shp::Signal Growth::getRelative(const shp::Distance& location) const {
    shp::Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = getClosure().getRelative(location);
    shp::Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    shp::Signal result(distribution.getOrientation(), signal.getMagnitude(),
        (distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

shp::Signal Growth::getRelativeX(const shp::Distance& location) const {
    shp::Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = getClosure().getRelativeX(location);
    shp::Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    shp::Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

shp::Signal Growth::getRelativeY(const shp::Distance& location) const {
    shp::Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = getClosure().getRelativeY(location);
    shp::Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    shp::Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

shp::Signal Growth::getRelativeZ(const shp::Distance& location) const {
    shp::Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = getClosure().getRelativeZ(location);
    shp::Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    shp::Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

shp::Signal Growth::copy() const {
	shp::Potential self = *this;
    Growth fresh(self.getHigh(), self.getLow(), self.getScaling(), self.getUnit());
    return fresh;
}

void Growth::clear() {
    shp::Potential::clear();
    return;
}

std::string Growth::print() const {
    std::stringstream result;
	result << "↑";
    result << shp::Potential::print();
	return result.str();
}

std::string Growth::printRadians() const {
    std::stringstream result;
	result << "↑";
    result << shp::Potential::printRadians();
	return result.str();
}

} // namespace eco