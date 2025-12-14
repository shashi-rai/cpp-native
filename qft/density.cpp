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

#include "density.h"

namespace qft {

const std::string Density::UNIT = "/m^3";   // System International

Density::Density() : name(), unit(UNIT), magnitude(), volume() {

}

Density::Density(std::string name)
        : name(name), unit(UNIT), magnitude(), volume() {

}

Density::Density(const float magnitude)
        : name(), unit(UNIT), magnitude(magnitude), volume() {

}

Density::Density(const float magnitude, const std::string unit)
        : name(), unit(UNIT), magnitude(magnitude, unit), volume() {

}

Density::Density(const float magnitude, short int scaling, const std::string unit)
        : name(), unit(UNIT), magnitude(magnitude, scaling, unit), volume() {

}

Density::Density(const float magnitude, const float volume)
        : name(), unit(UNIT), magnitude(magnitude), volume(std::cbrt(volume)) {

}

Density::Density(const float magnitude, const float volume,
        const std::string unit)
        : name(), unit(UNIT), magnitude(magnitude, unit), volume(std::cbrt(volume)) {

}

Density::Density(const float magnitude, const float volume,
        short int scaling, const std::string unit)
        : name(), unit(UNIT), magnitude(magnitude, scaling, unit), volume(std::cbrt(volume)) {

}

Density::Density(const shp::Quantity& magnitude, const shp::Volume& volume)
        : name(), unit(UNIT), magnitude(magnitude), volume(volume) {

}

Density::Density(const shp::Quantity& magnitude, const shp::Volume& volume,
        const shp::Unit& unit)
        : name(), unit(unit), magnitude(magnitude), volume(volume) {

}

Density::Density(std::string name, const shp::Unit& unit)
        : name(name), unit(UNIT), magnitude(unit), volume() {

}

Density::Density(std::string name, short int scaling, const shp::Unit& unit)
        : name(name), unit(UNIT), magnitude(scaling, unit), volume() {

}

Density::Density(std::string name, const float magnitude)
        : name(name), unit(UNIT), magnitude(magnitude), volume() {

}

Density::Density(std::string name, const float magnitude, const std::string unit)
        : name(name), unit(UNIT), magnitude(magnitude, unit), volume() {

}

Density::Density(std::string name, const float magnitude,
        short int scaling, const std::string unit)
        : name(name), unit(UNIT), magnitude(magnitude, scaling, unit), volume() {

}

Density::Density(std::string name, const float magnitude, const float volume)
        : name(name), unit(UNIT), magnitude(magnitude), volume(std::cbrt(volume)) {

}

Density::Density(std::string name, const float magnitude, const float volume,
        const std::string unit)
        : name(name), unit(UNIT), magnitude(magnitude, unit), volume(std::cbrt(volume)) {

}

Density::Density(std::string name, const float magnitude, const float volume,
        short int scaling, const std::string unit)
        : name(name), unit(UNIT), magnitude(magnitude, scaling, unit), volume(std::cbrt(volume)) {

}

Density::Density(std::string name, const shp::Quantity& magnitude)
        : name(name), unit(UNIT), magnitude(magnitude), volume() {

}

Density::Density(std::string name, const shp::Quantity& magnitude,
        const shp::Unit& unit)
        : name(name), unit(unit), magnitude(magnitude), volume() {

}

Density::Density(std::string name,
        const shp::Quantity& magnitude, const shp::Volume& volume)
        : name(name), unit(UNIT), magnitude(magnitude), volume(volume) {

}

Density::Density(std::string name, const shp::Quantity& magnitude,
        const shp::Volume& volume, const shp::Unit& unit)
        : name(name), unit(unit), magnitude(magnitude), volume(volume) {

}

Density::~Density() {

}

bool Density::operator==(const Density& peer) const {
    return (magnitude == peer.magnitude) && (volume == peer.volume);
}

Density Density::operator+(const Density& peer) const {
	shp::Quantity newmagnitude = (magnitude + peer.magnitude);
    shp::Quantity newvolume = (volume.getTotal() + peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("+", newmagnitude, newvolume);
}

Density Density::operator-(const Density& peer) const {
	shp::Quantity newmagnitude = (magnitude - peer.magnitude);
    shp::Quantity newvolume = (volume.getTotal() - peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("-", newmagnitude, newvolume);
}

Density Density::operator*(const Density& peer) const {
	shp::Quantity newmagnitude = (magnitude * peer.magnitude);
    shp::Quantity newvolume = (volume.getTotal() * peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("*", newmagnitude, newvolume);
}

Density Density::operator/(const Density& peer) const {
	shp::Quantity newmagnitude = (magnitude / peer.magnitude);
    shp::Quantity newvolume = (volume.getTotal() / peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("/", newmagnitude, newvolume);
}

Density Density::operator%(const Density& peer) const {
	shp::Quantity newmagnitude = (magnitude % peer.magnitude);
    shp::Quantity newvolume = (volume.getTotal() % peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("%", newmagnitude, newvolume);
}

shp::Quantity Density::getTotal() const {
    shp::Quantity density = (magnitude / volume.getTotal());
    return shp::Quantity(density.getValue(), density.getScaling(), density.getUnit());
}

Density Density::copy() {
    Density fresh(name, magnitude, volume, unit);
    return fresh;
}

void Density::clear() {
	name = "";
    unit.clear();
    magnitude.clear();
    volume.clear();
    return;
}

std::string Density::print() {
    std::stringstream result;
    result << "(ρ:";
	result << name << ",";
    result << magnitude.print() << ",";
	result << volume.print() << ")";
	result << unit.print() + UNIT;
	return result.str();
}

shp::Quantity Density::getComponent(float phase) const {
	shp::Quantity density = getTotal();
    return shp::Quantity(getTotal().getValue() * cos(phase), density.getScaling(), density.getUnit());
}

} // namespace qft