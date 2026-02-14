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

#include "position.h"
#include "../qft/fluid.h"

namespace phy {

class Space : public qft::Fluid {
    Position location;
public:
    // Constructors
    Space();
    Space(const qft::Energy& energy);
    Space(const qft::Energy& energy, const Position& location);
    Space(const Position& location);
    Space(const qft::Energy& energy, const double x);
    Space(const qft::Energy& energy, const double x, const double y);
    Space(const qft::Energy& energy, const double x, const double y, const double z);

    // Destructors
    ~Space();

    // Getters
    Position getLocation() const { return location; }

    // Setters
    void setLocation(const Position& coordinates) { this->location = coordinates; }

    // Additional methods
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(const double value);
    void setY(const double value);
    void setZ(const double value);
    Space copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Space > SpaceArray;

} // namespace phy

#endif //PHY_SPACE_H