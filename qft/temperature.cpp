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

#include "temperature.h"
#include "thermal.h"

namespace qft {

const std::string Temperature::UNIT = "K";                              // System International
const std::string Temperature::THERMAL_FIELD = "Thermal";               // Thermal Field
const short int Temperature::THERMAL_SCALE = 0;                         // 10^0 K
const float Temperature::QGP = 150;                                     // 150 MeV
const short int Temperature::QGP_SCALE = 6;                             // 10^6 eV
const float Temperature::BASE_VALUE = 273.15f;                          // 0.0 K
const short int Temperature::DEFAULT_SCALE = 0;                         // 10^0 K
const float Temperature::DEFAULT_VALUE = shp::Quantity::DEFAULT_VALUE;  // 0.0 K
const float Temperature::BOLTZMANN_CONSTANT = 1.380649f;                // 1.380649fx10^-23 J/K
const short int Temperature::BOLTZMANN_SCALE = -23;                     // 10^-23 J/K

Temperature::Temperature()
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, THERMAL_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {
    setField(nullptr);
}

Temperature::Temperature(const std::shared_ptr<Field> field)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, THERMAL_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {
    setField(field);
}

Temperature::Temperature(const std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, THERMAL_SCALE, std::string(unit)) {
    setField(nullptr);
}

Temperature::Temperature(const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, THERMAL_SCALE, unit) {
    setField(nullptr);
}

Temperature::Temperature(const shp::Unit& unit, const std::shared_ptr<Field> field)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, THERMAL_SCALE, unit) {
    setField(field);
}

