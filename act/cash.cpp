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

#include "cash.h"

namespace act {

Cash::Cash() : Account(), batch() {

}

Cash::Cash(std::string name)
        : Account(name), batch() {

}

Cash::Cash(const Currency& currency)
        : Account(currency), batch() {

}

Cash::Cash(std::string name, const Currency& currency)
        : Account(name, currency), batch() {

}

Cash::Cash(const Batch& batch)
        : Account(), batch(batch) {

}

Cash::Cash(std::string name, const Batch& batch)
        : Account(name), batch(batch) {

}

Cash::Cash(const Batch& batch, const Currency& currency)
        : Account(currency), batch(batch) {

}

Cash::Cash(std::string name, const Batch& batch, const Currency& currency)
        : Account(name, currency), batch(batch) {

}

Cash::~Cash() {

}

bool Cash::operator==(const Cash& peer) const {
    return (static_cast<const Account&>(*this) == static_cast<const Account&>(peer))
        && (batch == peer.batch);
}

Cash Cash::operator+(const Cash& peer) const {
    return Cash("+", (batch + peer.batch), getCurrency());
}

Cash Cash::operator-(const Cash& peer) const {
    return Cash("-", (batch - peer.batch), getCurrency());
}

Account Cash::copy() {
    Cash fresh(getName(), batch, getCurrency());
    return fresh;
}

void Cash::clear() {
    Account::clear();
    batch.clear();
    return;
}

std::string Cash::print() {
    std::stringstream result;
    result << Account::print() << ",";
    result << batch.print();
	return result.str();
}

} // namespace act