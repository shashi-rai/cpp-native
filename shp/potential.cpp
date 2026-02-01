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
        : Signal(), kinetic(), origin() {

}

Potential::Potential(const Angular& origin)
        : Signal(), kinetic(), origin(origin) {

}

Potential::Potential(const Polar& polar)
        : Signal(), kinetic(), origin(polar) {

}

Potential::Potential(const Polar& polar, const Azimuth& azimuth)
        : Signal(), kinetic(), origin(polar, azimuth) {

}

Potential::Potential(const Distance& radius)
        : Signal(), kinetic(), origin(radius) {

}

Potential::Potential(const Distance& radius, const Polar& polar)
        : Signal(), kinetic(), origin(radius, polar) {

}

Potential::Potential(const Distance& radius, const Azimuth& azimuth)
        : Signal(), kinetic(), origin(radius, azimuth) {

}

Potential::Potential(const Distance& radius, const Polar& polar, const Azimuth& azimuth)
        : Signal(), kinetic(), origin(radius, polar, azimuth) {

}

Potential::Potential(const Azimuth& potential)
        : Signal(potential), kinetic(), origin() {

}

Potential::Potential(const Azimuth& potential, const Angular& origin)
        : Signal(potential), kinetic(), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const Azimuth& kinetic)
        : Signal(potential), kinetic(kinetic), origin() {

}

Potential::Potential(const Azimuth& potential, const Angular& origin, const Azimuth& kinetic)
        : Signal(potential), kinetic(kinetic), origin(origin) {

}

Potential::Potential(const float high)
        : Signal(high), kinetic(), origin() {

}

Potential::Potential(const float high, const Angular& origin)
        : Signal(high), kinetic(), origin(origin) {

}

Potential::Potential(const float high, const Angular& origin, const Azimuth& kinetic)
        : Signal(high), kinetic(kinetic), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const Angular& origin)
        : Signal(potential, high), kinetic(), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const Angular& origin,
        const Azimuth& kinetic)
        : Signal(potential, high), kinetic(kinetic), origin(origin) {

}

Potential::Potential(const float high, const float low)
        : Signal(high), kinetic(low), origin() {

}

Potential::Potential(const float high, const float low, const Angular& origin)
        : Signal(high), kinetic(low), origin(origin) {

}

Potential::Potential(const float high, const float low, const Angular& origin,
        const Azimuth& kinetic)
        : Signal(high), kinetic(kinetic, low), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const Angular& origin)
        : Signal(potential, high), kinetic(low), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, high), kinetic(kinetic, low), origin(origin) {

}

Potential::Potential(const std::string unit)
        : Signal(unit), kinetic(unit), origin() {

}

Potential::Potential(const Unit& unit)
        : Signal(unit), kinetic(unit), origin() {
}

Potential::Potential(const Unit& unit, const Angular& origin)
        : Signal(unit), kinetic(unit), origin(origin) {
}

Potential::Potential(const Azimuth& potential, const Unit& unit, const Angular& origin)
        : Signal(potential, unit), kinetic(unit), origin(origin) {
}

Potential::Potential(const Azimuth& potential, const Unit& unit, const Angular& origin,
        const Azimuth& kinetic)
        : Signal(potential, unit), kinetic(kinetic, unit), origin(origin) {
}

Potential::Potential(const short int scaling, const std::string unit)
        : Signal(scaling, unit), kinetic(scaling, unit), origin() {

}

Potential::Potential(const short int scaling, const Unit& unit)
        : Signal(scaling, unit), kinetic(scaling, unit), origin() {

}

Potential::Potential(const short int scaling, const Unit& unit, const Angular& origin)
        : Signal(scaling, unit), kinetic(scaling, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const short int scaling,
        const Unit& unit, const Angular& origin)
        : Signal(potential, scaling, unit), kinetic(), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const short int scaling,
		const Unit& unit, const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, scaling, unit), kinetic(kinetic, scaling, unit), origin(origin) {

}

Potential::Potential(const float high, const std::string unit, const Angular& origin)
        : Signal(high, unit), kinetic(unit), origin(origin) {

}

Potential::Potential(const float high, const std::string unit, const Angular& origin,
        const Azimuth& kinetic)
        : Signal(high, unit), kinetic(kinetic, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const std::string unit,
        const Angular& origin)
        : Signal(potential, high, unit), kinetic(unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const std::string unit,
        const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, high, unit), kinetic(kinetic, unit), origin(origin) {

}

Potential::Potential(const float high, const float low, const std::string unit)
        : Signal(high, unit), kinetic(low, unit), origin() {

}

Potential::Potential(const float high, const float low, const std::string unit,
        const Angular& origin)
        : Signal(high, unit), kinetic(low, unit), origin(origin) {

}

Potential::Potential(const float high, const float low, const std::string unit,
        const Angular& origin, const Azimuth& kinetic)
        : Signal(high, unit), kinetic(kinetic, low, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const std::string unit, const Angular& origin)
        : Signal(potential, high, unit), kinetic(low, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const std::string unit, const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, high, unit), kinetic(kinetic, low, unit), origin(origin) {

}

