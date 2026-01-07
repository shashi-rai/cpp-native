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

#include "neutral.h"

namespace ecn {

Neutral::Neutral()
        : Element(), line() {

}

Neutral::Neutral(const Conductor& ground)
        : Element(), line(ground) {

}

Neutral::Neutral(std::string name)
        : Element(name), line() {

}

Neutral::Neutral(std::string name, const Conductor& ground)
        : Element(name), line(ground) {

}

Neutral::~Neutral() {

}

bool Neutral::operator==(const Neutral& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (line == peer.line);
}

Neutral Neutral::operator+(const Neutral& peer) const {
    return Neutral("+", (line + peer.line));
}

Neutral Neutral::operator-(const Neutral& peer) const {
    return Neutral("-", (line - peer.line));
}

Neutral Neutral::operator*(const Neutral& peer) const {
    return Neutral("*", (line * peer.line));
}

Neutral Neutral::operator/(const Neutral& peer) const {
    return Neutral("/", (line / peer.line));
}

Neutral Neutral::operator%(const Neutral& peer) const {
    return Neutral("%", (line % peer.line));
}

bool Neutral::isCharged() const {
    return line.isCharged();
}

qft::Charge Neutral::getCharge() const {
    return line.getCharge();
}

void Neutral::setCharge(const qft::Charge& electric) {
    line.setCharge(electric);
}

shp::Quantity Neutral::getVoltage() const {
    return line.getVoltage();
}

Neutral Neutral::copy() {
    Neutral fresh(getName(), line);
    return fresh;
}

void Neutral::clear() {
    Element::clear();
    line.clear();
    return;
}

std::string Neutral::print() {
    std::stringstream result;
    result << Element::print() << ",-:";
    result << line.print();
	return result.str();
}

} // namespace ecn