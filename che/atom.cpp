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

const int Atom::MAX_ELECTRON_PER_ORBITAL = 2;
const int Atom::S_BLOCK[] = { 1, 2 };
const int Atom::P_BLOCK[] = { 13, 14, 15, 16, 17, 18 };
const int Atom::D_BLOCK[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
const int Atom::F_BLOCK[] = { 6, 7 };
const std::string Atom::ELEMENT_SYMBOL[] = {
	"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
	"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
	"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",
	"Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",
	"I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
	"Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt",
	"Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa",
	"U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf",
	"Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};
const std::string Atom::ORBITAL_NAME[] = { "s", "p", "d", "f" };
const int Atom::ORBITAL_ELECTRON_LIMIT[] = { 2, 6, 10, 14 };
const int Atom::PERIOD_ELECTRON_LIMIT[] = { 2, 8, 8, 18, 18, 32, 32 };
const int Atom::ALKALI_METAL[] = { 1, 3, 11, 19, 37, 55, 87 };
const int Atom::ALKALINE_METAL[] = { 4, 12, 20, 38, 56, 88 };
const int Atom::HALOGEN_GAS[] = { 9, 17, 35, 53, 85, 117 };
const int Atom::NOBLE_GAS[] = { 2, 10, 18, 36, 54, 86, 118 };
const int Atom::TRANSITION_METAL[] = {
	21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
	72, 73, 74, 75, 76, 77, 78, 89, 80, 104, 105, 106, 107, 108
};
const int Atom::POST_TRANSITION_METAL[] = { 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};
const int Atom::NON_METAL[] = { 6, 7, 8, 9,15, 16, 17, 34, 35, 53 };
const int Atom::METALLOID[] = { 5, 14, 32, 33, 51, 52 };
const int Atom::LANTHANIDE[] = { 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 6, 69, 70, 71 };
const int Atom::ACTINIDE[] = { 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103 };

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

Period& Atom::getPeriod(int primary) const {
	shp::ShellArray shells = this->getShells();
	Period& result = static_cast<Period&>(shells[primary]);
	return result;
}

void Atom::setPeriod(int primary, const Period& object) {
	Cellular::set(primary, object);
	return;
}

Orbital& Atom::getOrbital(int primary, int azimuthal) const {
	shp::ShellArray shells = this->getShells();
	Orbital& result = static_cast<Orbital&>(shells[primary](azimuthal));
	return result;
}

void Atom::setOrbital(int primary, int azimuthal, const Orbital& object) {
	Cellular::get(primary).set(azimuthal, object);
	return;
}

Electron& Atom::getElectron(int primary, int azimuthal, int magnetic) const {
	shp::ShellArray shells = this->getShells();
	Electron& result = static_cast<Electron&>(shells[primary](azimuthal)(magnetic));
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

const std::string Atom::getSymbol(short int number) {
	return (number > 0 && number <= 118) ? ELEMENT_SYMBOL[number-1] : "Unknown";
}

/*
 * Allocate (periods + orbitals) using Atomic Number
 */
Atom Atom::initialize(short number, std::string symbol, std::string name) {
	Atom peer(number, symbol, name);
	short int remaining = number;
	for (short int period = 0; (remaining > 0) && (period < 7); period++) {
		std::stringstream pid; pid << "P" << (period + 1);
		remaining -= PERIOD_ELECTRON_LIMIT[period];
		if (remaining > 0) { // next cycle required
			createPeriods(peer, pid.str(), period, PERIOD_ELECTRON_LIMIT[period]);
		} else {	// final period allocation
			createPeriods(peer, pid.str(), period, PERIOD_ELECTRON_LIMIT[period]);
			remaining = (PERIOD_ELECTRON_LIMIT[period] - remaining);
			break;
		}
	}
	return peer;
}

void Atom::createPeriods(Atom& peer, std::string prefix,
		short int period, short int capacity) {
	Period shell(prefix, (capacity / MAX_ELECTRON_PER_ORBITAL));
	peer.setPeriod(period, shell);

	short int remaining = capacity;
	for (short int orbital = 0; (remaining > 0) && (orbital < 4); orbital++) {
		std::stringstream orbid; orbid << (period + 1) << ORBITAL_NAME[orbital];
		remaining -= ORBITAL_ELECTRON_LIMIT[orbital];
		if (remaining > 0) { // next cycle required
			createOrbitals(peer, orbid.str(), period, orbital,
				(ORBITAL_ELECTRON_LIMIT[orbital] / MAX_ELECTRON_PER_ORBITAL));
		} else { // final orbital allocation
			createOrbitals(peer, orbid.str(), period, orbital,
				(ORBITAL_ELECTRON_LIMIT[orbital] / MAX_ELECTRON_PER_ORBITAL));
			break;
		}
	}
}

void Atom::createOrbitals(Atom& peer, std::string prefix,
		short int period, short int starting, short int capacity) {
	for (short int index = 0; index < capacity; index++) {
		std::stringstream orbid; orbid << prefix << index;
		Orbital orbital(orbid.str(), MAX_ELECTRON_PER_ORBITAL);
		peer.setOrbital(period, (starting + index), orbital);;
	}
}

} // namespace che