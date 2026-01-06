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

#include "circuit.h"

namespace ecn {

Circuit::Circuit()
        : Element(), positive(), negative() {

}

Circuit::Circuit(const Conductor& positive, const Conductor& negative)
        : Element(), positive(positive), negative(negative) {

}

Circuit::Circuit(const std::string name)
        : Element(name), positive(), negative() {

}

Circuit::Circuit(const std::string name, const Conductor& positive, const Conductor& negative)
        : Element(name), positive(positive), negative(negative) {

}

Circuit::~Circuit() {

}

bool Circuit::operator==(const Circuit& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (positive == peer.positive) && (negative == peer.negative);
}

Circuit Circuit::operator+(const Circuit& peer) const {
    Element self = *this, other = peer;
    Element base = (self + other);
    return Circuit("+", (positive + peer.positive), (negative + peer.negative));
}

Circuit Circuit::operator-(const Circuit& peer) const {
    Element self = *this, other = peer;
    Element base = (self - other);
    return Circuit("-", (positive - peer.positive), (negative - peer.negative));
}

shp::Potential Circuit::getPotential() const {
    shp::Potential fresh(positive.getCharge().getMagnitude(),
                        negative.getCharge().getMagnitude());
    return fresh;
}

Circuit Circuit::copy() {
    Circuit fresh(getName(), positive, negative);
    return fresh;
}

void Circuit::clear() {
    Element::clear();
    positive.clear();
    negative.clear();
    return;
}

std::string Circuit::print() {
    std::stringstream result;
    result << Element::print() << ",";
    result << positive.print() << ",";
    result << negative.print();
    return result.str();
}

} // namespace ecn