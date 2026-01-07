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

#ifndef ECN_NEUTRAL_H
#define ECN_NEUTRAL_H

#include <sstream>
#include <string>
#include <vector>
#include "conductor.h"

namespace ecn {

class Neutral : public Element {
    Conductor line;       // Green or Black colour
public:
    // Constructors
    Neutral();
    Neutral(const Conductor& ground);
    Neutral(std::string name);
    Neutral(std::string name, const Conductor& ground);

    // Destructors
    ~Neutral();

    // Operator overloading
    bool operator==(const Neutral& peer) const;
    Neutral operator+(const Neutral& peer) const;
    Neutral operator-(const Neutral& peer) const;
    Neutral operator*(const Neutral& peer) const;
    Neutral operator/(const Neutral& peer) const;
    Neutral operator%(const Neutral& peer) const;

    // Getters
    Conductor getLine() const { return line; }

    // Setters
    void setLine(const Conductor& ground) { this->line = ground; }

    // Additional methods
    bool isCharged() const;
    qft::Charge getCharge() const;
    void setCharge(const qft::Charge& electric);
    shp::Quantity getVoltage() const;
    Neutral copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Neutral > NeutralArray;

} // namespace ecn

#endif //ECN_NEUTRAL_H