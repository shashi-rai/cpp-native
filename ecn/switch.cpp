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

#include "switch.h"

namespace ecn {

const bool Switch::DEFAULT_FLAG = false;

Switch::Switch()
        : Circuit(), status(DEFAULT_FLAG) {

}

Switch::Switch(const bool status)
        : Circuit(), status(status) {

}

Switch::Switch(const Conductor& positive, const Conductor& negative)
        : Circuit(positive, negative), status(DEFAULT_FLAG) {

}

Switch::Switch(const bool status, const Conductor& positive, const Conductor& negative)
        : Circuit(positive, negative), status(status) {

}

Switch::Switch(std::string name)
        : Circuit(name), status(DEFAULT_FLAG) {

}

Switch::Switch(std::string name, const bool status)
        : Circuit(name), status(status) {

}

Switch::Switch(std::string name, const Conductor& positive, const Conductor& negative)
        : Circuit(name, positive, negative), status(DEFAULT_FLAG) {

}

Switch::Switch(std::string name, const bool status, const Conductor& positive, const Conductor& negative)
        : Circuit(name, positive, negative), status(status) {

}

Switch::~Switch() {

}

bool Switch::operator==(const Switch& peer) const {
    return (static_cast<const Circuit&>(*this) == static_cast<const Circuit&>(peer))
        && (status == peer.status);
}

Switch Switch::operator+(const Switch& peer) const {
    Circuit self = *this, other = peer;
    Circuit result = (self + other);
    return Switch("+", status, result.getPositive(), result.getNegative());
}

Switch Switch::operator-(const Switch& peer) const {
    Circuit self = *this, other = peer;
    Circuit result = (self - other);
    return Switch("-", status, result.getPositive(), result.getNegative());
}

Switch Switch::operator*(const Switch& peer) const {
    Circuit self = *this, other = peer;
    Circuit result = (self * other);
    return Switch("*", status, result.getPositive(), result.getNegative());
}

Switch Switch::operator/(const Switch& peer) const {
    Circuit self = *this, other = peer;
    Circuit result = (self / other);
    return Switch("/", status, result.getPositive(), result.getNegative());
}

Switch Switch::operator%(const Switch& peer) const {
    Circuit self = *this, other = peer;
    Circuit result = (self % other);
    return Switch("%", status, result.getPositive(), result.getNegative());
}

Circuit Switch::copy() {
    Switch fresh(getName(), status, getPositive(), getNegative());
    return fresh;
}

void Switch::clear() {
    Circuit::clear();
    status = DEFAULT_FLAG;
    return;
}

std::string Switch::print() {
    std::stringstream result;
    result << Circuit::print() << ",f:";
    result << status;
	return result.str();
}

} // namespace ecn