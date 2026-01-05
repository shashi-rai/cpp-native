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

#include "claim.h"

namespace law {

Claim::Claim()
        : name(), facts() {

}

Claim::Claim(const FactArray& facts)
        : name(), facts(facts) {

}

Claim::Claim(std::string name)
        : name(name), facts() {

}

Claim::Claim(std::string name, const FactArray& facts)
        : name(name), facts(facts) {

}

Claim::~Claim() {

}

bool Claim::operator==(const Claim& peer) const {
    return (name == peer.name) && (facts == peer.facts);
}

Claim Claim::operator+(const Claim& peer) const {
    FactArray result(facts);
    result.insert(result.end(), peer.facts.begin(), peer.facts.end());
    return Claim("+", result);
}

Claim Claim::operator-(const Claim& peer) const {
    FactArray result(facts);
    for (FactArray::const_iterator it = peer.facts.begin(); it != peer.facts.end(); ++it) {
        FactArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Claim("-", result);
}

int Claim::getFactCount() const {
    return facts.size();
}

Fact Claim::get(const int index) const {
    Fact result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(facts.size())) {
        return result;
    }
    return facts[index];
}

void Claim::set(const int index, const Fact& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(facts.size())) {
        // replace existing element
        facts[index] = object;
    } else if (index == static_cast<int>(facts.size())) {
        // append at end
        facts.push_back(object);
    } else {
        // index beyond current size: append at end
        facts.push_back(object);
    }
    return;
}

Claim Claim::copy() {
    Claim fresh(getName(), facts);
    return fresh;
}

void Claim::clear() {
    name.clear();
    facts.clear();
    return;
}

std::string Claim::print() {
    std::stringstream result;
    result << "cl:";
	result << name << ",sz:";
	result << facts.size() << "[";
    for (int i = 0; i < facts.size(); i++) {
        result << "," << facts[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace law