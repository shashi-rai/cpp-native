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

#include "gene.h"

namespace bio {

Gene::Gene() : Shape(), sequence() {

}

Gene::Gene(std::string name, NucleotideArray& codon) : Shape(name), sequence(codon) {

}

Gene::~Gene() {

}

bool Gene::operator==(const Gene& peer) const {
    return (sequence == peer.sequence);
}

Gene Gene::operator+(const Gene& peer) const {
    NucleotideArray result(sequence);
    result.insert(result.end(), peer.sequence.begin(), peer.sequence.end());
    return Gene("+", result);
}

Gene Gene::operator-(const Gene& peer) const {
    NucleotideArray result(sequence);
    for (NucleotideArray::const_iterator it = peer.sequence.begin(); it != peer.sequence.end(); ++it) {
        NucleotideArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Gene("-", result);
}

int Gene::getNucleotideCount() const {
    return sequence.size();
}

Nucleotide Gene::get(int index) const {
    Nucleotide result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(sequence.size())) {
        return result;
    }
    return sequence[index];
}

void Gene::set(int index, const Nucleotide& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(sequence.size())) {
        // replace existing element
        sequence[index] = object;
    } else if (index == static_cast<int>(sequence.size())) {
        // append at end
        sequence.push_back(object);
    } else {
        // index beyond current size: append at end
        sequence.push_back(object);
    }
    return;
}

Gene Gene::copy() {
    Gene fresh(this->getName(), this->sequence);
    return fresh;
}

void Gene::clear() {
    Shape::clear();
    sequence.clear();
    return;
}

std::string Gene::print() {
    std::stringstream result;
    result << "{ge";
	result << Shape::print() << ",sz:";
	result << sequence.size() << "}";
	return result.str();
}

} // namespace bio
