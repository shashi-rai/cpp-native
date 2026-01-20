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

const std::string Quantity::DEFAULT_TEXT = "";  // Empty
const float Quantity::DEFAULT_VALUE = 0.0f;     // 0.0f
const float Quantity::DECIMAL_SCALE = 10.0f;    // 10.0f
const short int Quantity::DEFAULT_SCALE = 0;    // 10^0

Quantity::Quantity()
        : magnitude(DEFAULT_VALUE), scaling(DEFAULT_SCALE), unit(DEFAULT_TEXT) {

}

Quantity::Quantity(const float magnitude)
        : magnitude(magnitude), scaling(DEFAULT_SCALE), unit(DEFAULT_TEXT) {

}

Quantity::Quantity(const short int scaling)
        : magnitude(), scaling(scaling), unit(DEFAULT_TEXT) {

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
        : magnitude(magnitude), scaling(scaling), unit(DEFAULT_TEXT) {

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
    Quantity self = *this;
    short int exponent = (self.scaling - peer.scaling);
    float mantissa = (self.magnitude + (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

Quantity Quantity::operator-(const Quantity& peer) const {
    Quantity self = *this;
    short int exponent = (self.scaling - peer.scaling);
    float mantissa = (self.magnitude - (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

Quantity Quantity::operator*(const Quantity& peer) const {
    Quantity self = *this;
    float mantissa = (self.magnitude * peer.magnitude);
    Quantity result(mantissa, (self.scaling + peer.scaling), self.getUnit());
    return result;
}

Quantity Quantity::operator/(const Quantity& peer) const {
    Quantity self = *this; float mantissa = DEFAULT_VALUE;
    if (peer.magnitude != DEFAULT_VALUE) {
        mantissa = (self.magnitude / peer.magnitude);
    }
    Quantity result(mantissa, (self.scaling - peer.scaling), self.getUnit());
    return result;
}

Quantity Quantity::operator%(const Quantity& peer) const {
    Quantity self = *this; float mantissa = DEFAULT_VALUE;
    short int exponent = (self.scaling - peer.scaling);
    if (peer.magnitude != DEFAULT_VALUE) {
        mantissa = fmod(self.magnitude, (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    }
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

void Quantity::setMagnitude(const float value, const short int scale) {
    this->magnitude = value;
    this->scaling = scale;
}

void Quantity::setMagnitude(const float value, const short int scale, const std::string unit) {
    this->magnitude = value;
    this->scaling = scale;
    this->unit.setName(unit);
}

void Quantity::setMagnitude(const float value, const short int scale, const Unit& unit) {
    this->magnitude = value;
    this->scaling = scale;
    this->unit = unit;
}

void Quantity::setUnit(const std::string name) {
    this->unit.setName(name);
}

double Quantity::getZeroScale() const {
    return (magnitude * std::pow(DECIMAL_SCALE, scaling));
}

Quantity Quantity::getAbsolute() const {
    Quantity fresh(std::abs(magnitude), scaling, unit.getModulus());
    return fresh;
}

Quantity Quantity::getNegative() const {
    Quantity fresh(-magnitude, scaling, unit.getModulus());
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

Quantity Quantity::getMultiple(const float coefficient) const {
    Quantity self = *this;
    float mantissa = (self.magnitude * coefficient);
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

Quantity Quantity::getFraction(const float coefficient) const {
    Quantity self = *this; float mantissa = Quantity::DEFAULT_VALUE;
    if (self.magnitude != Quantity::DEFAULT_VALUE) {
        mantissa = (coefficient / self.magnitude);
    }
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

Quantity Quantity::getDivision(const float coefficient) const {
    Quantity self = *this; float mantissa = Quantity::DEFAULT_VALUE;
    if (coefficient != Quantity::DEFAULT_VALUE) {
        mantissa = (self.magnitude / coefficient);
    }
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

Quantity Quantity::getRemainder(const float coefficient) const {
    Quantity self = *this; float mantissa = Quantity::DEFAULT_VALUE;
    if (coefficient != Quantity::DEFAULT_VALUE) {
        mantissa = fmod(self.magnitude, coefficient);
    }
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
}

Quantity Quantity::getLeftOver(const float coefficient) const {
    Quantity self = *this; float mantissa = Quantity::DEFAULT_VALUE;
    if (coefficient != Quantity::DEFAULT_VALUE) {
        mantissa = (self.magnitude - coefficient);
    }
    Quantity result(mantissa, self.scaling, self.getUnit());
    return result;
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
    if (checkInfinity()) {
        scaling = Quantity::DEFAULT_SCALE;
    } else if (std::isnan(magnitude)) {
        magnitude = Quantity::DEFAULT_VALUE;
        scaling = Quantity::DEFAULT_SCALE;
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

std::string Quantity::print() const {
	return printSuffixed();
}

std::string Quantity::printSuffixed() const {
    std::stringstream result;
    result << magnitude << "ₑ";
    result << scaling;
    result << unit.print();
	return result.str();
}

std::string Quantity::printPrefixed() const {
    std::stringstream result;
    result << unit.print() << " ";
    result << magnitude << "ₑ";
    result << scaling;
	return result.str();
}

float Quantity::getCosComponent(const float phase) const {
    return (magnitude * cos(phase));
}

float Quantity::getSinComponent(const float phase) const {
    return (magnitude * sin(phase));
}

const std::complex<float> Quantity::getComplex(const float value, const float direction) {
    return std::complex<float>(value, direction);
}

} // namespace shp