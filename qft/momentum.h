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

#include <vector>
#include "mass.h"
#include "acceleration.h"

namespace qft {

class Field;

class Momentum {
    std::string name;
    qft::Mass mass;
    qft::Acceleration velocity;
public:
    // Constructors
    Momentum();
    Momentum(std::string name);
    Momentum(const qft::Mass& mass);
    Momentum(std::string name, const qft::Mass& mass);
    Momentum(const float mass, const float velocity);
    Momentum(const qft::Mass& mass, const qft::Acceleration& velocity);
    Momentum(std::string name, const float mass, const float velocity);
    Momentum(std::string name, const qft::Mass& mass, const qft::Acceleration& velocity);

    // Destructors
    ~Momentum();

    // Operator overloading
    bool operator==(const Momentum& peer) const;
    Momentum operator+(const Momentum& peer) const;
    Momentum operator-(const Momentum& peer) const;
    Momentum operator*(const Momentum& peer) const;
    Momentum operator/(const Momentum& peer) const;

    // Getters
    std::string getName() const { return name; }
    qft::Mass getMass() const { return mass; }
    qft::Velocity getVelocity() const { return velocity; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setMass(const qft::Mass& object) { this->mass = object; }
    void setVelocity(const qft::Acceleration& object) { this->velocity = object; }

    // Additional methods
    qft::Acceleration getAcceleration() const;
    void applyChangeTogether();
    void changeFlowSpeed(const float motion);
    void applyChangeFlowSpeed();
    void changeDirection(const float degree);
    void applyChangeDirection();
    shp::Quantity getLinearTotal() const;
    shp::Quantity getAngularTotal() const;
    shp::Quantity getRateOfChange() const;
    std::shared_ptr<Field> getMatterField() const;
    std::shared_ptr<Field> getGravityField() const;
    virtual Momentum copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const std::string UNIT;
    static const std::string GRAVITY_FIELD;
};

typedef std::vector<Momentum > MomentumArray;

} // namespace qft

#endif //QFT_MOMENTUM_H