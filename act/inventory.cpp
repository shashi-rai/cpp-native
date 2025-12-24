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

#include "inventory.h"

namespace act {

Inventory::Inventory() : name(), items() {

}

Inventory::Inventory(std::string name)
        : name(name), items() {

}

Inventory::Inventory(const ItemArray& items)
        : name(), items(items) {

}

Inventory::Inventory(std::string name, const ItemArray& items)
        : name(name), items(items) {

}

Inventory::~Inventory() {

}

bool Inventory::operator==(const Inventory& peer) const {
    return (name == peer.name) && (items == peer.items);
}

Inventory Inventory::operator+(const Inventory& peer) const {
    ItemArray result(items);
    result.insert(result.end(), peer.items.begin(), peer.items.end());
    return Inventory("+", result);
}

Inventory Inventory::operator-(const Inventory& peer) const {
    ItemArray result(items);
    for (ItemArray::const_iterator it = peer.items.begin(); it != peer.items.end(); ++it) {
        ItemArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Inventory("-", result);
}

int Inventory::getItemCount() const {
    return items.size();
}

Item Inventory::get(int index) const {
    Item result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(items.size())) {
        return result;
    }
    return items[index];
}

void Inventory::set(int index, const Item& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(items.size())) {
        // replace existing element
        items[index] = object;
    } else if (index == static_cast<int>(items.size())) {
        // append at end
        items.push_back(object);
    } else {
        // index beyond current size: append at end
        items.push_back(object);
    }
    return;
}

Inventory Inventory::copy() {
    Inventory fresh(name, items);
    return fresh;
}

void Inventory::clear() {
    name = "";
    items.clear();
    return;
}

std::string Inventory::print() {
    std::stringstream result;
    result << name << ",sz:";
    result << items.size();
	return result.str();
}

} // namespace act