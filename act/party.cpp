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

#include "party.h"

namespace act {

Party::Party() : name(), address(), balance() {

}

Party::Party(std::string name)
        : name(name), address(), balance() {

}

Party::Party(const gis::Address& address)
        : name(), address(address), balance() {

}

Party::Party(const Balance& balance)
        : name(), address(), balance(balance) {

}

Party::Party(const gis::Address& address, const Balance& balance)
        : name(), address(address), balance(balance) {

}

Party::Party(std::string name, const gis::Address& address)
        : name(name), address(address), balance() {

}

Party::Party(std::string name, const Balance& balance)
        : name(name), address(), balance(balance) {

}

Party::Party(std::string name, const gis::Address& address, const Balance& balance)
        : name(name), address(address), balance(balance) {

}

Party::~Party() {

}

bool Party::operator==(const Party& peer) const {
    return (name == peer.name) && (address == peer.address) && (balance == peer.balance);
}

Party Party::operator+(const Party& peer) const {
    return Party("+", address, (balance + peer.balance));
}

Party Party::operator-(const Party& peer) const {
    return Party("-", address, (balance - peer.balance));
}

Party Party::copy() {
    Party fresh(name, address, balance);
    return fresh;
}

void Party::clear() {
    name = "";
    address.clear();
    balance.clear();
    return;
}

std::string Party::print() {
    std::stringstream result;
    result << name << ",";
    result << address.print() << ",";
    result << balance.print();
	return result.str();
}

} // namespace act