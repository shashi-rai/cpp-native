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

#include "frequency.h"

namespace shp {

Frequency::Frequency()
        : Signal(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const std::string unit)
        : Signal(unit),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const Unit& unit)
        : Signal(unit),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const float magnitude)
		: Signal(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const float magnitude, std::string unit)
		: Signal(magnitude, unit),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const float magnitude, const Unit& unit)
		: Signal(magnitude, unit),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const float magnitude, short int scaling)
		: Signal(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const float magnitude, short int scaling, const std::string unit)
		: Signal(magnitude, scaling, unit),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const float magnitude, short int scaling, const Unit& unit)
		: Signal(magnitude, scaling, unit),
		modulation(shp::Direction::DEFAULT_RADIANS) {

}

Frequency::Frequency(const Polar& modulation)
        : Signal(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const shp::Quantity& magnitude)
        : Signal(magnitude), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const Azimuth& phase, const shp::Quantity& magnitude)
        : Signal(phase, magnitude), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude)
        : Signal(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude)
        : Signal(phase, magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, const std::string unit)
        : Signal(magnitude, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        const std::string unit)
        : Signal(phase, magnitude, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, const Unit& unit)
        : Signal(magnitude, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude, const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float magnitude)
        : Signal(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude)
        : Signal(phase, magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, short int scaling)
        : Signal(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float magnitude, short int scaling)
        : Signal(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float phase, const float magnitude,
        short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude,
        short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, short int scaling,
		std::string unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        short int scaling, std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float magnitude, short int scaling,
		std::string unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float phase, const float magnitude,
        short int scaling, std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude,
        short int scaling, std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float magnitude, short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const float phase, const float magnitude,
        short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude,
        short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::~Frequency() {

}

bool Frequency::operator==(const Frequency& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer))
        && (modulation == peer.modulation);
}

Frequency Frequency::operator+(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self + other);
    return Frequency((modulation + peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::operator-(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self - other);
    return Frequency((modulation - peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::operator*(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self * other);
    return Frequency((modulation * peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::operator/(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self / other);
    return Frequency((modulation / peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::operator%(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self % other);
    return Frequency((modulation % peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

float Frequency::getMagnitude() const {
    return Signal::getAmplitude();
}

void Frequency::setMagnitude(const float value) {
    Signal::setAmplitude(value);
}

float Frequency::getPhase() const {
    return Signal::getOrientation();
}

void Frequency::setPhase(const float value) {
    Signal::setOrientation(value);
}

short int Frequency::getScaling() const {
    return Signal::getScaling();
}

void Frequency::setScaling(const short int factor) {
    Signal::setScaling(factor);
}

Unit Frequency::getUnit() const {
    return Signal::getUnit();
}

void Frequency::setUnit(const Unit& object) {
    Signal::setUnit(object);
}

Quantity Frequency::getPhaseShift() const {
    Signal self = *this; Frequency frequency = Signal::getFrequency();
    float phase = (modulation.getCyclingRate() / frequency.getMagnitude());
    shp::Quantity periodicity(phase, frequency.getScaling(), frequency.getUnit());
	periodicity.adjustScaling(); periodicity.adjustNumeric();
    return shp::Quantity(periodicity.getMagnitude(), periodicity.getScaling(), periodicity.getUnit());
}

Quantity Frequency::getWavelength() const {
	Signal self = *this;
    float periodicity = (modulation.getTimePerCycle() * self.getAmplitude());
    shp::Quantity result(periodicity, self.getScaling(), self.getUnit());
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Signal Frequency::copy() const {
    Signal self = *this;
    Frequency fresh(modulation, self.getOrientation(),
        self.getAmplitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Frequency::clear() {
    Signal::clear();
    modulation.clear();
    return;
}

std::string Frequency::print() {
    std::stringstream result;
    result << Signal::print() << "?";
    result << modulation.print();
	return result.str();
}

} // namespace shp