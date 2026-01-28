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
    shp::Unit unit;
    float changeSpeed;
public:
    // Constructors
    Acceleration();
    Acceleration(const qft::Velocity& velocity);
    Acceleration(const std::shared_ptr<Time> domain);
    Acceleration(const shp::Unit& unit);
    Acceleration(const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle);
    Acceleration(const float changeAngle, const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle, const std::string unit);
    Acceleration(const float changeAngle, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle, const shp::Unit& unit);
    Acceleration(const float changeAngle, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle, const float changeSpeed);
    Acceleration(const float changeAngle, const float changeSpeed,
        const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle, const float changeSpeed, const std::string unit);
    Acceleration(const float changeAngle, const float changeSpeed, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle, const float changeSpeed, const shp::Unit& unit);
    Acceleration(const float changeAngle, const float changeSpeed, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const float changeAngle, const float changeSpeed, const qft::Velocity& velocity);
    Acceleration(const float changeAngle, const float changeSpeed, const qft::Velocity& velocity,
        const std::shared_ptr<Time> domain);
    Acceleration(const float changeSpeed, const qft::Velocity& velocity, const std::string unit);
    Acceleration(const float changeSpeed, const qft::Velocity& velocity, const shp::Unit& unit);
    Acceleration(const std::string name);
    Acceleration(const std::string name, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const std::string unit);
    Acceleration(const std::string name, const std::string unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const shp::Unit& unit);
    Acceleration(const std::string name, const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float changeAngle);
    Acceleration(const std::string name, const float changeAngle,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float changeAngle, const std::string unit);
    Acceleration(const std::string name, const float changeAngle, const std::string unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float changeAngle, const shp::Unit& unit);
    Acceleration(const std::string name, const float changeAngle, const shp::Unit& unit,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float changeAngle, const float changeSpeed);
    Acceleration(const std::string name, const float changeAngle, const float changeSpeed,
        const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float changeAngle, const float changeSpeed,
        const std::string unit);
    Acceleration(const std::string name, const float changeAngle, const float changeSpeed,
        const std::string unit, const std::shared_ptr<Time> domain);
    Acceleration(const std::string name, const float changeAngle, const float changeSpeed,
        const shp::Unit& unit);
    Acceleration(const std::string name, const float changeAngle, const float changeSpeed,
        const shp::Unit& unit, const std::shared_ptr<Time> domain);
    Acceleration(const float changeSpeed, const qft::Velocity& velocity);
    Acceleration(const std::string name, const float displacement, const short int scale, const std::string unit,
        const shp::Azimuth& orientation, const std::shared_ptr<Time> domain, const float changeSpeed);
    Acceleration(const std::string name, const float displacement, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& orientation, const std::shared_ptr<Time> domain, const float changeSpeed);
    
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
    shp::Unit getUnit() const { return unit; }

    // Setters
    void setUnit(const shp::Unit& value) { this->unit = value; }

    // Additional methods
    shp::Distance getDisplacement() const;
    void setDisplacement(const shp::Quantity& distance, const shp::Azimuth& direction);
    void setDisplacement(const shp::Quantity& distance, const shp::Polar& curvature);
    void setDisplacement(const shp::Distance& distance);
    void setDisplacement(const float distance);
    void setDisplacement(const float distance, const short int scale);
    void setDisplacement(const float distance, const short int scale, const std::string unit);
    void setDisplacement(const float distance, const short int scale, const shp::Unit& unit);
    void applyChangeTogether();
    void applyChangeDirection();
    void applyChangeMagnitude();
    float getChangeMagnitude() const;
    void setChangeMagnitude(const float speed);
    void setChangeMagnitude(const float speed, const short int scale);
    void setChangeDirection(const float degree);
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