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

#include "belief.h"

namespace con {

const std::string Belief::UNIT = "T";                   // Unit of Measure
const std::string Belief::KNOWLEDGE_FIELD = "Knowledge";// Knowledge Space
const short int Belief::KNOWLEDGE_SCALE = 0;            // 10^-1 T
const float Belief::EMOTION = -1.0f;                    // -1.0 x 10^-1 T

Belief::Belief()
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, KNOWLEDGE_SCALE, UNIT) {
    setSituation(nullptr);
}

Belief::Belief(const std::shared_ptr<Circumstance> situation)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, KNOWLEDGE_SCALE, UNIT) {
    setSituation(situation);
}

Belief::Belief(const std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, KNOWLEDGE_SCALE, std::string(unit)) {
    setSituation(nullptr);
}

Belief::Belief(const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, KNOWLEDGE_SCALE, unit) {
    setSituation(nullptr);
}

Belief::Belief(const shp::Unit& unit, const std::shared_ptr<Circumstance> situation)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, KNOWLEDGE_SCALE, unit) {
    setSituation(situation);
}

Belief::Belief(const float awareness)
        : shp::Temporal(awareness, KNOWLEDGE_SCALE, UNIT) {
    setSituation(nullptr);
}

Belief::Belief(const float awareness, const std::shared_ptr<Circumstance> situation)
        : shp::Temporal(awareness, KNOWLEDGE_SCALE, UNIT) {
    setSituation(situation);
}

Belief::Belief(const float awareness, const std::string unit)
        : shp::Temporal(awareness, KNOWLEDGE_SCALE, shp::Unit(unit)) {
    setSituation(nullptr);
}

Belief::Belief(const float awareness, const shp::Unit& unit)
        : shp::Temporal(awareness, KNOWLEDGE_SCALE, unit) {
    setSituation(nullptr);
}

Belief::Belief(const float awareness, const shp::Unit& unit, const std::shared_ptr<Circumstance> situation)
        : shp::Temporal(awareness, KNOWLEDGE_SCALE, unit) {
    setSituation(situation);
}

Belief::Belief(const float awareness, const short int scaling)
        : shp::Temporal(awareness, scaling, UNIT) {
    setSituation(nullptr);
}

Belief::Belief(const float awareness, const short int scaling, const std::shared_ptr<Circumstance> situation)
        : shp::Temporal(awareness, scaling, UNIT) {
    setSituation(situation);
}

Belief::Belief(const float awareness, const short int scaling, const std::string unit)
        : shp::Temporal(awareness, scaling, shp::Unit(unit)) {
    setSituation(nullptr);
}

