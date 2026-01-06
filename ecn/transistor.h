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

#ifndef ECN_TRANSISTOR_H
#define ECN_TRANSISTOR_H

#include <sstream>
#include <string>
#include <vector>
#include "conductor.h"

namespace ecn {

class Transistor : public Element {
    Conductor emitter;
    Conductor base;
    Conductor collector;
public:
    // Constructors
    Transistor();
    Transistor(const Conductor& emitter, const Conductor& base, const Conductor& collector);
    Transistor(std::string name);
    Transistor(std::string name, const Conductor& emitter, const Conductor& base, const Conductor& collector);

    // Destructors
    ~Transistor();

    // Operator overloading
    bool operator==(const Transistor& peer) const;
    Transistor operator+(const Transistor& peer) const;
    Transistor operator-(const Transistor& peer) const;
    Transistor operator*(const Transistor& peer) const;
    Transistor operator/(const Transistor& peer) const;
    Transistor operator%(const Transistor& peer) const;

    // Getters
    Conductor getEmitter() const { return emitter; }
    Conductor getBase() const { return base; }
    Conductor getCollector() const { return collector; }

    // Setters
    void setEmitter(const Conductor& potential) { this->emitter = potential; }
    void setBase(const Conductor& potential) { this->base = potential; }
    void setCollector(const Conductor& potential) { this->collector = potential; }

    // Additional methods
    virtual Transistor copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Transistor > TransistorArray;

} // namespace ecn

#endif //ECN_TRANSISTOR_H