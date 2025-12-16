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
const float Energy::ELECTRON_VOLT = 1.602176634f;   // 1.602176634f J
const short int Energy::EV_SCALE = -19;             // 10^-19 J
const short int Energy::MEV_SCALE = -13;            // 10^-13 J
const short int Energy::GEV_SCALE = -10;            // 10^-10 J
const short int Energy::TEV_SCALE = -7;             // 10^-7 J
const float Energy::LIGHT_SPEED = 2.99792458;       // 2.99792458 x 10^8 m/s
const short int Energy::LIGHT_SCALE = 8;            // 10^8 m/s

Energy::Energy() : Phase(),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name) : Phase(name),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float gradient) : Phase(gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float gradient) : Phase(name, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient)
        : Phase(amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient)
        : Phase(name, amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength)
        : Phase(amplitude, gradient),
		wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling)
        : Phase(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient,
		float wavelength, short int scaling)
        : Phase(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE),
        charge(shp::Quantity::DEFAULT_VALUE), unit(unit) {

}

Energy::Energy(const Mass& mass)
        : Phase(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Mass& mass, const shp::Unit& unit)
        : Phase(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(const Charge& charge)
        : Phase(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Charge& charge, const shp::Unit& unit)
        : Phase(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(const Mass& mass, const Charge& charge)
        : Phase(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Phase(), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, const Mass& mass, const Charge& charge)
        : Phase(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Phase(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, const Mass& mass)
        : Phase(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Mass& mass, const shp::Unit& unit)
        : Phase(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, const Charge& charge)
        : Phase(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, const Charge& charge, const shp::Unit& unit)
        : Phase(name), wavelength(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const Charge& charge)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, const Mass& mass, const Charge& charge)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float wavelength, float mass, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float wavelength, const Charge& charge, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, const Mass& mass, const Charge& charge,
        const shp::Unit& unit)
        : Phase(), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, float mass, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Mass& mass,
        const shp::Unit& unit)
        : Phase(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Charge& charge,
        const shp::Unit& unit)
        : Phase(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(float wavelength, short int scaling, const Mass& mass,
        const Charge& charge, const shp::Unit& unit)
        : Phase(), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, float mass,
        const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Charge& charge,
        const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const Charge& charge)
        : Phase(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float wavelength, const Mass& mass,
        const Charge& charge, const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		float mass, const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Charge& charge, const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const Charge& charge)
        : Phase(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Phase(name), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        float mass, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Charge& charge, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge)
        : Phase(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        float mass, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        const Mass& mass, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        const Charge& charge, const shp::Unit& unit)
        : Phase(amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Charge& charge)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        short int scaling, const Mass& mass, const Charge& charge)
        : Phase(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge),
        unit(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        float mass, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Mass& mass, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        const Charge& charge, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, float mass, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Mass& mass, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(shp::Quantity::DEFAULT_VALUE),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Charge& charge, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(shp::Quantity::DEFAULT_VALUE), charge(charge),
        unit(unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling, const Mass& mass, const Charge& charge, const shp::Unit& unit)
        : Phase(name, amplitude, gradient), wavelength(wavelength, scaling,
            shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        mass(mass), charge(charge), unit(unit) {

}

Energy::~Energy() {

}

bool Energy::operator==(const Energy& peer) const {
    return (static_cast<const Phase&>(*this) == static_cast<const Phase&>(peer))
        && (wavelength == peer.wavelength)
        && (mass == peer.mass)
        && (charge == peer.charge);
}

Energy Energy::operator+(const Energy& peer) const {
    float amplitude = (getAmplitude() + peer.getAmplitude());
    float gradient = (getGradient() + peer.getGradient());
    float planck_phase = (getPolarization() + peer.getPolarization());
    shp::Distance planck_wave = (wavelength + peer.wavelength);
    shp::Quantity length = planck_wave.getMagnitude(); length.adjustScaling();
    Energy result("+", amplitude, gradient, length.getValue(), planck_wave.getScaling(),
            (mass + peer.mass), (charge + peer.charge), unit);
    result.setPolarization(planck_phase);
    return result;
}

Energy Energy::operator-(const Energy& peer) const {
    float amplitude = (getAmplitude() - peer.getAmplitude());
    float gradient = (getGradient() - peer.getGradient());
    float planck_phase = (getPolarization() - peer.getPolarization());
    shp::Distance planck_wave = (wavelength - peer.wavelength);
    shp::Quantity length = planck_wave.getMagnitude(); length.adjustScaling();
    Energy result("-", amplitude, gradient, length.getValue(), planck_wave.getScaling(),
            (mass - peer.mass), (charge - peer.charge), unit);
    result.setPolarization(planck_phase);
    return result;
}

Energy Energy::operator*(const Energy& peer) const {
    float amplitude = (getAmplitude() * peer.getAmplitude());
    float gradient = (getGradient() * peer.getGradient());
    float planck_phase = (getPolarization() * peer.getPolarization());
    shp::Distance planck_wave = (wavelength * peer.wavelength);
    shp::Quantity length = planck_wave.getMagnitude(); length.adjustScaling();
    Energy result("*", amplitude, gradient, length.getValue(), planck_wave.getScaling(),
            (mass * peer.mass), (charge * peer.charge), unit);
    result.setPolarization(planck_phase);
    return result;
}

Energy Energy::operator/(const Energy& peer) const {
    float amplitude = (getAmplitude() / peer.getAmplitude());
    float gradient = (getGradient() / peer.getGradient());
    float planck_phase = (getPolarization() / peer.getPolarization());
    shp::Distance planck_wave = (wavelength / peer.wavelength);
    shp::Quantity length = planck_wave.getMagnitude(); length.adjustScaling();
    Energy result("/", amplitude, gradient, length.getValue(), planck_wave.getScaling(),
            (mass / peer.mass), (charge / peer.charge), unit);
    result.setPolarization(planck_phase);
    return result;
}

Energy Energy::operator%(const Energy& peer) const {
    float amplitude = fmod(getAmplitude(), peer.getAmplitude());
    float gradient = fmod(getGradient(), peer.getGradient());
    float planck_phase = fmod(getPolarization(), peer.getPolarization());
    shp::Distance planck_wave = (wavelength % peer.wavelength);
    shp::Quantity length = planck_wave.getMagnitude(); length.adjustScaling();
    Energy result("%", amplitude, gradient, length.getValue(), planck_wave.getScaling(),
            (mass % peer.mass), (charge % peer.charge), unit);
    result.setPolarization(planck_phase);
    return result;
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
    float energy = (mass.getMagnitude() * (speed_of_light * speed_of_light)).getValue();
	shp::Quantity result(energy, ((LIGHT_SCALE * 2) + mass.getMagnitude().getScaling()), unit);
    result.adjustScaling();
    return result;
}

shp::Quantity Energy::getKinetic() const {
    shp::Quantity frequency = getFrequency();
    float energy = (PLANCK_CONSTANT * frequency.getValue());
    shp::Quantity result(energy, (PLANCK_SCALE + frequency.getScaling()), unit);
    result.adjustScaling();
    return result;
}

shp::Quantity Energy::getFrequency() const {
    shp::Quantity result = wavelength.getMagnitude().getInverse();
    result.setScaling((0 - wavelength.getScaling()));
    result.setUnit(shp::Unit::getDerivedSymbol(shp::Unit::FREQUENCY));
    result.adjustScaling();
    return result;;
}

/*
 * Wavelength refers to the distance that Energy could traverse in one cycle
 * At a given point in space, no Planckian Energy exists if wavelength is zero
 */
shp::Distance Energy::getDivergence(const float modulation) const {
    shp::Quantity lambda(wavelength.getMagnitude().getValue(),
            wavelength.getScaling(), wavelength.getUnit());
    float coefficient = (lambda.getValue() * Phase::getAmplitudeAzimuthal(modulation));
    shp::Quantity delta((getPhysicalLimit().getValue() / coefficient),
            (lambda.getScaling() - PLANCK_SCALE), shp::Unit::getBaseSymbol(shp::Unit::LENGTH));
    delta.adjustScaling();
    return shp::Distance(delta.getValue(), delta.getScaling(), delta.getUnit());
}

qft::Time Energy::getPerpetuity(const float modulation) const {
    shp::Quantity frequency = getFrequency();
    float coefficient = (frequency.getValue() * Phase::getAmplitudePolarization(modulation));
    shp::Quantity delta((getPhysicalLimit().getValue() / coefficient),
            (frequency.getScaling() - PLANCK_SCALE), shp::Unit::getBaseSymbol(shp::Unit::TIME));
    delta.adjustScaling();
    return qft::Time(delta.getValue(), delta.getScaling(), delta.getUnit());
}

const shp::Quantity Energy::getPhysicalLimit() {
    shp::Quantity result((PLANCK_CONSTANT / 2), PLANCK_SCALE, UNIT);
    return result;
}

const shp::Quantity Energy:: getElectronvolt(const float quantum) {
    shp::Quantity result((ELECTRON_VOLT * quantum), EV_SCALE, UNIT);
    return result;
}

const shp::Quantity Energy:: getMegaElectronvolt(const float quantum) {
    shp::Quantity result((ELECTRON_VOLT * quantum), MEV_SCALE, UNIT);
    return result;
}

const shp::Quantity Energy:: getGigaElectronvolt(const float quantum) {
    shp::Quantity result((ELECTRON_VOLT * quantum), GEV_SCALE, UNIT);
    return result;
}

const shp::Quantity Energy:: getTeraElectronvolt(const float quantum) {
    shp::Quantity result((ELECTRON_VOLT * quantum), TEV_SCALE, UNIT);
    return result;
}

shp::Point Energy::copy() {
    Energy fresh(wavelength.getMagnitude().getValue(),
            mass.getMagnitude().getValue(), charge.getMagnitude().getValue(), getUnit());
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
	result << Phase::print() << ",";
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