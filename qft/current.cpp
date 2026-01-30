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
        : qft::Charge(), velocity() {

}

Current::Current(const std::string name)
        : qft::Charge(), velocity(name) {

}

Current::Current(const qft::Charge& charge)
        : qft::Charge(charge.getMagnitude(), charge.getScaling(), charge.getUnit(), charge.getField()),
        velocity() {

}

Current::Current(const float charge)
        : qft::Charge(charge), velocity() {

}

Current::Current(const float charge, const std::string unit)
        : qft::Charge(charge, unit), velocity() {

}

Current::Current(const float charge, const shp::Unit& unit)
        : qft::Charge(charge, unit), velocity() {

}

Current::Current(const float charge, const short int scaling)
        : qft::Charge(charge, scaling), velocity() {

}

Current::Current(const float charge, const short int scaling, const std::string unit)
        : qft::Charge(charge, scaling, unit), velocity() {

}

Current::Current(const float charge, const short int scaling, const shp::Unit& unit)
        : qft::Charge(charge, scaling, unit), velocity() {

}

Current::Current(const qft::Velocity& velocity)
        : qft::Charge(), velocity(velocity) {

}

Current::Current(const std::string name, const qft::Charge& charge)
        : qft::Charge(charge), velocity(name) {

}

Current::Current(const std::string name, const float charge)
        : qft::Charge(charge), velocity(name) {

}

Current::Current(const std::string name, const float charge, const std::string unit)
        : qft::Charge(charge, unit), velocity(name) {

}

Current::Current(const std::string name, const float charge, const shp::Unit& unit)
        : qft::Charge(charge, unit), velocity(name) {

}

Current::Current(const std::string name, const float charge, const short int scaling)
        : qft::Charge(charge, scaling), velocity(name) {

}

Current::Current(const std::string name, const float charge, const short int scaling, const std::string unit)
        : qft::Charge(charge, scaling, unit), velocity(name) {

}

Current::Current(const std::string name, const float charge, const short int scaling, const shp::Unit& unit)
        : qft::Charge(charge, scaling, unit), velocity(name) {

}

Current::Current(const qft::Charge& charge, const qft::Velocity& velocity)
        : qft::Charge(charge.getMagnitude(), charge.getScaling(), charge.getUnit(), charge.getField()),
        velocity(velocity) {

}

Current::Current(const float charge, const float velocity)
        : qft::Charge(charge), velocity(velocity) {

}

Current::Current(const std::string name, const float charge, const float velocity)
        : qft::Charge(charge), velocity(name, velocity) {

}

Current::~Current() {

}

bool Current::operator==(const Current& peer) const {
    return (static_cast<const qft::Charge&>(*this) == static_cast<const qft::Charge&>(peer))
        && (velocity == peer.velocity);
}

bool Current::operator<(const Current& peer) const {
    Current self = *this; bool result = false;
    if (static_cast<const qft::Charge&>(*this) < static_cast<const qft::Charge&>(peer)) {
        result = true;
    } else if (self.velocity < peer.velocity) {
        result = true;
    }
    return result;
}

bool Current::operator>(const Current& peer) const {
    Current self = *this; bool result = false;
    if (static_cast<const qft::Charge&>(*this) > static_cast<const qft::Charge&>(peer)) {
        result = true;
    } else if (self.velocity > peer.velocity) {
        result = true;
    }
    return result;
}

bool Current::operator<=(const Current& peer) const {
    Current self = *this;
    return (self < peer) || (self == peer);
}

bool Current::operator>=(const Current& peer) const {
    Current self = *this;
    return (self > peer) || (self == peer);
}

Current Current::operator+(const Current& peer) const {
    Charge self = *this, other = peer, newCharge = (self + other);
    Velocity newVelocity = (this->velocity + peer.velocity);
    return Current(newCharge, newVelocity);
}

Current Current::operator-(const Current& peer) const {
    Charge self = *this, other = peer, newCharge = (self - other);
    Velocity newVelocity = (this->velocity - peer.velocity);
    return Current(newCharge, newVelocity);
}

Current Current::operator*(const Current& peer) const {
    Charge self = *this, other = peer, newCharge = (self * other);
    Velocity newVelocity = (this->velocity * peer.velocity);
    return Current(newCharge, newVelocity);
}

Current Current::operator/(const Current& peer) const {
    Charge self = *this, other = peer, newCharge = (self / other);
    Velocity newVelocity = (this->velocity / peer.velocity);
    return Current(newCharge, newVelocity);
}

