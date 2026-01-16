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

#include "neutrino.h"

namespace qft {

const float Neutrino::DEFAULT_SPIN = 0.5f;    // Dirac Fermions have 1/2 spin

Neutrino::Neutrino()
        : Particle(Spin(DEFAULT_SPIN)) {

}

Neutrino::Neutrino(std::string name)
        : Particle(name, Spin(DEFAULT_SPIN)) {

}

Neutrino::Neutrino(const float wavelength)
        : Particle(Spin(DEFAULT_SPIN)) {
    this->getEnergy().setWavelength(wavelength);
}

Neutrino::Neutrino(std::string name, const float wavelength)
        : Particle(name, Spin(DEFAULT_SPIN)) {
    this->getEnergy().setWavelength(wavelength);
}

Neutrino::Neutrino(std::string name, const Energy& energy)
        : Particle(name, Spin(DEFAULT_SPIN), energy) {

}

Neutrino::Neutrino(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy) {

}

Neutrino::Neutrino(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))) {

}

Neutrino::Neutrino(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)) {

}

Neutrino::~Neutrino() {

}

bool Neutrino::operator==(const Neutrino& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer));
}

Neutrino Neutrino::operator+(const Neutrino& peer) const {
    return Neutrino("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Neutrino Neutrino::operator-(const Neutrino& peer) const {
    return Neutrino("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Neutrino Neutrino::operator*(const Neutrino& peer) const {
    return Neutrino("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Neutrino Neutrino::operator/(const Neutrino& peer) const {
    return Neutrino("/",
        (this->getSpin() / peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Neutrino Neutrino::operator%(const Neutrino& peer) const {
    return Neutrino("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

shp::Point Neutrino::copy() {
    Neutrino fresh(this->getName(), this->getEnergy());
	fresh.setMagnitude(this->getMagnitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Neutrino::clear() {
    Particle::clear();
    return;
}

std::string Neutrino::print() {
    std::stringstream result;
    result << "ν:";
	result << Particle::print();
	return result.str();
}

} // namespace qft