Potential::Potential(const float high, const float low, const Unit& unit)
        : Signal(high, unit), kinetic(low, unit), origin() {

}

Potential::Potential(const float high, const float low, const Unit& unit,
        const Angular& origin)
        : Signal(high, unit), kinetic(low, unit), origin(origin) {

}

Potential::Potential(const float high, const float low, const Unit& unit,
        const Angular& origin, const Azimuth& kinetic)
        : Signal(high, unit), kinetic(kinetic, low, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const Unit& unit, const Angular& origin)
        : Signal(potential, high, unit), kinetic(low, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const Unit& unit, const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, high, unit), kinetic(kinetic, low, unit), origin(origin) {

}

Potential::Potential(const float high, const float low, const short int scaling)
        : Signal(high, scaling), kinetic(low, scaling), origin() {

}

Potential::Potential(const float high, const float low, const short int scaling,
        const std::string unit)
        : Signal(high, scaling, unit), kinetic(low, scaling, unit), origin() {

}

Potential::Potential(const float high, const float low, const short int scaling,
        const Unit& unit)
        : Signal(high, scaling, unit), kinetic(low, scaling, unit), origin() {

}

Potential::Potential(const float potential, const float high, const float low,
		const short int scaling, const Unit& unit)
        : Signal(potential, high, scaling, unit), kinetic(low, scaling, unit), origin() {

}

Potential::Potential(const float potential, const float high, const float low,
		const short int scaling, const Unit& unit, const float kinetic)
        : Signal(potential, high, scaling, unit), kinetic(kinetic, low, scaling, unit), origin() {

}

Potential::Potential(const float potential, const float high, const float low,
		const short int scaling, const Unit& unit, const Azimuth& kinetic)
        : Signal(potential, high, scaling, unit), kinetic(kinetic, low, scaling, unit), origin() {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const short int scaling, const Unit& unit)
        : Signal(potential, high, scaling, unit), kinetic(low, scaling, unit), origin() {

}

Potential::Potential(const float high, const float low, const short int scaling,
        const Unit& unit, const Angular& origin)
        : Signal(high, scaling, unit), kinetic(low, scaling, unit), origin(origin) {

}

Potential::Potential(const float high, const float low, const short int scaling,
        const Unit& unit, const Angular& origin, const Azimuth& kinetic)
        : Signal(high, scaling, unit), kinetic(kinetic, low, scaling, unit), origin(origin) {

}

Potential::Potential(const float potential, const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin)
        : Signal(potential, high, scaling, unit), kinetic(low, scaling, unit), origin(origin) {

}

Potential::Potential(const float potential, const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, high, scaling, unit), kinetic(kinetic, low, scaling, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin)
        : Signal(potential, high, scaling, unit), kinetic(low, scaling, unit), origin(origin) {

}

Potential::Potential(const Azimuth& potential, const float high, const float low,
		const short int scaling, const Unit& unit, const Angular& origin, const Azimuth& kinetic)
        : Signal(potential, high, scaling, unit), kinetic(kinetic, low, scaling, unit), origin(origin) {

}

Potential::~Potential() {

}

bool Potential::operator==(const Potential& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer))
        && (kinetic == peer.kinetic) && (origin == peer.origin);
}

bool Potential::operator<(const Potential& peer) const {
    Potential self = *this; bool result = false;
    if (static_cast<const Signal&>(*this) < static_cast<const Signal&>(peer)) {
        result = true;
    } else if (self.getSpreadActive() < peer.getSpreadActive()) {
        result = true;
    } else if (origin < peer.origin) {
        result = true;
    }
    return result;
}

bool Potential::operator>(const Potential& peer) const {
    Potential self = *this; bool result = false;
    if (static_cast<const Signal&>(*this) > static_cast<const Signal&>(peer)) {
        result = true;
    } else if (self.getSpreadActive() > peer.getSpreadActive()) {
        result = true;
    } else if (origin > peer.origin) {
        result = true;
    }
    return result;
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
    return getLinearPotential(peer, separation, position);
}

Signal Potential::operator()(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
    return getLinearPotential(peerX, peerY, separationX, separationY);
}