Belief::Belief(const float awareness, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(awareness, scaling, unit) {
    setSituation(nullptr);
}

Belief::Belief(const float awareness, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Circumstance> situation)
        : shp::Temporal(awareness, scaling, unit) {
    setSituation(situation);
}

Belief::~Belief() {
    setSituation(nullptr);
}

bool Belief::operator==(const Belief& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (situation == peer.situation);
}

bool Belief::operator<(const Belief& peer) const {
    Belief self = *this; bool result = false;
    if (static_cast<const shp::Temporal&>(*this) < static_cast<const shp::Temporal&>(peer)) {
        result = true;
    }
    return result;
}

bool Belief::operator>(const Belief& peer) const {
    Belief self = *this; bool result = false;
    if (static_cast<const shp::Temporal&>(*this) > static_cast<const shp::Temporal&>(peer)) {
        result = true;
    }
    return result;
}

bool Belief::operator<=(const Belief& peer) const {
    Belief self = *this;
    return (self < peer) || (self == peer);
}

bool Belief::operator>=(const Belief& peer) const {
    Belief self = *this;
    return (self > peer) || (self == peer);
}

Belief Belief::operator+(const Belief& peer) const {
    shp::Temporal self = *this, other = peer, trust = (self + other);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator-(const Belief& peer) const {
    shp::Temporal self = *this, other = peer, trust = (self - other);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator*(const Belief& peer) const {
    shp::Temporal self = *this, other = peer, trust = (self * other);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator/(const Belief& peer) const {
    shp::Temporal self = *this, other = peer, trust = (self / other);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator%(const Belief& peer) const {
    shp::Temporal self = *this, other = peer, trust = (self % other);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator+(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal trust = (self.getTotal() + peer);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator-(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal trust = (self.getTotal() - peer);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator*(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal trust = (self.getTotal() * peer);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator/(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal trust = (self.getTotal() / peer);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

Belief Belief::operator%(const shp::Quantity& peer) const {
    shp::Temporal self = *this; shp::Signal trust = (self.getTotal() % peer);
    return Belief(trust.getMagnitude(), trust.getScaling(), trust.getUnit(), situation);
}

shp::Signal Belief::operator()(const Belief& peer, const shp::Distance awareness,
        const shp::Distance stance) const {
    if (isFamiliar()) {
        shp::Potential self = situation->getConfidence();
        shp::Potential other = peer.situation->getConfidence();
        shp::Signal factor = self(other, awareness, stance);
        shp::Signal force(factor * (*this).getTrustRadius().getScalarTotal());
        shp::Signal result(force.getMagnitude(), self.getAzimuthOrientation().toRadians(), force.getScaling());
        result.adjustScaling();
        return result;
    } else {
        float quantum = shp::Quantity::DEFAULT_VALUE; shp::Direction direction(quantum);
        return shp::Signal(quantum, direction.toRadians(), KNOWLEDGE_SCALE);
    }
}

bool Belief::isFamiliar() const {
    return (situation != nullptr);
}

shp::Distance Belief::getTrustRadius() const {
    shp::Distance result;
    if (isFamiliar()) {
        result = situation->getCapability();
    }
    return result;
}

void Belief::setTrustRadius(const shp::Distance& awareness) {
    if (isFamiliar()) {
        situation->setCapability(awareness.getMagnitude(), awareness.getScaling(), awareness.getUnit());
    }
}

void Belief::setTrustRadius(const float awareness) {
    if (isFamiliar()) {
        situation->setCapability(awareness);
    }
}

void Belief::setTrustRadius(const float awareness, const short int scale) {
    if (isFamiliar()) {
        situation->setCapability(awareness, scale);
    }
}

void Belief::setTrustRadius(const float awareness, const short int scale, const std::string unit) {
    if (isFamiliar()) {
        situation->setCapability(awareness, scale, unit);
    }
}

void Belief::setTrustRadius(const float awareness, const short int scale, const shp::Unit& unit) {
    if (isFamiliar()) {
        situation->setCapability(awareness, scale, unit);
    }
}

short int Belief::getScaling() const {
    return shp::Temporal::getScaling();
}

void Belief::setScaling(const short int factor) {
    shp::Temporal::setScaling(factor);
}

shp::Unit Belief::getUnit() const {
    return shp::Temporal::getUnit();
}

void Belief::setUnit(const shp::Unit& object) {
    shp::Temporal::setUnit(object);
}

void Belief::adjustNumeric() {
    shp::Temporal::adjustNumeric();
}

void Belief::adjustScaling() {
    shp::Temporal::adjustScaling();
}

bool Belief::checkNonZero() const {
	return shp::Temporal::checkNonZero();
}

bool Belief::checkInfinity() const {
    return shp::Temporal::checkInfinity();
}

short int Belief::checkScaling(const float amount) const {
    return shp::Temporal::checkScaling(amount);
}

shp::Potential Belief::getConfidence() const {
    shp::Potential result;
    if (isFamiliar()) {
        result = situation->getConfidence();
    }
    return result;
}

shp::Signal Belief::getFeeling() const {
    return shp::Temporal::getModulation();
}

void Belief::setFeeling(const con::Feeling& feeling) {
    shp::Temporal::setModulation(feeling.getSummary());
}

std::shared_ptr<Circumstance> Belief::getOriginalSituation() const {
    std::shared_ptr<Circumstance> result = Circumstance::shareable(Belief::KNOWLEDGE_FIELD,
            shp::Temporal::getMagnitude(), shp::Temporal::getScaling());
    result->setConfidence(shp::Potential(shp::Temporal::getMagnitude(), shp::Quantity::DEFAULT_VALUE,
        shp::Temporal::getScaling(), shp::Temporal::getUnit(), shp::Angular()));
    return result;
}

shp::Signal Belief::copy() const {
    shp::Temporal self = *this;
    Belief fresh(self.getMagnitude(), self.getScaling(), self.getUnit(), situation);
    return fresh.getTotal();
}

void Belief::clear() {
    shp::Temporal::clear();
    setSituation(nullptr);
    return;
}

std::string Belief::print() const {
    std::stringstream result;
    result << "b:";
    result << shp::Temporal::print();
    if (isFamiliar()) {
        result << ",";
        result << situation->print();
    }
	return result.str();
}

std::string Belief::printRadians() const {
    std::stringstream result;
    result << "b:";
    result << shp::Temporal::printRadians();
    if (isFamiliar()) {
        result << ",";
        result << situation->printRadians();
    }
	return result.str();
}

shp::Temporal Belief::getFluctuation(const float phase) const {
    shp::Temporal self = *this, intensity = self.getMagnitude();
    intensity.setIntensityDrift(phase);
	return shp::Temporal(intensity.getMagnitude(), intensity.getScaling(), intensity.getUnit());
}

} // namespace con