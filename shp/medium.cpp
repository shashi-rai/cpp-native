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

#include "medium.h"

namespace shp {

Medium::Medium()
        : Distance() {

}

Medium::Medium(const std::string unit)
        : Distance(unit) {

}

Medium::Medium(const Unit& unit)
        : Distance(unit) {

}

Medium::Medium(const float separation)
        : Distance(separation) {

}

Medium::Medium(const float separation, const std::string unit)
        : Distance(separation, unit) {

}

Medium::Medium(const float separation, const Unit& unit)
        : Distance(separation, unit) {

}

Medium::Medium(const float separation, const short int scaling)
        : Distance(separation, scaling) {

}

Medium::Medium(const float separation, const short int scaling, const std::string unit)
        : Distance(separation, scaling, unit) {

}

Medium::Medium(const float separation, const short int scaling, const Unit& unit)
        : Distance(separation, scaling, unit) {

}

Medium::Medium(const Distance& separation)
        : Distance(separation.getMagnitude(), separation.getScaling(), separation.getUnit(),
            separation.getModulation(), separation.getAzimuth()) {

}

Medium::Medium(const float separation, const float orientation)
		: Distance(separation, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const std::string unit, const float orientation)
		: Distance(separation, unit, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const std::string unit, const Azimuth& orientation)
		: Distance(separation, unit, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const Unit& unit, const float orientation)
		: Distance(separation, unit, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const Unit& unit, const Azimuth& orientation)
		: Distance(separation, unit, orientation) {

}

Medium::Medium(const float separation, const short int scaling, const float orientation)
		: Distance(separation, scaling, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const short int scaling, const Azimuth& orientation)
		: Distance(separation, scaling, orientation) {

}

Medium::Medium(const float separation, const short int scaling, const std::string unit,
        const float orientation)
		: Distance(separation, scaling, unit, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const short int scaling, const std::string unit,
        const Azimuth& orientation)
		: Distance(separation, scaling, unit, orientation) {

}

Medium::Medium(const float separation, const short int scaling, const Unit& unit,
        const float orientation)
		: Distance(separation, scaling, unit, Azimuth(orientation)) {

}

Medium::Medium(const float separation, const short int scaling, const Unit& unit,
        const Azimuth& orientation)
		: Distance(separation, scaling, unit, orientation) {

}

Medium::Medium(const float separation, const short int scaling, const Unit& unit,
        const Polar& threshold)
		: Distance(separation, scaling, unit, threshold) {

}

Medium::Medium(const float separation, const Azimuth& orientation)
		: Distance(separation, orientation) {

}

Medium::Medium(const float separation, const Polar& threshold)
		: Distance(separation, threshold) {

}

Medium::Medium(const float separation, const short int scaling, const Polar& threshold)
		: Distance(separation, scaling, threshold) {

}

Medium::Medium(const float separation, const Polar& threshold, const Azimuth& orientation)
		: Distance(separation, threshold, orientation) {

}

Medium::Medium(const float separation, const short int scaling, const Polar& threshold, const Azimuth& orientation)
		: Distance(separation, scaling, threshold, orientation) {

}

Medium::Medium(const float separation, const float threshold, const float orientation)
		: Distance(separation, Polar(threshold), Azimuth(orientation)) {

}

Medium::Medium(const float separation, std::string unit, const float threshold, const float orientation)
		: Distance(separation, unit, Polar(threshold), Azimuth(orientation)) {

}

Medium::Medium(const float separation, const Unit& unit, const float threshold, const float orientation)
		: Distance(separation, unit, Polar(threshold), Azimuth(orientation)) {

}

Medium::Medium(const float separation, const Unit& unit, const Polar& threshold, const Azimuth& orientation)
		: Distance(separation, unit, threshold, orientation) {

}

Medium::Medium(const float separation, const short int scaling, const float threshold, const float orientation)
		: Distance(separation, scaling, Polar(threshold), Azimuth(orientation)) {

}

Medium::Medium(const float separation, const short int scaling, const std::string unit,
        const float threshold, const float orientation)
		: Distance(separation, scaling, unit, Azimuth(orientation), Polar(threshold)) {

}

Medium::Medium(const float separation, const short int scaling, const std::string unit,
        const Polar& threshold, const Azimuth& orientation)
		: Distance(separation, scaling, unit, orientation, threshold) {

}

Medium::Medium(const float separation, const short int scaling, const Unit& unit,
        const float threshold, const float orientation)
		: Distance(separation, scaling, unit, Polar(threshold), Azimuth(orientation)) {

}

Medium::Medium(const float separation, const short int scaling, const Unit& unit,
        const Polar& threshold, const Azimuth& orientation)
		: Distance(separation, scaling, unit, orientation, threshold) {

}

Medium::Medium(const Azimuth& orientation)
		: Distance(orientation) {

}

Medium::Medium(const Polar& threshold)
		: Distance(threshold) {

}

Medium::Medium(const Polar& threshold, const Azimuth& orientation)
		: Distance(threshold, orientation) {

}

Medium::~Medium() {

}

bool Medium::operator==(const Medium& peer) const {
    return (static_cast<const Distance&>(*this) == static_cast<const Distance&>(peer));
}

bool Medium::operator<(const Medium& peer) const {
    Medium self = *this; bool result = false;
    if (static_cast<const Distance&>(*this) < static_cast<const Distance&>(peer)) {
        result = true;
    }
    return result;
}

bool Medium::operator>(const Medium& peer) const {
    Medium self = *this; bool result = false;
    if (static_cast<const Distance&>(*this) > static_cast<const Distance&>(peer)) {
        result = true;
    }
    return result;
}

bool Medium::operator<=(const Medium& peer) const {
    Medium self = *this;
    return (self < peer) || (self == peer);
}

bool Medium::operator>=(const Medium& peer) const {
    Medium self = *this;
    return (self > peer) || (self == peer);
}

Medium Medium::operator+(const Medium& peer) const {
    Distance self = *this, other = peer, separation = (self + other);
    return Medium(separation.getMagnitude(), separation.getScaling(), separation.getUnit(),
        separation.getModulation(), separation.getAzimuth());
}

Medium Medium::operator-(const Medium& peer) const {
    Distance self = *this, other = peer, separation = (self - other);
    return Medium(separation.getMagnitude(), separation.getScaling(), separation.getUnit(),
        separation.getModulation(), separation.getAzimuth());
}

Medium Medium::operator*(const Medium& peer) const {
    Distance self = *this, other = peer, separation = (self * other);
    return Medium(separation.getMagnitude(), separation.getScaling(), separation.getUnit(),
        separation.getModulation(), separation.getAzimuth());
}

Medium Medium::operator/(const Medium& peer) const {
    Distance self = *this, other = peer, separation = (self / other);
    return Medium(separation.getMagnitude(), separation.getScaling(), separation.getUnit(),
        separation.getModulation(), separation.getAzimuth());
}

Medium Medium::operator%(const Medium& peer) const {
    Distance self = *this, other = peer, separation = (self % other);
    return Medium(separation.getMagnitude(), separation.getScaling(), separation.getUnit(),
        separation.getModulation(), separation.getAzimuth());
}

Medium Medium::operator+(const Distance& separation) const {
    Medium self = *this;
    Distance newSeparation = (self.getSeparation() + separation);
    return Medium(newSeparation.getMagnitude(), newSeparation.getScaling(), newSeparation.getUnit(),
        newSeparation.getModulation(), newSeparation.getAzimuth());
}

Medium Medium::operator-(const Distance& separation) const {
    Medium self = *this;
    Distance newSeparation = (self.getSeparation() - separation);
    return Medium(newSeparation.getMagnitude(), newSeparation.getScaling(), newSeparation.getUnit(),
        newSeparation.getModulation(), newSeparation.getAzimuth());
}

Medium Medium::operator*(const Distance& separation) const {
    Medium self = *this;
    Distance newSeparation = (self.getSeparation() * separation);
    return Medium(newSeparation.getMagnitude(), newSeparation.getScaling(), newSeparation.getUnit(),
        newSeparation.getModulation(), newSeparation.getAzimuth());
}

Medium Medium::operator/(const Distance& separation) const {
    Medium self = *this;
    Distance newSeparation = (self.getSeparation() / separation);
    return Medium(newSeparation.getMagnitude(), newSeparation.getScaling(), newSeparation.getUnit(),
        newSeparation.getModulation(), newSeparation.getAzimuth());
}

Medium Medium::operator%(const Distance& separation) const {
    Medium self = *this;
    Distance newSeparation = (self.getSeparation() % separation);
    return Medium(newSeparation.getMagnitude(), newSeparation.getScaling(), newSeparation.getUnit(),
        newSeparation.getModulation(), newSeparation.getAzimuth());
}

Medium Medium::operator+(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newSeparation = (self.getAzimuth() + orientation);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newSeparation);
}

