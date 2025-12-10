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

#include "chromosome.h"

namespace bio {

Chromosome::Chromosome() : Shape(), genes() {

}

Chromosome::Chromosome(std::string name) : Shape(name), genes() {

}

Chromosome::~Chromosome() {

}

bool Chromosome::operator==(const Chromosome& peer) const {
    return (genes == peer.genes);
}

Chromosome Chromosome::operator+(const Chromosome& peer) const {
    GeneArray result(genes);
    result.insert(result.end(), peer.genes.begin(), peer.genes.end());
    return Chromosome("+", result);
}

Chromosome Chromosome::operator-(const Chromosome& peer) const {
    GeneArray result(genes);
    for (GeneArray::const_iterator it = peer.genes.begin(); it != peer.genes.end(); ++it) {
        GeneArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Chromosome("-", result);
}

int Chromosome::getGeneCount() const {
    return genes.size();
}

Gene Chromosome::get(int index) const {
    Gene result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(genes.size())) {
        return result;
    }
    return genes[index];
}

void Chromosome::set(int index, const Gene& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(genes.size())) {
        // replace existing element
        genes[index] = object;
    } else if (index == static_cast<int>(genes.size())) {
        // append at end
        genes.push_back(object);
    } else {
        // index beyond current size: append at end
        genes.push_back(object);
    }
    return;
}

Chromosome Chromosome::copy() {
    Chromosome fresh(this->getName(), this->genes);
    return fresh;
}

void Chromosome::clear() {
    Shape::clear();
    genes.clear();
    return;
}

std::string Chromosome::print() {
    std::stringstream result;
    result << "{ch";
	result << Shape::print() << ",sz:";
	result << genes.size() << "}";
	return result.str();
}

} // namespace bio