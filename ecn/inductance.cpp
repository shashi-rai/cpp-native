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

#include "inductance.h"

namespace ecn {

Inductance::Inductance() : threshold() {

}

Inductance::Inductance(const shp::Potential& threshold) : threshold(threshold) {

}

Inductance::~Inductance() {
    threshold.clear();
}

bool Inductance::operator==(const Inductance& peer) const {
    return (threshold == peer.threshold);
}

Inductance Inductance::operator+(const Inductance& peer) const {
    return Inductance(threshold + peer.threshold);
}

Inductance Inductance::operator-(const Inductance& peer) const {
    return Inductance(threshold - peer.threshold);
}

Inductance Inductance::operator*(const Inductance& peer) const {
    return Inductance(threshold * peer.threshold);
}

Inductance Inductance::operator/(const Inductance& peer) const {
    return Inductance(threshold / peer.threshold);
}

Inductance Inductance::operator%(const Inductance& peer) const {
    return Inductance(threshold % peer.threshold);
}

Inductance Inductance::copy() {
    Inductance fresh(threshold);
    return fresh;
}

void Inductance::clear() {
    threshold.clear();
    return;
}

std::string Inductance::print() {
    std::stringstream result;
    result << threshold.print();
	return result.str();
}

} // namespace ecn