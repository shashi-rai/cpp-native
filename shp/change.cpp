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

#include "change.h"

namespace shp {

Change::Change() : gradient(),
	kinetic(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
	potential(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient)
		: gradient(gradient),
		kinetic(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, short int scaling)
        : gradient(gradient),
		kinetic(scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, short int scaling, std::string unit)
        : gradient(gradient),
		kinetic(scaling, unit), potential(scaling, unit) {

}

Change::Change(const float gradient, short int scaling, const Unit& unit)
        : gradient(gradient),
		kinetic(scaling, unit), potential(scaling, unit) {

}

Change::Change(const Direction& gradient)
        : gradient(gradient),
		kinetic(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, const float potential)
        : gradient(gradient),
		kinetic(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, const float potential, short int scaling)
        : gradient(gradient),
		kinetic(scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, const float potential, short int scaling, std::string unit)
        : gradient(gradient), kinetic(scaling, unit), potential(potential, scaling, unit) {

}

Change::Change(const float gradient, const float potential, short int scaling, const Unit& unit)
        : gradient(gradient), kinetic(scaling, unit), potential(potential, scaling, unit) {

}

Change::Change(const Quantity& potential)
        : gradient(),
		kinetic(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)), potential(potential) {

}

Change::Change(const Quantity& kinetic, const Quantity& potential)
        : gradient(), kinetic(kinetic), potential(potential) {

}

Change::Change(const Direction& gradient, const Quantity& potential)
        : gradient(gradient),
		kinetic(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)), potential(potential) {

}

Change::Change(const Direction& gradient, const Quantity& kinetic, const Quantity& potential)
        : gradient(gradient), kinetic(kinetic), potential(potential) {

}

Change::Change(const float gradient, const float kinetic, const float potential)
        : gradient(gradient),
		kinetic(kinetic, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, const float kinetic, const float potential, short int scaling)
        : gradient(gradient),
		kinetic(kinetic, scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float gradient, const float kinetic, const float potential, short int scaling, std::string unit)
        : gradient(gradient), kinetic(kinetic, scaling, unit), potential(potential, scaling, unit) {

}

Change::Change(const float gradient, const float kinetic, const float potential, short int scaling, const Unit& unit)
        : gradient(gradient), kinetic(kinetic, scaling, unit), potential(potential, scaling, unit) {

}

Change::~Change() {

}

bool Change::operator==(const Change& peer) const {
    return (gradient == peer.gradient)
        && (kinetic == peer.kinetic)
        && (potential == peer.potential);
}

Change Change::operator+(const Change& peer) const {
    return Change((gradient + peer.gradient),
            (kinetic + peer.kinetic), (potential + peer.potential));
}

Change Change::operator-(const Change& peer) const {
    return Change((gradient - peer.gradient),
            (kinetic - peer.kinetic), (potential - peer.potential));
}

Change Change::operator*(const Change& peer) const {
    return Change((gradient * peer.gradient),
            (kinetic * peer.kinetic), (potential * peer.potential));
}

Change Change::operator/(const Change& peer) const {
    return Change((gradient / peer.gradient),
            (kinetic / peer.kinetic), (potential / peer.potential));
}

Change Change::operator%(const Change& peer) const {
    return Change((gradient % peer.gradient),
            (kinetic % peer.kinetic), (potential % peer.potential));
}

float Change::toRadians() const {
    return gradient.toRadians();
}

shp::Quantity Change::getLagrangian() const {
    Quantity difference = (kinetic - potential); difference.adjustScaling();
    return Quantity(difference.getValue(), difference.getScaling(), difference.getUnit());
}

shp::Quantity Change::getHamiltonian() const {
    Quantity sumtotal = (kinetic + potential); sumtotal.adjustScaling();
    return Quantity(sumtotal.getValue(), sumtotal.getScaling(), sumtotal.getUnit());
}

float Change::leastAction() {
    float hamiltonian = getHamiltonian().getValue();
    float lagrangian = getLagrangian().getValue();
    float conversion = (lagrangian * cos(gradient.toRadians()));
    kinetic.setValue((hamiltonian * conversion));
    potential.setValue((hamiltonian * (1 - conversion)));
    return conversion;
}

Change Change::copy() {
    Change fresh(gradient, kinetic, potential);
    return fresh;
}

void Change::clear() {
    kinetic.clear();
    potential.clear();
    gradient.clear();
    return;
}

std::string Change::print() {
    std::stringstream result;
    result << "T:";
    result << kinetic.print() << ",U:";
	result << potential.print() << ",";
	result << gradient.print();
	return result.str();
}

} // namespace shp