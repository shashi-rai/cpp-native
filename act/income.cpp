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

#include "income.h"

namespace act {
 
Income::Income() : name(), currency(), revenues(), expenses() {

}

Income::Income(std::string name)
        : name(name), currency(), revenues(), expenses() {

}

Income::Income(const Currency& currency)
        : name(), currency(currency), revenues(), expenses() {

}

Income::Income(const RevenueArray& revenues)
        : name(), currency(), revenues(revenues), expenses() {

}

Income::Income(const Currency& currency, const RevenueArray& revenues)
        : name(), currency(currency), revenues(revenues), expenses() {

}

Income::Income(const ExpenseArray& expenses)
        : name(), currency(), revenues(), expenses(expenses) {

}

Income::Income(const Currency& currency, const ExpenseArray& expenses)
        : name(), currency(currency), revenues(), expenses(expenses) {

}

Income::Income(const RevenueArray& revenues, const ExpenseArray& expenses)
        : name(), currency(), revenues(revenues), expenses(expenses) {

}

Income::Income(const Currency& currency, const RevenueArray& revenues, const ExpenseArray& expenses)
        : name(), currency(currency), revenues(revenues), expenses(expenses) {

}

Income::Income(std::string name, const RevenueArray& revenues)
        : name(name), currency(), revenues(revenues), expenses() {

}

Income::Income(std::string name, const Currency& currency, const RevenueArray& revenues)
        : name(name), currency(currency), revenues(revenues), expenses() {

}

Income::Income(std::string name, const ExpenseArray& expenses)
        : name(name), currency(), revenues(), expenses(expenses) {

}

Income::Income(std::string name, const Currency& currency, const ExpenseArray& expenses)
        : name(name), currency(currency), revenues(), expenses(expenses) {

}

Income::Income(std::string name, const RevenueArray& revenues, const ExpenseArray& expenses)
        : name(name), currency(), revenues(revenues), expenses(expenses) {

}

Income::Income(std::string name, const Currency& currency,
        const RevenueArray& revenues, const ExpenseArray& expenses)
        : name(name), currency(currency), revenues(revenues), expenses(expenses) {

}

Income::~Income() {

}

bool Income::operator==(const Income& peer) const {
    return (name == peer.name) && (currency == peer.currency)
        && (revenues == peer.revenues) && (expenses == peer.expenses);
}

Income Income::operator+(const Income& peer) const {
    RevenueArray incoming(revenues);
    incoming.insert(incoming.end(), peer.revenues.begin(), peer.revenues.end());
    ExpenseArray outgoing(expenses);
    outgoing.insert(outgoing.end(), peer.expenses.begin(), peer.expenses.end());
    return Income("+", currency, incoming, outgoing);
}

Income Income::operator-(const Income& peer) const {
    RevenueArray incoming(revenues);
    for (RevenueArray::const_iterator it = peer.revenues.begin(); it != peer.revenues.end(); ++it) {
        RevenueArray::iterator found = std::find(incoming.begin(), incoming.end(), *it);
        if (found != incoming.end()) {
            incoming.erase(found);
        }
    }
    ExpenseArray outgoing(expenses);
    for (ExpenseArray::const_iterator it = peer.expenses.begin(); it != peer.expenses.end(); ++it) {
        ExpenseArray::iterator found = std::find(outgoing.begin(), outgoing.end(), *it);
        if (found != outgoing.end()) {
            outgoing.erase(found);
        }
    }
    return Income("-", currency, incoming, outgoing);
}

int Income::getRevenueCount() const {
    return revenues.size();
}

Revenue Income::getRevenue(int index) const {
    Revenue result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(revenues.size())) {
        return result;
    }
    return revenues[index];
}

void Income::setRevenue(int index, const Revenue& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(revenues.size())) {
        // replace existing element
        revenues[index] = object;
    } else if (index == static_cast<int>(revenues.size())) {
        // append at end
        revenues.push_back(object);
    } else {
        // index beyond current size: append at end
        revenues.push_back(object);
    }
    return;
}

int Income::getExpenseCount() const {
    return expenses.size();
}

Expense Income::getExpense(int index) const {
    Expense result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(expenses.size())) {
        return result;
    }
    return expenses[index];
}

void Income::setExpense(int index, const Expense& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(expenses.size())) {
        // replace existing element
        expenses[index] = object;
    } else if (index == static_cast<int>(expenses.size())) {
        // append at end
        expenses.push_back(object);
    } else {
        // index beyond current size: append at end
        expenses.push_back(object);
    }
    return;
}

Amount Income::getRevenueTotal() const {
    Amount result(0, "Revenue Total");
    for (RevenueArray::const_iterator it = revenues.begin(); it != revenues.end(); ++it) {
        float amount = (*it).getValue();
        result = (result + amount);
    }
    return result;
}

Amount Income::getExpenseTotal() const {
    Amount result(0, "Expense Total");
    for (ExpenseArray::const_iterator it = expenses.begin(); it != expenses.end(); ++it) {
        float amount = (*it).getValue();
        result = (result + amount);
    }
    return result;
}

Amount Income::getBalance() const {
    return (getRevenueTotal() - getExpenseTotal());
}

Income Income::copy() {
    Income fresh(name, currency, revenues, expenses);
    return fresh;
}

void Income::clear() {
    name.clear();
    currency.clear();
    revenues.clear();
    expenses.clear();
    return;
}

std::string Income::print() {
    std::stringstream result;
    result << name << ",";
    result << currency.print() << ",sz:";
    result << revenues.size() << ",sz:";
    result << expenses.size();
	return result.str();
}

} // namespace act