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
#include "frequency.h"

namespace shp {

Temporal::Temporal()
        : Signal(shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const std::string unit)
        : Signal(unit),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const Unit& unit)
        : Signal(unit),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float magnitude)
		: Signal(magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float magnitude, std::string unit)
		: Signal(magnitude, unit),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float magnitude, const Unit& unit)
		: Signal(magnitude, unit),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float magnitude, short int scaling)
		: Signal(magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float magnitude, short int scaling, const std::string unit)
		: Signal(magnitude, scaling, unit),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const float magnitude, short int scaling, const Unit& unit)
		: Signal(magnitude, scaling, unit),
		entropy(shp::Direction::DEFAULT_RADIANS) {

}

Temporal::Temporal(const Polar& entropy)
        : Signal(shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const shp::Quantity& magnitude)
        : Signal(magnitude), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const Azimuth& phase)
        : Signal(phase), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const Azimuth& phase, const shp::Quantity& magnitude)
        : Signal(phase, magnitude), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float magnitude)
        : Signal(magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float phase, const float magnitude)
        : Signal(phase, magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float magnitude, const std::string unit)
        : Signal(magnitude, unit), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float phase, const float magnitude,
        const std::string unit)
        : Signal(phase, magnitude, unit), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float magnitude, const Unit& unit)
        : Signal(magnitude, unit), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float phase, const float magnitude, const Unit& unit)
        : Signal(phase, magnitude, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float magnitude)
        : Signal(magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const Azimuth& phase, const float magnitude)
        : Signal(phase, magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float magnitude, short int scaling)
        : Signal(magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float phase, const float magnitude,
        short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float magnitude, short int scaling)
        : Signal(magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float phase, const float magnitude,
        short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const Azimuth& phase, const float magnitude,
        short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float magnitude, short int scaling,
		std::string unit)
        : Signal(magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float phase, const float magnitude,
        short int scaling, std::string unit)
        : Signal(phase, magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float magnitude, short int scaling,
		std::string unit)
        : Signal(magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float phase, const float magnitude,
        short int scaling, std::string unit)
        : Signal(phase, magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const Azimuth& phase, const float magnitude,
        short int scaling, std::string unit)
        : Signal(phase, magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float magnitude, short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const float entropy, const float phase, const float magnitude,
        short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float magnitude, short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const float phase, const float magnitude,
        short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), entropy(entropy) {

}

Temporal::Temporal(const Polar& entropy, const Azimuth& phase, const float magnitude,
        short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), entropy(entropy) {

}

Temporal::~Temporal() {

}

bool Temporal::operator==(const Temporal& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer))
        && (entropy == peer.entropy);
}

Temporal Temporal::operator+(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self + other);
    return Temporal((entropy + peer.entropy), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator-(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self - other);
    return Temporal((entropy - peer.entropy), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator*(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self * other);
    return Temporal((entropy * peer.entropy), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator/(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self / other);
    return Temporal((entropy / peer.entropy), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator%(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self % other);
    return Temporal((entropy % peer.entropy), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

float Temporal::getMagnitude() const {
    return Signal::getAmplitude();
}

void Temporal::setMagnitude(const float value) {
    Signal::setAmplitude(value);
}

float Temporal::getPhase() const {
    return Signal::getOrientation();
}

void Temporal::setPhase(const float value) {
    Signal::setOrientation(value);
}

short int Temporal::getScaling() const {
    return Signal::getScaling();
}

void Temporal::setScaling(const short int factor) {
    Signal::setScaling(factor);
}

Unit Temporal::getUnit() const {
    return Signal::getUnit();
}

void Temporal::setUnit(const Unit& object) {
    Signal::setUnit(object);
}

bool Temporal::checkNonZero() const {
    return Signal::checkNonZero();
}

bool Temporal::checkInfinity() const {
    return Signal::checkInfinity();
}

short int Temporal::checkScaling(const float amount) const {
    return Signal::checkScaling(amount);
}

void Temporal::adjustNumeric() {
    return Signal::adjustNumeric();
}

void Temporal::adjustScaling() {
    Signal::adjustScaling();
}

Quantity Temporal::getPhaseShift() const {
    Signal self = *this; shp::Frequency frequency = Signal::getFrequency();
    float phase = (entropy.getCyclingRate() / frequency.getMagnitude());
    shp::Quantity periodicity(phase, frequency.getScaling(), frequency.getUnit());
	periodicity.adjustScaling(); periodicity.adjustNumeric();
    return shp::Quantity(periodicity.getMagnitude(), periodicity.getScaling(), periodicity.getUnit());
}

Quantity Temporal::getTimePeriod() const {
	Signal self = *this;
    float periodicity = (entropy.getTimePerCycle() * self.getAmplitude());
    shp::Quantity result(periodicity, self.getScaling(), self.getUnit());
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Frequency Temporal::getFrequency() const {
    return Signal::getFrequency();
}

Temporal Temporal::copy() {
    Signal self = *this;
    Temporal fresh(entropy, self.getOrientation(),
        self.getAmplitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Temporal::clear() {
    Signal::clear();
    entropy.clear();
    return;
}

std::string Temporal::print() {
    std::stringstream result;
    result << Signal::print() << "?";
    result << entropy.print();
	return result.str();
}

} // namespace shp