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
        : Signal(shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const std::string unit)
        : Signal(unit), modulation(unit) {

}

Temporal::Temporal(const Unit& unit)
        : Signal(unit), modulation(unit) {

}

Temporal::Temporal(const float magnitude)
		: Signal(magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const float magnitude, const std::string unit)
		: Signal(magnitude, unit), modulation(unit) {

}

Temporal::Temporal(const float magnitude, const Unit& unit)
		: Signal(magnitude, unit), modulation(unit) {

}

Temporal::Temporal(const float magnitude, const short int scaling)
		: Signal(magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const float magnitude, const short int scaling, const std::string unit)
		: Signal(magnitude, scaling, unit), modulation(unit) {

}

Temporal::Temporal(const float magnitude, const short int scaling, const Unit& unit)
		: Signal(magnitude, scaling, unit), modulation(unit) {

}

Temporal::Temporal(const Azimuth& phase)
        : Signal(phase), modulation(shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const Azimuth& phase, const std::string unit)
        : Signal(phase, unit), modulation(unit) {

}

Temporal::Temporal(const Azimuth& phase, const Unit& unit)
        : Signal(phase, unit), modulation(unit) {

}

Temporal::Temporal(const Azimuth& phase, const float magnitude)
        : Signal(phase, magnitude), modulation(shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const Azimuth& phase, const float magnitude, const std::string unit)
        : Signal(phase, magnitude, unit), modulation(unit) {

}

Temporal::Temporal(const Azimuth& phase, const float magnitude, const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(unit) {

}

Temporal::Temporal(const Azimuth& phase, const float magnitude, const short int scaling)
        : Signal(phase, magnitude, scaling), modulation(shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const Azimuth& phase, const float magnitude, const short int scaling,
        const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(unit) {

}

Temporal::Temporal(const Azimuth& phase, const float magnitude, const short int scaling,
        const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(unit) {

}

Temporal::Temporal(const Signal& modulation)
        : Signal(modulation.getUnit()), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const shp::Quantity& magnitude)
        : Signal(magnitude), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase)
        : Signal(phase, modulation.getUnit()), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const shp::Quantity& magnitude)
        : Signal(phase, magnitude), modulation(modulation) {

}

Temporal::Temporal(const float modulation, const float magnitude)
        : Signal(magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(modulation, shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const float modulation, const float phase, const float magnitude)
        : Signal(phase, magnitude, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(modulation, shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const float modulation, const float magnitude, const std::string unit)
        : Signal(magnitude, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const float modulation, const float phase, const float magnitude,
        const std::string unit)
        : Signal(phase, magnitude, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const float modulation, const float magnitude, const Unit& unit)
        : Signal(magnitude, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const float modulation, const float phase, const float magnitude,
        const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const Signal& modulation, const float magnitude)
        : Signal(magnitude, modulation.getUnit()), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude)
        : Signal(phase, magnitude, modulation.getUnit()),
		modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const std::string unit)
        : Signal(phase, magnitude, unit), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const Unit& unit)
        : Signal(phase, magnitude, unit), modulation(modulation) {

}

Temporal::Temporal(const float modulation, const float magnitude, const short int scaling)
        : Signal(magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(modulation, shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const float modulation, const float phase, const float magnitude,
        const short int scaling)
        : Signal(phase, magnitude, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		modulation(modulation, shp::Unit::getBaseSymbol(shp::Unit::TIME)) {

}

Temporal::Temporal(const Signal& modulation, const float magnitude, const short int scaling)
        : Signal(magnitude, scaling, modulation.getUnit()), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling)
        : Signal(phase, magnitude, scaling, modulation.getUnit()), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling)
        : Signal(phase, magnitude, scaling, modulation.getUnit()), modulation(modulation) {

}

Temporal::Temporal(const float modulation, const float magnitude, const short int scaling,
		const std::string unit)
        : Signal(magnitude, scaling, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const float modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const Signal& modulation, const float magnitude, const short int scaling,
		const std::string unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const std::string unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Temporal::Temporal(const float modulation, const float magnitude, const short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const float modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation, unit) {

}

Temporal::Temporal(const Signal& modulation, const float magnitude, const short int scaling,
		const Unit& unit)
        : Signal(magnitude, scaling, unit), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Temporal::Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const Unit& unit)
        : Signal(phase, magnitude, scaling, unit), modulation(modulation) {

}

Temporal::~Temporal() {

}

bool Temporal::operator==(const Temporal& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer))
        && (modulation == peer.modulation);
}

bool Temporal::operator<(const Temporal& peer) const {
    return (static_cast<const Signal&>(*this) < static_cast<const Signal&>(peer))
        && (modulation < peer.modulation);
}

