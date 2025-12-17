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
#include "../shp/cellular.h"
#include "../shp/potential.h"
#include "../shp/shape.h"

namespace qft {

// To enable compiler resolve forward declarations
class Charge;
class Mass;

class Field : public shp::Cellular {
    std::shared_ptr<shp::Shape> physical;
    shp::Potential potential;
    shp::Direction direction;
public:
    // Constructors
    Field();
    Field(std::string name);
    Field(const std::shared_ptr<shp::Shape> physical);
    Field(std::string name, const std::shared_ptr<shp::Shape> physical);
    Field(const float direction);
    Field(const shp::Direction& direction);
    Field(const float potential, const float direction);
    Field(const shp::Potential& potential, const shp::Direction& direction);
    Field(std::string name, const float direction);
    Field(std::string name, const shp::Direction& direction);
    Field(std::string name, const float direction, const std::shared_ptr<shp::Shape> physical);
    Field(std::string name, const shp::Direction& direction, const std::shared_ptr<shp::Shape> physical);
    Field(std::string name, const float potential, const float direction);
    Field(std::string name, const float potential, const float direction, const std::shared_ptr<shp::Shape> physical);
    Field(std::string name, const shp::Potential& potential, const shp::Direction& direction);
    Field(std::string name, const shp::Potential& potential, const shp::Direction& direction, const std::shared_ptr<shp::Shape> physical);

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
    std::shared_ptr<shp::Shape> getPhysical() const { return physical; }
    shp::Potential getPotential() const { return potential; }
    shp::Direction getDirection() const { return direction; }

    // Setters
    void setPhysical(const std::shared_ptr<shp::Shape> structure) { this->physical = structure; }
    void setPotential(const shp::Potential& difference) { this->potential = difference; }
    void setDirection(const shp::Direction& direction) { this->direction = direction; }

    // Additional methods
    bool isStructured() const;
    void changePoint(const Action& action);
    Particle* getDivergence(const Action& action) const;
    Particle* getConvergence(const Action& action) const;
    shp::Quantity getTotal() const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
};

typedef std::vector<Field > FieldArray;

} // namespace qft

#endif //QFT_FIELD_H