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

const float Angular::DEFAULT_RADIUS = Quantity::DEFAULT_VALUE;
const float Angular::DEFAULT_POLARITY = Quantity::DEFAULT_VALUE;
const float Angular::DEFAULT_AZIMUTHAL = Quantity::DEFAULT_VALUE;

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

Angular::Angular(const float radius, const float azimuth, const std::string unit)
		: Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const float azimuth, const Unit& unit)
		: Distance(radius, unit), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const float azimuth)
		: Distance(radius, scaling), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit,
        const float azimuth)
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

Angular::Angular(const float radius, const short int scaling, const Azimuth& azimuth)
		: Distance(radius, scaling), polar(DEFAULT_POLARITY), azimuth(azimuth) {

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

Quantity Angular::operator()(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    return getLinearDisplacement(peer, separation, position);
}

Quantity Angular::operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    return getLinearDisplacement(peerX, peerY, separationX, separationY);
}

Quantity Angular::getLinearDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ax = self.getLinearX(position), bx = peer.getLinearX((separation - position));
    Quantity result = (ax - bx); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ax = self.getLinearXConvergence(position), bx = peer.getLinearXConvergence((separation - position));
    Quantity result = (ax - bx); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ax = self.getLinearXDivergence(position), bx = peer.getLinearXDivergence((separation - position));
    Quantity result = (ax - bx); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ay = self.getLinearY(position), by = peer.getLinearY((separation - position));
    Quantity result = (ay - by); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ay = self.getLinearYConvergence(position), by = peer.getLinearYConvergence((separation - position));
    Quantity result = (ay - by); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ay = self.getLinearYDivergence(position), by = peer.getLinearYDivergence((separation - position));
    Quantity result = (ay - by); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity az = self.getLinearZ(position), bz = peer.getLinearZ((separation - position));
    Quantity result = (az - bz); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity az = self.getLinearZConvergence(position), bz = peer.getLinearZConvergence((separation - position));
    Quantity result = (az - bz); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity az = self.getLinearZDivergence(position), bz = peer.getLinearZDivergence((separation - position));
    Quantity result = (az - bz); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getLinearDisplacement(peerX, separationX, end);
    Quantity azimY = self.getLinearDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getLinearConvergence(peerX, separationX, end);
    Quantity azimY = self.getLinearConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getLinearDivergence(peerX, separationX, end);
    Quantity azimY = self.getLinearDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getAzimuthDisplacement(peerX, separationX, end);
    Quantity azimY = self.getAzimuthDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getAzimuthConvergence(peerX, separationX, end);
    Quantity azimY = self.getAzimuthConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getAzimuthDivergence(peerX, separationX, end);
    Quantity azimY = self.getAzimuthDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getPolarDisplacement(peerX, separationX, end);
    Quantity azimY = self.getPolarDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getPolarConvergence(peerX, separationX, end);
    Quantity azimY = self.getPolarConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    std::complex<float> polarized = std::sqrt(radial);
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; Distance end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self.getPolarDivergence(peerX, separationX, end);
    Quantity azimY = self.getPolarDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Quantity result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Distance Angular::getRadius() const {
    return Distance(Distance::getMagnitude(), Distance::getScaling(),
        Distance::getUnit(), Distance::getChange());
}

void Angular::setRadius(const Distance& length) {
    Angular self = *this;
    self.setRadius(length.getMagnitude(), length.getScaling(), length.getUnit());
    self.setRadiusChange(length.getChange());
}

void Angular::setRadius(const float length) {
    Quantity::setMagnitude(length);
}

void Angular::setRadius(const float length, const short int scaling) {
    Quantity::setMagnitude(length, scaling);
}

void Angular::setRadius(const float length, const short int scaling, const std::string unit) {
    Quantity::setMagnitude(length, scaling, unit);
}

void Angular::setRadius(const float length, const short int scaling, const Unit& unit) {
    Quantity::setMagnitude(length, scaling, unit);
}

Direction Angular::getRadiusChange() const {
    return Distance::getChange();
}

void Angular::setRadiusChange(const Direction& orientation) {
    Distance::setChange(orientation);
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

Quantity Angular::getRelative(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius(position, Direction::DEFAULT_RADIANS);    // radial, X, Y, Z combined;
}

Quantity Angular::getLinearX(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getLinear(position, polar);               // X component only;
}

Quantity Angular::getLinearXConvergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getLinearAmplified(position, polar);      // X component only;
}

Quantity Angular::getLinearXDivergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getLinearDivergence(position, polar);     // X component only;
}

Quantity Angular::getLinearY(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonal(position, azimuth);         // Y component only;
}

Quantity Angular::getLinearYConvergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalAmplified(position, polar);  // Y component only;
}

Quantity Angular::getLinearYDivergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalDivergence(position, polar); // Y component only;
}

Quantity Angular::getLinearZ(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonal(position, polar);           // Z component only;
}

Quantity Angular::getLinearZConvergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalAmplified(position, polar);  // Z component only;
}

Quantity Angular::getLinearZDivergence(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    return radius.getOrthogonalDivergence(position, polar); // Z component only;
}

Distance Angular::copy() const {
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