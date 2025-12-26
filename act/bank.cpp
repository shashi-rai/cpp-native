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

#include "bank.h"

namespace act {

Bank::Bank() : Party(), accounts() {

}

Bank::Bank(std::string name)
        : Party(name), accounts() {

}

Bank::Bank(const LedgerArray& accounts)
        : Party(), accounts(accounts) {

}

Bank::Bank(std::string name, const LedgerArray& accounts)
        : Party(name), accounts(accounts) {

}

Bank::~Bank() {

}

bool Bank::operator==(const Bank& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (accounts == peer.accounts);
}

Bank Bank::operator+(const Bank& peer) const {
    LedgerArray result(accounts);
    result.insert(result.end(), peer.accounts.begin(), peer.accounts.end());
    return Bank("+", result);
}

Bank Bank::operator-(const Bank& peer) const {
    LedgerArray result(accounts);
    for (LedgerArray::const_iterator it = peer.accounts.begin(); it != peer.accounts.end(); ++it) {
        LedgerArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Bank("-", result);
}

int Bank::getLedgerCount() const {
    return accounts.size();
}

Ledger Bank::get(int index) const {
    Ledger result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(accounts.size())) {
        return result;
    }
    return accounts[index];
}

void Bank::set(int index, const Ledger& object) {
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

Party Bank::copy() {
    Bank fresh(getName(), accounts);
    return fresh;
}

void Bank::clear() {
    Party::clear();
    accounts.clear();
    return;
}

std::string Bank::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << accounts.size();
	return result.str();
}

} // namespace act