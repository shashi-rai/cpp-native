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

#include "azimuth.h"
#include "polar.h"
#include "signal.h"

namespace shp {

class Distance : private Signal {
    Azimuth horizontal;     // relativity factor, curvature of spacetime
    Polar vertical;         // relativity factor, curvature of spacetime
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
    Distance(const Intrinsic& orientation);
    Distance(const Azimuth& horizontal);
    Distance(const Polar& vertical);
    Distance(const Intrinsic& orientation, const Azimuth& horizontal);
    Distance(const Intrinsic& orientation, const Polar& vertical);
    Distance(const Intrinsic& orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const std::string unit, const Intrinsic& orientation);
    Distance(const Unit& unit, const Intrinsic& orientation);
    Distance(const std::string unit, const Azimuth& horizontal);
    Distance(const Unit& unit, const Azimuth& horizontal);
    Distance(const std::string unit, const Polar& vertical);
    Distance(const Unit& unit, const Polar& vertical);
    Distance(const Unit& unit, const Intrinsic& orientation, const Azimuth& horizontal);
    Distance(const Unit& unit, const Intrinsic& orientation, const Polar& vertical);
    Distance(const Unit& unit, const Intrinsic& orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const Intrinsic& orientation);
    Distance(const float length, const Azimuth& horizontal);
    Distance(const float length, const Polar& vertical);
    Distance(const float length,
        const Intrinsic& orientation, const Azimuth& horizontal);
    Distance(const float length,
        const Intrinsic& orientation, const Polar& vertical);
    Distance(const float length,
        const Intrinsic& orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const std::string unit, const float orientation);
    Distance(const float length, const std::string unit, const Intrinsic& orientation);
    Distance(const float length, const Unit& unit, const float orientation);
    Distance(const float length, const Unit& unit, const Intrinsic& orientation);
    Distance(const float length, const std::string unit,
        const Azimuth& horizontal);
    Distance(const float length, const std::string unit,
        const Polar& vertical);
    Distance(const float length, const Unit& unit,
        const Azimuth& horizontal);
    Distance(const float length, const Unit& unit,
        const Polar& vertical);
    Distance(const float length, const Unit& unit,
        const Intrinsic& orientation, const Azimuth& horizontal);
    Distance(const float length, const Unit& unit,
        const Intrinsic& orientation, const Polar& vertical);
    Distance(const float length, const Unit& unit,
        const Intrinsic& orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const short int scaling,
        const float orientation);
    Distance(const float length, const short int scaling,
        const Intrinsic& orientation);
    Distance(const float length, const short int scaling,
        const Azimuth& horizontal);
    Distance(const float length, const short int scaling,
        const Polar& vertical);
    Distance(const float length, const short int scaling,
        const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const short int scaling,
        const Intrinsic& orientation, const Azimuth& horizontal);
    Distance(const float length, const short int scaling,
        const Intrinsic& orientation, const Polar& vertical);
    Distance(const float length, const short int scaling,
        const Intrinsic& orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const short int scaling,
        const std::string unit, const float orientation);
    Distance(const float length, const short int scaling, const std::string unit,
        const Intrinsic& orientation);
    Distance(const float length, const short int scaling, const std::string unit,
        const Azimuth& horizontal);
    Distance(const float length, const short int scaling, const std::string unit,
        const Polar& vertical);
    Distance(const float length, const short int scaling, const Unit& unit,
        const float orientation);
    Distance(const float length, const short int scaling, const Unit& unit,
        const Intrinsic& orientation);
    Distance(const float length, const short int scaling, const Unit& unit,
        const Azimuth& horizontal);
    Distance(const float length, const short int scaling, const Unit& unit,
        const Polar& vertical);
    Distance(const float length, const short int scaling, const std::string unit,
        const float orientation, const Azimuth& horizontal);
    Distance(const float length, const short int scaling, const std::string unit,
        const float orientation, const Polar& vertical);
    Distance(const float length, const short int scaling, const std::string unit,
        const float orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const short int scaling, const Unit& unit,
        const float orientation, const Azimuth& horizontal);
    Distance(const float length, const short int scaling, const Unit& unit,
        const float orientation, const Polar& vertical);
    Distance(const float length, const short int scaling, const Unit& unit,
        const float orientation, const Azimuth& horizontal, const Polar& vertical);
    Distance(const float length, const short int scaling, const Unit& unit,
        const Intrinsic& orientation, const Azimuth& horizontal);
    Distance(const float length, const short int scaling, const Unit& unit,
        const Intrinsic& orientation, const Polar& vertical);
    Distance(const float length, const short int scaling, const Unit& unit,
        const Intrinsic& orientation, const Azimuth& horizontal, const Polar& vertical);

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

