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

#include "tax.h"

namespace act {

const float Tax::DEFAULT_VALUE = 0.18f;     // 18%

Tax::Tax() : name(), percent(DEFAULT_VALUE), amount() {

}

Tax::Tax(std::string name)
        : name(name), percent(DEFAULT_VALUE), amount() {

}

Tax::Tax(const float percent)
        : name(), percent(percent), amount() {

}

Tax::Tax(const Amount& amount)
        : name(), percent(DEFAULT_VALUE), amount(amount) {

}

Tax::Tax(const float percent, const Amount& amount)
        : name(), percent(percent), amount(amount) {

}

Tax::Tax(std::string name, const Amount& amount)
        : name(name), percent(DEFAULT_VALUE), amount(amount) {

}

Tax::Tax(std::string name, const float percent, const Amount& amount)
        : name(name), percent(percent), amount(amount) {

}

Tax::~Tax() {

}

bool Tax::operator==(const Tax& peer) const {
    return (name == peer.name) && (percent == peer.percent) && (amount == peer.amount);
}

Tax Tax::operator+(const Tax& peer) const {
    return Tax("+", (percent + peer.percent), (amount + peer.amount));
}

Tax Tax::operator-(const Tax& peer) const {
    return Tax("-", (percent - peer.percent), (amount - peer.amount));
}

Tax Tax::operator*(const Tax& peer) const {
    return Tax("*", (percent * peer.percent), (amount * peer.amount));
}

Tax Tax::operator/(const Tax& peer) const {
    return Tax("/", (percent / peer.percent), (amount / peer.amount));
}

Tax Tax::operator%(const Tax& peer) const {
    return Tax("%", fmod(percent, peer.percent), (amount % peer.amount));
}

Tax Tax::copy() {
    Tax fresh(name, percent, amount);
    return fresh;
}

void Tax::clear() {
    name = "";
    percent = DEFAULT_VALUE;
    amount.clear();
    return;
}

std::string Tax::print() {
    std::stringstream result;
    result << name << ",%:";
    result << percent << ",";
    result << amount.print();
	return result.str();
}

} // namespace act