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

#ifndef ECN_DIODE_H
#define ECN_DIODE_H

#include <sstream>
#include <string>
#include <vector>
#include "conductor.h"

namespace ecn {

class Diode : public Element {
    Conductor positive;
    Conductor negative;
public:
    // Constructors
    Diode();
    Diode(const Conductor& positive, const Conductor& negative);
    Diode(std::string name);
    Diode(std::string name, const Conductor& positive, const Conductor& negative);

    // Destructors
    ~Diode();

    // Operator overloading
    bool operator==(const Diode& peer) const;
    Diode operator+(const Diode& peer) const;
    Diode operator-(const Diode& peer) const;
    Diode operator*(const Diode& peer) const;
    Diode operator/(const Diode& peer) const;
    Diode operator%(const Diode& peer) const;

    // Getters
    Conductor getPositive() const { return positive; }
    Conductor getNegative() const { return negative; }

    // Setters
    void setPositive(const Conductor& potential) { this->positive = potential; }
    void setNegative(const Conductor& potential) { this->negative = potential; }

    // Additional methods
    shp::Potential getPotential() const;
    virtual Diode copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Diode > DiodeArray;

} // namespace ecn

#endif //ECN_DIODE_H