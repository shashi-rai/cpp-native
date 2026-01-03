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
        : Potential() {

}

Growth::Growth(const shp::Angular& closure)
        : Potential(closure) {

}

Growth::Growth(const float high)
        : Potential(Quantity::DEFAULT_VALUE, high) {

}

Growth::Growth(const float high, const shp::Angular& closure)
        : Potential(Quantity::DEFAULT_VALUE, high, closure) {
}

Growth::Growth(const float high, const float low)
        : Potential(low, high) {

}

Growth::Growth(const float high, const float low, const shp::Angular& closure)
        : Potential(low, high, closure) {

}

Growth::Growth(const std::string unit)
        : Potential(unit) {

}

Growth::Growth(const shp::Unit& unit)
        : Potential(unit) {
}

Growth::Growth(const shp::Unit& unit, const shp::Angular& closure)
        : Potential(unit, closure) {
}

Growth::Growth(const short int scaling, const std::string unit)
        : Potential(scaling, unit) {

}

Growth::Growth(const short int scaling, const shp::Unit& unit)
        : Potential(scaling, unit) {

}

Growth::Growth(const short int scaling, const shp::Unit& unit, const shp::Angular& closure)
        : Potential(scaling, unit, closure) {

}

Growth::Growth(const float high, const std::string unit, const shp::Angular& closure)
        : Potential(Quantity::DEFAULT_VALUE, high, unit, closure) {

}

Growth::Growth(const float high, const float low, const std::string unit)
        : Potential(low, high, unit) {

}

Growth::Growth(const float high, const float low, const std::string unit, const shp::Angular& closure)
        : Potential(low, high, unit, closure) {

}

Growth::Growth(const float high, const float low, const shp::Unit& unit)
        : Potential(low, high, unit) {

}

Growth::Growth(const float high, const float low, const shp::Unit& unit, const shp::Angular& closure)
        : Potential(low, high, unit, closure) {

}

Growth::Growth(const float high, const float low, const short int scaling)
        : Potential(low, high, scaling) {

}

Growth::Growth(const float high, const float low, const short int scaling, const std::string unit)
        : Potential(low, high, scaling, unit) {

}

Growth::Growth(const float high, const float low, const short int scaling, const shp::Unit& unit)
        : Potential(low, high, scaling, unit) {

}

Growth::Growth(const float high, const float low, const short int scaling, const shp::Unit& unit,
        const shp::Angular& closure)
        : Potential(low, high, scaling, unit, closure) {

}

Growth::~Growth() {

}

bool Growth::operator==(const Growth& peer) const {
    return (static_cast<const Potential&>(*this) == static_cast<const Potential&>(peer));
}

Growth Growth::operator+(const Growth& peer) const {
    float newhigh = (getHigh() + (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    float newlow = (getLow() + (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    return Growth(newlow, newhigh, getScaling(), getUnit());
}

Growth Growth::operator-(const Growth& peer) const {
    float newhigh = (getHigh() - (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    float newlow = (getLow() - (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    return Growth(newlow, newhigh, getScaling(), getUnit());
}

Growth Growth::operator*(const Growth& peer) const {
    float newhigh = (getHigh() * peer.getHigh());
    float newlow = (getLow() * peer.getLow());
    return Growth(newlow, newhigh, (getScaling() + peer.getScaling()), getUnit());
}

Growth Growth::operator/(const Growth& peer) const {
    float newhigh = (getHigh() / peer.getHigh());
    float newlow = (getLow() / peer.getLow());
    return Growth(newlow, newhigh, (getScaling() - peer.getScaling()), getUnit());
}

Growth Growth::operator%(const Growth& peer) const {
    float newhigh = fmod(getHigh(), (peer.getHigh() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    float newlow = fmod(getLow(), (peer.getLow() / std::pow(Quantity::DECIMAL_SCALE, (getScaling() - peer.getScaling()))));
    return Growth(newlow, newhigh, getScaling(), getUnit());
}

shp::Quantity Growth::operator()(const Growth& peer,
        const shp::Distance& separation, const shp::Distance& position) const {
    Growth self = *this; float distribution = (getHigh() - getLow());
    shp::Angular closure = self.getClosure();
    Quantity coefficient = (closure(peer.getClosure(), separation, position) * distribution);
    Quantity result(coefficient.getMagnitude(), getScaling(), getUnit()); result.adjustScaling();
    return result;
}

shp::Quantity Growth::operator()(const Growth& peerX, const Growth& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const {
    Growth self = *this; float distribution = (getHigh() - getLow());
    shp::Angular closure = self.getClosure();
    Quantity coefficient = (closure(peerX.getClosure(), peerY.getClosure(), separationX, separationY) * distribution);
    Quantity result(coefficient.getMagnitude(), getScaling(), getUnit()); result.adjustScaling();
    return result;
}

shp::Direction Growth::getPolar() const {
    return this->getOrigin().getPolar();
}

void Growth::setPolar(const shp::Direction& angle) {
    this->getOrigin().setPolar(angle);
}

shp::Direction Growth::getAzimuthal() const {
    return this->getOrigin().getAzimuthal();
}

void Growth::setAzimuthal(const shp::Direction& angle) {
    this->getOrigin().setAzimuthal(angle);
}

shp::Quantity Growth::getDifference() const {
    Quantity result((getHigh() - getLow()), getScaling(), getUnit());
    return result;
}

shp::Quantity Growth::getRelative(const shp::Distance& location, const float angle) const {
    Growth self = *this; float distribution = (getHigh() - getLow());
    shp::Angular closure = this->getClosure();
    Quantity coefficient = (closure.getRelative(location, angle) * distribution);
    Quantity result(coefficient.getMagnitude(), getScaling(), getUnit()); result.adjustScaling();
    return result;
}

shp::Quantity Growth::getPolarComponent(const shp::Distance& location) const {
    shp::Angular closure = this->getClosure();
    return getRelative(location, closure.getPolar().toRadians());
}

shp::Quantity Growth::getAzimuthalComponent(const shp::Distance& location) const {
    shp::Angular closure = this->getClosure();
    return getRelative(location, closure.getAzimuthal().toRadians());
}

Growth Growth::copy() {
    Growth fresh(getHigh(), getLow(), getScaling(), getUnit());
    return fresh;
}

void Growth::clear() {
    Potential::clear();
    return;
}

std::string Growth::print() {
    std::stringstream result;
    result << Potential::print();
	return result.str();
}

} // namespace eco