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
    Unit(const std::string name);
    Unit(const short int prefix, const std::string name);
    Unit(const std::string name, const std::string suffix);
    Unit(const short int prefix, const std::string name, const std::string suffix);

    // Destructors
    ~Unit();

    // Operator overloading
    bool operator==(const Unit& peer) const;
    Unit operator+(const Unit& peer) const;

    // Getters
    std::string getName() const { return name; }

    // Setters
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    void setName(const short int prefix, const std::string name);
    void setName(const std::string name, const std::string suffix);
    void setName(const short int prefix, const std::string name, const std::string suffix);
    std::string getModulus() const;
    std::string getInverse() const;
    std::string getPercent() const;
    std::string getSquare() const;
    std::string getSquareRoot() const;
    std::string getCube() const;
    std::string getCubeRoot() const;
    virtual Unit copy() const;
    virtual void clear();
    virtual std::string print() const;

public:
    static const std::string getPrefixName(const short int index);
    static const std::string getPrefixSymbol(const short int index);
    static const short int getPrefixBase(const short int index);
    static const std::string getBaseName(const short int index);
    static const std::string getBaseDimension(const short int index);
    static const std::string getBaseSymbol(const short int index);
    static const std::string getDerivedName(const short int index);
    static const std::string getDerivedDimension(const short int index);
    static const std::string getDerivedSymbol(const short int index);

public:
    static const std::string UNKNOWN;
    static const short int PREFIX_MIN;
    static const short int PREFIX_MAX;
    static const std::string PER_UNIT;
    enum PREFIX {
        QUETTA, RONNA, YOTTA, ZETTA, EXA, PETA, TERA, GIGA, MEGA, KILO, HECTO, DECA,
        ZERO,
        DECI, CENTI, MILLI, MICRO, NANO, PICO, FEMTO, ATTO, ZEPTO, YOCTO, RONTO, QUECTO,
    };
    static const std::string PREFIX_NAME[];
    static const std::string PREFIX_SYMBOL[];
    static const short int PREFIX_BASE[];
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