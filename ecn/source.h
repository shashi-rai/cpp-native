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

#ifndef ECN_SOURCE_H
#define ECN_SOURCE_H

#include <sstream>
#include <string>
#include <vector>
#include "neutral.h"
#include "../shp/potential.h"

namespace ecn {

class Source : protected Neutral {
    Conductor positive;
public:
    // Constructors
    Source();
    Source(const Conductor& positive);
    Source(const Conductor& positive, const Conductor& negative);
    Source(std::string name);
    Source(std::string name, const Conductor& positive);
    Source(std::string name, const Conductor& positive, const Conductor& negative);

    // Destructors
    ~Source();

    // Operator overloading
    bool operator==(const Source& peer) const;
    Source operator+(const Source& peer) const;
    Source operator-(const Source& peer) const;
    Source operator*(const Source& peer) const;
    Source operator/(const Source& peer) const;
    Source operator%(const Source& peer) const;

    // Getters
    Conductor getPositive() const { return positive; }

    // Setters
    void setPositive(const Conductor& potential) { this->positive = potential; }

    // Additional methods
    Conductor getNegative() const;
    void setNegative(const Conductor& line);
    shp::Potential getVoltage() const;
    Source copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Source > SourceArray;

} // namespace ecn

#endif //ECN_SOURCE_H