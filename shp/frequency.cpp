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
		modulation(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const std::string unit)
        : Signal(unit), modulation(unit) {

}

Frequency::Frequency(const Unit& unit)
        : Signal(unit), modulation(unit) {

}

Frequency::Frequency(const float magnitude)
		: Signal(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const float magnitude, const std::string unit)
		: Signal(magnitude, unit), modulation(unit) {

}

Frequency::Frequency(const float magnitude, const Unit& unit)
		: Signal(magnitude, unit), modulation(unit) {

}

Frequency::Frequency(const float magnitude, const short int scaling)
		: Signal(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const float magnitude, const short int scaling, const std::string unit)
		: Signal(magnitude, scaling, unit), modulation(unit) {

}

Frequency::Frequency(const float magnitude, const short int scaling, const Unit& unit)
		: Signal(magnitude, scaling, unit), modulation(unit) {

}

Frequency::Frequency(const Azimuth& phase)
        : Signal(phase), modulation(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const Azimuth& phase, const std::string unit)
        : Signal(phase, unit), modulation(unit) {

}

Frequency::Frequency(const Azimuth& phase, const Unit& unit)
        : Signal(phase, unit), modulation(unit) {

}

Frequency::Frequency(const Azimuth& phase, const float magnitude)
        : Signal(phase, magnitude), modulation(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const Azimuth& phase, const float magnitude, const std::string unit)
        : Signal(phase, magnitude, unit), modulation(unit) {

}

Frequency::Frequency(const Azimuth& phase, const float magnitude, const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(unit) {

}

Frequency::Frequency(const Azimuth& phase, const float magnitude, const short int scaling)
        : Signal(phase, magnitude, scaling), modulation() {

}

Frequency::Frequency(const Azimuth& phase, const float magnitude, const short int scaling,
        const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(unit) {

}

Frequency::Frequency(const Azimuth& phase, const float magnitude, const short int scaling,
        const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(unit) {

}

Frequency::Frequency(const Signal& modulation)
        : Signal(modulation.getUnit()), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const shp::Quantity& magnitude)
        : Signal(magnitude), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase)
        : Signal(phase), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const shp::Quantity& magnitude)
        : Signal(phase, magnitude), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude)
        : Signal(magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude)
        : Signal(phase, magnitude, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const float modulation, const float magnitude, const std::string unit)
        : Signal(magnitude, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        const std::string unit)
        : Signal(phase, magnitude, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const float modulation, const float magnitude, const Unit& unit)
        : Signal(magnitude, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude, const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const Signal& modulation, const float magnitude)
        : Signal(magnitude, modulation.getUnit()), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude)
        : Signal(phase, magnitude, modulation.getUnit()), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const std::string unit)
        : Signal(phase, magnitude, unit), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, const short int scaling)
        : Signal(magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        const short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)),
		modulation(modulation, shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY)) {

}

Frequency::Frequency(const Signal& modulation, const float magnitude, const short int scaling)
        : Signal(magnitude, scaling, modulation.getUnit()), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling)
        : Signal(phase, magnitude, scaling, modulation.getUnit()), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling)
        : Signal(phase, magnitude, scaling, modulation.getUnit()), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, const short int scaling,
		const std::string unit)
        : Signal(magnitude, scaling, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const Signal& modulation, const float magnitude, const short int scaling,
		const std::string unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const float modulation, const float magnitude, const short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), modulation(modulation, unit) {

}

