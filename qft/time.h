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

#include <chrono>
#include <string>
#include <vector>
#include "../shp/quantity.h"

namespace qft {

class Time : public shp::Quantity {
    std::string name;
public:
    // Constructors
    Time();
    Time(std::string name);
    Time(const shp::Unit& unit);
    Time(const float duration);
    Time(const float duration, const shp::Unit& unit);
    Time(const float duration, const short int scaling);
    Time(const float duration, const short int scaling, const shp::Unit& unit);
    Time(std::string duration, const shp::Unit& unit);
    Time(std::string name, const float duration);
    Time(std::string name, const float duration, const shp::Unit& unit);
    Time(std::string name, const float duration, const short int scaling);
    Time(std::string name, const float duration, const short int scaling, const shp::Unit& unit);
    Time(std::string name, const shp::Quantity& duration);

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
    std::string getName() const { return name; }

    // Setters
    void setName(const std::string& name) { this->name = name; }

    // Additional methods
    shp::Quantity getTotal() const;
    long getSeconds() const;
    long getMilliseconds() const;
    long long getNanoseconds() const;
    virtual Time copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string UNIT;
    static const short int ATOMIC_SCALE;
    static const float ATOMIC_UNIT;
    static const long RADIATION_PERIODS;
};

typedef std::vector<Time > TimeArray;

} // namespace qft

#endif //QFT_TIME_H