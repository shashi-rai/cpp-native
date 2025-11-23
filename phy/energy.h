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

#ifndef PHY_ENERGY_H
#define PHY_ENERGY_H

#include <string>
#include <vector>
#include "unit.h"

namespace phy {

class Energy {
    std::string name;
    Unit unit;
    double kinetic;
    double potential;
public:
    // Constructors
    Energy();
    Energy(std::string name, const Unit& unit);
    Energy(std::string name, const Unit& unit, double kinetic, double potential);

    // Destructors
    ~Energy();

    // Getters
    std::string getName() const { return name; }
    Unit getUnit() const { return unit; }
    double getKinetic() const { return kinetic; }
    double getPotential() const { return potential; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setUnit(const Unit& value) { this->unit = value; }
    void setKinetic(double value) { this->kinetic = value; }
    void setPotential(double value) { this->potential = value; }
};

typedef std::vector<Energy > EnergyArray;

} // namespace phy

#endif //PHY_ENERGY_H