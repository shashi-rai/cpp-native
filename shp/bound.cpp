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

#include "bound.h"

namespace shp {

const float Bound::DEFAULT_VALUE = 0.0f;     // 0.0f
const float Bound::DECIMAL_SCALE = 10.0f;    // 10.0f
const short int Bound::DEFAULT_SCALE = 0;    // 10^0

Bound::Bound()
        : magnitude(DEFAULT_VALUE), scaling(DEFAULT_SCALE) {

}

Bound::Bound(const float magnitude)
        : magnitude(magnitude), scaling(DEFAULT_SCALE) {

}

Bound::Bound(const float magnitude, const short int scaling)
        : magnitude(magnitude), scaling(scaling) {

}

Bound::~Bound() {

}

bool Bound::operator==(const Bound& peer) const {
    Bound self = *this;
    return (self.magnitude == peer.magnitude)
        && (self.scaling == peer.scaling);
}

bool Bound::operator<(const Bound& peer) const {
    Bound self = *this; bool result = false;
    if (self.magnitude < peer.magnitude) {
        result = true;
    } else if (self.scaling < peer.scaling) {
        result = true;
    }
    return result;
}

bool Bound::operator>(const Bound& peer) const {
    Bound self = *this; bool result = false;
    if (self.magnitude > peer.magnitude) {
        result = true;
    } else if (self.scaling > peer.scaling) {
        result = true;
    }
    return result;
}

bool Bound::operator<=(const Bound& peer) const {
    Bound self = *this;
    return (self < peer) || (self == peer);
}

bool Bound::operator>=(const Bound& peer) const {
    Bound self = *this;
    return (self > peer) || (self == peer);
}

Bound Bound::operator+(const Bound& peer) const {
    Bound self = *this;
    short int exponent = (self.scaling - peer.scaling);
    float mantissa = (self.magnitude + (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    return Bound(mantissa, self.scaling);
}

Bound Bound::operator-(const Bound& peer) const {
    Bound self = *this;
    short int exponent = (self.scaling - peer.scaling);
    float mantissa = (self.magnitude - (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    return Bound(mantissa, self.scaling);
}

Bound Bound::operator*(const Bound& peer) const {
    Bound self = *this;
    float mantissa = (self.magnitude * peer.magnitude);
    return Bound(mantissa, (self.scaling + peer.scaling));
}

Bound Bound::operator/(const Bound& peer) const {
    Bound self = *this; float mantissa = DEFAULT_VALUE;
    if (peer.magnitude != DEFAULT_VALUE) {
        mantissa = (self.magnitude / peer.magnitude);
    }
    return Bound(mantissa, (self.scaling - peer.scaling));
}

Bound Bound::operator%(const Bound& peer) const {
    Bound self = *this; float mantissa = DEFAULT_VALUE;
    short int exponent = (self.scaling - peer.scaling);
    if (peer.magnitude != DEFAULT_VALUE) {
        mantissa = fmod(self.magnitude, (peer.magnitude / std::pow(DECIMAL_SCALE, exponent)));
    }
    return Bound(mantissa, self.scaling);
}

void Bound::setMagnitude(const float value, const short int scale) {
    this->magnitude = value;
    this->scaling = scale;
}

double Bound::getZeroScale() const {
    return (magnitude * std::pow(DECIMAL_SCALE, scaling));
}

Bound Bound::getAbsolute() const {
    return Bound(std::abs(magnitude), scaling);
}

Bound Bound::getNegative() const {
    return Bound(-magnitude, scaling);
}

Bound Bound::getInverse() const {
    Bound fresh((magnitude != DEFAULT_VALUE)
        ? (1 / magnitude) : DEFAULT_VALUE, -scaling);
    fresh.adjustScaling();
    return fresh;
}

Bound Bound::getSquare() const {
    double mantissa = magnitude, newMagnitude = (mantissa * mantissa);
    Bound fresh(static_cast<float>(newMagnitude), (scaling * 2));
    fresh.adjustScaling();
    return fresh;
}

Bound Bound::getSquareRoot() const {  // handle negative magnitude
    double mantissa = (magnitude * std::pow(DECIMAL_SCALE, scaling));
    std::complex<double> result = std::sqrt(mantissa);
    double newMagnitude = std::real(result);
    newMagnitude = (newMagnitude / std::pow(DECIMAL_SCALE, scaling));
    Bound fresh(static_cast<float>(newMagnitude), scaling);
    fresh.adjustScaling();
    return fresh;
}

Bound Bound::getCube() const {
    double mantissa = magnitude, newMagnitude = (mantissa * mantissa * mantissa);
    Bound fresh(static_cast<float>(newMagnitude), (scaling * 3));
    fresh.adjustScaling();
    return fresh;
}

Bound Bound::getCubeRoot() const {
    double mantissa = (magnitude * std::pow(DECIMAL_SCALE, scaling));
    double newMagnitude = std::cbrt(mantissa);
    newMagnitude = (newMagnitude / std::pow(DECIMAL_SCALE, scaling));
    Bound fresh(static_cast<float>(newMagnitude), scaling);
    fresh.adjustScaling();
    return fresh;
}

Bound Bound::getMultiple(const float coefficient) const {
    Bound self = *this;
    float mantissa = (self.magnitude * coefficient);
    Bound result(mantissa, self.scaling);
    return result;
}

Bound Bound::getFraction(const float coefficient) const {
    Bound self = *this; float mantissa = Bound::DEFAULT_VALUE;
    if (self.magnitude != Bound::DEFAULT_VALUE) {
        mantissa = (coefficient / self.magnitude);
    }
    Bound result(mantissa, self.scaling);
    return result;
}

Bound Bound::getDivision(const float coefficient) const {
    Bound self = *this; float mantissa = Bound::DEFAULT_VALUE;
    if (coefficient != Bound::DEFAULT_VALUE) {
        mantissa = (self.magnitude / coefficient);
    }
    Bound result(mantissa, self.scaling);
    return result;
}

Bound Bound::getRemainder(const float coefficient) const {
    Bound self = *this; float mantissa = Bound::DEFAULT_VALUE;
    if (coefficient != Bound::DEFAULT_VALUE) {
        mantissa = fmod(self.magnitude, coefficient);
    }
    Bound result(mantissa, self.scaling);
    return result;
}

Bound Bound::getLeftOver(const float coefficient) const {
    Bound self = *this; float mantissa = Bound::DEFAULT_VALUE;
    if (coefficient != Bound::DEFAULT_VALUE) {
        mantissa = (self.magnitude - coefficient);
    }
    Bound result(mantissa, self.scaling);
    return result;
}

bool Bound::isConvergent() const {
    return (magnitude > DEFAULT_VALUE);
}

bool Bound::isDivergent() const {
    return (magnitude < DEFAULT_VALUE);
}

bool Bound::checkNonZero() const {
    return (magnitude != DEFAULT_VALUE);
}

bool Bound::checkInfinity() const {
    return std::isinf(magnitude);
}

short int Bound::checkScaling(const float amount) const {
    return log10(amount);
}

void Bound::adjustNumeric() {
    if (checkInfinity()) {
        scaling = Bound::DEFAULT_SCALE;
    } else if (std::isnan(magnitude)) {
        magnitude = Bound::DEFAULT_VALUE;
        scaling = Bound::DEFAULT_SCALE;
    }
}

void Bound::adjustScaling() {
    float current = magnitude;
    if (current == DEFAULT_VALUE) {
        return;
    }
    int exponent = static_cast<int>(std::floor(std::log10(std::fabs(current))));
    float mantissa = current / std::pow(DECIMAL_SCALE, exponent);
    scaling += exponent;
    magnitude = mantissa;
}

Bound Bound::copy() const {
    return Bound(magnitude, scaling);
}

void Bound::clear() {
    magnitude = DEFAULT_VALUE;
    scaling = DEFAULT_SCALE;
    return;
}

std::string Bound::print() const {
    std::stringstream result;
    result << magnitude << "ₑ";
    result << scaling;
	return result.str();
}

float Bound::getCosComponent(const float phase) const {
    return (magnitude * cos(phase));
}

float Bound::getSinComponent(const float phase) const {
    return (magnitude * sin(phase));
}

float Bound::getCosHyperbola(const float phase) const {
    return (magnitude * cosh(phase));
}

float Bound::getSinHyperbola(const float phase) const {
    return (magnitude * sinh(phase));
}

const std::complex<float> Bound::getComplex(const float value, const float direction) {
    return std::complex<float>(value, direction);
}

} // namespace shp