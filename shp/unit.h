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

#ifndef SHP_UNIT_H
#define SHP_UNIT_H

#include <sstream>
#include <string>
#include <vector>

namespace shp {

class Unit {
    std::string name;
public:
    // Constructors
    Unit();
    Unit(std::string name);

    // Destructors
    ~Unit();

    // Getters
    std::string getName() const { return name; }

    // Operator overloading
    bool operator==(const Unit& peer) const;

    // Setters
    void setName(const std::string& name) { this->name = name; }

    // Additional methods
    virtual Unit copy();
    virtual void clear();
    virtual std::string print();

public:
    static std::string getBaseName(short int index);
    static std::string getBaseDimension(short int index);
    static std::string getBaseSymbol(short int index);
    static std::string getDerivedName(short int index);
    static std::string getDerivedDimension(short int index);
    static std::string getDerivedSymbol(short int index);

public:
    static const std::string UNKNOWN;
    enum BASE {
        TIME, LENGTH, MASS, CURRENT, TEMPERATURE, SUBSTANCE, LUMINOUSITY
    };
    static const short int SI_BASE_MIN;
    static const short int SI_BASE_MAX;
    static const std::string BASE_NAME[];
    static const std::string BASE_DIMENSION[];
    static const std::string BASE_SYMBOL[];
    enum DERIVED {
        PLANE_ANGLE, SOLID_ANGLE, FREQUENCY, FORCE, PRESSURE, ENERGY, POWER,
        ELECTRIC_CHARGE, ELECTRIC_POTENTIAL, CAPACITANCE, ELECTRIC_RESISTANCE,
        ELECTRIC_CONDUCTANCE, MAGNETIC_FLUX, MAGNETIC_FLUX_DENSITY, INDUCTANCE,
        CELSIUS_TEMPERATURE, LUMINOUS_FLUX, ILLUMINANCE, ACTIVITY_RADIONUCLIDE,
        ABSORBED_DOSE, DOSE_EQUIVALENT, CATALYTIC_ACTIVITY,
    };
    static const short int SI_DERIVED_MIN;
    static const short int SI_DERIVED_MAX;
    static const std::string DERIVED_NAME[];
    static const std::string DERIVED_DIMENSION[];
    static const std::string DERIVED_SYMBOL[];
};

typedef std::vector<Unit > UnitArray;

} // namespace shp

#endif //SHP_UNIT_H