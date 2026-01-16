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

const std::string Density::UNIT = "/m³";	// System International

Density::Density()
        : name(), parameter(UNIT), volume() {

} 

Density::Density(std::string name)
        : name(name), parameter(UNIT), volume() {

}

Density::Density(const float parameter)
        : name(), parameter(parameter, UNIT), volume() {

}

Density::Density(const float parameter, const std::string unit)
        : name(), parameter(parameter, unit), volume() {

}

Density::Density(const float parameter, const short int scaling, const std::string unit)
        : name(), parameter(parameter, scaling, unit), volume() {

}

Density::Density(const float parameter, const float volume)
        : name(), parameter(parameter, UNIT) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const float volume)
        : name(), parameter(parameter, scaling, UNIT) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const std::string unit, const float volume)
        : name(), parameter(parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter,
        const short int scaling, const std::string unit, const float volume)
        : name(), parameter(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter,
        const short int scaling, const std::string unit, const shp::Volume& volume)
        : name(), parameter(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter,
        const short int scaling, const shp::Unit& unit, const shp::Volume& volume)
        : name(), parameter(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const shp::Signal& parameter, const shp::Volume& volume)
        : name(), parameter(parameter), volume(volume) {

}

Density::Density(std::string name, const shp::Unit& unit)
        : name(name), parameter(unit), volume() {

}

Density::Density(std::string name, const short int scaling, const shp::Unit& unit)
        : name(name), parameter(scaling, unit), volume() {

}

Density::Density(std::string name, const float parameter)
        : name(name), parameter(parameter, UNIT), volume() {

}

Density::Density(std::string name, const float parameter, const std::string unit)
        : name(name), parameter(parameter, unit), volume() {

}

Density::Density(std::string name, const float parameter,
        const short int scaling, const std::string unit)
        : name(name), parameter(parameter, scaling, unit), volume() {

}

Density::Density(std::string name, const float parameter, const float volume)
        : name(name), parameter(parameter, UNIT) {
	this->setVolume(volume);
}

Density::Density(std::string name, const float parameter, const short int scaling,
        const float volume)
        : name(name), parameter(parameter, scaling, UNIT) {
	this->setVolume(volume);
}

Density::Density(std::string name, const float parameter,
        const std::string unit, const float volume)
        : name(name), parameter(parameter, unit) {
	this->setVolume(volume);
}

Density::Density(std::string name, const float parameter,
        const short int scaling, const std::string unit, const float volume)
        : name(name), parameter(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(std::string name, const float parameter,
        const short int scaling, const shp::Unit& unit, const shp::Volume& volume)
        : name(name), parameter(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(std::string name, const shp::Signal& parameter)
        : name(name), parameter(parameter), volume() {

}

Density::Density(std::string name, const shp::Signal& parameter, const shp::Volume& volume)
        : name(name), parameter(parameter), volume(volume) {

}

Density::~Density() {

}

bool Density::operator==(const Density& peer) const {
    return (parameter == peer.parameter) && (volume == peer.volume);
}

Density Density::operator+(const Density& peer) const {
	shp::Signal newparameter = (parameter + peer.parameter);
    shp::Signal newvolume = (volume.getTotal() + peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("+", newparameter, newvolume);
}

Density Density::operator-(const Density& peer) const {
	shp::Signal newparameter = (parameter - peer.parameter);
    shp::Signal newvolume = (volume.getTotal() - peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("-", newparameter, newvolume);
}

Density Density::operator*(const Density& peer) const {
	shp::Signal newparameter = (parameter * peer.parameter);
    shp::Signal newvolume = (volume.getTotal() * peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("*", newparameter, newvolume);
}

Density Density::operator/(const Density& peer) const {
	shp::Signal newparameter = (parameter / peer.parameter);
    shp::Signal newvolume = (volume.getTotal() / peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("/", newparameter, newvolume);
}

Density Density::operator%(const Density& peer) const {
	shp::Signal newparameter = (parameter % peer.parameter);
    shp::Signal newvolume = (volume.getTotal() % peer.volume.getTotal());
	newvolume.adjustScaling();
    return Density("%", newparameter, newvolume);
}

float Density::getMagnitude() const {
    return parameter.getMagnitude();
}

void Density::setMagnitude(const float value) {
	this->parameter.setMagnitude(value);
}

void Density::setMagnitude(const float value, const short int scale) {
	this->parameter.setMagnitude(value, scale);
}

void Density::setMagnitude(const float value, const short int scale, const std::string unit) {
	this->parameter.setMagnitude(value, scale, unit);
}

short int Density::getScaling() const {
	return parameter.getScaling();
}

void Density::setScaling(const short int scale) {
	this->parameter.setScaling(scale);
}

shp::Unit Density::getUnit() const {
	return parameter.getUnit();
}

void Density::setUnit(const shp::Unit& unit) {
	this->parameter.setUnit(unit);
}

void Density::setVolume(const float value) {
	this->volume = shp::Volume(std::cbrt(value));
}

shp::Signal Density::getTotal() const {
    shp::Signal density = (parameter / volume.getTotal());
    return shp::Signal(density.getMagnitude(), density.getScaling(), density.getUnit());
}

Density Density::copy() {
    Density fresh(name, parameter, volume);
    return fresh;
}

void Density::clear() {
	name.clear();
    parameter.clear();
    volume.clear();
    return;
}

std::string Density::print() {
    std::stringstream result;
    result << "(ρ:";
	result << name << ",";
    result << parameter.print() << ",";
	result << volume.print() << ")";
	return result.str();
}

shp::Signal Density::getCosComponent(const float phase) const {
	shp::Signal density = this->getTotal();
    return shp::Signal(density.getOrientation(),
		density.getCosComponent(phase), density.getScaling(), density.getUnit());
}

shp::Signal Density::getSinComponent(const float phase) const {
	shp::Signal density = this->getTotal();
    return shp::Signal(density.getOrientation(),
		density.getSinComponent(phase), density.getScaling(), density.getUnit());
}

} // namespace qft