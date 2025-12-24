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

#include "distributor.h"

namespace act {

Distributor::Distributor() : Party(), retailers() {

}

Distributor::Distributor(std::string name)
        : Party(name), retailers() {

}

Distributor::Distributor(const RetailerArray& retailers)
        : Party(), retailers(retailers) {

}

Distributor::Distributor(std::string name, const RetailerArray& retailers)
        : Party(name), retailers(retailers) {

}

Distributor::~Distributor() {

}

bool Distributor::operator==(const Distributor& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (retailers == peer.retailers);
}

Distributor Distributor::operator+(const Distributor& peer) const {
    RetailerArray result(retailers);
    result.insert(result.end(), peer.retailers.begin(), peer.retailers.end());
    return Distributor("+", result);
}

Distributor Distributor::operator-(const Distributor& peer) const {
    RetailerArray result(retailers);
    for (RetailerArray::const_iterator it = peer.retailers.begin(); it != peer.retailers.end(); ++it) {
        RetailerArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Distributor("-", result);
}

int Distributor::getRetailerCount() const {
    return retailers.size();
}

Retailer Distributor::get(int index) const {
    Retailer result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(retailers.size())) {
        return result;
    }
    return retailers[index];
}

void Distributor::set(int index, const Retailer& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(retailers.size())) {
        // replace existing element
        retailers[index] = object;
    } else if (index == static_cast<int>(retailers.size())) {
        // append at end
        retailers.push_back(object);
    } else {
        // index beyond current size: append at end
        retailers.push_back(object);
    }
    return;
}

Party Distributor::copy() {
    Distributor fresh(getName(), retailers);
    return fresh;
}

void Distributor::clear() {
    Party::clear();
    retailers.clear();
    return;
}

std::string Distributor::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << retailers.size();
	return result.str();
}

} // namespace act