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

#include "behaviour.h"

namespace con {

Behaviour::Behaviour()
        : name() {

}

Behaviour::Behaviour(const std::string name)
        : name(name) {

}

Behaviour::~Behaviour() {

}

bool Behaviour::operator==(const Behaviour& peer) const {
    return (name == peer.name);
}

Behaviour Behaviour::operator+(const Behaviour& peer) const {
    return Behaviour("+");
}

Behaviour Behaviour::operator-(const Behaviour& peer) const {
    return Behaviour("-");
}

Behaviour Behaviour::operator*(const Behaviour& peer) const {
    return Behaviour("*");
}

Behaviour Behaviour::operator/(const Behaviour& peer) const {
    return Behaviour("/");
}

Behaviour Behaviour::operator%(const Behaviour& peer) const {
    return Behaviour("%");
}

Behaviour Behaviour::copy() const {
    Behaviour fresh(getName());
    return fresh;
}

void Behaviour::clear() {
    name.clear();
    return;
}

std::string Behaviour::print() const {
    std::stringstream result;
	result << name;
	return result.str();
}

} // namespace con