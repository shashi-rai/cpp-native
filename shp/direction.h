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
    int degrees;
    int minutes;
    int seconds;
public:
    // Constructors
    Direction();
    Direction(float radians);
    Direction(int degrees);
    Direction(int degrees, int minutes);
    Direction(int degrees, int minutes, int seconds);

    // Destructors
    ~Direction();

    // Operator overloading
    bool operator==(const Direction& peer) const;
    Direction operator+(const Direction& peer) const;
    Direction operator-(const Direction& peer) const;

    // Getters
    int getDegrees() const { return degrees; }
    int getMinutes() const { return minutes; }
    int getSeconds()const { return seconds; }

    // Setters
    void setDegrees(const int value) { this->degrees = getIndexDegrees(value); }
    void setMinutes(const int value) { this->minutes = getIndexMinutes(value); }
    void setSeconds(const int value) { this->seconds = getIndexSeconds(value); }

    // Additional methods
    float toRadians() const;
    Direction copy();
    void clear();
    std::string print();
private:
    int getIndexDegrees(const int value) const;
    int getIndexMinutes(const int value) const;
    int getIndexSeconds(const int value) const;
};

typedef std::vector<Direction > DirectionArray;

} // namespace shp

#endif //SHP_DIRECTION_H