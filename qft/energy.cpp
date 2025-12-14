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
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name) : Point(name),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float gradient) : Point(gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float gradient) : Point(name, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient)
        : Point(amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient)
        : Point(name, amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength)
        : Point(amplitude, gradient),
		wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient,
		float wavelength, short int scaling)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(const Mass& mass)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Mass& mass, const shp::Unit& unit)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(const Charge& charge)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Charge& charge, const shp::Unit& unit)
        : Point(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Mass& mass, const shp::Unit& unit)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, const Charge& charge)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const Charge& charge)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float wavelength, const Charge& charge, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Mass& mass,
        const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Charge& charge,
        const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Charge& charge,
        const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Charge& charge, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Charge& charge, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        const Mass& mass, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        const Charge& charge, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Charge& charge)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

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
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Charge& charge, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, float mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Mass& mass, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Charge& charge, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
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
    float amplitude = (getAmplitude() + peer.getAmplitude());
    float gradient = (getGradient() + peer.getGradient());
    shp::Quantity length = (wavelength + peer.wavelength);
    return Energy("+", amplitude, gradient, length.getValue(), length.getScaling(),
            (mass + peer.mass), (charge + peer.charge), unit);
}

Energy Energy::operator-(const Energy& peer) const {
    float amplitude = (getAmplitude() - peer.getAmplitude());
    float gradient = (getGradient() - peer.getGradient());
    shp::Quantity length = (wavelength - peer.wavelength);
    return Energy("-", amplitude, gradient, length.getValue(), length.getScaling(),
            (mass - peer.mass), (charge - peer.charge), unit);
}

Energy Energy::operator*(const Energy& peer) const {
    float amplitude = (getAmplitude() * peer.getAmplitude());
    float gradient = (getGradient() * peer.getGradient());
    shp::Quantity length = (wavelength * peer.wavelength);
    return Energy("*", amplitude, gradient, length.getValue(), length.getScaling(),
            (mass * peer.mass), (charge * peer.charge), unit);
}

Energy Energy::operator/(const Energy& peer) const {
    float amplitude = (getAmplitude() / peer.getAmplitude());
    float gradient = (getGradient() / peer.getGradient());
    shp::Quantity length = (wavelength / peer.wavelength);
    return Energy("/", amplitude, gradient, length.getValue(), length.getScaling(),
            (mass / peer.mass), (charge / peer.charge), unit);
}

Energy Energy::operator%(const Energy& peer) const {
    float amplitude = fmod(getAmplitude(), peer.getAmplitude());
    float gradient = fmod(getGradient(), peer.getGradient());
    shp::Quantity length = (wavelength % peer.wavelength);
    return Energy("%", amplitude, gradient, length.getValue(), length.getScaling(),
            (mass % peer.mass), (charge % peer.charge), unit);
}

shp::Quantity Energy::getTotal() const {
    shp::Quantity potential = getPotential(); potential.adjustScaling();
    shp::Quantity kinetic = getKinetic(); kinetic.adjustScaling();
    short int scaling = (potential.getScaling() - kinetic.getScaling());
    float quantum = (potential.getValue() + (kinetic.getValue() / std::pow(10, scaling)));
    shp::Quantity result(quantum, potential.getScaling(), potential.getUnit());
    result.adjustScaling();
    return result;
}

Density Energy::getDensity(const shp::Volume& volume) const {
    Density result(getTotal(), volume, getUnit());
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
shp::Quantity Energy::getSpatial(float state) const {
    shp::Quantity coefficient(wavelength.getValue(),
            wavelength.getScaling(), wavelength.getUnit());
    float planck = (coefficient.getValue() * Point::getAmplitudeAzimuthal(state));
    shp::Quantity result((getPhysicalLimit().getValue() / planck),
            (PLANCK_SCALE - wavelength.getScaling()), UNIT);
    return result;
}

shp::Quantity Energy::getTemporal(float state) const {
    shp::Quantity coefficient(wavelength.getInverse().getValue(),
            wavelength.getScaling(), wavelength.getUnit());
    float planck = (coefficient.getValue() * Point::getAmplitudeAzimuthal(state));
    shp::Quantity result((getPhysicalLimit().getValue() / planck),
            (PLANCK_SCALE - wavelength.getScaling()), UNIT);
    return result;
}

const shp::Quantity Energy::getPhysicalLimit() {
    shp::Quantity result((PLANCK_CONSTANT / 2), PLANCK_SCALE, UNIT);
    return result;
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
    result << "[E";
	result << Point::print() << ",l:";
    result << wavelength.print() << ",";
    result << mass.print() << ",";
    result << charge.print() << "]";
    result << unit.print();
	return result.str();
}

shp::Quantity Energy::getComponent(float phase) const {
	shp::Quantity energy = getTotal();
	return shp::Quantity((energy.getValue() * cos(phase)), energy.getScaling(), energy.getUnit());
}

} // namespace qft