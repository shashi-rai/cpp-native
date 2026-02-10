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
const float Density::DEFAULT_VOLUME = 1.0f;

Density::Density()
        : shp::Medium(UNIT) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter)
        : shp::Medium(parameter, UNIT) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const shp::Signal& modulation)
        : shp::Medium(parameter, UNIT, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const std::string unit)
        : shp::Medium(parameter, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const shp::Unit& unit)
        : shp::Medium(parameter, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const std::string unit, const shp::Signal& modulation)
        : shp::Medium(parameter, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const shp::Unit& unit, const shp::Signal& modulation)
        : shp::Medium(parameter, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const short int scaling, const std::string unit)
        : shp::Medium(parameter, scaling, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const short int scaling, const shp::Unit& unit)
        : shp::Medium(parameter, scaling, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const short int scaling, const std::string unit,
        const shp::Signal& modulation)
        : shp::Medium(parameter, scaling, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation)
        : shp::Medium(parameter, scaling, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const float parameter, const float volume)
        : shp::Medium(parameter, UNIT) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const shp::Volume& volume)
        : shp::Medium(parameter, UNIT) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const shp::Signal& modulation, const float volume)
        : shp::Medium(parameter, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(parameter, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const float volume)
        : shp::Medium(parameter, scaling, UNIT) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Volume& volume)
        : shp::Medium(parameter, scaling, UNIT) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Signal& modulation,
        const float volume)
        : shp::Medium(parameter, scaling, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Signal& modulation,
        const shp::Volume& volume)
        : shp::Medium(parameter, scaling, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const std::string unit, const float volume)
        : shp::Medium(parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const shp::Unit& unit, const float volume)
        : shp::Medium(parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const std::string unit, const shp::Volume& volume)
        : shp::Medium(parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const shp::Unit& unit, const shp::Volume& volume)
        : shp::Medium(parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const std::string unit, const shp::Signal& modulation,
        const float volume)
        : shp::Medium(parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const std::string unit, const shp::Signal& modulation,
        const shp::Volume& volume)
        : shp::Medium(parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const shp::Unit& unit, const shp::Signal& modulation,
        const shp::Volume& volume)
        : shp::Medium(parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const std::string unit,
        const float volume)
        : shp::Medium(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Unit& unit,
        const float volume)
        : shp::Medium(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const std::string unit,
        const shp::Volume& volume)
        : shp::Medium(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Volume& volume)
        : shp::Medium(parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const std::string unit,
        const shp::Signal& modulation, const float volume)
        : shp::Medium(parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const float volume)
        : shp::Medium(parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const std::string unit,
        const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const shp::Signal& modulation)
        : shp::Medium(modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const shp::Signal& modulation, const float volume)
        : shp::Medium(modulation) {
	this->setVolume(volume);
}

Density::Density(const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name)
        : shp::Medium(name, UNIT) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const std::string unit)
        : shp::Medium(name, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const shp::Unit& unit)
        : shp::Medium(name, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const short int scaling, const std::string unit)
        : shp::Medium(name, scaling, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const short int scaling, const shp::Unit& unit)
        : shp::Medium(name, scaling, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter)
        : shp::Medium(name, parameter, UNIT) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const shp::Signal& modulation)
        : shp::Medium(name, parameter, UNIT, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const std::string unit)
        : shp::Medium(name, parameter, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const shp::Unit& unit)
        : shp::Medium(name, parameter, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const std::string unit,
        const shp::Signal& modulation)
        : shp::Medium(name, parameter, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const shp::Unit& unit,
        const shp::Signal& modulation)
        : shp::Medium(name, parameter, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const std::string unit)
        : shp::Medium(name, parameter, scaling, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit)
        : shp::Medium(name, parameter, scaling, unit) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const std::string unit, const shp::Signal& modulation)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit, const shp::Signal& modulation)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const float parameter, const float volume)
        : shp::Medium(name, parameter, UNIT) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Volume& volume)
        : shp::Medium(name, parameter, UNIT) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Signal& modulation,
        const float volume)
        : shp::Medium(name, parameter, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Signal& modulation,
        const shp::Volume& volume)
        : shp::Medium(name, parameter, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const float volume)
        : shp::Medium(name, parameter, scaling, UNIT) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Volume& volume)
        : shp::Medium(name, parameter, scaling, UNIT) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Signal& modulation, const float volume)
        : shp::Medium(name, parameter, scaling, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(name, parameter, scaling, UNIT, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const std::string unit,
        const float volume)
        : shp::Medium(name, parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Unit& unit,
        const float volume)
        : shp::Medium(name, parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const std::string unit,
        const shp::Volume& volume)
        : shp::Medium(name, parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Unit& unit,
        const shp::Volume& volume)
        : shp::Medium(name, parameter, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const std::string unit,
        const shp::Signal& modulation, const float volume)
        : shp::Medium(name, parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Unit& unit,
        const shp::Signal& modulation, const float volume)
        : shp::Medium(name, parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const std::string unit,
        const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(name, parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(name, parameter, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const std::string unit, const float volume)
        : shp::Medium(name, parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit, const float volume)
        : shp::Medium(name, parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const std::string unit, const shp::Volume& volume)
        : shp::Medium(name, parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit, const shp::Volume& volume)
        : shp::Medium(name, parameter, scaling, unit) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const std::string unit, const shp::Signal& modulation, const float volume)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit, const shp::Signal& modulation, const float volume)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const std::string unit, const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit, const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const float parameter, const short int scaling,
        const shp::Unit& unit, const shp::Signal& modulation, const shp::Signal& volume)
        : shp::Medium(name, parameter, scaling, unit, modulation) {
	this->setVolume(volume);
}

