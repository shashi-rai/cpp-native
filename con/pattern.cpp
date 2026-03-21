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

#include "pattern.h"

namespace con {

Pattern::Pattern()
        : Behaviour(), stimulus(), feedback(), response() {

}

Pattern::Pattern(const shp::Unit& unit)
        : Behaviour(unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const float delay)
        : Behaviour(delay), stimulus(), feedback(), response() {

}

Pattern::Pattern(const float delay, const std::string unit)
        : Behaviour(delay, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const float delay, const shp::Unit& unit)
        : Behaviour(delay, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const float delay, const short int scaling)
        : Behaviour(delay, scaling), stimulus(), feedback(), response() {

}

Pattern::Pattern(const float delay, const short int scaling, const std::string unit)
        : Behaviour(delay, scaling, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const float delay, const short int scaling, const shp::Unit& unit)
        : Behaviour(delay, scaling, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const Stimulus& stimulus)
        : Behaviour(), stimulus(stimulus), feedback(), response() {

}

Pattern::Pattern(const Feedback& feedback)
        : Behaviour(), stimulus(), feedback(feedback), response() {

}

Pattern::Pattern(const Response& response)
        : Behaviour(), stimulus(), feedback(), response(response) {

}

Pattern::Pattern(const Stimulus& stimulus, const Feedback& feedback)
        : Behaviour(), stimulus(stimulus), feedback(feedback), response() {

}

Pattern::Pattern(const Stimulus& stimulus, const Response& response)
        : Behaviour(), stimulus(stimulus), feedback(), response(response) {

}

Pattern::Pattern(const Feedback& feedback, const Response& response)
        : Behaviour(), stimulus(), feedback(feedback), response(response) {

}

Pattern::Pattern(const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Behaviour(), stimulus(stimulus), feedback(feedback), response(response) {

}

Pattern::Pattern(const float delay, const short int scaling, const shp::Unit& unit,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Behaviour(delay, scaling, unit), stimulus(stimulus), feedback(feedback), response(response) {

}

Pattern::Pattern(const std::string name)
        : Behaviour(name), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const shp::Unit& unit)
        : Behaviour(name, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const float delay)
        : Behaviour(name, delay), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const float delay, const std::string unit)
        : Behaviour(name, delay, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const float delay, const shp::Unit& unit)
        : Behaviour(name, delay, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const float delay, const short int scaling)
        : Behaviour(name, delay, scaling), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const float delay, const short int scaling, const std::string unit)
        : Behaviour(name, delay, scaling, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const float delay, const short int scaling, const shp::Unit& unit)
        : Behaviour(name, delay, scaling, unit), stimulus(), feedback(), response() {

}

Pattern::Pattern(const std::string name, const Stimulus& stimulus)
        : Behaviour(name), stimulus(stimulus), feedback(), response() {

}

Pattern::Pattern(const std::string name, const Feedback& feedback)
        : Behaviour(name), stimulus(), feedback(feedback), response() {

}

Pattern::Pattern(const std::string name, const Response& response)
        : Behaviour(name), stimulus(), feedback(), response(response) {

}

Pattern::Pattern(const std::string name, const Stimulus& stimulus, const Feedback& feedback)
        : Behaviour(name), stimulus(stimulus), feedback(feedback), response() {

}

Pattern::Pattern(const std::string name, const Stimulus& stimulus, const Response& response)
        : Behaviour(name), stimulus(stimulus), feedback(), response(response) {

}

Pattern::Pattern(const std::string name, const Feedback& feedback, const Response& response)
        : Behaviour(name), stimulus(), feedback(feedback), response(response) {

}

Pattern::Pattern(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Behaviour(name), stimulus(stimulus), feedback(feedback), response(response) {

}

Pattern::Pattern(const std::string name, const float delay, const short int scaling, const shp::Unit& unit,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Behaviour(name, delay, scaling, unit), stimulus(stimulus), feedback(feedback), response(response) {

}

Pattern::~Pattern() {

}

bool Pattern::operator==(const Pattern& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (stimulus == peer.stimulus) && (feedback == peer.feedback) && (response == peer.response);
}

Pattern Pattern::operator+(const Pattern& peer) const {
    return Pattern("+", (stimulus + peer.stimulus), (feedback + peer.feedback), (response + peer.response));
}

Pattern Pattern::operator-(const Pattern& peer) const {
    return Pattern("-", (stimulus - peer.stimulus), (feedback - peer.feedback), (response - peer.response));
}

Pattern Pattern::operator*(const Pattern& peer) const {
    return Pattern("*", (stimulus * peer.stimulus), (feedback * peer.feedback), (response * peer.response));
}

Pattern Pattern::operator/(const Pattern& peer) const {
    return Pattern("/", (stimulus / peer.stimulus), (feedback / peer.feedback), (response / peer.response));
}

Pattern Pattern::operator%(const Pattern& peer) const {
    return Pattern("%", (stimulus % peer.stimulus), (feedback % peer.feedback), (response % peer.response));
}

std::string Pattern::getName() const {
    return Behaviour::getName();
}

void Pattern::setName(const std::string name) {
    Behaviour::setName(name);
}

void Pattern::setTemporalDelay(const shp::Temporal& time) {
    Behaviour::setDelay(time.getMagnitude(), time.getScaling(), time.getUnit());
}

float Pattern::getTemporalDelay() const {
    return Behaviour::getDelay();
}

void Pattern::setTemporalDelay(const float value) {
    Behaviour::setDelay(value);
}

void Pattern::setTemporalDelay(const float value, const short int scale) {
    Behaviour::setDelay(value, scale);
}

void Pattern::setTemporalDelay(const float value, const short int scale, const std::string unit) {
    Behaviour::setDelay(value, scale, unit);
}

void Pattern::setTemporalDelay(const float value, const short int scale, const shp::Unit& unit) {
    Behaviour::setDelay(value, scale, unit);
}

short int Pattern::getTemporalScaling() const {
    return Behaviour::getScaling();
}

void Pattern::setTemporalScaling(const short int factor) {
    Behaviour::setScaling(factor);
}

shp::Unit Pattern::getTemporalUnit() const {
    return Behaviour::getUnit();
}

void Pattern::setTemporalUnit(const shp::Unit& object) {
    Behaviour::setUnit(object);
}

shp::Quantity Pattern::getAgeShift() const {
    return Behaviour::getDelayShift();
}

shp::Signal Pattern::getIndicative() const {
    return Behaviour::getRepeating();
}

shp::Signal Pattern::getMemorable() const {
    return Behaviour::getEndurance();
}

Pattern Pattern::copy() {
    Pattern fresh(Behaviour::getName(), Behaviour::getDelay(), Behaviour::getScaling(), Behaviour::getUnit(),
        this->stimulus, this->feedback, this->response);
    return fresh;
}

void Pattern::clear() {
    Behaviour::clear();
    stimulus.clear();
    feedback.clear();
    response.clear();
    return;
}

std::string Pattern::print() const {
    std::stringstream result;
    result << "(";
	result << Behaviour::print() << ",";
    result << stimulus.print() << ",";
    result << feedback.print() << ",";
    result << response.print();
    result << ")";
	return result.str();
}

std::string Pattern::printRadians() const {
    std::stringstream result;
    result << "(";
	result << Behaviour::printRadians() << ",";
    result << stimulus.printRadians() << ",";
    result << feedback.printRadians() << ",";
    result << response.printRadians();
    result << ")";
	return result.str();
}

} // namespace con