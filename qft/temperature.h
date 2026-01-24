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

#include "../shp/direction.h"
#include "../shp/quantity.h"

namespace qft {

class Temperature : public shp::Quantity {
    shp::Direction change;
public:
    // Constructors
    Temperature();
    Temperature(const std::string unit);
    Temperature(const shp::Unit& unit);
    Temperature(const float quantity);
    Temperature(const float quantity, const std::string unit);
    Temperature(const float quantity, const shp::Unit& unit);
    Temperature(const float quantity, const short int scaling);
    Temperature(const float quantity, const short int scaling, const std::string unit);
    Temperature(const float quantity, const short int scaling, const shp::Unit& unit);
    Temperature(const shp::Direction& change);
    Temperature(const std::string unit, const shp::Direction& change);
    Temperature(const shp::Unit& unit, const shp::Direction& change);
    Temperature(const float quantity, const shp::Direction& change);
    Temperature(const float quantity, const std::string unit, const shp::Direction& change);
    Temperature(const float quantity, const shp::Unit& unit, const shp::Direction& change);
    Temperature(const float quantity, const short int scaling, const shp::Direction& change);
    Temperature(const float quantity, const short int scaling, const std::string unit, const shp::Direction& change);
    Temperature(const float quantity, const short int scaling, const shp::Unit& unit, const shp::Direction& change);

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

    // Getters
    shp::Direction getChange() const { return change; }

    // Setters
    void setChange(const shp::Direction& orientation) { this->change = orientation; }

    // Additional methods
    shp::Quantity getTotal() const;
    void fromCelsius(const float value);
    float toCelsius() const;
    void fromFahrenheit(const float value);
    float toFahrenheit() const;
    float toKelvin() const;
    virtual Temperature copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printKelvin() const;
    virtual std::string printCelsius() const;
    virtual std::string printFahrenheit() const;
    float getCosComponent(const float phase) const;
    float getSinComponent(const float phase) const;
protected:
    static const std::complex<float> getComplex(const float value, const float direction);
public:
    static const shp::Quantity getBoltzmannConstant();
public:
    static const std::string UNIT;
    static const float BASE_VALUE;
    static const short int DEFAULT_SCALE;
    static const float DEFAULT_VALUE;
    static const float BOLTZMANN_CONSTANT;
    static const short int BOLTZMANN_SCALE;
};

typedef std::vector<Temperature > TemperatureArray;

} // namespace qft

#endif //QFT_TEMPERATURE_H