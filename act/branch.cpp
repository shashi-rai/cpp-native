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

#include "branch.h"

namespace act {

Branch::Branch() : name(), address(), certificate() {

}

Branch::Branch(std::string name)
        : name(name), address(), certificate() {

}

Branch::Branch(const gis::Address& address)
        : name(), address(address), certificate() {

}

Branch::Branch(const doc::Document& certificate)
        : name(), address(), certificate(certificate) {

}

Branch::Branch(const gis::Address& address, const doc::Document& certificate)
        : name(), address(address), certificate(certificate) {

}

Branch::Branch(std::string name, const gis::Address& address)
        : name(name), address(address), certificate() {

}

Branch::Branch(std::string name, const doc::Document& certificate)
        : name(name), address(), certificate(certificate) {

}

Branch::Branch(std::string name, const gis::Address& address, const doc::Document& certificate)
        : name(name), address(address), certificate(certificate) {

}

Branch::~Branch() {

}

bool Branch::operator==(const Branch& peer) const {
    return (name == peer.name) && (address == peer.address) && (certificate == peer.certificate);
}

Branch Branch::copy() {
    Branch fresh(name, address, certificate);
    return fresh;
}

void Branch::clear() {
    name = "";
    address.clear();
    certificate.clear();
    return;
}

std::string Branch::print() {
    std::stringstream result;
    result << name << ",";
    result << address.print() << ",";
    result << certificate.print();
	return result.str();
}

} // namespace act