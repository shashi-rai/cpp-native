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
        : Quantity(), low(), radius() {

}

Potential::Potential(const Distance& radius)
        : Quantity(), low(), radius(radius) {

}

Potential::Potential(float high)
        : Quantity(high), low(), radius() {

}

Potential::Potential(float high, const Distance& radius)
        : Quantity(high), low(), radius(radius) {
}

Potential::Potential(float high, float low)
        : Quantity(high), low(low), radius() {

}

Potential::Potential(float high, float low, const Distance& radius)
        : Quantity(high), low(low), radius(radius) {

}

Potential::Potential(const std::string unit)
    : Quantity(unit), low(), radius() {

}

Potential::Potential(const Unit& unit)
    : Quantity(unit), low(), radius() {
}

Potential::Potential(const Unit& unit, const Distance& radius)
    : Quantity(unit), low(), radius(radius) {
}

Potential::Potential(short int scaling, const std::string unit)
    : Quantity(scaling, unit), low(), radius() {

}

Potential::Potential(short int scaling, const Unit& unit)
    : Quantity(scaling, unit), low(), radius() {

}

Potential::Potential(short int scaling, const Unit& unit, const Distance& radius)
    : Quantity(scaling, unit), low(), radius(radius) {

}

Potential::Potential(float high, const std::string unit, const Distance& radius)
        : Quantity(high, unit), low(), radius(radius) {

}

Potential::Potential(float high, float low, const std::string unit)
        : Quantity(high, unit), low(low), radius() {

}

Potential::Potential(float high, float low, const std::string unit, const Distance& radius)
        : Quantity(high, unit), low(low), radius(radius) {

}

Potential::Potential(float high, float low, const Unit& unit)
        : Quantity(high, unit), low(low), radius() {

}

Potential::Potential(float high, float low, const Unit& unit, const Distance& radius)
        : Quantity(high, unit), low(low), radius(radius) {

}

Potential::Potential(float high, float low, short int scaling)
        : Quantity(high, scaling), low(low), radius() {

}

Potential::Potential(float high, float low, short int scaling, const std::string unit)
        : Quantity(high, scaling, unit), low(low), radius() {

}

Potential::Potential(float high, float low, short int scaling, const Unit& unit)
        : Quantity(high, scaling, unit), low(low), radius() {

}

Potential::Potential(float high, float low, short int scaling, const Unit& unit,
        const Distance& radius)
        : Quantity(high, scaling, unit), low(low), radius(radius) {

}

Potential::~Potential() {

}

bool Potential::operator==(const Potential& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (low == peer.low) && (radius == peer.radius);
}

Potential Potential::operator+(const Potential& peer) const {
    float newhigh = (getHigh() + (peer.getHigh() / std::pow(10, (getScaling() - peer.getScaling()))));
    float newlow = (getLow() + (peer.getLow() / std::pow(10, (getScaling() - peer.getScaling()))));
    return Potential(newhigh, newlow, getScaling(), getUnit());
}

Potential Potential::operator-(const Potential& peer) const {
    float newhigh = (getHigh() - (peer.getHigh() / std::pow(10, (getScaling() - peer.getScaling()))));
    float newlow = (getLow() - (peer.getLow() / std::pow(10, (getScaling() - peer.getScaling()))));
    return Potential(newhigh, newlow, getScaling(), getUnit());
}

Potential Potential::operator*(const Potential& peer) const {
    float newhigh = (getHigh() * peer.getHigh());
    float newlow = (getLow() * peer.getLow());
    return Potential(newhigh, newlow, (getScaling() + peer.getScaling()), getUnit());
}

Potential Potential::operator/(const Potential& peer) const {
    float newhigh = (getHigh() / peer.getHigh());
    float newlow = (getLow() / peer.getLow());
    return Potential(newhigh, newlow, (getScaling() - peer.getScaling()), getUnit());
}

Potential Potential::operator%(const Potential& peer) const {
    float newhigh = fmod(getHigh(), (peer.getHigh() / std::pow(10, (getScaling() - peer.getScaling()))));
    float newlow = fmod(getLow(), (peer.getLow() / std::pow(10, (getScaling() - peer.getScaling()))));
    return Potential(newhigh, newlow, getScaling(), getUnit());
}

Quantity Potential::operator()(const Potential& peer,
        const Distance& separation, const Distance& position) const {
    Potential self = *this, other = peer;
    Distance x = position, y = (separation - position);
    Quantity px = self.getRelative(x), py = other.getRelative(y);
    Quantity result = (px - py);
    result.adjustScaling();
    return result;
}

Quantity Potential::getDifference() const {
    Quantity result((getHigh() - getLow()), getScaling(), getUnit());
    return result;
}

Quantity Potential::getRelative(const Distance& location) const {
    float distribution = (getHigh() - getLow());
    Distance distance = (radius / (radius + location));
    Distance coefficient = (distance * distance);
    Quantity result((coefficient.getMagnitude().getValue() * distribution), getScaling(), getUnit());
    result.adjustScaling();
    return result;
}

Potential Potential::copy() {
    Potential fresh(getHigh(), getLow(), getScaling(), getUnit());
    return fresh;
}

void Potential::clear() {
    low = Quantity::DEFAULT_VALUE;
    return;
}

std::string Potential::print() {
    std::stringstream result;
    result << radius.print() << ",(";
    result << getHigh() << "~";
    result << getLow() << ")x10^";
    result << getScaling();
    result << getUnit().print();
	return result.str();
}

} // namespace shp