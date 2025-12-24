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

#include "cost.h"

namespace act {

Cost::Cost() : Price(), code(), discount(), tax() {

}

Cost::Cost(std::string code)
        : Price(), code(code), discount(), tax() {

}

Cost::Cost(const Discount& discount)
        : Price(), code(), discount(discount), tax() {

}

Cost::Cost(std::string code, const Discount& discount)
        : Price(), code(code), discount(discount), tax() {

}

Cost::Cost(const Tax& tax)
        : Price(), code(), discount(), tax(tax) {

}

Cost::Cost(std::string code, const Tax& tax)
        : Price(), code(code), discount(), tax(tax) {

}

Cost::Cost(std::string code, const Discount& discount, const Tax& tax)
        : Price(), code(code), discount(discount), tax(tax) {

}

Cost::~Cost() {

}

bool Cost::operator==(const Cost& peer) const {
    return (code == peer.code) && (discount == peer.discount) && (tax == peer.tax);
}

Cost Cost::operator+(const Cost& peer) const {
    return Cost("+", (discount + peer.discount), (tax + peer.tax));
}

Cost Cost::operator-(const Cost& peer) const {
    return Cost("-", (discount - peer.discount), (tax - peer.tax));
}

Cost Cost::operator*(const Cost& peer) const {
    return Cost("*", (discount * peer.discount), (tax * peer.tax));
}

Cost Cost::operator/(const Cost& peer) const {
    return Cost("/", (discount / peer.discount), (tax / peer.tax));
}

Cost Cost::operator%(const Cost& peer) const {
    return Cost("%", (discount % peer.discount), (tax % peer.tax));
}

Price Cost::copy() {
    Cost fresh(code, discount, tax);
    return fresh;
}

void Cost::clear() {
    code = "";
    discount.clear();
    tax.clear();
    return;
}

std::string Cost::print() {
    std::stringstream result;
    result << Price::print() << ",";
    result << code << ",";
    result << discount.print() << ",";
    result << tax.print();
	return result.str();
}

} // namespace act