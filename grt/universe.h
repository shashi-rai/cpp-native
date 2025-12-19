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

#ifndef GRT_UNIVERSE_H
#define GRT_UNIVERSE_H

#include <string>
#include <vector>
#include "celestial.h"
#include "galaxy.h"

namespace grt {

class Universe : public Celestial {
     GalaxyArray galaxies;
public:
    // Constructors
    Universe();
    Universe(std::string name);
    Universe(std::string name, const GalaxyArray& objects);

    // Destructors
    ~Universe();

    // Operator overloading
    bool operator==(const Universe& peer) const;
    Universe operator+(const Universe& peer) const;
    Universe operator-(const Universe& peer) const;

    // Access operator
    Galaxy& operator()(int x) { return galaxies[x]; }
    const Galaxy& operator()(int x) const { return galaxies[x]; }

    // Getters
    GalaxyArray getGalaxies() const { return galaxies; }

    // Setters
    void setGalaxies(const GalaxyArray& objects) { this->galaxies = objects; }

    // Additional methods
    int getGalaxyCount() const;
    Galaxy get(int index) const;
    void set(int index, const Galaxy& object);
    virtual Celestial copy();
    virtual void clear();
    virtual std::string print();
public:
    static const shp::Distance getRadius();
    static const qft::Mass getMass();
    static const qft::Density getDensity();
    static const shp::Potential getGravity();
public:
    static const float RADIUS;
    static const float MASS;
    static const float DENSITY;
    static const float GRAVITY;
};

typedef std::vector<Universe > UniverseArray;

} // namespace grt

#endif //GRT_UNIVERSE_H