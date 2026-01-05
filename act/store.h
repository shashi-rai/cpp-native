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

#ifndef ACT_STORE_H
#define ACT_STORE_H

#include <sstream>
#include <string>
#include <vector>
#include "warehouse.h"

namespace act {

class Store : public Warehouse {
    doc::Document taxation;
public:
    // Constructors
    Store();
    Store(std::string name);
    Store(const Inventory& saleable);
    Store(std::string name, const Inventory& saleable);
    Store(const gis::Address& address);
    Store(const Inventory& saleable, const gis::Address& address);
    Store(std::string name, const gis::Address& address);
    Store(std::string name, const Inventory& saleable, const gis::Address& address);

    // Destructors
    ~Store();

    // Operator overloading
    bool operator==(const Store& peer) const;

    // Getters
    doc::Document getTaxation() const { return taxation; }

    // Setters
    void setTaxation(const doc::Document& certificate) { this->taxation = certificate; }

    // Additional methods
    virtual Branch copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Store > StoreArray;

} // namespace act

#endif //ACT_STORE_H