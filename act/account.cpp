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

#include "account.h"

namespace act {

Account::Account() : name(), currency(), transactions() {

}

Account::Account(std::string name)
        : name(name), currency(), transactions() {

}

Account::Account(std::string name, const Currency& currency)
        : name(name), currency(currency), transactions() {

}

Account::Account(const TradeArray& transactions)
        : name(), currency(), transactions(transactions) {

}

Account::Account(const Currency& currency, const TradeArray& transactions)
        : name(), currency(currency), transactions(transactions) {

}

Account::Account(std::string name, const TradeArray& transactions)
        : name(name), currency(), transactions(transactions) {

}

Account::Account(std::string name, const Currency& currency, const TradeArray& transactions)
        : name(name), currency(currency), transactions(transactions) {

}

Account::~Account() {

}

bool Account::operator==(const Account& peer) const {
    return (name == peer.name) && (currency == peer.currency) && (transactions == peer.transactions);
}

Account Account::operator+(const Account& peer) const {
    TradeArray result(transactions);
    result.insert(result.end(), peer.transactions.begin(), peer.transactions.end());
    return Account("+", currency, result);
}

Account Account::operator-(const Account& peer) const {
    TradeArray result(transactions);
    for (TradeArray::const_iterator it = peer.transactions.begin(); it != peer.transactions.end(); ++it) {
        TradeArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Account("-", currency, result);
}

int Account::getTransactionCount() const {
    return transactions.size();
}

Trade Account::get(int index) const {
    Trade result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(transactions.size())) {
        return result;
    }
    return transactions[index];
}

void Account::set(int index, const Trade& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(transactions.size())) {
        // replace existing element
        transactions[index] = object;
    } else if (index == static_cast<int>(transactions.size())) {
        // append at end
        transactions.push_back(object);
    } else {
        // index beyond current size: append at end
        transactions.push_back(object);
    }
    return;
}

Amount Account::getIncoming() {
    Amount result(0, currency, "Incoming Total");
    for (TradeArray::const_iterator it = transactions.begin(); it != transactions.end(); ++it) {
        float amount = (*it).getIncoming().getValue();
        result = (result + amount);
    }
    return result;
}

Amount Account::getOutgoing() {
    Amount result(0, currency, "Outgoing Total");
    for (TradeArray::const_iterator it = transactions.begin(); it != transactions.end(); ++it) {
        float amount = (*it).getOutgoing().getValue();
        result = (result + amount);
    }
    return result;
}

Amount Account::getBalance() {
    return (getOutgoing() - getIncoming());
}

Account Account::copy() {
    Account fresh(name, currency, transactions);
    return fresh;
}

void Account::clear() {
    name = "";
    currency.clear();
    transactions.clear();
    return;
}

std::string Account::print() {
    std::stringstream result;
    result << name << ",";
    result << currency.print() << ",sz:";
    result << transactions.size();
	return result.str();
}

} // namespace act