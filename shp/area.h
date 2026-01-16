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

#ifndef SHP_AREA_H
#define SHP_AREA_H

#include <cmath>
#include <complex>
#include <sstream>
#include <string>
#include <vector>
#include "signal.h"

namespace shp {

class Area {
    Signal length;
    Signal breadth;
public:
    // Constructors
    Area();
    Area(const std::string unit);
    Area(const short int scaling, const std::string unit);
    Area(const float length);
    Area(const float length, const std::string unit);
    Area(const float length, const short int scaling, const std::string unit);
    Area(const float length, const float breadth);
    Area(const float length, const float breadth, const std::string unit);
    Area(const float length, const float breadth, const short int scaling);
    Area(const float length, const float breadth, const short int scaling, const std::string unit);
    Area(const Signal& length);
    Area(const Signal& length, const Signal& breadth);

    // Destructors
    ~Area();

    // Operator overloading
    bool operator==(const Area& peer) const;
    Area operator+(const Area& peer) const;
    Area operator-(const Area& peer) const;
    Area operator*(const Area& peer) const;
    Area operator/(const Area& peer) const;
    Area operator%(const Area& peer) const;

    // Getters
    Signal getLength() const { return length; }
    Signal getBreadth() const { return breadth; }

    // Setters
    void setLength(const Signal& length) { this->length = length; }
    void setBreadth(const Signal& breadth) { this->breadth = breadth; }

    // Additional methods
    Signal getTotal() const;
    std::string getUnit() const;
    virtual Area copy();
    virtual void clear();
    virtual std::string print();
    Signal getComponent(const float phase) const;
public:
    static const std::string UNIT;
    static const short int SCALING_FACTOR;
};

typedef std::vector<Area > AreaArray;

} // namespace shp

#endif //SHP_AREA_H