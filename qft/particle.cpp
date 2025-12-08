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
        : Point(), spin(), energy() {
    setPhysical(nullptr);
}

Particle::Particle(Spin& spin)
        : Point(), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name)
        : Point(name), spin(), energy() {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, Spin& spin)
        : Point(name), spin(spin), energy() {
    setPhysical(nullptr);
}

Particle::Particle(Energy& energy)
        : Point(), spin(), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(Spin& spin, Energy& energy)
        : Point(), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, Energy& energy)
        : Point(name), spin(), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, Spin& spin, Energy& energy)
        : Point(name), spin(spin), energy(energy) {
    setPhysical(nullptr);
}

Particle::Particle(Mass& mass, Charge& charge)
        : Point(), spin(), energy(mass, charge) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, Mass& mass, Charge& charge)
        : Point(name), spin(), energy(mass, charge) {
    setPhysical(nullptr);
}

Particle::Particle(Spin& spin, Mass& mass, Charge& charge)
        : Point(), spin(spin), energy(mass, charge) {
    setPhysical(nullptr);
}

Particle::Particle(std::string name, Spin& spin, Mass& mass, Charge& charge)
        : Point(name), spin(spin), energy(mass, charge) {
    setPhysical(nullptr);
}

Particle::Particle(shp::Shape* physical)
        : Point(), spin(), energy() {
    setPhysical(physical);
}

Particle::Particle(std::string name, shp::Shape* physical)
        : Point(name), spin(), energy() {
    setPhysical(physical);
}

Particle::Particle(std::string name, shp::Shape* physical, Spin& spin)
        : Point(name), spin(spin), energy() {
    setPhysical(physical);
}

Particle::Particle(std::string name, shp::Shape* physical, Spin& spin, Energy& energy)
        : Point(name), spin(spin), energy(energy) {
    setPhysical(physical);
}

Particle::Particle(shp::Shape* physical, Spin& spin, Energy& energy)
        : Point(), spin(spin), energy(energy) {
    setPhysical(physical);
}

Particle::Particle(shp::Shape* physical, Spin& spin, Mass& mass, Charge& charge)
        : Point(), spin(spin), energy(mass, charge) {
    setPhysical(physical);
}

Particle::Particle(std::string name, shp::Shape* physical, Spin& spin, Mass& mass, Charge& charge)
        : Point(name), spin(spin), energy(mass, charge) {
    setPhysical(physical);
}

Particle::~Particle() {
    setPhysical(nullptr);
}

bool Particle::operator==(const Particle& peer) const {
    return (physical == peer.physical)
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

bool Particle::isStructured() const {
    return physical != nullptr;
}

shp::Point Particle::copy() {
    Particle fresh(physical, spin, energy);
    return fresh;
}

void Particle::clear() {
    Point::clear();
    spin.clear();
    energy.clear();
    return;
}

std::string Particle::print() {
    std::stringstream result;
    result << "[";
    result << Point::print() << ",";
    result << spin.print() << ",";
    result << energy.print() << "]";
	return result.str();
}

} // namespace qft
