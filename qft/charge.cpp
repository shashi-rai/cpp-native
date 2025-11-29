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

#include "charge.h"

namespace qft {

Charge::Charge() : quantity(0.0f) {

}

Charge::Charge(float quantity) : quantity(quantity) {

}

Charge::Charge(float quantity, const shp::Unit& unit) : quantity(quantity, unit) {

}

Charge::Charge(const shp::Quantity& quantity, const shp::Unit& unit) : quantity(unit) {

}

Charge::~Charge() {

}

bool Charge::operator==(const Charge& peer) const {
    return (quantity == peer.quantity);
}

Charge Charge::operator+(const Charge& peer) const {
    return Charge((quantity + peer.quantity), quantity.getUnit());
}

Charge Charge::operator-(const Charge& peer) const {
    return Charge((quantity - peer.quantity), quantity.getUnit());
}

Charge Charge::copy() {
    Charge fresh(quantity, quantity.getUnit());
    return fresh;
}

void Charge::clear() {
    quantity.clear();
    return;
}

std::string Charge::print() {
    std::stringstream result;
    result << "(q:";
    result << quantity.print() << ")";
	return result.str();
}

} // namespace qft