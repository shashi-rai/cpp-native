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

#include "momentum.h"
#include "field.h"

namespace qft {

const std::string Momentum::UNIT = "kg.m/s";            // System International
const std::string Momentum::KILOGRAM_SECOND = "kg/s";   // Kilogram per second
const std::string Momentum::GRAVITY_FIELD = "Gravity";  // Gravity Field
const float Momentum::ELECTRON_FLOW_RATE = 6.241509f;   // 6.241509x10^18 electrons per second
const short int Momentum::ELECTRON_FLOW_SCALE = 18;     // 10^18

Momentum::Momentum()
        : qft::Mass(), velocity() {

}

Momentum::Momentum(const std::string name)
        : qft::Mass(), velocity(name) {

}

Momentum::Momentum(const qft::Mass& mass)
        : qft::Mass(mass.getMagnitude(), mass.getScaling(), mass.getUnit(), mass.getField()),
        velocity() {

}

Momentum::Momentum(const float mass)
        : qft::Mass(mass), velocity() {

}

Momentum::Momentum(const float mass, const std::string unit)
        : qft::Mass(mass, unit), velocity() {

}

Momentum::Momentum(const float mass, const shp::Unit& unit)
        : qft::Mass(mass, unit), velocity() {

}

Momentum::Momentum(const float mass, const short int scaling)
        : qft::Mass(mass, scaling), velocity() {

}

Momentum::Momentum(const float mass, const short int scaling, const std::string unit)
        : qft::Mass(mass, scaling, unit), velocity() {

}

Momentum::Momentum(const float mass, const short int scaling, const shp::Unit& unit)
        : qft::Mass(mass, scaling, unit), velocity() {

}

Momentum::Momentum(const qft::Velocity& velocity)
        : qft::Mass(), velocity(velocity) {

}

Momentum::Momentum(const std::string name, const qft::Mass& mass)
        : qft::Mass(mass.getMagnitude(), mass.getScaling(), mass.getUnit(), mass.getField()),
        velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass)
        : qft::Mass(mass), velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass, const std::string unit)
        : qft::Mass(mass, unit), velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass, const shp::Unit& unit)
        : qft::Mass(mass, unit), velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass, const short int scaling)
        : qft::Mass(mass, scaling), velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass, const short int scaling, const std::string unit)
        : qft::Mass(mass, scaling, unit), velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass, const short int scaling, const shp::Unit& unit)
        : qft::Mass(mass, scaling, unit), velocity(name) {

}

Momentum::Momentum(const std::string name, const float mass, const float velocity)
        : qft::Mass(mass), velocity(name, velocity) {

}

Momentum::Momentum(const float mass, const float velocity)
        : qft::Mass(mass), velocity(velocity) {

}

Momentum::Momentum(const qft::Mass& mass, const qft::Velocity& velocity)
        : qft::Mass(mass.getMagnitude(), mass.getScaling(), mass.getUnit(), mass.getField()),
        velocity(velocity) {

}

Momentum::~Momentum() {

}

bool Momentum::operator==(const Momentum& peer) const {
    return (static_cast<const qft::Mass&>(*this) == static_cast<const qft::Mass&>(peer))
        && (velocity == peer.velocity);
}

bool Momentum::operator<(const Momentum& peer) const {
    Momentum self = *this; bool result = false;
    if (static_cast<const qft::Mass&>(*this) < static_cast<const qft::Mass&>(peer)) {
        result = true;
    } else if (self.velocity < peer.velocity) {
        result = true;
    }
    return result;
}

bool Momentum::operator>(const Momentum& peer) const {
    Momentum self = *this; bool result = false;
    if (static_cast<const qft::Mass&>(*this) > static_cast<const qft::Mass&>(peer)) {
        result = true;
    } else if (self.velocity > peer.velocity) {
        result = true;
    }
    return result;
}

bool Momentum::operator<=(const Momentum& peer) const {
    Momentum self = *this;
    return (self < peer) || (self == peer);
}

bool Momentum::operator>=(const Momentum& peer) const {
    Momentum self = *this;
    return (self > peer) || (self == peer);
}

Momentum Momentum::operator+(const Momentum& peer) const {
    Mass self = *this, other = peer, newMass = (self + other);
    Velocity newVelocity = (this->velocity + peer.velocity);
    return Momentum(newMass, newVelocity);
}

Momentum Momentum::operator-(const Momentum& peer) const {
    Mass self = *this, other = peer, newMass = (self - other);
    Velocity newVelocity = (this->velocity - peer.velocity);
    return Momentum(newMass, newVelocity);
}

Momentum Momentum::operator*(const Momentum& peer) const {
    Mass self = *this, other = peer, newMass = (self * other);
    Velocity newVelocity = (this->velocity * peer.velocity);
    return Momentum(newMass, newVelocity);
}

