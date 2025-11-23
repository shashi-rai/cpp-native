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

#ifndef PHY_FORCE_H
#define PHY_FORCE_H

#include <string>
#include <vector>
#include "direction.h"
#include "unit.h"

namespace phy {

class Force {
    std::string name;
    Unit unit;
    Direction magnitude;
    Direction direction;
public:
    // Constructors
    Force();
    Force(std::string name, const Unit& unit);
    Force(std::string name, const Unit& unit, const Direction& magnitude, const Direction& direction);

    // Destructors
    ~Force();

    // Getters
    std::string getName() const { return name; }
    Unit getUnit() const { return unit; }
    Direction getMagnitude() const { return magnitude; }
    Direction getDirection() const { return direction; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setUnit(const Unit& value) { this->unit = value; }
    void setMagnitude(const Direction& magnitude) { this->magnitude = magnitude; }
    void setDirection(const Direction& direction) { this->direction = direction; }
};

typedef std::vector<Force > ForceArray;

} // namespace phy

#endif //PHY_FORCE_H