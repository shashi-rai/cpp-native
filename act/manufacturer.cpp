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

#include "manufacturer.h"

namespace act {

Manufacturer::Manufacturer() : Party(), factories() {

}

Manufacturer::Manufacturer(std::string name)
        : Party(name), factories() {

}

Manufacturer::Manufacturer(const FactoryArray& factories)
        : Party(), factories(factories) {

}

Manufacturer::Manufacturer(std::string name, const FactoryArray& factories)
        : Party(name), factories(factories) {

}

Manufacturer::~Manufacturer() {

}

bool Manufacturer::operator==(const Manufacturer& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (factories == peer.factories);
}

Manufacturer Manufacturer::operator+(const Manufacturer& peer) const {
    FactoryArray result(factories);
    result.insert(result.end(), peer.factories.begin(), peer.factories.end());
    return Manufacturer("+", result);
}

Manufacturer Manufacturer::operator-(const Manufacturer& peer) const {
    FactoryArray result(factories);
    for (FactoryArray::const_iterator it = peer.factories.begin(); it != peer.factories.end(); ++it) {
        FactoryArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Manufacturer("-", result);
}

int Manufacturer::getFactoryCount() const {
    return factories.size();
}

Factory Manufacturer::get(int index) const {
    Factory result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(factories.size())) {
        return result;
    }
    return factories[index];
}

void Manufacturer::set(int index, const Factory& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(factories.size())) {
        // replace existing element
        factories[index] = object;
    } else if (index == static_cast<int>(factories.size())) {
        // append at end
        factories.push_back(object);
    } else {
        // index beyond current size: append at end
        factories.push_back(object);
    }
    return;
}

Party Manufacturer::copy() {
    Manufacturer fresh(getName(), factories);
    return fresh;
}

void Manufacturer::clear() {
    Party::clear();
    factories.clear();
    return;
}

std::string Manufacturer::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << factories.size();
	return result.str();
}

} // namespace act