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

#include "supplier.h"

namespace act {

Supplier::Supplier() : Party(), partners() {

}

Supplier::Supplier(std::string name)
        : Party(name), partners() {

}

Supplier::Supplier(const PartyArray& partners)
        : Party(), partners(partners) {

}

Supplier::Supplier(std::string name, const PartyArray& partners)
        : Party(name), partners(partners) {

}

Supplier::~Supplier() {

}

bool Supplier::operator==(const Supplier& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (partners == peer.partners);
}

Supplier Supplier::operator+(const Supplier& peer) const {
    PartyArray result(partners);
    result.insert(result.end(), peer.partners.begin(), peer.partners.end());
    return Supplier("+", result);
}

Supplier Supplier::operator-(const Supplier& peer) const {
    PartyArray result(partners);
    for (PartyArray::const_iterator it = peer.partners.begin(); it != peer.partners.end(); ++it) {
        PartyArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Supplier("-", result);
}

int Supplier::getPartnerCount() const {
    return partners.size();
}

Party Supplier::get(int index) const {
    Party result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(partners.size())) {
        return result;
    }
    return partners[index];
}

void Supplier::set(int index, const Party& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(partners.size())) {
        // replace existing element
        partners[index] = object;
    } else if (index == static_cast<int>(partners.size())) {
        // append at end
        partners.push_back(object);
    } else {
        // index beyond current size: append at end
        partners.push_back(object);
    }
    return;
}

Party Supplier::copy() {
    Supplier fresh(getName(), partners);
    return fresh;
}

void Supplier::clear() {
    Party::clear();
    partners.clear();
    return;
}

std::string Supplier::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << partners.size();
	return result.str();
}

} // namespace act