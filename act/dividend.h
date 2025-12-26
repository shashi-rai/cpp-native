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

#ifndef ACT_DIVIDEND_H
#define ACT_DIVIDEND_H

#include <sstream>
#include <string>
#include <vector>
#include "amount.h"

namespace act {

class Dividend {
    std::string name;
    float rate;
    Amount principal;
public:
    // Constructors
    Dividend();
    Dividend(std::string name);
    Dividend(const float rate);
    Dividend(const Amount& principal);
    Dividend(const float rate, const Amount& principal);
    Dividend(std::string name, const Amount& principal);
    Dividend(std::string name, const float rate, const Amount& principal);

    // Destructors
    ~Dividend();

    // Operator overloading
    bool operator==(const Dividend& peer) const;
    Dividend operator+(const Dividend& peer) const;
    Dividend operator-(const Dividend& peer) const;
    Dividend operator*(const Dividend& peer) const;
    Dividend operator/(const Dividend& peer) const;
    Dividend operator%(const Dividend& peer) const;

    // Getters
    std::string getName() const { return name; }
    float getRate() const { return rate; }
    Amount getPrincipal() const { return principal; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void getRate(const float rate) { this->rate = rate; }
    void setPrincipal(const Amount& value) { this->principal = value; }

    // Additional methods
    Amount getSimple(const float time);
    Amount getCompound(const short int period, const float time);
    virtual Dividend copy();
    virtual void clear();
    virtual std::string print();
public:
    static const float DEFAULT_VALUE;
};

typedef std::vector<Dividend > DividendArray;

} // namespace act

#endif //ACT_DIVIDEND_H