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

#include "retailer.h"

namespace act {

Retailer::Retailer() : Party(), stores() {

}

Retailer::Retailer(std::string name)
        : Party(name), stores() {

}

Retailer::Retailer(const StoreArray& stores)
        : Party(), stores(stores) {

}

Retailer::Retailer(std::string name, const StoreArray& stores)
        : Party(name), stores(stores) {

}

Retailer::~Retailer() {

}

bool Retailer::operator==(const Retailer& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (stores == peer.stores);
}

Retailer Retailer::operator+(const Retailer& peer) const {
    StoreArray result(stores);
    result.insert(result.end(), peer.stores.begin(), peer.stores.end());
    return Retailer("+", result);
}

Retailer Retailer::operator-(const Retailer& peer) const {
    StoreArray result(stores);
    for (StoreArray::const_iterator it = peer.stores.begin(); it != peer.stores.end(); ++it) {
        StoreArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Retailer("-", result);
}

int Retailer::getStoreCount() const {
    return stores.size();
}

Store Retailer::get(int index) const {
    Store result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(stores.size())) {
        return result;
    }
    return stores[index];
}

void Retailer::set(int index, const Store& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(stores.size())) {
        // replace existing element
        stores[index] = object;
    } else if (index == static_cast<int>(stores.size())) {
        // append at end
        stores.push_back(object);
    } else {
        // index beyond current size: append at end
        stores.push_back(object);
    }
    return;
}

Party Retailer::copy() {
    Retailer fresh(getName(), stores);
    return fresh;
}

void Retailer::clear() {
    Party::clear();
    stores.clear();
    return;
}

std::string Retailer::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << stores.size();
	return result.str();
}

} // namespace act