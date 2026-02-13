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

#ifndef SHP_CONSTRAINT_H
#define SHP_CONSTRAINT_H

#include "signal.h"

namespace shp {

class Constraint : private Signal {
    shp::Bound upperBound;
    shp::Bound lowerBound;
public:
    // Constructors
    Constraint();
    Constraint(const shp::Unit& unit);
    Constraint(const float magnitude);
    Constraint(const float magnitude, const std::string unit);
    Constraint(const float magnitude, const shp::Unit& unit);
    Constraint(const float magnitude, const short int scaling);
    Constraint(const float magnitude, const short int scaling,
        const std::string unit);
    Constraint(const float magnitude, const short int scaling,
        const shp::Unit& unit);
    Constraint(const Intrinsic& phase);
    Constraint(const Intrinsic& phase, const std::string unit);
    Constraint(const Intrinsic& phase, const shp::Unit& unit);
    Constraint(const Intrinsic& phase, const float magnitude);
    Constraint(const Intrinsic& phase, const float magnitude, 
        const std::string unit);
    Constraint(const Intrinsic& phase, const float magnitude,
        const Unit& unit);
    Constraint(const Intrinsic& phase, const float magnitude,
        const short int scaling);
    Constraint(const Intrinsic& phase, const float magnitude,
        const short int scaling, const std::string unit);
    Constraint(const Intrinsic& phase, const float magnitude,
        const short int scaling, const Unit& unit);

    // Destructors
    ~Constraint();

    // Operator overloading
    bool operator==(const Constraint& peer) const;
    bool operator<(const Constraint& peer) const;
    bool operator>(const Constraint& peer) const;
    bool operator<=(const Constraint& peer) const;
    bool operator>=(const Constraint& peer) const;
    Constraint operator+(const Constraint& peer) const;
    Constraint operator-(const Constraint& peer) const;
    Constraint operator*(const Constraint& peer) const;
    Constraint operator/(const Constraint& peer) const;
    Constraint operator%(const Constraint& peer) const;

    // Quantity operator
    Constraint operator+(const shp::Quantity& peer) const;
    Constraint operator-(const shp::Quantity& peer) const;
    Constraint operator*(const shp::Quantity& peer) const;
    Constraint operator/(const shp::Quantity& peer) const;
    Constraint operator%(const shp::Quantity& peer) const;

    // Getters
    shp::Bound getUpperBound() const { return upperBound; }
    shp::Bound getLowerBound() const { return lowerBound; }

    // Setters
    void setUpperBound(const shp::Bound& object) { this->upperBound = object; }
    void setLowerBound(const shp::Bound& object) { this->lowerBound = object; }

    // Additional methods
public:
    float getAmplitude() const;
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    void setMagnitude(const float value, const short int scale, const Unit& unit);
    float getIntensity() const;
    float getIntensityDrift() const;
    void setIntensityDrift(const float shift);
    void setIntensityDrift(const Intrinsic& shift);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    Signal getFrequency() const;
    Signal getTotal() const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;

protected:
    shp::Bound getIncluded(const shp::Bound& value) const;
    shp::Bound getExcluded(const shp::Bound& value) const;
};

typedef std::vector<Constraint > ConstraintArray;

} // namespace shp

#endif //SHP_CONSTRAINT_H