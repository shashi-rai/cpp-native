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

#include "electron.h"

namespace qft {

const short int Electron::DEFAULT_VALUE = 0;

Electron::Electron()
		: Particle(Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(float polarization)
		: Particle(Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
}

Electron::Electron(float polarization, float azimuthal)
		: Particle(Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	setGradient(azimuthal);
}

Electron::Electron(std::string name)
		: Particle(name, Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, float polarization)
	: Particle(name, Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
}

Electron::Electron(std::string name, float polarization, float azimuthal)
        : Particle(name, Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	setGradient(azimuthal);
}

Electron::Electron(const Energy& energy)
        : Particle(energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, const Energy& energy)
        : Particle(name, energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(const Mass& mass, const Charge& charge)
        : Particle(mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, const Mass& mass, const Charge& charge)
        : Particle(name, mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Mass(mass), Charge(charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(short int principal, short int azimuthal, short int magnetic, float spin)
        : Particle(Spin(spin), Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, short int principal, short int azimuthal, short int magnetic,
		const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, short int principal, short int azimuthal, short int magnetic,
		const Spin& spin, const Mass& mass)
        : Particle(name, spin, mass, Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, short int principal, short int azimuthal, short int magnetic,
		const Spin& spin, const Charge& charge)
        : Particle(name, spin, Mass(Mass::ELECTRON), charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::Electron(std::string name, short int principal, short int azimuthal, short int magnetic,
		const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {

}

Electron::~Electron() {

}

bool Electron::operator==(const Electron& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer))
		&& (principal == peer.principal)
		&& (azimuthal == peer.azimuthal)
		&& (magnetic == peer.magnetic);
}

Electron Electron::operator+(const Electron& peer) const {
    return Electron("+", principal, azimuthal, magnetic,
		(this->getSpin() + peer.getSpin()),
		(this->getEnergy() + peer.getEnergy()));
}

Electron Electron::operator-(const Electron& peer) const {
    return Electron("-", principal, azimuthal, magnetic,
		(this->getSpin() - peer.getSpin()),
		(this->getEnergy() - peer.getEnergy()));
}

Electron Electron::operator*(const Electron& peer) const {
    return Electron("*", principal, azimuthal, magnetic,
		(this->getSpin() * peer.getSpin()),
		(this->getEnergy() * peer.getEnergy()));
}

Electron Electron::operator/(const Electron& peer) const {
    return Electron("/", principal, azimuthal, magnetic,
		(this->getSpin() / peer.getSpin()),
		(this->getEnergy() / peer.getEnergy()));
}

Electron Electron::operator%(const Electron& peer) const {
    return Electron("%", principal, azimuthal, magnetic,
		(this->getSpin() % peer.getSpin()),
		(this->getEnergy() % peer.getEnergy()));
}

Electron Electron::operator+(const Photon& peer) const {
    return Electron("+", principal, azimuthal, magnetic,
		(this->getSpin() + peer.getSpin()),
		(this->getEnergy() + peer.getEnergy()));
}

Electron Electron::operator-(const Photon& peer) const {
    return Electron("-", principal, azimuthal, magnetic,
		(this->getSpin() - peer.getSpin()),
		(this->getEnergy() - peer.getEnergy()));
}

Electron Electron::operator*(const Photon& peer) const {
    return Electron("*", principal, azimuthal, magnetic,
		(this->getSpin() * peer.getSpin()),
		(this->getEnergy() * peer.getEnergy()));
}

Electron Electron::operator/(const Photon& peer) const {
    return Electron("/", principal, azimuthal, magnetic,
		(this->getSpin() / peer.getSpin()),
		(this->getEnergy() / peer.getEnergy()));
}

Electron Electron::operator%(const Photon& peer) const {
    return Electron("%", principal, azimuthal, magnetic,
		(this->getSpin() % peer.getSpin()),
		(this->getEnergy() % peer.getEnergy()));
}

shp::Point Electron::copy() {
    Electron fresh(getName(), principal, azimuthal, magnetic, this->getSpin(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
	return fresh;
}

void Electron::clear() {
    Particle::clear();
	principal = azimuthal = magnetic = DEFAULT_VALUE;
    return;
}

std::string Electron::print() {
    std::stringstream result;
    result << "e";
	result << Particle::print();
	result << ",p:";
	result << principal << ",a:";
	result << azimuthal << ",m:";
	result << magnetic << "";
	return result.str();
}

} // namespace qft