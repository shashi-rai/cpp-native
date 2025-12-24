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

#ifndef ACT_ORDER_H
#define ACT_ORDER_H

#include <sstream>
#include <string>
#include <vector>
#include "amount.h"
#include "item.h"
#include "transaction.h"

namespace act {

class Order : public Transaction {
    ItemArray items;
public:
    // Constructors
    Order();
    Order(const float value);
    Order(const float value, std::string remarks);
    Order(const float value, const Currency& currency, std::string remarks);
    Order(const long datetime, const float value, std::string remarks);
    Order(const long datetime, const float value, const Currency& currency, std::string remarks);
    Order(std::string remarks);
    Order(std::string remarks, const ItemArray& items);
    Order(const float value, std::string remarks, const ItemArray& items);
    Order(const float value, const Currency& currency, std::string remarks, const ItemArray& items);
    Order(const long datetime, const float value, std::string remarks, const ItemArray& items);
    Order(const long datetime, const float value, const Currency& currency, std::string remarks, const ItemArray& items);

    // Destructors
    ~Order();

    // Operator overloading
    bool operator==(const Order& peer) const;
    Order operator+(const Order& peer) const;
    Order operator-(const Order& peer) const;

    // Access operator
    Item& operator()(int x) { return items[x]; }
    const Item& operator()(int x) const { return items[x]; }

    // Getters
    ItemArray getItems() const { return items; }

    // Setters
    void setItems(const ItemArray& objects) { this->items = objects; }

    // Additional methods
    int getItemCount() const;
    Item get(int index) const;
    void set(int index, const Item& object);
    virtual Amount getCostTotal();
    virtual Amount getSaleTotal();
    virtual Amount copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Order > OrderArray;

} // namespace act

#endif //ACT_ORDER_H