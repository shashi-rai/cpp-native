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

const float Angular::DEFAULT_RADIUS = 0.0f;
const float Angular::DEFAULT_POLARITY = 0.0f;
const float Angular::DEFAULT_AZIMUTH = 0.0f;

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
    Distance newRadius = (getRadius() + peer.getValue());
    return Quantity(newRadius.getMagnitude().getValue(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator-(const Quantity& peer) const {
    Distance newRadius = (getRadius() - peer.getValue());
    return Quantity(newRadius.getMagnitude().getValue(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator*(const Quantity& peer) const {
    Distance newRadius = (getRadius() * peer.getValue());
    return Quantity(newRadius.getMagnitude().getValue(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator/(const Quantity& peer) const {
    Distance newRadius = (getRadius() / peer.getValue());
    return Quantity(newRadius.getMagnitude().getValue(),
        newRadius.getScaling(), getRadius().getUnit());
}

Quantity Angular::operator%(const Quantity& peer) const {
    Distance newRadius = (getRadius() % peer.getValue());
    return Quantity(newRadius.getMagnitude().getValue(),
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
    Quantity ax = self.getRelative(rx), ay = peer.getRelative(ry);
    Quantity result = (ax - ay);
    result.adjustScaling();
    return result;
}

Quantity Angular::operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Angular self = *this;
    Distance radiusX = (self.getRadius() + peerX.getRadius());
    Distance totalX = (radiusX + separationX.getMagnitude());
    Distance radiusY = (self.getRadius() + peerY.getRadius());
    Distance totalY = (radiusY + separationY.getMagnitude());
    Distance hx = (totalY * cos(self.azimuthal.toRadians()));
    //Distance hy = (totalY * sin(self.azimuthal.toRadians()));
    Distance r0 = hx, rx = (separationX - hx);
    Quantity a0 = self.getRelative((r0 - self.getRadius()));
    Quantity ax = peerX.getRelative((rx - peerX.getRadius()));    
    Quantity result = (a0 - ax);
    result.adjustScaling();
    return result;
}

Distance Angular::getRadius() const {
    return this->getMagnitude();
}

void Angular::setRadius(const Distance& distance) {
    this->setMagnitude(distance.getMagnitude());
}

Quantity Angular::getRelative(const Distance& location) const {
    Angular self = *this;
    Distance radius = self.getRadius();
    Distance distance = (radius / (radius + location));
    Distance coefficient = (distance * distance);
    Quantity result((coefficient.getMagnitude().getValue()), getScaling(), getUnit());
    result.adjustScaling();
    return result;
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