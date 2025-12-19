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

#ifndef GRT_SATELLITE_H
#define GRT_SATELLITE_H

#include <string>
#include <vector>
#include "celestial.h"
#include "../shp/shape.h"

namespace grt {

class Satellite : public Celestial {
    CelestialArray celestials;
public:
    // Constructors
    Satellite();
    Satellite(std::string name);
    Satellite(std::string name, const CelestialArray& objects);

    // Destructors
    ~Satellite();


    // Operator overloading
    bool operator==(const Satellite& peer) const;
    Satellite operator+(const Satellite& peer) const;
    Satellite operator-(const Satellite& peer) const;

    // Access operator
    Celestial& operator()(int x) { return celestials[x]; }
    const Celestial& operator()(int x) const { return celestials[x]; }

    // Getters
    CelestialArray getCelestials() const { return celestials; }

    // Setters
    void setCelestials(const CelestialArray& objects) { this->celestials = objects; }

    // Additional methods
    int getCelestialCount() const;
    Celestial get(int index) const;
    void set(int index, const Celestial& object);
    virtual Celestial copy();
    virtual void clear();
    virtual std::string print();
public:
    static const shp::Distance getMoonRadius();
    static const qft::Mass getMoonMass();
    static const qft::Density getMoonDensity();
    static const shp::Potential getMoonGravity();
    static const shp::Distance getMoonToEarth();
public:
public:
    static const float MOON_RADIUS;
    static const float MOON_MASS;
    static const float MOON_DENSITY;
    static const float MOON_GRAVITY;
    static const float MOON_TO_EARTH;
};

typedef std::vector<Satellite > SatelliteArray;

} // namespace grt

#endif //GRT_SATELLITE_H