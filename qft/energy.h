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
#include "density.h"
#include "mass.h"
#include "time.h"
#include "../shp/distance.h"
#include "../shp/phase.h"

namespace qft {

class Energy : public shp::Phase {
    shp::Unit unit;                 // Standard Unit of Measure
    shp::Distance wavelength;       // Kinetic Energy as Planck wave
    qft::Mass mass;                 // Potential Energy as conserved
    qft::Charge charge;             // Cause of Kinetic Energy
public:
    // Constructors
    Energy();
    Energy(std::string name);
    Energy(const float gradient);
    Energy(std::string name, const float gradient);
    Energy(const float amplitude, const float gradient);
    Energy(std::string name, const float amplitude, const float gradient);
    Energy(const float amplitude, const float gradient,
        const float wavelength);
    Energy(const float amplitude, const float gradient,
        const float wavelength, const short int scaling);
    Energy(std::string name, const float amplitude, const float gradient,
        const float wavelength);
    Energy(std::string name, const float amplitude, const float gradient,
        const float wavelength, const short int scaling);
    Energy(const float wavelength,
        const shp::Unit& unit);
    Energy(const float wavelength, const short int scaling,
        const shp::Unit& unit);
    Energy(std::string name, const float wavelength,
        const shp::Unit& unit);
    Energy(std::string name, const float wavelength, const short int scaling,
        const shp::Unit& unit);
    Energy(const Mass& mass);
    Energy(const Mass& mass, const shp::Unit& unit);
    Energy(const Charge& charge);
    Energy(const Charge& charge, const shp::Unit& unit);
    Energy(const Mass& mass, const Charge& charge);
    Energy(const Mass& mass, const Charge& charge,
        const shp::Unit& unit);
    Energy(std::string name, const Mass& mass,
        const Charge& charge);
    Energy(std::string name, const Mass& mass, const Charge& charge,
        const shp::Unit& unit);
    Energy(std::string name, const Mass& mass);
    Energy(std::string name, const Mass& mass,
        const shp::Unit& unit);
    Energy(std::string name, const Charge& charge);
    Energy(std::string name, const Charge& charge,
        const shp::Unit& unit);
    Energy(const float wavelength, const Mass& mass);
    Energy(const float wavelength, const Charge& charge);
    Energy(const float wavelength, const Mass& mass, const Charge& charge);
    Energy(const float wavelength, const float mass,
        const shp::Unit& unit);
    Energy(const float wavelength, const Mass& mass,
        const shp::Unit& unit);
    Energy(const float wavelength, const Charge& charge,
        const shp::Unit& unit);
    Energy(const float wavelength, const Mass& mass, const Charge& charge,
        const shp::Unit& unit);
    Energy(const float wavelength, const short int scaling,
        const float mass, const shp::Unit& unit);
    Energy(const float wavelength, const short int scaling,
        const Mass& mass, const shp::Unit& unit);
    Energy(const float wavelength, const short int scaling,
        const Charge& charge, const shp::Unit& unit);
    Energy(const float wavelength, const short int scaling,
        const Mass& mass, const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float wavelength,
        const float mass, const shp::Unit& unit);
    Energy(std::string name, const float wavelength,
        const Mass& mass, const shp::Unit& unit);
    Energy(std::string name, const float wavelength,
        const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float wavelength,
        const Mass& mass, const Charge& charge);
    Energy(std::string name, const float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float wavelength, const short int scaling,
        const float mass, const shp::Unit& unit);
    Energy(std::string name, const float wavelength, const short int scaling,
        const Mass& mass, const shp::Unit& unit);
    Energy(std::string name, const float wavelength, const short int scaling,
        const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float wavelength, const short int scaling,
        const Mass& mass, const Charge& charge);
    Energy(std::string name, const float wavelength, const short int scaling,
        const Mass& mass, const Charge& charge, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const float mass, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const Mass& mass, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const Charge& charge, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const Mass& mass, const Charge& charge);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const short int scaling, float mass, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const Mass& mass, const shp::Unit& unit);
    Energy(const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const Mass& mass);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const Charge& charge);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const Mass& mass, const Charge& charge);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const Mass& mass, const Charge& charge);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const Mass& mass, const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const float mass, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const Mass& mass, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const float mass, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const Mass& mass, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const Charge& charge, const shp::Unit& unit);
    Energy(std::string name, const float amplitude, const float gradient, const float wavelength,
        const short int scaling, const Mass& mass, const Charge& charge, const shp::Unit& unit);

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
    shp::Distance getWavelength() const { return wavelength; }
    qft::Mass getMass() const { return mass; }
    qft::Charge getCharge() const { return charge; }

    // Setters
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setWavelength(const shp::Distance& length) { this->wavelength = length; }
    void setMass(const qft::Mass& amount) { this->mass = amount; }
    void setCharge(const qft::Charge& quantum) { charge = quantum; }

    // Additional methods
    shp::Quantity getTotal() const;
    Density getDensity(const shp::Volume& volume) const;
    shp::Quantity getPotential() const;
    shp::Quantity getKinetic() const;
    shp::Quantity getFrequency() const;
    shp::Distance getDivergence(const float modulation) const;
    qft::Time getPerpetuity(const float modulation) const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const shp::Quantity getPhysicalLimit();
    static const shp::Quantity getElectronvolt(const float quantum);
    static const shp::Quantity getMegaElectronvolt(const float quantum);
    static const shp::Quantity getGigaElectronvolt(const float quantum);
    static const shp::Quantity getTeraElectronvolt(const float quantum);
public:
    static const std::string UNIT;
    static const float PLANCK_CONSTANT;
    static const short int PLANCK_SCALE;
    static const float ELECTRON_VOLT;
    static const short int EV_SCALE;
    static const short int MEV_SCALE;
    static const short int GEV_SCALE;
    static const short int TEV_SCALE;
    static const float LIGHT_SPEED;
    static const short int LIGHT_SCALE;
};

typedef std::vector<Energy > EnergyArray;

} // namespace qft

#endif //QFT_ENERGY_H