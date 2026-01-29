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

#ifndef QFT_CURRENT_H
#define QFT_CURRENT_H

#include "charge.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Current : protected qft::Charge {
    qft::Velocity velocity;
public:
    // Constructors
    Current();
    Current(const std::string name);
    Current(const qft::Charge& charge);
    Current(const float charge);
    Current(const float charge, const std::string unit);
    Current(const float charge, const shp::Unit& unit);
    Current(const float charge, const short int scaling);
    Current(const float charge, const short int scaling, const std::string unit);
    Current(const float charge, const short int scaling, const shp::Unit& unit);
    Current(const qft::Velocity& velocity);
    Current(const std::string name, const qft::Charge& charge);
    Current(const std::string name, const float charge);
    Current(const std::string name, const float charge, const std::string unit);
    Current(const std::string name, const float charge, const shp::Unit& unit);
    Current(const std::string name, const float charge, const short int scaling);
    Current(const std::string name, const float charge, const short int scaling, const std::string unit);
    Current(const std::string name, const float charge, const short int scaling, const shp::Unit& unit);
    Current(const qft::Charge& charge, const qft::Velocity& velocity);
    Current(const float charge, const float velocity);
    Current(const std::string name, const float charge, const float velocity);

    // Destructors
    ~Current();

    // Operator overloading
    bool operator==(const Current& peer) const;
    bool operator<(const Current& peer) const;
    bool operator>(const Current& peer) const;
    bool operator<=(const Current& peer) const;
    bool operator>=(const Current& peer) const;
    Current operator+(const Current& peer) const;
    Current operator-(const Current& peer) const;
    Current operator*(const Current& peer) const;
    Current operator/(const Current& peer) const;
    Current operator%(const Current& peer) const;

    // Charge operator
    Current operator+(const Charge& peer) const;
    Current operator-(const Charge& peer) const;
    Current operator*(const Charge& peer) const;
    Current operator/(const Charge& peer) const;
    Current operator%(const Charge& peer) const;

    // Velocity operator
    Current operator+(const Velocity& peer) const;
    Current operator-(const Velocity& peer) const;
    Current operator*(const Velocity& peer) const;
    Current operator/(const Velocity& peer) const;
    Current operator%(const Velocity& peer) const;

    // Getters
    qft::Velocity getVelocity() const { return velocity; }

    // Setters
    void setVelocity(const qft::Velocity& object) { this->velocity = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    qft::Charge getCharge() const;
    void setCharge(const qft::Charge& object);
    shp::Quantity getMass();
    shp::Quantity getElectrons() const;
    void setElectrons(const int count);
    void changeFlowSpeed(const float motion);
    void changeDirection(const float degree);
    shp::Signal getVoltage() const;
    shp::Signal getForce(const Time& interval) const;
    shp::Signal getPotential() const;
    shp::Signal getChargeFlow() const;
    shp::Signal getInductance() const;
    shp::Signal getElectricPower() const;
    shp::Signal getElectroKinetic() const;
    shp::Signal getMagneticPower() const;
    shp::Signal getMagnetoKinetic() const;
    shp::Signal getRateOfChange() const;
    std::shared_ptr<Field> getElectricField() const;
    std::shared_ptr<Field> getMagneticField() const;
    bool checkNonZero() const;
    virtual shp::Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const Current getLooping(const Current unitary, const float multiplier);
    static const shp::Quantity getAmpereCoulombs();
    static const shp::Quantity getAmpereFlowRate();
public:
    static const std::string UNIT;
    static const std::string COULOMB_SECOND;
    static const std::string ELECTRIC_FIELD;
    static const std::string MAGNETIC_FIELD;
    static const float ELECTRON_FLOW_RATE;
    static const short int ELECTRON_FLOW_SCALE;
};

typedef std::vector<Current > CurrentArray;

} // namespace qft

#endif //QFT_CURRENT_H