Momentum Momentum::operator/(const Momentum& peer) const {
    Mass self = *this, other = peer, newMass = (self / other);
    Velocity newVelocity = (this->velocity / peer.velocity);
    return Momentum(newMass, newVelocity);
}

Momentum Momentum::operator%(const Momentum& peer) const {
    Mass self = *this, other = peer, newMass = (self % other);
    Velocity newVelocity = (this->velocity % peer.velocity);
    return Momentum(newMass, newVelocity);
}

Momentum Momentum::operator+(const Mass& peer) const {
    Mass self = *this, newMass = (self + peer);
    return Momentum(newMass, this->velocity);
}

Momentum Momentum::operator-(const Mass& peer) const {
    Mass self = *this, newMass = (self - peer);
    return Momentum(newMass, this->velocity);
}

Momentum Momentum::operator*(const Mass& peer) const {
    Mass self = *this, newMass = (self * peer);
    return Momentum(newMass, this->velocity);
}

Momentum Momentum::operator/(const Mass& peer) const {
    Mass self = *this, newMass = (self / peer);
    return Momentum(newMass, this->velocity);
}

Momentum Momentum::operator%(const Mass& peer) const {
    Mass self = *this, newMass = (self % peer);
    return Momentum(newMass, this->velocity);
}

Momentum Momentum::operator+(const Velocity& peer) const {
    Momentum self = *this; Velocity newVelocity = (self.velocity + peer);
    return Momentum(self.getMass(), newVelocity);
}

Momentum Momentum::operator-(const Velocity& peer) const {
    Momentum self = *this; Velocity newVelocity = (self.velocity - peer);
    return Momentum(self.getMass(), newVelocity);
}

Momentum Momentum::operator*(const Velocity& peer) const {
    Momentum self = *this; Velocity newVelocity = (self.velocity * peer);
    return Momentum(self.getMass(), newVelocity);
}

Momentum Momentum::operator/(const Velocity& peer) const {
    Momentum self = *this; Velocity newVelocity = (self.velocity / peer);
    return Momentum(self.getMass(), newVelocity);
}

Momentum Momentum::operator%(const Velocity& peer) const {
    Momentum self = *this; Velocity newVelocity = (self.velocity % peer);
    return Momentum(self.getMass(), newVelocity);
}

std::string Momentum::getName() const {
    return velocity.getName();
}

void Momentum::setName(const std::string name) {
    this->velocity.setName(name);
}

qft::Mass Momentum::getMass() const {
    qft::Mass result = *this;
    return result;
}

void Momentum::setMass(const qft::Mass& mass) {
    qft::Mass::setMagnitude(mass.getMagnitude(), mass.getScaling(), mass.getUnit());
}

shp::Signal Momentum::getCharge() {
    Mass mass = *this; shp::Signal difference = mass.getPotential().getDifference();
    shp::Signal angular = velocity.getAngular(shp::Quantity::DEFAULT_VALUE);
    float magnitude = (((mass.getMagnitude() * angular.getMagnitude()) / difference.getMagnitude()));
    shp::Signal result(magnitude, mass.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE));
    return result;
}

shp::Quantity Momentum::getParticles() const {
    Mass mass = *this; qft::Mass particle(qft::Mass::ELECTRON);
    float quantum = (mass.getMagnitude() / Momentum::getMatterParticles().getMagnitude());
    return shp::Quantity((quantum / particle.getMagnitude()),
        (mass.getScaling() - particle.getScaling()), "m⁻");
}

void Momentum::setParticles(const int count) {
    Mass mass = *this;
    if (count > 0) {
        qft::Mass particle(qft::Mass::ELECTRON);
        float total = (particle.getMagnitude() * count);
        mass.setMagnitude(total); mass.adjustScaling();
    }
}

void Momentum::changeFlowSpeed(const float motion) {
    velocity.setChangeMagnitude(motion);
}

void Momentum::changeFlowSpeed(const float motion, const short int scale) {
    velocity.setChangeMagnitude(motion, scale);
}

void Momentum::changeDirection(const float degree) {
    velocity.setChangeDirection(degree);
}

shp::Signal Momentum::getDifference() const {
    Mass mass = *this;
    shp::Signal result = mass.getPotential().getDifference(); result.setUnit(UNIT);
    return result;
}

