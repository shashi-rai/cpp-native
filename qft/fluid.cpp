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

#include "fluid.h"

namespace qft {

Fluid::Fluid()
		: qft::Density(), energy() {

}

Fluid::Fluid(const qft::Energy& energy)
        : qft::Density(), energy(energy) {

}

Fluid::Fluid(const float parameter, const qft::Energy& energy)
        : qft::Density(parameter), energy(energy) {

}

Fluid::Fluid(const float parameter, const short int scaling, const qft::Energy& energy)
        : qft::Density(parameter, scaling), energy(energy) {

}

Fluid::Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const qft::Energy& energy)
        : qft::Density(parameter, scaling, unit), energy(energy) {

}

Fluid::Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const qft::Energy& energy)
        : qft::Density(parameter, scaling, unit, modulation), energy(energy) {

}

Fluid::Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume, const qft::Energy& energy)
        : qft::Density(parameter, scaling, unit, modulation, volume), energy(energy) {

}

Fluid::Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Signal& volume, const qft::Energy& energy)
        : qft::Density(parameter, scaling, unit, modulation, volume), energy(energy) {

}

Fluid::Fluid(const std::string name)
        : qft::Density(name), energy() {

}

Fluid::Fluid(const std::string name, const qft::Energy& energy)
        : qft::Density(name), energy(energy) {

}

Fluid::Fluid(const std::string name, const float parameter, const qft::Energy& energy)
        : qft::Density(name, parameter), energy(energy) {

}

Fluid::Fluid(const std::string name, const float parameter, const short int scaling, const qft::Energy& energy)
        : qft::Density(name, parameter, scaling), energy(energy) {

}

Fluid::Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const qft::Energy& energy)
        : qft::Density(name, parameter, scaling, unit), energy(energy) {

}

Fluid::Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const qft::Energy& energy)
        : qft::Density(name, parameter, scaling, unit, modulation), energy(energy) {

}

Fluid::Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume, const qft::Energy& energy)
        : qft::Density(name, parameter, scaling, unit, modulation, volume), energy(energy) {

}

Fluid::Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Signal& volume, const qft::Energy& energy)
        : qft::Density(name, parameter, scaling, unit, modulation, volume), energy(energy) {

}

Fluid::~Fluid() {

}

bool Fluid::operator==(const Fluid& peer) const {
    return (static_cast<const qft::Density&>(*this) == static_cast<const qft::Density&>(peer))
        && (energy == peer.energy);
}

bool Fluid::operator<(const Fluid& peer) const {
    Fluid self = *this; bool result = false;
    if (static_cast<const qft::Density&>(*this) < static_cast<const qft::Density&>(peer)) {
        result = true;
    } else if (self.energy < peer.energy) {
        result = true;
    }
    return result;
}

bool Fluid::operator>(const Fluid& peer) const {
    Fluid self = *this; bool result = false;
    if (static_cast<const qft::Density&>(*this) > static_cast<const qft::Density&>(peer)) {
        result = true;
    } else if (self.energy > peer.energy) {
        result = true;
    }
    return result;
}

bool Fluid::operator<=(const Fluid& peer) const {
    Fluid self = *this;
    return (self < peer) || (self == peer);
}

bool Fluid::operator>=(const Fluid& peer) const {
    Fluid self = *this;
    return (self > peer) || (self == peer);
}

Fluid Fluid::operator+(const Fluid& peer) const {
    qft::Density self = *this, other = peer, density = (self + other);
    qft::Energy newEnergy = (this->energy + peer.energy);
    return Fluid("+", density.getMagnitude(), density.getScaling(), density.getUnit(),
        density.getScalarThermalDrift(), density.getVolume(), newEnergy);
}

Fluid Fluid::operator-(const Fluid& peer) const {
    qft::Density self = *this, other = peer, density = (self - other);
    qft::Energy newEnergy = (this->energy - peer.energy);
    return Fluid("-", density.getMagnitude(), density.getScaling(), density.getUnit(),
        density.getScalarThermalDrift(), density.getVolume(), newEnergy);
}

Fluid Fluid::operator*(const Fluid& peer) const {
    qft::Density self = *this, other = peer, density = (self * other);
    qft::Energy newEnergy = (this->energy * peer.energy);
    return Fluid("*", density.getMagnitude(), density.getScaling(), density.getUnit(),
        density.getScalarThermalDrift(), density.getVolume(), newEnergy);
}

Fluid Fluid::operator/(const Fluid& peer) const {
    qft::Density self = *this, other = peer, density = (self / other);
    qft::Energy newEnergy = (this->energy / peer.energy);
    return Fluid("/", density.getMagnitude(), density.getScaling(), density.getUnit(),
        density.getScalarThermalDrift(), density.getVolume(), newEnergy);
}

Fluid Fluid::operator%(const Fluid& peer) const {
    qft::Density self = *this, other = peer, density = (self % other);
    qft::Energy newEnergy = (this->energy % peer.energy);
    return Fluid("%", density.getMagnitude(), density.getScaling(), density.getUnit(),
        density.getScalarThermalDrift(), density.getVolume(), newEnergy);
}

Fluid Fluid::copy() {
    Fluid fresh(qft::Density::getName(),
        qft::Density::getMagnitude(), qft::Density::getScaling(), qft::Density::getUnit(),
        qft::Density::getScalarThermalDrift(), qft::Density::getVolume(), this->energy);
    return fresh;
}

void Fluid::clear() {
    qft::Density::clear();
    energy.clear();
    return;
}

std::string Fluid::print() const {
    std::stringstream result;
	result << qft::Density().print() << ",";
    result << energy.print();
	return result.str();
}

std::string Fluid::printRadians() const {
    std::stringstream result;
	result << qft::Density().printRadians() << ",";
    result << energy.printRadians();
	return result.str();
}

} // namespace qft