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

const std::string Temperature::UNIT = shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE);
const short int Temperature::DEFAULT_SCALE = 0;     // 10^0 K
const float Temperature::DEFAULT_VALUE = 0.0f;      // O.0 K

Temperature::Temperature() : quantity(shp::Quantity::DEFAULT_VALUE, DEFAULT_SCALE, UNIT) {

}

Temperature::Temperature(float quantity) : quantity(quantity, DEFAULT_SCALE, UNIT) {

}

Temperature::Temperature(float quantity, short int scaling) : quantity(quantity, scaling, UNIT) {

}

Temperature::Temperature(float quantity, const shp::Unit& unit)
        : quantity(quantity, DEFAULT_SCALE, unit) {

}

Temperature::Temperature(float quantity, short int scaling, const shp::Unit& unit)
        : quantity(quantity, scaling, unit) {

}

Temperature::Temperature(const shp::Quantity& quantity, const shp::Unit& unit)
        : quantity(unit) {

}

Temperature::~Temperature() {

}

bool Temperature::operator==(const Temperature& peer) const {
    return (quantity == peer.quantity);
}

Temperature Temperature::operator+(const Temperature& peer) const {
    return Temperature((quantity + peer.quantity), quantity.getUnit());
}

Temperature Temperature::operator-(const Temperature& peer) const {
    return Temperature((quantity - peer.quantity), quantity.getUnit());
}

Temperature Temperature::operator*(const Temperature& peer) const {
    return Temperature((quantity * peer.quantity), quantity.getUnit());
}

Temperature Temperature::operator/(const Temperature& peer) const {
    return Temperature((quantity / peer.quantity), quantity.getUnit());
}

Temperature Temperature::operator%(const Temperature& peer) const {
    return Temperature((quantity % peer.quantity), quantity.getUnit());
}

void Temperature::fromCelsius(const float value) {
    quantity.setValue(value + 273.15f);
}

float Temperature::toCelsius() const {
    return (toKelvin() - 273.15f);
}

void Temperature::fromFahrenheit(const float value) {
    float celsius = ((5.0f / 9.0f) * (value - 32));
    quantity.setValue((celsius + 273.15f));
}

float Temperature::toFahrenheit() const {
    return ((9.0f / 5.0f) * (toCelsius()) + 32);
}

float Temperature::toKelvin() const {
    return quantity.getValue();
}

Temperature Temperature::copy() {
    Temperature fresh(quantity, quantity.getUnit());
    return fresh;
}

void Temperature::clear() {
    quantity.clear();
    return;
}

std::string Temperature::print() {
    std::stringstream result;
    result << "(t:";
    result << quantity.print() << ")";
	return result.str();
}

} // namespace qft