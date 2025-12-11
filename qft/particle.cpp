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
        : Wave(), spin(), energy() {
    setPhysical(nullptr);
}

Particle::Particle(const float spin)
        : Wave(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(const Spin& spin)
        : Wave(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name)
        : Wave(name), spin(), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const float spin)
        : Wave(name), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Spin& spin)
        : Wave(name), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(const Energy& energy)
        : Wave(), spin(), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Energy& energy)
        : Wave(name), spin(), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(const Spin& spin, const Energy& energy)
        : Wave(), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const float spin, const float energy)
        : Wave(name), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Spin& spin, const Energy& energy)
        : Wave(name), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(const Mass& mass, const Charge& charge)
        : Wave(), spin(), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Mass& mass, const Charge& charge)
        : Wave(name), spin(), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(), spin(spin), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const float spin,
        const float mass, const float charge)
        : Wave(name), spin(spin), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, const Spin& spin,
        const Mass& mass, const Charge& charge)
        : Wave(name), spin(spin), energy(Mass(mass), Charge(charge)) {
    setPhysical(nullptr);
}

Particle::Particle(shp::Shape* description)
        : Wave(), spin(), energy() {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description)
        : Wave(name), spin(), energy() {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Spin& spin)
        : Wave(name), spin(spin), energy() {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Spin& spin, const Energy& energy)
        : Wave(name), spin(spin), energy(energy) {
    setPhysical(description);
}

Particle::Particle(shp::Shape* description,
        const Spin& spin, const Energy& energy)
        : Wave(), spin(spin), energy(energy) {
    setPhysical(description);
}

Particle::Particle(shp::Shape* description,
        const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(), spin(spin), energy(mass, charge) {
    setPhysical(description);
}

Particle::Particle(std::string name, shp::Shape* description,
        const Spin& spin, const Mass& mass, const Charge& charge)
        : Wave(name), spin(spin), energy(mass, charge) {
    setPhysical(description);
}

Particle::~Particle() {
    setPhysical(nullptr);
}

bool Particle::operator==(const Particle& peer) const {
    return (static_cast<const Wave&>(*this) == static_cast<const Wave&>(peer))
        && (physical == peer.physical)
        && (spin == peer.spin)
        && (energy == peer.energy);
}

Particle Particle::operator+(const Particle& peer) const {
    Spin newspin = (spin + peer.spin);
    Energy newenergy = (energy + peer.energy);
    return Particle("+", newspin, newenergy);
}

Particle Particle::operator-(const Particle& peer) const {
    Spin newspin = (spin - peer.spin);
    Energy newenergy = (energy - peer.energy);
    return Particle("-", newspin, newenergy);
}

Particle Particle::operator*(const Particle& peer) const {
    Spin newspin = (spin * peer.spin);
    Energy newenergy = (energy * peer.energy);
    return Particle("*", newspin, newenergy);
}

Particle Particle::operator/(const Particle& peer) const {
    Spin newspin = (spin / peer.spin);
    Energy newenergy = (energy / peer.energy);
    return Particle("/", newspin, newenergy);
}

Particle Particle::operator%(const Particle& peer) const {
    Spin newspin = (spin % peer.spin);
    Energy newenergy = (energy % peer.energy);
    return Particle("%", newspin, newenergy);
}

float Particle::getTotal() const {
    return energy.getTotal();
}

bool Particle::isStructured() const {
    return physical != nullptr;
}

shp::Point Particle::copy() {
    Particle fresh(physical, spin, energy);
    return fresh;
}

void Particle::clear() {
    Wave::clear();
    spin.clear();
    energy.clear();
    return;
}

std::string Particle::print() {
    std::stringstream result;
    result << "[";
    result << Wave::print() << ",";
    result << energy.print() << ",";
    result << spin.print() << ",";
    result << (physical != nullptr ? physical->print() : "");
    result << "]";
	return result.str();
}

} // namespace qft
