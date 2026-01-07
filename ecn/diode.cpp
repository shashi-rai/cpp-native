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

#include "diode.h"

namespace ecn { 

Diode::Diode()
        : Switch(), threshold() {

}

Diode::Diode(const bool status)
        : Switch(status), threshold() {

}

Diode::Diode(const shp::Potential& threshold)
        : Switch(), threshold(threshold) {

}

Diode::Diode(const Conductor& positive, const Conductor& negative)
        : Switch(positive, negative), threshold() {

}

Diode::Diode(const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold)
        : Switch(positive, negative), threshold(threshold) {

}

Diode::Diode(const bool status, const shp::Potential& threshold)
        : Switch(status), threshold(threshold) {

}

Diode::Diode(const bool status, const Conductor& positive, const Conductor& negative)
        : Switch(status, positive, negative), threshold() {

}

Diode::Diode(const bool status, const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold)
        : Switch(status, positive, negative), threshold(threshold) {

}

Diode::Diode(std::string name)
        : Switch(name), threshold() {

}

Diode::Diode(std::string name, const bool status)
        : Switch(name, status), threshold() {

}

Diode::Diode(std::string name, const shp::Potential& threshold)
        : Switch(name), threshold(threshold) {

}

Diode::Diode(std::string name, const Conductor& positive, const Conductor& negative)
        : Switch(name, positive, negative), threshold() {

}

Diode::Diode(std::string name, const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold)
        : Switch(name, positive, negative), threshold(threshold) {

}

Diode::Diode(std::string name, const bool status, const shp::Potential& threshold)
        : Switch(name, status), threshold(threshold) {

}

Diode::Diode(std::string name, const bool status, const Conductor& positive, const Conductor& negative)
        : Switch(name, status, positive, negative), threshold() {

}

Diode::Diode(std::string name, const bool status, const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold)
        : Switch(name, status, positive, negative), threshold(threshold) {

}

Diode::~Diode() {

}

bool Diode::operator==(const Diode& peer) const {
    return (static_cast<const Switch&>(*this) == static_cast<const Switch&>(peer))
        && (threshold == peer.threshold);
}

Diode Diode::operator+(const Diode& peer) const {
    Switch self = *this, other = peer;
    Switch result = (self + other);
    return Diode("+", result.getStatus(), result.getPositive(), result.getNegative(),
        (threshold + peer.threshold));
}

Diode Diode::operator-(const Diode& peer) const {
    Switch self = *this, other = peer;
    Switch result = (self - other);
    return Diode("-", result.getStatus(), result.getPositive(), result.getNegative(),
        (threshold - peer.threshold));
}

Diode Diode::operator*(const Diode& peer) const {
    Switch self = *this, other = peer;
    Switch result = (self * other);
    return Diode("*", result.getStatus(), result.getPositive(), result.getNegative(),
        (threshold * peer.threshold));
}

Diode Diode::operator/(const Diode& peer) const {
    Switch self = *this, other = peer;
    Switch result = (self / other);
    return Diode("/", result.getStatus(), result.getPositive(), result.getNegative(),
        (threshold / peer.threshold));
}

Diode Diode::operator%(const Diode& peer) const {
    Switch self = *this, other = peer;
    Switch result = (self % other);
    return Diode("%", result.getStatus(), result.getPositive(), result.getNegative(),
        (threshold % peer.threshold));
}

Circuit Diode::copy() {
    Diode fresh(getName(), getStatus(), getPositive(), getNegative(), threshold);
    return fresh;
}

void Diode::clear() {
    Switch::clear();
    threshold.clear();
    return;
}

std::string Diode::print() {
    std::stringstream result;
    result << Switch::print() << ",t:";
    result << threshold.print();
	return result.str();
}

} // namespace ecn