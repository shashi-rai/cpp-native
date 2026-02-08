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

#ifndef SHP_INTRINSIC_H
#define SHP_INTRINSIC_H

#include "direction.h"

namespace shp {

class Intrinsic : public Direction {
    Direction shifting;
public:
    // Constructors
    Intrinsic();
    Intrinsic(const float radians);
    Intrinsic(const std::complex<float> polar);
    Intrinsic(const short int degrees);
    Intrinsic(const short int degrees, const short int minutes);
    Intrinsic(const short int degrees, const short int minutes, const short int seconds);
    Intrinsic(const Direction& change);
    Intrinsic(const float radians, const Direction& change);
    Intrinsic(const std::complex<float> polar, const Direction& change);
    Intrinsic(const short int degrees, const Direction& change);
    Intrinsic(const short int degrees, const short int minutes, const Direction& change);
    Intrinsic(const short int degrees, const short int minutes, const short int seconds, const Direction& change);

    // Destructors
    ~Intrinsic();

    // Operator overloading
    bool operator==(const Intrinsic& peer) const;
    bool operator<(const Intrinsic& peer) const;
    bool operator>(const Intrinsic& peer) const;
    bool operator<=(const Intrinsic& peer) const;
    bool operator>=(const Intrinsic& peer) const;
    Intrinsic operator+(const Direction& peer) const;
    Intrinsic operator-(const Direction& peer) const;
    Intrinsic operator*(const Direction& peer) const;
    Intrinsic operator/(const Direction& peer) const;
    Intrinsic operator%(const Direction& peer) const;

    // Getters
    Direction getShifting() const { return shifting; }

    // Setters
    void setShifting(const Direction& angular) { this->shifting = angular; }

    // Additional methods
    void setAngleShiftRate(const float degree);
    Direction getCurrent() const;
    virtual Direction copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printEuler() const;
};

typedef std::vector<Intrinsic > IntrinsicArray;

} // namespace shp

#endif //SHP_INTRINSIC_H