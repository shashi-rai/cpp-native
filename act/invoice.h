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

#ifndef ACT_INVOICE_H
#define ACT_INVOICE_H

#include <sstream>
#include <string>
#include <vector>
#include "order.h"

namespace act {

class Invoice {
    std::string name;
    Order order;
public:
    // Constructors
    Invoice();
    Invoice(std::string name);
    Invoice(const Order& order);
    Invoice(std::string name, const Order& order);

    // Destructors
    ~Invoice();

    // Operator overloading
    bool operator==(const Invoice& peer) const;

    // Getters
    std::string getName() const { return name; }
    Order getOrder() const { return order; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setOrder(const Order& object) { this->order = object; }

    // Additional methods
    virtual Invoice copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Invoice > InvoiceArray;

} // namespace act

#endif //ACT_INVOICE_H