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

#include "core.h"

namespace ecn {

Core::Core()
        : Element(), reluctance() {

}

Core::Core(const Reluctance& reluctance)
        : Element(), reluctance(reluctance) {

}

Core::Core(std::string name)
        : Element(name), reluctance() {

}

Core::Core(std::string name, const Reluctance& reluctance)
        : Element(name), reluctance(reluctance) {

}

Core::~Core() {

}

bool Core::operator==(const Core& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (reluctance == peer.reluctance);
}

Core Core::operator+(const Core& peer) const {
    return Core("+", (reluctance + peer.reluctance));
}

Core Core::operator-(const Core& peer) const {
    return Core("-", (reluctance - peer.reluctance));
}

Core Core::operator*(const Core& peer) const {
    return Core("*", (reluctance * peer.reluctance));
}

Core Core::operator/(const Core& peer) const {
    return Core("/", (reluctance / peer.reluctance));
}

Core Core::operator%(const Core& peer) const {
    return Core("%", (reluctance % peer.reluctance));
}

Core Core::copy() {
    Core fresh(getName(), reluctance);
    return fresh;
}

void Core::clear() {
    Element::clear();
    reluctance.clear();
    return;
}

std::string Core::print() {
    std::stringstream result;
	result << Element::print() << ",ℜ:";
    result << reluctance.print();
	return result.str();
}

} // namespace ecn