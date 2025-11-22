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

namespace grt {

class Universe {
    std::string name;
    double mass;
    double gravity;
public:
    // Constructors
    Universe();
    Universe(std::string name);
    Universe(std::string name, double mass, double gravity);

    // Destructors
    ~Universe();

    // Getters
    std::string getName() const { return name; }
    double getMass() const { return mass; }
    double getGravity() const { return gravity; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setMass(double value) { mass = value; }
    void setGravity(double value) { gravity = value; }
};

typedef std::vector<Universe > UniverseArray;

} // namespace grt

#endif //GRT_UNIVERSE_H