bool Temporal::operator>(const Temporal& peer) const {
    return (static_cast<const Signal&>(*this) > static_cast<const Signal&>(peer))
        && (modulation > peer.modulation);
}

bool Temporal::operator<=(const Temporal& peer) const {
    Temporal self = *this;
    return (self < peer) || (self == peer);
}

bool Temporal::operator>=(const Temporal& peer) const {
    Temporal self = *this;
    return (self > peer) || (self == peer);
}

Temporal Temporal::operator+(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self + other); signal.adjustScaling();
    return Temporal((modulation + peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator-(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self - other); signal.adjustScaling();
    return Temporal((modulation - peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator*(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self * other); signal.adjustScaling();
    return Temporal((modulation * peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator/(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self / other); signal.adjustScaling();
    return Temporal((modulation / peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::operator%(const Temporal& peer) const {
    Signal self = *this, other = peer;
    Signal signal = (self % other); signal.adjustScaling();
    return Temporal((modulation % peer.modulation), signal.getOrientation(),
        signal.getAmplitude(), signal.getScaling(), signal.getUnit());
}

Temporal Temporal::getCarrierScalar(const float coefficient) const {
    Signal self = *this; Signal carrier = self(coefficient);
    return Temporal(this->modulation, carrier.getOrientation(),
		carrier.getMagnitude(), carrier.getScaling(), self.getUnit());
}

Temporal Temporal::getOverlayScalar(const float coefficient) const {
    Signal self = *this; Signal overlay = modulation(coefficient);
    return Temporal(overlay, self.getOrientation(),
		self.getMagnitude(), self.getScaling(), self.getUnit());
}

Temporal Temporal::getCarrierRotation(const short int degree) const {
    Signal self = *this; Azimuth carrier(self.getOrientation());
    Azimuth phase = carrier.getRotation(degree);
    return Temporal(this->modulation, phase,
		self.getMagnitude(), self.getScaling(), self.getUnit());
}

Temporal Temporal::getOverlayRotation(const short int degree) const {
    Signal self = *this; Azimuth overlay(modulation.getOrientation());
    Azimuth phase = overlay.getRotation(degree);
    return Temporal(phase, self.getOrientation(),
		self.getMagnitude(), self.getScaling(), self.getUnit());
}

Temporal Temporal::getDotProduct(const Temporal& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getDotProduct(other);
	Signal overlay = this->modulation.getDotProduct(peer.getModulation());
    return Temporal(overlay, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Temporal Temporal::getCarrierDotProduct(const Temporal& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getDotProduct(other);
    return Temporal(this->modulation, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Temporal Temporal::getOverlayDotProduct(const Temporal& peer) const {
	Signal self = *this, other = peer;
	Signal overlay = this->modulation.getDotProduct(peer.getModulation());
    return Temporal(overlay, self.getOrientation(),
        self.getAmplitude(), self.getScaling(), self.getUnit());
}

Temporal Temporal::getCrossProduct(const Temporal& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getCrossProduct(other);
	Signal overlay = this->modulation.getCrossProduct(peer.getModulation());
    return Temporal(overlay, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Temporal Temporal::getCarrierCrossProduct(const Temporal& peer) const {
	Signal self = *this, other = peer;
    Signal carrier = self.getCrossProduct(other);
    return Temporal(this->modulation, carrier.getOrientation(),
        carrier.getAmplitude(), carrier.getScaling(), carrier.getUnit());
}

Temporal Temporal::getOverlayCrossProduct(const Temporal& peer) const {
	Signal self = *this, other = peer;
	Signal overlay = this->modulation.getCrossProduct(peer.getModulation());
    return Temporal(overlay, self.getOrientation(),
        self.getAmplitude(), self.getScaling(), self.getUnit());
}

float Temporal::getMagnitude() const {
    return Signal::getMagnitude();
}

void Temporal::setMagnitude(const float value) {
    Signal::setMagnitude(value);
}

void Temporal::setMagnitude(const float value, const short int scale) {
    Signal::setMagnitude(value, scale);
}

void Temporal::setMagnitude(const float value, const short int scale, const std::string unit) {
    Signal::setMagnitude(value, scale, unit);
}

void Temporal::setMagnitude(const float value, const short int scale, const Unit& unit) {
    Signal::setMagnitude(value, scale, unit);
}

float Temporal::getIntensity() const {
    return Signal::getAmplitude();
}

float Temporal::getIntensityDrift() const {
    return Signal::getOrientation();
}

void Temporal::setIntensityDrift(const float shift) {
    Signal::setOrientation(shift);
}

void Temporal::setIntensityDrift(const Azimuth& shift) {
    Signal::setOrientation(shift.toRadians());
}

float Temporal::getSpatialDrift() const {
    return modulation.getOrientation();
}

void Temporal::setSpatialDrift(const shp::Signal& motion) {
    modulation = motion;
}

void Temporal::setSpatialDrift(const Azimuth& rate) {
    modulation.setOrientation(rate.toRadians());
}

void Temporal::setSpatialDrift(const float distance,
        const Azimuth& rate) {
    modulation.setMagnitude(distance);
    modulation.setOrientation(rate.toRadians());
}

void Temporal::setSpatialDrift(const float distance, const short int scale,
        const Azimuth& rate) {
    modulation.setMagnitude(distance, scale);
    modulation.setOrientation(rate.toRadians());
}

void Temporal::setSpatialDrift(const float distance, const short int scale, const std::string unit,
        const Azimuth& rate) {
    modulation.setMagnitude(distance, scale, unit);
    modulation.setOrientation(rate.toRadians());
}

void Temporal::setSpatialDrift(const float distance, const short int scale, const Unit& unit,
        const Azimuth& rate) {
    modulation.setMagnitude(distance, scale, unit);
    modulation.setOrientation(rate.toRadians());
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
    Signal self = *this;
    float twoPiFraction = modulation.getCyclingRate();
    shp::Quantity result(twoPiFraction, shp::Quantity::DEFAULT_SCALE,
        shp::Unit::getDerivedSymbol(shp::Unit::PLANE_ANGLE));
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Quantity Temporal::getPhaseScaling() const {
    Signal self = *this;
    float twoPiFraction = (modulation.getCyclingRate() * self.getAmplitude());
    shp::Quantity result(twoPiFraction, self.getScaling(), self.getUnit());
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Quantity Temporal::getPeriodScaling() const {
    Signal self = *this;
    float propagation = (modulation.getTimePerCycle() * self.getAmplitude());
    shp::Quantity result(propagation, self.getScaling(), self.getUnit());
	result.adjustScaling(); result.adjustNumeric();
    return result;
}

Signal Temporal::getPhaseSpace() const {
    Signal self = *this;
    Signal result(self.getOrientation(), self.getMagnitude(),
        self.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getPhaseConvergence(const Signal& signal) const {
    Signal self = *this, result = self.getLinearConvergence(signal);
    return result;
}

Signal Temporal::getPhaseConvergenceAmplified(const Signal& signal) const {
    Signal self = *this, result = self.getSquareConvergence(signal);
    return result;
}

Signal Temporal::getPhaseDivergence(const Signal& signal) const {
    Signal self = *this, result = self.getLinearDivergence(signal);
    return result;
}

Signal Temporal::getPhaseDivergenceAmplified(const Signal& signal) const {
    Signal self = *this, result = self.getSquareDivergence(signal);
    return result;
}

Signal Temporal::getLinearSpace() const {
    Signal self = *this; Signal propagation = self.getDotProduct(modulation);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getLinearConvergence(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getDotProduct(modulation).getLinearConvergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getLinearConvergenceAmplified(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getDotProduct(modulation).getSquareConvergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getLinearDivergence(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getDotProduct(modulation).getLinearDivergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getLinearDivergenceAmplified(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getDotProduct(modulation).getSquareDivergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getCurvedSpace() const {
    Signal self = *this; Signal propagation = self.getCrossProduct(modulation);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getCurvedConvergence(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getCrossProduct(modulation).getLinearConvergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getCurvedConvergenceAmplified(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getCrossProduct(modulation).getSquareConvergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getCurvedDivergence(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getCrossProduct(modulation).getLinearDivergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getCurvedDivergenceAmplified(const Signal& signal) const {
    Signal self = *this; Signal propagation = self.getCrossProduct(modulation).getSquareDivergence(signal);
    Signal result(propagation.getOrientation(), propagation.getMagnitude(),
        propagation.getScaling(), self.getUnit());
    return result;
}

Signal Temporal::getFrequency() const {
    return Signal::getFrequency();
}

Signal Temporal::getTotal() const {
    Signal self = *this;
    Temporal fresh(modulation, self.getOrientation(),
        self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

Signal Temporal::copy() const {
    Signal self = *this;
    Temporal fresh(modulation, self.getOrientation(),
        self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Temporal::clear() {
    Signal::clear();
    modulation.clear();
    return;
}

std::string Temporal::print() const {
    std::stringstream result;
    result << Signal::print() << "δ";
    result << modulation.print();
	return result.str();
}

std::string Temporal::printRadians() const {
    std::stringstream result;
    result << Signal::printRadians() << "δ";
    result << modulation.printRadians();
	return result.str();
}

} // namespace shp