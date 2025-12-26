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

#ifndef ACT_CHART_H
#define ACT_CHART_H

#include <sstream>
#include <string>
#include <vector>
#include "account.h"
#include "balance.h"

namespace act {

class Chart {
    std::string name;
    Balance balance;
    AccountArray accounts;
public:
    // Constructors
    Chart();
    Chart(std::string name);
    Chart(const Balance& balance);
    Chart(const AccountArray& accounts);
    Chart(std::string name, const Balance& balance);
    Chart(std::string name, const AccountArray& accounts);
    Chart(std::string name, const Balance& balance, const AccountArray& accounts);

    // Destructors
    ~Chart();

    // Operator overloading
    bool operator==(const Chart& peer) const;
    Chart operator+(const Chart& peer) const;
    Chart operator-(const Chart& peer) const;

    // Access operator
    Account& operator()(int x) { return accounts[x]; }
    const Account& operator()(int x) const { return accounts[x]; }

    // Getters
    std::string getName() const { return name; }
    Balance getBalance() const { return balance; }
    AccountArray getAccounts() const { return accounts; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setBalance(const Balance& object) { this->balance = object; }
    void setAccounts(const AccountArray& object) { this->accounts = object; }

    // Additional methods
    int getAccountCount() const;
    Account get(int index) const;
    void set(int index, const Account& object);
    virtual Chart copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Chart > ChartArray;

} // namespace act

#endif //ACT_CHART_H