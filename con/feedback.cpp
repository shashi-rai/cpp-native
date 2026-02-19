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

#include "feedback.h"

namespace con {

Feedback::Feedback()
        : Behaviour(), adjustment(), threshold() {

}

Feedback::Feedback(const shp::Signal& adjustment)
        : Behaviour(), adjustment(adjustment), threshold() {

}

Feedback::Feedback(const shp::Frequency& threshold)
        : Behaviour(), adjustment(), threshold(threshold) {

}

Feedback::Feedback(const shp::Signal& adjustment, const shp::Frequency& threshold)
        : Behaviour(), adjustment(adjustment), threshold(threshold) {

}

Feedback::Feedback(const std::string name)
        : Behaviour(name), adjustment(), threshold() {

}

Feedback::Feedback(const std::string name, const shp::Signal& adjustment)
        : Behaviour(name), adjustment(adjustment), threshold() {

}

Feedback::Feedback(const std::string name, const shp::Frequency& threshold)
        : Behaviour(name), adjustment(), threshold(threshold){

}

Feedback::Feedback(const std::string name, const shp::Signal& adjustment, const shp::Frequency& threshold)
        : Behaviour(name), adjustment(adjustment), threshold(threshold) {

}

Feedback::~Feedback() {

}

bool Feedback::operator==(const Feedback& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (adjustment == peer.adjustment) && (threshold == peer.threshold);
}

Feedback Feedback::operator+(const Feedback& peer) const {
    return Feedback("+", (adjustment + peer.adjustment), (threshold + peer.threshold));
}

Feedback Feedback::operator-(const Feedback& peer) const {
    return Feedback("-", (adjustment - peer.adjustment), (threshold - peer.threshold));
}

Feedback Feedback::operator*(const Feedback& peer) const {
    return Feedback("*", (adjustment * peer.adjustment), (threshold * peer.threshold));
}

Feedback Feedback::operator/(const Feedback& peer) const {
    return Feedback("/", (adjustment / peer.adjustment), (threshold / peer.threshold));
}

Feedback Feedback::operator%(const Feedback& peer) const {
    return Feedback("%", (adjustment % peer.adjustment), (threshold % peer.threshold));
}

shp::Signal Feedback::operator()(const Feedback& feedback) const {
    Feedback result;
    if (this->getName() == feedback.getName()) {
        result = (this->getAdjustment().getDotProduct(feedback.getAdjustment()));
    } else {
        result = (this->getAdjustment().getCrossProduct(feedback.getAdjustment()));
    }
    return result.getAdjustment();
}

std::string Feedback::getName() const {
    return Behaviour::getName();
}

void Feedback::setName(const std::string name) {
    Behaviour::setName(name);
}

void Feedback::setFrequencyThreshold(const shp::Frequency& repetition) {
    threshold.setMagnitude(repetition.getMagnitude(), repetition.getScaling(), repetition.getUnit());
}

float Feedback::getFrequencyThreshold() const {
    return threshold.getMagnitude();
}

void Feedback::setFrequencyThreshold(const float value) {
    threshold.setMagnitude(value);
}

void Feedback::setFrequencyThreshold(const float value, const short int scale) {
    threshold.setMagnitude(value, scale);
}

void Feedback::setFrequencyThreshold(const float value, const short int scale, const std::string unit) {
    threshold.setMagnitude(value, scale, unit);
}

void Feedback::setFrequencyThreshold(const float value, const short int scale, const shp::Unit& unit) {
    threshold.setMagnitude(value, scale, unit);
}

short int Feedback::getFrequencyScaling() const {
    return threshold.getScaling();
}

void Feedback::setFrequencyScaling(const short int factor) {
    threshold.setScaling(factor);
}

shp::Unit Feedback::getFrequencyUnit() const {
    return threshold.getUnit();
}

void Feedback::setFrequencyUnit(const shp::Unit& object) {
    threshold.setUnit(object);
}

void Feedback::setTemporalDelay(const shp::Temporal& time) {
    Behaviour::setDelay(time.getMagnitude(), time.getScaling(), time.getUnit());
}

float Feedback::getTemporalDelay() const {
    return Behaviour::getDelay();
}

void Feedback::setTemporalDelay(const float value) {
    Behaviour::setDelay(value);
}

void Feedback::setTemporalDelay(const float value, const short int scale) {
    Behaviour::setDelay(value, scale);
}

void Feedback::setTemporalDelay(const float value, const short int scale, const std::string unit) {
    Behaviour::setDelay(value, scale, unit);
}

void Feedback::setTemporalDelay(const float value, const short int scale, const shp::Unit& unit) {
    Behaviour::setDelay(value, scale, unit);
}

short int Feedback::getTemporalScaling() const {
    return Behaviour::getScaling();
}

void Feedback::setTemporalScaling(const short int factor) {
    Behaviour::setScaling(factor);
}

shp::Unit Feedback::getTemporalUnit() const {
    return Behaviour::getUnit();
}

void Feedback::setTemporalUnit(const shp::Unit& object) {
    Behaviour::setUnit(object);
}

Feedback Feedback::copy() {
    Feedback fresh(Behaviour::getName(), this->adjustment, this->threshold);
    return fresh;
}

void Feedback::clear() {
    Behaviour::clear();
	threshold.clear();
    adjustment.clear();
    return;
}

std::string Feedback::print() const {
    std::stringstream result;
    result << "f:";
	result << Behaviour::print() << ",";
	result << threshold.print() << ",";
    result << adjustment.print() << ",";
	return result.str();
}

} // namespace con