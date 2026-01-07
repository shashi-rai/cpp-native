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

#include "inductor.h"

namespace ecn {

Inductor::Inductor()
        : Element(), inductance() {

}

Inductor::Inductor(const Inductance& inductance)
        : Element(), inductance(inductance) {

}

Inductor::Inductor(const std::string name)
        : Element(name), inductance() {

}

Inductor::Inductor(std::string name, const Inductance& inductance)
        : Element(name), inductance(inductance) {

}

Inductor::~Inductor() {

}

bool Inductor::operator==(const Inductor& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (inductance == peer.inductance);
}

Inductor Inductor::operator+(const Inductor& peer) const {
    return Inductor("+", (inductance + peer.inductance));
}

Inductor Inductor::operator-(const Inductor& peer) const {
    return Inductor("-", (inductance - peer.inductance));
}

Inductor Inductor::operator*(const Inductor& peer) const {
    return Inductor("*", (inductance * peer.inductance));
}

Inductor Inductor::operator/(const Inductor& peer) const {
    return Inductor("/", (inductance / peer.inductance));
}

Inductor Inductor::operator%(const Inductor& peer) const {
    return Inductor("%", (inductance % peer.inductance));
}

Inductor Inductor::copy() {
    Inductor fresh(getName(), inductance);
    return fresh;
}

void Inductor::clear() {
    Element::clear();
    inductance.clear();
    return;
}

std::string Inductor::print() {
    std::stringstream result;
    result << Element::print() << ",L:";
    result << inductance.print();
	return result.str();
}

} // namespace ecn