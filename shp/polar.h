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

#ifndef SHP_POLAR_H
#define SHP_POLAR_H

#include <cmath>
#include <sstream>
#include <vector>
#include "direction.h"

namespace shp {

class Polar : public Direction {
    Direction change;
public:
    // Constructors
    Polar();
    Polar(const float radians);
    Polar(const std::complex<float> polar);
    Polar(const short int degrees);
    Polar(const short int degrees, const short int minutes);
    Polar(const short int degrees, const short int minutes, const short int seconds);
    Polar(const Direction& change);
    Polar(const float radians, const Direction& change);
    Polar(const std::complex<float> polar, const Direction& change);
    Polar(const short int degrees, const Direction& change);
    Polar(const short int degrees, const short int minutes, const Direction& change);
    Polar(const short int degrees, const short int minutes, const short int seconds, const Direction& change);

    // Destructors
    ~Polar();

    // Operator overloading
    bool operator==(const Polar& peer) const;
    Polar operator+(const Direction& peer) const;
    Polar operator-(const Direction& peer) const;
    Polar operator*(const Direction& peer) const;
    Polar operator/(const Direction& peer) const;
    Polar operator%(const Direction& peer) const;

    // Getters
    Direction getChange() const { return change; }

    // Setters
    void setChange(const Direction& orientation) { this->change = orientation; }

    // Additional methods
    virtual Direction copy() const;
    virtual void clear();
    virtual std::string print();
    virtual std::string printEuler();
};

typedef std::vector<Polar > PolarArray;

} // namespace shp

#endif //SHP_POLAR_H