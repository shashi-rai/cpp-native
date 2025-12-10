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

#include "molecule.h"

namespace che {

Molecule::Molecule()
        : Shape(), formulae(), potential(), bonds() {

}

Molecule::Molecule(std::string name)
        : Shape(name), formulae(), potential(), bonds() {

}

Molecule::Molecule(const float potential)
        : Shape(), formulae(), potential(potential), bonds() {

}

Molecule::Molecule(std::string name, std::string formulae)
        : Shape(name), formulae(formulae), potential(), bonds() {

}

Molecule::Molecule(std::string name, std::string formulae, const float potential)
        : Shape(name), formulae(formulae), potential(potential), bonds() {

}

Molecule::Molecule(BondArray& bonds)
        : Shape(), formulae(), potential(), bonds(bonds) {

}

Molecule::Molecule(std::string name, BondArray& bonds)
        : Shape(name), formulae(), potential(), bonds(bonds) {

}

Molecule::Molecule(std::string name, const float potential, BondArray& bonds)
        : Shape(name), formulae(), potential(potential), bonds(bonds) {

}

Molecule::Molecule(std::string name, std::string formulae, const float potential, BondArray& bonds)
        : Shape(name), formulae(formulae), potential(potential), bonds(bonds) {

}

Molecule::~Molecule() {

}

bool Molecule::operator==(const Molecule& peer) const {
    return (formulae == peer.formulae)
        && (potential == peer.potential)
        && (bonds == peer.bonds);
}

Molecule Molecule::operator+(const Molecule& peer) const {
    BondArray result(bonds);
    result.insert(result.end(), peer.bonds.begin(), peer.bonds.end());
    return Molecule("+", result);
}

Molecule Molecule::operator-(const Molecule& peer) const {
    BondArray result(bonds);
    for (BondArray::const_iterator it = peer.bonds.begin(); it != peer.bonds.end(); ++it) {
        BondArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Molecule("-", result);
}

int Molecule::getBondCount() const {
    return bonds.size();
}

Bond Molecule::get(int index) const {
    Bond result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(bonds.size())) {
        return result;
    }
    return bonds[index];
}

void Molecule::set(int index, const Bond& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(bonds.size())) {
        // replace existing element
        bonds[index] = object;
    } else if (index == static_cast<int>(bonds.size())) {
        // append at end
        bonds.push_back(object);
    } else {
        // index beyond current size: append at end
        bonds.push_back(object);
    }
    return;
}

Molecule Molecule::copy() {
    Molecule fresh(getName(), formulae, potential, bonds);
    return fresh;
}

void Molecule::clear() {
    Shape::clear();
    formulae = "";
    potential = 0.0f;
    bonds.clear();
    return;
}

std::string Molecule::print() {
    std::stringstream result;
    result << "{mo";
	result << Shape::print() << ",f:";
    result << formulae << ",v:";
    result << potential << ",sz:";
	result << bonds.size() << "}";
	return result.str();
}

} // namespace che