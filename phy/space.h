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

#ifndef PHY_SPACE_H
#define PHY_SPACE_H

#include <vector>
#include "position.h"
#include "../qft/energy.h"

namespace phy {

class Space {
    qft::Energy energy;
    Position location;
public:
    // Constructors
    Space();
    Space(const qft::Energy& energy);
    Space(const qft::Energy& energy, const Position& location);
    Space(const Position& location);
    Space(const qft::Energy& energy, double x);
    Space(const qft::Energy& energy, double x, double y);
    Space(const qft::Energy& energy, double x, double y, double z);

    // Destructors
    ~Space();

    // Getters
    qft::Energy getEnergy() const { return energy; }
    Position getLocation() const { return location; }

    // Setters
    void setEnergy(const qft::Energy& value) { this->energy = value; }
    void setLocation(const Position& value) { this->location = value; }

    // Additional methods
    double getX() const { return location.getX(); }
    double getY() const { return location.getY(); }
    double getZ() const { return location.getZ(); }
    void setX(const double value) { this->location.setX(value); }
    void setY(const double value) { this->location.setY(value); }
    void setZ(const double value) { this->location.setZ(value); }
    virtual Space copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Space > SpaceArray;

} // namespace phy

#endif //PHY_SPACE_H