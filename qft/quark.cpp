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

#include "quark.h"

namespace qft {

Quark::Quark() : Particle() {

}

Quark::Quark(std::string name) : Particle(name) {

}

Quark::Quark(float wavelength) : Particle(wavelength) {
    this->getEnergy().setWavelength(wavelength);
}

Quark::Quark(std::string name, float wavelength)
        : Particle(name) {
    this->getEnergy().setWavelength(wavelength);
}

Quark::Quark(std::string name, const Energy& energy)
        : Particle(name, energy) {

}

Quark::Quark(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy) {

}

Quark::Quark(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))) {

}

Quark::Quark(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)) {

}

Quark::~Quark() {

}

bool Quark::operator==(const Quark& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer));
}

Quark Quark::operator+(const Quark& peer) const {
    return Quark("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Quark Quark::operator-(const Quark& peer) const {
    return Quark("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Quark Quark::operator*(const Quark& peer) const {
    return Quark("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Quark Quark::operator/(const Quark& peer) const {
    return Quark("/",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Quark Quark::operator%(const Quark& peer) const {
    return Quark("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

shp::Quantity Quark::getWavelength() const {
    return this->getEnergy().getWavelength().getMagnitude();
}

shp::Point Quark::copy() {
    Quark fresh(this->getName(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Quark::clear() {
    Particle::clear();
    return;
}

std::string Quark::print() {
    std::stringstream result;
	result << Particle::print();
	return result.str();
}

} // namespace qft