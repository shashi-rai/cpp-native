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

#ifndef QFT_CHARGE_H
#define QFT_CHARGE_H

#include <sstream>
#include <vector>
#include "density.h"
#include "force.h"
#include "../shp/quantity.h"
#include "../shp/unit.h"

namespace qft {

class Charge {
    shp::Quantity quantity;
public:
    // Constructors
    Charge();
    Charge(float quantity);
    Charge(float quantity, short int scaling);
    Charge(float quantity, const shp::Unit& unit);
    Charge(float quantity, short int scaling, const shp::Unit& unit);
    Charge(const shp::Quantity& quantity, const shp::Unit& unit);

    // Destructors
    ~Charge();

    // Operator overloading
    bool operator==(const Charge& peer) const;
    Charge operator+(const Charge& peer) const;
    Charge operator-(const Charge& peer) const;
    Charge operator*(const Charge& peer) const;
    Charge operator/(const Charge& peer) const;
    Charge operator%(const Charge& peer) const;

    // Access operator
    Force operator()(const Charge& peer, const float distance) const;

    // Getters
    shp::Unit getUnit() const { return quantity.getUnit(); }
    shp::Quantity getQuantity() const { return quantity; }

    // Setters
    void setUnit(const shp::Unit& value) { this->quantity.setUnit(value); }
    void setQuantity(const float amount) { this->quantity = amount; }

    // Additional methods
    shp::Quantity getTotal() const;
    Density getDensity(const float volume) const;
    Force getForce(const float acceleration) const;
    void adjustScaling();
    virtual Charge copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const std::string UNIT;
    static const short int ATOMIC_SCALE;
    static const float PROTON;
    static const float NEUTRON;
    static const float ELECTRON;
};

typedef std::vector<Charge > ChargeArray;

} // namespace qft

#endif //QFT_CHARGE_H