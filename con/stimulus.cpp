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

#include "stimulus.h"

namespace con {

Stimulus::Stimulus()
        : Behaviour(), input() {

}

Stimulus::Stimulus(const shp::Signal& input)
        : Behaviour(), input(input) {

}

Stimulus::Stimulus(const std::string name)
        : Behaviour(name), input() {

}

Stimulus::Stimulus(const std::string name, const shp::Signal& input)
        : Behaviour(name), input(input) {

}

Stimulus::~Stimulus() {

}

bool Stimulus::operator==(const Stimulus& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (input == peer.input);
}

Stimulus Stimulus::operator+(const Stimulus& peer) const {
    return Stimulus("+", (input + peer.input));
}

Stimulus Stimulus::operator-(const Stimulus& peer) const {
    return Stimulus("-", (input - peer.input));
}

Stimulus Stimulus::operator*(const Stimulus& peer) const {
    return Stimulus("*", (input * peer.input));
}

Stimulus Stimulus::operator/(const Stimulus& peer) const {
    return Stimulus("/", (input / peer.input));
}

Stimulus Stimulus::operator%(const Stimulus& peer) const {
    return Stimulus("%", (input % peer.input));
}

std::string Stimulus::getName() const {
    return Behaviour::getName();
}

void Stimulus::setName(const std::string name) {
    Behaviour::setName(name);
}

void Stimulus::setTemporalDelay(const shp::Temporal& time) {
    Behaviour::setDelay(time.getMagnitude(), time.getScaling(), time.getUnit());
}

float Stimulus::getTemporalDelay() const {
    return Behaviour::getDelay();
}

void Stimulus::setTemporalDelay(const float value) {
    Behaviour::setDelay(value);
}

void Stimulus::setTemporalDelay(const float value, const short int scale) {
    Behaviour::setDelay(value, scale);
}

void Stimulus::setTemporalDelay(const float value, const short int scale, const std::string unit) {
    Behaviour::setDelay(value, scale, unit);
}

void Stimulus::setTemporalDelay(const float value, const short int scale, const shp::Unit& unit) {
    Behaviour::setDelay(value, scale, unit);
}

short int Stimulus::getTemporalScaling() const {
    return Behaviour::getScaling();
}

void Stimulus::setTemporalScaling(const short int factor) {
    Behaviour::setScaling(factor);
}

shp::Unit Stimulus::getTemporalUnit() const {
    return Behaviour::getUnit();
}

void Stimulus::setTemporalUnit(const shp::Unit& object) {
    Behaviour::setUnit(object);
}

Stimulus Stimulus::copy() {
    Stimulus fresh(Behaviour::getName(), this->input);
    return fresh;
}

void Stimulus::clear() {
    Behaviour::clear();
    input.clear();
    return;
}

std::string Stimulus::print() const {
    std::stringstream result;
    result << "s:";
	result << Behaviour::print() << ",";
    result << input.print();
	return result.str();
}

} // namespace con