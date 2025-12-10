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

namespace che {

const short int Electron::DEFAULT_VALUE = 0;

Electron::Electron() : Wave(),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy() {

}

Electron::Electron(float polarization) : Wave(polarization),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy()  {

}

Electron::Electron(float polarization, float azimuthal)
        : Wave(polarization, azimuthal),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy()  {

}

Electron::Electron(std::string name) : Wave(name),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy()  {

}

Electron::Electron(std::string name, float polarization) : Wave(name, polarization),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy()  {

}

Electron::Electron(std::string name, float polarization, float azimuthal)
        : Wave(name, polarization, azimuthal),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy() {

}

Electron::Electron(const qft::Energy& energy)
        : Wave(),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy(energy) {

}

Electron::Electron(std::string name, const qft::Energy& energy)
        : Wave(name),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy(energy) {

}

Electron::Electron(const qft::Mass& mass, const qft::Charge& charge)
        : Wave(),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy(mass, charge) {

}

Electron::Electron(std::string name, const qft::Mass& mass, const qft::Charge& charge)
        : Wave(name),
		principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(), energy(mass, charge) {

}

Electron::Electron(short int principal, short int azimuthal, short int magnetic, float spin)
        : Wave(), principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(spin), energy() {

}

Electron::Electron(std::string name,
        short int principal, short int azimuthal, short int magnetic, const qft::Spin& spin,
        const qft::Energy& energy)
        : Wave(name), principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(spin), energy(energy) {

}

Electron::Electron(std::string name,
        short int principal, short int azimuthal, short int magnetic, const qft::Spin& spin,
        const qft::Mass& mass)
        : Wave(name), principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(spin), energy(mass) {

}

Electron::Electron(std::string name,
        short int principal, short int azimuthal, short int magnetic, const qft::Spin& spin,
        const qft::Charge& charge)
        : Wave(name), principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(spin), energy(charge) {

}

Electron::Electron(std::string name,
        short int principal, short int azimuthal, short int magnetic, const qft::Spin& spin,
        const qft::Mass& mass, const qft::Charge& charge)
        : Wave(name), principal(DEFAULT_VALUE), azimuthal(DEFAULT_VALUE), magnetic(DEFAULT_VALUE),
		spin(spin), energy(mass, charge) {

}

Electron::~Electron() {

}

bool Electron::operator==(const Electron& peer) const {
    return (principal == peer.principal)
		&& (azimuthal == peer.azimuthal)
		&& (magnetic == peer.magnetic)
		&& (spin == peer.spin)
		&& (energy == peer.energy);
}

Electron Electron::operator+(const Photon& peer) const {
	qft::Energy total = (energy + peer.getEnergy());
    return Electron("+", principal, azimuthal, magnetic, spin, total);
}

Electron Electron::operator-(const Photon& peer) const {
	qft::Energy total = (energy - peer.getEnergy());
    return Electron("-", principal, azimuthal, magnetic, spin, total);
}

shp::Point Electron::copy() {
    Electron fresh(getName(), principal, azimuthal, magnetic, spin, energy);
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
	fresh.setPolarization(this->getPolarization());
	fresh.setFrequency(this->getFrequency());
	fresh.setWavelength(this->getWavelength());
	return fresh;
}

void Electron::clear() {
    Wave::clear();
	principal = azimuthal = magnetic = DEFAULT_VALUE;
	spin.clear();
	energy.clear();
    return;
}

std::string Electron::print() {
    std::stringstream result;
    result << "e";
	result << Wave::print();
	result << energy.print();
	return result.str();
}

} // namespace che