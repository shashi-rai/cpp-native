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

#include "mood.h"

namespace con {

const std::string Mood::UNIT = "M";                     // Unit of Measure
const std::string Mood::EMOTION_SECOND = "E/s";         // Emotion per second
const std::string Mood::KNOWLEDGE_FIELD = "Knowledge";  // Knowledge Sitation
const std::string Mood::EMOTIONAL_FIELD = "Emotion";    // Emotional Situation
const float Mood::EMOTION_FLOW_RATE = 1.0f;             // 1.0^0 emotions per second
const short int Mood::EMOTION_FLOW_SCALE = 0;           // 10^0

Mood::Mood()
        : con::Belief(), feeling() {

}

Mood::Mood(const std::string name)
        : con::Belief(), feeling(name) {

}

Mood::Mood(const Belief& belief)
        : con::Belief(belief.getTrustRadius().getMagnitude(), belief.getScaling(), belief.getUnit(), belief.getSituation()),
        feeling() {

}

Mood::Mood(const float belief)
        : con::Belief(belief), feeling() {

}

Mood::Mood(const float belief, const std::string unit)
        : con::Belief(belief, unit), feeling() {

}

Mood::Mood(const float belief, const shp::Unit& unit)
        : con::Belief(belief, unit), feeling() {

}

Mood::Mood(const float belief, const short int scaling)
        : con::Belief(belief, scaling), feeling() {

}

Mood::Mood(const float belief, const short int scaling, const std::string unit)
        : con::Belief(belief, scaling, unit), feeling() {

}

Mood::Mood(const float belief, const short int scaling, const shp::Unit& unit)
        : con::Belief(belief, scaling, unit), feeling() {

}

Mood::Mood(const con::Feeling& feeling)
        : con::Belief(), feeling(feeling) {

}

Mood::Mood(const std::string name, const con::Belief& belief)
        : con::Belief(belief), feeling(name) {

}

Mood::Mood(const std::string name, const float belief)
        : con::Belief(belief), feeling(name) {

}

Mood::Mood(const std::string name, const float belief, const std::string unit)
        : con::Belief(belief, unit), feeling(name) {

}

Mood::Mood(const std::string name, const float belief, const shp::Unit& unit)
        : con::Belief(belief, unit), feeling(name) {

}

Mood::Mood(const std::string name, const float belief, const short int scaling)
        : con::Belief(belief, scaling), feeling(name) {

}

Mood::Mood(const std::string name, const float belief, const short int scaling, const std::string unit)
        : con::Belief(belief, scaling, unit), feeling(name) {

}

Mood::Mood(const std::string name, const float belief, const short int scaling, const shp::Unit& unit)
        : con::Belief(belief, scaling, unit), feeling(name) {

}

Mood::Mood(const con::Belief& belief, const con::Feeling& feeling)
        : con::Belief(belief.getTrustRadius().getMagnitude(), belief.getScaling(), belief.getUnit(), belief.getSituation()),
        feeling(feeling) {

}

Mood::Mood(const float belief, const float feeling)
        : con::Belief(belief), feeling(feeling) {

}

Mood::Mood(const std::string name, const float belief, const float feeling)
        : con::Belief(belief), feeling(name, feeling) {

}

Mood::~Mood() {

}

bool Mood::operator==(const Mood& peer) const {
    return (static_cast<const con::Belief&>(*this) == static_cast<const con::Belief&>(peer))
        && (feeling == peer.feeling);
}

bool Mood::operator<(const Mood& peer) const {
    Mood self = *this; bool result = false;
    if (static_cast<const con::Belief&>(*this) < static_cast<const con::Belief&>(peer)) {
        result = true;
    } else if (self.feeling < peer.feeling) {
        result = true;
    }
    return result;
}

bool Mood::operator>(const Mood& peer) const {
    Mood self = *this; bool result = false;
    if (static_cast<const con::Belief&>(*this) > static_cast<const con::Belief&>(peer)) {
        result = true;
    } else if (self.feeling > peer.feeling) {
        result = true;
    }
    return result;
}

bool Mood::operator<=(const Mood& peer) const {
    Mood self = *this;
    return (self < peer) || (self == peer);
}

bool Mood::operator>=(const Mood& peer) const {
    Mood self = *this;
    return (self > peer) || (self == peer);
}

Mood Mood::operator+(const Mood& peer) const {
    Belief self = *this, other = peer, newBelief = (self + other);
    Feeling newFeeling = (this->feeling + peer.feeling);
    return Mood(newBelief, newFeeling);
}

Mood Mood::operator-(const Mood& peer) const {
    Belief self = *this, other = peer, newBelief = (self - other);
    Feeling newFeeling = (this->feeling - peer.feeling);
    return Mood(newBelief, newFeeling);
}

Mood Mood::operator*(const Mood& peer) const {
    Belief self = *this, other = peer, newBelief = (self * other);
    Feeling newFeeling = (this->feeling * peer.feeling);
    return Mood(newBelief, newFeeling);
}

Mood Mood::operator/(const Mood& peer) const {
    Belief self = *this, other = peer, newBelief = (self / other);
    Feeling newFeeling = (this->feeling / peer.feeling);
    return Mood(newBelief, newFeeling);
}

Mood Mood::operator%(const Mood& peer) const {
    Belief self = *this, other = peer, newBelief = (self % other);
    Feeling newFeeling = (this->feeling % peer.feeling);
    return Mood(newBelief, newFeeling);
}

Mood Mood::operator+(const Belief& peer) const {
    Belief self = *this, newBelief = (self + peer);
    return Mood(newBelief, this->feeling);
}

Mood Mood::operator-(const Belief& peer) const {
    Belief self = *this, newBelief = (self - peer);
    return Mood(newBelief, this->feeling);
}

Mood Mood::operator*(const Belief& peer) const {
    Belief self = *this, newBelief = (self * peer);
    return Mood(newBelief, this->feeling);
}

Mood Mood::operator/(const Belief& peer) const {
    Belief self = *this, newBelief = (self / peer);
    return Mood(newBelief, this->feeling);
}

Mood Mood::operator%(const Belief& peer) const {
    Belief self = *this, newBelief = (self % peer);
    return Mood(newBelief, this->feeling);
}

Mood Mood::operator+(const Feeling& peer) const {
    Mood self = *this; Feeling newFeeling = (self.feeling + peer);
    return Mood(self.getBelief(), newFeeling);
}

Mood Mood::operator-(const Feeling& peer) const {
    Mood self = *this; Feeling newFeeling = (self.feeling - peer);
    return Mood(self.getBelief(), newFeeling);
}

Mood Mood::operator*(const Feeling& peer) const {
    Mood self = *this; Feeling newFeeling = (self.feeling * peer);
    return Mood(self.getBelief(), newFeeling);
}

Mood Mood::operator/(const Feeling& peer) const {
    Mood self = *this; Feeling newFeeling = (self.feeling / peer);
    return Mood(self.getBelief(), newFeeling);
}

Mood Mood::operator%(const Feeling& peer) const {
    Mood self = *this; Feeling newFeeling = (self.feeling % peer);
    return Mood(self.getBelief(), newFeeling);
}

std::string Mood::getName() const {
    return feeling.getName();
}

void Mood::setName(const std::string name) {
    this->feeling.setName(name);
}

con::Belief Mood::getBelief() const {
    con::Belief result = *this;
    return result;
}

void Mood::setBelief(const con::Belief& belief) {
    Belief::setMagnitude(belief.getTrustRadius().getMagnitude(), belief.getScaling(), belief.getUnit());
}

shp::Quantity Mood::getSubstance() {
    Belief belief = *this; shp::Signal difference = belief.getConfidence().getDifference();
    shp::Signal angular = feeling.getPragmatic(shp::Quantity::DEFAULT_VALUE);
    float magnitude = ((difference.getMagnitude() / angular.getMagnitude()) * belief.getTrustRadius().getMagnitude());
    shp::Quantity result(magnitude, belief.getScaling(), Belief::UNIT);
    return result;
}

shp::Quantity Mood::getEmotions() const {
    Belief belief = *this; con::Belief emotion(con::Belief::EMOTION);
    float quantum = (belief.getTrustRadius().getMagnitude() / Mood::getEmotionCharges().getMagnitude());
    return shp::Quantity((quantum / emotion.getTrustRadius().getMagnitude()),
        (belief.getScaling() - emotion.getScaling()), "e⁻");
}

void Mood::setEmotions(const int count) {
    Belief belief = *this;
    if (count > 0) {
        con::Belief emotion(con::Belief::EMOTION);
        float total = (emotion.getTrustRadius().getMagnitude() * count);
        belief.setTrustRadius(total); belief.adjustScaling();
    }
}

void Mood::changeFlowSpeed(const float drift) {
    feeling.setChangeEmotion(drift);
}

void Mood::changeFlowSpeed(const float drift, const short int scale) {
    feeling.setChangeEmotion(drift, scale);
}

void Mood::changeIntensity(const float degree) {
    feeling.setChangeIntensity(degree);
}

shp::Signal Mood::getChallenge() const {
    Belief belief = *this;
    shp::Signal result = belief.getConfidence().getDifference();
    return result;
}

shp::Signal Mood::getStrength(const shp::Temporal& interval) const {
    shp::Signal result = (this->getForce(interval) * this->getFeeling().getSummary());
    return result;
}

shp::Signal Mood::getForce(const shp::Temporal& interval) const {
    shp::Signal result = (this->getRateOfChange() / interval.getMagnitude());
    return result;
}

shp::Signal Mood::getPotential() const {
    Belief belief = *this;      // non-moving belief only
    belief.setSpatialDrift(feeling.getEmotion().getAmplitude(), feeling.getScaling(), feeling.getIntensity());
    shp::Signal flow = belief.getPhaseSpace();
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), flow.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Mood::getPotential(const shp::Signal& drift) const {
    Belief belief = *this;      // belief in a moving reference frame
    belief.setSpatialDrift(feeling.getEmotion().getAmplitude(), feeling.getScaling(), feeling.getIntensity());
    shp::Signal flow = belief.getPhaseConvergence(drift);
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), flow.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Mood::getBeliefFlow() const {
    Belief belief = *this;      // belief linearly moving, but non-accelerating
    belief.setSpatialDrift(feeling.getEmotion().getAmplitude(), feeling.getScaling(), feeling.getIntensity());
    shp::Signal flow = belief.getLinearSpace();
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Mood::getBeliefFlow(const shp::Signal& drift) const {
    Belief belief = *this;      // linearly moving belief in non-accelerating conductor
    belief.setSpatialDrift(feeling.getEmotion().getAmplitude(), feeling.getScaling(), feeling.getIntensity());
    shp::Signal flow = belief.getLinearConvergence(drift);
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Mood::getThoughtful() const {
    Belief belief = *this;      // loop belief within a situation
    belief.setSpatialDrift(feeling.getEmotion().getAmplitude(), feeling.getScaling(), feeling.getIntensity());
    shp::Signal flow = belief.getCurvedSpace();
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Mood::getThoughtful(const shp::Signal& drift) const {
    Belief belief = *this;      // loop belief carrying body moving in a situation
    belief.setSpatialDrift(feeling.getEmotion().getAmplitude(), feeling.getScaling(), feeling.getIntensity());
    shp::Signal flow = belief.getCurvedConvergence(drift);
    shp::Signal result(flow.getOrientation(),
        -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Mood::getKnowledgeStrength() const {
    shp::Signal result = (this->getChallenge() * this->getBeliefFlow());
    return result;
}

shp::Signal Mood::getKnowledgeDynamic() const {
    Belief belief = *this; shp::Signal flow = getBeliefFlow();
    shp::Temporal total = (belief + belief);
    shp::Signal result = ((flow * flow) / total.getMagnitude());
    return result;
}

shp::Signal Mood::getEmotionalStrength() const {
    shp::Signal result = (this->getChallenge() * this->getThoughtful());
    return result;
}

shp::Signal Mood::getEmotionalDynamic() const {
    Belief belief = *this; shp::Signal flow = getThoughtful();
    shp::Temporal total = (belief + belief);
    shp::Signal result = ((flow * flow) / total.getMagnitude());
    return result;
}

shp::Signal Mood::getRateOfChange() const {
    shp::Signal result = (this->getBeliefFlow() - this->getThoughtful());
    result.adjustScaling();
    return result;
}

std::shared_ptr<Circumstance> Mood::getKnowledgeSituation() const {
    Belief belief = *this;
    return belief.getOriginalSituation();
}

std::shared_ptr<Circumstance> Mood::getEmotionalSituation() const {
    Belief belief = *this;
    std::shared_ptr<Circumstance> situation =
        Circumstance::shareable(Mood::EMOTIONAL_FIELD, getMagnitude(), getScaling());
    shp::Signal drift = getRateOfChange();
    if (drift.checkNonZero()) {
        situation->setConfidence(shp::Potential(drift.getMagnitude(),
            shp::Quantity::DEFAULT_VALUE, drift.getScaling(), belief.getUnit(),
            shp::Angular()));
    } else {
        situation->setConfidence(shp::Potential(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, belief.getScaling(), belief.getUnit(),
            shp::Angular()));
    }
    shp::Direction orientation = feeling.getIntensity().getNormal();
    situation->setCentral(orientation);
    return situation;
}

bool Mood::checkNonZero() const {
    Belief belief = *this;
    return (belief.checkNonZero() && feeling.checkNonZero());
}

shp::Signal Mood::copy() const {
    Belief belief = *this;
    Mood fresh = Mood(belief, feeling);
    return fresh.getTotal();
}

void Mood::clear() {
    Belief::clear();
    feeling.clear();
    return;
}

std::string Mood::print() const {
    std::stringstream result;
    result << "M:";
    result << Belief::print() << ",";
    result << feeling.print();
    result << UNIT;
	return result.str();
}

std::string Mood::printRadians() const {
    std::stringstream result;
    result << "M:";
    result << Belief::printRadians() << ",";
    result << feeling.printRadians();
    result << UNIT;
	return result.str();
}

shp::Signal Mood::getCosComponent(const float phase) const {
	shp::Signal flow = this->getBeliefFlow();
	return shp::Signal(flow.getOrientation(), (flow.getCosComponent(phase)),
        flow.getScaling(), flow.getUnit());
}

shp::Signal Mood::getSinComponent(const float phase) const {
	shp::Signal flow = this->getBeliefFlow();
	return shp::Signal(flow.getOrientation(), (flow.getSinComponent(phase)),
        flow.getScaling(), flow.getUnit());
}

const Mood Mood::getLooping(const Mood unitary, const float multiplier) {
    if (multiplier > 0) {
        Mood fresh = unitary;
        fresh.setEmotions(multiplier);
        return fresh;
    }
    return unitary;
}

const shp::Quantity Mood::getEmotionCharges() {
    shp::Quantity flowrate = getEmotionFlowRate();
    con::Belief emotion_belief(-con::Belief::EMOTION);
    shp::Quantity total = (flowrate * emotion_belief.getTrustRadius().getMagnitude()); total.adjustScaling();
    return total;
}

const shp::Quantity Mood::getEmotionFlowRate() {
    shp::Quantity standard(EMOTION_FLOW_RATE, EMOTION_FLOW_SCALE, EMOTION_SECOND);
    return standard;
}

} // namespace con