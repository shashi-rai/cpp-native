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
const float Angular::DEFAULT_AZIMUTH = Quantity::DEFAULT_VALUE;

Angular::Angular()
        : Distance(), polar(), azimuthal() {

}

Angular::Angular(float radius)
        : Distance(radius), polar(), azimuthal() {

}

Angular::Angular(float radius, short int scaling)
        : Distance(radius, scaling), polar(), azimuthal() {

}

Angular::Angular(float radius, short int scaling, std::string unit)
        : Distance(radius, scaling, unit), polar(), azimuthal() {

}

Angular::Angular(float radius, short int scaling, const Unit& unit)
        : Distance(radius, scaling, unit), polar(), azimuthal() {

}

Angular::Angular(const Distance& radius)
        : Distance(radius), polar(), azimuthal() {

}

Angular::Angular(float radius, float azimuthal)
		: Distance(radius), polar(), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, float azimuthal)
		: Distance(radius, scaling), polar(), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, std::string unit, float azimuthal)
		: Distance(radius, scaling, unit), polar(), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, const Unit& unit, float azimuthal)
		: Distance(radius, scaling, unit), polar(), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, const Unit& unit,
        const Direction& azimuthal)
		: Distance(radius, scaling, unit), polar(), azimuthal(azimuthal) {

}

Angular::Angular(const Distance& radius, const Direction& azimuthal)
		: Distance(radius), polar(), azimuthal(azimuthal) {

}

Angular::Angular(float radius, float polar, float azimuthal)
		: Distance(radius), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(float radius, std::string unit, float polar, float azimuthal)
		: Distance(radius, unit), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(float radius, const Unit& unit, float polar, float azimuthal)
		: Distance(radius, unit), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, float polar, float azimuthal)
		: Distance(radius, scaling), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, std::string unit, float polar, float azimuthal)
		: Distance(radius, scaling, unit), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, const Unit& unit, float polar, float azimuthal)
		: Distance(radius, scaling, unit), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(float radius, short int scaling, const Unit& unit,
        const Direction& polar, const Direction& azimuthal)
		: Distance(radius, scaling, unit), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(const Direction& azimuthal)
		: Distance(), polar(), azimuthal(azimuthal) {

}

Angular::Angular(const Direction& polar, const Direction& azimuthal)
		: Distance(), polar(polar), azimuthal(azimuthal) {

}

Angular::Angular(const Distance& radius, const Direction& polar, const Direction& azimuthal)
		: Distance(radius), polar(polar), azimuthal(azimuthal) {

}

Angular::~Angular() {

}

bool Angular::operator==(const Angular& peer) const {
    return (static_cast<const Distance&>(*this) == static_cast<const Distance&>(peer))
            && (polar == peer.polar)
            && (azimuthal == peer.azimuthal);
}

Angular Angular::operator+(const Angular& peer) const {
    Distance newRadius = (getRadius() + peer.getRadius());
    Direction newPolar = (polar + peer.polar);
    Direction newAzimuthal = (azimuthal + peer.azimuthal);
    return Angular(newRadius, newPolar, newAzimuthal);
}

Angular Angular::operator-(const Angular& peer) const {
    Distance newRadius = (getRadius() - peer.getRadius());
    Direction newPolar = (polar - peer.polar);
    Direction newAzimuthal = (azimuthal - peer.azimuthal);
    return Angular(newRadius, newPolar, newAzimuthal);
}

Angular Angular::operator*(const Angular& peer) const {
    Distance newRadius = (getRadius() * peer.getRadius());
    Direction newPolar = (polar * peer.polar);
    Direction newAzimuthal = (azimuthal * peer.azimuthal);
    return Angular(newRadius, newPolar, newAzimuthal);
}

Angular Angular::operator/(const Angular& peer) const {
    Distance newRadius = (getRadius() / peer.getRadius());
    Direction newPolar = (polar / peer.polar);
    Direction newAzimuthal = (azimuthal / peer.azimuthal);
    return Angular(newRadius, newPolar, newAzimuthal);
}

