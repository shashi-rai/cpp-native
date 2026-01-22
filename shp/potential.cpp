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
// THE SOFTWARE.const float high, const float low, const std::string unit, const Angular& origin

#include "potential.h"

namespace shp {

Potential::Potential()
        : Signal(), low(), origin() {

}

Potential::Potential(const Azimuth& phase)
        : Signal(phase), low(), origin() {

}

Potential::Potential(const Angular& origin)
        : Signal(), low(), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const Angular& origin)
        : Signal(phase), low(), origin(origin) {

}

Potential::Potential(const float high)
        : Signal(high), low(), origin() {

}

Potential::Potential(const float high, const Angular& origin)
        : Signal(high), low(), origin(origin) {
}

Potential::Potential(const Azimuth& phase, const float high, const Angular& origin)
        : Signal(phase, high), low(), origin(origin) {
}

Potential::Potential(const float high, const float low)
        : Signal(high), low(low), origin() {

}

Potential::Potential(const float high, const float low,
		const Angular& origin)
        : Signal(high), low(low), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const float high, const float low,
		const Angular& origin)
        : Signal(phase, high), low(low), origin(origin) {

}

Potential::Potential(const std::string unit)
        : Signal(unit), low(), origin() {

}

Potential::Potential(const Unit& unit)
        : Signal(unit), low(), origin() {
}

Potential::Potential(const Unit& unit, const Angular& origin)
        : Signal(unit), low(), origin(origin) {
}

Potential::Potential(const Azimuth& phase, const Unit& unit, const Angular& origin)
        : Signal(phase, unit), low(), origin(origin) {
}

Potential::Potential(const short int scaling, const std::string unit)
        : Signal(scaling, unit), low(), origin() {

}

Potential::Potential(const short int scaling, const Unit& unit)
        : Signal(scaling, unit), low(), origin() {

}

Potential::Potential(const short int scaling,
		const Unit& unit, const Angular& origin)
        : Signal(scaling, unit), low(), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const short int scaling,
		const Unit& unit, const Angular& origin)
        : Signal(phase, scaling, unit), low(), origin(origin) {

}

Potential::Potential(const float high,
		const std::string unit, const Angular& origin)
        : Signal(high, unit), low(), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const float high,
		const std::string unit, const Angular& origin)
        : Signal(phase, high, unit), low(), origin(origin) {

}

Potential::Potential(const float high, const float low,
		const std::string unit)
        : Signal(high, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low,
		const std::string unit, const Angular& origin)
        : Signal(high, unit), low(low), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const float high, const float low,
		const std::string unit, const Angular& origin)
        : Signal(phase, high, unit), low(low), origin(origin) {

}

Potential::Potential(const float high, const float low,
		const Unit& unit)
        : Signal(high, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low,
		const Unit& unit, const Angular& origin)
        : Signal(high, unit), low(low), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const float high, const float low,
		const Unit& unit, const Angular& origin)
        : Signal(phase, high, unit), low(low), origin(origin) {

}

Potential::Potential(const float high, const float low,
		const short int scaling)
        : Signal(high, scaling), low(low), origin() {

}

Potential::Potential(const float high, const float low,
		const short int scaling, const std::string unit)
        : Signal(high, scaling, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low,
		const short int scaling, const Unit& unit)
        : Signal(high, scaling, unit), low(low), origin() {

}

Potential::Potential(const float phase, const float high, const float low,
		const short int scaling, const Unit& unit)
        : Signal(phase, high, scaling, unit), low(low), origin() {

}

Potential::Potential(const Azimuth& phase, const float high, const float low,
		const short int scaling, const Unit& unit)
        : Signal(phase, high, scaling, unit), low(low), origin() {

}

Potential::Potential(const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin)
        : Signal(high, scaling, unit), low(low), origin(origin) {

}

Potential::Potential(const float phase, const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin)
        : Signal(phase, high, scaling, unit), low(low), origin(origin) {

}

Potential::Potential(const Azimuth& phase, const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin)
        : Signal(phase, high, scaling, unit), low(low), origin(origin) {

}

Potential::~Potential() {

}

bool Potential::operator==(const Potential& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer))
        && (low == peer.low) && (origin == peer.origin);
}

bool Potential::operator<(const Potential& peer) const {
    return (static_cast<const Signal&>(*this) < static_cast<const Signal&>(peer))
        && (low < peer.low) && (origin < peer.origin);
}

bool Potential::operator>(const Potential& peer) const {
    return (static_cast<const Signal&>(*this) > static_cast<const Signal&>(peer))
        && (low > peer.low) && (origin > peer.origin);
}

bool Potential::operator<=(const Potential& peer) const {
    Potential self = *this;
    return (self < peer) || (self == peer);
}

bool Potential::operator>=(const Potential& peer) const {
    Potential self = *this;
    return (self > peer) || (self == peer);
}

