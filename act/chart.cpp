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

#include "chart.h"

namespace act {

Chart::Chart() : name(), balance(), accounts() {

}

Chart::Chart(std::string name)
        : name(name), balance(), accounts() {

}

Chart::Chart(const Balance& balance)
        : name(), balance(balance), accounts() {

}

Chart::Chart(const AccountArray& accounts)
        : name(), balance(), accounts(accounts) {

}

Chart::Chart(std::string name, const Balance& balance)
        : name(name), balance(balance), accounts() {

}

Chart::Chart(std::string name, const AccountArray& accounts)
        : name(name), balance(), accounts(accounts) {

}

Chart::Chart(std::string name, const Balance& balance, const AccountArray& accounts)
        : name(name), balance(balance), accounts(accounts) {

}

Chart::~Chart() {

}

bool Chart::operator==(const Chart& peer) const {
    return (name == peer.name) && (balance == peer.balance) && (accounts == peer.accounts);
}

Chart Chart::operator+(const Chart& peer) const {
    AccountArray result(accounts);
    result.insert(result.end(), peer.accounts.begin(), peer.accounts.end());
    return Chart("+", (balance + peer.balance), result);
}

Chart Chart::operator-(const Chart& peer) const {
    AccountArray result(accounts);
    for (AccountArray::const_iterator it = peer.accounts.begin(); it != peer.accounts.end(); ++it) {
        AccountArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Chart("-", (balance - peer.balance), result);
}

int Chart::getAccountCount() const {
    return accounts.size();
}

Account Chart::get(int index) const {
    Account result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(accounts.size())) {
        return result;
    }
    return accounts[index];
}

void Chart::set(int index, const Account& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(accounts.size())) {
        // replace existing element
        accounts[index] = object;
    } else if (index == static_cast<int>(accounts.size())) {
        // append at end
        accounts.push_back(object);
    } else {
        // index beyond current size: append at end
        accounts.push_back(object);
    }
    return;
}

Chart Chart::copy() {
    Chart fresh(name, balance, accounts);
    return fresh;
}

void Chart::clear() {
    name = "";
    balance.clear();
    accounts.clear();
    return;
}

std::string Chart::print() {
    std::stringstream result;
    result << "CA![";
    result << name << ",";
    result << balance.print() << ",sz:";
    result << accounts.size() << "]!";
	return result.str();
}

} // namespace act