Density::Density(const std::string name, const shp::Signal& modulation)
        : shp::Medium(name, modulation) {
	this->setVolume(DEFAULT_VOLUME);
}

Density::Density(const std::string name, const shp::Signal& modulation, const float volume)
        : shp::Medium(name, modulation) {
	this->setVolume(volume);

}

Density::Density(const std::string name, const shp::Signal& modulation, const shp::Volume& volume)
        : shp::Medium(name, modulation) {
	this->setVolume(volume);
}

Density::~Density() {

}

bool Density::operator==(const Density& peer) const {
    return (static_cast<const shp::Medium&>(*this) == static_cast<const shp::Medium&>(peer))
        && (volume == peer.volume);
}

bool Density::operator<(const Density& peer) const {
    Density self = *this; bool result = false;
    if (static_cast<const shp::Medium&>(*this) < static_cast<const shp::Medium&>(peer)) {
        result = true;
    } else if (volume < peer.volume) {
        result = true;
    }
    return result;
}

bool Density::operator>(const Density& peer) const {
    Density self = *this; bool result = false;
    if (static_cast<const shp::Medium&>(*this) > static_cast<const shp::Medium&>(peer)) {
        result = true;
    } else if (volume > peer.volume) {
        result = true;
    }
    return result;
}

bool Density::operator<=(const Density& peer) const {
    Density self = *this;
    return (self < peer) || (self == peer);
}

bool Density::operator>=(const Density& peer) const {
    Density self = *this;
    return (self > peer) || (self == peer);
}

Density Density::operator+(const Density& peer) const {
    Density self = *this, other = peer; shp::Medium medium = (self + other);
    shp::Signal density = medium.getParameter().getVectorTotal();
	shp::Signal newIntrinsic = (self.getIntrinsic() + peer.getIntrinsic());
    shp::Signal newVolume = (volume.getRealScalar() + peer.volume.getRealScalar());
	newVolume.adjustScaling();
    return Density("+", density.getMagnitude(), density.getScaling(), density.getUnit(), 
		newIntrinsic, newVolume);
}

Density Density::operator-(const Density& peer) const {
    Density self = *this, other = peer; shp::Medium medium = (self - other);
    shp::Signal density = medium.getParameter().getVectorTotal();
	shp::Signal newIntrinsic = (self.getIntrinsic() - peer.getIntrinsic());
    shp::Signal newVolume = (volume.getRealScalar() - peer.volume.getRealScalar());
	newVolume.adjustScaling();
    return Density("-", density.getMagnitude(), density.getScaling(), density.getUnit(),
		newIntrinsic, newVolume);
}

Density Density::operator*(const Density& peer) const {
    Density self = *this, other = peer; shp::Medium medium = (self * other);
    shp::Signal density = medium.getParameter().getVectorTotal();
	shp::Signal newIntrinsic = (self.getIntrinsic() * peer.getIntrinsic());
    shp::Signal newVolume = (volume.getRealScalar() * peer.volume.getRealScalar());
	newVolume.adjustScaling();
    return Density("*", density.getMagnitude(), density.getScaling(), density.getUnit(),
		newIntrinsic, newVolume);
}

