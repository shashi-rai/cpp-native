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

#include "angular.h"

namespace shp {

const float Angular::DEFAULT_RADIUS = shp::Quantity::DEFAULT_VALUE;
const float Angular::DEFAULT_POLARITY = shp::Direction::DEFAULT_RADIANS;
const float Angular::DEFAULT_AZIMUTHAL = shp::Direction::DEFAULT_RADIANS;

Angular::Angular()
        : Distance(DEFAULT_RADIUS), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const std::string unit)
        : Distance(unit), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const Unit& unit)
        : Distance(unit), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius)
        : Distance(radius), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const std::string unit)
        : Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const Unit& unit)
        : Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const short int scaling)
        : Distance(radius, scaling), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit)
        : Distance(radius, scaling, unit), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const short int scaling, const Unit& unit)
        : Distance(radius, scaling, unit), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const Distance& radius)
        : Distance(radius), polar(DEFAULT_POLARITY), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const float azimuth)
		: Distance(radius), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const std::string unit, const float azimuth)
		: Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const std::string unit, const Azimuth& azimuth)
		: Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const Unit& unit, const float azimuth)
		: Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const Unit& unit, const Azimuth& azimuth)
		: Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const float azimuth)
		: Distance(radius, scaling), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Azimuth& azimuth)
		: Distance(radius, scaling), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit,
        const float azimuth)
		: Distance(radius, scaling, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit,
        const Azimuth& azimuth)
		: Distance(radius, scaling, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Unit& unit,
        const float azimuth)
		: Distance(radius, scaling, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Unit& unit,
        const Azimuth& azimuth)
		: Distance(radius, scaling, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Unit& unit,
        const Polar& polar)
		: Distance(radius, scaling, unit), polar(polar), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const Azimuth& azimuth)
		: Distance(radius), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const Distance& radius, const Azimuth& azimuth)
		: Distance(radius), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const Polar& polar)
		: Distance(radius), polar(polar), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const short int scaling, const Polar& polar)
		: Distance(radius, scaling), polar(polar), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const Distance& radius, const Polar& polar)
		: Distance(radius), polar(polar), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const float radius, const Polar& polar, const Azimuth& azimuth)
		: Distance(radius), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Polar& polar, const Azimuth& azimuth)
		: Distance(radius, scaling), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const float polar, const float azimuth)
		: Distance(radius), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, std::string unit, const float polar, const float azimuth)
		: Distance(radius, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const Unit& unit, const float polar, const float azimuth)
		: Distance(radius, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const Unit& unit, const Polar& polar, const Azimuth& azimuth)
		: Distance(radius, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const float polar, const float azimuth)
		: Distance(radius, scaling), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit,
        const float polar, const float azimuth)
		: Distance(radius, scaling, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit,
        const Polar& polar, const Azimuth& azimuth)
		: Distance(radius, scaling, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Unit& unit,
        const float polar, const float azimuth)
		: Distance(radius, scaling, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const Unit& unit,
        const Polar& polar, const Azimuth& azimuth)
		: Distance(radius, scaling, unit), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const Azimuth& azimuth)
		: Distance(DEFAULT_RADIUS), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const Polar& polar)
		: Distance(DEFAULT_RADIUS), polar(polar), azimuth(DEFAULT_AZIMUTHAL) {

}

Angular::Angular(const Polar& polar, const Azimuth& azimuth)
		: Distance(DEFAULT_RADIUS), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const Distance& radius, const Polar& polar, const Azimuth& azimuth)
		: Distance(radius), polar(polar), azimuth(azimuth) {

}

Angular::~Angular() {

}

bool Angular::operator==(const Angular& peer) const {
    return (static_cast<const Distance&>(*this) == static_cast<const Distance&>(peer))
            && (polar == peer.polar)
            && (azimuth == peer.azimuth);
}

bool Angular::operator<(const Angular& peer) const {
    Angular self = *this; bool result = false;
    if (static_cast<const Distance&>(*this) < static_cast<const Distance&>(peer)) {
        result = true;
    } else if (polar < peer.polar) {
        result = true;
    } else if (azimuth < peer.azimuth) {
        result = true;
    }
    return result;
}

bool Angular::operator>(const Angular& peer) const {
    Angular self = *this; bool result = false;
    if (static_cast<const Distance&>(*this) > static_cast<const Distance&>(peer)) {
        result = true;
    } else if (polar > peer.polar) {
        result = true;
    } else if (azimuth > peer.azimuth) {
        result = true;
    }
    return result;
}

