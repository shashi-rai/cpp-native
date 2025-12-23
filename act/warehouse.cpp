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

#include "warehouse.h"

namespace act {

Warehouse::Warehouse() : Branch(), inventory() {

}

Warehouse::Warehouse(std::string name)
        : Branch(name), inventory() {

}

Warehouse::Warehouse(const Inventory& inventory)
        : Branch(), inventory(inventory) {

}

Warehouse::Warehouse(std::string name, const Inventory& inventory)
        : Branch(name), inventory(inventory) {

}

Warehouse::Warehouse(const gis::Address& address)
        : Branch(address), inventory() {

}

Warehouse::Warehouse(const Inventory& inventory, const gis::Address& address)
        : Branch(address), inventory(inventory) {

}

Warehouse::Warehouse(std::string name, const gis::Address& address)
        : Branch(name, address), inventory() {

}

Warehouse::Warehouse(std::string name, const Inventory& inventory, const gis::Address& address)
        : Branch(name, address), inventory(inventory) {

}

Warehouse::~Warehouse() {

}

bool Warehouse::operator==(const Warehouse& peer) const {
    return (static_cast<const Branch&>(*this) == static_cast<const Branch&>(peer))
        && (inventory == peer.inventory);
}

Branch Warehouse::copy() {
    Warehouse fresh(getName(), inventory, getAddress());
    return fresh;
}

void Warehouse::clear() {
    Branch::clear();
    inventory.clear();
    return;
}

std::string Warehouse::print() {
    std::stringstream result;
    result << Branch::print() << ",";
    result << inventory.print();;
	return result.str();
}

} // namespace act