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
#include "../qft/charge.h"
#include "../qft/velocity.h"

namespace qft {

class Field;

class Current {
    std::string name;
    qft::Charge charge;
    qft::Velocity velocity;
public:
    // Constructors
    Current();
    Current(std::string name);
    Current(const qft::Charge& charge);
    Current(std::string name, const qft::Charge& charge);
    Current(const float charge, const float velocity);
    Current(const qft::Charge& charge, const qft::Velocity& velocity);
    Current(std::string name, const float charge, const float velocity);
    Current(std::string name, const qft::Charge& charge, const qft::Velocity& velocity);

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
    void setCharge(const qft::Charge& value) { this->charge = value; }
    void setVelocity(const qft::Velocity& value) { this->velocity = value; }

    // Additional methods
    shp::Quantity getTotal() const;
    std::shared_ptr<Field> getElectricField() const;
    std::shared_ptr<Field> getMagneticField() const;
    virtual Current copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const std::string UNIT;
    static const std::string ELECTRIC_FIELD;
    static const std::string MAGNETIC_FIELD;
    static const float ELECTRON_FLOW_RATE;
    static const short int ELECTRON_FLOW_SCALE;
};

typedef std::vector<Current > CurrentArray;

} // namespace qft

#endif //QFT_CURRENT_H