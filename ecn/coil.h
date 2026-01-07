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

#ifndef ECN_COIL_H
#define ECN_COIL_H

#include <sstream>
#include <string>
#include <vector>
#include "conductor.h"
#include "inductance.h"
#include "../qft/magnetic.h"

namespace ecn {

class Coil : public Conductor {
    float loopcount;
    Inductance inductance;
public:
    // Constructors
    Coil();
    Coil(const float turns);
    Coil(const Inductance& inductance);
    Coil(const float turns, const Inductance& inductance);
    Coil(const Resistance& resistance);
    Coil(const float turns, const Resistance& resistance);
    Coil(const Reluctance& reluctance);
    Coil(const float turns, const Reluctance& reluctance);
    Coil(const Inductance& inductance, const Resistance& resistance);
    Coil(const float turns, const Inductance& inductance, const Resistance& resistance);
    Coil(const Inductance& inductance, const Reluctance& reluctance);
    Coil(const float turns, const Inductance& inductance, const Reluctance& reluctance);
    Coil(const Inductance& inductance, const Reluctance& reluctance, const Resistance& resistance);
    Coil(const float turns, const Inductance& inductance, const Reluctance& reluctance, const Resistance& resistance);
    Coil(std::string name);
    Coil(std::string name, const float turns);
    Coil(std::string name, const Inductance& inductance);
    Coil(std::string name, const float turns, const Inductance& inductance);
    Coil(std::string name, const Resistance& resistance);
    Coil(std::string name, const float turns, const Resistance& resistance);
    Coil(std::string name, const Reluctance& reluctance);
    Coil(std::string name, const float turns, const Reluctance& reluctance);
    Coil(std::string name, const Inductance& inductance, const Resistance& resistance);
    Coil(std::string name, const float turns, const Inductance& inductance, const Resistance& resistance);
    Coil(std::string name, const Inductance& inductance, const Reluctance& reluctance);
    Coil(std::string name, const float turns, const Inductance& inductance, const Reluctance& reluctance);
    Coil(std::string name, const Inductance& inductance, const Reluctance& reluctance, const Resistance& resistance);
    Coil(std::string name, const float turns, const Inductance& inductance, const Reluctance& reluctance, const Resistance& resistance);

    // Destructors
    ~Coil();

    // Operator overloading
    bool operator==(const Coil& peer) const;
    Coil operator+(const Coil& peer) const;
    Coil operator-(const Coil& peer) const;
    Coil operator*(const Coil& peer) const;
    Coil operator/(const Coil& peer) const;
    Coil operator%(const Coil& peer) const;

    // Getters
    float getLoopCount() const { return loopcount; }
    Inductance getInductance() const { return inductance; }

    // Setters
    void setLoopCount(const float turns) { this->loopcount = turns; }
    void setInductance(const Inductance& range) { this->inductance = range; }

    // Additional methods
    shp::Potential getVoltage() const;
    qft::Magnetic getForce() const;
    Coil copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Coil > CoilArray;

} // namespace ecn

#endif //ECN_COIL_H