shp::Signal Momentum::getPower(const Time& interval) const {
    shp::Signal result = (this->getForce(interval) * this->getVelocity().getTotal());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Momentum::getForce(const Time& interval) const {
    shp::Signal result = (this->getRateOfChange() / interval.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Momentum::getPotential() const {
    Mass mass = *this;      // non-moving material substance only
    mass.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = mass.getPhaseSpace();
    shp::Signal result(flow.getOrientation(), flow.getMagnitude(), flow.getScaling(), flow.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Momentum::getPotential(const shp::Signal& motion) const {
    Mass mass = *this;      // material substance in a moving reference frame
    mass.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = mass.getPhaseConvergence(motion);
    shp::Signal result(flow.getOrientation(), flow.getMagnitude(), flow.getScaling(), flow.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Momentum::getMatterFlow() const {
    Mass mass = *this;      // material substance linearly moving, but non-accelerating
    mass.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = mass.getLinearSpace();
    shp::Signal result(flow.getOrientation(), flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Momentum::getMatterFlow(const shp::Signal& motion) const {
    Mass mass = *this;      // linearly moving material in a non-accelerating reference frame
    mass.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = mass.getLinearConvergence(motion);
    shp::Signal result(flow.getOrientation(), flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Momentum::getGravitation() const {
    Mass mass = *this;      // material body orbiting within a field
    mass.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = mass.getCurvedSpace();
    shp::Signal result(flow.getOrientation(), flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Momentum::getGravitation(const shp::Signal& motion) const {
    Mass mass = *this;      // material body accelerating in a field
    mass.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = mass.getCurvedConvergence(motion);
    shp::Signal result(flow.getOrientation(),
        flow.getMagnitude(), flow.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::ENERGY));
    result.adjustScaling();
    return result;
}

shp::Signal Momentum::getMatterPower() const {
    shp::Signal result = (this->getDifference() * this->getMatterFlow());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Momentum::getMatterKinetic() const {
    Mass mass = *this; shp::Signal momentum = this->getMatterFlow();
    shp::Frequency total = (mass + mass);
    shp::Signal result = ((momentum * momentum) / total.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Momentum::getGravityPower() const {
    shp::Signal result = (this->getDifference() * this->getGravitation());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Momentum::getGravityKinetic() const {
    Mass mass = *this; shp::Signal momentum = this->getGravitation();
    shp::Frequency total = (mass + mass);
    shp::Signal result = ((momentum * momentum) / total.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Momentum::getRateOfChange() const {
    shp::Signal result = (this->getMatterFlow() - this->getGravitation());
    result.adjustScaling();
    return result;
}

std::shared_ptr<Field> Momentum::getMatterField() const {
    Mass mass = *this;
    return mass.getOriginField();
}

std::shared_ptr<Field> Momentum::getGravityField() const {
    Mass mass = *this;
    std::shared_ptr<Field> field = Field::shareable(Momentum::GRAVITY_FIELD);
    shp::Signal motion = this->getRateOfChange();
    if (motion.checkNonZero()) {
        field->setPotential(shp::Potential(motion.getMagnitude(),
            shp::Quantity::DEFAULT_VALUE, motion.getScaling(), mass.getUnit(),
            shp::Angular(Energy::getPlanckLength())));
    } else {
        field->setPotential(shp::Potential(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, mass.getScaling(), mass.getUnit(),
            shp::Angular(Energy::getPlanckLength())));
    }
    shp::Direction orientation = velocity.getDirection().getNormal();
    field->setLinear(orientation);
    return field;
}

bool Momentum::checkNonZero() const {
    Mass mass = *this;
    return (mass.checkNonZero() && velocity.checkNonZero());
}

shp::Signal Momentum::copy() const {
    Mass mass = *this;
    Momentum fresh = Momentum(mass, velocity);
    return fresh.getTotal();
}

void Momentum::clear() {
    Mass::clear();
    velocity.clear();
    return;
}

std::string Momentum::print() const {
    std::stringstream result;
    result << "Π{";
    result << Mass::print() << ",";
    result << velocity.print();
    result << UNIT << "}";
	return result.str();
}

std::string Momentum::printRadians() const {
    std::stringstream result;
    result << "Π{";
    result << Mass::printRadians() << ",";
    result << velocity.printRadians();
    result << UNIT << "}";
	return result.str();
}

shp::Signal Momentum::getCosComponent(const float phase) const {
	shp::Signal momentum = this->getMatterFlow();
	return shp::Signal(momentum.getOrientation(), (momentum.getCosComponent(phase)),
        momentum.getScaling(), momentum.getUnit());
}

shp::Signal Momentum::getSinComponent(const float phase) const {
	shp::Signal momentum = this->getMatterFlow();
	return shp::Signal(momentum.getOrientation(), (momentum.getSinComponent(phase)),
        momentum.getScaling(), momentum.getUnit());
}

const Momentum Momentum::getOrbiting(const Momentum unitary, const float multiplier) {
    if (multiplier > 0) {
        Momentum fresh = unitary;
        fresh.setParticles(multiplier);
        return fresh;
    }
    return unitary;
}

const shp::Quantity Momentum::getMatterParticles() {
    shp::Quantity flowrate = getMatterFlowRate();
    qft::Mass particle_mass(-qft::Mass::ELECTRON);
    shp::Quantity total = (flowrate * particle_mass.getMagnitude()); total.adjustScaling();
    return total;
}

const shp::Quantity Momentum::getMatterFlowRate() {
    shp::Quantity standard(ELECTRON_FLOW_RATE, ELECTRON_FLOW_SCALE, KILOGRAM_SECOND);
    return standard;
}

} // namespace qft