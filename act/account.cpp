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

Account::Account() : name(), code(), currency(), entries() {

}

Account::Account(std::string name)
        : name(name), code(), currency(), entries() {

}

Account::Account(std::string name, std::string code)
        : name(name), code(code), currency(), entries() {

}

Account::Account(const Currency& currency)
        : name(), code(), currency(currency), entries() {

}

Account::Account(std::string name, const Currency& currency)
        : name(name), code(), currency(currency), entries() {

}

Account::Account(std::string name, const Currency& currency, std::string code)
        : name(name), code(code), currency(currency), entries() {

}

Account::Account(const TradeArray& entries)
        : name(), code(), currency(), entries(entries) {

}

Account::Account(const Currency& currency, const TradeArray& entries)
        : name(), code(), currency(currency), entries(entries) {

}

Account::Account(const Currency& currency, std::string code, const TradeArray& entries)
        : name(), code(code), currency(currency), entries(entries) {

}

Account::Account(std::string name, const TradeArray& entries)
        : name(name), code(), currency(), entries(entries) {

}

Account::Account(std::string name, std::string code, const TradeArray& entries)
        : name(name), code(code), currency(), entries(entries) {

}

Account::Account(std::string name, const Currency& currency, const TradeArray& entries)
        : name(name), code(), currency(currency), entries(entries) {

}

Account::Account(std::string name, const Currency& currency, std::string code, const TradeArray& entries)
        : name(name), code(code), currency(currency), entries(entries) {

}

Account::~Account() {

}

bool Account::operator==(const Account& peer) const {
    return (name == peer.name) && (code == peer.code)
        && (currency == peer.currency) && (entries == peer.entries);
}

Account Account::operator+(const Account& peer) const {
    TradeArray result(entries);
    result.insert(result.end(), peer.entries.begin(), peer.entries.end());
    return Account("+", currency, code, result);
}

Account Account::operator-(const Account& peer) const {
    TradeArray result(entries);
    for (TradeArray::const_iterator it = peer.entries.begin(); it != peer.entries.end(); ++it) {
        TradeArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Account("-", currency, code, result);
}

int Account::getEntryCount() const {
    return entries.size();
}

Trade Account::get(int index) const {
    Trade result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(entries.size())) {
        return result;
    }
    return entries[index];
}

void Account::set(int index, const Trade& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(entries.size())) {
        // replace existing element
        entries[index] = object;
    } else if (index == static_cast<int>(entries.size())) {
        // append at end
        entries.push_back(object);
    } else {
        // index beyond current size: append at end
        entries.push_back(object);
    }
    return;
}

Amount Account::getIncoming() {
    Amount result(0, currency, "Incoming Total");
    for (TradeArray::const_iterator it = entries.begin(); it != entries.end(); ++it) {
        float amount = (*it).getIncoming().getValue();
        result = (result + amount);
    }
    return result;
}

Amount Account::getOutgoing() {
    Amount result(0, currency, "Outgoing Total");
    for (TradeArray::const_iterator it = entries.begin(); it != entries.end(); ++it) {
        float amount = (*it).getOutgoing().getValue();
        result = (result + amount);
    }
    return result;
}

Amount Account::getBalance() {
    return (getIncoming() - getOutgoing());
}

std::string Account::findEntryImbalance() {
    std::stringstream result;
    for (TradeArray::const_iterator it = entries.begin(); it != entries.end(); ++it) {
        float amount = (*it).getBalance().getValue();
        if (amount != 0) {
            result << (*it).getIncoming().print() << " ≠ ";
            result << (*it).getOutgoing().print() << std::endl;
        }
    }
	return result.str(); 
}

Account Account::copy() {
    Account fresh(name, currency, code, entries);
    return fresh;
}

void Account::clear() {
    name.clear();
    code.clear();
    currency.clear();
    entries.clear();
    return;
}

std::string Account::print() {
    std::stringstream result;
    result << "(a:";
    result << name << ",";
    result << code << ",";
    result << currency.print() << "),sz:";
    result << entries.size();
	return result.str();
}

} // namespace act