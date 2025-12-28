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

#include "current.h"
#include "field.h"

namespace qft {

const std::string Current::UNIT = "A";                  // System International (i.e. C/s)
const std::string Current::ELECTRIC_FIELD = "Electric"; // Electric Field
const std::string Current::MAGNETIC_FIELD = "Magnetic"; // Magnetic Field
const float Current::ELECTRON_FLOW_RATE = 6.24f;        // 6.24x10^18 electrons per second
const short int Current::ELECTRON_FLOW_SCALE = 18;      // 10^18

Current::Current()
        : name(), charge(), velocity() {

}

Current::Current(std::string name)
        : name(name), charge(), velocity() {

}

Current::Current(const qft::Charge& charge)
        : name(), charge(charge), velocity() {

}

Current::Current(std::string name, const qft::Charge& charge)
        : name(name), charge(charge), velocity() {

}

Current::Current(const float charge, const float velocity)
        : name(), charge(charge), velocity(velocity) {

}

Current::Current(const qft::Charge& charge, const qft::Velocity& velocity)
        : name(), charge(charge), velocity(velocity) {

}

Current::Current(std::string name, const float charge, const float velocity)
        : name(name), charge(charge), velocity(velocity) {

}

Current::Current(std::string name, const qft::Charge& charge, const qft::Velocity& velocity)
        : name(name), charge(charge), velocity(velocity) {

}

Current::~Current() {

}

bool Current::operator==(const Current& peer) const {
    return (charge == peer.charge) && (velocity == peer.velocity);
}

Current Current::operator+(const Current& peer) const {
    return Current("+", (charge + peer.charge), (velocity + peer.velocity));
}

Current Current::operator-(const Current& peer) const {
    return Current("-", (charge - peer.charge), (velocity - peer.velocity));
}

Current Current::operator*(const Current& peer) const {
    return Current("*", (charge * peer.charge), (velocity * peer.velocity));
}

Current Current::operator/(const Current& peer) const {
    return Current("/", (charge / peer.charge), (velocity / peer.velocity));
}

shp::Quantity Current::getTotal() const {
    float current = charge.getMagnitude() * velocity.getTotal().getMagnitude();
    short int scaling = charge.getScaling() + velocity.getTotal().getScaling();
    shp::Quantity result(current, scaling, UNIT); 
    return result;
}

std::shared_ptr<Field> Current::getElectricField() const {
    std::shared_ptr<Field> field = Field::shareable(Current::ELECTRIC_FIELD);
    field->setPotential(shp::Potential(charge.getMagnitude(), 0, charge.getScaling(), charge.getUnit()));
    return field;
}

std::shared_ptr<Field> Current::getMagneticField() const {
    std::shared_ptr<Field> field = Field::shareable(Current::MAGNETIC_FIELD);
    field->setPotential(shp::Potential(charge.getMagnitude(), 0, charge.getScaling(), charge.getUnit()));
    field->setLinear(shp::Direction(90, 0, 0));
    return field;
}

Current Current::copy() {
    Current fresh(name, charge, velocity);
    return fresh;
}

void Current::clear() {
    name.clear();
    charge.clear();
    velocity.clear();
    return;
}

std::string Current::print() {
    std::stringstream result;
    result << "I:";
    result << name << ",";
    result << charge.print() << ",";
    result << velocity.print();
    result << UNIT;
	return result.str();
}

shp::Quantity Current::getComponent(float phase) const {
	shp::Quantity current = getTotal();
	return shp::Quantity((current.getMagnitude() * cos(phase)), current.getScaling(), current.getUnit());
}

} // namespace qft