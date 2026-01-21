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

Angular::Angular(const Distance& radius, const Azimuth& azimuth)
		: Distance(radius), polar(DEFAULT_POLARITY), azimuth(azimuth) {

}

Angular::Angular(const Distance& radius, const Polar& polar)
		: Distance(radius), polar(polar), azimuth(DEFAULT_AZIMUTHAL) {

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

Angular::Angular(const float radius, const short int scaling, const float polar, const float azimuth)
		: Distance(radius, scaling), polar(polar), azimuth(azimuth) {

}

Angular::Angular(const float radius, const short int scaling, const std::string unit,
        const float polar, const float azimuth)
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
    return (static_cast<const Distance&>(*this) < static_cast<const Distance&>(peer))
            && (polar < peer.polar)
            && (azimuth < peer.azimuth);
}

bool Angular::operator>(const Angular& peer) const {
    return (static_cast<const Distance&>(*this) > static_cast<const Distance&>(peer))
            && (polar > peer.polar)
            && (azimuth > peer.azimuth);
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
    Angular self = *this;
    Quantity result = getLinearDisplacement(peer, separation, position);
    return result;
}

Quantity Angular::operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; float end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self(peerX, separationX, end).getCosComponent(peerX.polar.toRadians());
    Quantity azimY = self(peerY, separationY, end).getCosComponent(peerY.polar.toRadians());
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    std::complex<float> polarized = std::sqrt(radial);
    shp::Quantity result((std::abs(polarized) * cos(self.polar.toRadians())),
            azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ax = self.getRelativeX(position), bx = peer.getRelativeX((separation - position));
    Quantity result = (ax - bx); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity ay = self.getRelativeY(position), by = peer.getRelativeY((separation - position));
    Quantity result = (ay - by); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Quantity az = self.getRelativeZ(position), bz = peer.getRelativeZ((separation - position));
    Quantity result = (az - bz); result.adjustScaling();
    return result;
}

Quantity Angular::getLinearDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; float end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self(peerX, separationX, end).getCosComponent(peerX.polar.toRadians());
    Quantity azimY = self(peerY, separationY, end).getCosComponent(peerY.polar.toRadians());
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    std::complex<float> polarized = std::sqrt(radial);
    shp::Quantity result((std::abs(polarized) * cos(self.polar.toRadians())),
            azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getAzimuthDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; float end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self(peerX, separationX, end).getCosComponent(peerX.polar.toRadians());
    Quantity azimY = self(peerY, separationY, end).getCosComponent(peerY.polar.toRadians());
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    std::complex<float> polarized = std::sqrt(radial);
    shp::Quantity result((std::abs(polarized) * cos(self.polar.toRadians())),
            azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Quantity Angular::getPolarDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; float end = Quantity::DEFAULT_VALUE;
    Quantity azimX = self(peerX, separationX, end).getCosComponent(peerX.polar.toRadians());
    Quantity azimY = self(peerY, separationY, end).getCosComponent(peerY.polar.toRadians());
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    std::complex<float> polarized = std::sqrt(radial);
    shp::Quantity result((std::abs(polarized) * cos(self.polar.toRadians())),
            azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Distance Angular::getRadius() const {
    return Distance(Distance::getMagnitude(), Distance::getScaling(),
        Distance::getUnit(), Distance::getChange());
}

void Angular::setRadius(const Distance& length) {
    Quantity::setMagnitude(length.getMagnitude(), length.getScaling());
    Quantity::setUnit(length.getUnit());
    Distance::setChange(length.getChange());
}

void Angular::setRadius(const float length) {
    Quantity::setMagnitude(length);
}

void Angular::setRadius(const float length, const short int scaling) {
    Quantity::setMagnitude(length, scaling);
}

void Angular::setRadius(const float length, const short int scaling, const std::string unit) {
    Quantity::setMagnitude(length, scaling);
    Quantity::setUnit(unit);
}

void Angular::setRadius(const float length, const short int scaling, const Unit& unit) {
    Quantity::setMagnitude(length, scaling);
    Quantity::setUnit(unit);
}

Direction Angular::getChange() const {
    return Distance::getChange();
}

void Angular::setChange(const Direction& orientation) {
    Distance::setChange(orientation);
}

float Angular::getPolarFraction(const Polar& peer) const {
    return Direction::getFraction(polar.toRadians(), peer.toRadians());
}

float Angular::getAzimuthFraction(const Azimuth& peer) const {
    return Direction::getFraction(azimuth.toRadians(), peer.toRadians());
}

Quantity Angular::getRelative(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    Quantity coefficient  = radius(position, polar);            // radial, X, Y, Z combined
    Quantity result(coefficient.getMagnitude(), coefficient.getScaling(), self.getUnit());
    result.adjustScaling();
    return result;
}

Quantity Angular::getRelativeX(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    Quantity coefficient  = radius.getFactorX(position, polar); // X component only
    Quantity result(coefficient.getMagnitude(), coefficient.getScaling(), self.getUnit());
    result.adjustScaling();
    return result;
}

Quantity Angular::getRelativeY(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    Quantity coefficient  = radius.getFactorY(position, polar); // Y component only
    Quantity result(coefficient.getMagnitude(), coefficient.getScaling(), self.getUnit());
    result.adjustScaling();
    return result;
}

Quantity Angular::getRelativeZ(const Distance& position) const {
    Angular self = *this; Distance radius = self.getRadius();
    Quantity coefficient  = radius.getFactorZ(position, polar); // Z component only
    Quantity result(coefficient.getMagnitude(), coefficient.getScaling(), self.getUnit());
    result.adjustScaling();
    return result;
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