Angular Angular::operator%(const Angular& peer) const {
    Distance newRadius = (getRadius() % peer.getRadius());
    Direction newPolar = (polar % peer.polar);
    Direction newAzimuthal = (azimuthal % peer.azimuthal);
    return Angular(newRadius, newPolar, newAzimuthal);
}

Quantity Angular::operator+(const Quantity& peer) const {
    Distance newRadius = (getRadius() + peer.getMagnitude());
    return Quantity(newRadius.getMagnitude(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator-(const Quantity& peer) const {
    Distance newRadius = (getRadius() - peer.getMagnitude());
    return Quantity(newRadius.getMagnitude(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator*(const Quantity& peer) const {
    Distance newRadius = (getRadius() * peer.getMagnitude());
    return Quantity(newRadius.getMagnitude(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator/(const Quantity& peer) const {
    Distance newRadius = (getRadius() / peer.getMagnitude());
    return Quantity(newRadius.getMagnitude(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator%(const Quantity& peer) const {
    Distance newRadius = (getRadius() % peer.getMagnitude());
    return Quantity(newRadius.getMagnitude(),
        newRadius.getScaling(), getRadius().getUnit());
}

Angular Angular::operator+(const Direction& peer) const {
    Direction newAzimuthal = (azimuthal + peer);
    return Angular(getRadius(), polar, newAzimuthal);
}

Angular Angular::operator-(const Direction& peer) const {
    Direction newAzimuthal = (azimuthal - peer);
    return Angular(getRadius(), polar, newAzimuthal);
}

Angular Angular::operator*(const Direction& peer) const {
    Direction newAzimuthal = (azimuthal * peer);
    return Angular(getRadius(), polar, newAzimuthal);
}

Angular Angular::operator/(const Direction& peer) const {
    Direction newAzimuthal = (azimuthal / peer);
    return Angular(getRadius(), polar, newAzimuthal);
}

Angular Angular::operator%(const Direction& peer) const {
    Direction newAzimuthal = (azimuthal % peer);
    return Angular(getRadius(), polar, newAzimuthal);
}

Quantity Angular::operator()(const Angular& peer,
        const Distance& separation, const Distance& position) const {
    Angular self = *this;
    Distance rx = position, ry = (separation - position);
    Quantity ax = self.getAzimuthalComponent(rx), ay = peer.getAzimuthalComponent(ry);
    Quantity result = (ax - ay); result.adjustScaling();
    return result;
}

Quantity Angular::operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this; float end = Quantity::DEFAULT_VALUE;
    Quantity azimX = (self(peerX, separationX, end) * cos(peerX.polar.toRadians()));
    Quantity azimY = (self(peerY, separationY, end) * cos(peerY.polar.toRadians()));
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    std::complex<float> polarized = std::sqrt(radial);
    shp::Quantity result((std::abs(polarized) * cos(self.polar.toRadians())),
            azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Distance Angular::getRadius() const {
    return this->getMagnitude();
}

void Angular::setRadius(const Distance& distance) {
    this->setMagnitude(distance.getMagnitude());
    this->setScaling(distance.getScaling());
}

Quantity Angular::getRelative(const Distance& location, const float angle) const {
    Angular self = *this; Distance radius = self.getRadius();
    Distance distance = (radius / (radius + location)); distance.adjustNumeric();
    Quantity coefficient = (distance.getComponent(angle) * distance.getComponent(angle));
    Quantity result((coefficient.getMagnitude()), getScaling(), getUnit());
    result.adjustScaling();
    return result;
}

Quantity Angular::getPolarComponent(const Distance& location) const {
    return getRelative(location, this->polar.toRadians());
}

Quantity Angular::getAzimuthalComponent(const Distance& location) const {
    return getRelative(location, this->azimuthal.toRadians());
}

Distance Angular::copy() {
    Angular fresh(getRadius(), polar, azimuthal);
    return fresh;
}

void Angular::clear() {
    Distance::clear();
    polar.clear();
    azimuthal.clear();
    return;
}

std::string Angular::print() {
    std::stringstream result;
    result << "{r:";
    result << Distance::print() << ",𝜃:";
    result << polar.print() << ",𝜙:";
    result << azimuthal.print() << "}";
	return result.str();
}

} // namespace shp