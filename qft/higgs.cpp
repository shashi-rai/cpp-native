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

#include "higgs.h"

namespace qft {

Higgs::Higgs()
        : Boson(Spin(Boson::SCALAR_SPIN)) {

}

Higgs::Higgs(std::string name)
        : Boson(name, Spin(Boson::SCALAR_SPIN)) {

}

Higgs::Higgs(const float wavelength)
        : Boson(wavelength) {
}

Higgs::Higgs(std::string name, const float wavelength)
        : Boson(name, wavelength) {

}

Higgs::Higgs(std::string name, const Energy& energy)
        : Boson(name, energy) {

}

Higgs::Higgs(std::string name, const Spin& spin, const Energy& energy)
        : Boson(name, spin, energy) {

}

Higgs::Higgs(std::string name, const float spin, const float mass, const float charge)
        : Boson(name, Spin(spin), Energy(Mass(mass), Charge(charge))) {

}

Higgs::Higgs(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Boson(name, spin, Energy(mass, charge)) {

}

Higgs::~Higgs() {

}

bool Higgs::operator==(const Higgs& peer) const {
    return (static_cast<const Boson&>(*this) == static_cast<const Boson&>(peer));
}

Higgs Higgs::operator+(const Higgs& peer) const {
    return Higgs("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Higgs Higgs::operator-(const Higgs& peer) const {
    return Higgs("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Higgs Higgs::operator*(const Higgs& peer) const {
    return Higgs("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Higgs Higgs::operator/(const Higgs& peer) const {
    return Higgs("/",
        (this->getSpin() / peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Higgs Higgs::operator%(const Higgs& peer) const {
    return Higgs("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

shp::Point Higgs::copy() {
    Higgs fresh(this->getName(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Higgs::clear() {
    Boson::clear();
    return;
}

std::string Higgs::print() {
    std::stringstream result;
    result << "H0:";
	result << Boson::print();
	return result.str();
}

} // namespace qft