Temperature::Temperature(const float magnitude)
        : shp::Temporal(magnitude, THERMAL_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {
    setField(nullptr);
}

Temperature::Temperature(const float magnitude, const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, THERMAL_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {
    setField(field);
}

Temperature::Temperature(const float magnitude, const std::string unit)
        : shp::Temporal(magnitude, THERMAL_SCALE, shp::Unit(unit)) {
    setField(nullptr);
}

Temperature::Temperature(const float magnitude, const shp::Unit& unit)
        : shp::Temporal(magnitude, THERMAL_SCALE, unit) {
    setField(nullptr);
}

Temperature::Temperature(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, THERMAL_SCALE, unit) {
    setField(field);
}

Temperature::Temperature(const float magnitude, const short int scaling)
        : shp::Temporal(magnitude, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {
    setField(nullptr);
}

Temperature::Temperature(const float magnitude, const short int scaling, const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {
    setField(field);
}

Temperature::Temperature(const float magnitude, const short int scaling, const std::string unit)
        : shp::Temporal(magnitude, scaling, shp::Unit(unit)) {
    setField(nullptr);
}

Temperature::Temperature(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(magnitude, scaling, unit) {
    setField(nullptr);
}

Temperature::Temperature(const float magnitude, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Field> field)
        : shp::Temporal(magnitude, scaling, unit) {
    setField(field);
}

Temperature::~Temperature() {
    setField(nullptr);
}

bool Temperature::operator==(const Temperature& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer));
}

bool Temperature::operator<(const Temperature& peer) const {
    Temperature self = *this; bool result = false;
    if (static_cast<const shp::Temporal&>(*this) < static_cast<const shp::Temporal&>(peer)) {
        result = true;
    }
    return result;
}

bool Temperature::operator>(const Temperature& peer) const {
    Temperature self = *this; bool result = false;
    if (static_cast<const shp::Temporal&>(*this) > static_cast<const shp::Temporal&>(peer)) {
        result = true;
    }
    return result;
}

bool Temperature::operator<=(const Temperature& peer) const {
    Temperature self = *this;
    return (self < peer) || (self == peer);
}

bool Temperature::operator>=(const Temperature& peer) const {
    Temperature self = *this;
    return (self > peer) || (self == peer);
}

Temperature Temperature::operator+(const Temperature& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self + other);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator-(const Temperature& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self - other);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator*(const Temperature& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self * other);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator/(const Temperature& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self / other);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator%(const Temperature& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Temporal result = (self % other);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator+(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal result = (self.getTotal() + peer);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator-(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal result = (self.getTotal() - peer);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator*(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal result = (self.getTotal() * peer);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator/(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal result = (self.getTotal() / peer);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Temperature Temperature::operator%(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal result = (self.getTotal() % peer);
    return Temperature(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

Force Temperature::operator()(const Temperature& peer, const shp::Distance separation,
        const shp::Distance position) const {
    if (isOwned()) {
        shp::Potential self = field->getPotential();
        shp::Potential other = peer.field->getPotential();
        shp::Signal factor = self(other, separation, position);
        shp::Signal force(factor * (*this).getMagnitude());
        Thermal result(force.getMagnitude(), self.getAzimuthOrientation().toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return Thermal(quantum, direction.toRadians(), Force::KELVIN_SCALE, field);
    }
}

bool Temperature::isOwned() const {
    return (field != nullptr);
}

shp::Distance Temperature::getFieldRadius() const {
    shp::Distance result;
    if (isOwned()) {
        result = field->getRadius();
    }
    return result;
}

void Temperature::setFieldRadius(const shp::Distance& length) {
    if (isOwned()) {
        field->setRadius(length.getMagnitude(), length.getScaling(), length.getUnit());
    }
}

void Temperature::setFieldRadius(const float length) {
    if (isOwned()) {
        field->setRadius(length);
    }
}

void Temperature::setFieldRadius(const float length, const short int scale) {
    if (isOwned()) {
        field->setRadius(length, scale);
    }
}

void Temperature::setFieldRadius(const float length, const short int scale, const std::string unit) {
    if (isOwned()) {
        field->setRadius(length, scale, unit);
    }
}

void Temperature::setFieldRadius(const float length, const short int scale, const shp::Unit& unit) {
    if (isOwned()) {
        field->setRadius(length, scale, unit);
    }
}

shp::Potential Temperature::getPotential() const {
    shp::Potential result;
    if (isOwned()) {
        result = field->getPotential();
    }
    return result;
}

shp::Signal Temperature::getVelocity() const {
    return shp::Temporal::getModulation();
}

void Temperature::setVelocity(const qft::Velocity& velocity) {
    shp::Temporal::setModulation(velocity.getTotal());
}

Density Temperature::getDensity(const shp::Volume& volume) const {
    shp::Temporal self = *this;
    return Density(self.getMagnitude(), self.getScaling(), self.getUnit(), volume);
}

Force Temperature::getForce(const shp::Angular& coordinates) const {
    if (isOwned()) {
        shp::Temporal force = (field->getTotal() * (*this));
        shp::Direction direction = field->getLinear();
        Thermal result(force.getMagnitude(), direction.toRadians(), force.getScaling(), field);
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return Thermal(quantum, direction.toRadians(), Force::COULOMB_SCALE, field);
    }
}

std::shared_ptr<Field> Temperature::getOriginField() const {
    std::shared_ptr<Field> result = Field::shareable(Temperature::THERMAL_FIELD, getMagnitude(), getScaling());
    result->setPotential(shp::Potential(getMagnitude(), shp::Quantity::DEFAULT_VALUE,
        getScaling(), getUnit(), shp::Angular(Energy::getPlanckLength())));
    return result;
}

void Temperature::fromCelsius(const float value) {
    setMagnitude(value + BASE_VALUE);
}

float Temperature::toCelsius() const {
    return (toKelvin() - BASE_VALUE);
}

void Temperature::fromFahrenheit(const float value) {
    float celsius = ((5.0f / 9.0f) * (value - 32));
    setMagnitude((celsius + BASE_VALUE));
}

float Temperature::toFahrenheit() const {
    return ((9.0f / 5.0f) * (toCelsius()) + 32);
}

float Temperature::toKelvin() const {
    return getMagnitude();
}

shp::Signal Temperature::copy() const {
    shp::Temporal self = *this;
    Temperature fresh(self.getMagnitude(), self.getScaling(), self.getUnit(), field);
    return fresh.getTotal();
}

void Temperature::clear() {
    shp::Temporal::clear();
    setField(nullptr);
    return;
}

std::string Temperature::print() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << shp::Temporal::print();
    if (isOwned()) {
        result << ",";
        result << field->print();
    }
	return result.str();
}

std::string Temperature::printRadians() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << shp::Temporal::printRadians();
    if (isOwned()) {
        result << ",";
        result << field->printRadians();
    }
	return result.str();
}

std::string Temperature::printKelvin() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << toKelvin() << "ₑ";
    result << shp::Temporal::getScaling();
    result << "°K,";
    if (isOwned()) {
        result << ",";
        result << field->print();
    }
	return result.str();
}

std::string Temperature::printCelsius() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << toCelsius() << "ₑ";
    result << shp::Temporal::getScaling();
    result << "°C,";
    if (isOwned()) {
        result << ",";
        result << field->print();
    }
	return result.str();
}

std::string Temperature::printFahrenheit() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << toFahrenheit() << "ₑ";
    result << shp::Temporal::getScaling();
    result << "°F,";
    if (isOwned()) {
        result << ",";
        result << field->print();
    }
	return result.str();
}

shp::Temporal Temperature::getFluctuation(const float phase) const {
    shp::Temporal self = *this, intensity = self.getMagnitude();
    intensity.setIntensityDrift(phase);
	return shp::Temporal(intensity.getMagnitude(), intensity.getScaling(), intensity.getUnit());
}

const shp::Quantity Temperature::getBoltzmannConstant() {
    return shp::Quantity(BOLTZMANN_CONSTANT, BOLTZMANN_SCALE, "J/K");
}

} // namespace qft