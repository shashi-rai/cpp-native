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

#include "commodity.h"

namespace fin {

Commodity::Commodity() : act::Item() {

}

Commodity::Commodity(std::string name)
        : act::Item(name) {

}

Commodity::Commodity(std::string name, const shp::Quantity& quantity)
        : act::Item(name, quantity) {

}

Commodity::~Commodity() {

}

bool Commodity::operator==(const Commodity& peer) const {
    return (static_cast<const act::Item&>(*this) == static_cast<const act::Item&>(peer));
}

Commodity Commodity::operator+(const Commodity& peer) const {
    return Commodity("+", (getQuantity() + peer.getQuantity()));
}

Commodity Commodity::operator-(const Commodity& peer) const {
    return Commodity("-", (getQuantity() - peer.getQuantity()));
}

Commodity Commodity::operator*(const Commodity& peer) const {
    return Commodity("*", (getQuantity() * peer.getQuantity()));
}

Commodity Commodity::operator/(const Commodity& peer) const {
    return Commodity("/", (getQuantity() / peer.getQuantity()));
}

Commodity Commodity::operator%(const Commodity& peer) const {
    return Commodity("%", (getQuantity() % peer.getQuantity()));
}

act::Item Commodity::copy() {
    Commodity fresh(getName(), getQuantity());
    return fresh;
}

void Commodity::clear() {
    act::Item::clear();
    return;
}

std::string Commodity::print() {
    std::stringstream result;
    result << act::Item::print();
	return result.str();
}

} // namespace fin