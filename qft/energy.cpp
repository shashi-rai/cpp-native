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

#include "energy.h"

namespace qft {

const std::string Energy::UNIT = "J";               // System International
const float Energy::PLANCK_CONSTANT = 6.62607015f;  // 6.62607015 x 10^-34 m^2 kg/s
const short int Energy::PLANCK_SCALE = -34;         // 10^-34 m^2 kg/s
const float Energy::LIGHT_SPEED = 2.99792458;       // 2.99792458 x 10^8 m/s
const short int Energy::LIGHT_SCALE = 8;            // 10^8 m/s

Energy::Energy() : Point(),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name) : Point(name),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float gradient) : Point(gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float gradient) : Point(name, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient)
        : Point(amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient)
        : Point(name, amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength)
        : Point(amplitude, gradient),
		wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient,
		float wavelength, short int scaling)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), unit(unit) {

}

Energy::Energy(const Mass& mass)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Mass& mass, const shp::Unit& unit)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(const Charge& charge)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Charge& charge, const shp::Unit& unit)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(const Mass& mass, const Charge& charge)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, const Mass& mass, const Charge& charge)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, const Mass& mass)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Mass& mass, const shp::Unit& unit)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, const Charge& charge)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const Charge& charge)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const Mass& mass, const Charge& charge)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, float mass, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float wavelength, const Charge& charge, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass, const Charge& charge,
        const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, float mass, const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Mass& mass,
        const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Charge& charge,
        const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Mass& mass,
        const Charge& charge, const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, float mass,
        const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Charge& charge,
        const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const Charge& charge)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		float mass, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const Charge& charge)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        float mass, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Charge& charge, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        float mass, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        const Mass& mass, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        const Charge& charge, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        float mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Charge& charge, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, float mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass, PLANCK_SCALE), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Mass& mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Charge& charge, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::~Energy() {

}

bool Energy::operator==(const Energy& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (wavelength == peer.wavelength)
        && (mass == peer.mass)
        && (charge == peer.charge);
}

Energy Energy::operator+(const Energy& peer) const {
    return Energy("+", (wavelength + peer.wavelength).getValue(),
            (mass + peer.mass), (charge + peer.charge), unit);
}

Energy Energy::operator-(const Energy& peer) const {
    return Energy("-", (wavelength - peer.wavelength).getValue(),
            (mass - peer.mass), (charge - peer.charge), unit);
}

Energy Energy::operator*(const Energy& peer) const {
    return Energy("*", (wavelength * peer.wavelength).getValue(),
            (mass * peer.mass), (charge * peer.charge), unit);
}

Energy Energy::operator/(const Energy& peer) const {
    return Energy("/", (wavelength / peer.wavelength).getValue(),
            (mass / peer.mass), (charge / peer.charge), unit);
}

Energy Energy::operator%(const Energy& peer) const {
    return Energy("%", (wavelength % peer.wavelength).getValue(),
            (mass % peer.mass), (charge % peer.charge), unit);
}

float Energy::getTotal() const {
    float result = (getKinetic() + getPotential()).getValue();
    return result;
}

Density Energy::getDensity(const float volume) const {
    Density result(getTotal(), volume, getUnit().getName());
    return result;
}

shp::Quantity Energy::getPotential() const {
    shp::Quantity speed_of_light(LIGHT_SPEED, LIGHT_SCALE);
    float energy = (mass.getQuantity() * (speed_of_light * speed_of_light)).getValue();
	shp::Quantity result(energy, ((LIGHT_SCALE * 2) + mass.getQuantity().getScaling()), unit);
    return result;
}

shp::Quantity Energy::getKinetic() const {
	shp::Quantity result(PLANCK_CONSTANT * getFrequency().getValue(), PLANCK_SCALE, unit);
    return result;
}

shp::Quantity Energy::getFrequency() const {
    return wavelength.getInverse();
}

/*
 * Wavelength refers to the distance that Energy could traverse in one cycle
 * At a given point in space, no Planckian Energy exists if wavelength is zero
 */
float Energy::getSpatial(float state) const {
    float planckian = wavelength.getValue();
    return (getPhysicalLimit() / (planckian * Point::getAmplitudeAzimuthal(state)));
}

float Energy::getTemporal(float state) const {
    float planckian = wavelength.getInverse().getValue();
    return getPhysicalLimit() / (planckian * Point::getAmplitudeAzimuthal(state));
}

const float Energy::getPhysicalLimit() {
    return PLANCK_CONSTANT / 2;
}

shp::Point Energy::copy() {
    Energy fresh(wavelength.getValue(), mass.getQuantity().getValue(),
            charge.getQuantity().getValue(), getUnit());
    return fresh;
}

void Energy::clear() {
    wavelength.clear();
    mass.clear();
    charge.clear();
    unit.clear();
    return;
}

std::string Energy::print() {
    std::stringstream result;
    result << "[";
	result << Point::print() << ",l:";
    result << wavelength.print() << ",";
    result << mass.print() << ",";
    result << charge.print();
    result << unit.print() << "]";
	return result.str();
}

float Energy::getComponent(float phase) const {
    return getTotal() * cos(phase);
}

} // namespace qft