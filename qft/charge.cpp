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

#include "charge.h"

namespace qft {

const std::string Charge::UNIT = "C";               // System International
const short int Charge::ATOMIC_SCALE = -19;         // 10^-19 C
const float Charge::PROTON = 1.602f;                // 1.602 x 10^-19 C
const float Charge::NEUTRON = 0.0f;                 // 0.0 x 10^-19 C
const float Charge::ELECTRON = -1.6021766341019f;   // 1.602 x 10^-19 C

Charge::Charge()
        : quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {

}

Charge::Charge(float quantity)
        : quantity(quantity, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {

}

Charge::Charge(float quantity, short int scaling)
        : quantity(quantity, scaling,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {

}

Charge::Charge(float quantity, const shp::Unit& unit)
        : quantity(quantity, ATOMIC_SCALE, unit) {

}

Charge::Charge(float quantity, short int scaling, const shp::Unit& unit)
        : quantity(quantity, scaling, unit) {

}

Charge::Charge(const shp::Quantity& quantity, const shp::Unit& unit) : quantity(unit) {

}

Charge::~Charge() {

}

bool Charge::operator==(const Charge& peer) const {
    return (quantity == peer.quantity);
}

Charge Charge::operator+(const Charge& peer) const {
    return Charge((quantity + peer.quantity).getValue(), quantity.getUnit());
}

Charge Charge::operator-(const Charge& peer) const {
    return Charge((quantity - peer.quantity).getValue(), quantity.getUnit());
}

Charge Charge::operator*(const Charge& peer) const {
    return Charge((quantity * peer.quantity).getValue(), quantity.getUnit());
}

Charge Charge::operator/(const Charge& peer) const {
    return Charge((quantity / peer.quantity).getValue(), quantity.getUnit());
}

Charge Charge::operator%(const Charge& peer) const {
    return Charge((quantity % peer.quantity).getValue(), quantity.getUnit());
}

Force Charge::operator()(const Charge& peer, const float distance) const {
    float charged = (quantity.getValue() * peer.quantity.getValue());
    float quantum = (Force::COULOMB_CONSTANT * (charged / (distance * distance)));
    Force result(quantum, Force::COULOMB_SCALE, shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    result.adjustScaling();
    return result;
}

shp::Quantity Charge::getTotal() const {
    shp::Quantity result(quantity.getValue(), quantity.getScaling(), getUnit());
    return result;
}

Density Charge::getDensity(const float volume) const {
    Density result(getTotal().getValue(), volume, quantity.getUnit().getName());
    return result;
}

Force Charge::getForce(const float acceleration) const {
    float movable = (getTotal().getValue() * acceleration);
    Force result(movable, quantity.getUnit().getName());
    result.adjustScaling();
    return result;
}

void Charge::adjustScaling() {
    quantity.adjustScaling();
}

Charge Charge::copy() {
    Charge fresh(quantity, quantity.getUnit());
    return fresh;
}

void Charge::clear() {
    quantity.clear();
    return;
}

std::string Charge::print() {
    std::stringstream result;
    result << "(q:";
    result << quantity.print() << ")";
	return result.str();
}

shp::Quantity Charge::getComponent(float phase) const {
	shp::Quantity charge = getTotal();
	return shp::Quantity((charge.getValue() * cos(phase)), charge.getScaling(), charge.getUnit());
}

} // namespace qft