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
#include "switch.h"

namespace ecn {

class Diode : public Switch {
    shp::Potential threshold;
public:
    // Constructors
    Diode();
    Diode(const bool status);
    Diode(const shp::Potential& threshold);
    Diode(const Conductor& positive, const Conductor& negative);
    Diode(const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold);
    Diode(const bool status, const shp::Potential& threshold);
    Diode(const bool status, const Conductor& positive, const Conductor& negative);
    Diode(const bool status, const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold);
    Diode(std::string name);
    Diode(std::string name, const bool status);
    Diode(std::string name, const shp::Potential& threshold);
    Diode(std::string name, const Conductor& positive, const Conductor& negative);
    Diode(std::string name, const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold);
    Diode(std::string name, const bool status, const shp::Potential& threshold);
    Diode(std::string name, const bool status, const Conductor& positive, const Conductor& negative);
    Diode(std::string name, const bool status, const Conductor& positive, const Conductor& negative,
        const shp::Potential& threshold);

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
    shp::Potential getThreshold() const { return threshold; }

    // Setters
    void setThreshold(const shp::Potential& potential) { this->threshold = potential; }

    // Additional methods
    virtual Circuit copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Diode > DiodeArray;

} // namespace ecn

#endif //ECN_DIODE_H