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

const std::string Charge::UNIT = "C";                       // System International
const std::string Charge::ELECTRIC_FIELD = "Electric";      // Electric Field
const short int Charge::ATOMIC_SCALE = -19;                 // 10^-19 C
const float Charge::PROTON = 1.602f;                        // 1.602 x 10^-19 C
const float Charge::NEUTRON = shp::Quantity::DEFAULT_VALUE; // 0.0 x 10^-19 C
const float Charge::ELECTRON = -1.6021766341019f;           // 1.602 x 10^-19 C

Charge::Charge()
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(nullptr);
}

Charge::Charge(const std::shared_ptr<Field> field)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(field);
}

Charge::Charge(std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, std::string(unit)) {
    setField(nullptr);
}

Charge::Charge(const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Charge::Charge(const shp::Unit& unit, const std::shared_ptr<Field> field)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit) {
    setField(field);
}

Charge::Charge(const float magnitude)
        : shp::Temporal(magnitude, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, ATOMIC_SCALE,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(field);
}

Charge::Charge(const float magnitude, std::string unit)
        : shp::Temporal(magnitude, ATOMIC_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const shp::Unit& unit)
        : shp::Temporal(magnitude, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, ATOMIC_SCALE, unit) {
    setField(field);
}

Charge::Charge(const float magnitude, const short int scaling)
        : shp::Temporal(magnitude, scaling,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const short int scaling, const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, scaling,
            shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE)) {
    setField(field);
}

Charge::Charge(const float magnitude, const short int scaling, std::string unit)
        : shp::Temporal(magnitude, scaling, shp::Unit(unit)) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(magnitude, scaling, unit) {
    setField(nullptr);
}

Charge::Charge(const float magnitude, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, scaling, unit) {
    setField(field);
}

Charge::~Charge() {
    setField(nullptr);
}

bool Charge::operator==(const Charge& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (field == peer.field);
}

Charge Charge::operator+(const Charge& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self + other);
    return Charge(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Charge Charge::operator-(const Charge& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self - other);
    return Charge(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Charge Charge::operator*(const Charge& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self * other);
    return Charge(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Charge Charge::operator/(const Charge& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self / other);
    return Charge(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Charge Charge::operator%(const Charge& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self % other);
    return Charge(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Force Charge::operator()(const Charge& peer, const shp::Distance separation,
        const shp::Distance position) const {
    if (isOwned()) {
        shp::Potential self = field->getPotential();
        shp::Potential other = peer.field->getPotential();
        shp::Quantity factor = self(other, separation, position);
        shp::Quantity force(factor * (*this).getMagnitude());
        Electric result(force.getMagnitude(), self.getAzimuth().toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return Electric(quantum, direction.toRadians(), Force::COULOMB_SCALE, field);
    }
}

bool Charge::isOwned() const {
    return field != nullptr;
}

shp::Distance Charge::getRadius() const {
    shp::Distance result;
    if (isOwned()) {
        result = field->getRadius();
    }
    return result;
}

void Charge::setRadius(const shp::Distance& length) {
    if (isOwned()) {
        field->setRadius(length);
    }
}

shp::Potential Charge::getPotential() const {
    shp::Potential result;
    if (isOwned()) {
        result = field->getPotential();
    }
    return result;
}

Density Charge::getDensity(const shp::Volume& volume) const {
    return Density(getMagnitude(), volume, getUnit());
}

Force Charge::getForce(const shp::Angular& coordinates) const {
    if (isOwned()) {
        shp::Temporal force = (field->getTotal() * (*this));
        shp::Direction direction = field->getLinear();
        Electric result(force.getMagnitude(), direction.toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return Electric(quantum, direction.toRadians(), Force::COULOMB_SCALE, field);
    }
}

std::shared_ptr<Field> Charge::getOriginField() const {
    std::shared_ptr<Field> result = Field::shareable(Charge::ELECTRIC_FIELD);
    result->setPotential(shp::Potential(getMagnitude(), shp::Quantity::DEFAULT_VALUE,
        getScaling(), getUnit(), shp::Angular(Energy::getPlanckLength())));
    return result;
}

Charge Charge::copy() {
    shp::Temporal self = *this;
    Charge fresh(self.getMagnitude(), self.getScaling(), self.getUnit(), field);
    return fresh;
}

void Charge::clear() {
    shp::Temporal::clear();
    setField(nullptr);
    return;
}

std::string Charge::print() {
    std::stringstream result;
    result << "q:";
    result << shp::Temporal::print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

shp::Temporal Charge::getFluctuation(const float phase) const {
    shp::Temporal self = *this;
    shp::Temporal intensity = self.getMagnitude();
    intensity.setPhase(phase);
	return shp::Temporal(intensity.getMagnitude(), intensity.getScaling(), intensity.getUnit());
}

} // namespace qft