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

#ifndef SHP_DISTANCE_H
#define SHP_DISTANCE_H

#include "polar.h"
#include "signal.h"

namespace shp {

class Distance : private Signal {
    Polar modulation;       // relativity factor, curvature of spacetime
public:
    // Constructors
    Distance();
    Distance(const std::string unit);
    Distance(const Unit& unit);
    Distance(const float length);
    Distance(const float length, const std::string unit);
    Distance(const float length, const Unit& unit);
    Distance(const float length, const short int scaling);
    Distance(const float length, const short int scaling, const std::string unit);
    Distance(const float length, const short int scaling, const Unit& unit);
    Distance(const Azimuth& orientation);
    Distance(const Polar& modulation);
    Distance(const std::string unit, const Azimuth& orientation);
    Distance(const Unit& unit, const Azimuth& orientation);
    Distance(const Unit& unit, const Polar& modulation);
    Distance(const float length, const Azimuth& orientation);
    Distance(const float length, const Polar& modulation);
    Distance(const float length, const std::string unit, const float orientation);
    Distance(const float length, const std::string unit, const Azimuth& orientation);
    Distance(const float length, const Unit& unit, const float orientation);
    Distance(const float length, const Unit& unit, const Azimuth& orientation);
    Distance(const float length, const std::string unit, const Polar& modulation);
    Distance(const float length, const Unit& unit, const Polar& modulation);
    Distance(const float length, const short int scaling, const float orientation);
    Distance(const float length, const short int scaling, const Azimuth& orientation);
    Distance(const float length, const short int scaling, const Polar& modulation);
    Distance(const float length, const short int scaling, const std::string unit, const float orientation);
    Distance(const float length, const short int scaling, const std::string unit, const Azimuth& orientation);
    Distance(const float length, const short int scaling, const Unit& unit, const float orientation);
    Distance(const float length, const short int scaling, const Unit& unit, const Azimuth& orientation);
    Distance(const float length, const short int scaling, const Unit& unit, const Polar& modulation);
    Distance(const float length, const short int scaling, const std::string unit, const float orientation, const Polar& modulation);
    Distance(const float length, const short int scaling, const Unit& unit, const float orientation, const Polar& modulation);
    Distance(const float length, const short int scaling, const Unit& unit, const Azimuth& orientation, const Polar& modulation);

    // Destructors
    ~Distance();

    // Operator overloading
    bool operator==(const Distance& peer) const;
    bool operator<(const Distance& peer) const;
    bool operator>(const Distance& peer) const;
    bool operator<=(const Distance& peer) const;
    bool operator>=(const Distance& peer) const;
    Distance operator+(const Distance& peer) const;
    Distance operator-(const Distance& peer) const;
    Distance operator*(const Distance& peer) const;
    Distance operator/(const Distance& peer) const;
    Distance operator%(const Distance& peer) const;

    // Distance operator
    Distance operator+(const float length) const;
    Distance operator-(const float length) const;
    Distance operator+(const shp::Quantity length) const;
    Distance operator-(const shp::Quantity length) const;

    // Direction operator
    Distance operator+(const Azimuth& rotation) const;
    Distance operator-(const Azimuth& rotation) const;
    Distance operator*(const Azimuth& rotation) const;
    Distance operator/(const Azimuth& rotation) const;
    Distance operator%(const Azimuth& rotation) const;

    // Relativity operator
    Distance operator+(const Polar& rotation) const;
    Distance operator-(const Polar& rotation) const;
    Distance operator*(const Polar& rotation) const;
    Distance operator/(const Polar& rotation) const;
    Distance operator%(const Polar& rotation) const;

    // Access operator
    Signal operator()(const Distance& peer, const Direction& elevation) const;

    // Getters
    Polar getModulation() const { return modulation; }

    // Setters
    void setModulation(const Polar& relativity) { this->modulation = relativity; }

    // Additional methods
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    void setMagnitude(const float value, const short int scale, const Unit& unit);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    Azimuth getAzimuth() const;
    void setAzimuth(const float orientation);
    void setAzimuth(const Azimuth& orientation);
    void setChangeMagnitude(const float motion);
    void setChangeDirection(const float degree);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    Signal getScalarInverse() const;
    Signal getVectorInverse() const;
    Polar getRelativity(const Direction& elevation) const;
    Azimuth getDeviation(const Direction& elevation) const;
    Signal getLinear(const Distance& peer, const Direction& elevation) const;
    Signal getLinearConvergence(const Distance& peer, const Direction& elevation) const;
    Signal getLinearDivergence(const Distance& peer, const Direction& elevation) const;
    Signal getPlanar(const Distance& peer, const Direction& elevation) const;
    Signal getPlanarConvergence(const Distance& peer, const Direction& elevation) const;
    Signal getPlanarDivergence(const Distance& peer, const Direction& elevation) const;
    Signal getOrthogonal(const Distance& peer, const Direction& elevation) const;
    Signal getOrthogonalConvergence(const Distance& peer, const Direction& elevation) const;
    Signal getOrthogonalDivergence(const Distance& peer, const Direction& elevation) const;
    Signal getTotal() const;
    Signal getRadial(const Direction& elevation) const;
    Signal getRadialX(const Direction& elevation) const;
    Signal getRadialY(const Direction& elevation) const;
    Signal getRadialZ(const Direction& elevation) const;
    Signal getRadialXSquare(const Direction& elevation) const;
    Signal getRadialYSquare(const Direction& elevation) const;
    Signal getRadialZSquare(const Direction& elevation) const;
    virtual Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
private:
    static const std::complex<float> getDiffusion(const Distance& peer, const Direction& elevation);
    shp::Quantity getLinearX(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getSquareX(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getInverseX(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getInverseSquareX(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getLinearY(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getSquareY(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getInverseY(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getInverseSquareY(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getLinearZ(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getSquareZ(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getInverseZ(const Distance& peer, const Direction& elevation) const;
    shp::Quantity getInverseSquareZ(const Distance& peer, const Direction& elevation) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Distance > DistanceArray;

} // namespace shp

#endif //SHP_DISTANCE_H