Density Density::operator/(const Density& peer) const {
    Density self = *this, other = peer; shp::Medium medium = (self / other);
    shp::Signal density = medium.getParameter().getVectorTotal();
	shp::Signal newIntrinsic = (self.getIntrinsic() / peer.getIntrinsic());
    shp::Signal newVolume = (volume.getRealScalar() / peer.volume.getRealScalar());
	newVolume.adjustScaling();
    return Density("/", density.getMagnitude(), density.getScaling(), density.getUnit(),
		newIntrinsic, newVolume);
}

Density Density::operator%(const Density& peer) const {
    Density self = *this, other = peer; shp::Medium medium = (self % other);
    shp::Signal density = medium.getParameter().getVectorTotal();
	shp::Signal newIntrinsic = (self.getIntrinsic() % peer.getIntrinsic());
    shp::Signal newVolume = (volume.getRealScalar() % peer.volume.getRealScalar());
	newVolume.adjustScaling();
    return Density("%", density.getMagnitude(), density.getScaling(), density.getUnit(),
		newIntrinsic, newVolume);
}

std::string Density::getName() const {
    return shp::Medium::getName();
}

void Density::setName(const std::string name) {
    shp::Medium::setName(name);
}

shp::Area Density::getArea() const {
    return this->volume.getSurface();
}

void Density::setArea(const shp::Area& planar) {
    this->volume.setSurface(planar.getLength(), planar.getBreadth());
}

void Density::setArea(const shp::Distance& length, const shp::Distance& breadth) {
    this->volume.setSurface(length, breadth);
}

void Density::setArea(const float length, const float breadth) {
    this->volume.setSurface(length, breadth);
}

void Density::setArea(const float length, const float breadth, const short int scale) {
    this->volume.setSurface(length, breadth, scale);
}

void Density::setArea(const float length, const float breadth, const short int scale, const std::string unit) {
    this->volume.setSurface(length, breadth, scale, unit);
}

void Density::setArea(const float length, const float breadth, const short int scale, const shp::Unit& unit) {
    this->volume.setSurface(length, breadth, scale, unit);
}

shp::Distance Density::getHeight() const {
	return this->volume.getHeight();
}

void Density::setHeight(const shp::Distance& height) {
	this->volume.setHeight(height);
}

void Density::setHeight(const float height) {
	this->volume.setHeight(height);
}

void Density::setHeight(const float height, const short int scale) {
	this->volume.setHeight(height, scale);
}

void Density::setHeight(const float height, const short int scale, const std::string unit) {
	this->volume.setHeight(height, scale, unit);
}

void Density::setHeight(const float height, const short int scale, const shp::Unit& unit) {
	this->volume.setHeight(height, scale, unit);
}

void Density::setVolume(const shp::Signal& signal) {
	this->volume.setMagnitude(signal);
}

shp::Direction Density::getParameterDiffusion() const {
    return shp::Medium::getDiffusionCurrent();
}

void Density::setParameterDiffusion(const float factor) {
    shp::Medium::setDiffusionFactor(factor);
}

void Density::setParameterDiffusion(const shp::Intrinsic& rate) {
    shp::Medium::setDiffusionFactor(rate);
}

shp::Direction Density::getParameterThreshold() const {
    return shp::Medium::getThresholdShift();
}

void Density::setParameterThreshold(const float factor) {
    shp::Medium::setThresholdShift(factor);
}

void Density::setParameterThreshold(const shp::Polar& factor) {
    shp::Medium::setThresholdShift(factor);
}

shp::Signal Density::getThermalFactor() const {
    return shp::Medium::getIntrinsic();
}

void Density::setThermalFactor(const shp::Signal& temperature) {
    shp::Medium::setTransform(temperature);
}

shp::Signal Density::getScalarThermalDrift() {
    return shp::Medium::getScalarFieldDrift();
}

shp::Signal Density::getScalarThermalTotal() {
    return shp::Medium::getScalarFieldTotal();
}

shp::Signal Density::getThermalFieldDrift() {
    return shp::Medium::getVectorFieldDrift();
}

shp::Signal Density::getThermalFieldTotal() {
    return shp::Medium::getVectorFieldTotal();
}

float Density::getAmplitude() const {
    return shp::Medium::getAmplitude();
}

float Density::getMagnitude() const {
    return shp::Medium::getMagnitude();
}

void Density::setMagnitude(const float value) {
	shp::Medium::setMagnitude(value);
}

void Density::setMagnitude(const float value, const short int scale) {
	shp::Medium::setMagnitude(value, scale);
}

void Density::setMagnitude(const float value, const short int scale, const std::string unit) {
	shp::Medium::setMagnitude(value, scale, unit);
}

void Density::setMagnitude(const float value, const short int scale, const shp::Unit& unit) {
	shp::Medium::setMagnitude(value, scale, unit);
}

