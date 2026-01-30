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

#ifndef QFT_MOMENTUM_H
#define QFT_MOMENTUM_H

#include "mass.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Momentum : protected qft::Mass {
    qft::Velocity velocity;
public:
    // Constructors
    Momentum();
    Momentum(const std::string name);
    Momentum(const qft::Mass& mass);
    Momentum(const float mass);
    Momentum(const float mass, const std::string unit);
    Momentum(const float mass, const shp::Unit& unit);
    Momentum(const float mass, const short int scaling);
    Momentum(const float mass, const short int scaling, const std::string unit);
    Momentum(const float mass, const short int scaling, const shp::Unit& unit);
    Momentum(const qft::Velocity& velocity);
    Momentum(const std::string name, const qft::Mass& mass);
    Momentum(const std::string name, const float mass);
    Momentum(const std::string name, const float mass, const std::string unit);
    Momentum(const std::string name, const float mass, const shp::Unit& unit);
    Momentum(const std::string name, const float mass, const short int scaling);
    Momentum(const std::string name, const float mass, const short int scaling, const std::string unit);
    Momentum(const std::string name, const float mass, const short int scaling, const shp::Unit& unit);
    Momentum(const std::string name, const float mass, const float velocity);
    Momentum(const float mass, const float velocity);
    Momentum(const qft::Mass& mass, const qft::Velocity& velocity);

    // Destructors
    ~Momentum();

    // Operator overloading
    bool operator==(const Momentum& peer) const;
    bool operator<(const Momentum& peer) const;
    bool operator>(const Momentum& peer) const;
    bool operator<=(const Momentum& peer) const;
    bool operator>=(const Momentum& peer) const;
    Momentum operator+(const Momentum& peer) const;
    Momentum operator-(const Momentum& peer) const;
    Momentum operator*(const Momentum& peer) const;
    Momentum operator/(const Momentum& peer) const;
    Momentum operator%(const Momentum& peer) const;

    // Mass operator
    Momentum operator+(const Mass& peer) const;
    Momentum operator-(const Mass& peer) const;
    Momentum operator*(const Mass& peer) const;
    Momentum operator/(const Mass& peer) const;
    Momentum operator%(const Mass& peer) const;

    // Velocity operator
    Momentum operator+(const Velocity& peer) const;
    Momentum operator-(const Velocity& peer) const;
    Momentum operator*(const Velocity& peer) const;
    Momentum operator/(const Velocity& peer) const;
    Momentum operator%(const Velocity& peer) const;

    // Getters
    qft::Velocity getVelocity() const { return velocity; }

    // Setters
    void setVelocity(const qft::Velocity& object) { this->velocity = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    qft::Mass getMass() const;
    void setMass(const qft::Mass& object);
    shp::Signal getCharge();
    shp::Quantity getParticles() const;
    void setParticles(const int count);
    void changeFlowSpeed(const float motion);
    void changeFlowSpeed(const float motion, const short int scale);
    void changeDirection(const float degree);
    shp::Signal getDifference() const;
    shp::Signal getPower(const Time& interval) const;
    shp::Signal getForce(const Time& interval) const;
    shp::Signal getPotential() const;
    shp::Signal getPotential(const shp::Signal& motion) const;
    shp::Signal getMatterFlow() const;
    shp::Signal getMatterFlow(const shp::Signal& motion) const;
    shp::Signal getGravitation() const;
    shp::Signal getGravitation(const shp::Signal& motion) const;
    shp::Signal getMatterPower() const;
    shp::Signal getMatterKinetic() const;
    shp::Signal getGravityPower() const;
    shp::Signal getGravityKinetic() const;
    shp::Signal getRateOfChange() const;
    std::shared_ptr<Field> getMatterField() const;
    std::shared_ptr<Field> getGravityField() const;
    bool checkNonZero() const;
    virtual shp::Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const Momentum getOrbiting(const Momentum unitary, const float multiplier);
    static const shp::Quantity getMatterParticles();
    static const shp::Quantity getMatterFlowRate();
public:
    static const std::string UNIT;
    static const std::string KILOGRAM_SECOND;
    static const std::string GRAVITY_FIELD;
    static const float ELECTRON_FLOW_RATE;
    static const short int ELECTRON_FLOW_SCALE;
};

typedef std::vector<Momentum > MomentumArray;

} // namespace qft

#endif //QFT_MOMENTUM_H