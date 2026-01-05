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

#ifndef ACT_FACTORY_H
#define ACT_FACTORY_H

#include <sstream>
#include <string>
#include <vector>
#include "warehouse.h"

namespace act {

class Factory : public Warehouse {
    Inventory material;
    Inventory working;
    doc::Document license;
public:
    // Constructors
    Factory();
    Factory(std::string name);
    Factory(const Inventory& working);
    Factory(const Inventory& material, const Inventory& working);
    Factory(std::string name, const Inventory& working);
    Factory(std::string name, const Inventory& material, const Inventory& working);
    Factory(const gis::Address& address);
    Factory(const Inventory& working, const gis::Address& address);
    Factory(const Inventory& material, const Inventory& working, const gis::Address& address);
    Factory(std::string name, const gis::Address& address);
    Factory(std::string name, const Inventory& working, const gis::Address& address);
    Factory(std::string name, const Inventory& material, const Inventory& working, const gis::Address& address);

    // Destructors
    ~Factory();

    // Operator overloading
    bool operator==(const Factory& peer) const;

    // Getters
    Inventory getMaterial() const { return material; }
    Inventory getWorking() const { return working; }
    doc::Document getLicense() const { return license; }

    // Setters
    void setMaterial(const Inventory& raw) { this->material = raw; }
    void setWorking(const Inventory& items) { this->working = items; }
    void setLicense(const doc::Document& certificate) { this->license = certificate; }

    // Additional methods
    virtual Branch copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Factory > FactoryArray;

} // namespace act

#endif //ACT_FACTORY_H