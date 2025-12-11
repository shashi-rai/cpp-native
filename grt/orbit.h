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

#ifndef GRT_ORBIT_H
#define GRT_ORBIT_H

#include <string>
#include <vector>
#include "../shp/distance.h"
#include "../shp/shape.h"

namespace grt {

class Orbit : public shp::Shape {
    shp::Distance major;
    shp::Distance minor;
public:
    // Constructors
    Orbit();
    Orbit(std::string name);
    Orbit(const shp::Distance& major);
    Orbit(const shp::Distance& major, const shp::Distance& minor);
    Orbit(std::string name, const shp::Distance& major);
    Orbit(std::string name, const shp::Distance& major, const shp::Distance& minor);

    // Destructors
    ~Orbit();

    // Getters
    shp::Distance getMajor() const { return major; }
    shp::Distance getMinor() const { return minor; }

    // Setters
    void setMajor(const shp::Distance& value) { major = value; }
    void setMinor(const shp::Distance& value) { minor = value; }

    // Additional methods
    float getEccentricity() const;
    float getRotation() const;
    void setRotation(const float value);
    float getRevolution() const;
    void setRevolution(const float value);
    virtual Orbit copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Orbit > OrbitArray;

} // namespace grt

#endif //GRT_ORBIT_H