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
        : unit(UNIT), velocity(), change() {

}

Acceleration::Acceleration(std::string name)
        : unit(UNIT), velocity(name), change() {

}

Acceleration::Acceleration(const float change)
        : unit(UNIT), velocity(), change(change) {

}

Acceleration::Acceleration(const float velocity, const float change)
        : unit(UNIT), velocity(velocity), change(change) {

}

Acceleration::Acceleration(const qft::Velocity& velocity, const shp::Change& change)
        : unit(UNIT), velocity(velocity), change(change) {

}

Acceleration::Acceleration(const shp::Unit& unit)
        : unit(unit), velocity(), change() {

}

Acceleration::Acceleration(std::string name, const shp::Unit& unit)
        : unit(unit), velocity(name), change() {

}

Acceleration::Acceleration(std::string name, const float change)
        : unit(UNIT), velocity(name), change(change) {

}

Acceleration::Acceleration(std::string name, const float velocity, const float change)
        : unit(UNIT), velocity(name, velocity), change(change) {

}

Acceleration::Acceleration(const qft::Velocity& velocity, const shp::Change& change,
        const shp::Unit& unit)
        : unit(unit), velocity(velocity), change(change) {

}

Acceleration::~Acceleration() {

}

bool Acceleration::operator==(const Acceleration& peer) const {
    return (velocity == peer.velocity) && (change == peer.change);
}

Acceleration Acceleration::operator+(const Acceleration& peer) const {
    return Acceleration((velocity + peer.velocity), (change + peer.change));
}

Acceleration Acceleration::operator-(const Acceleration& peer) const {
    return Acceleration((velocity - peer.velocity), (change - peer.change));
}

Acceleration Acceleration::operator*(const Acceleration& peer) const {
    return Acceleration((velocity * peer.velocity), (change * peer.change));
}

Acceleration Acceleration::operator/(const Acceleration& peer) const {
    return Acceleration((velocity / peer.velocity), (change / peer.change));
}

shp::Quantity Acceleration::getTotal() const {
    float acceleration = (velocity.getTotal().getMagnitude() * cos(change.toRadians()));
    shp::Quantity result(acceleration, velocity.getDisplacement().getScaling(), getUnit());
    return result;
}

void Acceleration::adjustScaling() {
    velocity.adjustScaling();
}

Acceleration Acceleration::copy() {
    Acceleration fresh(velocity, change, unit);
    return fresh;
}

void Acceleration::clear() {
    unit.clear();
    velocity.clear();
    change.clear();
    return;
}

std::string Acceleration::print() {
    std::stringstream result;
    result << "a";
    result << velocity.print() << ",Δ";
	result << change.print();
    result << unit.print();
	return result.str();
}

shp::Quantity Acceleration::getComponent(float phase) const {
	shp::Quantity acceleration = getTotal();
	return shp::Quantity((acceleration.getMagnitude() * cos(phase)), acceleration.getScaling(), acceleration.getUnit());
}

} // namespace qft