Current Current::operator%(const Current& peer) const {
    Charge self = *this, other = peer, newCharge = (self % other);
    Velocity newVelocity = (this->velocity % peer.velocity);
    return Current(newCharge, newVelocity);
}

Current Current::operator+(const Charge& peer) const {
    Charge self = *this, newCharge = (self + peer);
    return Current(newCharge, this->velocity);
}

Current Current::operator-(const Charge& peer) const {
    Charge self = *this, newCharge = (self - peer);
    return Current(newCharge, this->velocity);
}

Current Current::operator*(const Charge& peer) const {
    Charge self = *this, newCharge = (self * peer);
    return Current(newCharge, this->velocity);
}

Current Current::operator/(const Charge& peer) const {
    Charge self = *this, newCharge = (self / peer);
    return Current(newCharge, this->velocity);
}

Current Current::operator%(const Charge& peer) const {
    Charge self = *this, newCharge = (self % peer);
    return Current(newCharge, this->velocity);
}

Current Current::operator+(const Velocity& peer) const {
    Current self = *this; Velocity newVelocity = (self.velocity + peer);
    return Current(self.getCharge(), newVelocity);
}

Current Current::operator-(const Velocity& peer) const {
    Current self = *this; Velocity newVelocity = (self.velocity - peer);
    return Current(self.getCharge(), newVelocity);
}

Current Current::operator*(const Velocity& peer) const {
    Current self = *this; Velocity newVelocity = (self.velocity * peer);
    return Current(self.getCharge(), newVelocity);
}

Current Current::operator/(const Velocity& peer) const {
    Current self = *this; Velocity newVelocity = (self.velocity / peer);
    return Current(self.getCharge(), newVelocity);
}

Current Current::operator%(const Velocity& peer) const {
    Current self = *this; Velocity newVelocity = (self.velocity % peer);
    return Current(self.getCharge(), newVelocity);
}

std::string Current::getName() const {
    return velocity.getName();
}

void Current::setName(const std::string name) {
    this->velocity.setName(name);
}

qft::Charge Current::getCharge() const {
    qft::Charge result = *this;
    return result;
}

void Current::setCharge(const qft::Charge& charge) {
    Charge::setMagnitude(charge.getMagnitude(), charge.getScaling(), charge.getUnit());
}

shp::Quantity Current::getMass() {
    Charge charge = *this; shp::Signal difference = charge.getPotential().getDifference();
    shp::Signal angular = velocity.getAngular(shp::Quantity::DEFAULT_VALUE);
    float magnitude = ((difference.getMagnitude() / angular.getMagnitude()) * charge.getMagnitude());
    shp::Quantity result(magnitude, charge.getScaling(), shp::Unit::getBaseSymbol(shp::Unit::MASS));
    return result;
}

shp::Quantity Current::getElectrons() const {
    Charge charge = *this; qft::Charge electron(qft::Charge::ELECTRON);
    float quantum = (charge.getMagnitude() / Current::getAmpereCoulombs().getMagnitude());
    return shp::Quantity((quantum / electron.getMagnitude()),
        (charge.getScaling() - electron.getScaling()), "e⁻");
}

void Current::setElectrons(const int count) {
    Charge charge = *this;
    if (count > 0) {
        qft::Charge electron(qft::Charge::ELECTRON);
        float total = (electron.getMagnitude() * count);
        charge.setMagnitude(total); charge.adjustScaling();
    }
}

void Current::changeFlowSpeed(const float motion) {
    velocity.setChangeMagnitude(motion);
}

void Current::changeFlowSpeed(const float motion, const short int scale) {
    velocity.setChangeMagnitude(motion, scale);
}

void Current::changeDirection(const float degree) {
    velocity.setChangeDirection(degree);
}

shp::Signal Current::getVoltage() const {
    Charge charge = *this;
    shp::Signal result = charge.getPotential().getDifference();
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return result;
}

