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

#include "order.h"

namespace act {

Order::Order() : Transaction(), items() {

}

Order::Order(const float value)
        : Transaction(value), items() {

}

Order::Order(const float value, std::string remarks)
        : Transaction(value, remarks), items() {

}

Order::Order(const float value, const Currency& currency, std::string remarks)
        : Transaction(value, currency, remarks), items() {

}

Order::Order(const long datetime, const float value, std::string remarks)
        : Transaction(datetime, value, remarks), items() {

}

Order::Order(const long datetime, const float value, const Currency& currency, std::string remarks)
        : Transaction(datetime, value, currency, remarks), items() {

}

Order::Order(std::string remarks)
        : Transaction(remarks), items() {

}

Order::Order(std::string remarks, const ItemArray& items)
        : Transaction(remarks), items(items) {

}

Order::Order(const float value, std::string remarks, const ItemArray& items)
        : Transaction(value, remarks), items(items) {

}

Order::Order(const float value, const Currency& currency,
        std::string remarks, const ItemArray& items)
        : Transaction(value, currency, remarks), items(items) {

}

Order::Order(const long datetime, const float value,
        std::string remarks, const ItemArray& items)
        : Transaction(datetime, value, remarks), items(items) {

}

Order::Order(const long datetime, const float value, const Currency& currency,
        std::string remarks, const ItemArray& items)
        : Transaction(datetime, value, currency, remarks), items(items) {

}

Order::~Order() {

}

bool Order::operator==(const Order& peer) const {
    return (static_cast<const Transaction&>(*this) == static_cast<const Transaction&>(peer))
        && (items == peer.items);
}

Order Order::operator+(const Order& peer) const {
    ItemArray result(items);
    result.insert(result.end(), peer.items.begin(), peer.items.end());
    return Order("+", result);
}

Order Order::operator-(const Order& peer) const {
    ItemArray result(items);
    for (ItemArray::const_iterator it = peer.items.begin(); it != peer.items.end(); ++it) {
        ItemArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Order("-", result);
}

int Order::getItemCount() const {
    return items.size();
}

Item Order::get(int index) const {
    Item result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(items.size())) {
        return result;
    }
    return items[index];
}

void Order::set(int index, const Item& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(items.size())) {
        // replace existing element
        items[index] = object;
    } else if (index == static_cast<int>(items.size())) {
        // append at end
        items.push_back(object);
    } else {
        // index beyond current size: append at end
        items.push_back(object);
    }
    return;
}

Amount Order::getCostTotal() {
    Amount result(0, getCurrency(), "Cost Total");
    for (ItemArray::const_iterator it = items.begin(); it != items.end(); ++it) {
        Cost cost = (*it).getCost();
        result = (result + cost.getAmount());
    }
    return result;
}

Amount Order::getSaleTotal() {
    Amount result(0, getCurrency(), "Sale Total");
    for (ItemArray::const_iterator it = items.begin(); it != items.end(); ++it) {
        Sale sale = (*it).getSale();
        result = (result + sale.getAmount());
    }
    return result;
}

Amount Order::copy() {
    Order fresh(getDateTime().getValue(), getValue(), getCurrency(), getRemarks(), this->items);
    return fresh;
}

void Order::clear() {
    Transaction::clear();
    items.clear();
    return;
}

std::string Order::print() {
    std::stringstream result;
    result << "{O:";
	result << Transaction::print() << ",sz:";
	result << items.size() << "}";
	return result.str();
}

} // namespace act