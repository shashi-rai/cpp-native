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

namespace qft {

const short int Proton::UP_MIN = 0;
const short int Proton::UP_MAX = 2;
const float Proton::DEFAULT_SPIN = 0.5f;    // Dirac Fermions have 1/2 spin

Proton::Proton()
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)), up(), down() {

}

Proton::Proton(std::string name)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)), up(), down() {

}

Proton::Proton(float wavelength)
        : Particle(Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)), up(), down() {
    this->getEnergy().setWavelength(wavelength);
}

Proton::Proton(std::string name, float wavelength)
        : Particle(name, Spin(DEFAULT_SPIN), Mass(Mass::PROTON), Charge(Charge::PROTON)), up(), down() {
    this->getEnergy().setWavelength(wavelength);
}

Proton::Proton(std::string name, const Energy& energy)
        : Particle(name, Spin(DEFAULT_SPIN), energy), up(), down() {

}

Proton::Proton(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy), up(), down() {

}

Proton::Proton(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))), up(), down() {

}

Proton::Proton(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)), up(), down() {

}

Proton::~Proton() {

}

Quark Proton::getUp(short int index) const {
    Quark result;
    if (index >= UP_MIN && index < UP_MAX) {
        result = up[index];
    }
    return result;
}

Quark Proton::getDown() const {
    return down;
}

void Proton::setUp(const Quark& particle, short int index) {
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
        (this->getEnergy() / peer.getEnergy()));
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

shp::Quantity Proton::getWavelength() const {
    return this->getEnergy().getWavelength().getMagnitude();
}

shp::Point Proton::copy() {
    Proton fresh(this->getName(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
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
    result << "γ:";
	result << Particle::print() << std::endl << "\tu:";
    result << up[0].print() << std::endl << "\tu:";
    result << up[1].print() << std::endl << "\td:";
    result << down.print();
	return result.str();
}

} // namespace qft