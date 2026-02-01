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

#include "heat.h"
#include "field.h"

namespace qft {

const std::string Heat::UNIT = "J";                     // System International (i.e. K/s)
const std::string Heat::KELVIN_SECOND = "K/s";          // Kelvin per second
const std::string Heat::THERMAL_FIELD = "Thermal";      // Thermal Field
const std::string Heat::DIFFUSION_FIELD = "Diffusion";  // Diffusion Field
const float Heat::QGP_FLOW_RATE = 6.241509f;            // 6.241509x10^18 Kelvin per second
const short int Heat::QGP_FLOW_SCALE = 18;              // 10^18

Heat::Heat()
        : qft::Temperature(), velocity() {

}

Heat::Heat(const std::string name)
        : qft::Temperature(), velocity(name) {

}

Heat::Heat(const qft::Temperature& temperature)
        : qft::Temperature(temperature.getMagnitude(), temperature.getScaling(),
            temperature.getUnit(), temperature.getField()),
        velocity() {

}

Heat::Heat(const float temperature)
        : qft::Temperature(temperature), velocity() {

}

Heat::Heat(const float temperature, const std::string unit)
        : qft::Temperature(temperature, unit), velocity() {

}

Heat::Heat(const float temperature, const shp::Unit& unit)
        : qft::Temperature(temperature, unit), velocity() {

}

Heat::Heat(const float temperature, const short int scaling)
        : qft::Temperature(temperature, scaling), velocity() {

}

Heat::Heat(const float temperature, const short int scaling, const std::string unit)
        : qft::Temperature(temperature, scaling, unit), velocity() {

}

Heat::Heat(const float temperature, const short int scaling, const shp::Unit& unit)
        : qft::Temperature(temperature, scaling, unit), velocity() {

}

Heat::Heat(const qft::Velocity& velocity)
        : qft::Temperature(), velocity(velocity) {

}

Heat::Heat(const std::string name, const qft::Temperature& temperature)
        : qft::Temperature(temperature), velocity(name) {

}

Heat::Heat(const std::string name, const float temperature)
        : qft::Temperature(temperature), velocity(name) {

}

Heat::Heat(const std::string name, const float temperature, const std::string unit)
        : qft::Temperature(temperature, unit), velocity(name) {

}

Heat::Heat(const std::string name, const float temperature, const shp::Unit& unit)
        : qft::Temperature(temperature, unit), velocity(name) {

}

Heat::Heat(const std::string name, const float temperature, const short int scaling)
        : qft::Temperature(temperature, scaling), velocity(name) {

}

Heat::Heat(const std::string name, const float temperature, const short int scaling, const std::string unit)
        : qft::Temperature(temperature, scaling, unit), velocity(name) {

}

Heat::Heat(const std::string name, const float temperature, const short int scaling, const shp::Unit& unit)
        : qft::Temperature(temperature, scaling, unit), velocity(name) {

}

Heat::Heat(const qft::Temperature& temperature, const qft::Velocity& velocity)
        : qft::Temperature(temperature.getMagnitude(), temperature.getScaling(),
            temperature.getUnit(), temperature.getField()),
        velocity(velocity) {

}

Heat::Heat(const float temperature, const float velocity)
        : qft::Temperature(temperature), velocity(velocity) {

}

Heat::Heat(const std::string name, const float temperature, const float velocity)
        : qft::Temperature(temperature), velocity(name, velocity) {

}

Heat::~Heat() {

}

bool Heat::operator==(const Heat& peer) const {
    return (static_cast<const qft::Temperature&>(*this) == static_cast<const qft::Temperature&>(peer))
        && (velocity == peer.velocity);
}

bool Heat::operator<(const Heat& peer) const {
    Heat self = *this; bool result = false;
    if (static_cast<const qft::Temperature&>(*this) < static_cast<const qft::Temperature&>(peer)) {
        result = true;
    } else if (self.velocity < peer.velocity) {
        result = true;
    }
    return result;
}

bool Heat::operator>(const Heat& peer) const {
    Heat self = *this; bool result = false;
    if (static_cast<const qft::Temperature&>(*this) > static_cast<const qft::Temperature&>(peer)) {
        result = true;
    } else if (self.velocity > peer.velocity) {
        result = true;
    }
    return result;
}

bool Heat::operator<=(const Heat& peer) const {
    Heat self = *this;
    return (self < peer) || (self == peer);
}

bool Heat::operator>=(const Heat& peer) const {
    Heat self = *this;
    return (self > peer) || (self == peer);
}

Heat Heat::operator+(const Heat& peer) const {
    Temperature self = *this, other = peer, newTemperature = (self + other);
    Velocity newVelocity = (this->velocity + peer.velocity);
    return Heat(newTemperature, newVelocity);
}

Heat Heat::operator-(const Heat& peer) const {
    Temperature self = *this, other = peer, newTemperature = (self - other);
    Velocity newVelocity = (this->velocity - peer.velocity);
    return Heat(newTemperature, newVelocity);
}

Heat Heat::operator*(const Heat& peer) const {
    Temperature self = *this, other = peer, newTemperature = (self * other);
    Velocity newVelocity = (this->velocity * peer.velocity);
    return Heat(newTemperature, newVelocity);
}

Heat Heat::operator/(const Heat& peer) const {
    Temperature self = *this, other = peer, newTemperature = (self / other);
    Velocity newVelocity = (this->velocity / peer.velocity);
    return Heat(newTemperature, newVelocity);
}

Heat Heat::operator%(const Heat& peer) const {
    Temperature self = *this, other = peer, newTemperature = (self % other);
    Velocity newVelocity = (this->velocity % peer.velocity);
    return Heat(newTemperature, newVelocity);
}

Heat Heat::operator+(const Temperature& peer) const {
    Temperature self = *this, newTemperature = (self + peer);
    return Heat(newTemperature, this->velocity);
}

Heat Heat::operator-(const Temperature& peer) const {
    Temperature self = *this, newTemperature = (self - peer);
    return Heat(newTemperature, this->velocity);
}

Heat Heat::operator*(const Temperature& peer) const {
    Temperature self = *this, newTemperature = (self * peer);
    return Heat(newTemperature, this->velocity);
}

Heat Heat::operator/(const Temperature& peer) const {
    Temperature self = *this, newTemperature = (self / peer);
    return Heat(newTemperature, this->velocity);
}

Heat Heat::operator%(const Temperature& peer) const {
    Temperature self = *this, newTemperature = (self % peer);
    return Heat(newTemperature, this->velocity);
}

Heat Heat::operator+(const Velocity& peer) const {
    Heat self = *this; Velocity newVelocity = (self.velocity + peer);
    return Heat(self.getTemperature(), newVelocity);
}

Heat Heat::operator-(const Velocity& peer) const {
    Heat self = *this; Velocity newVelocity = (self.velocity - peer);
    return Heat(self.getTemperature(), newVelocity);
}

Heat Heat::operator*(const Velocity& peer) const {
    Heat self = *this; Velocity newVelocity = (self.velocity * peer);
    return Heat(self.getTemperature(), newVelocity);
}

Heat Heat::operator/(const Velocity& peer) const {
    Heat self = *this; Velocity newVelocity = (self.velocity / peer);
    return Heat(self.getTemperature(), newVelocity);
}

Heat Heat::operator%(const Velocity& peer) const {
    Heat self = *this; Velocity newVelocity = (self.velocity % peer);
    return Heat(self.getTemperature(), newVelocity);
}

std::string Heat::getName() const {
    return velocity.getName();
}

void Heat::setName(const std::string name) {
    this->velocity.setName(name);
}

qft::Temperature Heat::getTemperature() const {
    qft::Temperature result = *this;
    return result;
}

void Heat::setTemperature(const qft::Temperature& temperature) {
    Temperature::setMagnitude(temperature.getMagnitude(), temperature.getScaling(), temperature.getUnit());
}

shp::Quantity Heat::getMass() {
    Temperature temperature = *this; shp::Signal difference = temperature.getPotential().getDifference();
    shp::Signal angular = velocity.getAngular(shp::Quantity::DEFAULT_VALUE);
    float magnitude = ((difference.getMagnitude() / angular.getMagnitude()) * temperature.getMagnitude());
    shp::Quantity result(magnitude, temperature.getScaling(), shp::Unit::getBaseSymbol(shp::Unit::MASS));
    return result;
}

shp::Quantity Heat::getParticles() const {
    Temperature temperature = *this; qft::Temperature particle(qft::Temperature::QGP);
    float quantum = (temperature.getMagnitude() / Heat::getPlasmaKelvins().getMagnitude());
    return shp::Quantity((quantum / particle.getMagnitude()),
        (temperature.getScaling() - particle.getScaling()), "e⁻");
}

void Heat::setParticles(const int count) {
    Temperature temperature = *this;
    if (count > 0) {
        qft::Temperature particle(qft::Temperature::QGP);
        float total = (particle.getMagnitude() * count);
        temperature.setMagnitude(total); temperature.adjustScaling();
    }
}

void Heat::changeFlowSpeed(const float motion) {
    velocity.setChangeMagnitude(motion);
}

void Heat::changeFlowSpeed(const float motion, const short int scale) {
    velocity.setChangeMagnitude(motion, scale);
}

void Heat::changeDirection(const float degree) {
    velocity.setChangeDirection(degree);
}

shp::Signal Heat::getDifference() const {
    Temperature temperature = *this;
    shp::Signal result = temperature.getPotential().getDifference();
    result.setUnit(shp::Unit::getBaseSymbol(shp::Unit::TEMPERATURE));
    return result;
}

shp::Signal Heat::getPower(const Time& interval) const {
    shp::Signal result = (this->getForce(interval) * this->getVelocity().getTotal());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Heat::getForce(const Time& interval) const {
    shp::Signal result = (this->getRateOfChange() / interval.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Heat::getPotential() const {
    Temperature temperature = *this;      // non-moving temperature only
    temperature.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = temperature.getPhaseSpace();
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), flow.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Heat::getPotential(const shp::Signal& motion) const {
    Temperature temperature = *this;      // electric temperature in a moving reference frame
    temperature.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = temperature.getPhaseConvergence(motion);
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), flow.getUnit());
    result.adjustScaling();
    return result;
}

shp::Signal Heat::getThermalFlow() const {
    Temperature temperature = *this;      // temperature linearly moving, but non-accelerating
    temperature.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = temperature.getLinearSpace();
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Heat::getThermalFlow(const shp::Signal& motion) const {
    Temperature temperature = *this;      // linearly moving electric temperature in non-accelerating conductor
    temperature.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = temperature.getLinearConvergence(motion);
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Heat::getDiffusivity() const {
    Temperature temperature = *this;      // loop temperature within a field
    temperature.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = temperature.getCurvedSpace();
    shp::Signal result(flow.getOrientation(), -flow.getMagnitude(), flow.getScaling(), UNIT);
    result.adjustScaling();
    return result;
}

shp::Signal Heat::getDiffusivity(const shp::Signal& motion) const {
    Temperature temperature = *this;      // loop temperature carrying body moving in a field
    temperature.setSpatialDrift(velocity.getDisplacement().getAmplitude(), velocity.getScaling(), velocity.getDirection());
    shp::Signal flow = temperature.getCurvedConvergence(motion);
    shp::Signal result(flow.getOrientation(),
        -flow.getMagnitude(), flow.getScaling(), shp::Unit::getDerivedSymbol(shp::Unit::ENERGY));
    result.adjustScaling();
    return result;
}

shp::Signal Heat::getThermalPower() const {
    shp::Signal result = (this->getDifference() * this->getThermalFlow());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Heat::getThermalKinetic() const {
    Temperature temperature = *this; shp::Signal current = getThermalFlow();
    shp::Temporal total = (temperature + temperature);
    shp::Signal result = ((current * current) / total.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Heat::getDiffusionPower() const {
    shp::Signal result = (this->getDifference() * this->getDiffusivity());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::POWER));
    return result;
}

shp::Signal Heat::getDiffusionKinetic() const {
    Temperature temperature = *this; shp::Signal current = getDiffusivity();
    shp::Temporal total = (temperature + temperature);
    shp::Signal result = ((current * current) / total.getMagnitude());
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FORCE));
    return result;
}

shp::Signal Heat::getRateOfChange() const {
    shp::Signal result = (this->getThermalFlow() - this->getDiffusivity());
    result.adjustScaling();
    return result;
}

std::shared_ptr<Field> Heat::getThermalField() const {
    Temperature temperature = *this;
    return temperature.getOriginField();
}

std::shared_ptr<Field> Heat::getDiffusionField() const {
    Temperature temperature = *this;
    std::shared_ptr<Field> field = Field::shareable(Heat::DIFFUSION_FIELD, getMagnitude(), getScaling());
    shp::Signal motion = getRateOfChange();
    if (motion.checkNonZero()) {
        field->setPotential(shp::Potential(motion.getMagnitude(),
            shp::Quantity::DEFAULT_VALUE, motion.getScaling(), temperature.getUnit(),
            shp::Angular(Energy::getPlanckLength())));
    } else {
        field->setPotential(shp::Potential(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, temperature.getScaling(), temperature.getUnit(),
            shp::Angular(Energy::getPlanckLength())));
    }
    shp::Direction orientation = velocity.getDirection().getNormal();
    field->setLinear(orientation);
    return field;
}

bool Heat::checkNonZero() const {
    Temperature temperature = *this;
    return (temperature.checkNonZero() && velocity.checkNonZero());
}

shp::Signal Heat::copy() const {
    Temperature temperature = *this;
    Heat fresh = Heat(temperature, velocity);
    return fresh.getTotal();
}

void Heat::clear() {
    Temperature::clear();
    velocity.clear();
    return;
}

std::string Heat::print() const {
    std::stringstream result;
    result << "Q:";
    result << Temperature::print() << ",";
    result << velocity.print();
    result << UNIT;
	return result.str();
}

std::string Heat::printRadians() const {
    std::stringstream result;
    result << "Q:";
    result << Temperature::printRadians() << ",";
    result << velocity.printRadians();
    result << UNIT;
	return result.str();
}

shp::Signal Heat::getCosComponent(const float phase) const {
	shp::Signal flow = this->getThermalFlow();
	return shp::Signal(flow.getOrientation(), (flow.getCosComponent(phase)),
        flow.getScaling(), flow.getUnit());
}

shp::Signal Heat::getSinComponent(const float phase) const {
	shp::Signal flow = this->getThermalFlow();
	return shp::Signal(flow.getOrientation(), (flow.getSinComponent(phase)),
        flow.getScaling(), flow.getUnit());
}

const Heat Heat::getLooping(const Heat unitary, const float multiplier) {
    if (multiplier > 0) {
        Heat fresh = unitary;
        fresh.setParticles(multiplier);
        return fresh;
    }
    return unitary;
}

const shp::Quantity Heat::getPlasmaKelvins() {
    shp::Quantity flowrate = getPlasmaFlowRate();
    qft::Temperature body(-qft::Temperature::QGP);
    shp::Quantity total = (flowrate * body.getMagnitude()); total.adjustScaling();
    return total;
}

const shp::Quantity Heat::getPlasmaFlowRate() {
    shp::Quantity standard(QGP_FLOW_RATE, QGP_FLOW_SCALE, KELVIN_SECOND);
    return standard;
}

} // namespace qft