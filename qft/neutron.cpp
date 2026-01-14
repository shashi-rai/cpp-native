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
#include "field.h"

namespace qft {

const short int Neutron::DOWN_MIN = 0;
const short int Neutron::DOWN_MAX = 2;
const float Neutron::DEFAULT_SPIN = 0.5f;               // Dirac Fermions have 1/2 spin
const float Neutron::RADIUS = 0.8418467f;               // Muonic Hydrogen
const short int Neutron::RADIUS_SCALE = -15;            // 10^-15 m
const float Neutron::COMPTON_WAVELENGTH = 1.31959f;     // Compton Wavelegth
const short int Neutron::WAVELENGTH_SCALE = -15;        // 10^-15 m

Neutron::Neutron()
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)),
        up(), down() {
    initialize();
}

Neutron::Neutron(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON, mass), Charge(Charge::NEUTRON, charge)),
        up(), down() {
    initialize();
}

Neutron::Neutron(std::string name)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)),
        up(), down() {
    initialize();
}

Neutron::Neutron(const float wavelength)
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)),
        up(), down() {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Neutron::Neutron(std::string name, const float wavelength)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::NEUTRON), Charge(Charge::NEUTRON)),
        up(), down() {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
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
    Energy self = getEnergy();
    self.setRadius(shp::Distance(RADIUS, RADIUS_SCALE));
    self.setWavelength(shp::Distance(COMPTON_WAVELENGTH, WAVELENGTH_SCALE));

    std::shared_ptr<qft::Field> mfield = Field::shareable("G");
    mfield->setMagnitude(Mass::PROTON, Mass::ATOMIC_SCALE);

    std::shared_ptr<qft::Field> efield = Field::shareable("E");
    efield->setMagnitude(Charge::PROTON, Charge::ATOMIC_SCALE);

    up = Quark("u", Quark::getComptonWavelength(Quark::UP),
        Quark::getMassLow(Quark::UP, mfield), Quark::getElectricCharge(Quark::UP, efield));
    down[0] = Quark("d", Quark::getComptonWavelength(Quark::DOWN),
        Quark::getMassLow(Quark::DOWN, mfield), Quark::getElectricCharge(Quark::DOWN, efield));
    down[1] = Quark("d", Quark::getComptonWavelength(Quark::DOWN),
        Quark::getMassLow(Quark::DOWN, mfield), Quark::getElectricCharge(Quark::DOWN, efield));
}

} // namespace qft