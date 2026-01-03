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

const short int Quark::TYPE_MAX = 6;
const short int Quark::COLOUR_MAX = 3;
const short int Quark::GENERATION_MAX = 3;

const float Quark::MASS_LOWER[] = {
    1.7f, 4.1f,                 // First Generation (Up, Down)
    1270.0f, 101.0f,            // Second Generation (Charm, Strange)
    172000.0f, 4190.0f,         // Third Generation (Top, Bottom)
};

const float Quark::MASS_HIGHER[] = {
    3.3f, 5.8f,                 // First Generation (Up, Down)
    1270.0f, 101.0f,            // Second Generation (Charm, Strange)
    172000.0f, 4190.0f,         // Third Generation (Top, Bottom)
};

const float Quark::ELECTRIC_CHARGE[] = {
    +(2.0f/3.0f), -(1.0f/3.0f), // First Generation (Up, Down)
    +(2.0f/3.0f), -(1.0f/3.0f), // Second Generation (Charm, Strange)
    +(2.0f/3.0f), -(1.0f/3.0f), // Third Generation (Top, Bottom)
};

const float Quark::DEFAULT_SPIN = 0.5f;     // Dirac Fermions have 1/2 spin
const float Quark::RADIUS = 0.43f;          // 0.43x10^-16 m
const short int Quark::RADIUS_SCALE = -16;  // 10^-16 m
const float Quark::COMPTON_WAVELENGTH[] = {
    140.0f, 225.0f,             // First Generation (Up, Down)
    1.0f, 13.0f,                // Second Generation (Charm, Strange)
    0.0007f, 0.3f,              // Third Generation (Top, Bottom)
};
const short int Quark::WAVELENGTH_SCALE = -15;  // 10^-15 m

Quark::Quark()
        : Particle(Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, nullptr), getElectricCharge(Quark::UP, nullptr)) {
    initialize();
}

Quark::Quark(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, mass), getElectricCharge(Quark::UP, charge)) {
    initialize();
}

Quark::Quark(std::string name)
        : Particle(name, Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, nullptr), getElectricCharge(Quark::UP, nullptr)) {
    initialize();
}

Quark::Quark(std::string name,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(name, Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, mass), getElectricCharge(Quark::UP, charge)) {
    initialize();
}

Quark::Quark(float wavelength)
        : Particle(Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, nullptr), getElectricCharge(Quark::UP, nullptr)) {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Quark::Quark(float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, mass), getElectricCharge(Quark::UP, charge)) {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Quark::Quark(std::string name, float wavelength)
        : Particle(name, Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, nullptr), getElectricCharge(Quark::UP, nullptr)) {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Quark::Quark(std::string name, float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(name, Spin(DEFAULT_SPIN),
        getMassLow(Quark::UP, nullptr), getElectricCharge(Quark::UP, nullptr)) {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
}

Quark::Quark(std::string name, const Energy& energy)
        : Particle(name, Spin(DEFAULT_SPIN), energy) {
    initialize();
}

Quark::Quark(std::string name, const Mass& mass, const Charge& charge)
        : Particle(name, Spin(DEFAULT_SPIN), Energy(mass, charge)) {
    initialize();
}

Quark::Quark(std::string name, const shp::Distance& wavelength,
        const Mass& mass, const Charge& charge)
        : Particle(name, Spin(DEFAULT_SPIN), Energy(mass, charge)) {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);

}

Quark::Quark(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy) {
    initialize();
}

Quark::Quark(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Energy(Mass(mass), Charge(charge))) {
    initialize();
}

Quark::Quark(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)) {
    initialize();
}

Quark::Quark(std::string name, const shp::Distance& wavelength, const Spin& spin,
        const Mass& mass, const Charge& charge)
        : Particle(name, spin, Energy(mass, charge)) {
    initialize();
    Energy self = getEnergy(); self.setWavelength(wavelength);
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
        (this->getEnergy() * peer.getEnergy()));
}

Quark Quark::operator%(const Quark& peer) const {
    return Quark("%",
        (this->getSpin() % peer.getSpin()),
        (this->getEnergy() % peer.getEnergy()));
}

const Mass Quark::getMassLow(short int number, const std::shared_ptr<Field> field) {
    shp::Quantity result;
    if ((number > 0 && number <= TYPE_MAX)) {
        result = Energy::getMegaElectronvolt(MASS_LOWER[number-1]);
    } else {
        result = Energy::getMegaElectronvolt(MASS_LOWER[0]);
    }
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

const Mass Quark::getMassHigh(short int number, const std::shared_ptr<Field> field) {
    shp::Quantity result;
    if ((number > 0 && number <= TYPE_MAX)) {
        result = Energy::getMegaElectronvolt(MASS_HIGHER[number-1]);
    } else {
        result = Energy::getMegaElectronvolt(MASS_HIGHER[0]);
    }
    return Mass(result.getMagnitude(), result.getScaling(), result.getUnit(), field);
}

const Charge Quark::getElectricCharge(short int number, const std::shared_ptr<Field> field) {
    Charge result;
    if ((number > 0 && number <= TYPE_MAX)) {
        result = Charge(ELECTRIC_CHARGE[number-1], field);
    } else {
        result = Charge(ELECTRIC_CHARGE[0], field);
    }
    return result;
}

const shp::Distance Quark::getComptonWavelength(short int number) {
    float length;
    if ((number > 0 && number <= TYPE_MAX)) {
        length = COMPTON_WAVELENGTH[number-1];
    } else {
        length = COMPTON_WAVELENGTH[0];
    }
    return shp::Distance(length, WAVELENGTH_SCALE);
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

void Quark::initialize() {
    Energy self = getEnergy();
    self.setRadius(shp::Distance(RADIUS, RADIUS_SCALE));
}

} // namespace qft