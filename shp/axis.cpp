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

#include "axis.h"

namespace shp {

const float Axis::NORMAL = 1.570796326794897000f;           // 90 degrees rotation
const float Axis::DEFAULT_VALUE = Quantity::DEFAULT_VALUE;  // 0 degrees

Axis::Axis() : name(), gradient(DEFAULT_VALUE), scaling(DEFAULT_VALUE) {

}

Axis::Axis(std::string name)
        : name(name), gradient(DEFAULT_VALUE), scaling(DEFAULT_VALUE) {

}
Axis::Axis(const float gradient)
        : name(), gradient(gradient), scaling(DEFAULT_VALUE) {

}

Axis::Axis(std::string name, const float gradient)
        : name(name), gradient(gradient), scaling(DEFAULT_VALUE) {

}

Axis::Axis(std::string name, const float gradient, const float scaling)
        : name(name), gradient(gradient), scaling(scaling) {

}

Axis::~Axis() {

}

bool Axis::operator==(const Axis& peer) const {
    return (name == peer.name) && ((gradient == peer.gradient)) && (scaling == peer.scaling);
}

Axis Axis::operator+(const Axis& peer) const {
    return Axis("+", (gradient + (peer.gradient != 0 ? peer.gradient : NORMAL)), scaling);
}

Axis Axis::operator-(const Axis& peer) const {
    return Axis("-", (gradient - (peer.gradient != 0 ? peer.gradient : NORMAL)), scaling);
}

Axis Axis::copy() {
    Axis fresh(name, gradient, scaling);
    return fresh;
}

void Axis::clear() {
    name.clear(); gradient = scaling = DEFAULT_VALUE;
    return;
}

std::string Axis::print() {
    std::stringstream result;
    result << "{n:";
    result << name << ",𝜙:";
    result << gradient << ",s:";
    result << scaling << "}";
	return result.str();
}

} // namespace shp