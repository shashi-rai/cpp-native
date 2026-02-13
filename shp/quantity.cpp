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
        : Bound(DEFAULT_VALUE, DEFAULT_SCALE), unit(DEFAULT_TEXT) {

}

Quantity::Quantity(const float magnitude)
        : Bound(magnitude, DEFAULT_SCALE), unit(DEFAULT_TEXT) {

}

Quantity::Quantity(const short int scaling)
        : Bound(DEFAULT_VALUE, scaling), unit(DEFAULT_TEXT) {

}

Quantity::Quantity(const std::string unit)
        : Bound(DEFAULT_VALUE, DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const Unit& unit)
        : Bound(DEFAULT_VALUE, DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const short int scaling, const std::string unit)
        : Bound(DEFAULT_VALUE, scaling), unit(unit) {

}

Quantity::Quantity(const short int scaling, const Unit& unit)
        : Bound(DEFAULT_VALUE, scaling), unit(unit) {

}

Quantity::Quantity(const float magnitude, const std::string unit)
        : Bound(magnitude, DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const float magnitude, const Unit& unit)
        : Bound(magnitude, DEFAULT_SCALE), unit(unit) {

}

Quantity::Quantity(const float magnitude, const short int scaling)
        : Bound(magnitude, scaling), unit(DEFAULT_TEXT) {

}

Quantity::Quantity(const float magnitude, const short int scaling, const std::string unit)
        : Bound(magnitude, scaling), unit(unit) {

}

Quantity::Quantity(const float magnitude, const short int scaling, const Unit& unit)
        : Bound(magnitude, scaling), unit(unit) {

}

Quantity::~Quantity() {

}

bool Quantity::operator==(const Quantity& peer) const {
    Quantity self = *this;
    return (static_cast<const Bound&>(*this) == static_cast<const Bound&>(peer))
        && (self.unit == peer.unit);
}

bool Quantity::operator<(const Quantity& peer) const {
    Quantity self = *this; bool result = false;
    if (static_cast<const Bound&>(*this) < static_cast<const Bound&>(peer)) {
        result = true;
    }
    return result;
}

bool Quantity::operator>(const Quantity& peer) const {
    Quantity self = *this; bool result = false;
    if (static_cast<const Bound&>(*this) > static_cast<const Bound&>(peer)) {
        result = true;
    }
    return result;
}

bool Quantity::operator<=(const Quantity& peer) const {
    Quantity self = *this;
    return (self < peer) || (self == peer);
}

bool Quantity::operator>=(const Quantity& peer) const {
    Quantity self = *this;
    return (self > peer) || (self == peer);
}

Quantity Quantity::operator+(const Quantity& peer) const {
    Bound self = *this, other = peer, result = (self + other);
    return Quantity(result.getMagnitude(), result.getScaling(), this->getUnit());
}

Quantity Quantity::operator-(const Quantity& peer) const {
    Bound self = *this, other = peer, result = (self - other);
    return Quantity(result.getMagnitude(), result.getScaling(), this->getUnit());
}

Quantity Quantity::operator*(const Quantity& peer) const {
    Bound self = *this, other = peer, result = (self * other);
    return Quantity(result.getMagnitude(), result.getScaling(), this->getUnit());
}

Quantity Quantity::operator/(const Quantity& peer) const {
    Bound self = *this, other = peer, result = (self / other);
    return Quantity(result.getMagnitude(), result.getScaling(), this->getUnit());
}

Quantity Quantity::operator%(const Quantity& peer) const {
    Bound self = *this, other = peer, result = (self % other);
    return Quantity(result.getMagnitude(), result.getScaling(), this->getUnit());
}

float Quantity::getMagnitude() const {
    return Bound::getMagnitude();
}

void Quantity::setMagnitude(const float value) {
    Bound::setMagnitude(value);
}

void Quantity::setMagnitude(const float value, const short int scale) {
    Bound::setMagnitude(value, scale);
}

void Quantity::setMagnitude(const float value, const short int scale, const std::string unit) {
    Bound::setMagnitude(value, scale);
    this->unit.setName(unit);
}

