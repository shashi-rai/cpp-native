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
    : Quantity(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Distance::Distance(const std::string unit)
    : Quantity(unit) {

}

Distance::Distance(const Unit& unit)
    : Quantity(unit) {

}

Distance::Distance(const float length)
    : Quantity(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Distance::Distance(const float length, const std::string unit)
    : Quantity(length, unit) {

}

Distance::Distance(const float length, const Unit& unit)
    : Quantity(length, unit) {

}

Distance::Distance(const float length, const short int scaling)
    : Quantity(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit)
    : Quantity(length, scaling, unit) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit)
    : Quantity(length, scaling, unit) {

}

Distance::~Distance() {

}

bool Distance::operator==(const Distance& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer));
}

Distance Distance::operator+(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self + other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator-(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator*(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self * other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator/(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self / other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator%(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self % other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit());
}

Quantity Distance::getTotal() const {
    return Quantity(getMagnitude(), getScaling(), getUnit());
}

Distance Distance::copy() {
    Distance fresh(getMagnitude(), getScaling(), getUnit());
    return fresh;
}

void Distance::clear() {
    Quantity::clear();
    return;
}

std::string Distance::print() {
    std::stringstream result;
    result << Quantity::print();
	return result.str();
}

Quantity Distance::getComponent(float phase) const {
    Quantity length = getTotal();
    return Quantity((length.getMagnitude() * cos(phase)), length.getScaling(), length.getUnit());
}

} // namespace shp