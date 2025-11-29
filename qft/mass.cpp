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

#include "mass.h"

namespace qft {

Mass::Mass() : unit(), mass(0.0f) {

}

Mass::Mass(float mass) : unit(), mass(mass) {

}

Mass::Mass(const shp::Unit& unit, float mass) : unit(unit), mass(mass) {

}

Mass::~Mass() {

}

bool Mass::operator==(const Mass& peer) const {
    return (unit == peer.unit) && (mass == peer.mass);
}

Mass Mass::operator+(const Mass& peer) const {
    return Mass(mass + peer.mass);
}

Mass Mass::operator-(const Mass& peer) const {
    return Mass(mass - peer.mass);
}

Mass Mass::copy() {
    Mass fresh(unit, mass);
    return fresh;
}

void Mass::clear() {
    unit.clear();
    mass = 0.0f;
    return;
}

std::string Mass::print() {
    std::stringstream result;
    result << "(";
    result << mass << " ";
    result << unit.print() << ")";
	return result.str();
}

} // namespace qft