short int Density::getScaling() const {
	return shp::Medium::getScaling();
}

void Density::setScaling(const short int scale) {
	shp::Medium::setScaling(scale);
}

shp::Unit Density::getUnit() const {
	return shp::Medium::getUnit();
}

void Density::setUnit(const shp::Unit& unit) {
	shp::Medium::setUnit(unit);
}

void Density::setVolume(const float value) {
	this->volume = shp::Volume(std::cbrt(value));
}

void Density::setVolume(const float value, const short int scale) {
    float magnitude = (value * std::pow(shp::Quantity::DECIMAL_SCALE, scale));
	this->volume = shp::Volume(std::cbrt(magnitude));
}

void Density::setChangeLength(const float value) {
	this->volume.setLength(value);
}

void Density::setChangeLength(const float value, const short int scale) {
	this->volume.setLength(value, scale);
}

void Density::setChangeLength(const float value, const short int scale, const std::string unit) {
	this->volume.setLength(value, scale, unit);
}

void Density::setChangeLength(const float value, const short int scale, const shp::Unit& unit) {
	this->volume.setLength(value, scale, unit);
}

void Density::setChangeLengthPhase(const float direction) {
	this->volume.setLengthPhase(direction);
}

void Density::setChangeLengthPhase(const shp::Intrinsic& orientation) {
	this->volume.setLengthPhase(orientation);
}

void Density::setChangeBreadth(const float value) {
	this->volume.setBreadth(value);
}

void Density::setChangeBreadth(const float value, const short int scale) {
	this->volume.setBreadth(value, scale);
}

void Density::setChangeBreadth(const float value, const short int scale, const std::string unit) {
	this->volume.setBreadth(value, scale, unit);
}

void Density::setChangeBreadth(const float value, const short int scale, const shp::Unit& unit) {
	this->volume.setBreadth(value, scale, unit);
}

void Density::setChangeBreadthPhase(const float direction) {
	this->volume.setBreadthPhase(direction);
}

void Density::setChangeBreadthPhase(const shp::Intrinsic& orientation) {
	this->volume.setBreadthPhase(orientation);
}

void Density::setChangeHeight(const float value) {
	this->volume.setHeight(value);
}

void Density::setChangeHeight(const float value, const short int scale) {
	this->volume.setHeight(value, scale);
}

void Density::setChangeHeight(const float value, const short int scale, const std::string unit) {
	this->volume.setHeight(value, scale, unit);
}

void Density::setChangeHeight(const float value, const short int scale, const shp::Unit& unit) {
	this->volume.setHeight(value, scale, unit);
}

void Density::setChangeHeightPhase(const float direction) {
	this->volume.setHeightPhase(direction);
}

void Density::setChangeHeightPhase(const shp::Intrinsic& orientation) {
	this->volume.setHeightPhase(orientation);
}

shp::Signal Density::getScalarFlux() const {
    shp::Signal density = (shp::Medium::getScalarTotal() / volume.getRealScalar());
    return shp::Signal(density.getMagnitude(), density.getScaling(), density.getUnit());
}

shp::Signal Density::getVectorFlux() const {
    shp::Signal density = (shp::Medium::getVectorTotal() / volume.getRealVector());
    return shp::Signal(density.getMagnitude(), density.getScaling(), density.getUnit());
}

Density Density::copy() {
    Density self = *this; shp::Distance parameter = shp::Medium::getParameter();
    Density fresh(shp::Medium::getName(),
		parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
		shp::Medium::getTransform(), this->volume);
    return fresh;
}

void Density::clear() {
	shp::Medium::clear();
    volume.clear();
    return;
}

std::string Density::print() const {
    std::stringstream result;
    result << "(ρ:";
	result << shp::Medium::print() << ",";
	result << volume.print() << ")";
	return result.str();
}

std::string Density::printRadians() const {
    std::stringstream result;
    result << "(ρ:";
	result << shp::Medium::printRadians() << ",";
	result << volume.printRadians() << ")";
	return result.str();
}

shp::Signal Density::getCosComponent(const float phase) const {
	shp::Signal density = this->getScalarTotal();
    return shp::Signal(density.getOrientation(),
		density.getCosComponent(phase), density.getScaling(), density.getUnit());
}

shp::Signal Density::getSinComponent(const float phase) const {
	shp::Signal density = this->getScalarTotal();
    return shp::Signal(density.getOrientation(),
		density.getSinComponent(phase), density.getScaling(), density.getUnit());
}

} // namespace qft