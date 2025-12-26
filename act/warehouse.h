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

#ifndef ACT_WAREHOUSE_H
#define ACT_WAREHOUSE_H

#include <sstream>
#include <string>
#include <vector>
#include "branch.h"
#include "inventory.h"

namespace act {

class Warehouse : public Branch {
    Inventory saleable;
    Inventory expired;
public:
    // Constructors
    Warehouse();
    Warehouse(std::string name);
    Warehouse(const Inventory& saleable);
    Warehouse(const Inventory& saleable, const Inventory& expired);
    Warehouse(std::string name, const Inventory& saleable);
    Warehouse(std::string name, const Inventory& saleable, const Inventory& expired);
    Warehouse(const gis::Address& address);
    Warehouse(const Inventory& saleable, const gis::Address& address);
    Warehouse(const Inventory& saleable, const Inventory& expired, const gis::Address& address);
    Warehouse(std::string name, const gis::Address& address);
    Warehouse(std::string name, const Inventory& saleable, const gis::Address& address);
    Warehouse(std::string name, const Inventory& saleable, const Inventory& expired, const gis::Address& address);

    // Destructors
    ~Warehouse();

    // Operator overloading
    bool operator==(const Warehouse& peer) const;

    // Getters
    Inventory getSaleable() const { return saleable; }
    Inventory getExpired() const { return expired; }

    // Setters
    void setSaleable(const Inventory& items) { this->saleable = items; }
    void setExpired(const Inventory& items) { this->expired = items; }

    // Additional methods
    virtual Branch copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Warehouse > WarehouseArray;

} // namespace act

#endif //ACT_WAREHOUSE_H