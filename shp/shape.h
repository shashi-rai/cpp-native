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

#include <sstream>
#include <string>
#include <vector>

namespace shp {

class Shape {
    std::shared_ptr<Shape> owner;
    std::string name;
public:
    // Constructors
    Shape();
    Shape(const std::string name);
    Shape(const std::shared_ptr<Shape> parent);
    Shape(const std::string name, const std::shared_ptr<Shape> parent);

    // Destructors
    ~Shape();

    // Operator overloading
    bool operator==(const Shape& peer) const;

    // Getters
    std::shared_ptr<Shape> getOwner() const { return owner; }
    std::string getName() const { return name; }

    // Setters
    void setOwner(const std::shared_ptr<Shape> parent) { this->owner = parent; }
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    bool isOwned() const;
    virtual void clear();
    virtual std::string print() const;
};

typedef std::vector<Shape > ShapeArray;

} // namespace shp

#endif //SHP_SHAPE_H