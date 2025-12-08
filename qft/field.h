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

#ifndef QFT_FIELD_H
#define QFT_FIELD_H

#include <vector>
#include "action.h"
#include "charge.h"
#include "mass.h"
#include "particle.h"
#include "spin.h"
#include "../shp/cellular.h"
#include "../shp/shape.h"

namespace qft {

class Field : public shp::Cellular {
    shp::Shape* physical;
    Spin defaultSpin;
    Mass defaultMass;
    Charge defaultCharge;
public:
    // Constructors
    Field();
    Field(Spin& spin);
    Field(std::string name);
    Field(std::string name, Spin& spin);
    Field(Mass& mass, Charge& charge);
    Field(std::string name, Mass& mass, Charge& charge);
    Field(Spin& spin, Mass& mass, Charge& charge);
    Field(std::string name, Spin& spin, Mass& mass, Charge& charge);
    Field(shp::Shape* physical);
    Field(std::string name, shp::Shape* physical);
    Field(std::string name, shp::Shape* physical, Spin& spin);
    Field(std::string name, shp::Shape* physical, Spin& spin, Mass& mass);
    Field(shp::Shape* physical, Spin& spin, Mass& mass, Charge& charge);
    Field(std::string name, shp::Shape* physical, Spin& spin, Mass& mass, Charge& charge);

    // Destructors
    ~Field();

    // Operator overloading
    bool operator==(const Field& peer) const;
    Field operator+(const Field& peer) const;
    Field operator-(const Field& peer) const;

    // Access operator
    Point operator()(int x, int y, int z) { return this->get(x).get(y).get(z); }
	const Point operator()(int x, int y, int z) const { return this->get(x).get(y).get(z); }

    // Getters
    shp::Shape* getPhysical() const { return physical; }
    Spin getDefaultSpin() const { return defaultSpin; }
    Mass getDefaultMass() const { return defaultMass; }
    Charge getDefaultCharge() const { return defaultCharge; }

    // Setters
    void setPhysical(shp::Shape* structure) { this->physical = structure; }
    void setDefaultSpin(const Spin& value) { defaultSpin = value; }
    void setDefaultMass(const Mass& value) { defaultMass = value; }
    void setDefaultCharge(const Charge& value) { defaultCharge = value; }

    // Additional methods
    bool isStructured() const;
    void changePoint(Action& action);
    Particle* getDivergence(Action& action) const;
    Particle* getConvergence(Action& action) const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Field > FieldArray;

} // namespace qft

#endif //QFT_FIELD_H