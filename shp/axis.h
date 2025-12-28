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

#ifndef SHP_AXIS_H
#define SHP_AXIS_H

#include <sstream>
#include <string>
#include <vector>
#include "quantity.h"

namespace shp {

class Axis {
    std::string name;
    float gradient;
    float scaling;
public:
    // Constructors
    Axis();
    Axis(std::string name);
    Axis(const float gradient);
    Axis(std::string name, const float gradient);
    Axis(std::string name, const float gradient, const float scaling);

    // Destructors
    ~Axis();

    // Operator overloading
    bool operator==(const Axis& peer) const;
    Axis operator+(const Axis& peer) const;
    Axis operator-(const Axis& peer) const;

    // Getters
    std::string getName() const { return name; }
    float getGradient() const { return gradient; }
    float getScaling() const { return scaling; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setGradient(const float value) { this->gradient = value; }
    void setScaling(const float value) { this->scaling = value; }

    // Additional methods
    Axis copy();
    void clear();
    std::string print();
public:
    static const float NORMAL;
    static const float DEFAULT_VALUE;
};

typedef std::vector<Axis > AxisArray;

} // namespace shp

#endif //SHP_AXIS_H