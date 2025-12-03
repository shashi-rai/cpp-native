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

const std::string Energy::UNIT = "J";        		// System International
const float Energy::PLANCK_CONSTANT = 6.62607015f;  // 6.62607015 x 10^-34 m^2 kg/s
const short int Energy::PLANCK_SCALE = -34;         // 10^-34 m^2 kg/s

Energy::Energy() : Point(),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(float gradient) : Point(gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(std::string name, float gradient) : Point(name, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(float amplitude, float gradient)
        : Point(amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(std::string name, float amplitude, float gradient)
        : Point(name, amplitude, gradient),
		wavelength(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(float amplitude, float gradient, float wavelength)
        : Point(amplitude, gradient),
		wavelength(wavelength, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling)
        : Point(amplitude, gradient), wavelength(wavelength, scaling),
		kinetic(shp::Quantity::DEFAULT_VALUE, scaling),
		potential(shp::Quantity::DEFAULT_VALUE, scaling) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE) {

}

Energy::Energy(std::string name, float amplitude, float gradient,
		float wavelength, short int scaling)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling),
		kinetic(shp::Quantity::DEFAULT_VALUE, scaling),
		potential(shp::Quantity::DEFAULT_VALUE, scaling) {

}

Energy::Energy(float wavelength, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE, unit),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE, unit) {

}

Energy::Energy(float wavelength, short int scaling, const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling),
		kinetic(shp::Quantity::DEFAULT_VALUE, scaling, unit),
		potential(shp::Quantity::DEFAULT_VALUE, scaling, unit) {

}

Energy::Energy(std::string name, float wavelength, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE),
		kinetic(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE, unit),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE, unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling),
		kinetic(shp::Quantity::DEFAULT_VALUE, scaling, unit),
		potential(shp::Quantity::DEFAULT_VALUE, scaling, unit) {

}

Energy::Energy(float wavelength, float kinetic, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE),
		kinetic(kinetic, PLANCK_SCALE, unit),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE, unit) {

}

Energy::Energy(float wavelength, short int scaling, float kinetic, const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling),
		kinetic(kinetic, scaling, unit),
		potential(shp::Quantity::DEFAULT_VALUE, scaling, unit) {

}

Energy::Energy(std::string name, float wavelength, float kinetic, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE),
		kinetic(kinetic, PLANCK_SCALE, unit),
		potential(shp::Quantity::DEFAULT_VALUE, PLANCK_SCALE, unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		float kinetic, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling),
		kinetic(kinetic, scaling, unit),
		potential(shp::Quantity::DEFAULT_VALUE, scaling, unit) {

}

Energy::Energy(float wavelength, float kinetic, float potential, const shp::Unit& unit)
        : Point(), wavelength(wavelength, PLANCK_SCALE),
		kinetic(kinetic, PLANCK_SCALE, unit), potential(potential, PLANCK_SCALE, unit) {

}

Energy::Energy(float wavelength, short int scaling, float kinetic, float potential,
		const shp::Unit& unit)
        : Point(), wavelength(wavelength, scaling),
		kinetic(kinetic, scaling, unit), potential(potential, scaling, unit) {

}

Energy::Energy(std::string name, float wavelength, float kinetic, float potential,
		const shp::Unit& unit)
        : Point(name), wavelength(wavelength, PLANCK_SCALE),
		kinetic(kinetic, PLANCK_SCALE, unit), potential(potential, PLANCK_SCALE, unit) {

}

Energy::Energy(std::string name, float wavelength, short int scaling,
		float kinetic, float potential, const shp::Unit& unit)
        : Point(name), wavelength(wavelength, scaling),
		kinetic(kinetic, scaling, unit), potential(potential, scaling, unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength,
        float kinetic, float potential, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, PLANCK_SCALE),
        kinetic(kinetic, PLANCK_SCALE, unit), potential(potential, PLANCK_SCALE, unit) {

}

Energy::Energy(float amplitude, float gradient, float wavelength, short int scaling,
        float kinetic, float potential, const shp::Unit& unit)
        : Point(amplitude, gradient), wavelength(wavelength, scaling),
        kinetic(kinetic, scaling, unit), potential(potential, scaling, unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
        float kinetic, float potential, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, PLANCK_SCALE),
        kinetic(kinetic, PLANCK_SCALE, unit), potential(potential, PLANCK_SCALE, unit) {

}

Energy::Energy(std::string name, float amplitude, float gradient, float wavelength,
		short int scaling,
        float kinetic, float potential, const shp::Unit& unit)
        : Point(name, amplitude, gradient), wavelength(wavelength, scaling),
        kinetic(kinetic, scaling, unit), potential(potential, scaling, unit) {

}

Energy::~Energy() {

}

bool Energy::operator==(const Energy& peer) const {
    return (wavelength == peer.wavelength) &&
            (kinetic == peer.kinetic) &&
            (potential == peer.potential);
}

Energy Energy::operator+(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((wavelength + peer.wavelength).getValue(),
            (kinetic + peer.kinetic).getValue(),
            (potential + peer.potential).getValue(), newunit);
}

Energy Energy::operator-(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((wavelength - peer.wavelength).getValue(),
            (kinetic - peer.kinetic).getValue(),
            (potential - peer.potential).getValue(), newunit);
}

Energy Energy::operator*(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((wavelength * peer.wavelength).getValue(),
            (kinetic * peer.kinetic).getValue(),
            (potential * peer.potential).getValue(), newunit);
}

Energy Energy::operator/(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((wavelength / peer.wavelength).getValue(),
            (kinetic / peer.kinetic).getValue(),
            (potential / peer.potential).getValue(), newunit);
}

Energy Energy::operator%(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((wavelength % peer.wavelength).getValue(),
            (kinetic % peer.kinetic).getValue(),
            (potential % peer.potential).getValue(), newunit);
}

shp::Quantity Energy::getQuantum() const {
	shp::Quantity result(PLANCK_CONSTANT * getFrequency().getValue(), PLANCK_SCALE);
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
    Energy fresh(wavelength.getValue(),
        kinetic.getValue(), potential.getValue(), kinetic.getUnit());
    return fresh;
}

void Energy::clear() {
    wavelength.clear();
    kinetic.clear();
    potential.clear();
    return;
}

std::string Energy::print() {
    std::stringstream result;
    result << "[";
	result << Point::print() << ",l:";
    result << wavelength.print() << ",k:";
    result << kinetic.print() << ",p:";
    result << potential.print() << "]";
	return result.str();
}

} // namespace qft