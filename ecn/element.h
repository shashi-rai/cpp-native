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

#ifndef ECN_ELEMENT_H
#define ECN_ELEMENT_H

#include <sstream>
#include <string>
#include <vector>
#include "capacitance.h"
#include "inductance.h"
#include "resistance.h"

namespace ecn {

class Element {
    std::string name;
    Resistance resistance;
    Capacitance capacitance;
    Inductance inductance;
public:
    // Constructors
    Element();
    Element(const Resistance& resistance);
    Element(const Resistance& resistance, const Capacitance& capacitance);
    Element(const Resistance& resistance, const Capacitance& capacitance, const Inductance& inductance);
    Element(std::string name);
    Element(std::string name, const Resistance& resistance);
    Element(std::string name, const Resistance& resistance, const Capacitance& capacitance);
    Element(std::string name, const Resistance& resistance, const Capacitance& capacitance, const Inductance& inductance);

    // Destructors
    ~Element();

    // Operator overloading
    bool operator==(const Element& peer) const;
    Element operator+(const Element& peer) const;
    Element operator-(const Element& peer) const;
    Element operator*(const Element& peer) const;
    Element operator/(const Element& peer) const;
    Element operator%(const Element& peer) const;

    // Getters
    std::string getName() const { return name; }
    Resistance getResistance() const { return resistance; }
    Capacitance getCapacitance() const { return capacitance; }
    Inductance getInductance() const { return inductance; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setResistance(const Resistance& range) { this->resistance = range; }
    void setCapacitance(const Capacitance& range) { this->capacitance = range; }
    void setInductance(const Inductance& range) { this->inductance = range; }

    // Additional methods
    Element copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Element > ElementArray;

} // namespace ecn

#endif //ECN_ELEMENT_H