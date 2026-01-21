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

#include "distance.h"

namespace shp {

const std::string Distance::UNIT = "m";     // System International

Distance::Distance()
        : Quantity(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const std::string unit)
        : Quantity(unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Unit& unit)
        : Quantity(unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length)
        : Quantity(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const std::string unit)
        : Quantity(length, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const Unit& unit)
        : Quantity(length, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling)
        : Quantity(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit)
        : Quantity(length, scaling, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit)
        : Quantity(length, scaling, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Direction& change)
        : Quantity(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), change(change) {

}

Distance::Distance(const std::string unit, const Direction& change)
        : Quantity(unit), change(change) {

}

Distance::Distance(const Unit& unit, const Direction& change)
        : Quantity(unit), change(change) {

}

Distance::Distance(const float length, const Direction& change)
        : Quantity(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), change(change) {

}

Distance::Distance(const float length, const std::string unit, const Direction& change)
        : Quantity(length, unit), change(change) {

}

Distance::Distance(const float length, const Unit& unit, const Direction& change)
        : Quantity(length, unit), change(change) {

}

Distance::Distance(const float length, const short int scaling, const Direction& change)
        : Quantity(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), change(change) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit,
        const Direction& change)
        : Quantity(length, scaling, unit), change(change) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const Direction& change)
        : Quantity(length, scaling, unit), change(change) {

}

Distance::~Distance() {

}

bool Distance::operator==(const Distance& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (change == peer.change);
}

bool Distance::operator<(const Distance& peer) const {
    return (static_cast<const Quantity&>(*this) < static_cast<const Quantity&>(peer))
        && (change < peer.change);
}

bool Distance::operator>(const Distance& peer) const {
    return (static_cast<const Quantity&>(*this) > static_cast<const Quantity&>(peer))
        && (change > peer.change);
}

bool Distance::operator<=(const Distance& peer) const {
    Distance self = *this;
    return (self < peer) || (self == peer);
}

bool Distance::operator>=(const Distance& peer) const {
    Distance self = *this;
    return (self > peer) || (self == peer);
}

Distance Distance::operator+(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self + other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator-(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator*(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self * other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator/(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self / other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator%(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self % other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator+(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change + rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator-(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change - rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator*(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change * rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator/(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change / rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator%(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change % rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator()(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Direction poi(Direction::DEFAULT_RADIANS);
    Quantity radial = (self.getRadial(poi) + peer.getRadial(elevation));
    Distance result(radial.getMagnitude(),
        radial.getScaling(), self.getUnit(), self.getDeviation(elevation));
    result.adjustScaling();
    return result;
}

Direction Distance::getDeviation(const Direction& elevation) const {
    return Direction(change.getDegrees(), change.getMinutes(), change.getSeconds());
}

Distance Distance::getFactorX(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getDiffusionX(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getFactorY(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getDiffusionY(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getFactorZ(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getDiffusionZ(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getTotal() const {
    Quantity self = *this;
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), this->change);
}

Quantity Distance::getRadial(const Direction& elevation) const {
    Distance self = *this;
    Quantity sumtotal = self.getSquareX(change) + self.getSquareY(change) + self.getSquareZ(elevation);
    Quantity diagonal = sumtotal.getSquareRoot();
    Quantity result(diagonal.getMagnitude(),
        diagonal.getScaling(), self.getUnit()); result.adjustScaling();
    return result;
}

Quantity Distance::getRadialX(const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getDiffusionX(0, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getRadialY(const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getDiffusionY(0, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getRadialZ(const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getDiffusionZ(0, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getSquareX(const Direction& elevation) const {
    return getRadialX(elevation).getSquare();
}

Quantity Distance::getSquareY(const Direction& elevation) const {
    return getRadialY(elevation).getSquare();
}

Quantity Distance::getSquareZ(const Direction& elevation) const {
    return getRadialZ(elevation).getSquare();
}

Distance Distance::copy() {
    Distance self = *this;
    Distance fresh(self.getMagnitude(), self.getScaling(), self.getUnit(), self.change);
    return fresh;
}

void Distance::clear() {
    Quantity::clear();
    change.clear();
    return;
}

std::string Distance::print() const {
    std::stringstream result;
    result << Quantity::print() << "δ";
    result << change.print();
	return result.str();
}

std::string Distance::printRadians() const {
    std::stringstream result;
    result << Quantity::print() << "δ";
    result << change.printRadians();
	return result.str();
}

float Distance::getDiffusion(const Distance& peer, const Direction& elevation) const {
    float y_component = peer.getSinComponent(peer.change.toRadians());
    float z_component = peer.getCosComponent(elevation.toRadians());
    float diffusion = std::sqrt((y_component * y_component) + (z_component * z_component));
    return diffusion;
}

Quantity Distance::getDiffusionX(const Distance& peer, const Direction& elevation) const {
    Quantity self = *this;
    Quantity diffusion(getDiffusion(peer, elevation), self.getScaling(), self.getUnit());
    Quantity result = (self + diffusion.getCosComponent(change.toRadians()));
    result.adjustScaling();
    return result;
}

Quantity Distance::getDiffusionY(const Distance& peer, const Direction& elevation) const {
    Quantity self = *this;
    Quantity diffusion(getDiffusion(peer, elevation), peer.getScaling(), peer.getUnit());
    Quantity result = self.getFraction(diffusion.getSinComponent(peer.change.toRadians()));
    result.adjustScaling();
    return result;
}

Quantity Distance::getDiffusionZ(const Distance& peer, const Direction& elevation) const {
    Distance self = *this;
    Quantity diffusion(getDiffusion(peer, elevation), peer.getScaling(), peer.getUnit());
    Quantity result = self.getFraction(diffusion.getSinComponent(elevation.toRadians()));
    result.adjustScaling();
    return result;
}

} // namespace shp