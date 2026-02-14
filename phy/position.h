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

#ifndef PHY_POSITION_H
#define PHY_POSITION_H

#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>

namespace phy {

class Position {
    double x;       // Azimuthal Plane
    double y;       // Azimuthal Plane
    double z;       // Polar / Elevation
public:
    // Constructors
    Position();
    Position(const double x);
    Position(const double x, const double y);
    Position(const double x, const double y, const double z);

    // Destructors
    ~Position();

    // Operator overloading
    bool operator==(const Position& peer) const;
    bool operator<(const Position& peer) const;
    bool operator>(const Position& peer) const;
    bool operator<=(const Position& peer) const;
    bool operator>=(const Position& peer) const;
    Position operator+(const Position& peer) const;
    Position operator-(const Position& peer) const;
    Position operator*(const Position& peer) const;
    Position operator/(const Position& peer) const;
    Position operator%(const Position& peer) const;

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Setters
    void setX(const double value) { this->x = value; }
    void setY(const double value) { this->y = value; }
    void setZ(const double value) { this->z = value; }

    // Additional methods
    double getDiagonal() const;
    Position copy();
    virtual void clear();
    virtual std::string print() const;

public:
    static const long double getPiValue();
    static const long double toRadians(long double degree);
    static const double getAzimuthAngle(const Position& a, const Position& b);
    static const double getPolarAngle(const Position& a, const Position& b);
    static const double getAzimuthRadians(const Position& a, const Position& b);
    static const double getPolarRadians(const Position& a, const Position& b);
    static const double getAzimuthDegrees(const Position& a, const Position& b);
    static const double getPolarDegrees(const Position& a, const Position& b);
public:
    static const double ORIGIN;
    static const double DEGREE_QUADRANT_1;
    static const double DEGREE_QUADRANT_2;
    static const double DEGREE_QUADRANT_3;
    static const double DEGREE_QUADRANT_4;
};

typedef std::vector<Position > PositionArray;

} // namespace phy

#endif //PHY_POSITION_H