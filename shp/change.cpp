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

Change::Change() : rate(),
	dynamical(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
	potential(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate)
		: rate(rate),
		dynamical(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, short int scaling)
        : rate(rate),
		dynamical(scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, short int scaling, std::string unit)
        : rate(rate),
		dynamical(scaling, unit), potential(scaling, unit) {

}

Change::Change(const float rate, short int scaling, const Unit& unit)
        : rate(rate),
		dynamical(scaling, unit), potential(scaling, unit) {

}

Change::Change(const Direction& rate)
        : rate(rate),
		dynamical(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, const float potential)
        : rate(rate),
		dynamical(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, const float potential, short int scaling)
        : rate(rate),
		dynamical(scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, const float potential, short int scaling, std::string unit)
        : rate(rate), dynamical(scaling, unit), potential(potential, scaling, unit) {

}

Change::Change(const float rate, const float potential, short int scaling, const Unit& unit)
        : rate(rate), dynamical(scaling, unit), potential(potential, scaling, unit) {

}

Change::Change(const Signal& potential)
        : rate(),
		dynamical(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)), potential(potential) {

}

Change::Change(const Signal& dynamical, const Signal& potential)
        : rate(), dynamical(dynamical), potential(potential) {

}

Change::Change(const Direction& rate, const Signal& potential)
        : rate(rate),
		dynamical(shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)), potential(potential) {

}

Change::Change(const Direction& rate, const Signal& dynamical, const Signal& potential)
        : rate(rate), dynamical(dynamical), potential(potential) {

}

Change::Change(const float rate, const float dynamical, const float potential)
        : rate(rate),
		dynamical(dynamical, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, const float dynamical, const float potential, short int scaling)
        : rate(rate),
		dynamical(dynamical, scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)),
		potential(potential, scaling, shp::Unit::getDerivedSymbol(shp::Unit::ENERGY)) {

}

Change::Change(const float rate, const float dynamical, const float potential, short int scaling, std::string unit)
        : rate(rate), dynamical(dynamical, scaling, unit), potential(potential, scaling, unit) {

}

Change::Change(const float rate, const float dynamical, const float potential, short int scaling, const Unit& unit)
        : rate(rate), dynamical(dynamical, scaling, unit), potential(potential, scaling, unit) {

}

Change::~Change() {

}

bool Change::operator==(const Change& peer) const {
    return (rate == peer.rate)
        && (dynamical == peer.dynamical)
        && (potential == peer.potential);
}

Change Change::operator+(const Change& peer) const {
    return Change((rate + peer.rate),
            (dynamical + peer.dynamical), (potential + peer.potential));
}

Change Change::operator-(const Change& peer) const {
    return Change((rate - peer.rate),
            (dynamical - peer.dynamical), (potential - peer.potential));
}

Change Change::operator*(const Change& peer) const {
    return Change((rate * peer.rate),
            (dynamical * peer.dynamical), (potential * peer.potential));
}

Change Change::operator/(const Change& peer) const {
    return Change((rate / peer.rate),
            (dynamical / peer.dynamical), (potential / peer.potential));
}

Change Change::operator%(const Change& peer) const {
    return Change((rate % peer.rate),
            (dynamical % peer.dynamical), (potential % peer.potential));
}

float Change::toRadians() const {
    return rate.toRadians();
}

void Change::setConversion(const float rate) {
    this->rate = Direction(rate);
}

shp::Signal Change::getLagrangian() const {
    Signal difference = (dynamical - potential); difference.adjustScaling();
    return Signal(difference.getOrientation(), difference.getMagnitude(),
        difference.getScaling(), difference.getUnit());
}

shp::Signal Change::getHamiltonian() const {
    Signal sumtotal = (dynamical + potential); sumtotal.adjustScaling();
    return Signal(sumtotal.getOrientation(), sumtotal.getMagnitude(),
        sumtotal.getScaling(), sumtotal.getUnit());
}

float Change::leastAction() {
    float hamiltonian = getHamiltonian().getMagnitude();
    float lagrangian = getLagrangian().getMagnitude();
    float conversion = (lagrangian * cos(rate.toRadians()));
    dynamical.setMagnitude((hamiltonian * conversion));
    potential.setMagnitude((hamiltonian * (1 - conversion)));
    return conversion;
}

Change Change::copy() {
    Change fresh(this->rate, this->dynamical, this->potential);
    return fresh;
}

void Change::clear() {
    dynamical.clear();
    potential.clear();
    rate.clear();
    return;
}

std::string Change::print() const {
    std::stringstream result;
    result << "T:";
    result << dynamical.print() << ",U:";
	result << potential.print() << ",";
	result << rate.print();
	return result.str();
}

std::string Change::printRadians() const {
    std::stringstream result;
    result << "T:";
    result << dynamical.printRadians() << ",U:";
	result << potential.printRadians() << ",";
	result << rate.printRadians();
	return result.str();
}

} // namespace shp