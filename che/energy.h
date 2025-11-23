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

#ifndef CHE_ENERGY_H
#define CHE_ENERGY_H

#include <vector>
#include "unit.h"

namespace che {

class Energy {
    Unit unit;
    double ionisation;
    double kinetic;
    double potential;
    double heat;
public:
    // Constructors
    Energy();
    Energy(const Unit& unit, double ionisation, double kinetic, double potential, double heat);

    // Destructors
    ~Energy();

    // Getters
    Unit getUnit() const { return unit; }
    double getIonisation() const { return ionisation; }
    double getKinetic() const { return kinetic; }
    double getPotential() const { return potential; }
    double getHeat() const { return heat; }

    // Setters
    void setUnit(const Unit& value) { this->unit = value; }
    void setIonisation(const double value) { this->ionisation = value; }
    void setKinetic(const double value) { this->kinetic = value; }
    void setPotential(const double value) { this->potential = value; }
    void setHeat(const double value) { this->heat = value; }
};

typedef std::vector<Energy > EnergyArray;

} // namespace che

#endif //CHE_ENERGY_H