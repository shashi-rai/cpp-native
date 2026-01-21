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

#include "density.h"
#include "force.h"
#include "../shp/potential.h"
#include "../shp/temporal.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Charge : public shp::Temporal {
    std::shared_ptr<Field> field;
public:
    // Constructors
    Charge();
    Charge(const std::shared_ptr<Field> field);
    Charge(std::string unit);
    Charge(const shp::Unit& unit);
    Charge(const shp::Unit& unit, const std::shared_ptr<Field> field);
    Charge(const float magnitude);
    Charge(const float magnitude, const std::shared_ptr<Field> field);
    Charge(const float magnitude, std::string unit);
    Charge(const float magnitude, const shp::Unit& unit);
    Charge(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field);
    Charge(const float magnitude, const short int scaling);
    Charge(const float magnitude, const short int scaling, const std::shared_ptr<Field> field);
    Charge(const float magnitude, const short int scaling, std::string unit);
    Charge(const float magnitude, const short int scaling, const shp::Unit& unit);
    Charge(const float magnitude, const short int scaling, const shp::Unit& unit, const std::shared_ptr<Field> field);

    // Destructors
    ~Charge();

    // Operator overloading
    bool operator==(const Charge& peer) const;
    bool operator<(const Charge& peer) const;
    bool operator>(const Charge& peer) const;
    bool operator<=(const Charge& peer) const;
    bool operator>=(const Charge& peer) const;
    Charge operator+(const Charge& peer) const;
    Charge operator-(const Charge& peer) const;
    Charge operator*(const Charge& peer) const;
    Charge operator/(const Charge& peer) const;
    Charge operator%(const Charge& peer) const;

    // Access operator
    Force operator()(const Charge& peer, const shp::Distance separation,
        const shp::Distance position) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }

    // Setters
    void setField(std::shared_ptr<Field> address) { this->field = address; }

    // Additional methods
    bool isOwned() const;
    shp::Distance getRadius() const;
    void setRadius(const shp::Distance& length);
    shp::Potential getPotential() const;
    Density getDensity(const shp::Volume& volume) const;
    Force getForce(const shp::Angular& coordinates) const;
    std::shared_ptr<Field> getOriginField() const;
    virtual Charge copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Temporal getFluctuation(const float phase) const;
public:
    static const std::string UNIT;
    static const std::string ELECTRIC_FIELD;
    static const short int ATOMIC_SCALE;
    static const float PROTON;
    static const float NEUTRON;
    static const float ELECTRON;
};

typedef std::vector<Charge > ChargeArray;

} // namespace qft

#endif //QFT_CHARGE_H