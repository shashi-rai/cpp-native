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

#ifndef ECN_MOTOR_H
#define ECN_MOTOR_H

#include <sstream>
#include <string>
#include <vector>
#include "coil.h"

namespace ecn {

class Motor : public Element {
    float slip;
    Coil stator;
    Coil rotor;
public:
    // Constructors
    Motor();
    Motor(const float slip);
    Motor(const Coil& stator);
    Motor(const float slip, const Coil& stator);
    Motor(const Coil& stator, const Coil& rotor);
    Motor(const float slip, const Coil& stator, const Coil& rotor);

    Motor(std::string name);
    Motor(std::string name, const float slip);
    Motor(std::string name, const Coil& stator);
    Motor(std::string name, const float slip, const Coil& stator);
    Motor(std::string name, const Coil& stator, const Coil& rotor);
    Motor(std::string name, const float slip, const Coil& stator, const Coil& rotor);

    // Destructors
    ~Motor();

    // Operator overloading
    bool operator==(const Motor& peer) const;
    Motor operator+(const Motor& peer) const;
    Motor operator-(const Motor& peer) const;
    Motor operator*(const Motor& peer) const;
    Motor operator/(const Motor& peer) const;
    Motor operator%(const Motor& peer) const;

    // Getters
    float getSlip() const { return slip; }
    Coil getStator() const { return stator; }
    Coil getRotor() const { return rotor; }

    // Setters
    void setSlip(const float value) { this->slip = value; }
    void setStator(const Coil& coil) { this->stator = coil; }
    void setRotor(const Coil& coil) { this->rotor = coil; }

    // Additional methods
    float getTurnsRatio() const;
    float getHighVoltageRatio() const;
    float getLowVoltageRatio() const;
    shp::Potential getRotorVoltage() const;
    virtual Motor copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Motor > MotorArray;

} // namespace ecn

#endif //ECN_MOTOR_H