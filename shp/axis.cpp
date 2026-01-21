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

// Normal - 90 degrees rotation
const float Axis::NORMAL_RADIANS = 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533240000000000f;

Axis::Axis()
        : name(), gradient(Direction::DEFAULT_RADIANS), scaling(Quantity::DEFAULT_SCALE) {

}

Axis::Axis(const std::string name)
        : name(name), gradient(Direction::DEFAULT_RADIANS), scaling(Quantity::DEFAULT_SCALE) {

}

Axis::Axis(const float gradient)
        : name(), gradient(gradient), scaling(Quantity::DEFAULT_SCALE) {

}

Axis::Axis(const Direction& gradient)
        : name(), gradient(gradient.toRadians()), scaling(Quantity::DEFAULT_SCALE) {

}

Axis::Axis(const std::string name, const float gradient)
        : name(name), gradient(gradient), scaling(Quantity::DEFAULT_SCALE) {

}

Axis::Axis(const std::string name, const Direction& gradient)
        : name(name), gradient(gradient.toRadians()), scaling(Quantity::DEFAULT_SCALE) {

}

Axis::Axis(const std::string name, const float gradient, const short int scaling)
        : name(name), gradient(gradient), scaling(scaling) {

}

Axis::Axis(const std::string name, const Direction& gradient, const short int scaling)
        : name(name), gradient(gradient.toRadians()), scaling(scaling) {

}

Axis::~Axis() {

}

bool Axis::operator==(const Axis& peer) const {
    Axis self = *this;
    if (self.gradient == peer.gradient)
        return true;
    if (self.scaling == peer.scaling)
        return true;
    if (self.name == peer.name) {
        return true;
    }
    return false;
}

bool Axis::operator<(const Axis& peer) const {
    Axis self = *this;
    if (self.gradient < peer.gradient)
        return true;
    if (self.scaling < peer.scaling)
        return true;
    return false;
}

bool Axis::operator>(const Axis& peer) const {
    Axis self = *this;
    if (self.gradient > peer.gradient)
        return true;
    if (self.scaling > peer.scaling)
        return true;
    return false;
}

bool Axis::operator<=(const Axis& peer) const {
    Axis self = *this;
    return (self < peer) || (self == peer);
}

bool Axis::operator>=(const Axis& peer) const {
    Axis self = *this;
    return (self > peer) || (self == peer);
}

Axis Axis::operator+(const Axis& peer) const {
    return Axis("+", (gradient + (peer.gradient != 0 ? peer.gradient : NORMAL_RADIANS)), scaling);
}

Axis Axis::operator-(const Axis& peer) const {
    return Axis("-", (gradient - (peer.gradient != 0 ? peer.gradient : NORMAL_RADIANS)), scaling);
}

Axis Axis::copy() {
    Axis fresh(name, gradient, scaling);
    return fresh;
}

void Axis::clear() {
    name.clear();
    gradient = NORMAL_RADIANS;
    scaling = Quantity::DEFAULT_SCALE;
    return;
}

std::string Axis::print() const {
    std::stringstream result;
    result << "{n:";
    result << name << ",𝜙:";
    result << Direction(gradient).print() << ",s:";
    result << scaling << "}";
	return result.str();
}

std::string Axis::printRadians() const {
    std::stringstream result;
    result << "{n:";
    result << name << ",𝜙:";
    result << std::setfill('0') <<  std::setprecision(8)
        << gradient << shp::Unit::getDerivedSymbol(shp::Unit::PLANE_ANGLE);
    result << ",s:";
    result << scaling << "}";
	return result.str();
}

} // namespace shp