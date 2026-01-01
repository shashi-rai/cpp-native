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
const std::string Momentum::GRAVITY_FIELD = "Gravity";  // Gravity Field

Momentum::Momentum()
        : name(), mass(), velocity() {

}

Momentum::Momentum(std::string name)
        : name(name), mass(), velocity() {

}

Momentum::Momentum(const qft::Mass& mass)
        : name(), mass(mass), velocity() {

}

Momentum::Momentum(std::string name, const qft::Mass& mass)
        : name(name), mass(mass), velocity() {

}

Momentum::Momentum(const float mass, const float velocity)
        : name(), mass(mass), velocity(velocity) {

}

Momentum::Momentum(const qft::Mass& mass, const qft::Acceleration& velocity)
        : name(), mass(mass), velocity(velocity) {

}

Momentum::Momentum(std::string name, const float mass, const float velocity)
        : name(name), mass(mass), velocity(velocity) {

}

Momentum::Momentum(std::string name, const qft::Mass& mass, const qft::Acceleration& velocity)
        : name(name), mass(mass), velocity(velocity) {

}

Momentum::~Momentum() {

}

bool Momentum::operator==(const Momentum& peer) const {
    return (mass == peer.mass) && (velocity == peer.velocity);
}

Momentum Momentum::operator+(const Momentum& peer) const {
    return Momentum("+", (mass + peer.mass), (velocity + peer.velocity));
}

Momentum Momentum::operator-(const Momentum& peer) const {
    return Momentum("-", (mass - peer.mass), (velocity - peer.velocity));
}

Momentum Momentum::operator*(const Momentum& peer) const {
    return Momentum("*", (mass * peer.mass), (velocity * peer.velocity));
}

Momentum Momentum::operator/(const Momentum& peer) const {
    return Momentum("/", (mass / peer.mass), (velocity / peer.velocity));
}

shp::Quantity Momentum::getCharge() {
    shp::Quantity difference = mass.getPotential().getDifference();
    shp::Quantity angular = velocity.getAngular(shp::Quantity::DEFAULT_VALUE);
    float magnitude = (((mass.getMagnitude() * angular.getMagnitude()) / difference.getMagnitude()));
    shp::Quantity result(magnitude, mass.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_CHARGE));
    return result;
}

Acceleration Momentum::getAcceleration() const {
    return velocity;
}

void Momentum::applyChangeTogether() {
    applyChangeFlowSpeed();
    applyChangeDirection();
}

void Momentum::changeFlowSpeed(const float motion) {
    velocity.setChangeMagnitude(motion);
}

void Momentum::applyChangeFlowSpeed() {
    velocity.applyChangeMagnitude();
}

void Momentum::changeDirection(const float degree) {
    velocity.setChangeDirection(degree);
}

void Momentum::applyChangeDirection() {
    velocity.applyChangeDirection();
}

shp::Quantity Momentum::getPower(const Time& interval) const {
    shp::Quantity result = (getForce(interval) * getVelocity().getTotal());
    return result;
}

shp::Quantity Momentum::getForce(const Time& interval) const {
    shp::Quantity result = (getRateOfChange() / interval.getMagnitude());
    return result;
}

shp::Quantity Momentum::getLinearTotal() const {
    qft::Velocity invariant = velocity;     // non-accelerating component only
    float momentum = mass.getMagnitude() * invariant.getTotal().getMagnitude();
    short int scaling = mass.getScaling() + invariant.getTotal().getScaling();
    shp::Quantity result(momentum, scaling, UNIT);
    return result;
}

shp::Quantity Momentum::getLinearKinetic() const {
    shp::Quantity momentum = getLinearTotal();
    shp::Quantity result = ((momentum * momentum) / (mass + mass));
    return result;
}

shp::Quantity Momentum::getAngularTotal() const {   // directional acceleration
    float momentum = mass.getMagnitude() * velocity.getTotal().getMagnitude();
    short int scaling = mass.getScaling() + velocity.getTotal().getScaling();
    shp::Quantity result(momentum, scaling, UNIT);
    return result;
}

shp::Quantity Momentum::getAngularKinetic() const {
    shp::Quantity momentum = getAngularTotal();
    shp::Quantity result = ((momentum * momentum) / (mass + mass));
    return result;
}

shp::Quantity Momentum::getRateOfChange() const {
    shp::Quantity result = (getLinearTotal() - getAngularTotal());
    result.adjustScaling();
    return result;
}

std::shared_ptr<Field> Momentum::getMatterField() const {
    return mass.getOriginField();
}

std::shared_ptr<Field> Momentum::getGravityField() const {
    std::shared_ptr<Field> field = Field::shareable(Momentum::GRAVITY_FIELD);
    shp::Quantity motion = getRateOfChange();
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

Momentum Momentum::copy() {
    Momentum fresh(name, mass, velocity);
    return fresh;
}

void Momentum::clear() {
    name.clear();
    mass.clear();
    velocity.clear();
    return;
}

std::string Momentum::print() {
    std::stringstream result;
    result << "Π:";
    result << name << ",";
    result << mass.print() << ",";
    result << velocity.print();
    result << UNIT;
	return result.str();
}

shp::Quantity Momentum::getComponent(float phase) const {
	shp::Quantity momentum = getLinearTotal();
	return shp::Quantity((momentum.getMagnitude() * cos(phase)),
        momentum.getScaling(), momentum.getUnit());
}

} // namespace qft