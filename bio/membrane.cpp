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

#include "membrane.h"

namespace bio {

Membrane::Membrane() : Shape(), potential(), proteins() {

}

Membrane::Membrane(const float potential)
        : Shape(), potential(potential), proteins() {

}

Membrane::Membrane(const float potential, ProteinArray& objects)
        : Shape(), potential(potential), proteins(objects) {

}

Membrane::~Membrane() {

}

bool Membrane::operator==(const Membrane& peer) const {
    return (proteins == peer.proteins);
}

Membrane Membrane::operator+(const Membrane& peer) const {
    ProteinArray result(proteins);
    result.insert(result.end(), peer.proteins.begin(), peer.proteins.end());
    return Membrane(potential, result);
}

Membrane Membrane::operator-(const Membrane& peer) const {
    ProteinArray result(proteins);
    for (ProteinArray::const_iterator it = peer.proteins.begin(); it != peer.proteins.end(); ++it) {
        ProteinArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Membrane(potential, result);
}

int Membrane::getProteinCount() const {
    return proteins.size();
}

Protein Membrane::get(int index) const {
    Protein result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(proteins.size())) {
        return result;
    }
    return proteins[index];
}

void Membrane::set(int index, const Protein& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(proteins.size())) {
        // replace existing element
        proteins[index] = object;
    } else if (index == static_cast<int>(proteins.size())) {
        // append at end
        proteins.push_back(object);
    } else {
        // index beyond current size: append at end
        proteins.push_back(object);
    }
    return;
}

Membrane Membrane::copy() {
    Membrane fresh(potential, this->proteins);
    return fresh;
}

void Membrane::clear() {
    Shape::clear();
    potential = 0.0f;
    proteins.clear();
    return;
}

std::string Membrane::print() {
    std::stringstream result;
    result << "{mem:";
    result << Shape::print() << ",p:";
    result << potential << ",sz:";
	result << proteins.size() << "}";
	return result.str();
}

} // namespace bio