void Quantity::setMagnitude(const float value, const short int scale, const Unit& unit) {
    Bound::setMagnitude(value, scale);
    this->unit = unit;
}

short int Quantity::getScaling() const {
    return Bound::getScaling();
}

void Quantity::setScaling(const short int factor) {
    Bound::setScaling(factor);
}

void Quantity::setUnit(const std::string name) {
    this->unit.setName(name);
}

double Quantity::getZeroScale() const {
    return Bound::getZeroScale();
}

Quantity Quantity::getAbsolute() const {
    Bound quantity = Bound::getAbsolute();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getModulus());
}

Quantity Quantity::getNegative() const {
    Bound quantity = Bound::getNegative();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getModulus());
}

Quantity Quantity::getInverse() const {
    Bound quantity = Bound::getInverse();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getInverse());
}

Quantity Quantity::getPercent() const {
    Bound quantity = Bound::getAbsolute();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getPercent());
}

Quantity Quantity::getSquare() const {
    Bound quantity = Bound::getSquare();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getSquare());
}

Quantity Quantity::getSquareRoot() const {  // handle negative magnitude
    Bound quantity = Bound::getSquareRoot();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getSquareRoot());
}

Quantity Quantity::getCube() const {
    Bound quantity = Bound::getCube();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getCube());
}

Quantity Quantity::getCubeRoot() const {
    Bound quantity = Bound::getCubeRoot();
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), unit.getCubeRoot());
}

Quantity Quantity::getMultiple(const float coefficient) const {
    Bound quantity = Bound::getMultiple(coefficient);
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), this->getUnit());
}

Quantity Quantity::getFraction(const float coefficient) const {
    Bound quantity = Bound::getFraction(coefficient);
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), this->getUnit());
}

Quantity Quantity::getDivision(const float coefficient) const {
    Bound quantity = Bound::getDivision(coefficient);
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), this->getUnit());
}

Quantity Quantity::getRemainder(const float coefficient) const {
    Bound quantity = Bound::getRemainder(coefficient);
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), this->getUnit());
}

Quantity Quantity::getLeftOver(const float coefficient) const {
    Bound quantity = Bound::getLeftOver(coefficient);
    return Quantity(quantity.getMagnitude(), quantity.getScaling(), this->getUnit());
}

bool Quantity::isConvergent() const {
    return Bound::isConvergent();
}

bool Quantity::isDivergent() const {
    return Bound::isDivergent();
}

bool Quantity::checkNonZero() const {
    return Bound::checkNonZero();
}

bool Quantity::checkInfinity() const {
    return Bound::checkInfinity();
}

short int Quantity::checkScaling(const float amount) const {
    return Bound::checkScaling(amount);
}

void Quantity::adjustNumeric() {
    Bound::adjustNumeric();
}

void Quantity::adjustScaling() {
    Bound::adjustScaling();
}

Quantity Quantity::copy() const {
    return Quantity(Bound::getMagnitude(), Bound::getScaling(), unit);
}

void Quantity::clear() {
    Bound::clear();
    unit.clear();
    return;
}

std::string Quantity::print() const {
	return printSuffixed();
}

std::string Quantity::printSuffixed() const {
    std::stringstream result;
    result << Bound::print();
    result << unit.print();
	return result.str();
}

std::string Quantity::printPrefixed() const {
    std::stringstream result;
    result << unit.print() << " ";
    result << Bound::print();
	return result.str();
}

float Quantity::getCosComponent(const float phase) const {
    return Bound::getCosComponent(phase);
}

float Quantity::getSinComponent(const float phase) const {
    return Bound::getSinComponent(phase);
}

float Quantity::getCosHyperbola(const float phase) const {
    return Bound::getCosHyperbola(phase);
}

float Quantity::getSinHyperbola(const float phase) const {
    return Bound::getSinHyperbola(phase);
}

const std::complex<float> Quantity::getComplex(const float value, const float direction) {
    return Bound::getComplex(value, direction);
}

} // namespace shp