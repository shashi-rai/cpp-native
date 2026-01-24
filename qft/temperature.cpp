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

namespace qft {

const std::string Temperature::UNIT = "K";                              // System International
const float Temperature::BASE_VALUE = 273.15f;                          // 0.0K
const short int Temperature::DEFAULT_SCALE = 0;                         // 10^0 K
const float Temperature::DEFAULT_VALUE = shp::Quantity::DEFAULT_VALUE;  // 0.0 K
const float Temperature::BOLTZMANN_CONSTANT = 1.380649f;                // 1.380649fx10^-23 J/K
const short int Temperature::BOLTZMANN_SCALE = -23;                     // 10^-23 J/K

Temperature::Temperature()
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const std::string unit)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const shp::Unit& unit)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const float quantity)
        : shp::Quantity(quantity, DEFAULT_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const float quantity, const std::string unit)
        : shp::Quantity(quantity, DEFAULT_SCALE, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const float quantity, const shp::Unit& unit)
        : shp::Quantity(quantity, DEFAULT_SCALE, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const float quantity, const short int scaling)
        : shp::Quantity(quantity, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const float quantity, const short int scaling, const std::string unit)
        : shp::Quantity(quantity, scaling, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const float quantity, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(quantity, scaling, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Temperature::Temperature(const shp::Direction& change)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)),
        change(change) {

}

Temperature::Temperature(const std::string unit, const shp::Direction& change)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE, unit),
        change(change) {

}

Temperature::Temperature(const shp::Unit& unit, const shp::Direction& change)
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE, unit),
        change(change) {

}

Temperature::Temperature(const float quantity, const shp::Direction& change)
        : shp::Quantity(quantity, DEFAULT_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)),
        change(change) {

}

Temperature::Temperature(const float quantity, const std::string unit, const shp::Direction& change)
        : shp::Quantity(quantity, DEFAULT_SCALE, unit),
        change(change) {

}

Temperature::Temperature(const float quantity, const shp::Unit& unit, const shp::Direction& change)
        : shp::Quantity(quantity, DEFAULT_SCALE, unit),
        change(change) {

}

Temperature::Temperature(const float quantity, const short int scaling, const shp::Direction& change)
        : shp::Quantity(quantity, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)),
        change(change) {

}

Temperature::Temperature(const float quantity, const short int scaling, const std::string unit,
        const shp::Direction& change)
        : shp::Quantity(quantity, scaling, unit),
        change(change) {

}

Temperature::Temperature(const float quantity, const short int scaling, const shp::Unit& unit,
        const shp::Direction& change)
        : shp::Quantity(quantity, scaling, unit),
        change(change) {

}

Temperature::~Temperature() {

}

bool Temperature::operator==(const Temperature& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (change == peer.change);
}

bool Temperature::operator<(const Temperature& peer) const {
    Temperature self = *this; bool result = false;
    if (static_cast<const shp::Quantity&>(*this) < static_cast<const shp::Quantity&>(peer)) {
        result = true;
    } else if (change < peer.change) {
        result = true;
    }
    return result;
}

bool Temperature::operator>(const Temperature& peer) const {
    Temperature self = *this; bool result = false;
    if (static_cast<const shp::Quantity&>(*this) > static_cast<const shp::Quantity&>(peer)) {
        result = true;
    } else if (change > peer.change) {
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
    shp::Quantity self = *this, other = peer;
    shp::Quantity temperature = (self + other);
    shp::Direction direction = (this->change + peer.change);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit(), direction);
}

Temperature Temperature::operator-(const Temperature& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity temperature = (self - other);
    shp::Direction direction = (this->change - peer.change);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit(), direction);
}

Temperature Temperature::operator*(const Temperature& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity temperature = (self * other);
    shp::Direction direction = (this->change * peer.change);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit(), direction);
}

Temperature Temperature::operator/(const Temperature& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity temperature = (self / other);
    shp::Direction direction = (this->change / peer.change);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit(), direction);
}

Temperature Temperature::operator%(const Temperature& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity temperature = (self % other);
    shp::Direction direction = (this->change % peer.change);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit(), direction);
}

shp::Quantity Temperature::getTotal() const {
    shp::Quantity result(getMagnitude(), getScaling(), getUnit());
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

Temperature Temperature::copy() {
    Temperature fresh(getMagnitude(), getScaling(), getUnit(), change);
    return fresh;
}

void Temperature::clear() {
    shp::Quantity::clear();
    change.clear();
    return;
}

std::string Temperature::print() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << shp::Quantity::print();
    result << change.print();
	return result.str();
}

std::string Temperature::printRadians() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << shp::Quantity::print();
    result << change.printRadians();
	return result.str();
}

std::string Temperature::printKelvin() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << toKelvin() << "ₑ";
    result << shp::Quantity::getScaling();
    result << "°K,";
    result << change.print();
	return result.str();
}

std::string Temperature::printCelsius() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << toCelsius() << "ₑ";
    result << shp::Quantity::getScaling();
    result << "°C,";
    result << change.print();
	return result.str();
}

std::string Temperature::printFahrenheit() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << toFahrenheit() << "ₑ";
    result << shp::Quantity::getScaling();
    result << "°F,";
    result << change.print();
	return result.str();
}

float Temperature::getCosComponent(const float phase) const {
    return Quantity::getCosComponent(phase);
}

float Temperature::getSinComponent(const float phase) const {
    return Quantity::getSinComponent(phase);
}

const std::complex<float> Temperature::getComplex(const float value, const float direction) {
    return Quantity::getComplex(value, direction);
}

const shp::Quantity Temperature::getBoltzmannConstant() {
    return shp::Quantity(BOLTZMANN_CONSTANT, BOLTZMANN_SCALE, "J/K");
}

} // namespace qft