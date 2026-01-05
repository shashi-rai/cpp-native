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

#ifndef ECN_INDUCTANCE_H
#define ECN_INDUCTANCE_H

#include <sstream>
#include <string>
#include <vector>
#include "../shp/potential.h"

namespace ecn {

class Inductance {
    shp::Potential threshold;
public:
    // Constructors
    Inductance();
    Inductance(const shp::Potential& threshold);

    // Destructors
    ~Inductance();

    // Operator overloading
    bool operator==(const Inductance& peer) const;
    Inductance operator+(const Inductance& peer) const;
    Inductance operator-(const Inductance& peer) const;
    Inductance operator*(const Inductance& peer) const;
    Inductance operator/(const Inductance& peer) const;
    Inductance operator%(const Inductance& peer) const;

    // Getters
    shp::Potential getThreshold() const { return threshold; }

    // Setters
    void setThreshold(const shp::Potential& range) { this->threshold = range; }

    // Additional methods
    Inductance copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Inductance > InductanceArray;

} // namespace ecn

#endif //ECN_INDUCTANCE_H