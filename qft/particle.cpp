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
    setPhysical(nullptr);
}

Particle::Particle(const float spin)
        : Wave(), isospin(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(const Spin& spin)
        : Wave(), isospin(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name)
        : Wave(name), isospin(), spin(), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const float spin)
        : Wave(name), isospin(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Spin& spin)
        : Wave(name), isospin(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(const Energy& energy)
        : Wave(), isospin(), spin(), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Energy& energy)
        : Wave(name), isospin(), spin(), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(const Spin& spin, const Energy& energy)
        : Wave(), isospin(), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const float spin, const float energy)
        : Wave(name), isospin(), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Spin& spin, const Energy& energy)
        : Wave(name), isospin(), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Isospin& isospin, const Spin& spin, const Energy& energy)
        : Wave(name), isospin(isospin), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(const Mass& mass, const Charge& charge)
        : Wave(), isospin(), spin(), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Mass& mass, const Charge& charge)
        : Wave(name), isospin(), spin(), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(), isospin(), spin(spin), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const float spin,
        const float mass, const float charge)
        : Wave(name), isospin(), spin(spin), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Spin& spin,
        const Mass& mass, const Charge& charge)
        : Wave(name), isospin(), spin(spin), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(shp::Shape* description)
        : Wave(), isospin(), spin(), energy() {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description)
        : Wave(name), isospin(), spin(), energy() {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Spin& spin)
        : Wave(name), isospin(), spin(spin), energy() {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Spin& spin, const Energy& energy)
        : Wave(name), isospin(), spin(spin), energy(energy) {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Isospin& isospin, const Spin& spin, const Energy& energy)
        : Wave(name), isospin(isospin), spin(spin), energy(energy) {
    setPhysical(description);
}

Particle::Particle(shp::Shape* description,
        const Spin& spin, const Energy& energy)
        : Wave(), isospin(), spin(spin), energy(energy) {
    setPhysical(description);
}

Particle::Particle(shp::Shape* description,
        const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(), isospin(), spin(spin), energy(mass, charge) {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(name), isospin(), spin(spin), energy(mass, charge) {
    setPhysical(description);
}

Particle::~Particle() {
    setPhysical(nullptr);
}

bool Particle::operator==(const Particle& peer) const {
    return (static_cast<const Wave&>(*this) == static_cast<const Wave&>(peer))
        && (physical == peer.physical)
        && (isospin == peer.isospin) && (spin == peer.spin)
        && (energy == peer.energy);
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

shp::Quantity Particle::getTotal() const {
    return energy.getTotal();
}

shp::Quantity Particle::getFrequency() const {
    return energy.getWavelength().getInverse();
}

shp::Quantity Particle::getWavelength() const {
    return energy.getWavelength().getMagnitude();
}

bool Particle::isStructured() const {
    return physical != nullptr;
}

shp::Distance Particle::getRadius() const {
    return energy.getRadius().getMagnitude();
}

void Particle::setRadius(const shp::Distance& length) {
    energy.setRadius(length);
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

shp::Point Particle::copy() {
    Particle fresh(getName(), physical, isospin, spin, energy);
    return fresh;
}

void Particle::clear() {
    Wave::clear();
    setPhysical(nullptr);
    isospin.clear();
    spin.clear();
    energy.clear();
    return;
}

std::string Particle::print() {
    std::stringstream result;
    result << "[";
    result << Wave::print() << ",";
    result << energy.print() << ",";
    result << isospin.print() << ",";
    result << spin.print() << ",";
    result << (physical != nullptr ? physical->print() : "");
    result << "]";
	return result.str();
}

shp::Quantity Particle::getComponent(float phase) const {
	shp::Quantity energy = getTotal();
	return shp::Quantity((energy.getMagnitude() * cos(phase)), energy.getScaling(), energy.getUnit());
}

} // namespace qft
