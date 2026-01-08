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

#include "temporal.h"

namespace shp {

Temporal::Temporal()
        : Quantity(shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const std::string unit)
        : Quantity(unit),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const Unit& unit)
        : Quantity(unit),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float timeslice)
		: Quantity(timeslice, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float timeslice, std::string unit)
		: Quantity(timeslice, unit),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float timeslice, const Unit& unit)
		: Quantity(timeslice, unit),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float timeslice, short int scaling)
		: Quantity(timeslice, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float timeslice, short int scaling, const std::string unit)
		: Quantity(timeslice, scaling, unit),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float timeslice, short int scaling, const Unit& unit)
		: Quantity(timeslice, scaling, unit),
		change(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const Direction& change)
        : Quantity(shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(change) {

}

Temporal::Temporal(const Direction& change, const Quantity& timeslice)
        : Quantity(timeslice), change(change) {

}

Temporal::Temporal(const float change, const float timeslice)
        : Quantity(timeslice, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(change) {

}

Temporal::Temporal(const float change, const float timeslice, const std::string unit)
        : Quantity(timeslice, unit), change(change) {

}

Temporal::Temporal(const float change, const float timeslice, const Unit& unit)
        : Quantity(timeslice, unit), change(change) {

}

Temporal::Temporal(const Direction& change, const float timeslice)
        : Quantity(timeslice, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(change) {

}

Temporal::Temporal(const float change, const float timeslice, short int scaling)
        : Quantity(timeslice, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(change) {

}

Temporal::Temporal(const Direction& change, const float timeslice, short int scaling)
        : Quantity(timeslice, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		change(change) {

}

Temporal::Temporal(const float change, const float timeslice, short int scaling,
		std::string unit)
        : Quantity(timeslice, scaling, unit), change(change) {

}

Temporal::Temporal(const Direction& change, const float timeslice, short int scaling,
		std::string unit)
        : Quantity(timeslice, scaling, unit), change(change) {

}

Temporal::Temporal(const float change, const float timeslice, short int scaling,
		const Unit& unit)
        : Quantity(timeslice, scaling, unit), change(change) {

}

Temporal::Temporal(const Direction& change, const float timeslice, short int scaling,
		const Unit& unit)
        : Quantity(timeslice, scaling, unit), change(change) {

}

Temporal::~Temporal() {

}

bool Temporal::operator==(const Temporal& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (change == peer.change);
}

Temporal Temporal::operator+(const Temporal& peer) const {
    Quantity self = *this, other = peer;
    Quantity timeslice = (self + other);
    return Temporal((change + peer.change),
        timeslice.getMagnitude(), timeslice.getScaling(), timeslice.getUnit());
}

Temporal Temporal::operator-(const Temporal& peer) const {
    Quantity self = *this, other = peer;
    Quantity timeslice = (self - other);
    return Temporal((change - peer.change),
        timeslice.getMagnitude(), timeslice.getScaling(), timeslice.getUnit());
}

Temporal Temporal::operator*(const Temporal& peer) const {
    Quantity self = *this, other = peer;
    Quantity timeslice = (self * other);
    return Temporal((change * peer.change),
        timeslice.getMagnitude(), timeslice.getScaling(), timeslice.getUnit());
}

Temporal Temporal::operator/(const Temporal& peer) const {
    Quantity self = *this, other = peer;
    Quantity timeslice = (self / other);
    return Temporal((change / peer.change),
        timeslice.getMagnitude(), timeslice.getScaling(), timeslice.getUnit());
}

Temporal Temporal::operator%(const Temporal& peer) const {
    Quantity self = *this, other = peer;
    Quantity timeslice = (self % other);
    return Temporal((change % peer.change),
        timeslice.getMagnitude(), timeslice.getScaling(), timeslice.getUnit());
}

Quantity Temporal::getPhaseShift() const {
    Quantity self = *this, frequency = getInverse();
    float phase = (change.getCyclingRate() / frequency.getMagnitude());
    Quantity periodicity(phase, frequency.getScaling(), frequency.getUnit());
	periodicity.adjustScaling(); periodicity.adjustNumeric();
    return Quantity(periodicity.getMagnitude(), periodicity.getScaling(), periodicity.getUnit());
}

Quantity Temporal::getTimePeriod() const {
	Quantity self = *this;
    float periodicity = (change.getTimePerCycle() * self.getMagnitude());
    shp::Quantity result(periodicity, self.getScaling(), self.getUnit());
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Quantity Temporal::getFrequency() const {
    shp::Quantity frequency = getInverse();
    shp::Quantity result(std::abs(frequency.getMagnitude()), frequency.getScaling(),
        shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY));
    return result;
}

Temporal Temporal::copy() {
    Quantity self = *this;
    Temporal fresh(change, self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Temporal::clear() {
    Quantity::clear();
    change.clear();
    return;
}

std::string Temporal::print() {
    std::stringstream result;
    result << "φ";
    result << change.print() << ",Δ:";
    result << Quantity::print();
	return result.str();
}

} // namespace shp