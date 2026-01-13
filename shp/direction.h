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
#include <iostream>
#include <sstream>
#include <vector>

namespace shp {

class Direction {
    short int degrees;
    short int minutes;
    short int seconds;
public:
    // Constructors
    Direction();
    Direction(const float radians);
    Direction(const short int degrees);
    Direction(const short int degrees, const short int minutes);
    Direction(const short int degrees, const short int minutes, const short int seconds);

    // Destructors
    ~Direction();

    // Operator overloading
    bool operator==(const Direction& peer) const;
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
    float getCyclingRate() const;
    float getTimePerCycle() const;
    float toRadians() const;
    bool checkNonZero() const;
    Direction getInverse() const;
    Direction getNormal() const;
    Direction getRotation(const short int degree) const;
    Direction getMultiple(const float coefficient) const;
    Direction getDivision(const float coefficient) const;
    virtual Direction copy() const;
    virtual void clear();
    virtual std::string print();

private:
    short int getIndexDegrees(const short int value) const;
    short int getIndexMinutes(const short int value) const;
    short int getIndexSeconds(const short int value) const;

public:
    static const float DEFAULT_RADIANS;
    static const short int DEGREES_MIN;
    static const short int DEGREES_MAX;
    static const short int MINUTES_MIN;
    static const short int MINUTES_MAX;
    static const short int SECONDS_MIN;
    static const short int SECONDS_MAX;

    // Common high-Precision Radians
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
};

typedef std::vector<Direction > DirectionArray;

} // namespace shp

#endif //SHP_DIRECTION_H