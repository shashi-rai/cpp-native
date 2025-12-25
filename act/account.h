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

#ifndef ACT_ACCOUNT_H
#define ACT_ACCOUNT_H

#include <sstream>
#include <string>
#include <vector>
#include "trade.h"

namespace act {

class Account {
    std::string name;
    Currency currency;
    TradeArray transactions;
public:
    // Constructors
    Account();
    Account(std::string name);
    Account(std::string name, const Currency& currency);
    Account(const TradeArray& transactions);
    Account(const Currency& currency, const TradeArray& transactions);
    Account(std::string name, const TradeArray& transactions);
    Account(std::string name, const Currency& currency, const TradeArray& transactions);

    // Destructors
    ~Account();

    // Operator overloading
    bool operator==(const Account& peer) const;
    Account operator+(const Account& peer) const;
    Account operator-(const Account& peer) const;

    // Access operator
    Trade& operator()(int x) { return transactions[x]; }
    const Trade& operator()(int x) const { return transactions[x]; }

    // Getters
    std::string getName() const { return name; }
    Currency getCurrency() const { return currency; }
    TradeArray getTransactions() const { return transactions; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setCurrency(const Currency& object) { this->currency = object; }
    void setTransactions(const TradeArray& objects) { this->transactions = objects; }

    // Additional methods
    int getTransactionCount() const;
    Trade get(int index) const;
    void set(int index, const Trade& object);
    virtual Amount getIncoming();
    virtual Amount getOutgoing();
    virtual Amount getBalance();
    virtual Account copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Account > AccountArray;

} // namespace act

#endif //ACT_ACCOUNT_H