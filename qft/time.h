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

#ifndef QFT_TIME_H
#define QFT_TIME_H

#include <vector>
#include "../shp/unit.h"

namespace qft {

class Time {
    shp::Unit unit;
    long quantity;
    short int scaling;
public:
    // Constructors
    Time();
    Time(long time);
    Time(long time, short int scaling);
    Time(long time, const shp::Unit& unit);
    Time(long time, short int scaling, const shp::Unit& unit);

    // Destructors
    ~Time();

    // Operator overloading
    bool operator==(const Time& peer) const;
    Time operator+(const Time& peer) const;
    Time operator-(const Time& peer) const;
    Time operator*(const Time& peer) const;
    Time operator/(const Time& peer) const;
    Time operator%(const Time& peer) const;

    // Getters
    shp::Unit getUnit() const { return unit; }
    long getQuantity() const { return quantity; }
    short int getScaling() const { return scaling; }

    // Setters
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setQuantity(const long value) { this->quantity = value; }
    void setScaling(const short int value) { this->scaling = value; }

    // Additional methods
    virtual Time copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string UNIT;
    static const short int ATOMIC_SCALE;
    static const float ATOMIC_UNIT;
};

typedef std::vector<Time > TimeArray;

} // namespace qft

#endif //QFT_TIME_H