    // Length Factor operator
    Distance operator+(const float length) const;
    Distance operator-(const float length) const;
    Distance operator*(const float length) const;
    Distance operator/(const float length) const;
    Distance operator%(const float length) const;

    // Quantity Factor operator
    Distance operator+(const shp::Quantity length) const;
    Distance operator-(const shp::Quantity length) const;
    Distance operator*(const shp::Quantity length) const;
    Distance operator/(const shp::Quantity length) const;
    Distance operator%(const shp::Quantity length) const;

    // Signal Factor operator
    Distance operator+(const shp::Signal factor) const;
    Distance operator-(const shp::Signal factor) const;
    Distance operator*(const shp::Signal factor) const;
    Distance operator/(const shp::Signal factor) const;
    Distance operator%(const shp::Signal factor) const;

    // Intrinsic Amplitude operator
    Distance operator+(const Intrinsic& shifting) const;
    Distance operator-(const Intrinsic& shifting) const;
    Distance operator*(const Intrinsic& shifting) const;
    Distance operator/(const Intrinsic& shifting) const;
    Distance operator%(const Intrinsic& shifting) const;

    // Horizontal Direction - Relativity operator
    Distance operator+(const Azimuth& rotation) const;
    Distance operator-(const Azimuth& rotation) const;
    Distance operator*(const Azimuth& rotation) const;
    Distance operator/(const Azimuth& rotation) const;
    Distance operator%(const Azimuth& rotation) const;

    // Vertical Direction - Relativity operator
    Distance operator+(const Polar& rotation) const;
    Distance operator-(const Polar& rotation) const;
    Distance operator*(const Polar& rotation) const;
    Distance operator/(const Polar& rotation) const;
    Distance operator%(const Polar& rotation) const;

    // Access operator
    Signal operator()(const Distance& peer, const Azimuth& azimuth) const;
    Signal operator()(const Distance& peer, const Polar& polar) const;
    Signal operator()(const Distance& peer, const Azimuth& azimuth, const Polar& polar) const;

    // Getters
    Azimuth getHorizontal() const { return horizontal; }
    Polar getVertical() const { return vertical; }

    // Setters
    void setHorizontal(const Azimuth& modulation) { this->horizontal = modulation; }
    void setVertical(const Polar& modulation) { this->vertical = modulation; }

