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

const std::string Mass::UNIT = "kg";        // System International
const short int Mass::ATOMIC_SCALE = -27;   // 10^-27 kg
const float Mass::ATOMIC_UNIT = 1.6605f;    // 1.6605 x 10^-27 kg
const float Mass::PROTON = 1.672621027f;    // 1.67 x 10^-27 kg
const float Mass::NEUTRON = 1.67492749804f; // 1.67 x 10^-27 kg
const float Mass::ELECTRON = 0.0009109f;    // 0.0009109 x 10^-27 kg

Mass::Mass()
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(nullptr);
}

Mass::Mass(const std::shared_ptr<Field>)
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(field);
}

Mass::Mass(std::string unit)
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Mass::Mass(const shp::Unit& unit)
        : magnitude(shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Mass::Mass(const float magnitude)
        : magnitude(magnitude, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, std::string unit)
        : magnitude(magnitude, ATOMIC_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, const shp::Unit& unit)
        : magnitude(magnitude, ATOMIC_SCALE, unit) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, short int scaling)
        : magnitude(magnitude, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::MASS)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, short int scaling, std::string unit)
        : magnitude(magnitude, scaling, shp::Unit(unit)) {
    setField(nullptr);
}

Mass::Mass(const float magnitude, short int scaling, const shp::Unit& unit)
        : magnitude(magnitude, scaling, unit) {
    setField(nullptr);
}

Mass::Mass(const shp::Quantity& magnitude)
        : magnitude(magnitude) {
    setField(nullptr);
}

Mass::Mass(std::shared_ptr<Field> field, const shp::Quantity& magnitude)
        : magnitude(magnitude) {
    setField(field);
}

Mass::~Mass() {
    setField(nullptr);
}

bool Mass::operator==(const Mass& peer) const {
    return (magnitude == peer.magnitude);
}

Mass Mass::operator+(const Mass& peer) const {
    shp::Quantity mass = (magnitude + peer.magnitude);
    return Mass(mass.getValue(), mass.getScaling(), mass.getUnit());
}

Mass Mass::operator-(const Mass& peer) const {
    shp::Quantity mass = (magnitude - peer.magnitude);
    return Mass(mass.getValue(), mass.getScaling(), mass.getUnit());
}

Mass Mass::operator*(const Mass& peer) const {
    shp::Quantity mass = (magnitude * peer.magnitude);
    return Mass(mass.getValue(), mass.getScaling(), mass.getUnit());
}

Mass Mass::operator/(const Mass& peer) const {
    shp::Quantity mass = (magnitude / peer.magnitude);
    return Mass(mass.getValue(), mass.getScaling(), mass.getUnit());
}

Mass Mass::operator%(const Mass& peer) const {
    shp::Quantity mass = (magnitude % peer.magnitude);
    return Mass(mass.getValue(), mass.getScaling(), mass.getUnit());
}

Force Mass::operator()(const Mass& peer, const float distance) const {
    float movable = (magnitude.getValue() * peer.magnitude.getValue());
    float quantum = (Force::GRAVITATIONAL_CONSTANT * (movable / (distance * distance)));
    Force result(quantum, Force::GRAVITATIONAL_SCALE, shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    result.adjustScaling();
    return result;
}

shp::Unit Mass::getUnit() const {
    return magnitude.getUnit();
}

void Mass::setUnit(const shp::Unit& value) {
    this->magnitude.setUnit(value);
}

bool Mass::isOwned() const {
    return field != nullptr;
}

shp::Quantity Mass::getTotal() const {
    shp::Quantity result(magnitude.getValue(), magnitude.getScaling(), getUnit());
    return result;
}

Density Mass::getDensity(const shp::Volume& volume) const {
    Density result(getTotal(), volume, getUnit());
    return result;
}

Force Mass::getForce(const shp::Angular& coordinates) const {
    shp::Quantity force = (getTotal() * field->getTotal());
    shp::Direction direction = field->getDirection();
    Gravity result(force.getValue(), direction.toRadians(), force.getScaling(), field);
    result.adjustScaling();
    return result;
}

void Mass::adjustScaling() {
    magnitude.adjustScaling();
}

Mass Mass::copy() {
    Mass fresh(magnitude.getValue(), magnitude.getScaling(), magnitude.getUnit());
    fresh.setField(field);
    return fresh;
}

void Mass::clear() {
    magnitude.clear();
    setField(nullptr);
    return;
}

std::string Mass::print() {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::MASS) << ":";
    result << magnitude.print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

shp::Quantity Mass::getComponent(float phase) const {
	shp::Quantity mass = getTotal();
	return shp::Quantity((mass.getValue() * cos(phase)), mass.getScaling(), mass.getUnit());
}

} // namespace qft