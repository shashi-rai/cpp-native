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

#include "neutron.h"

namespace qft {

Neutron::Neutron() : Particle() {

}

Neutron::Neutron(std::string name) : Particle(name) {

}

Neutron::Neutron(float wavelength) : Particle(wavelength) {
    this->getEnergy().setWavelength(wavelength);
}

Neutron::Neutron(std::string name, float wavelength) : Particle(name) {
    this->getEnergy().setWavelength(wavelength);
}

Neutron::Neutron(std::string name, const Energy& energy) : Particle(name, energy) {

}

Neutron::~Neutron() {

}

bool Neutron::operator==(const Neutron& peer) const {
    return (static_cast<const Particle&>(*this) == static_cast<const Particle&>(peer));
}

Neutron Neutron::operator+(const Neutron& peer) const {
    return Neutron("+", (this->getEnergy() + peer.getEnergy()));
}

Neutron Neutron::operator-(const Neutron& peer) const {
    return Neutron("-", (this->getEnergy() - peer.getEnergy()));
}

shp::Quantity Neutron::getWavelength() const {
    return this->getEnergy().getWavelength();
}

shp::Point Neutron::copy() {
    Neutron fresh(this->getName(), this->getEnergy());
	fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
    return fresh;
}

void Neutron::clear() {
    Particle::clear();
    return;
}

std::string Neutron::print() {
    std::stringstream result;
    result << "γ:";
	result << Particle::print();
    result << "}";
	return result.str();
}

} // namespace qft