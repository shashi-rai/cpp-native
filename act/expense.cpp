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

#include "expense.h"

namespace act {

Expense::Expense() : Amount(), name(), receipt() {

}

Expense::Expense(const float value)
        : Amount(value), name(), receipt() {

}

Expense::Expense(std::string name)
        : Amount(), name(name), receipt() {

}

Expense::Expense(const doc::Document& receipt)
        : Amount(), name(), receipt(receipt) {

}

Expense::Expense(std::string name, const doc::Document& receipt)
        : Amount(), name(name), receipt(receipt) {

}

Expense::Expense(std::string name, const float value)
        : Amount(value), name(name), receipt() {

}

Expense::Expense(std::string name, std::string remarks)
        : Amount(remarks), name(name), receipt() {

}

Expense::Expense(std::string name,
        const Currency& currency, std::string remarks)
        : Amount(currency, remarks), name(name), receipt() {

}

Expense::Expense(std::string name, const float value,
        const Currency& currency, std::string remarks)
        : Amount(value, currency, remarks), name(name), receipt() {

}

Expense::Expense(std::string name, const long datetime, const float value,
        const Currency& currency, std::string remarks)
        : Amount(datetime, value, currency, remarks), name(name), receipt() {

}

Expense::~Expense() {

}

bool Expense::operator==(const Expense& peer) const {
    return (static_cast<const Amount&>(*this) == static_cast<const Amount&>(peer))
        && (name == peer.name) && (receipt == peer.receipt);
}

Expense Expense::operator+(const Expense& peer) const {
    return Expense("+", getDateTime().getValue(),
        (getValue() + peer.getValue()), getCurrency(), getRemarks());
}

Expense Expense::operator-(const Expense& peer) const {
    return Expense("-", getDateTime().getValue(),
        (getValue() - peer.getValue()), getCurrency(), getRemarks());
}

Expense Expense::operator*(const Expense& peer) const {
    return Expense("*", getDateTime().getValue(),
        (getValue() * peer.getValue()), getCurrency(), getRemarks());
}

Expense Expense::operator/(const Expense& peer) const {
    return Expense("/", getDateTime().getValue(),
        (getValue() / peer.getValue()), getCurrency(), getRemarks());
}

Expense Expense::operator%(const Expense& peer) const {
    return Expense("%", getDateTime().getValue(),
        fmod(getValue(), peer.getValue()), getCurrency(), getRemarks());
}

Amount Expense::copy() {
    Expense fresh(name, getDateTime().getValue(), getValue(), getCurrency(), getRemarks());
    fresh.setReceipt(receipt);
    return fresh;
}

void Expense::clear() {
    Amount::clear();
    name = "";
    receipt.clear();
    return;
}

std::string Expense::print() {
    std::stringstream result;
    result << Amount::print() << ",";
    result << name << ",";
    result << receipt.print();
	return result.str();
}

} // namespace act