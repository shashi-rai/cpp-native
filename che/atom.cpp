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

const int Atom::ELEMENT_MIN_LIMIT = Nucleus::PROTON_MIN_LIMIT;
const int Atom::ELEMENT_MAX_LIMIT = Nucleus::PROTON_MAX_LIMIT;
const int Atom::S_BLOCK[] = { 1, 2 };
const int Atom::P_BLOCK[] = { 13, 14, 15, 16, 17, 18 };
const int Atom::D_BLOCK[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
const int Atom::F_BLOCK[] = { 6, 7 };
const int Atom::ALKALI_METAL[] = { 1, 3, 11, 19, 37, 55, 87 };
const int Atom::ALKALINE_METAL[] = { 4, 12, 20, 38, 56, 88 };
const int Atom::SEMICONDUCTOR[] = { 6, 14, 32, 50, 82, 114 };
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

Atom::Atom(short number)
	: Cellular(getName(number)), nucleus(getSymbol(number), number), valency(0) {

}

Atom::Atom(short number, std::string name)
	: Cellular(name), nucleus(getSymbol(number), number), valency(0) {
}

Atom::Atom(std::string name) : Cellular(name), nucleus(name), valency(0) {

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

bool Atom::operator==(const Atom& peer) const {
    return (nucleus == peer.nucleus);
}

std::string Atom::getElementName() const {
	return nucleus.getElementName();
}

Period Atom::getPeriod(int primary) const {
	Period result;
	shp::ShellArray shells = this->getShells();
	if (this->getShellCount() > 0) {
		result = static_cast<Period&>(shells[primary]);
	}
	return result;
}

void Atom::setPeriod(int primary, const std::shared_ptr<che::Period> object) {
	Cellular::set(primary, *object);
	return;
}

Orbital Atom::getOrbital(int primary, int azimuthal) const {
	Orbital result;
	shp::ShellArray shells = this->getShells();
	if (this->getShellCount() > 0) {
		shp::Shell period = shells[primary];
		if (period.getOrbitalCount()) {
			shp::Polygon orbital = period(azimuthal);
			result = static_cast<Orbital&>(period(azimuthal));
		}
	}
	return result;
}

void Atom::setOrbital(int primary, int azimuthal, const std::shared_ptr<che::Orbital> object) {
	this->getPeriod(primary).setOrbital(azimuthal, object);
	return;
}

qft::Electron Atom::getElectron(int primary, int azimuthal, int magnetic) const {
	qft::Electron result;
	shp::ShellArray shells = this->getShells();
	if (this->getShellCount() > 0) {
		shp::Shell period = shells[primary];
		if (period.getOrbitalCount()) {
			shp::Polygon orbital = period(azimuthal);
			if (orbital.getWaveCount() > 0) {
				result = static_cast<qft::Electron&>(orbital(magnetic));
			}
		}
	}
	return result;
}

void Atom::setElectron(int primary, int azimuthal, int magnetic, const std::shared_ptr<qft::Electron> object) {
	this->getPeriod(primary).getOrbital(azimuthal).setElectron(magnetic, object);
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
	return Nucleus::getSymbol(number);
}

const std::string Atom::getName(short int number) {
	return Nucleus::getName(number);
}

/*
 * Allocate (periods + orbitals) using Atomic Number
 */
std::shared_ptr<che::Atom> Atom::initialize(short number, std::string name) {
	std::shared_ptr<che::Atom> peer = std::make_shared<che::Atom>(number, name);
	short int remaining = number;
	for (short int period = 0; (remaining > 0) && (period < Period::MAX_LIMIT); period++) {
		std::stringstream pid; pid << "P" << (period + 1);
		remaining -= Period::ELECTRON_LIMIT[period];
		std::shared_ptr<che::Period> shell = std::make_shared<che::Period>(pid.str(),
			(Period::ELECTRON_LIMIT[period] / Orbital::ELECTRON_MAX_LIMIT));
		createPeriods(shell, pid.str(), period, Period::ELECTRON_LIMIT[period]);
		peer->setPeriod(period, shell);
		if (remaining > 0) { // next cycle required

		} else {	// final period allocation
			remaining = (Period::ELECTRON_LIMIT[period] - remaining);
			break;
		}
	}
	return peer;
}

void Atom::createPeriods(std::shared_ptr<che::Period> peer, std::string prefix,
		short int period, short int capacity) {
	short int remaining = capacity;
	for (short int orbital = 0; (remaining > 0) && (orbital < 4); orbital++) {
		std::stringstream orbid; orbid << (period + 1) << Orbital::NAME[orbital];
		remaining -= Orbital::ELECTRON_LIMIT[orbital];
		createOrbitals(peer, orbid.str(), period, orbital,
			(Orbital::ELECTRON_LIMIT[orbital] / Orbital::ELECTRON_MAX_LIMIT));
		if (remaining > 0) { // next cycle required

		} else { // final orbital allocation
			break;
		}
	}
}

void Atom::createOrbitals(std::shared_ptr<che::Period> peer, std::string prefix,
		short int period, short int starting, short int capacity) {
	for (short int index = 0; index < capacity; index++) {
		std::stringstream orbid; orbid << prefix << index;
		std::shared_ptr<che::Orbital> orbital =
			std::make_shared<che::Orbital>(orbid.str(), Orbital::ELECTRON_MAX_LIMIT);
		peer->setOrbital((starting + index), orbital);;
	}
}

} // namespace che