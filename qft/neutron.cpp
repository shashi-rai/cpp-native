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

#include "neutron.h"
#include "proton.h"

namespace qft {

const short int Neutron::DOWN_MIN = 0;
const short int Neutron::DOWN_MAX = 2;
const float Neutron::DEFAULT_SPIN = 0.5f;    // Dirac Fermions have 1/2 spin

Neutron::Neutron()
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)), up(), down() {
    initialize();
}

Neutron::Neutron(std::string name)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)), up(), down() {
    initialize();
}

Neutron::Neutron(const float wavelength)
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)), up(), down() {
    this->getEnergy().setWavelength(wavelength);
    initialize();
}

Neutron::Neutron(std::string name, const float wavelength)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)), up(), down() {
    this->getEnergy().setWavelength(wavelength);
    initialize();
}

Neutron::Neutron(std::string name, const Energy& energy)
        : Particle(name, Spin(DEFAULT_SPIN), energy), up(), down() {
    initialize();
}

Neutron::Neutron(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy), up(), down() {
    initialize();
}

Neutron::Neutron(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))), up(), down() {
    initialize();
}

Neutron::Neutron(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)), up(), down() {
    initialize();
}

Neutron::~Neutron() {

}

Quark Neutron::getUp() const {
    return up;
}

Quark Neutron::getDown(short int index) const {
    Quark result;
    if (index >= DOWN_MIN && index < DOWN_MAX) {
        result = down[index];
    }
    return result;
}

void Neutron::setUp(const Quark& particle) {
    this->up = particle;
}

void Neutron::setDown(const Quark& particle, short int index) {
    if (index >= DOWN_MIN && index < DOWN_MAX) {
        this->down[index] = particle;
    }
}

bool Neutron::operator==(const Neutron& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer));
}

Neutron Neutron::operator+(const Neutron& peer) const {
    return Neutron("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Neutron Neutron::operator-(const Neutron& peer) const {
    return Neutron("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Neutron Neutron::operator*(const Neutron& peer) const {
    return Neutron("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Neutron Neutron::operator/(const Neutron& peer) const {
    return Neutron("/",
        (this->getSpin() / peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Neutron Neutron::operator%(const Neutron& peer) const {
    return Neutron("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

Proton Neutron::operator-(const Electron& peer) const {
    return Proton("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

shp::Point Neutron::copy() {
    Neutron fresh(this->getName(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Neutron::clear() {
    Particle::clear();
    down[0].clear();
    down[1].clear();
    up.clear();
    return;
}

std::string Neutron::print() {
    std::stringstream result;
    result << "n⁰:";
	result << Particle::print() << std::endl << "\td:";
    result << down[0].print() << std::endl << "\td:";
    result << down[1].print() << std::endl << "\tu:";
    result << up.print();
	return result.str();
}

void Neutron::initialize() {
    up = Quark("u", Quark::getMassLow(Quark::UP), Quark::getElectricCharge(Quark::UP));
    down[0] = Quark("d", Quark::getMassLow(Quark::DOWN), Quark::getElectricCharge(Quark::DOWN));
    down[1] = Quark("d", Quark::getMassLow(Quark::DOWN), Quark::getElectricCharge(Quark::DOWN));
}

} // namespace qft