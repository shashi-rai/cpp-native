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
const float Electron::DEFAULT_SPIN = 0.5f;					// Dirac Fermions have 1/2 spin
const float Electron::RADIUS = 2.817940320513f;				// electromagnetic scattering
const short int Electron::RADIUS_SCALE = -15;				// Classical Estimation
const float Electron::COMPTON_WAVELENGTH = 2.4263102386740f;// Compton Wavelegth
const short int Electron::WAVELENGTH_SCALE = -12;			// 10^-12 m

Electron::Electron()
		: Particle(Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
		: Particle(Mass(Mass::ELECTRON, mass), Charge(Charge::ELECTRON, charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const float polarization)
		: Particle(Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	initialize();
}

Electron::Electron(const float polarization,
		const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
		: Particle(Mass(Mass::ELECTRON, mass), Charge(Charge::ELECTRON, charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	initialize();
}

Electron::Electron(const float polarization, const float azimuthal)
		: Particle(Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	setGradient(azimuthal);
	initialize();
}

Electron::Electron(const float polarization, const float azimuthal,
		const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
		: Particle(Mass(Mass::ELECTRON, mass), Charge(Charge::ELECTRON, charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	setGradient(azimuthal);
	initialize();
}

Electron::Electron(const std::string name)
		: Particle(name, Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name,
		const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
		: Particle(name, Mass(Mass::ELECTRON, mass), Charge(Charge::ELECTRON, charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const float polarization)
	: Particle(name, Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	initialize();
}

Electron::Electron(const std::string name, const float polarization,
	const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
	: Particle(name, Mass(Mass::ELECTRON, mass), Charge(Charge::ELECTRON, charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	initialize();
}

Electron::Electron(const std::string name, const float polarization, const float azimuthal)
        : Particle(name, Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	setGradient(azimuthal);
	initialize();
}

Electron::Electron(const std::string name, const float polarization, const float azimuthal,
		const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge)
        : Particle(name, Mass(Mass::ELECTRON, mass), Charge(Charge::ELECTRON, charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	setPolarization(polarization);
	setGradient(azimuthal);
	initialize();
}

Electron::Electron(const Energy& energy)
        : Particle(energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const Energy& energy)
        : Particle(name, energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const Mass& mass, const Charge& charge)
        : Particle(mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const Mass& mass, const Charge& charge)
        : Particle(name, mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const float spin, const float mass, const float charge)
        : Particle(name, Spin(spin), Mass(mass), Charge(charge)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const short int principal, const short int azimuthal, const short int magnetic,
		const float spin)
        : Particle(Spin(spin), Mass(Mass::ELECTRON), Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const short int principal, const short int azimuthal,
		const short int magnetic, const Spin& spin, const Energy& energy)
        : Particle(name, spin, energy),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const short int principal, const short int azimuthal,
		const short int magnetic, const Spin& spin, const Mass& mass)
        : Particle(name, spin, mass, Charge(Charge::ELECTRON)),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const short int principal, const short int azimuthal,
		const short int magnetic, const Spin& spin, const Charge& charge)
        : Particle(name, spin, Mass(Mass::ELECTRON), charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
}

Electron::Electron(const std::string name, const short int principal, const short int azimuthal,
		const short int magnetic, const Spin& spin, const Mass& mass, const Charge& charge)
        : Particle(name, spin, mass, charge),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE) {
	initialize();
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
	fresh.setMagnitude(this->getMagnitude());
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
    result << "e⁻";
	result << Particle::print();
	result << ",p:";
	result << principal << ",a:";
	result << azimuthal << ",m:";
	result << magnetic << "";
	return result.str();
}

void Electron::initialize() {
    Energy self = getEnergy();
    self.setRadius(shp::Distance(RADIUS, RADIUS_SCALE));
	self.setWavelength(shp::Distance(COMPTON_WAVELENGTH, WAVELENGTH_SCALE));
}

} // namespace qft