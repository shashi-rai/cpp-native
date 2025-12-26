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
    std::string code;
    Currency currency;
    TradeArray entries;
public:
    // Constructors
    Account();
    Account(std::string name);
    Account(std::string name, std::string code);
    Account(const Currency& currency);
    Account(std::string name, const Currency& currency);
    Account(std::string name, const Currency& currency, std::string code);
    Account(const TradeArray& entries);
    Account(const Currency& currency, const TradeArray& entries);
    Account(const Currency& currency, std::string code, const TradeArray& entries);
    Account(std::string name, const TradeArray& entries);
    Account(std::string name, std::string code, const TradeArray& entries);
    Account(std::string name, const Currency& currency, const TradeArray& entries);
    Account(std::string name, const Currency& currency, std::string code, const TradeArray& entries);

    // Destructors
    ~Account();

    // Operator overloading
    bool operator==(const Account& peer) const;
    Account operator+(const Account& peer) const;
    Account operator-(const Account& peer) const;

    // Access operator
    Trade& operator()(int x) { return entries[x]; }
    const Trade& operator()(int x) const { return entries[x]; }

    // Getters
    std::string getName() const { return name; }
    std::string getCode() const { return code; }
    Currency getCurrency() const { return currency; }
    TradeArray getEntries() const { return entries; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setcode(const std::string& code) { this->code = name; }
    void setCurrency(const Currency& object) { this->currency = object; }
    void setEntries(const TradeArray& objects) { this->entries = objects; }

    // Additional methods
    int getEntryCount() const;
    Trade get(int index) const;
    void set(int index, const Trade& object);
    virtual Amount getIncoming();
    virtual Amount getOutgoing();
    virtual Amount getBalance();
    virtual std::string findEntryImbalance();
    virtual Account copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Account > AccountArray;

} // namespace act

#endif //ACT_ACCOUNT_H