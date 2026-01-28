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

Photon::Photon() : Boson() {

}

Photon::Photon(const std::string name)
        : Boson(name) {

}

Photon::Photon(const float wavelength)
        : Boson(wavelength) {
}

Photon::Photon(const std::string name, const float wavelength)
        : Boson(name, wavelength) {

}

Photon::Photon(const std::string name, const Energy& energy)
        : Boson(name, energy) {

}

Photon::Photon(const std::string name, const Spin& spin, const Energy& energy)
        : Boson(name, spin, energy) {

}

Photon::Photon(const std::string name, const float spin, const float mass, const float charge)
        : Boson(name, Spin(spin), Energy(Mass(mass), Charge(charge))) {

}

Photon::Photon(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Boson(name, spin, Energy(mass, charge)) {

}

Photon::~Photon() {

}

bool Photon::operator==(const Photon& peer) const {
    return (static_cast<const Boson&>(*this) == static_cast<const Boson&>(peer));
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

shp::Point Photon::copy() {
    Photon fresh(this->getName(), this->getEnergy());
	fresh.setMagnitude(this->getMagnitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Photon::clear() {
    Boson::clear();
    return;
}

std::string Photon::print() {
    std::stringstream result;
    result << "γ:";
	result << Boson::print();
	return result.str();
}

} // namespace qft