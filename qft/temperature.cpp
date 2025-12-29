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

Temperature::Temperature()
        : shp::Quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {

}

Temperature::Temperature(const float quantity)
        : shp::Quantity(quantity, DEFAULT_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {

}

Temperature::Temperature(const float quantity, const short int scaling)
        : shp::Quantity(quantity, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE)) {

}

Temperature::Temperature(const float quantity, const shp::Unit& unit)
        : shp::Quantity(quantity, DEFAULT_SCALE, unit) {

}

Temperature::Temperature(const float quantity, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(quantity, scaling, unit) {

}

Temperature::~Temperature() {

}

bool Temperature::operator==(const Temperature& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer));
}

Temperature Temperature::operator+(const Temperature& peer) const {
    Quantity self = *this, other = peer;
    Quantity temperature = (self + other);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit());
}

Temperature Temperature::operator-(const Temperature& peer) const {
    Quantity self = *this, other = peer;
    Quantity temperature = (self - other);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit());
}

Temperature Temperature::operator*(const Temperature& peer) const {
    Quantity self = *this, other = peer;
    Quantity temperature = (self * other);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit());
}

Temperature Temperature::operator/(const Temperature& peer) const {
    Quantity self = *this, other = peer;
    Quantity temperature = (self / other);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit());
}

Temperature Temperature::operator%(const Temperature& peer) const {
    Quantity self = *this, other = peer;
    Quantity temperature = (self % other);
    return Temperature(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit());
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
    Temperature fresh(getMagnitude(), getScaling(), getUnit());
    return fresh;
}

void Temperature::clear() {
    shp::Quantity::clear();
    return;
}

std::string Temperature::print() {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TEMPERATURE) << ":";
    result << shp::Quantity::print();
	return result.str();
}

shp::Quantity Temperature::getComponent(float phase) const {
	shp::Quantity temperature = getTotal();
	return shp::Quantity((temperature.getMagnitude() * cos(phase)), temperature.getScaling(), temperature.getUnit());
}

} // namespace qft