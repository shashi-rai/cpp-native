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

#ifndef QFT_HEAT_H
#define QFT_HEAT_H

#include "temperature.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Heat : protected qft::Temperature {
    qft::Velocity velocity;
public:
    // Constructors
    Heat();
    Heat(const std::string name);
    Heat(const qft::Temperature& temperature);
    Heat(const float temperature);
    Heat(const float temperature, const std::string unit);
    Heat(const float temperature, const shp::Unit& unit);
    Heat(const float temperature, const short int scaling);
    Heat(const float temperature, const short int scaling, const std::string unit);
    Heat(const float temperature, const short int scaling, const shp::Unit& unit);
    Heat(const qft::Velocity& velocity);
    Heat(const std::string name, const qft::Temperature& temperature);
    Heat(const std::string name, const float temperature);
    Heat(const std::string name, const float temperature, const std::string unit);
    Heat(const std::string name, const float temperature, const shp::Unit& unit);
    Heat(const std::string name, const float temperature, const short int scaling);
    Heat(const std::string name, const float temperature, const short int scaling, const std::string unit);
    Heat(const std::string name, const float temperature, const short int scaling, const shp::Unit& unit);
    Heat(const qft::Temperature& temperature, const qft::Velocity& velocity);
    Heat(const float temperature, const float velocity);
    Heat(const std::string name, const float temperature, const float velocity);

    // Destructors
    ~Heat();

    // Operator overloading
    bool operator==(const Heat& peer) const;
    bool operator<(const Heat& peer) const;
    bool operator>(const Heat& peer) const;
    bool operator<=(const Heat& peer) const;
    bool operator>=(const Heat& peer) const;
    Heat operator+(const Heat& peer) const;
    Heat operator-(const Heat& peer) const;
    Heat operator*(const Heat& peer) const;
    Heat operator/(const Heat& peer) const;
    Heat operator%(const Heat& peer) const;

    // Temperature operator
    Heat operator+(const Temperature& peer) const;
    Heat operator-(const Temperature& peer) const;
    Heat operator*(const Temperature& peer) const;
    Heat operator/(const Temperature& peer) const;
    Heat operator%(const Temperature& peer) const;

    // Velocity operator
    Heat operator+(const Velocity& peer) const;
    Heat operator-(const Velocity& peer) const;
    Heat operator*(const Velocity& peer) const;
    Heat operator/(const Velocity& peer) const;
    Heat operator%(const Velocity& peer) const;

    // Getters
    qft::Velocity getVelocity() const { return velocity; }

    // Setters
    void setVelocity(const qft::Velocity& object) { this->velocity = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    qft::Temperature getTemperature() const;
    void setTemperature(const qft::Temperature& object);
    shp::Quantity getMass();
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
    shp::Signal getThermalFlow() const;
    shp::Signal getThermalFlow(const shp::Signal& motion) const;
    shp::Signal getDiffusivity() const;
    shp::Signal getDiffusivity(const shp::Signal& motion) const;
    shp::Signal getThermalPower() const;
    shp::Signal getThermalKinetic() const;
    shp::Signal getDiffusionPower() const;
    shp::Signal getDiffusionKinetic() const;
    shp::Signal getRateOfChange() const;
    std::shared_ptr<Field> getThermalField() const;
    std::shared_ptr<Field> getDiffusionField() const;
    bool checkNonZero() const;
    virtual shp::Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const Heat getLooping(const Heat unitary, const float multiplier);
    static const shp::Quantity getPlasmaKelvins();
    static const shp::Quantity getPlasmaFlowRate();
public:
    static const std::string UNIT;
    static const std::string KELVIN_SECOND;
    static const std::string THERMAL_FIELD;
    static const std::string DIFFUSION_FIELD;
    static const float QGP_FLOW_RATE;
    static const short int QGP_FLOW_SCALE;
};

typedef std::vector<Heat > HeatArray;

} // namespace qft

#endif //QFT_HEAT_H