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

#include "country.h"

namespace act {

const std::string Country::DEFAULT_CODE = "+91";
const std::string Country::DEFAULT_NAME = "India";

Country::Country()
		: code(DEFAULT_CODE), name(DEFAULT_NAME), currency() {

}

Country::Country(std::string code)
        : code(code), name(), currency() {

}

Country::Country(std::string code, std::string name)
        : code(code), name(name), currency() {

}

Country::Country(const Currency& currency)
        : code(), name(), currency(currency) {

}

Country::Country(std::string name, const Currency& currency)
        : code(), name(name), currency(currency) {

}

Country::Country(std::string code, std::string name, const Currency& currency)
        : code(code), name(name), currency(currency) {

}

Country::~Country() {

}

bool Country::operator==(const Country& peer) const {
    return (code == peer.code)
        && (name == peer.name)
        && (currency == peer.currency);
}

Country Country::copy() {
    Country fresh(code, name, currency);
    return fresh;
}

void Country::clear() {
    code = DEFAULT_CODE;
    name = DEFAULT_NAME;
    currency.clear();
    return;
}

std::string Country::print() {
    std::stringstream result;
    result << code << ",";
    result << name << ",";
    result << currency.print();
	return result.str();
}

} // namespace act