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

#include "boson.h"

namespace qft {

const float Boson::DEFAULT_CHARGE = 0.0f;   //
const float Boson::DEFAULT_MASS = 0.0f;     //
const float Boson::DEFAULT_PARITY = -1.0f;  //
const float Boson::SCALAR_SPIN = 0.0f;      // Scalar Boson has zero spin
const float Boson::GUAGE_SPIN1 = 1.0f;      // Guage Bosons have integer spin
const float Boson::GUAGE_SPIN2 = 2.0f;      // Guage Bosons have integer spin

Boson::Boson()
        : Particle(GUAGE_SPIN1), handed() {

}

Boson::Boson(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(GUAGE_SPIN1, mass, charge), handed() {

}

Boson::Boson(const Spin& spin)
        : Particle(spin), handed() {

}

Boson::Boson(const Spin& spin,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(spin, mass, charge), handed() {

}

Boson::Boson(std::string name)
        : Particle(name, GUAGE_SPIN1), handed() {

}

Boson::Boson(std::string name,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(name, GUAGE_SPIN1, mass, charge), handed() {

}

Boson::Boson(std::string name, const Spin& spin)
        : Particle(name, spin), handed() {

}

Boson::Boson(std::string name,
        const Spin& spin, const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(name, spin, mass, charge), handed() {

}

Boson::Boson(const float wavelength)
        : Particle(GUAGE_SPIN1), handed() {
    Energy energy = getEnergy();
    energy.setWavelength(wavelength);
}

Boson::Boson(const float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(GUAGE_SPIN1, mass, charge), handed() {
    Energy energy = getEnergy();
    energy.setWavelength(wavelength);
}

Boson::Boson(std::string name, const float wavelength)
        : Particle(name, GUAGE_SPIN1), handed() {
    Energy energy = getEnergy();
    energy.setWavelength(wavelength);
}

Boson::Boson(std::string name, const float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(name, GUAGE_SPIN1, mass, charge), handed() {
    Energy energy = getEnergy();
    energy.setWavelength(wavelength);
}

Boson::Boson(std::string name, const Energy& energy)
        : Particle(name, GUAGE_SPIN1, energy), handed() {

}

Boson::Boson(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy), handed() {

}

Boson::Boson(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))), handed() {

}

Boson::Boson(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)), handed() {

}

Boson::~Boson() {

}

bool Boson::operator==(const Boson& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer))
        && (handed == peer.handed);
}

Boson Boson::operator+(const Boson& peer) const {
    return Boson("+",
        (this->getSpin() + peer.getSpin()),
        (this->getEnergy() + peer.getEnergy()));
}

Boson Boson::operator-(const Boson& peer) const {
    return Boson("-",
        (this->getSpin() - peer.getSpin()),
        (this->getEnergy() - peer.getEnergy()));
}

Boson Boson::operator*(const Boson& peer) const {
    return Boson("*",
        (this->getSpin() * peer.getSpin()),
        (this->getEnergy() * peer.getEnergy()));
}

Boson Boson::operator/(const Boson& peer) const {
    return Boson("/",
        (this->getSpin() / peer.getSpin()),
        (this->getEnergy() / peer.getEnergy()));
}

Boson Boson::operator%(const Boson& peer) const {
    return Boson("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

shp::Point Boson::copy() {
    Boson fresh(this->getName(), this->getEnergy());
    fresh.setHanded(handed);
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Boson::clear() {
    Particle::clear();
    handed.clear();
    return;
}

std::string Boson::print() {
    std::stringstream result;
    result << "b:";
	result << Particle::print() << ",";
    result << handed.print();
	return result.str();
}

} // namespace qft