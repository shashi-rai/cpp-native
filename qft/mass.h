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

#ifndef QFT_MASS_H
#define QFT_MASS_H

#include <sstream>
#include <vector>
#include "../shp/quantity.h"
#include "../shp/unit.h"

namespace qft {

class Mass {
    shp::Quantity quantity;
public:
    // Constructors
    Mass();
    Mass(float quantity);
    Mass(float quantity, const shp::Unit& unit);
    Mass(const shp::Quantity& quantity, const shp::Unit& unit);

    // Destructors
    ~Mass();

    // Operator overloading
    bool operator==(const Mass& peer) const;
    Mass operator+(const Mass& peer) const;
    Mass operator-(const Mass& peer) const;

    // Getters
    shp::Unit getUnit() const { return quantity.getUnit(); }
    shp::Quantity getQuantity() const { return quantity; }

    // Setters
    void setUnit(const shp::Unit& value) { this->quantity.setUnit(value); }
    void setQuantity(const float amount) { this->quantity = amount; }

    // Additional methods
    virtual Mass copy();
    virtual void clear();
    virtual std::string print();
public:
    static const std::string UNIT;
    static const short int ATOMIC_SCALE;
    static const float ATOMIC_UNIT;
    static const float PROTON;
    static const float NEUTRON;
    static const float ELECTRON;
};

typedef std::vector<Mass > MassArray;

} // namespace qft

#endif //QFT_MASS_H