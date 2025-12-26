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

#include "receivable.h"

namespace act {

Receivable::Receivable() : Account(), batch() {

}

Receivable::Receivable(std::string name)
        : Account(name), batch() {

}

Receivable::Receivable(const Currency& currency)
        : Account(currency), batch() {

}

Receivable::Receivable(std::string name, const Currency& currency)
        : Account(name, currency), batch() {

}

Receivable::Receivable(const Batch& batch)
        : Account(), batch(batch) {

}

Receivable::Receivable(std::string name, const Batch& batch)
        : Account(name), batch(batch) {

}

Receivable::Receivable(const Batch& batch, const Currency& currency)
        : Account(currency), batch(batch) {

}

Receivable::Receivable(std::string name, const Batch& batch, const Currency& currency)
        : Account(name, currency), batch(batch) {

}

Receivable::~Receivable() {

}

bool Receivable::operator==(const Receivable& peer) const {
    return (static_cast<const Account&>(*this) == static_cast<const Account&>(peer))
        && (batch == peer.batch);
}

Receivable Receivable::operator+(const Receivable& peer) const {
    return Receivable("+", (batch + peer.batch), getCurrency());
}

Receivable Receivable::operator-(const Receivable& peer) const {
    return Receivable("-", (batch - peer.batch), getCurrency());
}

Account Receivable::copy() {
    Receivable fresh(getName(), batch, getCurrency());
    return fresh;
}

void Receivable::clear() {
    Account::clear();
    batch.clear();
    return;
}

std::string Receivable::print() {
    std::stringstream result;
    result << Account::print() << ",";
    result << batch.print();
	return result.str();
}

} // namespace act