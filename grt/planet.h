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

#ifndef GRT_PLANET_H
#define GRT_PLANET_H

#include "satellite.h"

namespace grt {

class Planet : public Celestial {
    SatelliteArray satellites;
public:
    // Constructors
    Planet();
    Planet(const SatelliteArray& objects);
    Planet(const std::string name);
    Planet(const std::string name, const SatelliteArray& objects);

    // Destructors
    ~Planet();

    // Operator overloading
    bool operator==(const Planet& peer) const;
    Planet operator+(const Planet& peer) const;
    Planet operator-(const Planet& peer) const;

    // Access operator
    Satellite& operator()(const int x) { return satellites[x]; }
    const Satellite& operator()(const int x) const { return satellites[x]; }

    // Getters
    SatelliteArray getSatellites() const { return satellites; }

    // Setters
    void setSatellites(const SatelliteArray& objects) { this->satellites = objects; }

    // Additional methods
    int getSatelliteCount() const;
    Satellite get(const int index) const;
    void set(const int index, const Satellite& object);
    Planet copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printSatellites() const;
public:
    static const shp::Distance getEarthRadius();
    static const qft::Mass getEarthMass();
    static const qft::Density getEarthDensity();
    static const shp::Potential getEarthGravity();
    static const shp::Distance getEarthToSun();
public:
    static const float EARTH_RADIUS;
    static const float EARTH_MASS;
    static const float EARTH_DENSITY;
    static const float EARTH_GRAVITY;
    static const float EARTH_TO_SUN;
};

typedef std::vector<Planet > PlanetArray;

} // namespace grt

#endif //GRT_PLANET_H