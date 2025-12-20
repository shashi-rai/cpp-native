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
    : magnitude(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Distance::Distance(const std::string unit)
    : magnitude(unit) {

}

Distance::Distance(const Unit& unit)
    : magnitude(unit) {

}

Distance::Distance(const float magnitude)
    : magnitude(magnitude, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Distance::Distance(const float magnitude, const std::string unit)
    : magnitude(magnitude, unit) {

}

Distance::Distance(const float magnitude, const Unit& unit)
    : magnitude(magnitude, unit) {

}

Distance::Distance(const float magnitude, short int scaling)
    : magnitude(magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Distance::Distance(const float magnitude, short int scaling, const std::string unit)
    : magnitude(magnitude, scaling, unit) {

}

Distance::Distance(const float magnitude, short int scaling, const Unit& unit)
    : magnitude(magnitude, scaling, unit) {

}

Distance::Distance(const Quantity& length) : magnitude(length) {

}

Distance::~Distance() {

}

bool Distance::operator==(const Distance& peer) const {
    return (magnitude == peer.magnitude);
}

Distance Distance::operator+(const Distance& peer) const {
    Quantity distance = (magnitude + peer.magnitude);
    return Distance(distance.getValue(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator-(const Distance& peer) const {
    Quantity distance = (magnitude - peer.magnitude);
    return Distance(distance.getValue(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator*(const Distance& peer) const {
    Quantity distance = (magnitude * peer.magnitude);
    return Distance(distance.getValue(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator/(const Distance& peer) const {
    Quantity distance = (magnitude / peer.magnitude);
    return Distance(distance.getValue(), distance.getScaling(), distance.getUnit());
}

Distance Distance::operator%(const Distance& peer) const {
    Quantity distance = (magnitude % peer.magnitude);
    return Distance(distance.getValue(), distance.getScaling(), distance.getUnit());
}

Quantity Distance::getTotal() const {
    return Quantity(magnitude.getValue(), magnitude.getScaling(), magnitude.getUnit());
}

short int Distance::getScaling() const {
    return magnitude.getScaling();
}

std::string Distance::getUnit() const {
    return magnitude.getUnit().getName();
}

void Distance::adjustNumeric() {
    magnitude.adjustNumeric();
}

void Distance::adjustScaling() {
    magnitude.adjustScaling();
}

Distance Distance::copy() {
    Distance fresh(magnitude.getValue(), magnitude.getScaling(), magnitude.getUnit());
    return fresh;
}

void Distance::clear() {
    magnitude.clear();
    return;
}

std::string Distance::print() {
    std::stringstream result;
    result << magnitude.print();
	return result.str();
}

Quantity Distance::getComponent(float phase) const {
    Quantity length = getTotal();
    return Quantity((length.getValue() * cos(phase)), length.getScaling(), length.getUnit());
}

} // namespace shp