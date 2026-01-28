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

#include "proton.h"
#include "neutron.h"
#include "field.h"

namespace qft {

const short int Proton::UP_MIN = 0;
const short int Proton::UP_MAX = 2;
const float Proton::DEFAULT_SPIN = 0.5f;                    // Dirac Fermions have 1/2 spin
const float Proton::RADIUS = 0.8418467f;                    // Muonic Hydrogen
const short int Proton::RADIUS_SCALE = -15;                 // 10^-15 m
const float Proton::COMPTON_WAVELENGTH = 1.3214098536041f;	// Compton Wavelegth
const short int Proton::WAVELENGTH_SCALE = -15;             // 10^-15 m

Proton::Proton()
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)),
        up(), down() {
    initialize();
}

Proton::Proton(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::PROTON, mass), Charge(Charge::PROTON, charge)),
        up(), down() {
    initialize();
}

Proton::Proton(const std::string name)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)),
        up(), down() {
    initialize();
}

Proton::Proton(const float wavelength)
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)),
        up(), down() {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Proton::Proton(const std::string name, const float wavelength)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)),
        up(), down() {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Proton::Proton(const std::string name, const Energy& energy)
        : Particle(name, Spin(DEFAULT_SPIN), energy), up(), down() {
    initialize();
}

Proton::Proton(const std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy), up(), down() {
    initialize();
}

Proton::Proton(const std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))), up(), down() {
    initialize();
}

Proton::Proton(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)), up(), down() {
    initialize();
}

Proton::~Proton() {

}

Quark Proton::getUp(const short int index) const {
    Quark result;
    if (index >= UP_MIN && index < UP_MAX) {
        result = up[index];
    }
    return result;
}

Quark Proton::getDown() const {
    return down;
}

void Proton::setUp(const Quark& particle, const short int index) {
    if (index >= UP_MIN && index < UP_MAX) {
        this->up[index] = particle;
    }
}

void Proton::setDown(const Quark& particle) {
    this->down = particle;
}

bool Proton::operator==(const Proton& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer));
}

Proton Proton::operator+(const Proton& peer) const {
    return Proton("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Proton Proton::operator-(const Proton& peer) const {
    return Proton("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Proton Proton::operator*(const Proton& peer) const {
    return Proton("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Proton Proton::operator/(const Proton& peer) const {
    return Proton("/",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Proton Proton::operator%(const Proton& peer) const {
    return Proton("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

Neutron Proton::operator+(const Electron& peer) const {
    return Neutron("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

shp::Point Proton::copy() {
    Proton fresh(this->getName(), this->getEnergy());
	fresh.setMagnitude(this->getMagnitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Proton::clear() {
    Particle::clear();
    up[0].clear();
    up[1].clear();
    down.clear();
    return;
}

std::string Proton::print() {
    std::stringstream result;
    result << "p⁺:";
	result << Particle::print() << std::endl << "\tu:";
    result << up[0].print() << std::endl << "\tu:";
    result << up[1].print() << std::endl << "\td:";
    result << down.print();
	return result.str();
}

void Proton::initialize() {
    Energy self = getEnergy();
    self.setRadius(shp::Distance(RADIUS, RADIUS_SCALE));
    self.setWavelength(shp::Distance(COMPTON_WAVELENGTH, WAVELENGTH_SCALE));

    std::shared_ptr<qft::Field> mfield = Field::shareable("G");
    mfield->setMagnitude(Mass::PROTON, Mass::ATOMIC_SCALE);

    std::shared_ptr<qft::Field> efield = Field::shareable("E");
    efield->setMagnitude(Charge::PROTON, Charge::ATOMIC_SCALE);

    up[0] = Quark("u", Quark::getComptonWavelength(Quark::UP),
        Quark::getMassLow(Quark::UP, mfield), Quark::getElectricCharge(Quark::UP, efield));
    up[1] = Quark("u", Quark::getComptonWavelength(Quark::UP),
        Quark::getMassLow(Quark::UP, mfield), Quark::getElectricCharge(Quark::UP, efield));
    down = Quark("d", Quark::getComptonWavelength(Quark::DOWN),
        Quark::getMassLow(Quark::DOWN, mfield), Quark::getElectricCharge(Quark::DOWN, efield));
}

} // namespace qft