bool Angular::operator<=(const Angular& peer) const {
    Angular self = *this;
    return (self < peer) || (self == peer);
}

bool Angular::operator>=(const Angular& peer) const {
    Angular self = *this;
    return (self > peer) || (self == peer);
}

Angular Angular::operator+(const Angular& peer) const {
    Angular self = *this, other = peer;
    Distance newRadius = (self.getRadius() + other.getRadius());
    Polar newPolar = (self.polar + other.polar);
    Azimuth newAzimuth = (self.azimuth + other.azimuth);
    return Angular(newRadius, newPolar, newAzimuth);
}

Angular Angular::operator-(const Angular& peer) const {
    Angular self = *this, other = peer;
    Distance newRadius = (self.getRadius() - other.getRadius());
    Polar newPolar = (polar - other.polar);
    Azimuth newAzimuth = (azimuth - other.azimuth);
    return Angular(newRadius, newPolar, newAzimuth);
}

Angular Angular::operator*(const Angular& peer) const {
    Angular self = *this, other = peer;
    Distance newRadius = (self.getRadius() * other.getRadius());
    Polar newPolar = (self.polar * other.polar);
    Azimuth newAzimuth = (azimuth * other.azimuth);
    return Angular(newRadius, newPolar, newAzimuth);
}

Angular Angular::operator/(const Angular& peer) const {
    Angular self = *this, other = peer;
    Distance newRadius = (self.getRadius() / other.getRadius());
    Polar newPolar = (polar / other.polar);
    Azimuth newAzimuth = (self.azimuth / other.azimuth);
    return Angular(newRadius, newPolar, newAzimuth);
}

Angular Angular::operator%(const Angular& peer) const {
    Angular self = *this, other = peer;
    Distance newRadius = (self.getRadius() % other.getRadius());
    Polar newPolar = (self.polar % other.polar);
    Azimuth newAzimuth = (self.azimuth % other.azimuth);
    return Angular(newRadius, newPolar, newAzimuth);
}

Distance Angular::operator+(const Distance& separation) const {
    Angular self = *this;
    Distance newRadius = (self.getRadius() + separation);
    return Distance(newRadius.getMagnitude(),
        newRadius.getScaling(), self.getRadius().getUnit());
}

Distance Angular::operator-(const Distance& separation) const {
    Angular self = *this;
    Distance newRadius = (self.getRadius() - separation);
    return Distance(newRadius.getMagnitude(),
        newRadius.getScaling(), self.getRadius().getUnit());
}

Distance Angular::operator*(const Distance& separation) const {
    Angular self = *this;
    Distance newRadius = (self.getRadius() * separation);
    return Distance(newRadius.getMagnitude(),
        newRadius.getScaling(), self.getRadius().getUnit());
}

Distance Angular::operator/(const Distance& separation) const {
    Angular self = *this;
    Distance newRadius = (self.getRadius() / separation);
    return Distance(newRadius.getMagnitude(),
        newRadius.getScaling(), self.getRadius().getUnit());
}

Distance Angular::operator%(const Distance& separation) const {
    Angular self = *this;
    Distance newRadius = (self.getRadius() % separation);
    return Distance(newRadius.getMagnitude(),
        newRadius.getScaling(), self.getRadius().getUnit());
}

Angular Angular::operator+(const Azimuth& rotation) const {
    Angular self = *this;
    Azimuth newAzimuth = (self.azimuth + rotation);
    return Angular(self.getRadius(), self.polar, newAzimuth);
}

Angular Angular::operator-(const Azimuth& rotation) const {
    Angular self = *this;
    Azimuth newAzimuth = (self.azimuth - rotation);
    return Angular(self.getRadius(), self.polar, newAzimuth);
}

Angular Angular::operator*(const Azimuth& rotation) const {
    Angular self = *this;
    Azimuth newAzimuth = (self.azimuth * rotation);
    return Angular(self.getRadius(), self.polar, newAzimuth);
}

Angular Angular::operator/(const Azimuth& rotation) const {
    Angular self = *this;
    Azimuth newAzimuth = (self.azimuth / rotation);
    return Angular(self.getRadius(), self.polar, newAzimuth);
}

