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

#include "future.h"

namespace fin {

Future::Future()
        : Securities(), underlying(), strike() {

}

Future::Future(std::string name)
        : Securities(name), underlying(), strike() {

}

Future::Future(const act::Contract& contract)
        : Securities(contract), underlying(), strike() {

}

Future::Future(const act::Asset& underlying)
        : Securities(), underlying(underlying), strike() {

}

Future::Future(const act::Price& strike)
    : Securities(), underlying(), strike(strike) {

}

Future::Future(const act::Asset& underlying, const act::Price& strike)
        : Securities(), underlying(underlying), strike(strike) {

}

Future::Future(const act::Contract& contract, const act::Asset& underlying)
        : Securities(contract), underlying(underlying), strike() {

}

Future::Future(const act::Contract& contract, const act::Price& strike)
        : Securities(contract), underlying(), strike(strike) {

}

Future::Future(const act::Contract& contract, const act::Asset& underlying,
        const act::Price& strike)
        : Securities(contract), underlying(underlying), strike(strike) {

}

Future::Future(std::string name, const act::Contract& contract)
        : Securities(name, contract), underlying(), strike() {

}

Future::Future(std::string name, const act::Asset& underlying)
        : Securities(name), underlying(underlying), strike() {

}

Future::Future(std::string name, const act::Price& strike)
        : Securities(name), underlying(), strike(strike) {

}

Future::Future(std::string name, const act::Asset& underlying, const act::Price& strike)
        : Securities(name), underlying(underlying), strike(strike) {

}

Future::Future(std::string name, const act::Contract& contract, const act::Asset& underlying)
        : Securities(name, contract), underlying(underlying), strike() {

}

Future::Future(std::string name, const act::Contract& contract, const act::Price& strike)
        : Securities(name, contract), underlying(), strike(strike) {

}

Future::Future(std::string name, const act::Contract& contract, const act::Asset& underlying,
        const act::Price& strike)
        : Securities(name, contract), underlying(underlying), strike(strike) {

}

Future::~Future() {

}

bool Future::operator==(const Future& peer) const {
    return (static_cast<const Securities&>(*this) == static_cast<const Securities&>(peer))
        && (underlying == peer.underlying) && (strike == peer.strike);
}

Future Future::operator+(const Future& peer) const {
    return Future("+", (getContract() + peer.getContract()),
        (underlying + peer.underlying), (strike + peer.strike));
}

Future Future::operator-(const Future& peer) const {
    return Future("-", (getContract() - peer.getContract()),
        (underlying - peer.underlying), (strike - peer.strike));
}

act::Item Future::copy() {
    Future fresh(getName(), getContract(), underlying, strike);
    return fresh;
}

void Future::clear() {
    Securities::clear();
    underlying.clear();
    strike.clear();
    return;
}

std::string Future::print() {
    std::stringstream result;
    result << Securities::print() << ",";
    result << underlying.print() << ",";
    result << strike.print();
	return result.str();
}

} // namespace fin