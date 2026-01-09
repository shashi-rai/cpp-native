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

#ifndef ECO_GROWTH_H
#define ECO_GROWTH_H

#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include "../shp/potential.h"

namespace eco {

class Growth : protected shp::Potential {

public:
    // Constructors
    Growth();
    Growth(const shp::Angular& closure);
    Growth(const float high);
    Growth(const float high, const shp::Angular& closure);
    Growth(const float high, const float low);
    Growth(const float high, const float low, const shp::Angular& closure);
    Growth(const std::string unit);
    Growth(const shp::Unit& unit);
    Growth(const shp::Unit& unit, const shp::Angular& closure);
    Growth(const short int scaling, const std::string unit);
    Growth(const short int scaling, const shp::Unit& unit);
    Growth(const short int scaling, const shp::Unit& unit, const shp::Angular& closure);
    Growth(const float high, const std::string unit, const shp::Angular& closure);
    Growth(const float high, const float low, const std::string unit);
    Growth(const float high, const float low, const std::string unit, const shp::Angular& closure);
    Growth(const float high, const float low, const shp::Unit& unit);
    Growth(const float high, const float low, const shp::Unit& unit, const shp::Angular& closure);
    Growth(const float high, const float low, const short int scaling);
    Growth(const float high, const float low, const short int scaling, const std::string unit);
    Growth(const float high, const float low, const short int scaling, const shp::Unit& unit);
    Growth(const float high, const float low, const short int scaling, const shp::Unit& unit, const shp::Angular& closure);

    // Destructors
    ~Growth();

    // Operator overloading
    bool operator==(const Growth& peer) const;
    Growth operator+(const Growth& peer) const;
    Growth operator-(const Growth& peer) const;
    Growth operator*(const Growth& peer) const;
    Growth operator/(const Growth& peer) const;
    Growth operator%(const Growth& peer) const;

    // Access operator
    shp::Quantity operator()(const Growth& peer,
        const shp::Distance& separation, const shp::Distance& position) const;
    shp::Quantity operator()(const Growth& peerX, const Growth& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const;

    // Getters

    // Setters

    // Additional methods
    float getHigh() const;
    void setHigh(const float value);
    float getLow() const;
    void setLow(const float value);
    shp::Angular getClosure() const;
    void setClosure(const shp::Angular& position);
    shp::Polar getPolar() const;
    void setPolar(const shp::Polar& angle);
    shp::Azimuth getAzimuth() const;
    void setAzimuth(const shp::Azimuth& angle);
    shp::Quantity getDifference() const;
    shp::Quantity getRelative(const shp::Distance& location, const float angle) const;
    shp::Quantity getPolarComponent(const shp::Distance& location) const;
    shp::Quantity getAzimuthComponent(const shp::Distance& location) const;
    shp::Potential copy() const;
    void clear();
    std::string print();
};

typedef std::vector<Growth > GrowthArray;

} // namespace eco

#endif //ECO_GROWTH_H