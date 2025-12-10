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

#include "polymer.h"

namespace che {

Polymer::Polymer() : Point(), monomers() {

}

Polymer::Polymer(float gradient) : Point(), monomers() {

}

Polymer::Polymer(float amplitude, float gradient)
		: Point(amplitude, gradient), monomers()  {

}

Polymer::Polymer(std::string name) : Point(name), monomers() {

}

Polymer::Polymer(std::string name, float gradient)
		: Point(name, gradient), monomers() {

}

Polymer::Polymer(std::string name, float amplitude, float gradient)
		: Point(name, amplitude, gradient), monomers() {

}

Polymer::Polymer(std::string name, const MoleculeArray& monomers)
        : Point(name), monomers(monomers) {

}

Polymer::~Polymer() {

}

bool Polymer::operator==(const Polymer& peer) const {
    return (monomers == peer.monomers);
}

Polymer Polymer::operator+(const Polymer& peer) const {
    MoleculeArray result(monomers);
    result.insert(result.end(), peer.monomers.begin(), peer.monomers.end());
    return Polymer("+", result);
}

Polymer Polymer::operator-(const Polymer& peer) const {
    MoleculeArray result(monomers);
    for (MoleculeArray::const_iterator it = peer.monomers.begin(); it != peer.monomers.end(); ++it) {
        MoleculeArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Polymer("-", result);
}

int Polymer::getMoleculeCount() const {
    return monomers.size();
}

Molecule Polymer::get(int index) const {
    Molecule result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(monomers.size())) {
        return result;
    }
    return monomers[index];
}

void Polymer::set(int index, const Molecule& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(monomers.size())) {
        // replace existing element
        monomers[index] = object;
    } else if (index == static_cast<int>(monomers.size())) {
        // append at end
        monomers.push_back(object);
    } else {
        // index beyond current size: append at end
        monomers.push_back(object);
    }
    return;
}

shp::Point Polymer::copy() {
    Polymer fresh(getName(), monomers);
    return fresh;
}

void Polymer::clear() {
	Point::clear();
	monomers.clear();
    return;
}

std::string Polymer::print() {
    std::stringstream result;
    result << "(P:";
	result << Point::print() << ",sz:";
	result << monomers.size() << ")";
	return result.str();
}

} // namespace che