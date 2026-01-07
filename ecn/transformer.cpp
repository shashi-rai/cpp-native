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

#include "transformer.h"

namespace ecn {

Transformer::Transformer()
        : Element(), primary(), secondary() {

}

Transformer::Transformer(const Coil& primary)
        : Element(), primary(primary), secondary() {

}

Transformer::Transformer(const Coil& primary, const Coil& secondary)
        : Element(), primary(primary), secondary(secondary) {

}

Transformer::Transformer(const std::string name)
        : Element(name), primary(), secondary() {

}

Transformer::Transformer(const std::string name, const Coil& primary)
        : Element(name), primary(primary), secondary() {

}

Transformer::Transformer(const std::string name, const Coil& primary, const Coil& secondary)
        : Element(name), primary(primary), secondary(secondary) {

}

Transformer::~Transformer() {

}

bool Transformer::operator==(const Transformer& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (primary == peer.primary) && (secondary == peer.secondary);
}

Transformer Transformer::operator+(const Transformer& peer) const {
    Element self = *this, other = peer;
    Element base = (self + other);
    return Transformer("+", (primary + peer.primary), (secondary + peer.secondary));
}

Transformer Transformer::operator-(const Transformer& peer) const {
    Element self = *this, other = peer;
    Element base = (self - other);
    return Transformer("-", (primary - peer.primary), (secondary - peer.secondary));
}

Transformer Transformer::operator*(const Transformer& peer) const {
    Element self = *this, other = peer;
    Element base = (self * other);
    return Transformer("*", (primary * peer.primary), (secondary * peer.secondary));
}

Transformer Transformer::operator/(const Transformer& peer) const {
    Element self = *this, other = peer;
    Element base = (self / other);
    return Transformer("/", (primary / peer.primary), (secondary / peer.secondary));
}

Transformer Transformer::operator%(const Transformer& peer) const {
    Element self = *this, other = peer;
    Element base = (self % other);
    return Transformer("%", (primary % peer.primary), (secondary % peer.secondary));
}

float Transformer::getTurnsRatio() const {
    float ratio = primary.getLoopCount() / secondary.getLoopCount();
    return ratio;
}

float Transformer::getHighVoltageRatio() const {
    float ratio = (primary.getVoltage() / secondary.getVoltage()).getHigh();
    return ratio;
}

float Transformer::getLowVoltageRatio() const {
    float ratio = (primary.getVoltage() / secondary.getVoltage()).getLow();
    return ratio;
}

shp::Potential Transformer::getSecondaryVoltage() const {
    float ratio = secondary.getLoopCount() / primary.getLoopCount();
    shp::Potential input = primary.getVoltage();
    short int scaling = input.getScaling();
    shp::Potential fresh((input.getHigh() * ratio), (input.getLow() * ratio),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

Transformer Transformer::copy() {
    Transformer fresh(getName(), primary, secondary);
    return fresh;
}

void Transformer::clear() {
    Element::clear();
    primary.clear();
    secondary.clear();
    return;
}

std::string Transformer::print() {
    std::stringstream result;
    result << Element::print() << ",p:";
    result << primary.print() << ",s:";
    result << secondary.print();
    return result.str();
}

} // namespace ecn