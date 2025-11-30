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

#include "atom.h"

namespace che {

Atom::Atom() : Cellular(""), nucleus(), valency(0) {

}

Atom::Atom(std::string name) : Cellular(name), nucleus(name), valency(0) {

}

Atom::Atom(short number, std::string symbol)
	: Cellular(""), nucleus(symbol, number), valency(0) {

}

Atom::Atom(short number, std::string symbol, std::string name)
	: Cellular(name), nucleus(symbol, number), valency(0) {
}

Atom::Atom(std::string symbol, std::string name)
	: Cellular(name), nucleus(symbol), valency(0) {

}

Atom::Atom(std::string name, float gradient)
        : Cellular(name, gradient), nucleus(name), valency(0) {

}

Atom::Atom(std::string name, Nucleus& nucleus)
        : Cellular(name), nucleus(nucleus), valency(0) {

}

Atom::Atom(std::string name, float gradient, Nucleus& nucleus)
        : Cellular(name, gradient), nucleus(nucleus), valency(0) {

}

Atom::Atom(std::string name, Nucleus& nucleus, short valency)
        : Cellular(name), nucleus(nucleus), valency(valency) {

}

Atom::Atom(std::string name, float gradient, Nucleus& nucleus, short valency)
        : Cellular(name, gradient), nucleus(nucleus), valency(valency) {

}

Atom::~Atom() {

}

Period Atom::getPeriod(int primary) const {
	shp::Shell shell = Cellular::get(primary);
	Period result = static_cast<Period&>(shell);
	return result;
}

void Atom::setPeriod(int primary, const Period& object) {
	Cellular::set(primary, object);
	return;
}

Orbital Atom::getOrbital(int primary, int azimuthal) const {
	shp::Shell shell = Cellular::get(primary);
	Period period = static_cast<Period&>(shell);
	shp::Polygon polygon = period.getOrbital(azimuthal);
	Orbital result = static_cast<Orbital&>(polygon);
	return result;
}

void Atom::setOrbital(int primary, int azimuthal, const Orbital& object) {
	Cellular::get(primary).set(azimuthal, object);
	return;
}

Electron Atom::getElectron(int primary, int azimuthal, int magnetic) const {
	shp::Wave wave = Cellular::get(primary).get(azimuthal).get(magnetic);
	Electron result = static_cast<Electron&>(wave);
	return result;
}

void Atom::setElectron(int primary, int azimuthal, int magnetic, const Electron& object) {
	Cellular::get(primary).get(azimuthal).set(magnetic, object);
	return;
}

void Atom::clear() {
    Cellular::clear();
    return;
}

std::string Atom::print() {
    std::stringstream result;
    result << "[";
	result << nucleus.print() << ",";
    result << Cellular::print();
    result << "]";
	return result.str();
}

/*
 * Allocate (periods + orbitals) using Atomic Number
 */
Atom Atom::initialize(short number, std::string symbol, std::string name) {
	Atom peer(number, symbol, name);
	//Atom peer = *this;
	const int mapper[] = { 2, 8, 8, 18, 18, 32, 32 };	// seven periods capacity
	short int remaining = number;
	for (short int period = 0; (remaining > 0) && (period < 7); period++) {
		std::stringstream pid; pid << "P" << (period + 1);
		remaining -= mapper[period];
		if (remaining > 0) { // next cycle required
			createPeriods(peer, pid.str(), period, mapper[period]);
		} else {	// final period allocation
			createPeriods(peer, pid.str(), period, mapper[period]);
			remaining = (mapper[period] - remaining);
			break;
		}
	}
	return peer;
}

void Atom::createPeriods(Atom& peer, std::string prefix,
		short int period, short int capacity) {
	Period shell(prefix, (capacity/2));
	peer.setPeriod(period, shell);

	const std::string names[] = { "s", "p", "d", "f" };
	const int mapper[] = { 2, 6, 10, 14 };	// s, p, d, f orbital capacity
	short int remaining = capacity;
	for (short int orbital = 0; (remaining > 0) && (orbital < 4); orbital++) {
		std::stringstream orbid; orbid << (period + 1) << names[orbital];
		remaining -= mapper[orbital];
		if (remaining > 0) { // next cycle required
			createOrbitals(peer, orbid.str(), period, orbital, (mapper[orbital]/2));
		} else { // final orbital allocation
			createOrbitals(peer, orbid.str(), period, orbital, (mapper[orbital]/2));
			break;
		}
	}
}

void Atom::createOrbitals(Atom& peer, std::string prefix,
		short int period, short int starting, short int capacity) {
	for (short int index = 0; index < capacity; index++) {
		std::stringstream orbid; orbid << prefix << index;
		Orbital orbital(orbid.str(), 2);
		peer.setOrbital(period, (starting + index), orbital);;
	}
}

} // namespace che