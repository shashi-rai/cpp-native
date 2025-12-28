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

#ifndef ACT_INCOME_H
#define ACT_INCOME_H

#include <sstream>
#include <string>
#include <vector>
#include "expense.h"
#include "revenue.h"

namespace act {

class Income {
    std::string name;
    Currency currency;
    RevenueArray revenues;
    ExpenseArray expenses;
public:
    // Constructors
    Income();
    Income(std::string name);
    Income(const Currency& currency);
    Income(std::string name, const Currency& currency);
    Income(const RevenueArray& revenues);
    Income(const Currency& currency, const RevenueArray& revenues);
    Income(const ExpenseArray& expenses);
    Income(const Currency& currency, const ExpenseArray& expenses);
    Income(const RevenueArray& revenues, const ExpenseArray& expenses);
    Income(const Currency& currency, const RevenueArray& revenues, const ExpenseArray& expenses);
    Income(std::string name, const RevenueArray& revenues);
    Income(std::string name, const Currency& currency, const RevenueArray& revenues);
    Income(std::string name, const ExpenseArray& expenses);
    Income(std::string name, const Currency& currency, const ExpenseArray& expenses);
    Income(std::string name, const RevenueArray& revenues, const ExpenseArray& expenses);
    Income(std::string name, const Currency& currency, const RevenueArray& revenues, const ExpenseArray& expenses);

    // Destructors
    ~Income();

    // Operator overloading
    bool operator==(const Income& peer) const;
    Income operator+(const Income& peer) const;
    Income operator-(const Income& peer) const;

    // Getters
    std::string getName() const { return name; }
    Currency getCurrency() const { return currency; }
    RevenueArray getRevenues() const { return revenues; }
    ExpenseArray getExpenses() const { return expenses; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setCurrency(const Currency& object) { this->currency = object; }
    void setRevenues(const RevenueArray& object) { this->revenues = object; }
    void setExpenses(const ExpenseArray& object) { this->expenses = object; }

    // Additional methods
    int getRevenueCount() const;
    Revenue getRevenue(int index) const;
    void setRevenue(int index, const Revenue& object);
    int getExpenseCount() const;
    Expense getExpense(int index) const;
    void setExpense(int index, const Expense& object);
    virtual Amount getRevenueTotal() const;
    virtual Amount getExpenseTotal() const;
    virtual Amount getBalance() const;
    virtual Income copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Income > IncomeArray;

} // namespace act

#endif //ACT_INCOME_H