Angular Angular::operator%(const Azimuth& rotation) const {
    Angular self = *this;
    Azimuth newAzimuth = (self.azimuth % rotation);
    return Angular(self.getRadius(), self.polar, newAzimuth);
}

Angular Angular::operator+(const Polar& rotation) const {
    Angular self = *this;
    Polar newPolar = (self.polar + rotation);
    return Angular(self.getRadius(), newPolar, self.azimuth);
}

Angular Angular::operator-(const Polar& rotation) const {
    Angular self = *this;
    Polar newPolar = (self.polar - rotation);
    return Angular(self.getRadius(), newPolar, self.azimuth);
}

Angular Angular::operator*(const Polar& rotation) const {
    Angular self = *this;
    Polar newPolar = (self.polar * rotation);
    return Angular(self.getRadius(), newPolar, self.azimuth);
}

Angular Angular::operator/(const Polar& rotation) const {
    Angular self = *this;
    Polar newPolar = (self.polar / rotation);
    return Angular(self.getRadius(), newPolar, self.azimuth);
}

Angular Angular::operator%(const Polar& rotation) const {
    Angular self = *this;
    Polar newPolar = (self.polar % rotation);
    return Angular(self.getRadius(), newPolar, self.azimuth);
}

shp::Signal Angular::operator()(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    return getLinearDisplacement(peer, separation, position);
}

shp::Signal Angular::operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    return getLinearDisplacement(peerX, peerY, separationX, separationY);
}

