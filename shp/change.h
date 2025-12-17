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

#ifndef SHP_CHANGE_H
#define SHP_CHANGE_H

#include <sstream>
#include <string>
#include <vector>
#include "direction.h"
#include "quantity.h"
#include "unit.h"

namespace shp {

class Change {
    Direction gradient;
    Quantity kinetic;
    Quantity potential;
public:
    // Constructors
    Change();
    Change(const float gradient);
    Change(const float gradient, short int scaling);
    Change(const float gradient, short int scaling, std::string unit);
    Change(const float gradient, short int scaling, const Unit& unit);
    Change(const Direction& gradient);
    Change(const float gradient, const float potential);
    Change(const float gradient, const float potential, short int scaling);
    Change(const float gradient, const float potential, short int scaling, std::string unit);
    Change(const float gradient, const float potential, short int scaling, const Unit& unit);
    Change(const Quantity& potential);
    Change(const Quantity& kinetic, const Quantity& potential);
    Change(const Direction& gradient, const Quantity& potential);
    Change(const Direction& gradient, const Quantity& kinetic, const Quantity& potential);
    Change(const float gradient, const float kinetic, const float potential);
    Change(const float gradient, const float kinetic, const float potential, short int scaling);
    Change(const float gradient, const float kinetic, const float potential, short int scaling, std::string unit);
    Change(const float gradient, const float kinetic, const float potential, short int scaling, const Unit& unit);

    // Destructors
    ~Change();

    // Operator overloading
    bool operator==(const Change& peer) const;
    Change operator+(const Change& peer) const;
    Change operator-(const Change& peer) const;
    Change operator*(const Change& peer) const;
    Change operator/(const Change& peer) const;
    Change operator%(const Change& peer) const;

    // Getters
    Direction getGradient() const { return gradient; }
    Quantity getKinetic() const { return kinetic; }
    Quantity getPotential() const { return potential; }

    // Setters
    void setGradient(const float phase) { this->gradient = Direction(phase); }
    void setGradient(const Direction& phase) { this->gradient = phase; }
    void setKinetic(const Quantity& energy) { this->kinetic = energy; }
    void setPotential(const Quantity& energy) { this->potential = energy; }

    // Additional methods
    float toRadians() const;
    Quantity getLagrangian() const;
    Quantity getHamiltonian() const;
    float leastAction();
    virtual Change copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Change > ChangeArray;

} // namespace shp

#endif //SHP_CHANGE_H