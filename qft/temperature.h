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

#ifndef QFT_TEMPERATURE_H
#define QFT_TEMPERATURE_H

#include "density.h"
#include "force.h"
#include "velocity.h"
#include "../shp/potential.h"
#include "../shp/temporal.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Temperature : public shp::Temporal {
    std::shared_ptr<Field> field;
public:
    // Constructors
    Temperature();
    Temperature(const std::shared_ptr<Field> field);
    Temperature(const std::string unit);
    Temperature(const shp::Unit& unit);
    Temperature(const shp::Unit& unit, const std::shared_ptr<Field> field);
    Temperature(const float magnitude);
    Temperature(const float magnitude, const std::shared_ptr<Field> field);
    Temperature(const float magnitude, const std::string unit);
    Temperature(const float magnitude, const shp::Unit& unit);
    Temperature(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field);
    Temperature(const float magnitude, const short int scaling);
    Temperature(const float magnitude, const short int scaling, const std::shared_ptr<Field> field);
    Temperature(const float magnitude, const short int scaling, const std::string unit);
    Temperature(const float magnitude, const short int scaling, const shp::Unit& unit);
    Temperature(const float magnitude, const short int scaling, const shp::Unit& unit, const std::shared_ptr<Field> field);

    // Destructors
    ~Temperature();

    // Operator overloading
    bool operator==(const Temperature& peer) const;
    bool operator<(const Temperature& peer) const;
    bool operator>(const Temperature& peer) const;
    bool operator<=(const Temperature& peer) const;
    bool operator>=(const Temperature& peer) const;
    Temperature operator+(const Temperature& peer) const;
    Temperature operator-(const Temperature& peer) const;
    Temperature operator*(const Temperature& peer) const;
    Temperature operator/(const Temperature& peer) const;
    Temperature operator%(const Temperature& peer) const;

    // Quantity operator
    Temperature operator+(const shp::Quantity& peer) const;
    Temperature operator-(const shp::Quantity& peer) const;
    Temperature operator*(const shp::Quantity& peer) const;
    Temperature operator/(const shp::Quantity& peer) const;
    Temperature operator%(const shp::Quantity& peer) const;

    // Access operator
    Force operator()(const Temperature& peer, const shp::Distance separation,
        const shp::Distance position) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }

    // Setters
    void setField(std::shared_ptr<Field> address) { this->field = address; }

    // Additional methods
    bool isOwned() const;
    shp::Distance getFieldRadius() const;
    void setFieldRadius(const shp::Distance& length);
    void setFieldRadius(const float length);
    void setFieldRadius(const float length, const short int scale);
    void setFieldRadius(const float length, const short int scale, const std::string unit);
    void setFieldRadius(const float length, const short int scale, const shp::Unit& unit);
    shp::Potential getPotential() const;
    shp::Signal getVelocity() const;
    void setVelocity(const qft::Velocity& velocity);
    Density getDensity(const shp::Volume& volume) const;
    Force getForce(const shp::Angular& coordinates) const;
    std::shared_ptr<Field> getOriginField() const;
    void fromCelsius(const float value);
    float toCelsius() const;
    void fromFahrenheit(const float value);
    float toFahrenheit() const;
    float toKelvin() const;
    virtual shp::Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printKelvin() const;
    virtual std::string printCelsius() const;
    virtual std::string printFahrenheit() const;
    shp::Temporal getFluctuation(const float phase) const;
public:
    static const shp::Quantity getBoltzmannConstant();
public:
    static const std::string UNIT;
    static const std::string THERMAL_FIELD;
    static const short int THERMAL_SCALE;
    static const float QGP;
    static const short int QGP_SCALE;
    static const float BASE_VALUE;
    static const short int DEFAULT_SCALE;
    static const float DEFAULT_VALUE;
    static const float BOLTZMANN_CONSTANT;
    static const short int BOLTZMANN_SCALE;
};

typedef std::vector<Temperature > TemperatureArray;

} // namespace qft

#endif //QFT_TEMPERATURE_H