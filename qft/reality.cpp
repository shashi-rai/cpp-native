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

#include "reality.h"

namespace qft {

const float Reality::DEFAULT_VALUE = 0.0f;
const float Reality::DEFAULT_FIELD = 1.0f;

Reality::Reality()
        : gravity(), gluonic(), electric(), magnetic() {
    initialize(DEFAULT_FIELD, DEFAULT_VALUE, DEFAULT_FIELD);
}

Reality::Reality(const float mass, const float colour, const float charge)
        : gravity(), gluonic(), electric(), magnetic() {
    initialize(mass, colour, charge);
}

Reality::~Reality() {

}

bool Reality::operator==(const Reality& peer) const {
    return (gravity == peer.gravity)
            && (gluonic == peer.gluonic)
            && (electric == peer.electric)
            && (magnetic == peer.magnetic);
}

Reality Reality::copy() {
    Reality fresh;
    return fresh;
}

void Reality::clear() {
    gravity->clear();
    gluonic->clear();
    electric->clear();
    magnetic->clear();
    return;
}

std::string Reality::print() {
    std::stringstream result;
    result << "[";
	result << gravity << ",";
    result << gluonic << ",";
    result << electric << ",";
	result << magnetic;
    result << "]";
	return result.str();
}

void Reality::initialize(const float mass, const float colour, const float charge) {
    gravity = qft::Field::shareable("Gravity"); gravity->setAmplitude(mass);
    gluonic = qft::Field::shareable("Gluonic"); gluonic->setAmplitude(colour);
    electric = qft::Field::shareable("Electric"); electric->setAmplitude(charge);
    magnetic = qft::Field::shareable("Magnetic"); magnetic->setAmplitude(charge);
}

} // namespace qft