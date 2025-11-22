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

namespace grt {

class Celestial {
    std::string name;
    float rotation;
    float revolution;
    double mass;
    double gravity;
public:
    // Constructors
    Celestial();
    Celestial(std::string name);
    Celestial(std::string name, float rotation, float revolution, double mass, double gravity);

    // Destructors
    ~Celestial();

    // Getters
    std::string getName() const { return name; }
    float getRotation() const { return rotation; }
    float getRevolution() const { return revolution; }
    double getMass() const { return mass; }
    double getGravity() const { return gravity; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setRotation(float value) { rotation = value; }
    void setRevolution(float value) { revolution = value; }
    void setMass(double value) { mass = value; }
    void setGravity(double value) { gravity = value; }
};

typedef std::vector<Celestial > CelestialArray;

} // namespace grt

#endif //GRT_CELESTIAL_H