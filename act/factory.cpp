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

#include "factory.h"

namespace act {

Factory::Factory() : Warehouse(), license() {

}

Factory::Factory(std::string name)
        : Warehouse(name), license() {

}

Factory::Factory(const Inventory& inventory)
        : Warehouse(inventory), license() {

}

Factory::Factory(std::string name, const Inventory& inventory)
        : Warehouse(name, inventory), license() {

}

Factory::Factory(const gis::Address& address)
        : Warehouse(address), license() {

}

Factory::Factory(const Inventory& inventory, const gis::Address& address)
        : Warehouse(inventory, address), license() {

}

Factory::Factory(std::string name, const gis::Address& address)
        : Warehouse(name, address), license() {

}

Factory::Factory(std::string name, const Inventory& inventory, const gis::Address& address)
        : Warehouse(name, inventory, address), license() {

}

Factory::~Factory() {

}

bool Factory::operator==(const Factory& peer) const {
    return (static_cast<const Warehouse&>(*this) == static_cast<const Warehouse&>(peer))
        && (license == peer.license);
}

Branch Factory::copy() {
    Factory fresh(getName(), getInventory(), getAddress());
    return fresh;
}

void Factory::clear() {
    Warehouse::clear();
    license.clear();
    return;
}

std::string Factory::print() {
    std::stringstream result;
    result << Warehouse::print() << ",";
    result << license.print();
	return result.str();
}

} // namespace act