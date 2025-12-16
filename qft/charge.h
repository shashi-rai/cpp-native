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
#include <string>
#include <vector>
#include "density.h"
#include "force.h"
#include "../shp/angular.h"
#include "../shp/quantity.h"
#include "../shp/unit.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Charge {
    std::shared_ptr<Field> field;
    shp::Quantity magnitude;
public:
    // Constructors
    Charge();
    Charge(const std::shared_ptr<Field> field);
    Charge(std::string unit);
    Charge(const shp::Unit& unit);
    Charge(const float magnitude);
    Charge(const float magnitude, std::string unit);
    Charge(const float magnitude, const shp::Unit& unit);
    Charge(const float magnitude, short int scaling);
    Charge(const float magnitude, short int scaling, std::string unit);
    Charge(const float magnitude, short int scaling, const shp::Unit& unit);
    Charge(const shp::Quantity& magnitude);
    Charge(const std::shared_ptr<Field> field, const shp::Quantity& magnitude);

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
    std::shared_ptr<Field> getField() const { return field; }
    shp::Quantity getMagnitude() const { return magnitude; }

    // Setters
    void setField(std::shared_ptr<Field> address) { this->field = address; }
    void setMagnitude(const float amount) { this->magnitude = amount; }

    // Additional methods
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& value);
    bool isOwned() const;
    shp::Quantity getTotal() const;
    Density getDensity(const shp::Volume& volume) const;
    Force getForce(const shp::Angular& coordinates) const;
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