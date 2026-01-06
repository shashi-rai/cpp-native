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

#ifndef ECN_CONDUCTOR_H
#define ECN_CONDUCTOR_H

#include <sstream>
#include <string>
#include <vector>
#include "core.h"
#include "resistance.h"

namespace ecn {

class Conductor : public Core {
    shp::Quantity charge;
    Resistance resistance;
public:
    // Constructors
    Conductor();
    Conductor(const float charge, const short int scaling);
    Conductor(const Resistance& resistance);
    Conductor(const shp::Quantity& charge, const Resistance& resistance);
    Conductor(const Reluctance& reluctance);
    Conductor(const shp::Quantity& charge, const Reluctance& reluctance);
    Conductor(const Reluctance& reluctance, const Resistance& resistance);
    Conductor(const shp::Quantity& charge, const Reluctance& reluctance, const Resistance& resistance);
    Conductor(std::string name);
    Conductor(std::string name, const shp::Quantity& charge);
    Conductor(std::string name, const Resistance& resistance);
    Conductor(std::string name, const shp::Quantity& charge, const Resistance& resistance);
    Conductor(std::string name, const Reluctance& reluctance);
    Conductor(std::string name, const shp::Quantity& charge, const Reluctance& reluctance);
    Conductor(std::string name, const Reluctance& reluctance, const Resistance& resistance);
    Conductor(std::string name, const shp::Quantity& charge, const Reluctance& reluctance, const Resistance& resistance);

    // Destructors
    ~Conductor();

    // Operator overloading
    bool operator==(const Conductor& peer) const;
    Conductor operator+(const Conductor& peer) const;
    Conductor operator-(const Conductor& peer) const;
    Conductor operator*(const Conductor& peer) const;
    Conductor operator/(const Conductor& peer) const;
    Conductor operator%(const Conductor& peer) const;

    // Getters
    shp::Quantity getCharge() const { return charge; }
    Resistance getResistance() const { return resistance; }

    // Setters
    void setCharge(const shp::Quantity& potential) { this->charge = potential; }
    void setResistance(const Resistance& range) { this->resistance = range; }

    // Additional methods
    bool isCharged() const;
    Conductor copy();
    virtual void clear();
    virtual std::string print();
public:
    static const std::string UNIT;
};

typedef std::vector<Conductor > ConductorArray;

} // namespace ecn

#endif //ECN_CONDUCTOR_H