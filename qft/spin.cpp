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

#include "spin.h"

namespace qft {

const float Spin::DEFAULT_VALUE = shp::Quantity::DEFAULT_VALUE; // e.g., -1/2 or +1/2 

Spin::Spin() : value(DEFAULT_VALUE) {

}

Spin::Spin(const float value) : value(value) {

}

Spin::~Spin() {

}

bool Spin::operator==(const Spin& peer) const {
    return (value == peer.value);
}

Spin Spin::operator+(const Spin& peer) const {
    return Spin((value + peer.value));
}

Spin Spin::operator-(const Spin& peer) const {
    return Spin((value - peer.value));
}

Spin Spin::operator*(const Spin& peer) const {
    return Spin((value * peer.value));
}

Spin Spin::operator/(const Spin& peer) const {
    return Spin((value / peer.value));
}

Spin Spin::operator%(const Spin& peer) const {
    float result = fmod(value, peer.value);
    return Spin((result));
}

bool Spin::hasNoSpin() const {
    return value == DEFAULT_VALUE;
}

bool Spin::isClockwise() const {
    return value < DEFAULT_VALUE;
}

bool Spin::isAntiClockwise() const {
    return value > DEFAULT_VALUE;
}

Spin Spin::copy() {
    Spin fresh(value);
    return fresh;
}

void Spin::clear() {
    value = DEFAULT_VALUE;
    return;
}

std::string Spin::print() const {
    std::stringstream result;
    result << "|";
    if (hasNoSpin())
        result << "Ψ";
    else
        result << (isClockwise() ? "-" : "+");
    result << "⟩";
	return result.str();
}

} // namespace qft