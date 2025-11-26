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

#ifndef SHP_ANGULAR_H
#define SHP_ANGULAR_H

#include <string>
#include <vector>
#include "direction.h"

namespace shp {

class Angular {
    int radius;             // r - radial distance from the origin
    Direction polar;        // 𝜃 - polar zenith angle from Y axis
    Direction azimuthal;    // 𝜙 - angle within the XY plane only
public:
    // Constructors
    Angular();
    Angular(int radius);
    Angular(int radius, Direction& azimuthal);
    Angular(int radius, Direction& polar, Direction& azimuthal);

    // Destructors
    ~Angular();

    // Operator overloading
    bool operator==(const Angular& peer) const;
    Angular operator+(const Angular& peer) const;
    Angular operator-(const Angular& peer) const;

    // Getters
    int getRadius() const { return radius; }
    Direction getPolar() const { return polar; }
    Direction getAzimuthal() const { return azimuthal; }

    // Setters
    void setRadius(int value) { this->radius = value; }
    void setPolar(const Direction& angle) { this->polar = angle; }
    void setAzimuthal(const Direction& angle) { this->azimuthal = angle; }

    // Additional methods
    Angular copy();
    void clear();
    std::string print();
};

typedef std::vector<Angular > AngularArray;

} // namespace shp

#endif //SHP_ANGULAR_H