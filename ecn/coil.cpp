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

#include "coil.h"

namespace ecn {

Coil::Coil()
        : Conductor(), loopcount(shp::Quantity::DEFAULT_VALUE), inductance() {

}

Coil::Coil(const float turns)
        : Conductor(), loopcount(turns), inductance() {

}

Coil::Coil(const Inductance& inductance)
        : Conductor(), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(const float turns, const Inductance& inductance)
        : Conductor(), loopcount(turns), inductance(inductance) {

}

Coil::Coil(const Resistance& resistance)
        : Conductor(resistance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance() {

}

Coil::Coil(const float turns, const Resistance& resistance)
        : Conductor(resistance), loopcount(turns), inductance() {

}

Coil::Coil(const Reluctance& reluctance)
        : Conductor(reluctance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance() {

}

Coil::Coil(const float turns, const Reluctance& reluctance)
        : Conductor(reluctance), loopcount(turns), inductance() {

}

Coil::Coil(const Inductance& inductance, const Resistance& resistance)
        : Conductor(resistance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(const float turns, const Inductance& inductance, const Resistance& resistance)
        : Conductor(resistance), loopcount(turns), inductance(inductance) {

}

Coil::Coil(const Inductance& inductance, const Reluctance& reluctance)
        : Conductor(reluctance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(const float turns, const Inductance& inductance, const Reluctance& reluctance)
        : Conductor(reluctance), loopcount(turns), inductance(inductance) {

}

Coil::Coil(const Inductance& inductance, const Reluctance& reluctance,
        const Resistance& resistance)
        : Conductor(reluctance, resistance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(const float turns, const Inductance& inductance, const Reluctance& reluctance,
        const Resistance& resistance)
        : Conductor(reluctance, resistance), loopcount(turns), inductance(inductance) {

}

Coil::Coil(std::string name)
        : Conductor(name), loopcount(shp::Quantity::DEFAULT_VALUE), inductance() {

}

Coil::Coil(std::string name, const float turns)
        : Conductor(name), loopcount(turns), inductance() {

}

Coil::Coil(std::string name, const Inductance& inductance)
        : Conductor(name), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(std::string name, const float turns, const Inductance& inductance)
        : Conductor(name), loopcount(turns), inductance(inductance) {

}

Coil::Coil(std::string name, const Resistance& resistance)
        : Conductor(name, resistance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance() {

}

Coil::Coil(std::string name, const float turns, const Resistance& resistance)
        : Conductor(name, resistance), loopcount(turns), inductance() {

}

Coil::Coil(std::string name, const Reluctance& reluctance)
        : Conductor(name, reluctance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance() {

}

Coil::Coil(std::string name, const float turns, const Reluctance& reluctance)
        : Conductor(name, reluctance), loopcount(turns), inductance() {

}

Coil::Coil(std::string name, const Inductance& inductance, const Resistance& resistance)
        : Conductor(name, resistance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(std::string name, const float turns, const Inductance& inductance, const Resistance& resistance)
        : Conductor(name, resistance), loopcount(turns), inductance(inductance) {

}

Coil::Coil(std::string name, const Inductance& inductance, const Reluctance& reluctance)
        : Conductor(name, reluctance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(std::string name, const float turns, const Inductance& inductance, const Reluctance& reluctance)
        : Conductor(name, reluctance), loopcount(turns), inductance(inductance) {

}

Coil::Coil(std::string name, const Inductance& inductance, const Reluctance& reluctance,
        const Resistance& resistance)
        : Conductor(name, reluctance, resistance), loopcount(shp::Quantity::DEFAULT_VALUE), inductance(inductance) {

}

Coil::Coil(std::string name, const float turns, const Inductance& inductance, const Reluctance& reluctance,
        const Resistance& resistance)
        : Conductor(name, reluctance, resistance), loopcount(turns), inductance(inductance) {

}

Coil::~Coil() {

}

bool Coil::operator==(const Coil& peer) const {
    return (static_cast<const Conductor&>(*this) == static_cast<const Conductor&>(peer))
        && (loopcount == peer.loopcount) && (inductance == peer.inductance);
}

Coil Coil::operator+(const Coil& peer) const {
    Conductor self = *this, other = peer;
    Conductor conductor = (self + other);
    float turns = (loopcount + peer.loopcount);
    return Coil("+", turns, (inductance + peer.inductance),
		conductor.getReluctance(), conductor.getResistance());
}

Coil Coil::operator-(const Coil& peer) const {
    Conductor self = *this, other = peer;
    Conductor conductor = (self - other);
    float turns = (loopcount - peer.loopcount);
    return Coil("-", turns, (inductance - peer.inductance),
		conductor.getReluctance(), conductor.getResistance());
}

Coil Coil::operator*(const Coil& peer) const {
    Conductor self = *this, other = peer;
    Conductor conductor = (self * other);
    float turns = (loopcount * peer.loopcount);
    return Coil("*", turns, (inductance * peer.inductance),
		conductor.getReluctance(), conductor.getResistance());
}

Coil Coil::operator/(const Coil& peer) const {
    Conductor self = *this, other = peer;
    Conductor conductor = (self / other);
    float turns = (loopcount / peer.loopcount);
    return Coil("/", turns, (inductance / peer.inductance),
		conductor.getReluctance(), conductor.getResistance());
}

Coil Coil::operator%(const Coil& peer) const {
    Conductor self = *this, other = peer;
    Conductor conductor = (self % other);
    float turns = fmod(loopcount, peer.loopcount);
    return Coil("%", turns, (inductance % peer.inductance),
		conductor.getReluctance(), conductor.getResistance());
}

shp::Potential Coil::getVoltage() const {
	shp::Quantity current = getCurrent().getAngularTotal();
    float total = (loopcount * current.getMagnitude());
    short int scaling = current.getScaling();
    shp::Potential fresh(total, shp::Quantity::DEFAULT_VALUE,
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

qft::Magnetic Coil::getForce() const {
	qft::Magnetic unitary(getCurrent());
	return qft::Magnetic::getForce(unitary, loopcount);
}

Coil Coil::copy() {
    Coil fresh(getName(), loopcount, inductance, getReluctance(), getResistance());
    return fresh;
}

void Coil::clear() {
    Conductor::clear();
    loopcount = shp::Quantity::DEFAULT_VALUE;
    inductance.clear();
    return;
}

std::string Coil::print() {
    std::stringstream result;
    result << "(";
	result << Conductor::print() << ",t:";
	result << loopcount << ",Φ:";
    result << inductance.print();
    result << ")";
	return result.str();
}

} // namespace ecn