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
const std::string Current::COULOMB_SECOND = "C/s";      // Coulomb per second
const std::string Current::ELECTRIC_FIELD = "Electric"; // Electric Field
const std::string Current::MAGNETIC_FIELD = "Magnetic"; // Magnetic Field
const float Current::ELECTRON_FLOW_RATE = 6.241509f;    // 6.241509x10^18 electrons per second
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

Current::Current(const qft::Charge& charge, const qft::Acceleration& velocity)
        : name(), charge(charge), velocity(velocity) {

}

Current::Current(std::string name, const float charge, const float velocity)
        : name(name), charge(charge), velocity(velocity) {

}

Current::Current(std::string name, const qft::Charge& charge, const qft::Acceleration& velocity)
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

Acceleration Current::getAcceleration() const {
    return velocity;
}

shp::Quantity Current::getElectrons() const {
    qft::Charge electron(qft::Charge::ELECTRON);
    float quantum = (charge.getMagnitude() / Current::getAmpereCoulombs().getMagnitude());
    return shp::Quantity((quantum / electron.getMagnitude()),
        (charge.getScaling() - electron.getScaling()), "e⁻");
}

void Current::setElectrons(const int count) {
    if (count > 0) {
        qft::Charge electron(qft::Charge::ELECTRON);
        float total = (electron.getMagnitude() * count);
        charge.setMagnitude(total); charge.adjustScaling();
    }
}

void Current::applyChangeTogether() {
    applyChangeFlowSpeed();
    applyChangeDirection();
}

void Current::changeFlowSpeed(const float motion) {
    velocity.setChangeMagnitude(motion);
}

void Current::applyChangeFlowSpeed() {
    velocity.applyChangeMagnitude();
}

void Current::changeDirection(const float degree) {
    velocity.setChangeDirection(degree);
}

void Current::applyChangeDirection() {
    velocity.applyChangeDirection();
}

shp::Quantity Current::getVoltage() const {
    shp::Quantity result = charge.getPotential().getDifference();
    return result;
}

shp::Quantity Current::getForce(const Time& interval) const {
    shp::Quantity result = (getRateOfChange() / interval.getMagnitude());
    return result;
}

shp::Quantity Current::getLinearTotal() const {
    qft::Velocity invariant = velocity;     // non-accelerating component only
    float current = charge.getMagnitude() * invariant.getTotal().getMagnitude();
    short int scaling = charge.getScaling() + invariant.getTotal().getScaling();
    shp::Quantity result(-current, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Quantity Current::getLinearPower() const {
    shp::Quantity result = (getVoltage() * getLinearTotal());
    return result;
}

shp::Quantity Current::getLinearKinetic() const {
    shp::Quantity current = getLinearTotal();
    shp::Quantity result = ((current * current) / (charge + charge));
    return result;
}

shp::Quantity Current::getAngularTotal() const {    // directional acceleration
    float current = charge.getMagnitude() * velocity.getTotal().getMagnitude();
    short int scaling = charge.getScaling() + velocity.getTotal().getScaling();
    shp::Quantity result(-current, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Quantity Current::getAngularPower() const {
    shp::Quantity result = (getVoltage() * getAngularTotal());
    return result;
}

shp::Quantity Current::getAngularKinetic() const {
    shp::Quantity current = getAngularTotal();
    shp::Quantity result = ((current * current) / (charge + charge));
    return result;
}

shp::Quantity Current::getRateOfChange() const {
    shp::Quantity result = (getLinearTotal() - getAngularTotal());
    result.adjustScaling();
    return result;
}

std::shared_ptr<Field> Current::getElectricField() const {
    return charge.getOriginField();
}

std::shared_ptr<Field> Current::getMagneticField() const {
    std::shared_ptr<Field> field = Field::shareable(Current::MAGNETIC_FIELD);
    shp::Quantity motion = getRateOfChange();
    if (motion.checkNonZero()) {
        field->setPotential(shp::Potential(motion.getMagnitude(),
            shp::Quantity::DEFAULT_VALUE, motion.getScaling(), charge.getUnit(),
            shp::Angular(Energy::getPlanckLength())));
    } else {
        field->setPotential(shp::Potential(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, charge.getScaling(), charge.getUnit(),
            shp::Angular(Energy::getPlanckLength())));
    }
    shp::Direction orientation = velocity.getDirection().getNormal();
    field->setLinear(orientation);
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
	shp::Quantity current = getLinearTotal();
	return shp::Quantity((current.getMagnitude() * cos(phase)), current.getScaling(), current.getUnit());
}

const shp::Quantity Current::getAmpereCoulombs() {
    shp::Quantity flowrate = getAmpereFlowRate();
    qft::Charge electron_charge(-qft::Charge::ELECTRON);
    shp::Quantity total = (flowrate * electron_charge); total.adjustScaling();
    return total;
}

const shp::Quantity Current::getAmpereFlowRate() {
    shp::Quantity standard(ELECTRON_FLOW_RATE, ELECTRON_FLOW_SCALE, COULOMB_SECOND);
    return standard;
}

} // namespace qft