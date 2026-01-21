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

#include "proportion.h"

namespace shp {

const float Proportion::DEFAULT_MAX = 1.0f;

Proportion::Proportion()
        : numerator(), denominator() {

}

Proportion::Proportion(const Signal& numerator)
        : numerator(numerator), denominator() {

}

Proportion::Proportion(const float numerator)
		: numerator(numerator), denominator() {

}

Proportion::Proportion(const float numerator, const short int scaling)
        : numerator(numerator, scaling), denominator(scaling) {

}

Proportion::Proportion(const float numerator, const short int scaling, const std::string unit)
        : numerator(numerator, scaling, unit), denominator(scaling, unit) {

}

Proportion::Proportion(const float numerator, const short int scaling, const Unit& unit)
        : numerator(numerator, scaling, unit), denominator(scaling, unit) {

}

Proportion::Proportion(const Signal& numerator, const Signal& denominator)
        : numerator(numerator), denominator(denominator) {

}

Proportion::Proportion(const float numerator, const float denominator)
        : numerator(numerator), denominator(denominator) {

}

Proportion::Proportion(const float numerator, const float denominator,
        const short int scaling)
        : numerator(numerator, scaling), denominator(denominator, scaling) {

}

Proportion::Proportion(const float numerator, const float denominator,
        const short int scaling, const std::string unit)
        : numerator(numerator, scaling, unit), denominator(denominator, scaling, unit) {

}

Proportion::Proportion(const float numerator, const float denominator,
        const short int scaling, const Unit& unit)
        : numerator(numerator, scaling, unit), denominator(denominator, scaling, unit) {

}

Proportion::~Proportion() {

}

bool Proportion::operator==(const Proportion& peer) const {
    return (numerator == peer.numerator) && (denominator == peer.denominator);
}

bool Proportion::operator<(const Proportion& peer) const {
    return (numerator < peer.numerator) && (denominator < peer.denominator);
}

bool Proportion::operator>(const Proportion& peer) const {
    return (numerator > peer.numerator) && (denominator > peer.denominator);
}

bool Proportion::operator<=(const Proportion& peer) const {
    Proportion self = *this;
    return (self < peer) || (self == peer);
}

bool Proportion::operator>=(const Proportion& peer) const {
    Proportion self = *this;
    return (self > peer) || (self == peer);
}

Proportion Proportion::operator+(const Proportion& peer) const {
    return Proportion((numerator + peer.numerator), (denominator + peer.denominator));
}

Proportion Proportion::operator-(const Proportion& peer) const {
    return Proportion((numerator - peer.numerator), (denominator - peer.denominator));
}

Proportion Proportion::operator*(const Proportion& peer) const {
    return Proportion((numerator * peer.numerator), (denominator * peer.denominator));
}

Proportion Proportion::operator/(const Proportion& peer) const {
    return Proportion((numerator / peer.numerator), (denominator / peer.denominator));
}

Proportion Proportion::operator%(const Proportion& peer) const {
    return Proportion((numerator % peer.numerator), (denominator % peer.denominator));
}

Signal Proportion::getRemainder() const {
    Signal ratio = this->getRatio();
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), (DEFAULT_MAX - ratio.getMagnitude()), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getRatio() const {
    Signal ratio = (numerator / denominator);
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getInverse() const {
    Signal ratio = (denominator / numerator);
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getSquareDot() const {
    Signal ratio = (numerator.getDotProductSquare() / denominator.getDotProductSquare());
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getSquareRootDot() const {
    Signal ratio = (numerator.getDotProductSquareRoot() / denominator.getDotProductSquareRoot());
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getInverseSquareDot() const {
    Signal ratio = (denominator.getDotProductSquare() / numerator.getDotProductSquare());
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getInverseSquareRootDot() const {
    Signal ratio = (denominator.getDotProductSquareRoot() / numerator.getDotProductSquareRoot());
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getSquareCross() const {
    Signal ratio = (numerator.getCrossProductSquare() / denominator.getCrossProductSquare());
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Signal Proportion::getInverseSquareCross() const {
    Signal ratio = (denominator.getCrossProductSquare() / numerator.getCrossProductSquare());
    ratio.adjustScaling();
    return Signal(ratio.getOrientation(), ratio.getMagnitude(), ratio.getScaling(), ratio.getUnit());
}

Proportion Proportion::copy() {
    Proportion fresh(numerator, denominator);
    return fresh;
}

void Proportion::clear() {
    numerator.clear();
    denominator.clear();
    return;
}

std::string Proportion::print() const {
    std::stringstream result;
    result << "{";
    result << numerator.print() << ",";
	result << denominator.print() << "}";
	return result.str();
}

} // namespace shp