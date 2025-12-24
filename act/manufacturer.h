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

#ifndef ACT_MANUFACTURER_H
#define ACT_MANUFACTURER_H

#include <sstream>
#include <string>
#include <vector>
#include "factory.h"
#include "party.h"

namespace act {

class Manufacturer : public Party {
    FactoryArray factories;
public:
    // Constructors
    Manufacturer();
    Manufacturer(std::string name);
    Manufacturer(const FactoryArray& factories);
    Manufacturer(std::string name, const FactoryArray& factories);

    // Destructors
    ~Manufacturer();

    // Operator overloading
    bool operator==(const Manufacturer& peer) const;
    Manufacturer operator+(const Manufacturer& peer) const;
    Manufacturer operator-(const Manufacturer& peer) const;

    // Access operator
    Factory& operator()(int x) { return factories[x]; }
    const Factory& operator()(int x) const { return factories[x]; }

    // Getters
    FactoryArray getFactories() const { return factories; }

    // Setters
    void setFactories(const FactoryArray& object) { this->factories = object; }

    // Additional methods
    int getFactoryCount() const;
    Factory get(int index) const;
    void set(int index, const Factory& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Manufacturer > ManufacturerArray;

} // namespace act

#endif //ACT_MANUFACTURER_H