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

#include "transistor.h"

namespace ecn {

Transistor::Transistor()
        : Element(), emitter(), base(), collector() {

}

Transistor::Transistor(const Conductor& emitter,
        const Conductor& base, const Conductor& collector)
        : Element(), emitter(emitter), base(base), collector(collector) {

}

Transistor::Transistor(const std::string name)
        : Element(name), emitter(), base(), collector() {

}

Transistor::Transistor(std::string name, const Conductor& emitter,
        const Conductor& base, const Conductor& collector)
        : Element(name), emitter(emitter), base(base), collector(collector) {

}

Transistor::~Transistor() {

}

bool Transistor::operator==(const Transistor& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (emitter == peer.emitter) && (base == peer.base) && (collector == peer.collector);
}

Transistor Transistor::operator+(const Transistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self + other);
    return Transistor("+", (emitter + peer.emitter), (base + peer.base), (collector + peer.collector));
}

Transistor Transistor::operator-(const Transistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self - other);
    return Transistor("-", (emitter - peer.emitter), (base - peer.base), (collector - peer.collector));
}

Transistor Transistor::operator*(const Transistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self * other);
    return Transistor("*", (emitter * peer.emitter), (base * peer.base), (collector * peer.collector));
}

Transistor Transistor::operator/(const Transistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self / other);
    return Transistor("/", (emitter / peer.emitter), (base / peer.base), (collector / peer.collector));
}

Transistor Transistor::operator%(const Transistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self % other);
    return Transistor("%", (emitter % peer.emitter), (base % peer.base), (collector % peer.collector));
}

shp::Potential Transistor::getVoltageEB() const {
    Conductor base = getBase();
    shp::Quantity charge = (emitter.getCharge() - base.getCharge());
    short int scaling = charge.getScaling();
    shp::Potential fresh(emitter.getCharge().getMagnitude(), base.getCharge().getMagnitude(),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

shp::Potential Transistor::getVoltageCB() const {
    Conductor base = getBase();
    shp::Quantity charge = (collector.getCharge() - base.getCharge());
    short int scaling = charge.getScaling();
    shp::Potential fresh(collector.getCharge().getMagnitude(), base.getCharge().getMagnitude(),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

Transistor Transistor::copy() {
    Transistor fresh(getName(), emitter, base, collector);
    return fresh;
}

void Transistor::clear() {
    Element::clear();
    emitter.clear();
    base.clear();
    collector.clear();
    return;
}

std::string Transistor::print() {
    std::stringstream result;
    result << Element::print() << ",e:";
    result << emitter.print() << ",b:";
    result << base.print() << ",c:";
    result << collector.print();
	return result.str();
}

} // namespace ecn