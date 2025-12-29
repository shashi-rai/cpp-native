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

#include <string>
#include <vector>
#include "velocity.h"

namespace qft {

class Acceleration : public qft::Velocity {
    shp::Unit unit;
    float changeAngle;
    float changeSpeed;
public:
    // Constructors
    Acceleration();
    Acceleration(const qft::Velocity& velocity);
    Acceleration(const shp::Unit& unit);
    Acceleration(const float changeAngle);
    Acceleration(const float changeAngle, const std::string unit);
    Acceleration(const float changeAngle, const shp::Unit& unit);
    Acceleration(const float changeAngle, const float changeSpeed);
    Acceleration(const float changeAngle, const float changeSpeed,
        const std::string unit);
    Acceleration(const float changeAngle, const float changeSpeed,
        const shp::Unit& unit);
    Acceleration(const float changeAngle, const float changeSpeed,
        const qft::Velocity& velocity);
    Acceleration(const float changeAngle, const float changeSpeed,
        const qft::Velocity& velocity, const std::string unit);
    Acceleration(const float changeAngle, const float changeSpeed,
        const qft::Velocity& velocity, const shp::Unit& unit);
    Acceleration(std::string name);
    Acceleration(std::string name, const shp::Unit& unit);
    Acceleration(std::string name, const float changeAngle);
    Acceleration(std::string name, const float changeAngle, const std::string unit);
    Acceleration(std::string name, const float changeAngle, const shp::Unit& unit);
    Acceleration(std::string name, const float changeAngle, const float changeSpeed);
    Acceleration(std::string name, const float changeAngle, const float changeSpeed,
        const std::string unit);
    Acceleration(std::string name, const float changeAngle, const float changeSpeed,
        const shp::Unit& unit);
    Acceleration(std::string name, const float changeAngle, const float changeSpeed,
        const qft::Velocity& velocity);
    Acceleration(std::string name, const float changeAngle, const float changeSpeed,
        const qft::Velocity& velocity, const std::string unit);
    Acceleration(std::string name, const float changeAngle, const float changeSpeed,
        const qft::Velocity& velocity, const shp::Unit& unit);
    
    // Destructors
    ~Acceleration();

    // Operator overloading
    bool operator==(const Acceleration& peer) const;
    Acceleration operator+(const Acceleration& peer) const;
    Acceleration operator-(const Acceleration& peer) const;
    Acceleration operator*(const Acceleration& peer) const;
    Acceleration operator/(const Acceleration& peer) const;

    // Getters
    shp::Unit getUnit() const { return unit; }
    float getChangeDirection() const { return changeAngle; }
    float getChangeMagnitude() const { return changeSpeed; }

    // Setters
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setChangeDirection(const float degree) { this->changeAngle = degree; }
    void setChangeMagnitude(const float speed) { this->changeSpeed = speed; }

    // Additional methods
    void applyChangeTogether();
    void applyChangeDirection();
    void applyChangeMagnitude();
    shp::Quantity getTotal() const;
    virtual Velocity copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Acceleration > AccelerationArray;

} // namespace qft

#endif //QFT_ACCELERATION_H