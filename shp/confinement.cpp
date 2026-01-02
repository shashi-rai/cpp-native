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
        : Potential(Quantity::DEFAULT_VALUE, high) {

}

Confinement::Confinement(const float high, const Angular& closure)
        : Potential(Quantity::DEFAULT_VALUE, high, closure) {
}

Confinement::Confinement(const float high, const float low)
        : Potential(low, high) {

}

Confinement::Confinement(const float high, const float low, const Angular& closure)
        : Potential(low, high, closure) {

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
        : Potential(Quantity::DEFAULT_VALUE, high, unit, closure) {

}

Confinement::Confinement(const float high, const float low, const std::string unit)
        : Potential(low, high, unit) {

}

Confinement::Confinement(const float high, const float low, const std::string unit, const Angular& closure)
        : Potential(low, high, unit, closure) {

}

Confinement::Confinement(const float high, const float low, const Unit& unit)
        : Potential(low, high, unit) {

}

Confinement::Confinement(const float high, const float low, const Unit& unit, const Angular& closure)
        : Potential(low, high, unit, closure) {

}

Confinement::Confinement(const float high, const float low, const short int scaling)
        : Potential(low, high, scaling) {

}

Confinement::Confinement(const float high, const float low, const short int scaling, const std::string unit)
        : Potential(low, high, scaling, unit) {

}

Confinement::Confinement(const float high, const float low, const short int scaling, const Unit& unit)
        : Potential(low, high, scaling, unit) {

}

Confinement::Confinement(const float high, const float low, const short int scaling, const Unit& unit,
        const Angular& closure)
        : Potential(low, high, scaling, unit, closure) {

}

Confinement::~Confinement() {

}

bool Confinement::operator==(const Confinement& peer) const {
    return (static_cast<const Potential&>(*this) == static_cast<const Potential&>(peer));
}

Confinement Confinement::operator+(const Confinement& peer) const {
    float newhigh = (getHigh() + (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    float newlow = (getLow() + (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    return Confinement(newlow, newhigh, getScaling(), getUnit());
}

Confinement Confinement::operator-(const Confinement& peer) const {
    float newhigh = (getHigh() - (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    float newlow = (getLow() - (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    return Confinement(newlow, newhigh, getScaling(), getUnit());
}

Confinement Confinement::operator*(const Confinement& peer) const {
    float newhigh = (getHigh() * peer.getHigh());
    float newlow = (getLow() * peer.getLow());
    return Confinement(newlow, newhigh, (getScaling() + peer.getScaling()), getUnit());
}

Confinement Confinement::operator/(const Confinement& peer) const {
    float newhigh = (getHigh() / peer.getHigh());
    float newlow = (getLow() / peer.getLow());
    return Confinement(newlow, newhigh, (getScaling() - peer.getScaling()), getUnit());
}

Confinement Confinement::operator%(const Confinement& peer) const {
    float newhigh = fmod(getHigh(), (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    float newlow = fmod(getLow(), (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    return Confinement(newlow, newhigh, getScaling(), getUnit());
}

Quantity Confinement::operator()(const Confinement& peer,
        const Distance& separation, const Distance& position) const {
    Confinement self = *this; float distribution = (getHigh() - getLow());
    shp::Angular closure = self.getClosure();
    Quantity coefficient = (closure(peer.getClosure(), separation, position) * distribution);
    Quantity result(coefficient.getMagnitude(), getScaling(), getUnit()); result.adjustScaling();
    return result;
}

Quantity Confinement::operator()(const Confinement& peerX, const Confinement& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Confinement self = *this; float distribution = (getHigh() - getLow());
    shp::Angular closure = self.getClosure();
    Quantity coefficient = (closure(peerX.getClosure(), peerY.getClosure(), separationX, separationY) * distribution);
    Quantity result(coefficient.getMagnitude(), getScaling(), getUnit()); result.adjustScaling();
    return result;
}

Direction Confinement::getPolar() const {
    return this->getOrigin().getPolar();
}

void Confinement::setPolar(const Direction& angle) {
    this->getOrigin().setPolar(angle);
}

Direction Confinement::getAzimuthal() const {
    return this->getOrigin().getAzimuthal();
}

void Confinement::setAzimuthal(const Direction& angle) {
    this->getOrigin().setAzimuthal(angle);
}

Quantity Confinement::getDifference() const {
    Quantity result((getHigh() - getLow()), getScaling(), getUnit());
    return result;
}

Quantity Confinement::getRelative(const Distance& location, const float angle) const {
    Confinement self = *this; float distribution = (getHigh() - getLow());
    shp::Angular closure = this->getClosure();
    Quantity coefficient = (closure.getRelative(location, angle) * distribution);
    Quantity result(coefficient.getMagnitude(), getScaling(), getUnit()); result.adjustScaling();
    return result;
}

Quantity Confinement::getPolarComponent(const Distance& location) const {
    shp::Angular closure = this->getClosure();
    return getRelative(location, closure.getPolar().toRadians());
}

Quantity Confinement::getAzimuthalComponent(const Distance& location) const {
    shp::Angular closure = this->getClosure();
    return getRelative(location, closure.getAzimuthal().toRadians());
}

Confinement Confinement::copy() {
    Confinement fresh(getHigh(), getLow(), getScaling(), getUnit());
    return fresh;
}

void Confinement::clear() {
    Potential::clear();
    return;
}

std::string Confinement::print() {
    std::stringstream result;
    result << Potential::print();
	return result.str();
}

} // namespace shp