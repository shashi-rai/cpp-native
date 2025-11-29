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

#ifndef QFT_CHARGE_H
#define QFT_CHARGE_H

#include <sstream>
#include <vector>
#include "../shp/unit.h"

namespace qft {

class Charge {
    shp::Unit unit;
    float charge;
public:
    // Constructors
    Charge();
    Charge(float charge);
    Charge(const shp::Unit& unit, float charge);

    // Destructors
    ~Charge();

    // Operator overloading
    bool operator==(const Charge& peer) const;
    Charge operator+(const Charge& peer) const;
    Charge operator-(const Charge& peer) const;

    // Getters
    shp::Unit getUnit() const { return unit; }
    float getCharge() const { return charge; }

    // Setters
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setCharge(const float value) { this->charge = value; }

    // Additional methods
    virtual Charge copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Charge > ChargeArray;

} // namespace qft

#endif //QFT_CHARGE_H