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
#include "electric.h"
#include "field.h"

namespace qft {

const std::string Charge::UNIT = "C";               // System International
const short int Charge::ATOMIC_SCALE = -19;         // 10^-19 C
const float Charge::PROTON = 1.602f;                // 1.602 x 10^-19 C
const float Charge::NEUTRON = 0.0f;                 // 0.0 x 10^-19 C
const float Charge::ELECTRON = -1.6021766341019f;   // 1.602 x 10^-19 C

Charge::Charge()
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(nullptr);
}

Charge::Charge(const std::shared_ptr<Field> field)
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(field);
}

Charge::Charge(std::string unit)
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, std::string(unit)) {
    setField(nullptr);
}

Charge::Charge(const shp::Unit& unit)
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Charge::Charge(const float magnitude)
        : magnitude(magnitude, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, std::string unit)
        : magnitude(magnitude, ATOMIC_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const shp::Unit& unit)
        : magnitude(magnitude, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, short int scaling)
        : magnitude(magnitude, scaling,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, short int scaling, std::string unit)
        : magnitude(magnitude, scaling, shp::Unit(unit)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, short int scaling, const shp::Unit& unit)
        : magnitude(magnitude, scaling, unit) {
    setField(nullptr);
}

Charge::Charge(const shp::Quantity& magnitude)
        : magnitude(magnitude) {
    setField(nullptr);
}

Charge::Charge(const std::shared_ptr<Field> field, const shp::Quantity& magnitude)
        : magnitude(magnitude) {
    setField(nullptr);
}

Charge::~Charge() {
    setField(nullptr);
}

bool Charge::operator==(const Charge& peer) const {
    return (magnitude == peer.magnitude);
}

Charge Charge::operator+(const Charge& peer) const {
    shp::Quantity charge = (magnitude + peer.magnitude);
    return Charge(charge.getValue(), charge.getScaling(), charge.getUnit());
}

Charge Charge::operator-(const Charge& peer) const {
    shp::Quantity charge = (magnitude - peer.magnitude);
    return Charge(charge.getValue(), charge.getScaling(), charge.getUnit());
}

Charge Charge::operator*(const Charge& peer) const {
    shp::Quantity charge = (magnitude * peer.magnitude);
    return Charge(charge.getValue(), charge.getScaling(), charge.getUnit());
}

Charge Charge::operator/(const Charge& peer) const {
    shp::Quantity charge = (magnitude / peer.magnitude);
    return Charge(charge.getValue(), charge.getScaling(), charge.getUnit());
}

Charge Charge::operator%(const Charge& peer) const {
    shp::Quantity charge = (magnitude % peer.magnitude);
    return Charge(charge.getValue(), charge.getScaling(), charge.getUnit());
}

Force Charge::operator()(const Charge& peer, const shp::Distance sepration,
        const shp::Distance distance) const {
    if (isOwned()) {
        shp::Potential self = field->getPotential();
        shp::Potential other = peer.field->getPotential();
        shp::Quantity factor = self(other, sepration, distance);
        shp::Quantity force = (magnitude * factor);
        Electric result(force.getValue(), self.getAzimuthal().toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = 0.0f; shp::Direction direction(quantum);
        return Electric(quantum, direction.toRadians(), Force::COULOMB_SCALE, field);
    }
}

shp::Unit Charge::getUnit() const {
    return magnitude.getUnit();
}

void Charge::setUnit(const shp::Unit& value) {
    this->magnitude.setUnit(value);
}

bool Charge::isOwned() const {
    return field != nullptr;
}

shp::Quantity Charge::getTotal() const {
    shp::Quantity result(magnitude.getValue(), magnitude.getScaling(), getUnit());
    return result;
}

Density Charge::getDensity(const shp::Volume& volume) const {
    Density result(getTotal(), volume, getUnit());
    return result;
}

Force Charge::getForce(const shp::Angular& coordinates) const {
    if (isOwned()) {
        shp::Quantity force = (getTotal() * field->getTotal());
        shp::Direction direction = field->getLinear();
        Electric result(force.getValue(), direction.toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = 0.0f; shp::Direction direction(quantum);
        return Electric(quantum, direction.toRadians(), Force::COULOMB_SCALE, field);
    }
}

void Charge::adjustScaling() {
    magnitude.adjustScaling();
}

Charge Charge::copy() {
    Charge fresh(magnitude.getValue(), magnitude.getScaling(), magnitude.getUnit());
    fresh.setField(field);
    return fresh;
}

void Charge::clear() {
    magnitude.clear();
    setField(nullptr);
    return;
}

std::string Charge::print() {
    std::stringstream result;
    result << "q:";
    result << magnitude.print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

shp::Quantity Charge::getComponent(float phase) const {
	shp::Quantity charge = getTotal();
	return shp::Quantity((charge.getValue() * cos(phase)), charge.getScaling(), charge.getUnit());
}

} // namespace qft