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

#ifndef ACT_INVENTORY_H
#define ACT_INVENTORY_H

#include <sstream>
#include <string>
#include <vector>
#include "item.h"

namespace act {

class Inventory {
    std::string name;
    ItemArray items;
public:
    // Constructors
    Inventory();
    Inventory(std::string name);
    Inventory(const ItemArray& items);
    Inventory(std::string name, const ItemArray& items);

    // Destructors
    ~Inventory();

    // Operator overloading
    bool operator==(const Inventory& peer) const;
    Inventory operator+(const Inventory& peer) const;
    Inventory operator-(const Inventory& peer) const;

    // Access operator
    Item& operator()(int x) { return items[x]; }
    const Item& operator()(int x) const { return items[x]; }

    // Getters
    std::string getName() const { return name; }
    ItemArray getItems() const { return items; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setItems(const ItemArray& objects) { this->items = objects; }

    // Additional methods
    int getItemCount() const;
    Item get(int index) const;
    void set(int index, const Item& object);
    virtual Inventory copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Inventory > InventoryArray;

} // namespace act

#endif //ACT_INVENTORY_H