    // Additional methods
    float getAmplitude() const;
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    void setMagnitude(const float value, const short int scale, const Unit& unit);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    Intrinsic getIntrinsic() const;
    void setIntrinsic(const float orientation);
    void setIntrinsic(const Intrinsic& orientation);
    void setHorizontal(const float relativity);
    void setVertical(const float relativity);
    void setChangeMagnitude(const float motion);
    void setChangeMagnitude(const float motion, const short int scale);
    void setChangeIntrinsic(const float degree);
    void setChangeHorizontalCurvature(const float degree);
    void setChangeVerticalCurvature(const float degree);
    shp::Direction getHorizontalCurvatureCurrent() const;
    shp::Direction getVerticalCurvatureCurrent() const;
    shp::Direction getHorizontalCurvatureShiftRate() const;
    shp::Direction getVerticalCurvatureShiftRate() const;
    void setHorizontalCurvatureShiftRate(const float degree);
    void setVerticalCurvatureShiftRate(const float degree);
    void setHorizontalCurvatureShiftRate(const shp::Direction& angular);
    void setVerticalCurvatureShiftRate(const shp::Direction& angular);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    Signal getScalarNegative() const;
    Signal getVectorNegative() const;
    Signal getScalarInverse() const;
    Signal getVectorInverse() const;
    Signal getScalarSquare() const;
    Signal getVectorSquare() const;
    Signal getScalarFraction(const float length) const;
    Signal getScalarFraction(const float length, const short int scale) const;
    Signal getScalarSquareFraction(const float length) const;
    Signal getScalarSquareFraction(const float length, const short int scale) const;
    Intrinsic getIntrinsicDeviation(const Direction& elevation) const;
    Azimuth getHorizontalDeviation(const Direction& elevation) const;
    Polar getVerticalDeviation(const Direction& elevation) const;
    Signal getLinear(const Distance& peer, const Intrinsic& elevation) const;
    Signal getLinearConvergence(const Distance& peer, const Intrinsic& elevation) const;
    Signal getLinearDivergence(const Distance& peer, const Intrinsic& elevation) const;
    Signal getPlanar(const Distance& peer, const Azimuth& elevation) const;
    Signal getPlanarConvergence(const Distance& peer, const Azimuth& elevation) const;
    Signal getPlanarDivergence(const Distance& peer, const Azimuth& elevation) const;
    Signal getOrthogonal(const Distance& peer, const Polar& elevation) const;
    Signal getOrthogonalConvergence(const Distance& peer, const Polar& elevation) const;
    Signal getOrthogonalDivergence(const Distance& peer, const Polar& elevation) const;
    Signal getScalarTotal() const;
    Signal getVectorTotal() const;
    Signal getHorizontalDrift() const;
    Signal getHorizontalTotal() const;
    Signal getVerticalDrift() const;
    Signal getVerticalTotal() const;
    Signal getRadial(const Direction& elevation) const;
    Signal getRadial(const Azimuth& azimuth, const Polar& polar) const;
    Signal getRadialX(const Intrinsic& elevation) const;
    Signal getRadialY(const Azimuth& elevation) const;
    Signal getRadialZ(const Polar& elevation) const;
    Signal getRadialXSquare(const Intrinsic& elevation) const;
    Signal getRadialYSquare(const Azimuth& elevation) const;
    Signal getRadialZSquare(const Polar& elevation) const;
    virtual Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
private:
    static const std::complex<float> getDiffusion(const Distance& peer, const Direction& elevation);
    shp::Quantity getLinearX(const Distance& peer, const Intrinsic& elevation) const;
    shp::Quantity getSquareX(const Distance& peer, const Intrinsic& elevation) const;
    shp::Quantity getInverseX(const Distance& peer, const Intrinsic& elevation) const;
    shp::Quantity getInverseSquareX(const Distance& peer, const Intrinsic& elevation) const;
    shp::Quantity getLinearY(const Distance& peer, const Azimuth& elevation) const;
    shp::Quantity getSquareY(const Distance& peer, const Azimuth& elevation) const;
    shp::Quantity getInverseY(const Distance& peer, const Azimuth& elevation) const;
    shp::Quantity getInverseSquareY(const Distance& peer, const Azimuth& elevation) const;
    shp::Quantity getLinearZ(const Distance& peer, const Polar& elevation) const;
    shp::Quantity getSquareZ(const Distance& peer, const Polar& elevation) const;
    shp::Quantity getInverseZ(const Distance& peer, const Polar& elevation) const;
    shp::Quantity getInverseSquareZ(const Distance& peer, const Polar& elevation) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Distance > DistanceArray;

} // namespace shp

#endif //SHP_DISTANCE_H