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

#ifndef SHP_SHAPE_H
#define SHP_SHAPE_H

#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "angular.h"

namespace shp {

class Shape {
    std::shared_ptr<Angular> physical;
    std::string name;
public:
    // Constructors
    Shape();
    Shape(const std::string name);
    Shape(const std::shared_ptr<Angular> geometry);
    Shape(const std::string name, const std::shared_ptr<Angular> geometry);

    // Destructors
    ~Shape();

    // Operator overloading
    bool operator==(const Shape& peer) const;
    Shape operator+(const Shape& peer) const;
    Shape operator-(const Shape& peer) const;
    Shape operator*(const Shape& peer) const;
    Shape operator/(const Shape& peer) const;
    Shape operator%(const Shape& peer) const;

    // Getters
    std::shared_ptr<Angular> getPhysical() const { return physical; }
    std::string getName() const { return name; }

    // Setters
    void setPhysical(const std::shared_ptr<Angular> geometry) { this->physical = geometry; }
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    bool isStructured() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printGeometry() const;
public:
    static const std::string DEFAULT_TEXT;
};

typedef std::vector<Shape > ShapeArray;

} // namespace shp

#endif //SHP_SHAPE_H