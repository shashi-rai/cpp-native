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

#ifndef SHP_POINT_H
#define SHP_POINT_H

#include <complex>
#include <cmath>
#include <string>
#include <vector>
#include "angular.h"
#include "shape.h"
#include "signal.h"

namespace shp {

class Point : public Shape {
    Signal signal;
public:
    // Constructors
    Point();
    Point(const Unit& unit);
    Point(const float gradient);
    Point(const Azimuth& gradient);
    Point(const float magnitude, const float gradient);
    Point(const float magnitude, const Azimuth& gradient);
    Point(const float magnitude, const std::string unit);
    Point(const float magnitude, const std::string unit, const float gradient);
    Point(const float magnitude, const std::string unit, const Azimuth& gradient);
    Point(const float magnitude, const Unit& unit);
    Point(const float magnitude, const Unit& unit, const float gradient);
    Point(const float magnitude, const Unit& unit, const Azimuth& gradient);
    Point(const float magnitude, const short int scaling);
    Point(const float magnitude, const short int scaling, const float gradient);
    Point(const float magnitude, const short int scaling, const Azimuth& gradient);
    Point(const float magnitude, const short int scaling, const std::string unit);
    Point(const float magnitude, const short int scaling, const std::string unit, const float gradient);
    Point(const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient);
    Point(const float magnitude, const short int scaling, const Unit& unit);
    Point(const float magnitude, const short int scaling, const Unit& unit, const float gradient);
    Point(const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient);
    Point(const std::string name);
    Point(const std::string name, const float gradient);
    Point(const std::string name, const Azimuth& gradient);
    Point(const std::string name, const float magnitude, const float gradient);
    Point(const std::string name, const float magnitude, const Azimuth& gradient);
    Point(const std::string name, const float magnitude, const std::string unit);
    Point(const std::string name, const float magnitude, const std::string unit, const float gradient);
    Point(const std::string name, const float magnitude, const std::string unit, const Azimuth& gradient);
    Point(const std::string name, const float magnitude, const Unit& unit);
    Point(const std::string name, const float magnitude, const Unit& unit, const float gradient);
    Point(const std::string name, const float magnitude, const Unit& unit, const Azimuth& gradient);
    Point(const std::string name, const float magnitude, const short int scaling);
    Point(const std::string name, const float magnitude, const short int scaling, const float gradient);
    Point(const std::string name, const float magnitude, const short int scaling, const Azimuth& gradient);
    Point(const std::string name, const float magnitude, const short int scaling, const std::string unit);
    Point(const std::string name, const float magnitude, const short int scaling, const std::string unit, const float gradient);
    Point(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient);
    Point(const std::string name, const float magnitude, const short int scaling, const Unit& unit);
    Point(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const float gradient);
    Point(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient);

    // Destructors
    ~Point();

    // Operator overloading
    bool operator==(const Point& peer) const;
    Point operator+(const Point& peer) const;
    Point operator-(const Point& peer) const;
    Point operator*(const Point& peer) const;
    Point operator/(const Point& peer) const;
    Point operator%(const Point& peer) const;

    // Getters
    Signal getSignal() const { return signal; }

    // Setters
    void setSignal(const Signal& object) { this->signal = object; }

    // Additional methods
    float getAmplitude() const;
    float getMagnitude() const;
    void setMagnitude(const float magnitudet);
    void setMagnitude(const float magnitude, const short int scaling);
    void setMagnitude(const float magnitude, const short int scaling, const std::string unit);
    void setMagnitude(const float magnitude, const short int scaling, const Unit& unit);
    short int getScaling() const;
    void setScaling(const short int scaling);
    Unit getUnit() const;
    void setUnit(const Unit& unit);
    float getAzimuthal() const;
    void setAzimuthal(const float radians);
    void setAzimuthal(const Direction& orientation);
    float getGradient() const;
    void setGradient(const float radians);
    void setGradient(const Direction& orientation);
    virtual Angular getOrientation() const;
    virtual Point copy() const;
    virtual void clear();
    virtual std::string print();
    Quantity getAzimuthCosComponent(const float change) const;
    Quantity getAzimuthSinComponent(const float change) const;
protected:
    std::complex<float> toComplexAzimuth(const float change);
};

typedef std::vector<Point > PointArray;

} // namespace shp

#endif //SHP_POINT_H