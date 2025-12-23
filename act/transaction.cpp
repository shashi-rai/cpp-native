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

#include "transaction.h"

namespace act {

Transaction::Transaction() : Amount(), customer(), supplier() {

}

Transaction::Transaction(const float value)
        : Amount(value), customer(), supplier() {

}

Transaction::Transaction(std::string remarks)
        : Amount(remarks), customer(), supplier() {

}

Transaction::Transaction(const float value, std::string remarks)
        : Amount(value, remarks), customer(), supplier() {

}

Transaction::Transaction(const float value, const Currency& currency, std::string remarks)
        : Amount(value, currency, remarks), customer(), supplier() {

}

Transaction::Transaction(const long datetime, const float value,
        std::string remarks)
        : Amount(datetime, value, remarks), customer(), supplier() {

}

Transaction::Transaction(const long datetime, const float value,
        const Currency& currency, std::string remarks)
        : Amount(datetime, value, currency, remarks), customer(), supplier() {

}

Transaction::Transaction(const Customer& customer)
        : Amount(), customer(customer), supplier() {

}

Transaction::Transaction(const Supplier& supplier)
        : Amount(), customer(), supplier(supplier) {

}

Transaction::Transaction(const Customer& customer, const Supplier& supplier)
        : Amount(), customer(customer), supplier(supplier) {

}

Transaction::~Transaction() {

}

bool Transaction::operator==(const Transaction& peer) const {
    return (static_cast<const Amount&>(*this) == static_cast<const Amount&>(peer))
        && (customer == peer.customer) && (supplier == peer.supplier);
}

void Transaction::clear() {
    Amount::clear();
    customer.clear();
    supplier.clear();
    return;
}

std::string Transaction::print() {
    std::stringstream result;
    result << Amount::print() << ",";
	result << customer.print() << ",";
    result << supplier.print();
	return result.str();
}

} // namespace act