shp::Signal Current::getPower(const Time& interval) const {
    shp::Signal result = (this->getForce(interval) * this->getVelocity().getTotal());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Current::getForce(const Time& interval) const {
    shp::Signal result = (this->getRateOfChange() / interval.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Current::getPotential() const {
    Charge charge = *this;      // non-moving electric charge only
    charge.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal current = charge.getPhaseSpace();
    shp::Signal result(current.getOrientation(), -current.getMagnitude(), current.getScaling(), current.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Current::getPotential(const shp::Signal& motion) const {
    Charge charge = *this;      // electric charge in a moving reference frame
    charge.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal current = charge.getPhaseConvergence(motion);
    shp::Signal result(current.getOrientation(), -current.getMagnitude(), current.getScaling(), current.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Current::getChargeFlow() const {
    Charge charge = *this;      // electric charge linearly moving, but non-accelerating
    charge.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal current = charge.getLinearSpace();
    shp::Signal result(current.getOrientation(), -current.getMagnitude(), current.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Current::getChargeFlow(const shp::Signal& motion) const {
    Charge charge = *this;      // linearly moving electric charge in non-accelerating conductor
    charge.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal current = charge.getLinearConvergence(motion);
    shp::Signal result(current.getOrientation(), -current.getMagnitude(), current.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Current::getInductance() const {
    Charge charge = *this;      // loop electric charge within a field
    charge.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal current = charge.getCurvedSpace();
    shp::Signal result(current.getOrientation(), -current.getMagnitude(), current.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Current::getInductance(const shp::Signal& motion) const {
    Charge charge = *this;      // loop electric charge carrying body moving in a field
    charge.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal current = charge.getCurvedConvergence(motion);
    shp::Signal result(current.getOrientation(),
        -current.getMagnitude(), current.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::ENERGY));
    result.adjustScaling();
    return result;
}

shp::Signal Current::getElectricPower() const {
    shp::Signal result = (this->getVoltage() * this->getChargeFlow());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Current::getElectroKinetic() const {
    Charge charge = *this; shp::Signal current = getChargeFlow();
    shp::Temporal total = (charge + charge);
    shp::Signal result = ((current * current) / total.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Current::getMagneticPower() const {
    shp::Signal result = (this->getVoltage() * this->getInductance());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Current::getMagnetoKinetic() const {
    Charge charge = *this; shp::Signal current = getInductance();
    shp::Temporal total = (charge + charge);
    shp::Signal result = ((current * current) / total.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Current::getRateOfChange() const {
    shp::Signal result = (this->getChargeFlow() - this->getInductance());
    result.adjustScaling();
    return result;
}

std::shared_ptr<Field> Current::getElectricField() const {
    Charge charge = *this;
    return charge.getOriginField();
}

std::shared_ptr<Field> Current::getMagneticField() const {
    Charge charge = *this;
    std::shared_ptr<Field> field = Field::shareable(Current::MAGNETIC_FIELD);
    shp::Signal motion = getRateOfChange();
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

bool Current::checkNonZero() const {
    Charge charge = *this;
    return (charge.checkNonZero() && velocity.checkNonZero());
}

shp::Signal Current::copy() const {
    Charge charge = *this;
    Current fresh = Current(charge, velocity);
    return fresh.getTotal();
}

void Current::clear() {
    Charge::clear();
    velocity.clear();
    return;
}

std::string Current::print() const {
    std::stringstream result;
    result << "I:";
    result << Charge::print() << ",";
    result << velocity.print();
    result << UNIT;
	return result.str();
}

std::string Current::printRadians() const {
    std::stringstream result;
    result << "I:";
    result << Charge::printRadians() << ",";
    result << velocity.printRadians();
    result << UNIT;
	return result.str();
}

shp::Signal Current::getCosComponent(const float phase) const {
	shp::Signal current = this->getChargeFlow();
	return shp::Signal(current.getOrientation(), (current.getCosComponent(phase)),
        current.getScaling(), current.getUnit());
}

shp::Signal Current::getSinComponent(const float phase) const {
	shp::Signal current = this->getChargeFlow();
	return shp::Signal(current.getOrientation(), (current.getSinComponent(phase)),
        current.getScaling(), current.getUnit());
}

const Current Current::getLooping(const Current unitary, const float multiplier) {
    if (multiplier > 0) {
        Current fresh = unitary;
        fresh.setElectrons(multiplier);
        return fresh;
    }
    return unitary;
}

const shp::Quantity Current::getAmpereCoulombs() {
    shp::Quantity flowrate = getAmpereFlowRate();
    qft::Charge electron_charge(-qft::Charge::ELECTRON);
    shp::Quantity total = (flowrate * electron_charge.getMagnitude()); total.adjustScaling();
    return total;
}

const shp::Quantity Current::getAmpereFlowRate() {
    shp::Quantity standard(ELECTRON_FLOW_RATE, ELECTRON_FLOW_SCALE, COULOMB_SECOND);
    return standard;
}

} // namespace qft