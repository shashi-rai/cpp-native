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

#ifndef GRT_CELESTIAL_H
#define GRT_CELESTIAL_H

#include <string>
#include <vector>
#include "orbit.h"
#include "../qft/mass.h"
#include "../shp/potential.h"
#include "../shp/shape.h"

namespace grt {

class Celestial : public shp::Shape {
    std::shared_ptr<grt::Orbit> orbit;
    qft::Mass mass;
    shp::Potential gravity;
public:
    // Constructors
    Celestial();
    Celestial(std::string name);
    Celestial(std::shared_ptr<grt::Orbit> orbit);
    Celestial(std::string name, std::shared_ptr<grt::Orbit> orbit);
    Celestial(const qft::Mass& mass);
    Celestial(const qft::Mass& mass, std::shared_ptr<grt::Orbit> orbit);
    Celestial(std::string name, const qft::Mass& mass);
    Celestial(std::string name, const qft::Mass& mass, std::shared_ptr<grt::Orbit> orbit);
    Celestial(const shp::Potential& gravity);
    Celestial(const shp::Potential& gravity, std::shared_ptr<grt::Orbit> orbit);
    Celestial(std::string name, const shp::Potential& gravity);
    Celestial(std::string name, const shp::Potential& gravity, std::shared_ptr<grt::Orbit> orbit);
    Celestial(std::string name, const qft::Mass& mass, const shp::Potential& gravity);
    Celestial(std::string name, const qft::Mass& mass, const shp::Potential& gravity, std::shared_ptr<grt::Orbit> orbit);

    // Destructors
    ~Celestial();

    // Getters
    std::shared_ptr<grt::Orbit> getOrbit() const { return orbit; }
    qft::Mass getMass() const { return mass; }
    shp::Potential getGravity() const { return gravity; }

    // Setters
    void setOrbit(std::shared_ptr<grt::Orbit> value) { this->orbit = value; }
    void setMass(const qft::Mass& value) { mass = value; }
    void setGravity(const shp::Potential& value) { gravity = value; }

    // Additional methods
    shp::Distance getRadius() const;
    void setRadius(const shp::Distance& length);
    float getRotation() const;
    void setRotation(const float value);
    float getRevolution() const;
    void setRevolution(const float value);
    virtual Celestial copy();
    virtual void clear();
    virtual std::string print();
public:
    static const shp::Distance getLightYear();
public:
    static const std::string GRAVITY_UNIT;
    static const float GRAVITY_MIN;
    static const float LIGHT_YEAR;
    static const short int LIGHT_SCALE;
};

typedef std::vector<Celestial > CelestialArray;

} // namespace grt

#endif //GRT_CELESTIAL_H