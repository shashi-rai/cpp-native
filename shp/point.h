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

#include <cmath>
#include <string>
#include <vector>
#include "angular.h"
#include "shape.h"

namespace shp {

class Point : public Shape {
    float amplitude;
    float gradient;
public:
    // Constructors
    Point();
    Point(float gradient);
    Point(float amplitude, float gradient);
    Point(std::string name);
    Point(std::string name, float gradient);
    Point(std::string name, float amplitude, float gradient);

    // Destructors
    ~Point();

    // Operator overloading
    bool operator==(const Point& peer) const;
    Point operator+(const Point& peer) const;
    Point operator-(const Point& peer) const;

    // Getters
    float getAmplitude() const { return amplitude; }
    float getGradient() const { return gradient; }

    // Setters
    void setAmplitude(float value) { this->amplitude = value; }
    void setGradient(float value) { this->gradient = value; }

    // Additional methods
    virtual Angular getOrientation() const;
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
protected:
    float getAzimuthalAmplitudeAscent(const Point& peer) const;
    float getAzimuthalAmplitudeDescent(const Point& peer) const;
private:
    float getGradientAmplitude(const Point& peer, float phase) const;
};

typedef std::vector<Point > PointArray;

} // namespace shp

#endif //SHP_POINT_H