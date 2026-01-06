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

#ifndef ECN_INDUCTOR_H
#define ECN_INDUCTOR_H

#include <sstream>
#include <string>
#include <vector>
#include "element.h"
#include "inductance.h"

namespace ecn {

class Inductor : public Element {
    Inductance inductance;
public:
    // Constructors
    Inductor();
    Inductor(const Inductance& inductance);
    Inductor(std::string name);
    Inductor(std::string name, const Inductance& inductance);

    // Destructors
    ~Inductor();

    // Operator overloading
    bool operator==(const Inductor& peer) const;
    Inductor operator+(const Inductor& peer) const;
    Inductor operator-(const Inductor& peer) const;
    Inductor operator*(const Inductor& peer) const;
    Inductor operator/(const Inductor& peer) const;
    Inductor operator%(const Inductor& peer) const;

    // Getters
    Inductance getInductance() const { return inductance; }

    // Setters
    void setInductance(const Inductance& property) { this->inductance = property; }

    // Additional methods
    virtual Inductor copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Inductor > InductorArray;

} // namespace ecn

#endif //ECN_INDUCTOR_H