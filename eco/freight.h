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

#ifndef ECO_FREIGHT_H
#define ECO_FREIGHT_H

#include "market.h"

namespace eco {

class Freight : public Market {

public:
    // Constructors
    Freight();
    Freight(const Demand& demand);
    Freight(const Supply& supply);
    Freight(const Population& population);
    Freight(const Demand& demand, const Supply& supply);
    Freight(const Demand& demand, const Population& population);
    Freight(const Supply& supply, const Population& population);
    Freight(const Demand& demand, const Supply& supply, const Population& population);
    Freight(const std::string name);
    Freight(const std::string name, const Demand& demand);
    Freight(const std::string name, const Supply& supply);
    Freight(const std::string name, const Population& population);
    Freight(const std::string name, const Demand& demand, const Supply& supply);
    Freight(const std::string name, const Demand& demand, const Population& population);
    Freight(const std::string name, const Supply& supply, const Population& population);
    Freight(const std::string name, const Demand& demand, const Supply& supply, const Population& population);

    // Destructors
    ~Freight();

    // Operator overloading
    bool operator==(const Freight& peer) const;

    // Getters

    // Setters

    // Additional methods
    virtual Market copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Freight > FreightArray;

} // namespace eco

#endif //ECO_FREIGHT_H