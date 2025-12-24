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

#ifndef ACT_RETAILER_H
#define ACT_RETAILER_H

#include <sstream>
#include <string>
#include <vector>
#include "party.h"
#include "store.h"

namespace act {

class Retailer : public Party {
    StoreArray stores;
public:
    // Constructors
    Retailer();
    Retailer(std::string name);
    Retailer(const StoreArray& stores);
    Retailer(std::string name, const StoreArray& stores);

    // Destructors
    ~Retailer();

    // Operator overloading
    bool operator==(const Retailer& peer) const;
    Retailer operator+(const Retailer& peer) const;
    Retailer operator-(const Retailer& peer) const;

    // Access operator
    Store& operator()(int x) { return stores[x]; }
    const Store& operator()(int x) const { return stores[x]; }

    // Getters
    StoreArray getStores() const { return stores; }

    // Setters
    void setStores(const StoreArray& object) { this->stores = object; }

    // Additional methods
    int getStoreCount() const;
    Store get(int index) const;
    void set(int index, const Store& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Retailer > RetailerArray;

} // namespace act

#endif //ACT_RETAILER_H