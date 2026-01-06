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

#include "conductor.h"

namespace ecn {

const std::string Conductor::UNIT = "C";

Conductor::Conductor()
        : Core(), charge(UNIT), resistance() {

}

Conductor::Conductor(const float magnitude, const short int scaling)
        : Core(), charge(magnitude, scaling, UNIT), resistance() {

}

Conductor::Conductor(const Resistance& resistance)
        : Core(), charge(UNIT), resistance(resistance) {

}

Conductor::Conductor(const shp::Quantity& charge, const Resistance& resistance)
        : Core(), charge(charge), resistance(resistance) {

}

Conductor::Conductor(const Reluctance& reluctance)
        : Core(reluctance), charge(UNIT), resistance() {

}

Conductor::Conductor(const shp::Quantity& charge, const Reluctance& reluctance)
        : Core(reluctance), charge(charge), resistance() {

}

Conductor::Conductor(const Reluctance& reluctance, const Resistance& resistance)
        : Core(reluctance), charge(UNIT), resistance(resistance) {

}

Conductor::Conductor(const shp::Quantity& charge, const Reluctance& reluctance, const Resistance& resistance)
        : Core(reluctance), charge(charge), resistance(resistance) {

}

Conductor::Conductor(std::string name)
        : Core(name), charge(UNIT), resistance() {

}

Conductor::Conductor(std::string name, const shp::Quantity& charge)
        : Core(name), charge(charge), resistance() {

}

Conductor::Conductor(std::string name, const Resistance& resistance)
        : Core(name), charge(UNIT), resistance(resistance) {

}

Conductor::Conductor(std::string name, const shp::Quantity& charge, const Resistance& resistance)
        : Core(name), charge(charge), resistance(resistance) {

}

Conductor::Conductor(std::string name, const Reluctance& reluctance)
        : Core(name, reluctance), charge(UNIT), resistance() {

}

Conductor::Conductor(std::string name, const shp::Quantity& charge, const Reluctance& reluctance)
        : Core(name, reluctance), charge(charge), resistance() {

}

Conductor::Conductor(std::string name,
        const Reluctance& reluctance, const Resistance& resistance)
        : Core(name, reluctance), charge(UNIT), resistance(resistance) {

}

Conductor::Conductor(std::string name, const shp::Quantity& charge,
        const Reluctance& reluctance, const Resistance& resistance)
        : Core(name, reluctance), charge(charge), resistance(resistance) {

}

Conductor::~Conductor() {

}

bool Conductor::operator==(const Conductor& peer) const {
    return (static_cast<const Core&>(*this) == static_cast<const Core&>(peer))
        && (charge == peer.charge) && (resistance == peer.resistance);
}

Conductor Conductor::operator+(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self + other);
    shp::Quantity soc = (charge + peer.charge);
    return Conductor("+", soc, core.getReluctance(), (resistance + peer.resistance));
}

Conductor Conductor::operator-(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self - other);
    shp::Quantity soc = (charge - peer.charge);
    return Conductor("-", soc, core.getReluctance(), (resistance - peer.resistance));
}

Conductor Conductor::operator*(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self * other);
    shp::Quantity soc = (charge * peer.charge);
    return Conductor("*", soc, core.getReluctance(), (resistance * peer.resistance));
}

Conductor Conductor::operator/(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self / other);
    shp::Quantity soc = (charge / peer.charge);
    return Conductor("/", soc, core.getReluctance(), (resistance / peer.resistance));
}

Conductor Conductor::operator%(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self % other);
    shp::Quantity soc = (charge % peer.charge);
    return Conductor("%", soc, core.getReluctance(), (resistance % peer.resistance));
}

bool Conductor::isCharged() const {
	return charge.checkNonZero();
}

Conductor Conductor::copy() {
    Conductor fresh(getName(), charge, getReluctance(), resistance);
    return fresh;
}

void Conductor::clear() {
    Core::clear();
    charge.clear();
    resistance.clear();
    return;
}

std::string Conductor::print() {
    std::stringstream result;
	result << Core::print() << ",";
    result << resistance.print() << ",";
    result << charge.print();
	return result.str();
}

} // namespace ecn