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

#include "quantity.h"

namespace shp {

const float Quantity::DEFAULT_VALUE = 0.0f;     // 0.0f
const short int Quantity::DEFAULT_SCALE = 0;    // 10^0

Quantity::Quantity() : value(DEFAULT_VALUE), scaling(DEFAULT_SCALE), unit() {

}

Quantity::Quantity(float value): value(value), scaling(DEFAULT_SCALE), unit() {

}

Quantity::Quantity(short int scaling)
        : value(), scaling(scaling), unit() {

}

Quantity::Quantity(const std::string unit)
        : value(), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(short int scaling, const std::string unit)
        : value(), scaling(scaling), unit(unit) {

}

Quantity::Quantity(const Unit& unit)
        : value(), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(short int scaling, const Unit& unit)
        : value(), scaling(scaling), unit(unit) {

}

Quantity::Quantity(float value, const std::string unit)
        : value(value), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(float value, const Unit& unit)
        : value(value), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(float value, short int scaling)
        : value(value), scaling(scaling), unit() {

}

Quantity::Quantity(float value, short int scaling, const std::string unit)
        : value(value), scaling(scaling), unit(unit) {

}

Quantity::Quantity(float value, short int scaling, const Unit& unit)
        : value(value), scaling(scaling), unit(unit) {

}

Quantity::~Quantity() {

}

bool Quantity::operator==(const Quantity& peer) const {
    return (value == peer.value) &&
            (scaling == peer.scaling) &&
            (unit == peer.unit);
}

Quantity Quantity::operator+(const Quantity& peer) const {
    short int exponent = (scaling - peer.scaling);
    float mantissa = (value + (peer.value / std::pow(10, exponent)));
    Quantity result(mantissa, scaling, getUnit());
    return result;
}

Quantity Quantity::operator-(const Quantity& peer) const {
    short int exponent = (scaling - peer.scaling);
    float mantissa = (value - (peer.value / std::pow(10, exponent)));
    Quantity result(mantissa, scaling, getUnit());
    return result;
}

Quantity Quantity::operator*(const Quantity& peer) const {
    float mantissa = (value * peer.value);
    Quantity result(mantissa, (scaling + peer.scaling), getUnit());
    return result;
}

Quantity Quantity::operator/(const Quantity& peer) const {
    float mantissa = (value / peer.value);
    Quantity result(mantissa, (scaling - peer.scaling), getUnit());
    return result;
}

Quantity Quantity::operator%(const Quantity& peer) const {
    short int exponent = (scaling - peer.scaling);
    float mantissa = fmod(value, (peer.value / std::pow(10, exponent)));
    Quantity result(mantissa, scaling, getUnit());
    return result;
}

Quantity Quantity::getInverse() const {
    Quantity fresh(value != DEFAULT_VALUE ? (1 / value) : DEFAULT_VALUE, scaling, unit);
    return fresh;
}

short int Quantity::checkScaling(float amount) const {
    return log10(amount);
}

void Quantity::adjustScaling() {
    float current = value;
    if (current == DEFAULT_VALUE) {
        return;
    }
    int exponent = static_cast<int>(std::floor(std::log10(std::fabs(current))));
    float mantissa = current / std::pow(10.0f, exponent);
    scaling += exponent;
    value = mantissa;
    return;
}

Quantity Quantity::copy() {
    Quantity fresh(value, scaling, unit);
    return fresh;
}

void Quantity::clear() {
    value = DEFAULT_VALUE;
    scaling = DEFAULT_SCALE;
    unit.clear();
    return;
}

std::string Quantity::print() {
    std::stringstream result;
    result << value << "x10^";
    result << scaling;
    result << unit.print();
	return result.str();
}

float Quantity::getComponent(float phase) const {
    return getValue() * cos(phase);
}

} // namespace shp