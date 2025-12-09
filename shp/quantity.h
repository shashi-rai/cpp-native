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

#ifndef SHP_QUANTITY_H
#define SHP_QUANTITY_H

#include <cmath>
#include <sstream>
#include <vector>
#include "unit.h"

namespace shp {

class Quantity {
    float value;
    short int scaling;
    Unit unit;
public:
    // Constructors
    Quantity();
    Quantity(float value);
    Quantity(short int scaling);
    Quantity(const std::string unit);
    Quantity(short int scaling, const std::string unit);
    Quantity(const Unit& unit);
    Quantity(short int scaling, const Unit& unit);
    Quantity(float value, const std::string unit);
    Quantity(float value, const Unit& unit);
    Quantity(float value, short int scaling);
    Quantity(float value, short int scaling, const std::string unit);
    Quantity(float value, short int scaling, const Unit& unit);

    // Destructors
    ~Quantity();

    // Operator overloading
    bool operator==(const Quantity& peer) const;
    Quantity operator+(const Quantity& peer) const;
    Quantity operator-(const Quantity& peer) const;
    Quantity operator*(const Quantity& peer) const;
    Quantity operator/(const Quantity& peer) const;
    Quantity operator%(const Quantity& peer) const;

    // Getters
    float getValue() const { return value; }
    short int getScaling() const { return scaling; }
    Unit getUnit()const { return unit; }

    // Setters
    void setValue(const int amount) { this->value = amount; }
    void setScaling(const short int factor) { this->scaling = factor; }
    void setUnit(const Unit& object) { this->unit = object; }

    // Additional methods
    Quantity getInverse() const;
    short int checkScaling(float amount) const;
    Quantity copy();
    void clear();
    std::string print();
    float getComponent(float phase) const;
public:
    static const float DEFAULT_VALUE;
    static const short int DEFAULT_SCALE;
};

typedef std::vector<Quantity > QuantityArray;

} // namespace shp

#endif //SHP_QUANTITY_H