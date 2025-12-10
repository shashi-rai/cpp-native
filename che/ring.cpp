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

#include "ring.h"

namespace che {

Ring::Ring() : Molecule(), atoms() {

}

Ring::Ring(std::string name) : Molecule(name), atoms() {

}

Ring::Ring(std::string name, const AtomArray& atoms)
        : Molecule(name), atoms(atoms) {

}

Ring::~Ring() {

}

bool Ring::operator==(const Ring& peer) const {
    return (atoms == peer.atoms);
}

Ring Ring::operator+(const Ring& peer) const {
    AtomArray result(atoms);
    result.insert(result.end(), peer.atoms.begin(), peer.atoms.end());
    return Ring("+", result);
}

Ring Ring::operator-(const Ring& peer) const {
    AtomArray result(atoms);
    for (AtomArray::const_iterator it = peer.atoms.begin(); it != peer.atoms.end(); ++it) {
        AtomArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Ring("-", result);
}

int Ring::getAtomCount() const {
    return atoms.size();
}

Atom Ring::get(int index) const {
    Atom result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(atoms.size())) {
        return result;
    }
    return atoms[index];
}

void Ring::set(int index, const Atom& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(atoms.size())) {
        // replace existing element
        atoms[index] = object;
    } else if (index == static_cast<int>(atoms.size())) {
        // append at end
        atoms.push_back(object);
    } else {
        // index beyond current size: append at end
        atoms.push_back(object);
    }
    return;
}

Molecule Ring::copy() {
    Ring fresh(getName(), atoms);
    return fresh;
}

void Ring::clear() {
	Molecule::clear();
	atoms.clear();
    return;
}

std::string Ring::print() {
    std::stringstream result;
    result << "(R:";
	result << Molecule::print() << ",sz:";
	result << atoms.size() << ")";
	return result.str();
}

} // namespace che