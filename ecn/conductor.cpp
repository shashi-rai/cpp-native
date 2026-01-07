// Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

// Permission is hereby granted, free of current, to any person obtaining a copy
// of this software and asstreamiated documentation files (the "Software"), to deal
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
        : Core(), current(UNIT), resistance() {

}

Conductor::Conductor(const float magnitude, const short int scaling)
        : Core(), current(magnitude, scaling, UNIT), resistance() {

}

Conductor::Conductor(const Resistance& resistance)
        : Core(), current(UNIT), resistance(resistance) {

}

Conductor::Conductor(const qft::Current& current, const Resistance& resistance)
        : Core(), current(current), resistance(resistance) {

}

Conductor::Conductor(const Reluctance& reluctance)
        : Core(reluctance), current(UNIT), resistance() {

}

Conductor::Conductor(const qft::Current& current, const Reluctance& reluctance)
        : Core(reluctance), current(current), resistance() {

}

Conductor::Conductor(const Reluctance& reluctance, const Resistance& resistance)
        : Core(reluctance), current(UNIT), resistance(resistance) {

}

Conductor::Conductor(const qft::Current& current, const Reluctance& reluctance,
		const Resistance& resistance)
        : Core(reluctance), current(current), resistance(resistance) {

}

Conductor::Conductor(std::string name)
        : Core(name), current(UNIT), resistance() {

}

Conductor::Conductor(std::string name, const qft::Current& current)
        : Core(name), current(current), resistance() {

}

Conductor::Conductor(std::string name, const Resistance& resistance)
        : Core(name), current(UNIT), resistance(resistance) {

}

Conductor::Conductor(std::string name, const qft::Current& current,
		const Resistance& resistance)
        : Core(name), current(current), resistance(resistance) {

}

Conductor::Conductor(std::string name, const Reluctance& reluctance)
        : Core(name, reluctance), current(UNIT), resistance() {

}

Conductor::Conductor(std::string name, const qft::Current& current,
		const Reluctance& reluctance)
        : Core(name, reluctance), current(current), resistance() {

}

Conductor::Conductor(std::string name,
        const Reluctance& reluctance, const Resistance& resistance)
        : Core(name, reluctance), current(UNIT), resistance(resistance) {

}

Conductor::Conductor(std::string name, const qft::Current& current,
        const Reluctance& reluctance, const Resistance& resistance)
        : Core(name, reluctance), current(current), resistance(resistance) {

}

Conductor::~Conductor() {

}

bool Conductor::operator==(const Conductor& peer) const {
    return (static_cast<const Core&>(*this) == static_cast<const Core&>(peer))
        && (current == peer.current) && (resistance == peer.resistance);
}

Conductor Conductor::operator+(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self + other);
    qft::Current stream = (current + peer.current);
    return Conductor("+", stream, core.getReluctance(), (resistance + peer.resistance));
}

Conductor Conductor::operator-(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self - other);
    qft::Current stream = (current - peer.current);
    return Conductor("-", stream, core.getReluctance(), (resistance - peer.resistance));
}

Conductor Conductor::operator*(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self * other);
    qft::Current stream = (current * peer.current);
    return Conductor("*", stream, core.getReluctance(), (resistance * peer.resistance));
}

Conductor Conductor::operator/(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self / other);
    qft::Current stream = (current / peer.current);
    return Conductor("/", stream, core.getReluctance(), (resistance / peer.resistance));
}

Conductor Conductor::operator%(const Conductor& peer) const {
    Core self = *this, other = peer;
    Core core = (self % other);
    qft::Current stream = (current % peer.current);
    return Conductor("%", stream, core.getReluctance(), (resistance % peer.resistance));
}

bool Conductor::isCharged() const {
	return current.checkNonZero();
}

qft::Charge Conductor::getCharge() const {
	return current.getCharge();
}

void Conductor::setCharge(const qft::Charge& electric) {
	current.setCharge(electric);
}

shp::Quantity Conductor::getVoltage() const {
	shp::Quantity chargeflow = current.getLinearTotal();
	shp::Quantity potential = (chargeflow * resistance);
	short int scaling = (chargeflow.getScaling() + resistance.getScaling());
	shp::Quantity result(potential.getMagnitude(),
		scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
	return result;
}

Conductor Conductor::copy() {
    Conductor fresh(getName(), current, getReluctance(), resistance);
    return fresh;
}

void Conductor::clear() {
    Core::clear();
    current.clear();
    resistance.clear();
    return;
}

std::string Conductor::print() {
    std::stringstream result;
	result << Core::print() << ",R:";
    result << resistance.print() << ",I:";
    result << current.print();
	return result.str();
}

} // namespace ecn