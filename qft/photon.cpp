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

#include "photon.h"

namespace qft {

Photon::Photon() : Particle() {

}

Photon::Photon(std::string name) : Particle(name) {

}

Photon::Photon(float wavelength) : Particle(wavelength) {
    this->getEnergy().setWavelength(wavelength);
}

Photon::Photon(std::string name, float wavelength) : Particle(name) {
    this->getEnergy().setWavelength(wavelength);
}

Photon::Photon(std::string name, const Energy& energy)
        : Particle(name, energy) {

}

Photon::Photon(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy) {

}

Photon::Photon(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))) {

}

Photon::Photon(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)) {

}

Photon::~Photon() {

}

bool Photon::operator==(const Photon& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer));
}

Photon Photon::operator+(const Photon& peer) const {
    return Photon("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Photon Photon::operator-(const Photon& peer) const {
    return Photon("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Photon Photon::operator*(const Photon& peer) const {
    return Photon("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Photon Photon::operator/(const Photon& peer) const {
    return Photon("/",
        (this->getSpin() / peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Photon Photon::operator%(const Photon& peer) const {
    return Photon("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

shp::Quantity Photon::getWavelength() const {
    return this->getEnergy().getWavelength().getMagnitude();
}

shp::Point Photon::copy() {
    Photon fresh(this->getName(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Photon::clear() {
    Particle::clear();
    return;
}

std::string Photon::print() {
    std::stringstream result;
    result << "γ:";
	result << Particle::print();
	return result.str();
}

} // namespace qft