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

#include "cheque.h"

namespace act {

Cheque::Cheque() : receipient(), amount(), signatory() {

}

Cheque::Cheque(const Party& receipient)
        : receipient(receipient), amount(), signatory() {

}

Cheque::Cheque(const Amount& amount)
        : receipient(), amount(amount), signatory() {

}

Cheque::Cheque(const Staff& signatory)
        : receipient(), amount(), signatory(signatory) {

}

Cheque::Cheque(const Amount& amount, const Staff& signatory)
        : receipient(), amount(amount), signatory(signatory) {

}

Cheque::Cheque(const Party& receipient, const Amount& amount)
        : receipient(receipient), amount(amount), signatory() {

}

Cheque::Cheque(const Party& receipient, const Amount& amount, const Staff& signatory)
        : receipient(receipient), amount(amount), signatory(signatory) {

}

Cheque::~Cheque() {

}

bool Cheque::operator==(const Cheque& peer) const {
    return (receipient == peer.receipient)
        && (amount == peer.amount)
        && (signatory == peer.signatory);
}

Cheque Cheque::operator+(const Cheque& peer) const {
    return Cheque(receipient, (amount + peer.amount));
}

Cheque Cheque::operator-(const Cheque& peer) const {
    return Cheque(receipient, (amount - peer.amount));
}

Cheque Cheque::operator*(const Cheque& peer) const {
    return Cheque(receipient, (amount * peer.amount));
}

Cheque Cheque::operator/(const Cheque& peer) const {
    return Cheque(receipient, (amount / peer.amount));
}

Cheque Cheque::operator%(const Cheque& peer) const {
    return Cheque(receipient, (amount % peer.amount));
}

Cheque Cheque::copy() {
    Cheque fresh(receipient, amount);
    return fresh;
}

void Cheque::clear() {
    receipient.clear();
    amount.clear();
    return;
}

std::string Cheque::print() {
    std::stringstream result;
    result << receipient.print() << ",";
    result << amount.print();
	return result.str();
}

} // namespace act