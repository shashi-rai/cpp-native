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

#include "particle.h"

namespace qft {

Particle::Particle()
        : Wave(), isospin(), spin(), energy() {

}


Particle::Particle(const std::string name)
        : Wave(name), isospin(), spin(), energy() {

}

Particle::Particle(const float spin)
        : Wave(), isospin(), spin(spin), energy() {

}

Particle::Particle(const Spin& spin)
        : Wave(), isospin(), spin(spin), energy() {

}

Particle::Particle(const std::string name, const float spin)
        : Wave(name), isospin(), spin(spin), energy() {

}

Particle::Particle(const std::string name, const Spin& spin)
        : Wave(name), isospin(), spin(spin), energy() {

}

Particle::Particle(const Isospin& isospin)
        : Wave(), isospin(isospin), spin(), energy() {

}

Particle::Particle(const std::string name, const Isospin& isospin)
        : Wave(name), isospin(isospin), spin(), energy() {

}

Particle::Particle(const std::string name, const Isospin& isospin, const Spin& spin)
        : Wave(name), isospin(isospin), spin(spin), energy() {

}

Particle::Particle(const Energy& energy)
        : Wave(), isospin(), spin(), energy(energy) {

}

Particle::Particle(const std::string name, const Energy& energy)
        : Wave(name), isospin(), spin(), energy(energy) {

}

Particle::Particle(const Spin& spin, const Energy& energy)
        : Wave(), isospin(), spin(spin), energy(energy) {

}

Particle::Particle(const std::string name, const float spin, const float energy)
        : Wave(name), isospin(), spin(spin), energy(energy) {

}

Particle::Particle(const std::string name, const Spin& spin, const Energy& energy)
        : Wave(name), isospin(), spin(spin), energy(energy) {

}

Particle::Particle(const Isospin& isospin, const Energy& energy)
        : Wave(), isospin(isospin), spin(), energy(energy) {

}

Particle::Particle(const std::string name, const Isospin& isospin, const Energy& energy)
        : Wave(name), isospin(isospin), spin(), energy(energy) {

}

Particle::Particle(const Isospin& isospin, const Spin& spin, const Energy& energy)
        : Wave(), isospin(isospin), spin(spin), energy(energy) {

}

Particle::Particle(const std::string name, const Isospin& isospin, const Spin& spin, const Energy& energy)
        : Wave(name), isospin(isospin), spin(spin), energy(energy) {

}

Particle::Particle(const Mass& mass, const Charge& charge)
        : Wave(), isospin(), spin(), energy(Mass(mass), Charge(charge)) {

}

Particle::Particle(const std::string name, const Mass& mass, const Charge& charge)
        : Wave(name), isospin(), spin(), energy(Mass(mass), Charge(charge)) {

}

Particle::Particle(const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(), isospin(), spin(spin), energy(Mass(mass), Charge(charge)) {

}

Particle::Particle(const std::string name, const float spin,
        const float mass, const float charge)
        : Wave(name), isospin(), spin(spin), energy(Mass(mass), Charge(charge)) {

}

Particle::Particle(const std::string name, const Spin& spin,
        const Mass& mass, const Charge& charge)
        : Wave(name), isospin(), spin(spin), energy(Mass(mass), Charge(charge)) {

}

Particle::Particle(const std::string name, const Isospin& isospin,
        const Mass& mass, const Charge& charge)
        : Wave(name), isospin(isospin), spin(), energy(Mass(mass), Charge(charge)) {

}

Particle::Particle(const std::string name, const Isospin& isospin, const Spin& spin,
        const Mass& mass, const Charge& charge)
        : Wave(name), isospin(isospin), spin(spin), energy(Mass(mass), Charge(charge)) {

}

Particle::~Particle() {

}

bool Particle::operator==(const Particle& peer) const {
    return (static_cast<const Wave&>(*this) == static_cast<const Wave&>(peer))
        && (energy == peer.energy) && (isospin == peer.isospin) && (spin == peer.spin);
}

bool Particle::operator<(const Particle& peer) const {
    return (static_cast<const Wave&>(*this) < static_cast<const Wave&>(peer))
        && (energy < peer.energy);
}

bool Particle::operator>(const Particle& peer) const {
    return (static_cast<const Wave&>(*this) > static_cast<const Wave&>(peer))
        && (energy > peer.energy);
}

bool Particle::operator<=(const Particle& peer) const {
    Particle self = *this;
    return (self < peer) || (self == peer);
}

bool Particle::operator>=(const Particle& peer) const {
    Particle self = *this;
    return (self > peer) || (self == peer);
}

Particle Particle::operator+(const Particle& peer) const {
    Isospin newisospin = (isospin + peer.isospin);
    Spin newspin = (spin + peer.spin);
    Energy newenergy = (energy + peer.energy);
    return Particle("+", newisospin, newspin, newenergy);
}

Particle Particle::operator-(const Particle& peer) const {
    Isospin newisospin = (isospin - peer.isospin);
    Spin newspin = (spin - peer.spin);
    Energy newenergy = (energy - peer.energy);
    return Particle("-", newisospin, newspin, newenergy);
}

Particle Particle::operator*(const Particle& peer) const {
    Isospin newisospin = (isospin * peer.isospin);
    Spin newspin = (spin * peer.spin);
    Energy newenergy = (energy * peer.energy);
    return Particle("*", newisospin, newspin, newenergy);
}

Particle Particle::operator/(const Particle& peer) const {
    Isospin newisospin = (isospin / peer.isospin);
    Spin newspin = (spin / peer.spin);
    Energy newenergy = (energy / peer.energy);
    return Particle("/", newisospin, newspin, newenergy);
}

Particle Particle::operator%(const Particle& peer) const {
    Isospin newisospin = (isospin % peer.isospin);
    Spin newspin = (spin % peer.spin);
    Energy newenergy = (energy % peer.energy);
    return Particle("%", newisospin, newspin, newenergy);
}

Mass Particle::getMass() const {
    return energy.getMass();
}

void Particle::setMass(const Mass& value) {
    energy.setMass(value);
}

Charge Particle::getCharge() const {
    return energy.getCharge();
}

void Particle::setCharge(const Charge& value) {
    energy.setCharge(value);
}

Temperature Particle::getTemperature() const {
    return energy.getTemperature();
}

void Particle::setTemperature(const Temperature& value) {
    energy.setTemperature(value);
}

shp::Signal Particle::getFrequency() const {
    return energy.getWavelength().getScalarInverse();
}

shp::Signal Particle::getWavelength() const {
    return energy.getWavelength().getMagnitude();
}

shp::Distance Particle::getMassFieldRadius() const {
    return energy.getMassFieldRadius();
}

void Particle::setMassFieldRadius(const shp::Distance& radius) {
    energy.setMassFieldChange(radius);
}

void Particle::setMassFluxChange(const shp::Azimuth& shift) {
    energy.setMassFluxChange(shift);
}

void Particle::setMassFlowChange(const shp::Signal& motion) {
    energy.setMassFlowChange(motion);
}

shp::Distance Particle::getChargeFieldRadius() const {
    return energy.getChargeFieldRadius();
}

void Particle::setChargeFieldRadius(const shp::Distance& radius) {
    energy.setChargeFieldChange(radius);
}

void Particle::setChargeFluxChange(const shp::Azimuth& shift) {
    energy.setChargeFluxChange(shift);
}

void Particle::setChargeFlowChange(const shp::Signal& motion) {
    energy.setChargeFlowChange(motion);
}

shp::Distance Particle::getThermalFieldRadius() const {
    return energy.getThermalFieldRadius();
}

void Particle::setThermalFieldRadius(const shp::Distance& radius) {
    energy.setThermalFieldChange(radius);
}

void Particle::setThermalFluxChange(const shp::Azimuth& shift) {
    energy.setThermalFluxChange(shift);
}

void Particle::setThermalFlowChange(const shp::Signal& motion) {
    energy.setThermalFlowChange(motion);
}

std::shared_ptr<Field> Particle::getMassField() const {
    return energy.getMassField();
}

void Particle::setMassField(const std::shared_ptr<Field> field) {
    energy.setMassField(field);
}

std::shared_ptr<Field> Particle::getChargeField() const {
    return energy.getChargeField();
}

void Particle::setChargeField(const std::shared_ptr<Field> field) {
    energy.setChargeField(field);
}

std::shared_ptr<Field> Particle::getThermalField() const {
    return energy.getThermalField();
}

void Particle::setThermalField(const std::shared_ptr<Field> field) {
    energy.setThermalField(field);
}

shp::Signal Particle::getTotal() const {
    return energy.getTotal();
}

shp::Point Particle::copy() {
    Particle fresh(shp::Wave::getName(), this->isospin, this->spin, this->energy);
    return fresh;
}

void Particle::clear() {
    Wave::clear();
    isospin.clear();
    spin.clear();
    energy.clear();
    return;
}

std::string Particle::print() const {
    std::stringstream result;
    result << "[";
    result << Wave::print() << ",";
    result << energy.print() << ",";
    result << isospin.print() << ",";
    result << spin.print();
    result << "]";
	return result.str();
}

std::string Particle::printRadians() const {
    std::stringstream result;
    result << "[";
    result << Wave::printRadians() << ",";
    result << energy.printRadians() << ",";
    result << isospin.print() << ",";
    result << spin.print();
    result << "]";
	return result.str();
}

shp::Signal Particle::getCosComponent(const float phase) const {
	shp::Signal energy = this->getTotal();
	return shp::Signal(energy.getCosComponent(phase), energy.getScaling(), energy.getUnit());
}

shp::Signal Particle::getSinComponent(const float phase) const {
	shp::Signal energy = this->getTotal();
	return shp::Signal(energy.getSinComponent(phase), energy.getScaling(), energy.getUnit());
}

} // namespace qft
