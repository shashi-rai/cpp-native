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

#include <vector>
#include "charge.h"
#include "acceleration.h"

namespace qft {

class Field;

class Current {
    std::string name;
    qft::Charge charge;
    qft::Acceleration velocity;
public:
    // Constructors
    Current();
    Current(std::string name);
    Current(const qft::Charge& charge);
    Current(std::string name, const qft::Charge& charge);
    Current(const float charge, const float velocity);
    Current(const qft::Charge& charge, const qft::Acceleration& velocity);
    Current(std::string name, const float charge, const float velocity);
    Current(std::string name, const qft::Charge& charge, const qft::Acceleration& velocity);

    // Destructors
    ~Current();

    // Operator overloading
    bool operator==(const Current& peer) const;
    Current operator+(const Current& peer) const;
    Current operator-(const Current& peer) const;
    Current operator*(const Current& peer) const;
    Current operator/(const Current& peer) const;

    // Getters
    std::string getName() const { return name; }
    qft::Charge getCharge() const { return charge; }
    qft::Velocity getVelocity() const { return velocity; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setCharge(const qft::Charge& object) { this->charge = object; }
    void setVelocity(const qft::Acceleration& object) { this->velocity = object; }

    // Additional methods
    qft::Acceleration getAcceleration() const;
    shp::Quantity getElectrons() const;
    void setElectrons(const int count);
    void applyChangeTogether();
    void changeFlowSpeed(const float motion);
    void applyChangeFlowSpeed();
    void changeDirection(const float degree);
    void applyChangeDirection();
    shp::Quantity getLinearTotal() const;
    shp::Quantity getAngularTotal() const;
    shp::Quantity getRateOfChange() const;
    std::shared_ptr<Field> getElectricField() const;
    std::shared_ptr<Field> getMagneticField() const;
    virtual Current copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
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