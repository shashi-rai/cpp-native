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

#ifndef ACT_BANK_H
#define ACT_BANK_H

#include <sstream>
#include <string>
#include <vector>
#include "ledger.h"
#include "party.h"

namespace act {

class Bank : public Party {
    LedgerArray accounts;
public:
    // Constructors
    Bank();
    Bank(std::string name);
    Bank(const LedgerArray& accounts);
    Bank(std::string name, const LedgerArray& accounts);

    // Destructors
    ~Bank();

    // Operator overloading
    bool operator==(const Bank& peer) const;
    Bank operator+(const Bank& peer) const;
    Bank operator-(const Bank& peer) const;

    // Access operator
    Ledger& operator()(int x) { return accounts[x]; }
    const Ledger& operator()(int x) const { return accounts[x]; }

    // Getters
    LedgerArray getLedgers() const { return accounts; }

    // Setters
    void setLedgers(const LedgerArray& object) { this->accounts = object; }

    // Additional methods
    int getLedgerCount() const;
    Ledger get(int index) const;
    void set(int index, const Ledger& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Bank > BankArray;

} // namespace act

#endif //ACT_BANK_H