Frequency::Frequency(const float modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const float magnitude, const short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Frequency::Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const Unit& unit)
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
    Signal signal = (self + other); signal.adjustScaling();
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
    Signal signal = (self * other); signal.adjustScaling();
    return Frequency((modulation * peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::operator/(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self / other); signal.adjustScaling();
    return Frequency((modulation / peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::operator%(const Frequency& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self % other); signal.adjustScaling();
    return Frequency((modulation % peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Frequency Frequency::getCarrierScalar(const float coefficient) const {
    Signal self = *this; Signal carrier = self(coefficient);
    return Frequency(this->modulation, carrier.getOrientation(),
		carrier.getMagnitude(), carrier.getScaling(), self.getUnit());
}

Frequency Frequency::getOverlayScalar(const float coefficient) const {
    Signal self = *this; Signal overlay = modulation(coefficient);
    return Frequency(overlay, self.getOrientation(),
		self.getMagnitude(), self.getScaling(), self.getUnit());
}

Frequency Frequency::getCarrierRotation(const short int degree) const {
    Signal self = *this; Azimuth carrier(self.getOrientation());
    Azimuth phase = carrier.getRotation(degree);
    return Frequency(this->modulation, phase,
		self.getMagnitude(), self.getScaling(), self.getUnit());
}

Frequency Frequency::getOverlayRotation(const short int degree) const {
    Signal self = *this; Azimuth overlay(modulation.getOrientation());
    Azimuth phase = overlay.getRotation(degree);
    return Frequency(phase, self.getOrientation(),
		self.getMagnitude(), self.getScaling(), self.getUnit());
}

Frequency Frequency::getDotProduct(const Frequency& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getDotProduct(other);
	Signal overlay = this->modulation.getDotProduct(peer.getModulation());
    return Frequency(overlay, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Frequency Frequency::getCarrierDotProduct(const Frequency& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getDotProduct(other);
    return Frequency(this->modulation, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Frequency Frequency::getOverlayDotProduct(const Frequency& peer) const {
	Signal self = *this, other = peer;
	Signal overlay = this->modulation.getDotProduct(peer.getModulation());
    return Frequency(overlay, self.getOrientation(),
        self.getAmplitude(), self.getScaling(), self.getUnit());
}

Frequency Frequency::getCrossProduct(const Frequency& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getCrossProduct(other);
	Signal overlay = this->modulation.getCrossProduct(peer.getModulation());
    return Frequency(overlay, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Frequency Frequency::getCarrierCrossProduct(const Frequency& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getCrossProduct(other);
    return Frequency(this->modulation, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Frequency Frequency::getOverlayCrossProduct(const Frequency& peer) const {
	Signal self = *this, other = peer;
	Signal overlay = this->modulation.getCrossProduct(peer.getModulation());
    return Frequency(overlay, self.getOrientation(),
        self.getAmplitude(), self.getScaling(), self.getUnit());
}

float Frequency::getMagnitude() const {
    return Signal::getMagnitude();
}

void Frequency::setMagnitude(const float value) {
    Signal::setMagnitude(value);
}

void Frequency::setMagnitude(const float value, const short int scale) {
    Signal::setMagnitude(value, scale);
}

float Frequency::getAmplitude() const {
    return Signal::getAmplitude();
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

bool Frequency::checkNonZero() const {
    return Signal::checkNonZero();
}

bool Frequency::checkInfinity() const {
    return Signal::checkInfinity();
}

short int Frequency::checkScaling(const float amount) const {
    return Signal::checkScaling(amount);
}

void Frequency::adjustNumeric() {
    return Signal::adjustNumeric();
}

void Frequency::adjustScaling() {
    Signal::adjustScaling();
}

Quantity Frequency::getTraversal() const { 
    Signal self = *this; Signal time = self.getScalarInverse();
	std::string unit = self.getUnit().getName() + "/" + shp::Unit::getBaseSymbol(shp::Unit::TIME);
    float propagation = (time.getCyclingRate() * modulation.getAmplitude());
    shp::Quantity result(propagation, modulation.getScaling(), unit);
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Quantity Frequency::getLifespan() const {
	Signal self = *this; Signal time = self.getScalarInverse();
    float lifetime = (modulation.getTimePerCycle() * time.getAmplitude());
    shp::Quantity result(lifetime, (modulation.getScaling() + time.getScaling()),
		shp::Unit::getBaseSymbol(shp::Unit::TIME));
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
    result << Signal::print() << "δ";
    result << modulation.print();
	return result.str();
}

} // namespace shp