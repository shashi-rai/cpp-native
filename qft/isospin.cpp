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

#include "isospin.h"

namespace qft {

const float Isospin::DEFAULT_VALUE = shp::Quantity::DEFAULT_VALUE; // e.g., -1/2 or +1/2 

Isospin::Isospin() : value(DEFAULT_VALUE) {

}

Isospin::Isospin(const float value) : value(value) {

}

Isospin::~Isospin() {

}

bool Isospin::operator==(const Isospin& peer) const {
    return (value == peer.value);
}

Isospin Isospin::operator+(const Isospin& peer) const {
    return Isospin((value + peer.value));
}

Isospin Isospin::operator-(const Isospin& peer) const {
    return Isospin((value - peer.value));
}

Isospin Isospin::operator*(const Isospin& peer) const {
    return Isospin((value * peer.value));
}

Isospin Isospin::operator/(const Isospin& peer) const {
    return Isospin((value / peer.value));
}

Isospin Isospin::operator%(const Isospin& peer) const {
    float result = fmod(value, peer.value);
    return Isospin((result));
}

bool Isospin::hasNoIsospin() const {
    return value == DEFAULT_VALUE;
}

bool Isospin::isClockwise() const {
    return value < DEFAULT_VALUE;
}

bool Isospin::isAntiClockwise() const {
    return value > DEFAULT_VALUE;
}

Isospin Isospin::copy() {
    Isospin fresh(value);
    return fresh;
}

void Isospin::clear() {
    value = DEFAULT_VALUE;
    return;
}

std::string Isospin::print() const {
    std::stringstream result;
    result << "T3|";
    if (hasNoIsospin())
        result << "Ψ";
    else
        result << (isClockwise() ? "-" : "+");
    result << "⟩";
	return result.str();
}

} // namespace qft