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
#include "charge.h"
#include "mass.h"
#include "../shp/point.h"
#include "../shp/quantity.h"
#include "../shp/unit.h"

namespace qft {

class Energy : public shp::Point {
    shp::Unit unit;
    shp::Quantity wavelength;
    qft::Mass mass;
    qft::Charge charge;
public:
    // Constructors
    Energy();
    Energy(float gradient);
    Energy(std::string name, float gradient);
    Energy(float amplitude, float gradient);
    Energy(std::string name, float amplitude, float gradient);
    Energy(float amplitude, float gradient, float wavelength);
    Energy(float amplitude, float gradient, float wavelength, short int scaling);
    Energy(std::string name, float amplitude, float gradient, float wavelength);
    Energy(std::string name, float amplitude, float gradient, float wavelength, short int scaling);
    Energy(float wavelength, const shp::Unit& unit);
    Energy(float wavelength, short int scaling, const shp::Unit& unit);
    Energy(std::string name, float wavelength, const shp::Unit& unit);
    Energy(std::string name, float wavelength, short int scaling, const shp::Unit& unit);
    Energy(Mass& mass);
    Energy(Mass& mass, const shp::Unit& unit);
    Energy(Charge& charge);
    Energy(Charge& charge, const shp::Unit& unit);
    Energy(Mass& mass, Charge& charge);
    Energy(Mass& mass, Charge& charge, const shp::Unit& unit);
    Energy(std::string name, Mass& mass);
    Energy(std::string name, Mass& mass, const shp::Unit& unit);
    Energy(float wavelength, Mass& mass);
    Energy(float wavelength, float mass, const shp::Unit& unit);
    Energy(float wavelength, Mass& mass, const shp::Unit& unit);
    Energy(float wavelength, short int scaling, float mass, const shp::Unit& unit);
    Energy(float wavelength, short int scaling, Mass& mass, const shp::Unit& unit);
    Energy(std::string name, float wavelength, float mass, const shp::Unit& unit);
    Energy(std::string name, float wavelength, Mass& mass, const shp::Unit& unit);
    Energy(std::string name, float wavelength, short int scaling, float mass, const shp::Unit& unit);
    Energy(std::string name, float wavelength, short int scaling, Mass& mass, const shp::Unit& unit);
    Energy(float amplitude, float gradient, float wavelength, float mass, const shp::Unit& unit);
    Energy(float amplitude, float gradient, float wavelength, Mass& mass, const shp::Unit& unit);
    Energy(float amplitude, float gradient, float wavelength, short int scaling, float mass, const shp::Unit& unit);
    Energy(float amplitude, float gradient, float wavelength, short int scaling, Mass& mass, const shp::Unit& unit);
    Energy(std::string name, float amplitude, float gradient, float wavelength, float mass, const shp::Unit& unit);
    Energy(std::string name, float amplitude, float gradient, float wavelength, Mass& mass, const shp::Unit& unit);
    Energy(std::string name, float amplitude, float gradient, float wavelength, short int scaling, float mass, const shp::Unit& unit);
    Energy(std::string name, float amplitude, float gradient, float wavelength, short int scaling, Mass& mass, const shp::Unit& unit);

    // Destructors
    ~Energy();

    // Operator overloading
    bool operator==(const Energy& peer) const;
    Energy operator+(const Energy& peer) const;
    Energy operator-(const Energy& peer) const;
    Energy operator*(const Energy& peer) const;
    Energy operator/(const Energy& peer) const;
    Energy operator%(const Energy& peer) const;

    // Getters
    shp::Unit getUnit() const { return unit; }
    shp::Quantity getWavelength() const { return wavelength; }
    qft::Mass getMass() const { return mass; }
    qft::Charge getCharge() const { return charge; }

    // Setters
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setWavelength(const float amount) { this->wavelength = amount; }
    void setMass(const qft::Mass& amount) { this->mass = amount; }
    void setCharge(const qft::Charge& amount) { charge = amount; }

    // Additional methods
    float getTotal() const;
    shp::Quantity getPotential() const;
    shp::Quantity getKinetic() const;
    shp::Quantity getFrequency() const;
    float getSpatial(float state) const;
    float getTemporal(float state) const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();

public:
    static const float getPhysicalLimit();

public:
    static const std::string UNIT;
    static const float PLANCK_CONSTANT;
    static const short int PLANCK_SCALE;
    static const float LIGHT_SPEED;
    static const short int LIGHT_SCALE;
};

typedef std::vector<Energy > EnergyArray;

} // namespace qft

#endif //QFT_ENERGY_H