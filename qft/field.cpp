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

#include "field.h"

namespace qft {

Field::Field()
        : defaultSpin(0.0f), defaultMass(0.0), defaultCharge(0.0) {
    setPhysical(nullptr);
}

Field::Field(shp::Shape* physical)
        : defaultSpin(0.0f), defaultMass(0.0), defaultCharge(0.0) {
    setPhysical(physical);
}

Field::Field(shp::Shape* physical, float spin, double mass, double charge)
        : defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(physical);
}

Field::~Field() {
    setPhysical(nullptr);
}

bool Field::isStructured() const {
    return physical != nullptr;
}

void Field::changePoint(Action& action) {
    int x = action.getCoordinate().getX();
    int y = action.getCoordinate().getY();
    int z = action.getCoordinate().getZ();
    shp::Point received = action.getPoint();

    // simply replace the existing Point found at specific coordinates
    // with a new Point received from the Action item
    this->get(x).get(y).set(z, received);
    return;
}

Particle* Field::getDivergence(Action& action) const {
    // TODO: how is particle destroyed
    Particle* result = new Particle(defaultSpin, defaultMass, defaultCharge);
    result->setAmplitude(0);
    return result;
}

Particle* Field::getConvergence(Action& action) const {
    // TODO: how is particle generated
    Particle* result = new Particle(defaultSpin, defaultMass, defaultCharge);
    return result;
}

} // namespace qft