Medium Medium::operator-(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newSeparation = (self.getAzimuth() - orientation);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newSeparation);
}

Medium Medium::operator*(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newSeparation = (self.getAzimuth() * orientation);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newSeparation);
}

Medium Medium::operator/(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newSeparation = (self.getAzimuth() / orientation);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newSeparation);
}

Medium Medium::operator%(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newSeparation = (self.getAzimuth() % orientation);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newSeparation);
}

Medium Medium::operator+(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() + threshold);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth());
}

Medium Medium::operator-(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() - threshold);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth());
}

Medium Medium::operator*(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() * threshold);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth());
}

Medium Medium::operator/(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() / threshold);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth());
}

Medium Medium::operator%(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() % threshold);
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth());
}

shp::Signal Medium::operator()(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    return getLinearDisplacement(peer, separation, position);
}

shp::Signal Medium::operator()(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    return getLinearDisplacement(peerX, peerY, separationX, separationY);
}

shp::Signal Medium::getLinearDisplacement(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ax = self.getLinearX(position), bx = peer.getLinearX((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ax = self.getLinearXConvergence(position), bx = peer.getLinearXConvergence((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ax = self.getLinearXDivergence(position), bx = peer.getLinearXDivergence((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Medium::getSeparationDisplacement(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ay = self.getLinearY(position), by = peer.getLinearY((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Medium::getSeparationConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ay = self.getLinearYConvergence(position), by = peer.getLinearYConvergence((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Medium::getSeparationDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ay = self.getLinearYDivergence(position), by = peer.getLinearYDivergence((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDisplacement(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal az = self.getLinearZ(position), bz = peer.getLinearZ((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal az = self.getLinearZConvergence(position), bz = peer.getLinearZConvergence((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal az = self.getLinearZDivergence(position), bz = peer.getLinearZDivergence((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearDisplacement(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearDisplacement(peerX, separationX, end);
    shp::Signal azimY = self.getLinearDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getLinearConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getLinearDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getSeparationDisplacement(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getSeparationDisplacement(peerX, separationX, end);
    shp::Signal azimY = self.getSeparationDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getSeparationConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getSeparationConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getSeparationConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getSeparationDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getSeparationDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getSeparationDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDisplacement(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getThresholdDisplacement(peerX, separationX, end);
    shp::Signal azimY = self.getThresholdDisplacement(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getThresholdConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getThresholdConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getThresholdDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getThresholdDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Distance Medium::getSeparation() const {
    return Distance(Distance::getMagnitude(), Distance::getScaling(), Distance::getUnit(),
        Distance::getAzimuth(), Distance::getModulation());
}

void Medium::setSeparation(const Distance& length) {
    Medium self = *this;
    self.setSeparation(length.getMagnitude(), length.getScaling(), length.getUnit());
    self.setStressFactor(length.getAzimuth());
    self.setThresholdShift(length.getModulation());
}

void Medium::setSeparation(const float length) {
    Distance::setMagnitude(length);
}

void Medium::setSeparation(const float length, const short int scaling) {
    Distance::setMagnitude(length, scaling);
}

void Medium::setSeparation(const float length, const short int scaling, const std::string unit) {
    Distance::setMagnitude(length, scaling, unit);
}

void Medium::setSeparation(const float length, const short int scaling, const Unit& unit) {
    Distance::setMagnitude(length, scaling, unit);
}

Direction Medium::getStressFactor() const {
    return Distance::getAzimuth();
}

void Medium::setStressFactor(const float orientation) {
    Distance::setAzimuth(orientation);
}

void Medium::setStressFactor(const Azimuth& orientation) {
    Distance::setAzimuth(orientation);
}

Direction Medium::getThresholdShift() const {
    return Distance::getModulation();
}

void Medium::setThresholdShift(const float threshold) {
    Distance::setModulation(threshold);
}

void Medium::setThresholdShift(const Polar& threshold) {
    Distance::setModulation(threshold);
}

float Medium::getThresholdCyclingRate() const {
    return Distance::getModulation().getCyclingRate();
}

float Medium::getThresholdTimePerCycle() const {
    return Distance::getModulation().getTimePerCycle();
}

Direction Medium::getThresholdTangent() const {
    return Distance::getModulation().getNormal();
}

Direction Medium::getThresholdRotation(const short int degree) const {
    return Distance::getModulation().getRotation(degree);
}

void Medium::setThresholdRotation(const short int degree) {
    Distance::setChangeCurvature(degree);
}

Direction Medium::getThresholdChange() const {
    return Distance::getModulation().getChange();
}

void Medium::setThresholdChange(const Direction& orientation) {
    Polar threshold = Distance::getModulation();
    threshold.setChange(orientation);
}

float Medium::getThresholdFraction(const Polar& peer) const {
    return Direction::getFraction(Distance::getModulation().toRadians(), peer.toRadians());
}

float Medium::getSeparationCyclingRate() const {
    return Distance::getAzimuth().getCyclingRate();
}

float Medium::getSeparationTimePerCycle() const {
    return Distance::getAzimuth().getTimePerCycle();
}

Direction Medium::getSeparationTangent() const {
    return Distance::getAzimuth().getNormal();
}

Direction Medium::getSeparationRotation(const short int degree) const {
    return Distance::getAzimuth().getRotation(degree);
}

void Medium::setSeparationRotation(const short int degree) {
    Distance::setChangeDirection(degree);
}

Direction Medium::getSeparationChange() const {
    return Distance::getAzimuth().getChange();
}

void Medium::setSeparationChange(const Direction& orientation) {
    Azimuth direction = Distance::getAzimuth();
    direction.setChange(orientation);
}

float Medium::getSeparationFraction(const Azimuth& peer) const {
    return Direction::getFraction(Distance::getAzimuth().toRadians(), peer.toRadians());
}

shp::Signal Medium::getRelative(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation(position, Direction::DEFAULT_RADIANS);                        // radial, X, Y, Z combined;
}

shp::Signal Medium::getLinearX(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getLinear(position, Distance::getModulation());               // X component only;
}

shp::Signal Medium::getLinearXConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getLinearConvergence(position, Distance::getModulation());    // X component only;
}

shp::Signal Medium::getLinearXDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getLinearDivergence(position, Distance::getModulation());     // X component only;
}

shp::Signal Medium::getLinearY(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getOrthogonal(position, Distance::getAzimuth());              // Y component only;
}

shp::Signal Medium::getLinearYConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getOrthogonalConvergence(position, Distance::getModulation());// Y component only;
}

shp::Signal Medium::getLinearYDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getOrthogonalDivergence(position, Distance::getModulation()); // Y component only;
}

shp::Signal Medium::getLinearZ(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getOrthogonal(position, Distance::getModulation());           // Z component only;
}

shp::Signal Medium::getLinearZConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getOrthogonalConvergence(position, Distance::getModulation());// Z component only;
}

shp::Signal Medium::getLinearZDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getSeparation();
    return separation.getOrthogonalDivergence(position, Distance::getModulation()); // Z component only;
}

Distance Medium::copy() {
    Distance self = *this;
    Medium fresh(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), self.getAzimuth());
    return fresh;
}

void Medium::clear() {
    Distance::clear();
    return;
}

std::string Medium::print() const {
    std::stringstream result;
    result << "{";
    result << Distance::print();
    result << "}";
	return result.str();
}

std::string Medium::printRadians() const {
    std::stringstream result;
    result << "{";
    result << Distance::printRadians();
    result << "}";
	return result.str();
}

} // namespace shp