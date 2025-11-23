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

#ifndef PHY_MOMENTUM_H
#define PHY_MOMENTUM_H

#include <vector>
#include "direction.h"
#include "mass.h"

namespace phy {

class Momentum {
    Mass mass;
    Direction velocity;
public:
    // Constructors
    Momentum();
    Momentum(const Mass& mass, const Direction& velocity);

    // Destructors
    ~Momentum();

    // Getters
    Mass getMass() const { return mass; }
    Direction getVelocity() const { return velocity; }

    // Setters
    void setMass(const Mass& value) { this->mass = value; }
    void setVelocity(const Direction& value) { this->velocity = value; }
};

typedef std::vector<Momentum > MomentumArray;

} // namespace phy

#endif //PHY_MOMENTUM_H