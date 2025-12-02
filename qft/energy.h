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

#ifndef QFT_ENERGY_H
#define QFT_ENERGY_H

#include <sstream>
#include <vector>
#include "../shp/quantity.h"
#include "../shp/unit.h"

namespace qft {

class Energy {
    shp::Quantity kinetic;
    shp::Quantity potential;
public:
    // Constructors
    Energy();
    Energy(float kinetic);
    Energy(float kinetic, float potential);
    Energy(float kinetic, float potential, const shp::Unit& unit);

    // Destructors
    ~Energy();

    // Operator overloading
    bool operator==(const Energy& peer) const;
    Energy operator+(const Energy& peer) const;
    Energy operator-(const Energy& peer) const;

    // Getters
    shp::Quantity getKinetic() const { return kinetic; }
    shp::Quantity getPotential() const { return potential; }

    // Setters
    void setKinetic(const float amount) { this->kinetic = amount; }
    void setPotential(const float amount) { this->potential = amount; }

    // Additional methods
    virtual Energy copy();
    virtual void clear();
    virtual std::string print();

public:
    static const float PLANCK_CONSTANT;
    static const short int PLANCK_SCALE;
};

typedef std::vector<Energy > EnergyArray;

} // namespace qft

#endif //QFT_ENERGY_H