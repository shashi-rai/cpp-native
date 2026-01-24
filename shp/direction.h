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

#ifndef SHP_DIRECTION_H
#define SHP_DIRECTION_H

#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include "unit.h"

namespace shp {

class Direction {
    short int degrees;      // ° degrees
    short int minutes;      // ' minutes
    short int seconds;      // ″ seconds
public:
    // Constructors
    Direction();
    Direction(const float radians);
    Direction(const std::complex<float> polar);
    Direction(const short int degrees);
    Direction(const short int degrees, const short int minutes);
    Direction(const short int degrees, const short int minutes, const short int seconds);

    // Destructors
    ~Direction();

    // Operator overloading
    bool operator==(const Direction& peer) const;
    bool operator<(const Direction& peer) const;
    bool operator>(const Direction& peer) const;
    bool operator<=(const Direction& peer) const;
    bool operator>=(const Direction& peer) const;
    Direction operator+(const Direction& peer) const;
    Direction operator-(const Direction& peer) const;
    Direction operator*(const Direction& peer) const;
    Direction operator/(const Direction& peer) const;
    Direction operator%(const Direction& peer) const;

    // Getters
    short int getDegrees() const { return degrees; }
    short int getMinutes() const { return minutes; }
    short int getSeconds() const { return seconds; }

    // Setters
    void setDegrees(const short int value) { this->degrees = getIndexDegrees(value); }
    void setMinutes(const short int value) { this->minutes = getIndexMinutes(value); }
    void setSeconds(const short int value) { this->seconds = getIndexSeconds(value); }

    // Additional methods
    void setAngle(const short int degrees);
    void setAngle(const short int degrees, const short int minutes);
    void setAngle(const short int degrees, const short int minutes, const short int seconds);
    float getCyclingRate() const;
    float getTimePerCycle() const;
    float toRadians() const;
    void fromRadians(const float radians);
    bool checkNonZero() const;
    float getSine() const;
    float getCosine() const;
    float getTangent() const;
    std::complex<float> getPhase() const;
    std::complex<float> getCyclic(const float coefficient) const;
    Direction getInverse() const;
    Direction getNormal() const;
    Direction getSquare() const;
    Direction getRotation(const short int degree) const;
    void setRotation(const short int degree);
    Direction getMultiple(const float coefficient) const;
    Direction getDivision(const float coefficient) const;
    virtual Direction copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printEuler() const;

private:
    short int getIndexDegrees(const short int value) const;
    short int getIndexMinutes(const short int value) const;
    short int getIndexSeconds(const short int value) const;
public:
    static const float getMagnitude(const std::complex<float> phase);
    static const float getTheta(const std::complex<float> phase);
    static const float getSine(const std::complex<float> phase);
    static const float getCosine(const std::complex<float> phase);
    static const float getTangent(const std::complex<float> phase);
    static const std::complex<float> getConstructive(
        const std::complex<float> phase_a, const std::complex<float> phase_b);
    static const std::complex<float> getDestructive(
        const std::complex<float> phase_a, const std::complex<float> phase_b);
    static const short int getQuadrant(const float radians);
    static const float getPeriodic(const float radians);
    static const float getHalfPiAngle(const float radians);
    static const float getFullPiAngle(const float radians);
    static const float getTwoPiAngle(const float radians);
    static const float getFourPiAngle(const float radians);
    static const float getEightPiAngle(const float radians);
    static const Direction getDifference(const float x, const float y);
    static const Direction getDifference(const Direction& x, const Direction& y);
    static const Direction getNormal(const Direction& x, const Direction& y);
    static const float getFraction(const float x, const float y); 
    static const float getFraction(const Direction& x, const Direction& y);
    static const bool checkTranslation(const Direction& x, const Direction& y);
    static const bool checkRotation(const Direction& x, const Direction& y);
public:
    static const float get90minus(const float radians);
    static const float get90plus(const float radians);
    static const float getHalfPiRadians();
    static const float getFullPiRadians();
    static const float getTwoPiRadians();
    static const float getFourPiRadians();
    static const float getEightPiRadians();
public:
    static const bool checkPositive(const float radians);
    static const bool checkNegative(const float radians);
    static const bool check0degree(const float radians);
    static const bool check30degree(const float radians);
    static const bool check45degree(const float radians);
    static const bool check60degree(const float radians);
    static const bool check90degree(const float radians);
    static const bool check180degree(const float radians);
    static const bool check270degree(const float radians);
    static const bool check360degree(const float radians);
    static const bool check720degree(const float radians);
    static const bool check1440degree(const float radians);
public:
    static const short int DEGREES_MIN;
    static const short int DEGREES_MAX;
    static const short int MINUTES_MIN;
    static const short int MINUTES_MAX;
    static const short int SECONDS_MIN;
    static const short int SECONDS_MAX;

    // Common high-Precision Radians
    static const float DEGREE_000;
    static const float DEGREE_001;
    static const float DEGREE_005;
    static const float DEGREE_010;
    static const float DEGREE_030;
    static const float DEGREE_045;
    static const float DEGREE_060;
    static const float DEGREE_090;
    static const float DEGREE_180;
    static const float DEGREE_270;
    static const float DEGREE_360;
    static const float DEGREE_720;
    static const float DEGREE_1440;
    static const float DEFAULT_RADIANS;
    static const int DEFAULT_PRECISION;

    // Common base
    static const float EULER_NUMBER;
};

typedef std::vector<Direction > DirectionArray;

} // namespace shp

#endif //SHP_DIRECTION_H