shp::Signal Angular::getLinearDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal ax = self.getLinearX(position), bx = peer.getLinearX((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Angular::getLinearConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal ax = self.getLinearXConvergence(position), bx = peer.getLinearXConvergence((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Angular::getLinearDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal ax = self.getLinearXDivergence(position), bx = peer.getLinearXDivergence((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Angular::getAzimuthDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal ay = self.getLinearY(position), by = peer.getLinearY((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Angular::getAzimuthConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal ay = self.getLinearYConvergence(position), by = peer.getLinearYConvergence((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Angular::getAzimuthDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal ay = self.getLinearYDivergence(position), by = peer.getLinearYDivergence((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Angular::getPolarDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal az = self.getLinearZ(position), bz = peer.getLinearZ((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Angular::getPolarConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal az = self.getLinearZConvergence(position), bz = peer.getLinearZConvergence((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Angular::getPolarDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    shp::Signal az = self.getLinearZDivergence(position), bz = peer.getLinearZDivergence((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Angular::getLinearDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearDisplacement(peerX, separationX, end);
    shp::Signal azimY = self.getLinearDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getLinearConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getLinearConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getLinearDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getLinearDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getAzimuthDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getAzimuthDisplacement(peerX, separationX, end);
    shp::Signal azimY = self.getAzimuthDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getAzimuthConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getAzimuthConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getAzimuthConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getAzimuthDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getAzimuthDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getAzimuthDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getPolarDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getPolarDisplacement(peerX, separationX, end);
    shp::Signal azimY = self.getPolarDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getPolarConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getPolarConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getPolarConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Angular::getPolarDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getPolarDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getPolarDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Distance Angular::getRadius() const {
    return Distance(Distance::getMagnitude(), Distance::getScaling(), Distance::getUnit(),
        Distance::getAzimuth(), Distance::getModulation());
}

void Angular::setRadius(const Distance& length) {
    Angular self = *this;
    self.setRadius(length.getMagnitude(), length.getScaling(), length.getUnit());
    self.setStressFactor(length.getAzimuth());
    self.setDopplerShift(length.getModulation());
}

void Angular::setRadius(const float length) {
    Distance::setMagnitude(length);
}

void Angular::setRadius(const float length, const short int scaling) {
    Distance::setMagnitude(length, scaling);
}

void Angular::setRadius(const float length, const short int scaling, const std::string unit) {
    Distance::setMagnitude(length, scaling, unit);
}

void Angular::setRadius(const float length, const short int scaling, const Unit& unit) {
    Distance::setMagnitude(length, scaling, unit);
}

Direction Angular::getStressFactor() const {
    return Distance::getAzimuth();
}

void Angular::setStressFactor(const float orientation) {
    Distance::setAzimuth(orientation);
}

void Angular::setStressFactor(const Azimuth& orientation) {
    Distance::setAzimuth(orientation);
}

Direction Angular::getDopplerShift() const {
    return Distance::getModulation();
}

void Angular::setDopplerShift(const float relativity) {
    Distance::setModulation(relativity);
}

void Angular::setDopplerShift(const Polar& relativity) {
    Distance::setModulation(relativity);
}

float Angular::getPolarCyclingRate() const {
    Angular self = *this;
    return self.polar.getCyclingRate();
}

float Angular::getPolarTimePerCycle() const {
    Angular self = *this;
    return self.polar.getTimePerCycle();
}

Direction Angular::getPolarTangent() const {
    Angular self = *this;
    return self.polar.getNormal();
}

Direction Angular::getPolarRotation(const short int degree) const {
    Angular self = *this;
    return self.polar.getRotation(degree);
}

void Angular::setPolarRotation(const short int degree) {
    this->polar.setRotation(degree);
}

Direction Angular::getPolarChange() const {
    Angular self = *this;
    return self.polar.getChange();
}

void Angular::setPolarChange(const Direction& orientation) {
    Angular self = *this;
    self.polar.setChange(orientation);
}

float Angular::getPolarFraction(const Polar& peer) const {
    Angular self = *this;
    return Direction::getFraction(self.polar.toRadians(), peer.toRadians());
}

float Angular::getAzimuthCyclingRate() const {
    Angular self = *this;
    return self.azimuth.getCyclingRate();
}

float Angular::getAzimuthTimePerCycle() const {
    Angular self = *this;
    return self.azimuth.getTimePerCycle();
}

Direction Angular::getAzimuthTangent() const {
    Angular self = *this;
    return self.azimuth.getNormal();
}

Direction Angular::getAzimuthRotation(const short int degree) const {
    Angular self = *this;
    return self.azimuth.getRotation(degree);
}

void Angular::setAzimuthRotation(const short int degree) {
    this->azimuth.setRotation(degree);
}

Direction Angular::getAzimuthChange() const {
    Angular self = *this;
    return self.azimuth.getChange();
}

void Angular::setAzimuthChange(const Direction& orientation) {
    Angular self = *this;
    self.azimuth.setChange(orientation);
}

float Angular::getAzimuthFraction(const Azimuth& peer) const {
    Angular self = *this;
    return Direction::getFraction(self.azimuth.toRadians(), peer.toRadians());
}

shp::Signal Angular::getRelative(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius(position, Direction::DEFAULT_RADIANS);        // radial, X, Y, Z combined;
}

shp::Signal Angular::getLinearX(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getLinear(position, polar);                   // X component only;
}

shp::Signal Angular::getLinearXConvergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getLinearConvergence(position, polar);        // X component only;
}

shp::Signal Angular::getLinearXDivergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getLinearDivergence(position, polar);         // X component only;
}

shp::Signal Angular::getLinearY(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonal(position, azimuth);             // Y component only;
}

shp::Signal Angular::getLinearYConvergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalConvergence(position, polar);    // Y component only;
}

shp::Signal Angular::getLinearYDivergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalDivergence(position, polar);     // Y component only;
}

shp::Signal Angular::getLinearZ(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonal(position, polar);               // Z component only;
}

shp::Signal Angular::getLinearZConvergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalConvergence(position, polar);    // Z component only;
}

shp::Signal Angular::getLinearZDivergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalDivergence(position, polar);     // Z component only;
}

Distance Angular::copy() {
    Angular self = *this;
    Angular fresh(self.getRadius(), self.polar, self.azimuth);
    return fresh;
}

void Angular::clear() {
    Distance::clear();
    polar.clear();
    azimuth.clear();
    return;
}

std::string Angular::print() const {
    std::stringstream result;
    result << "{";
    result << Distance::print() << ",";
    result << polar.print() << ",";
    result << azimuth.print() << "}";
	return result.str();
}

std::string Angular::printRadians() const {
    std::stringstream result;
    result << "{";
    result << Distance::print() << ",";
    result << polar.printRadians() << ",";
    result << azimuth.printRadians() << "}";
	return result.str();
}

std::string Angular::printEuler() const {
    std::stringstream result;
    result << "{";
    result << Distance::print() << ",";
    result << polar.printEuler() << ",";
    result << azimuth.printEuler() << "}";
	return result.str();
}

} // namespace shp