Potential Potential::operator+(const Potential& peer) const {
	Potential self = *this;
	Direction phase = (self.getPhase() + peer.getPhase());
    float newhigh = (self.getHigh() + (peer.getHigh() /
		std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() + (peer.getLow() /
		std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Potential(phase.toRadians(), newhigh, newlow,
		self.getScaling(), self.getUnit());
}

Potential Potential::operator-(const Potential& peer) const {
	Potential self = *this;
	Direction phase = (self.getPhase() - peer.getPhase());
    float newhigh = (self.getHigh() - (peer.getHigh() /
		std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    float newlow = (self.getLow() - (peer.getLow() /
		std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
    return Potential(phase.toRadians(), newhigh, newlow,
		self.getScaling(), self.getUnit());
}

Potential Potential::operator*(const Potential& peer) const {
	Potential self = *this;
	Direction phase = (self.getPhase() * peer.getPhase());
    float newhigh = (self.getHigh() * peer.getHigh());
    float newlow = (self.getLow() * peer.getLow());
    return Potential(phase.toRadians(), newhigh, newlow,
		(self.getScaling() + peer.getScaling()), self.getUnit());
}

Potential Potential::operator/(const Potential& peer) const {
	Potential self = *this;
	Direction phase = (self.getPhase() / peer.getPhase());
	float newhigh = shp::Quantity::DEFAULT_VALUE, newlow = shp::Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != shp::Quantity::DEFAULT_VALUE) {
		newhigh = (self.getHigh() / peer.getHigh());
	}
	if (peer.getLow() != shp::Quantity::DEFAULT_VALUE) {
		newlow = (self.getLow() / peer.getLow());
	}
    return Potential(phase.toRadians(), newhigh, newlow,
		(self.getScaling() - peer.getScaling()), self.getUnit());
}

Potential Potential::operator%(const Potential& peer) const {
	Potential self = *this;
	Direction phase = (self.getPhase() % peer.getPhase());
	float newhigh = shp::Quantity::DEFAULT_VALUE, newlow = shp::Quantity::DEFAULT_VALUE;
	if (peer.getHigh() != shp::Quantity::DEFAULT_VALUE) {
    	newhigh = fmod(self.getHigh(), (peer.getHigh() /
			std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
	if (peer.getLow() != shp::Quantity::DEFAULT_VALUE) {
		newlow = fmod(self.getLow(), (peer.getLow() /
			std::pow(shp::Quantity::DECIMAL_SCALE, (self.getScaling() - peer.getScaling()))));
	}
    return Potential(phase.toRadians(), newhigh, newlow, self.getScaling(), self.getUnit());
}

Signal Potential::operator()(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin(peer.origin, separation, position);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::operator()(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getSquareAmplified(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getLinearDisplacement(peer.origin, separation, position);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this;
    shp::Signal distribution = self.getLinearPotential(peer, separation, position);
    shp::Quantity coefficient = peer.origin.getAzimuthDisplacement(self.origin, separation, position);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this;
    shp::Signal distribution = self.getLinearPotential(peer, separation, position);
    shp::Quantity coefficient = peer.origin.getPolarDisplacement(self.origin, separation, position);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getLinearDisplacement(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getAzimuthDisplacement(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getPolarDisplacement(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

float Potential::getHigh() const {
	return this->getMagnitude();
}

void Potential::setHigh(const float value) {
	this->setMagnitude(value);
}

void Potential::setRange(const float high, const float low) {
	this->setHigh(high); this->setLow(low);
}

void Potential::setRange(const float high, const float low, const short int scale) {
	this->setHigh(high); this->setLow(low); this->setScaling(scale);
}

short int Potential::getScaling() const {
	return Signal::getScaling();
}

void Potential::setScaling(const short int factor) {
	Signal::setScaling(factor);
}

Unit Potential::getUnit() const {
	return Signal::getUnit();
}

void Potential::setUnit(const Unit& object) {
	Signal::setUnit(object);
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

Signal Potential::getDifference() const {
    return Potential::getDivergence();
}

Signal Potential::getDivergence() const {
	Potential self = *this;
    Signal result(self.getOrientation(), (self.getHigh() - self.getLow()),
		self.getScaling(), self.getUnit());
    return result;
}

Signal Potential::getRelative(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getRelative(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
        (distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getRelativeX(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getLinearX(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getRelativeY(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getLinearY(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getRelativeZ(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    shp::Quantity coefficient = self.origin.getLinearZ(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::copy() const {
	Potential self = *this;
    Potential fresh(self.getOrientation(), self.getHigh(), self.getLow(),
		self.getScaling(), self.getUnit());
    return fresh;
}

void Potential::clear() {
    Signal::clear();
    origin.clear();
    low = shp::Quantity::DEFAULT_VALUE;
    return;
}

std::string Potential::print() const {
    std::stringstream result;
    result << "‖";
    result << getHigh() << "~";
    result << getLow() << "ₑ";
    result << getScaling();
    result << getUnit().print() << ",";
    result << origin.print();
	return result.str();
}

std::string Potential::printRadians() const {
    std::stringstream result;
    result << "‖";
    result << getHigh() << "~";
    result << getLow() << "ₑ";
    result << getScaling();
    result << getUnit().print() << ",";
    result << origin.printRadians();
	return result.str();
}

} // namespace shp