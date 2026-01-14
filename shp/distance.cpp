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

Distance Distance::operator()(const Distance& peer) const {
    Distance self = *this;
    Quantity radial = (self.getRadial() + peer.getRadial());
    Distance result(radial.getMagnitude(), radial.getScaling(), self.getUnit(), change);
    result.adjustScaling();
    return result;
}

Distance Distance::getFactorX(const Distance& peer) const {
    Distance self = *this;
    Quantity radial = (self.getRadialX() + peer.getRadialX());
    Distance result(radial.getMagnitude(), radial.getScaling(), self.getUnit(), change);
    result.adjustScaling();
    return result;
}

Distance Distance::getFactorY(const Distance& peer) const {
    Distance self = *this;
    Quantity radial = (self.getRadialY() + peer.getRadialY());
    Distance result(radial.getMagnitude(), radial.getScaling(), self.getUnit(), change);
    result.adjustScaling();
    return result;
}

Quantity Distance::getTotal() const {
    Quantity self = *this;
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit());
}

Quantity Distance::getRadial() const {
    Distance self = *this;
    Quantity radial = (self.getSquareX() + self.getSquareY()).getSquareRoot();
    Quantity result(radial.getMagnitude(), radial.getScaling(), self.getUnit());
    return result;
}

Quantity Distance::getRadialX() const {
    Distance self = *this; Quantity radial = self.getRadial();
    float length = radial.getCosComponent(change.toRadians());
    return Quantity(length, radial.getScaling(), radial.getUnit());
}

Quantity Distance::getRadialY() const {
    Distance self = *this; Quantity radial = self.getRadial();
    float length = radial.getSinComponent(change.toRadians());
    return Quantity(length, radial.getScaling(), radial.getUnit());
}

Quantity Distance::getSquareX() const {
    Distance self = *this; float angle = change.toRadians();
    float length = (self.getCosComponent(angle) * self.getCosComponent(angle));
    short int scaling = (self.getScaling() + self.getScaling());
    Quantity result(length, scaling, self.getUnit());
    return result;
}

Quantity Distance::getSquareY() const {
    Distance self = *this; float angle = change.toRadians();
    float length = (self.getSinComponent(angle) * self.getSinComponent(angle));
    short int scaling = (self.getScaling() + self.getScaling());
    Quantity result(length, scaling, self.getUnit());
    return result;
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

std::string Distance::print() {
    std::stringstream result;
    result << Quantity::print() << "δ";
    result << change.print();
	return result.str();
}

} // namespace shp