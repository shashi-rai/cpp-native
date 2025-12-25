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

#ifndef ACT_FEES_H
#define ACT_FEES_H

#include <sstream>
#include <string>
#include <vector>
#include "amount.h"

namespace act {

class Fees {
    std::string name;
    Amount amount;
public:
    // Constructors
    Fees();
    Fees(std::string name);
    Fees(const Amount& amount);
    Fees(std::string name, const Amount& amount);

    // Destructors
    ~Fees();

    // Operator overloading
    bool operator==(const Fees& peer) const;
    Fees operator+(const Fees& peer) const;
    Fees operator-(const Fees& peer) const;
    Fees operator*(const Fees& peer) const;
    Fees operator/(const Fees& peer) const;
    Fees operator%(const Fees& peer) const;

    // Getters
    std::string getName() const { return name; }
    Amount getAmount() const { return amount; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setAmount(const Amount& value) { this->amount = value; }

    // Additional methods
    virtual Fees copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Fees > FeesArray;

} // namespace act

#endif //ACT_FEES_H