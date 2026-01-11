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

const float Quantity::EULER_NUMBER = 2.7182818284590452353602874713526624977572470936999f;
const float Quantity::DEFAULT_VALUE = 0.0f;     // 0.0f
const float Quantity::DECIMAL_SCALE = 10.0f;    // 10.0f
const short int Quantity::DEFAULT_SCALE = 0;    // 10^0

Quantity::Quantity()
        : magnitude(DEFAULT_VALUE), scaling(DEFAULT_SCALE), unit() {

}

Quantity::Quantity(const float magnitude)
        : magnitude(magnitude), scaling(DEFAULT_SCALE), unit() {

}

Quantity::Quantity(const short int scaling)
        : magnitude(), scaling(scaling), unit() {

}

Quantity::Quantity(const std::string unit)
        : magnitude(), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const Unit& unit)
        : magnitude(), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const short int scaling, const std::string unit)
        : magnitude(), scaling(scaling), unit(unit) {

}

Quantity::Quantity(const short int scaling, const Unit& unit)
        : magnitude(), scaling(scaling), unit(unit) {

}

Quantity::Quantity(const float magnitude, const std::string unit)
        : magnitude(magnitude), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const float magnitude, const Unit& unit)
        : magnitude(magnitude), scaling(DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const float magnitude, const short int scaling)
        : magnitude(magnitude), scaling(scaling), unit() {

}

Quantity::Quantity(const float magnitude, const short int scaling, const std::string unit)
        : magnitude(magnitude), scaling(scaling), unit(unit) {

}

Quantity::Quantity(const float magnitude, const short int scaling, const Unit& unit)
        : magnitude(magnitude), scaling(scaling), unit(unit) {

}

Quantity::~Quantity() {

}

bool Quantity::operator==(const Quantity& peer) const {
    return (magnitude == peer.magnitude)
        && (scaling == peer.scaling)
        && (unit == peer.unit);
}

Quantity Quantity::operator+(const Quantity& peer) const {
    short int exponent = (scaling - peer.scaling);
    float mantissa = (magnitude + (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    Quantity result(mantissa, scaling, getUnit());
    return result;
}

Quantity Quantity::operator-(const Quantity& peer) const {
    short int exponent = (scaling - peer.scaling);
    float mantissa = (magnitude - (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    Quantity result(mantissa, scaling, getUnit());
    return result;
}

Quantity Quantity::operator*(const Quantity& peer) const {
    float mantissa = (magnitude * peer.magnitude);
    Quantity result(mantissa, (scaling + peer.scaling), getUnit());
    return result;
}

Quantity Quantity::operator/(const Quantity& peer) const {
    float mantissa = (magnitude / peer.magnitude);
    Quantity result(mantissa, (scaling - peer.scaling), getUnit());
    return result;
}

Quantity Quantity::operator%(const Quantity& peer) const {
    short int exponent = (scaling - peer.scaling);
    float mantissa = fmod(magnitude, (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    Quantity result(mantissa, scaling, getUnit());
    return result;
}

std::complex<float> Quantity::getComplex(const float imaginary) const {
    std::complex<float> result(magnitude, imaginary);
    return result;
}

Quantity Quantity::getAbsolute() const {
    Quantity fresh(std::abs(magnitude), scaling, unit.getModulus());
    return fresh;
}

Quantity Quantity::getInverse() const {
    Quantity fresh(magnitude != DEFAULT_VALUE
        ? (1 / magnitude) : DEFAULT_VALUE, -scaling, unit.getInverse());
    fresh.adjustScaling();
    return fresh;
}

Quantity Quantity::getPercent() const {
    Quantity fresh(magnitude, scaling, unit.getPercent());
    return fresh;
}

Quantity Quantity::getSquare() const {
    double mantissa = magnitude;
    double newMagnitude = (mantissa * mantissa);
    Quantity fresh(static_cast<float>(newMagnitude), (scaling * 2), unit.getSquare());
    fresh.adjustScaling();
    return fresh;
}

Quantity Quantity::getSquareRoot() const {  // handle negative magnitude
    double mantissa = (magnitude * std::pow(DECIMAL_SCALE, scaling));
    std::complex<double> result = std::sqrt(mantissa);
    double newMagnitude = std::real(result);
    newMagnitude = (newMagnitude / std::pow(DECIMAL_SCALE, scaling));
    Quantity fresh(static_cast<float>(newMagnitude), scaling, unit.getSquareRoot());
    fresh.adjustScaling();
    return fresh;
}

Quantity Quantity::getCube() const {
    double mantissa = magnitude;
    double newMagnitude = (mantissa * mantissa * mantissa);
    Quantity fresh(static_cast<float>(newMagnitude), (scaling * 3), unit.getCube());
    fresh.adjustScaling();
    return fresh;
}

Quantity Quantity::getCubeRoot() const {
    double mantissa = (magnitude * std::pow(DECIMAL_SCALE, scaling));
    double newMagnitude = std::cbrt(mantissa);
    newMagnitude = (newMagnitude / std::pow(DECIMAL_SCALE, scaling));
    Quantity fresh(static_cast<float>(newMagnitude), scaling, unit.getCubeRoot());
    fresh.adjustScaling();
    return fresh;
}

bool Quantity::isConvergent() const {
    return (magnitude > DEFAULT_VALUE);
}

bool Quantity::isDivergent() const {
    return (magnitude < DEFAULT_VALUE);
}

bool Quantity::checkNonZero() const {
    return (magnitude != DEFAULT_VALUE);
}

bool Quantity::checkInfinity() const {
    return std::isinf(magnitude);
}

short int Quantity::checkScaling(const float amount) const {
    return log10(amount);
}

void Quantity::adjustNumeric() {
    if (std::isnan(magnitude)) {
        magnitude = Quantity::DEFAULT_VALUE;
    }
}

void Quantity::adjustScaling() {
    float current = magnitude;
    if (current == DEFAULT_VALUE) {
        return;
    }
    int exponent = static_cast<int>(std::floor(std::log10(std::fabs(current))));
    float mantissa = current / std::pow(DECIMAL_SCALE, exponent);
    scaling += exponent;
    magnitude = mantissa;
    return;
}

Quantity Quantity::copy() const {
    Quantity fresh(magnitude, scaling, unit);
    return fresh;
}

void Quantity::clear() {
    magnitude = DEFAULT_VALUE;
    scaling = DEFAULT_SCALE;
    unit.clear();
    return;
}

std::string Quantity::print() {
    std::stringstream result;
    result << magnitude << "ₑ";     // "₁₀" base 10
    result << scaling;
    result << unit.print();
	return result.str();
}

float Quantity::getCosComponent(const float phase) const {
    return getMagnitude() * cos(phase);
}

float Quantity::getSinComponent(const float phase) const {
    return getMagnitude() * sin(phase);
}

} // namespace shp