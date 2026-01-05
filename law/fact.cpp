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

#include "fact.h"

namespace law {

Fact::Fact()
        : name(), evidences() {

}

Fact::Fact(const EvidenceArray& evidences)
        : name(), evidences(evidences) {

}

Fact::Fact(std::string name)
        : name(name), evidences() {

}

Fact::Fact(std::string name, const EvidenceArray& evidences)
        : name(name), evidences(evidences) {

}

Fact::~Fact() {

}

bool Fact::operator==(const Fact& peer) const {
    return (name == peer.name) && (evidences == peer.evidences);
}

Fact Fact::operator+(const Fact& peer) const {
    EvidenceArray result(evidences);
    result.insert(result.end(), peer.evidences.begin(), peer.evidences.end());
    return Fact("+", result);
}

Fact Fact::operator-(const Fact& peer) const {
    EvidenceArray result(evidences);
    for (EvidenceArray::const_iterator it = peer.evidences.begin(); it != peer.evidences.end(); ++it) {
        EvidenceArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Fact("-", result);
}

int Fact::getEvidenceCount() const {
    return evidences.size();
}

Evidence Fact::get(const int index) const {
    Evidence result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(evidences.size())) {
        return result;
    }
    return evidences[index];
}

void Fact::set(const int index, const Evidence& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(evidences.size())) {
        // replace existing element
        evidences[index] = object;
    } else if (index == static_cast<int>(evidences.size())) {
        // append at end
        evidences.push_back(object);
    } else {
        // index beyond current size: append at end
        evidences.push_back(object);
    }
    return;
}

Fact Fact::copy() {
    Fact fresh(getName(), evidences);
    return fresh;
}

void Fact::clear() {
    name.clear();
    evidences.clear();
    return;
}

std::string Fact::print() {
    std::stringstream result;
    result << "f:";
	result << name << ",sz:";
	result << evidences.size() << "[";
    for (int i = 0; i < evidences.size(); i++) {
        result << "," << evidences[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace law