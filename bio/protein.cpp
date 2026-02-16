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

#include "protein.h"

namespace bio {

Protein::Protein()
        : Molecule(), gates() {

}

Protein::Protein(const GateArray& objects)
        : Molecule(), gates(objects) {

}

Protein::Protein(const std::string name)
        : Molecule(name), gates() {

}

Protein::Protein(const std::string name, const GateArray& objects)
        : Molecule(name), gates(objects) {

}

Protein::~Protein() {

}

bool Protein::operator==(const Protein& peer) const {
    return (gates == peer.gates);
}

Protein Protein::operator+(const Protein& peer) const {
    GateArray result(gates);
    result.insert(result.end(), peer.gates.begin(), peer.gates.end());
    return Protein("+", result);
}

Protein Protein::operator-(const Protein& peer) const {
    GateArray result(gates);
    for (GateArray::const_iterator it = peer.gates.begin(); it != peer.gates.end(); ++it) {
        GateArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Protein("-", result);
}

int Protein::getGateCount() const {
    return gates.size();
}

Gate Protein::get(const int index) const {
    Gate result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(gates.size())) {
        return result;
    }
    return gates[index];
}

void Protein::set(const int index, const Gate& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(gates.size())) {
        // replace existing element
        gates[index] = object;
    } else if (index == static_cast<int>(gates.size())) {
        // append at end
        gates.push_back(object);
    } else {
        // index beyond current size: append at end
        gates.push_back(object);
    }
    return;
}

che::Molecule Protein::copy() {
    Protein fresh(this->getName(), this->gates);
    return fresh;
}

void Protein::clear() {
    Molecule::clear();
    gates.clear();
    return;
}

std::string Protein::print() const {
    std::stringstream result;
    result << "[pr:";
	result << Molecule::print() << "]";
	result << printGates();
	return result.str();
}

std::string Protein::printGates() const {
    std::stringstream result; int size = gates.size();
    if (size > 0) {
	    result << ",sz:";
        result << gates.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << gates[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace bio