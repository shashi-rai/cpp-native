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

#include <complex>
#include <string>
#include <vector>
#include "azimuth.h"
#include "distance.h"
#include "polar.h"

namespace shp {

class Angular : protected Distance {    // r - radial distance from the origin
    Polar polar;                        // 𝜃 - polar zenith angle from Y axis
    Azimuth azimuth;                    // 𝜙 - angle within the XY plane only
public:
    // Constructors
    Angular();
    Angular(const float radius);
    Angular(const float radius, const short int scaling);
    Angular(const float radius, const short int scaling, std::string unit);
    Angular(const float radius, const short int scaling, const Unit& unit);
    Angular(const Distance& radius);
    Angular(const float radius, const float azimuth);
    Angular(const float radius, const short int scaling, const float azimuth);
    Angular(const float radius, const short int scaling, std::string unit, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit, const Azimuth& azimuth);
    Angular(const Distance& radius, const Azimuth& azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit, const Polar& polar);
    Angular(const Distance& radius, const Polar& polar);
    Angular(const float radius, const float polar, const float azimuth);
    Angular(const float radius, std::string unit, const float polar, const float azimuth);
    Angular(const float radius, const Unit& unit, const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, std::string unit, const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit, const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit,
        const Polar& polar, const Azimuth& azimuth);
    Angular(const Azimuth& azimuth);
    Angular(const Polar& polar);
    Angular(const Polar& polar, const Azimuth& azimuth);
    Angular(const Distance& radius, const Polar& polar, const Azimuth& azimuth);

    // Destructors
    ~Angular();

    // Operator overloading
    bool operator==(const Angular& peer) const;
    Angular operator+(const Angular& peer) const;
    Angular operator-(const Angular& peer) const;
    Angular operator*(const Angular& peer) const;
    Angular operator/(const Angular& peer) const;
    Angular operator%(const Angular& peer) const;

    // Distance operator
    Distance operator+(const Distance& separation) const;
    Distance operator-(const Distance& separation) const;
    Distance operator*(const Distance& separation) const;
    Distance operator/(const Distance& separation) const;
    Distance operator%(const Distance& separation) const;

    // Azimuth operator
    Angular operator+(const Azimuth& rotation) const;
    Angular operator-(const Azimuth& rotation) const;
    Angular operator*(const Azimuth& rotation) const;
    Angular operator/(const Azimuth& rotation) const;
    Angular operator%(const Azimuth& rotation) const;

    // Polar operator
    Angular operator+(const Polar& rotation) const;
    Angular operator-(const Polar& rotation) const;
    Angular operator*(const Polar& rotation) const;
    Angular operator/(const Polar& rotation) const;
    Angular operator%(const Polar& rotation) const;

    // Access operator
    Quantity operator()(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    Quantity operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    Direction getPolar() const { return polar; }
    Direction getAzimuth() const { return azimuth; }

    // Setters
    void setPolar(const Polar& angle) { this->polar = angle; }
    void setAzimuth(const Azimuth& angle) { this->azimuth = angle; }

    // Additional methods
    Distance getRadius() const;
    void setRadius(const Distance& length);
    Quantity getRelative(const Distance& position, const float angle) const;
    Quantity getRelativeX(const Distance& position, const float angle) const;
    Quantity getRelativeY(const Distance& position, const float angle) const;
    Quantity getPolarComponent(const Distance& position) const;
    Quantity getAzimuthComponent(const Distance& position) const;
    virtual Distance copy() const;
    virtual void clear();
    virtual std::string print();

public:
    static const float DEFAULT_RADIUS;
    static const float DEFAULT_POLARITY;
    static const float DEFAULT_AZIMUTHAL;
};

typedef std::vector<Angular > AngularArray;

} // namespace shp

#endif //SHP_ANGULAR_H