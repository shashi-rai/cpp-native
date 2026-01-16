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

#include "gluon.h"

namespace qft {

Gluon::Gluon() : Boson(), colour() {

}

Gluon::Gluon(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Boson(mass, charge), colour() {

}

Gluon::Gluon(std::string name)
        : Boson(name), colour() {

}

Gluon::Gluon(std::string name,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Boson(name, mass, charge), colour() {

}
 
Gluon::Gluon(const float wavelength)
        : Boson(wavelength), colour() {
}

Gluon::Gluon(const float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Boson(wavelength, mass, charge), colour() {
}

Gluon::Gluon(std::string name, const float wavelength)
        : Boson(name, wavelength), colour() {

}

Gluon::Gluon(std::string name, const float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Boson(name, wavelength, mass, charge), colour() {

}

Gluon::Gluon(std::string name, const Energy& energy)
        : Boson(name, energy), colour() {

}

Gluon::Gluon(std::string name, const Spin& spin, const Energy& energy)
        : Boson(name, spin, energy), colour() {

}

Gluon::Gluon(std::string name, const float spin, const float mass, const float charge)
        : Boson(name, Spin(spin), Energy(Mass(mass), Charge(charge))), colour() {

}

Gluon::Gluon(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Boson(name, spin, Energy(mass, charge)), colour() {

}

Gluon::~Gluon() {

}

bool Gluon::operator==(const Gluon& peer) const {
    return (static_cast<const Boson&>(*this) == static_cast<const Boson&>(peer))
        && (colour == peer.colour);
}

Gluon Gluon::operator+(const Gluon& peer) const {
    return Gluon("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Gluon Gluon::operator-(const Gluon& peer) const {
    return Gluon("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Gluon Gluon::operator*(const Gluon& peer) const {
    return Gluon("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Gluon Gluon::operator/(const Gluon& peer) const {
    return Gluon("/",
        (this->getSpin() / peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Gluon Gluon::operator%(const Gluon& peer) const {
    return Gluon("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

shp::Point Gluon::copy() {
    Gluon fresh(this->getName(), this->getEnergy());
    fresh.setColour(colour);
	fresh.setMagnitude(this->getMagnitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Gluon::clear() {
    Boson::clear();
    colour.clear();
    return;
}

std::string Gluon::print() {
    std::stringstream result;
    result << "g";
	result << Boson::print() << ",";
    result << colour.print();
	return result.str();
}

} // namespace qft