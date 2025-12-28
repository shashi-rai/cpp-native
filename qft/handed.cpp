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

#include "handed.h"

namespace qft {

const short int Handed::DEFAULT_VALUE = 0;  // e.g., -1 or +1 

Handed::Handed() : orientation(DEFAULT_VALUE) {

}

Handed::Handed(const short int direction) : orientation(direction) {

}

Handed::~Handed() {

}

bool Handed::operator==(const Handed& peer) const {
    return (orientation == peer.orientation);
}

Handed Handed::operator+(const Handed& peer) const {
    return Handed((orientation + peer.orientation));
}

Handed Handed::operator-(const Handed& peer) const {
    return Handed((orientation - peer.orientation));
}

Handed Handed::operator*(const Handed& peer) const {
    return Handed((orientation * peer.orientation));
}

Handed Handed::operator/(const Handed& peer) const {
    return Handed((orientation / peer.orientation));
}

Handed Handed::operator%(const Handed& peer) const {
    float result = fmod(orientation, peer.orientation);
    return Handed((result));
}

bool Handed::isLeft() const {
    return orientation < DEFAULT_VALUE;
}

bool Handed::isRight() const {
    return orientation > DEFAULT_VALUE;
}

Handed Handed::copy() {
    Handed fresh(orientation);
    return fresh;
}

void Handed::clear() {
    orientation = DEFAULT_VALUE;
    return;
}

std::string Handed::print() {
    std::stringstream result;
    result << "|";
    if (orientation == DEFAULT_VALUE)
        result << "Ψ";
    else
        result << (isLeft() ? "-" : "+");
    result << "⟩";
	return result.str();
}

} // namespace qft