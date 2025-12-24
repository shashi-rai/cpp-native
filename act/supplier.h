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

#ifndef ACT_SUPPLIER_H
#define ACT_SUPPLIER_H

#include <sstream>
#include <string>
#include <vector>
#include "party.h"

namespace act {

class Supplier : public Party {
    PartyArray partners;
public:
    // Constructors
    Supplier();
    Supplier(std::string name);
    Supplier(const PartyArray& partners);
    Supplier(std::string name, const PartyArray& partners);

    // Destructors
    ~Supplier();

    // Operator overloading
    bool operator==(const Supplier& peer) const;
    Supplier operator+(const Supplier& peer) const;
    Supplier operator-(const Supplier& peer) const;

    // Access operator
    Party& operator()(int x) { return partners[x]; }
    const Party& operator()(int x) const { return partners[x]; }

    // Getters
    PartyArray getPartners() const { return partners; }

    // Setters
    void setPartners(const PartyArray& object) { this->partners = object; }

    // Additional methods
    int getPartnerCount() const;
    Party get(int index) const;
    void set(int index, const Party& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Supplier > SupplierArray;

} // namespace act

#endif //ACT_SUPPLIER_H