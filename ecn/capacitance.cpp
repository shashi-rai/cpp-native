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

#include "capacitance.h"

namespace ecn {

const std::string Capacitance::UNIT = "F";

Capacitance::Capacitance()
        : shp::Quantity(UNIT), positive(), negative() {

}

Capacitance::Capacitance(const Conductor& positive, const Conductor& negative)
        : shp::Quantity(UNIT), positive(positive), negative(negative) {

}

Capacitance::Capacitance(const float magnitude)
        : shp::Quantity(magnitude, UNIT), positive(), negative() {

}

Capacitance::Capacitance(const short int scaling)
        : shp::Quantity(scaling, UNIT), positive(), negative() {

}

Capacitance::Capacitance(const std::string unit)
        : shp::Quantity(unit), positive(), negative() {

}

Capacitance::Capacitance(const short int scaling, const std::string unit)
        : shp::Quantity(scaling, unit), positive(), negative() {

}

Capacitance::Capacitance(const shp::Unit& unit)
        : shp::Quantity(unit), positive(), negative() {

}

Capacitance::Capacitance(const short int scaling, const shp::Unit& unit)
        : shp::Quantity(scaling, unit), positive(), negative() {

}

Capacitance::Capacitance(const float magnitude, const std::string unit)
        : shp::Quantity(magnitude, unit), positive(), negative() {

}

Capacitance::Capacitance(const float magnitude, const shp::Unit& unit)
        : shp::Quantity(magnitude, unit), positive(), negative() {

}

Capacitance::Capacitance(const float magnitude, const short int scaling)
        : shp::Quantity(magnitude, scaling, UNIT), positive(), negative() {

}

Capacitance::Capacitance(const float magnitude, const short int scaling, const std::string unit)
        : shp::Quantity(magnitude, scaling, unit), positive(), negative() {

}

Capacitance::Capacitance(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(magnitude, scaling, unit), positive(), negative() {

}

Capacitance::Capacitance(const float magnitude, const short int scaling, const shp::Unit& unit,
        const Conductor& positive, const Conductor& negative)
        : shp::Quantity(magnitude, scaling, unit), positive(positive), negative(negative) {

}

Capacitance::~Capacitance() {

}

bool Capacitance::operator==(const Capacitance& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (positive == peer.positive) && (negative == peer.negative);
}

Capacitance Capacitance::operator+(const Capacitance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity capacitance = (self + other);
    return Capacitance(capacitance.getMagnitude(), capacitance.getScaling(), capacitance.getUnit(),
        (positive + peer.positive), (negative + peer.negative));
}

Capacitance Capacitance::operator-(const Capacitance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity capacitance = (self - other);
    return Capacitance(capacitance.getMagnitude(), capacitance.getScaling(), capacitance.getUnit(),
        (positive - peer.positive), (negative - peer.negative));
}

Capacitance Capacitance::operator*(const Capacitance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity capacitance = (self * other);
    return Capacitance(capacitance.getMagnitude(), capacitance.getScaling(), capacitance.getUnit(),
        (positive * peer.positive), (negative * peer.negative));
}

Capacitance Capacitance::operator/(const Capacitance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity capacitance = (self / other);
    return Capacitance(capacitance.getMagnitude(), capacitance.getScaling(), capacitance.getUnit(),
        (positive / peer.positive), (negative / peer.negative));
}

Capacitance Capacitance::operator%(const Capacitance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity capacitance = (self % other);
    return Capacitance(capacitance.getMagnitude(), capacitance.getScaling(), capacitance.getUnit(),
        (positive % peer.positive), (negative % peer.negative));
}

shp::Potential Capacitance::getThreshold() const {
	shp::Temporal charge = (positive.getCharge() - negative.getCharge());
	short int scaling = charge.getScaling();
    shp::Potential fresh(positive.getCharge().getMagnitude(), negative.getCharge().getMagnitude(),
		scaling, shp::Unit::getDerivedSymbol(shp::Unit::CAPACITANCE));
    return fresh;
}

Capacitance Capacitance::copy() {
    Capacitance fresh(getMagnitude(), getScaling(), getUnit(), positive, negative);
    return fresh;
}

void Capacitance::clear() {
    shp::Quantity::clear();
    positive.clear();
    negative.clear();
    return;
}

std::string Capacitance::print() {
    std::stringstream result;
    result << shp::Quantity::print() << ",+:";
    result << positive.print() << ",-:";
    result << negative.print();
	return result.str();
}

} // namespace ecn