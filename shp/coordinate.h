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

#ifndef SHP_COORDINATE_H
#define SHP_COORDINATE_H

#include "distance.h"

namespace shp {

class Coordinate {
    Distance x;
    Distance y;
    Distance z;
public:
    // Constructors
    Coordinate();
    Coordinate(const float x);
    Coordinate(const Distance& x);
    Coordinate(const float x, const float y);
    Coordinate(const Distance& x, const Distance& y);
    Coordinate(const float x, const float y, const float z);
    Coordinate(const Distance& x, const Distance& y, const Distance& z);

    // Destructors
    ~Coordinate();

    // Operator overloading
    bool operator==(const Coordinate& peer) const;
    bool operator<(const Coordinate& peer) const;
    bool operator>(const Coordinate& peer) const;
    bool operator<=(const Coordinate& peer) const;
    bool operator>=(const Coordinate& peer) const;
    Coordinate operator+(const Coordinate& peer) const;
    Coordinate operator-(const Coordinate& peer) const;
    Coordinate operator*(const Coordinate& peer) const;
    Coordinate operator/(const Coordinate& peer) const;
    Coordinate operator%(const Coordinate& peer) const;

    // Getters
    Distance getX() const { return x; }
    Distance getY() const { return y; }
    Distance getZ() const { return z; }

    // Setters
    void setX(const Distance& length) { this->x = length; }
    void setY(const Distance& length) { this->y = length; }
    void setZ(const Distance& length) { this->z = length; }

    // Additional methods
    void setX(const float length);
    void setX(const float length, const short int scale);
    void setX(const float length, const short int scale, const std::string unit);
    void setX(const float length, const short int scale, const Unit& unit);
    short int getScalingX() const;
    void setScalingX(const short int factor);
    Unit getUnitX() const;
    void setUnitX(const Unit& object);
    Azimuth getStressFactorX() const;
    void setStressFactorX(const float orientation);
    void setStressFactorX(const Azimuth& orientation);
    Polar getDopplerShiftX() const;
    void setDopplerShiftX(const float relativity);
    void setDopplerShiftX(const Polar& relativity);
    void setChangeXMagnitude(const float motion);
    void setChangeXDirection(const float degree);
    void setY(const float length);
    void setY(const float length, const short int scale);
    void setY(const float length, const short int scale, const std::string unit);
    void setY(const float length, const short int scale, const Unit& unit);
    short int getScalingY() const;
    void setScalingY(const short int factor);
    Unit getUnitY() const;
    void setUnitY(const Unit& object);
    Azimuth getStressFactorY() const;
    void setStressFactorY(const float orientation);
    void setStressFactorY(const Azimuth& orientation);
    Polar getDopplerShiftY() const;
    void setDopplerShiftY(const float relativity);
    void setDopplerShiftY(const Polar& relativity);
    void setChangeYMagnitude(const float motion);
    void setChangeYDirection(const float degree);
    void setZ(const float length);
    void setZ(const float length, const short int scale);
    void setZ(const float length, const short int scale, const std::string unit);
    void setZ(const float length, const short int scale, const Unit& unit);
    short int getScalingZ() const;
    void setScalingZ(const short int factor);
    Unit getUnitZ() const;
    void setUnitZ(const Unit& object);
    Azimuth getStressFactorZ() const;
    void setStressFactorZ(const float orientation);
    void setStressFactorZ(const Azimuth& orientation);
    Polar getDopplerShiftZ() const;
    void setDopplerShiftZ(const float relativity);
    void setDopplerShiftZ(const Polar& relativity);
    void setChangeZMagnitude(const float motion);
    void setChangeZDirection(const float degree);
    Signal getDiagonal() const;
    Coordinate getNormalize() const;
    Coordinate getField(const float intensity, const float conservable,
        const Coordinate& source, const Coordinate& target) const;
    Coordinate shiftX(const float step) const;
    Coordinate shiftY(const float step) const;
    Coordinate shiftZ(const float step) const;
    Coordinate copy();
    void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;

public:
    static const float ORIGIN;
    static const float UNIT_MAGNITUDE;
};

typedef std::vector<Coordinate > CoordinateArray;

} // namespace shp

#endif //SHP_COORDINATE_H