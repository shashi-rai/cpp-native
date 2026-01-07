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

#ifndef ECN_ALTERNATING_H
#define ECN_ALTERNATING_H

#include <sstream>
#include <string>
#include <vector>
#include "neutral.h"

namespace ecn {

class Alternating : protected Neutral {
    Conductor line1;        // Red colour
    Conductor line2;        // Yellow colour
    Conductor line3;        // Blue colour
public:
    // Constructors
    Alternating();
    Alternating(const Conductor& line1);
    Alternating(const Conductor& line1,
        const Conductor& neutral);
    Alternating(const Conductor& line1, const Conductor& line2,
        const Conductor& neutral);
    Alternating(const Conductor& line1, const Conductor& line2, const Conductor& line3,
        const Conductor& neutral);
    Alternating(std::string name);
    Alternating(std::string name, const Conductor& line1);
    Alternating(std::string name, const Conductor& line1,
        const Conductor& neutral);
    Alternating(std::string name, const Conductor& line1, const Conductor& line2,
        const Conductor& neutral);
    Alternating(std::string name, const Conductor& line1, const Conductor& line2, const Conductor& line3,
        const Conductor& neutral);

    // Destructors
    ~Alternating();

    // Operator overloading
    bool operator==(const Alternating& peer) const;
    Alternating operator+(const Alternating& peer) const;
    Alternating operator-(const Alternating& peer) const;
    Alternating operator*(const Alternating& peer) const;
    Alternating operator/(const Alternating& peer) const;
    Alternating operator%(const Alternating& peer) const;

    // Getters
    Conductor getLine1() const { return line1; }
    Conductor getLine2() const { return line2; }
    Conductor getLine3() const { return line3; }

    // Setters
    void setLine1(const Conductor& line) { this->line1 = line; }
    void setLine2(const Conductor& line) { this->line2 = line; }
    void setLine3(const Conductor& line) { this->line3 = line; }

    // Additional methods
    Conductor getNeutral() const;
    void setNeutral(const Conductor& line);
    shp::Potential getVoltageL1() const;
    shp::Potential getVoltageL2() const;
    shp::Potential getVoltageL3() const;
    Alternating copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Alternating > AlternatingArray;

} // namespace ecn

#endif //ECN_ALTERNATING_H