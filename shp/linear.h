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

#ifndef SHP_LINEAR_H
#define SHP_LINEAR_H

#include <string>
#include <vector>
#include "point.h"

namespace shp {

class Linear : public Point {
    PointArray points;
public:
    // Constructors
    Linear();
    Linear(const float gradient);
    Linear(std::string name);
    Linear(std::string name, const float gradient);
    Linear(std::string name, const PointArray& objects);
    Linear(std::string name, const PointArray& objects, const float gradient);

    // Destructors
    ~Linear();

    // Operator overloading
    bool operator==(const Linear& peer) const;
    Linear operator+(const Linear& peer) const;
    Linear operator-(const Linear& peer) const;

    // Access operator
    Point operator()(int x) { return points[x]; }
    const Point operator()(int x) const { return points[x]; }

    // Getters
    PointArray getPoints() const { return points; }

    // Setters
    void setPoints(const PointArray& objects) { this->points = objects; }

    // Additional methods
    int getPointCount() const;
    Point get(int index) const;
    void set(int index, const Point& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Linear > LinearArray;

} // namespace shp

#endif //SHP_LINEAR_H