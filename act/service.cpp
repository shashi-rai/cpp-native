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

#include "service.h"

namespace act {

Service::Service() : Item(), brand() {

}

Service::Service(std::string name)
        : Item(name), brand() {

}

Service::Service(const Brand& brand)
        : Item(), brand(brand) {

}

Service::Service(std::string name, const Brand& brand)
        : Item(name), brand(brand) {

}

Service::~Service() {

}

bool Service::operator==(const Service& peer) const {
    return static_cast<const Item&>(*this) == static_cast<const Item&>(peer)
        && (brand == peer.brand);
}

Item Service::copy() {
    Service fresh(getName(), brand);
    return fresh;
}

void Service::clear() {
    Item::clear();
    brand.clear();
    return;
}

std::string Service::print() {
    std::stringstream result;
    result << Item::print() << ",";
    result << brand.print();
	return result.str();
}

} // namespace act