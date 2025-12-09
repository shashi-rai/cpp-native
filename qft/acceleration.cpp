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

#include "acceleration.h"

namespace qft {

const std::string Acceleration::UNIT = "m/s^2";     // System International

Acceleration::Acceleration()
        : name(), unit(UNIT), velocity(), change() {

}

Acceleration::Acceleration(std::string name)
        : name(name), unit(UNIT), velocity(), change() {

}

Acceleration::Acceleration(const float change)
        : name(), unit(UNIT), velocity(), change(change) {

}

Acceleration::Acceleration(const float velocity, const float change)
        : name(), unit(UNIT), velocity(velocity), change(change) {

}

Acceleration::Acceleration(const qft::Velocity& velocity, const shp::Change& change)
        : name(), unit(UNIT), velocity(velocity), change(change) {

}

Acceleration::Acceleration(std::string name, const shp::Unit& unit) : name(name), unit(unit),
        velocity(), change() {

}

Acceleration::Acceleration(std::string name, const float velocity, const float change)
        : name(name), unit(UNIT), velocity(velocity), change(change) {

}

Acceleration::Acceleration(std::string name, const shp::Unit& unit,
        const qft::Velocity& velocity, const shp::Change& change)
        : name(name), unit(unit), velocity(velocity), change(change) {

}

Acceleration::Acceleration(std::string name,
        const qft::Velocity& velocity, const shp::Change& change)
        : name(name), unit(UNIT), velocity(velocity), change(change) {

}

Acceleration::~Acceleration() {

}

bool Acceleration::operator==(const Acceleration& peer) const {
    return (velocity == peer.velocity) && (change == peer.change);
}

Acceleration Acceleration::operator+(const Acceleration& peer) const {
    return Acceleration("+", (velocity + peer.velocity), (change + peer.change));
}

Acceleration Acceleration::operator-(const Acceleration& peer) const {
    return Acceleration("-", (velocity - peer.velocity), (change - peer.change));
}

Acceleration Acceleration::operator*(const Acceleration& peer) const {
    return Acceleration("*", (velocity * peer.velocity), (change * peer.change));
}

Acceleration Acceleration::operator/(const Acceleration& peer) const {
    return Acceleration("/", (velocity / peer.velocity), (change / peer.change));
}

float Acceleration::getTotal() const {
    float result = (velocity.getTotal() * cos(change.toRadians()));
    return result;
}

Acceleration Acceleration::copy() {
    Acceleration fresh(name, unit, velocity, change);
    return fresh;
}

void Acceleration::clear() {
	name = "";
    unit.clear();
    velocity.clear();
    change.clear();
    return;
}

std::string Acceleration::print() {
    std::stringstream result;
    result << "[a:";
	result << name << ",";
    result << velocity.print() << ",";
	result << change.print();
    result << unit.print() << "]";
	return result.str();
}

float Acceleration::getComponent(float phase) const {
    return getTotal() * cos(phase);
}

} // namespace qft