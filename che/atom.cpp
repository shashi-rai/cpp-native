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

Atom::Atom(std::string name) : Cellular(name), nucleus(), valency(0) {

}

Atom::Atom(std::string name, float gradient)
        : Cellular(name, gradient), nucleus(), valency(0) {

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
	shp::Polygon polygon = Cellular::get(primary).get(azimuthal);
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
    result << "{A:";
    result << Cellular::print() << ",sz:";
    result << "}";
	return result.str();
}

} // namespace che