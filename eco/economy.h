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

#ifndef ECO_ECONOMY_H
#define ECO_ECONOMY_H

#include "market.h"
#include "../act/currency.h"

namespace eco {

class Economy : public Market {
    act::Currency currency;
public:
    // Constructors
    Economy();
    Economy(const Demand& demand);
    Economy(const Supply& supply);
    Economy(const Population& population);
    Economy(const Demand& demand, const Supply& supply);
    Economy(const Demand& demand, const Population& population);
    Economy(const Supply& supply, const Population& population);
    Economy(const Demand& demand, const Supply& supply, const Population& population);
    Economy(const std::string name);
    Economy(const std::string name, const Demand& demand);
    Economy(const std::string name, const Supply& supply);
    Economy(const std::string name, const Population& population);
    Economy(const std::string name, const Demand& demand, const Supply& supply);
    Economy(const std::string name, const Demand& demand, const Population& population);
    Economy(const std::string name, const Supply& supply, const Population& population);
    Economy(const std::string name, const Demand& demand, const Supply& supply, const Population& population);

    // Destructors
    ~Economy();

    // Operator overloading
    bool operator==(const Economy& peer) const;

    // Getters
    act::Currency getCurrency() const { return currency; }

    // Setters
    void setCurrency(const act::Currency& object) { this->currency = object; }

    // Additional methods
    virtual Market copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Economy > EconomyArray;

} // namespace eco

#endif //ECO_ECONOMY_H