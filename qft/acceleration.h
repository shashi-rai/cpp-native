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

#ifndef QFT_ACCELERATION_H
#define QFT_ACCELERATION_H

#include "velocity.h"

namespace qft {

class Acceleration : protected qft::Velocity {
    shp::Signal change;
public:
    // Constructors
    Acceleration();
    Acceleration(const qft::Velocity& velocity);
    Acceleration(const std::shared_ptr<Time> domain);
    Acceleration(const shp::Unit& unit);
    Acceleration(const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const float orientation);
    Acceleration(const shp::Azimuth& orientation);
    Acceleration(const float orientation, const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const std::shared_ptr<Time> domain);
    Acceleration(const float orientation, const std::string unit);
    Acceleration(const shp::Azimuth& orientation, const std::string unit);
    Acceleration(const float orientation, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float orientation, const shp::Unit& unit);
    Acceleration(const shp::Azimuth& orientation, const shp::Unit& unit);
    Acceleration(const float orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float orientation, const shp::Signal& change);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change);
    Acceleration(const float orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain);
    Acceleration(const float orientation, const shp::Signal& change, const std::string unit);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change, const std::string unit);
    Acceleration(const float orientation, const shp::Signal& change, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float orientation, const shp::Signal& change, const shp::Unit& unit);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change, const shp::Unit& unit);
    Acceleration(const float orientation, const shp::Signal& change, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float orientation, const shp::Signal& change, const qft::Velocity& velocity);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change, const qft::Velocity& velocity);
    Acceleration(const float orientation, const shp::Signal& change, const qft::Velocity& velocity,
        const std::shared_ptr<Time> domain);
    Acceleration(const shp::Azimuth& orientation, const shp::Signal& change, const qft::Velocity& velocity,
        const std::shared_ptr<Time> domain);
    Acceleration(const float change, const qft::Velocity& velocity, const std::string unit);
    Acceleration(const shp::Signal& change, const qft::Velocity& velocity, const std::string unit);
    Acceleration(const float change, const qft::Velocity& velocity, const shp::Unit& unit);
    Acceleration(const shp::Signal& change, const qft::Velocity& velocity, const shp::Unit& unit);
    Acceleration(const std::string name);
    Acceleration(const std::string name, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const std::string unit);
    Acceleration(const std::string name, const std::string unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Unit& unit);
    Acceleration(const std::string name, const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float orientation);
    Acceleration(const std::string name, const shp::Azimuth& orientation);
    Acceleration(const std::string name, const float orientation,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Azimuth& orientation,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float orientation, const std::string unit);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const std::string unit);
    Acceleration(const std::string name, const float orientation, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float orientation, const shp::Unit& unit);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Unit& unit);
    Acceleration(const std::string name, const float orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float orientation, const shp::Signal& change);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change);
    Acceleration(const std::string name, const float orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float orientation, const shp::Signal& change,
        const std::string unit);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change,
        const std::string unit);
    Acceleration(const std::string name, const float orientation, const shp::Signal& change,
        const std::string unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change,
        const std::string unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float orientation, const shp::Signal& change,
        const shp::Unit& unit);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change,
        const shp::Unit& unit);
    Acceleration(const std::string name, const float orientation, const shp::Signal& change,
        const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Azimuth& orientation, const shp::Signal& change,
        const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const shp::Signal& change, const qft::Velocity& velocity);
    Acceleration(const std::string name, const float displacement, const short int scale, const std::string unit,
        const shp::Azimuth& orientation, const std::shared_ptr<Time> domain, const shp::Signal& change);
    Acceleration(const std::string name, const float displacement, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& orientation, const std::shared_ptr<Time> domain, const shp::Signal& change);
    
    // Destructors
    ~Acceleration();

    // Operator overloading
    bool operator==(const Acceleration& peer) const;
    bool operator<(const Acceleration& peer) const;
    bool operator>(const Acceleration& peer) const;
    bool operator<=(const Acceleration& peer) const;
    bool operator>=(const Acceleration& peer) const;
    Acceleration operator+(const Acceleration& peer) const;
    Acceleration operator-(const Acceleration& peer) const;
    Acceleration operator*(const Acceleration& peer) const;
    Acceleration operator/(const Acceleration& peer) const;
    Acceleration operator%(const Acceleration& peer) const;

    // Distance operator
    Acceleration operator+(const float distance) const;
    Acceleration operator-(const float distance) const;
    Acceleration operator*(const float distance) const;
    Acceleration operator/(const float distance) const;
    Acceleration operator%(const float distance) const;

    // Distance operator
    Acceleration operator+(const shp::Quantity& distance) const;
    Acceleration operator-(const shp::Quantity& distance) const;
    Acceleration operator*(const shp::Quantity& distance) const;
    Acceleration operator/(const shp::Quantity& distance) const;
    Acceleration operator%(const shp::Quantity& distance) const;

    // Displacement operator
    Acceleration operator+(const shp::Distance& distance) const;
    Acceleration operator-(const shp::Distance& distance) const;
    Acceleration operator*(const shp::Distance& distance) const;
    Acceleration operator/(const shp::Distance& distance) const;
    Acceleration operator%(const shp::Distance& distance) const;

    // Velocity operator
    Acceleration operator+(const qft::Velocity& velocity) const;
    Acceleration operator-(const qft::Velocity& velocity) const;
    Acceleration operator*(const qft::Velocity& velocity) const;
    Acceleration operator/(const qft::Velocity& velocity) const;
    Acceleration operator%(const qft::Velocity& velocity) const;

    // Direction operator
    Acceleration operator+(const shp::Azimuth& orientation) const;
    Acceleration operator-(const shp::Azimuth& orientation) const;
    Acceleration operator*(const shp::Azimuth& orientation) const;
    Acceleration operator/(const shp::Azimuth& orientation) const;
    Acceleration operator%(const shp::Azimuth& orientation) const;

    // SpaceTime operator
    Acceleration operator+(const shp::Polar& curvature) const;
    Acceleration operator-(const shp::Polar& curvature) const;
    Acceleration operator*(const shp::Polar& curvature) const;
    Acceleration operator/(const shp::Polar& curvature) const;
    Acceleration operator%(const shp::Polar& curvature) const;

    // Getters
    shp::Signal getChange() const { return change; }

    // Setters
    void setChange(const shp::Signal& rate) { this->change = rate; }

    // Additional methods
    shp::Distance getDisplacement() const;
    void setDisplacement(const shp::Quantity& distance, const shp::Azimuth& direction);
    void setDisplacement(const shp::Quantity& distance, const shp::Polar& curvature);
    void setDisplacement(const shp::Distance& distance);
    void setDisplacement(const float distance);
    void setDisplacement(const float distance, const short int scale);
    void setDisplacement(const float distance, const short int scale,
        const shp::Azimuth& direction);
    void setDisplacement(const float distance, const short int scale,
        const shp::Polar& curvature);
    void setDisplacement(const float distance, const short int scale,
        const shp::Azimuth& direction, const shp::Polar& curvature);
    void setDisplacement(const float distance, const short int scale, const std::string unit);
    void setDisplacement(const float distance, const short int scale, const std::string unit,
        const shp::Azimuth& direction);
    void setDisplacement(const float distance, const short int scale, const std::string unit,
        const shp::Polar& curvature);
    void setDisplacement(const float distance, const short int scale, const std::string unit,
        const shp::Azimuth& direction, const shp::Polar& curvature);
    void setDisplacement(const float distance, const short int scale, const shp::Unit& unit);
    void setDisplacement(const float distance, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& direction);
    void setDisplacement(const float distance, const short int scale, const shp::Unit& unit,
        const shp::Polar& curvature);
    void setDisplacement(const float distance, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& direction, const shp::Polar& curvature);
    short int getScaling() const;
    void setScaling(const short int factor);
    shp::Azimuth getDirection() const;
    void setDirection(const float orientation);
    void setDirection(const shp::Azimuth& direction);
    void setChangeDirection(const float degree);
    shp::Polar getFieldCurvature() const;
    void setFieldCurvature(const float curvature);
    void setFieldCurvature(const shp::Polar& curvature);
    void setChangeFieldCurvature(const float degree);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& value);
    void applyChangeTogether();
    void applyChangeDirection();
    void applyChangeSpeed();
    float getChangeSpeed() const;
    void setChangeSpeed(const shp::Signal& modulation);
    void setChangeSpeed(const float motion);
    void setChangeSpeed(const float motion, const short int scale);
    void setChangeDivergence(const float degree);
    shp::Signal getTotal() const;
    virtual shp::Signal getLinear();
    virtual shp::Signal getLinear(const Time& slice);
    virtual shp::Signal getAngular();
    virtual shp::Signal getAngular(const shp::Direction& theta);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    shp::Signal getScalarNegative() const;
    shp::Signal getVectorNegative() const;
    shp::Signal getScalarInverse() const;
    shp::Signal getVectorInverse() const;
    shp::Signal getScalarSquare() const;
    shp::Signal getVectorSquare() const;
    shp::Signal getScalarFraction(const float length) const;
    shp::Signal getScalarFraction(const float length, const short int scale) const;
    shp::Signal getScalarSquareFraction(const float length) const;
    shp::Signal getScalarSquareFraction(const float length, const short int scale) const;
    virtual shp::Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
    shp::Direction getAngularVelocity(const Time& interval) const;
    shp::Direction getCurvedSpaceTime(const Time& interval) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Acceleration > AccelerationArray;

} // namespace qft

#endif //QFT_ACCELERATION_H