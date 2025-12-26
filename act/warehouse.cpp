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

Warehouse::Warehouse() : Branch(), saleable(), expired() {

}

Warehouse::Warehouse(std::string name)
        : Branch(name), saleable(), expired() {

}

Warehouse::Warehouse(const Inventory& saleable)
        : Branch(), saleable(saleable), expired() {

}

Warehouse::Warehouse(const Inventory& saleable, const Inventory& expired)
        : Branch(), saleable(saleable), expired(expired) {

}

Warehouse::Warehouse(std::string name, const Inventory& saleable)
        : Branch(name), saleable(saleable), expired() {

}

Warehouse::Warehouse(std::string name, const Inventory& saleable, const Inventory& expired)
        : Branch(name), saleable(saleable), expired(expired) {

}

Warehouse::Warehouse(const gis::Address& address)
        : Branch(address), saleable(), expired() {

}

Warehouse::Warehouse(const Inventory& saleable, const gis::Address& address)
        : Branch(address), saleable(saleable), expired() {

}

Warehouse::Warehouse(const Inventory& saleable, const Inventory& expired,
		const gis::Address& address)
        : Branch(address), saleable(saleable), expired(expired) {

}

Warehouse::Warehouse(std::string name, const gis::Address& address)
        : Branch(name, address), saleable(), expired() {

}

Warehouse::Warehouse(std::string name, const Inventory& saleable, const gis::Address& address)
        : Branch(name, address), saleable(saleable), expired() {

}

Warehouse::Warehouse(std::string name, const Inventory& saleable, const Inventory& expired,
		const gis::Address& address)
        : Branch(name, address), saleable(saleable), expired(expired) {

}

Warehouse::~Warehouse() {

}

bool Warehouse::operator==(const Warehouse& peer) const {
    return (static_cast<const Branch&>(*this) == static_cast<const Branch&>(peer))
        && (saleable == peer.saleable) && (expired == peer.expired);
}

Branch Warehouse::copy() {
    Warehouse fresh(getName(), saleable, expired, getAddress());
    return fresh;
}

void Warehouse::clear() {
    Branch::clear();
    saleable.clear();
    expired.clear();
    return;
}

std::string Warehouse::print() {
    std::stringstream result;
    result << Branch::print() << ",";
    result << saleable.print() << ",";
	result << expired.print();
	return result.str();
}

} // namespace act