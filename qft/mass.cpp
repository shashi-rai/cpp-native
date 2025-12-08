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

#include "mass.h"

namespace qft {

const std::string Mass::UNIT = shp::Unit::getBaseSymbol(shp::Unit::MASS);
const short int Mass::ATOMIC_SCALE = -27;   // 10^-27 kg
const float Mass::ATOMIC_UNIT = 1.6605f;    // 1.6605 x 10^-27 kg
const float Mass::PROTON = 1.672621027f;    // 1.67 x 10^-27 kg
const float Mass::NEUTRON = 1.67492749804f; // 1.67 x 10^-27 kg
const float Mass::ELECTRON = 0.0009109f;    // 0.0009109 x 10^-27 kg

Mass::Mass() : quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, UNIT) {

}

Mass::Mass(float quantity) : quantity(quantity, ATOMIC_SCALE, UNIT) {

}

Mass::Mass(float quantity, short int scaling) : quantity(quantity, scaling, UNIT) {

}

Mass::Mass(float quantity, const shp::Unit& unit)
        : quantity(quantity, ATOMIC_SCALE, unit) {

}

Mass::Mass(float quantity, short int scaling, const shp::Unit& unit)
        : quantity(quantity, scaling, unit) {

}

Mass::Mass(const shp::Quantity& quantity, const shp::Unit& unit) : quantity(unit) {

}

Mass::~Mass() {

}

bool Mass::operator==(const Mass& peer) const {
    return (quantity == peer.quantity);
}

Mass Mass::operator+(const Mass& peer) const {
    return Mass((quantity + peer.quantity), quantity.getUnit());
}

Mass Mass::operator-(const Mass& peer) const {
    return Mass((quantity - peer.quantity), quantity.getUnit());
}

Mass Mass::operator*(const Mass& peer) const {
    return Mass((quantity * peer.quantity), quantity.getUnit());
}

Mass Mass::operator/(const Mass& peer) const {
    return Mass((quantity / peer.quantity), quantity.getUnit());
}

Mass Mass::operator%(const Mass& peer) const {
    return Mass((quantity % peer.quantity), quantity.getUnit());
}

float Mass::getTotal() const {
    float result = quantity.getValue();
    return result;
}

Mass Mass::copy() {
    Mass fresh(quantity, quantity.getUnit());
    return fresh;
}

void Mass::clear() {
    quantity.clear();
    return;
}

std::string Mass::print() {
    std::stringstream result;
    result << "(m:";
    result << quantity.print() << ")";
	return result.str();
}

} // namespace qft