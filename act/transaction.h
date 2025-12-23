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

#ifndef ACT_TRANSACTION_H
#define ACT_TRANSACTION_H

#include <sstream>
#include <string>
#include <vector>
#include "amount.h"
#include "customer.h"
#include "supplier.h"

namespace act {

// abstract

class Transaction : public Amount {
    Customer customer;
    Supplier supplier;
public:
    // Constructors
    Transaction();
    Transaction(const float value);
    Transaction(std::string remarks);
    Transaction(const float value, std::string remarks);
    Transaction(const float value, const Currency& currency, std::string remarks);
    Transaction(const long datetime, const float value, std::string remarks);
    Transaction(const long datetime, const float value, const Currency& currency, std::string remarks);
    Transaction(const Customer& customer);
    Transaction(const Supplier& supplier);
    Transaction(const Customer& customer, const Supplier& supplier);

    // Destructors
    ~Transaction();

    // Operator overloading
    bool operator==(const Transaction& peer) const;

    // Getters
    Customer getCustomer() const { return customer; }
    Supplier getSupplier() const { return supplier; }

    // Setters
    void setCustomer(const Customer& object) { this->customer = object; }
    void setSupplier(const Supplier& object) { this->supplier = object; }

    // Additional methods
    virtual Amount getTotal() = 0;
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Transaction > TransactionArray;

} // namespace act

#endif //ACT_TRANSACTION_H