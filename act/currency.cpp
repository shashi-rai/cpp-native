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

#include "currency.h"

namespace act {

const std::string Currency::DEFAULT_SYMBOL = "₹";
const std::string Currency::DEFAULT_NAME = "INR";

Currency::Currency()
        : symbol(DEFAULT_SYMBOL), name(DEFAULT_NAME ) {

}

Currency::Currency(std::string symbol)
        : symbol(symbol), name() {

}

Currency::Currency(std::string symbol, std::string name)
        : symbol(symbol), name(name) {

}

Currency::~Currency() {

}

bool Currency::operator==(const Currency& peer) const {
    return (symbol == peer.symbol) && (name == peer.name);
}

Currency Currency::copy() {
    Currency fresh(symbol, name);
    return fresh;
}

void Currency::clear() {
    symbol = DEFAULT_SYMBOL;
    name = DEFAULT_NAME;
    return;
}

std::string Currency::print() {
    std::stringstream result;
    result << symbol;
	return result.str();
}

} // namespace act