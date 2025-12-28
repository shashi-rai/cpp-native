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
#include <string>
#include <vector>
#include "density.h"
#include "force.h"
#include "../shp/angular.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Mass : public shp::Quantity {
    std::shared_ptr<Field> field;
public:
    // Constructors
    Mass();
    Mass(const std::shared_ptr<Field> field);
    Mass(std::string unit);
    Mass(const shp::Unit& unit);
    Mass(const float magnitude);
    Mass(const float magnitude, std::string unit);
    Mass(const float magnitude, const shp::Unit& unit);
    Mass(const float magnitude, const short int scaling);
    Mass(const float magnitude, const short int scaling, std::string unit);
    Mass(const float magnitude, const short int scaling, const shp::Unit& unit);
    Mass(const float magnitude, const short int scaling, const shp::Unit& unit, const std::shared_ptr<Field> field);

    // Destructors
    ~Mass();

    // Operator overloading
    bool operator==(const Mass& peer) const;
    Mass operator+(const Mass& peer) const;
    Mass operator-(const Mass& peer) const;
    Mass operator*(const Mass& peer) const;
    Mass operator/(const Mass& peer) const;
    Mass operator%(const Mass& peer) const;

    // Access operator
    Force operator()(const Mass& peer, const shp::Distance sepration,
        const shp::Distance& distance) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }

    // Setters
    void setField(std::shared_ptr<Field> address) { this->field = address; }

    // Additional methods
    bool isOwned() const;
    Density getDensity(const shp::Volume& volume) const;
    Force getForce(const shp::Angular& coordinates) const;
    virtual Mass copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
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