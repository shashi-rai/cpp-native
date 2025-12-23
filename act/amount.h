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

#ifndef ACT_AMOUNT_H
#define ACT_AMOUNT_H

#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include "currency.h"
#include "datetime.h"

namespace act {

class Amount {
    DateTime datetime;
    float value;
    Currency currency;
    std::string remarks;
public:
    // Constructors
    Amount();
    Amount(const float value);
    Amount(std::string remarks);
    Amount(const Currency& currency);
    Amount(const Currency& currency, std::string remarks);
    Amount(const float value, std::string remarks);
    Amount(const float value, const Currency& currency);
    Amount(const float value, const Currency& currency, std::string remarks);
    Amount(const long datetime, const float value, std::string remarks);
    Amount(const long datetime, const float value, const Currency& currency, std::string remarks);

    // Destructors
    ~Amount();

    // Operator overloading
    bool operator==(const Amount& peer) const;
    Amount operator+(const Amount& peer) const;
    Amount operator-(const Amount& peer) const;
    Amount operator*(const Amount& peer) const;
    Amount operator/(const Amount& peer) const;
    Amount operator%(const Amount& peer) const;

    // Getters
    DateTime getDateTime() const { return datetime; }
    float getValue() const { return value; }
    Currency getCurrency() const { return currency; }
    std::string getRemarks() const { return remarks; }

    // Setters
    void setDatetime(const DateTime& value) { this->datetime = value; }
    void setValue(const float monetary) { this->value = monetary; }
    void setCurrency(const Currency& object) { this->currency = object; }
    void setRemarks(const std::string& description) { this->remarks = description; }

    // Additional methods
    virtual Amount copy();
    virtual void clear();
    virtual std::string print();

public:
    static const float DEFAULT_VALUE;
};

typedef std::vector<Amount > AmountArray;

} // namespace act

#endif //ACT_AMOUNT_H