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

#ifndef ECN_CIRCUIT_H
#define ECN_CIRCUIT_H

#include <sstream>
#include <string>
#include <vector>
#include "element.h"

namespace ecn {

class Circuit : public Element {
    ElementArray elements;
public:
    // Constructors
    Circuit();
    Circuit(const ElementArray& elements);
    Circuit(const Resistance& resistance, const ElementArray& elements);
    Circuit(const Resistance& resistance, const Capacitance& capacitance,
        const ElementArray& elements);
    Circuit(const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance, const ElementArray& elements);
    Circuit(std::string name);
    Circuit(std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance);
    Circuit(std::string name, const ElementArray& elements);
    Circuit(std::string name, const Resistance& resistance, const ElementArray& elements);
    Circuit(std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const ElementArray& elements);
    Circuit(std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance, const ElementArray& elements);

    // Destructors
    ~Circuit();

    // Operator overloading
    bool operator==(const Circuit& peer) const;
    Circuit operator+(const Circuit& peer) const;
    Circuit operator-(const Circuit& peer) const;

    // Access operator
    Element operator()(const int x) { return elements[x]; }
    const Element operator()(const int x) const { return elements[x]; }

    // Getters
    ElementArray getElements() const { return elements; }

    // Setters
    void setElements(const ElementArray& components) { this->elements = components; }

    // Additional methods
    int getElementCount() const;
    Element get(const int index) const;
    void set(const int index, const Element& object);
    virtual Circuit copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Circuit > CircuitArray;

} // namespace ecn

#endif //ECN_CIRCUIT_H