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

#include "behaviour.h"

namespace con {

Behaviour::Behaviour()
        : shp::Temporal(), name() {

}

Behaviour::Behaviour(const shp::Unit& unit)
        : shp::Temporal(unit), name() {

}

Behaviour::Behaviour(const float delay)
        : shp::Temporal(delay), name() {

}

Behaviour::Behaviour(const float delay, const std::string unit)
        : shp::Temporal(delay, unit), name() {

}

Behaviour::Behaviour(const float delay, const shp::Unit& unit)
        : shp::Temporal(delay, unit), name() {

}

Behaviour::Behaviour(const float delay, const short int scaling)
        : shp::Temporal(delay, scaling), name() {

}

Behaviour::Behaviour(const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(delay, scaling, unit), name() {

}

Behaviour::Behaviour(const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(delay, scaling, unit), name() {

}

Behaviour::Behaviour(const shp::Intrinsic& intent, const float delay, const short int scaling)
        : shp::Temporal(intent, delay, scaling), name() {

}

Behaviour::Behaviour(const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(intent, delay, scaling, unit), name() {

}

Behaviour::Behaviour(const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(intent, delay, scaling, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience)
        : shp::Temporal(experience), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const shp::Unit& unit)
        : shp::Temporal(experience, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const float delay)
        : shp::Temporal(experience, delay), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const float delay, const std::string unit)
        : shp::Temporal(experience, delay, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const float delay, const shp::Unit& unit)
        : shp::Temporal(experience, delay, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const float delay, const short int scaling)
        : shp::Temporal(experience, delay, scaling), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(experience, delay, scaling, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(experience, delay, scaling, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling)
        : shp::Temporal(experience, intent, delay, scaling), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(experience, intent, delay, scaling, unit), name() {

}

Behaviour::Behaviour(const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(experience, intent, delay, scaling, unit), name() {

}

Behaviour::Behaviour(const std::string name)
        : shp::Temporal(), name(name) {

}

Behaviour::Behaviour(const std::string name, const std::string unit)
        : shp::Temporal(unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Unit& unit)
        : shp::Temporal(unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float delay)
        : shp::Temporal(delay), name(name) {

}

Behaviour::Behaviour(const std::string name, const float delay, const std::string unit)
        : shp::Temporal(delay, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float delay, const shp::Unit& unit)
        : shp::Temporal(delay, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float delay, const short int scaling)
        : shp::Temporal(delay, scaling), name(name) {

}

Behaviour::Behaviour(const std::string name, const float delay, const short int scaling,
        const std::string unit)
        : shp::Temporal(delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float delay, const short int scaling,
        const shp::Unit& unit)
        : shp::Temporal(delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Intrinsic& intent, const float delay, const short int scaling)
        : shp::Temporal(intent, delay, scaling), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(intent, delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(intent, delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience)
        : shp::Temporal(experience), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const shp::Unit& unit)
        : shp::Temporal(experience, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const float delay)
        : shp::Temporal(experience, delay), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const float delay, const std::string unit)
        : shp::Temporal(experience, delay, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const float delay, const shp::Unit& unit)
        : shp::Temporal(experience, delay, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const float delay, const short int scaling)
        : shp::Temporal(experience, delay, scaling), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(experience, delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(experience, delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling)
        : shp::Temporal(experience, intent, delay, scaling), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit)
        : shp::Temporal(experience, intent, delay, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(experience, intent, delay, scaling, unit), name(name) {

}

Behaviour::~Behaviour() {

}

bool Behaviour::operator==(const Behaviour& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (name == peer.name);
}

bool Behaviour::operator<(const Behaviour& peer) const {
    return (static_cast<const shp::Temporal&>(*this) < static_cast<const shp::Temporal&>(peer));
}

bool Behaviour::operator>(const Behaviour& peer) const {
    return (static_cast<const shp::Temporal&>(*this) > static_cast<const shp::Temporal&>(peer));
}

bool Behaviour::operator<=(const Behaviour& peer) const {
    Behaviour self = *this;
    return (self < peer) || (self == peer);
}

bool Behaviour::operator>=(const Behaviour& peer) const {
    Behaviour self = *this;
    return (self > peer) || (self == peer);
}

Behaviour Behaviour::operator+(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, interaction = (self + other);
    return Behaviour("+", interaction.getMagnitude(), interaction.getScaling(), interaction.getUnit());
}

Behaviour Behaviour::operator-(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, interaction = (self - other);
    return Behaviour("-", interaction.getMagnitude(), interaction.getScaling(), interaction.getUnit());
}

Behaviour Behaviour::operator*(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, interaction = (self * other);
    return Behaviour("*", interaction.getMagnitude(), interaction.getScaling(), interaction.getUnit());
}

Behaviour Behaviour::operator/(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, interaction = (self / other);
    return Behaviour("/", interaction.getMagnitude(), interaction.getScaling(), interaction.getUnit());
}

Behaviour Behaviour::operator%(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, interaction = (self % other);
    return Behaviour("%", interaction.getMagnitude(), interaction.getScaling(), interaction.getUnit());
}

shp::Signal Behaviour::getExperience() const {
    return shp::Temporal::getModulation();
}

void Behaviour::setExperience(const shp::Signal& knowledge) {
    shp::Temporal::setModulation(knowledge);
}

void Behaviour::setDelay(const shp::Temporal& necessity) {
    shp::Temporal::setMagnitude(necessity.getMagnitude(), necessity.getScaling(), necessity.getUnit());
}

float Behaviour::getDelay() const {
    return shp::Temporal::getMagnitude();
}

void Behaviour::setDelay(const float necessity) {
    shp::Temporal::setMagnitude(necessity);
}

void Behaviour::setDelay(const float necessity, const short int scale) {
    shp::Temporal::setMagnitude(necessity, scale);
}

void Behaviour::setDelay(const float necessity, const short int scale, const std::string unit) {
    shp::Temporal::setMagnitude(necessity, scale, unit);
}

void Behaviour::setDelay(const float necessity, const short int scale, const shp::Unit& unit) {
    shp::Temporal::setMagnitude(necessity, scale, unit);
}

float Behaviour::getIntention() const {
    return shp::Temporal::getIntensity();
}

float Behaviour::getIntentionDrift() const {
    return shp::Temporal::getIntensityDrift();
}

void Behaviour::setIntentionDrift(const shp::Intrinsic& moderation) {
    shp::Temporal::setIntensityDrift(moderation.toRadians());
}

float Behaviour::getExperienceShift() const {
    return shp::Temporal::getSpatialDrift();
}

void Behaviour::setExperienceShift(const shp::Intrinsic& moderation) {
	shp::Temporal::setSpatialDrift(moderation);
}

void Behaviour::setExperienceShift(const float action,
        const shp::Intrinsic& moderation) {
	shp::Temporal::setSpatialDrift(action, moderation);
}

void Behaviour::setExperienceShift(const float action, const short int scale,
        const shp::Intrinsic& moderation) {
	shp::Temporal::setSpatialDrift(action, scale, moderation);
}

void Behaviour::setExperienceShift(const float action, const short int scale, const std::string unit,
        const shp::Intrinsic& moderation) {
	shp::Temporal::setSpatialDrift(action, scale, unit, moderation);
}

void Behaviour::setExperienceShift(const float action, const short int scale, const shp::Unit& unit,
        const shp::Intrinsic& moderation) {
	shp::Temporal::setSpatialDrift(action, scale, unit, moderation);
}

short int Behaviour::getScaling() const {
    return shp::Temporal::getScaling();
}

void Behaviour::setScaling(const short int factor) {
    shp::Temporal::setScaling(factor);
}

shp::Unit Behaviour::getUnit() const {
    return shp::Temporal::getUnit();
}

void Behaviour::setUnit(const shp::Unit& object) {
    shp::Temporal::setUnit(object);
}

shp::Quantity Behaviour::getDelayShift() const {
    return shp::Temporal::getPhaseShift();
}

shp::Signal Behaviour::getFrequency() const {
    shp::Signal frequency = shp::Temporal::getFrequency();
    return shp::Signal(frequency.getMagnitude(), frequency.getScaling(), frequency.getUnit());
}

shp::Signal Behaviour::getTotal() const {
    return shp::Temporal::getTotal();
}

Behaviour Behaviour::copy() {
    shp::Temporal self = *this;
    Behaviour fresh(this->getName(), self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Behaviour::clear() {
    shp::Temporal::clear();
    name.clear();
    return;
}

std::string Behaviour::print() const {
    std::stringstream result;
	result << name << ",";
    result << shp::Temporal::print();
	return result.str();
}

std::string Behaviour::printRadians() const {
    std::stringstream result;
	result << name << ",";
    result << shp::Temporal::printRadians();
	return result.str();
}

} // namespace con