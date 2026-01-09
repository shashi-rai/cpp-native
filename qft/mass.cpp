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
#include "field.h"
#include "gravity.h"

namespace qft {

const std::string Mass::UNIT = "kg";                // System International
const std::string Mass::GRAVITY_FIELD = "Gravity";  // Gravity Field
const short int Mass::ATOMIC_SCALE = -27;           // 10^-27 kg
const float Mass::ATOMIC_UNIT = 1.6605f;            // 1.6605 x 10^-27 kg
const float Mass::PROTON = 1.672621027f;            // 1.67 x 10^-27 kg
const float Mass::NEUTRON = 1.67492749804f;         // 1.67 x 10^-27 kg
const float Mass::ELECTRON = 0.0009109f;            // 0.0009109 x 10^-27 kg

Mass::Mass()
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(nullptr);
}

Mass::Mass(const std::shared_ptr<Field> field)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(field);
}

Mass::Mass(std::string unit)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Mass::Mass(const shp::Unit& unit)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Mass::Mass(const shp::Unit& unit, const std::shared_ptr<Field> field)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit) {
    setField(field);
}

Mass::Mass(const float magnitude)
        : shp::Quantity(magnitude, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const std::shared_ptr<Field> field)
        : shp::Quantity(magnitude, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(field);
}

Mass::Mass(const float magnitude, std::string unit)
        : shp::Quantity(magnitude, ATOMIC_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const shp::Unit& unit)
        : shp::Quantity(magnitude, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field)
        : shp::Quantity(magnitude, ATOMIC_SCALE, unit) {
    setField(field);
}

Mass::Mass(const float magnitude, const short int scaling)
        : shp::Quantity(magnitude, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const short int scaling, std::string unit)
        : shp::Quantity(magnitude, scaling, shp::Unit(unit)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(magnitude, scaling, unit) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const short int scaling, const shp::Unit& unit,
        std::shared_ptr<Field> field)
        : shp::Quantity(magnitude, scaling, unit) {
    setField(field);
}

Mass::~Mass() {
    setField(nullptr);
}

bool Mass::operator==(const Mass& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (field == peer.field);
}

Mass Mass::operator+(const Mass& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity result = (self + other);
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Mass Mass::operator-(const Mass& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity result = (self - other);
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Mass Mass::operator*(const Mass& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity result = (self * other);
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Mass Mass::operator/(const Mass& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity result = (self / other);
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Mass Mass::operator%(const Mass& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity result = (self % other);
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Force Mass::operator()(const Mass& peer, const shp::Distance separation,
        const shp::Distance& position) const {
    if (isOwned()) {
        shp::Potential self = field->getPotential();
        shp::Potential other = peer.field->getPotential();
        shp::Quantity factor = self(other, separation, position);
        shp::Quantity force = (factor * (*this));
        Gravity result(force.getMagnitude(), self.getAzimuth().toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return Gravity(quantum, direction.toRadians(), Force::GRAVITATIONAL_SCALE, field);
    }
}

bool Mass::isOwned() const {
    return field != nullptr;
}

shp::Distance Mass::getRadius() const {
    shp::Distance result;
    if (isOwned()) {
        result = field->getRadius();
    }
    return result;
}

void Mass::setRadius(const shp::Distance& length) {
    if (isOwned()) {
        field->setRadius(length);
    }
}

shp::Potential Mass::getPotential() const {
    shp::Potential result;
    if (isOwned()) {
        result = field->getPotential();
    }
    return result;
}

Density Mass::getDensity(const shp::Volume& volume) const {
    return Density(getMagnitude(), volume, getUnit());
}

Force Mass::getForce(const shp::Angular& coordinates) const {
    if (isOwned()) {
        shp::Quantity force = (field->getTotal() * (*this));
        shp::Direction direction = field->getLinear();
        Gravity result(force.getMagnitude(), direction.toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return Gravity(quantum, direction.toRadians(), Force::GRAVITATIONAL_SCALE, field);
    }
}

std::shared_ptr<Field> Mass::getOriginField() const {
    std::shared_ptr<Field> result = Field::shareable(Mass::GRAVITY_FIELD);
    result->setPotential(shp::Potential(getMagnitude(), shp::Quantity::DEFAULT_VALUE,
        getScaling(), getUnit(), shp::Angular(Energy::getPlanckLength())));
    return result;
}

Mass Mass::copy() const {
    shp::Quantity self = *this;
    Mass fresh(self.getMagnitude(), self.getScaling(), self.getUnit(), field);
    return fresh;
}

void Mass::clear() {
    shp::Quantity::clear();
    setField(nullptr);
    return;
}

std::string Mass::print() {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::MASS) << ":";
    result << shp::Quantity::print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

shp::Quantity Mass::getFluctuation(const float phase) const {
    shp::Quantity self = *this;
	return shp::Quantity(self.getCosComponent(phase), self.getScaling(), self.getUnit());
}

} // namespace qft