Signal Potential::getLinearPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearDisplacement(peer.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearConvergence(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearConvergence(peer.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearDivergence(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearDivergence(peer.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = peer.origin.getAzimuthDisplacement(self.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthConvergence(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = peer.origin.getAzimuthConvergence(self.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthDivergence(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = peer.origin.getAzimuthDivergence(self.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = peer.origin.getPolarDisplacement(self.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarConvergence(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = peer.origin.getPolarConvergence(self.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarDivergence(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = peer.origin.getPolarDivergence(self.origin, separation, position);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearDisplacement(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearConvergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearConvergence(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getLinearDivergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearDivergence(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getAzimuthDisplacement(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthConvergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getAzimuthConvergence(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getAzimuthDivergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getAzimuthDivergence(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getPolarDisplacement(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarConvergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getPolarConvergence(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getPolarDivergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const {
	Potential self = *this; shp::Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getPolarDivergence(peerX.getOrigin(), peerY.getOrigin(), separationX, separationY);
    Signal signal = distribution.getLinearDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

float Potential::getKineticAmplitude() const {
    return kinetic.getAmplitude();
}

float Potential::getLow() const {
	return kinetic.getMagnitude();
}

void Potential::setKinetic(const float value) {
	kinetic.setMagnitude(value);
}

void Potential::setKinetic(const float value, const short int scale) {
	kinetic.setMagnitude(value, scale);
}

void Potential::setKinetic(const float value, const short int scale, const std::string unit) {
	kinetic.setMagnitude(value, scale, unit);
}

void Potential::setKinetic(const float value, const short int scale, const Unit& unit) {
	kinetic.setMagnitude(value, scale, unit);
}

short int Potential::getKineticScaling() const {
	return kinetic.getScaling();
}

void Potential::setKineticScaling(const short int factor) {
	kinetic.setScaling(factor);
}

Unit Potential::getKineticUnit() const {
	return kinetic.getUnit();
}

void Potential::setKineticUnit(const Unit& object) {
	kinetic.setUnit(object);
}

float Potential::getPotentialAmplitude() const {
    return Signal::getAmplitude();
}

float Potential::getHigh() const {
	return Signal::getMagnitude();
}

float Potential::getPotential() const {
	return Signal::getMagnitude();
}

void Potential::setPotential(const float value) {
	Signal::setMagnitude(value);
}

void Potential::setPotential(const float value, const short int scale) {
	Signal::setMagnitude(value, scale);
}

void Potential::setPotential(const float value, const short int scale, const std::string unit) {
	Signal::setMagnitude(value, scale, unit);
}

void Potential::setPotential(const float value, const short int scale, const Unit& unit) {
	Signal::setMagnitude(value, scale, unit);
}

short int Potential::getPotentialScaling() const {
	return Signal::getScaling();
}

void Potential::setPotentialScaling(const short int factor) {
	Signal::setScaling(factor);
}

Unit Potential::getPotentialUnit() const {
	return Signal::getUnit();
}

void Potential::setPotentialUnit(const Unit& object) {
	Signal::setUnit(object);
}

void Potential::setRange(const float high, const float low) {
	this->setPotential(high); this->setKinetic(low);
}

void Potential::setRange(const float high, const float low, const short int scale) {
	this->setPotential(high); this->setPotentialScaling(scale);
    this->setKinetic(low); this->setKineticScaling(scale);
}

float Potential::getRadius() const {
    return Signal::getMagnitude();
}

void Potential::setRadius(const float length) {
    Signal::setMagnitude(length);
}

void Potential::setRadius(const float length, const short int scale) {
    Signal::setMagnitude(length, scale);
}

void Potential::setRadius(const float length, const short int scale, const std::string unit) {
    Signal::setMagnitude(length, scale, unit);
}

void Potential::setRadius(const float length, const short int scale, const Unit& unit) {
    Signal::setMagnitude(length, scale, unit);
}

Azimuth Potential::getKineticPhase() const {
    return kinetic.getOrientation();
}

void Potential::setKineticPhase(const Azimuth& orientation) {
    kinetic.setOrientation(orientation.toRadians());
}

Azimuth Potential::getPotentialPhase() const {
    return Signal::getOrientation();
}

void Potential::setPotentialPhase(const Azimuth& orientation) {
    Signal::setOrientation(orientation.toRadians());
}

Polar Potential::getPolarOrientation() const {
    return origin.getPolar();
}

void Potential::setPolarOrientation(const Polar& angle) {
    this->origin.setPolar(angle);
}

Azimuth Potential::getAzimuthOrientation() const {
    return origin.getAzimuth();
}

void Potential::setAzimuthOrientation(const Azimuth& angle) {
    this->origin.setAzimuth(angle);
}

Signal Potential::getDifference() const {
    return Potential::getDivergence();
}

Signal Potential::getDivergence() const {
	Potential self = *this; Signal distribution = self.getSpreadActive();
    Signal result(self.getOrientation(), distribution.getAmplitude(), self.getScaling(), self.getUnit());
    return result;
}

Signal Potential::getRelative(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getRelative(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
        (distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getRelativeX(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearX(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getRelativeY(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearY(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::getRelativeZ(const Distance& location) const {
    Potential self = *this; Signal distribution = self.getDivergence();
    Signal coefficient = self.origin.getLinearZ(location);
    Signal signal = distribution.getSquareDivergence(coefficient); signal.adjustScaling();
    Signal result(distribution.getOrientation(), signal.getMagnitude(),
		(distribution.getScaling() + signal.getScaling()), self.getUnit());
    return result;
}

Signal Potential::copy() const {
	Potential self = *this;
    Potential fresh(self.getOrientation(), self.getHigh(), self.getLow(), self.getScaling(),
        self.getUnit(), self.getOrigin(), kinetic.getOrientation());
    return fresh;
}

void Potential::clear() {
    Signal::clear();
    kinetic.clear();
    origin.clear();
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

Signal Potential::getSpreadActive() const {
    Signal potential = *this;
    return (potential - kinetic);
}

} // namespace shp