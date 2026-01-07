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

#ifndef ECN_SWITCH_H
#define ECN_SWITCH_H

#include <sstream>
#include <string>
#include <vector>
#include "circuit.h"

namespace ecn {

class Switch : public Circuit {
    bool status;
public:
    // Constructors
    Switch();
    Switch(const bool status);
    Switch(const Conductor& positive, const Conductor& negative);
    Switch(const bool status, const Conductor& positive, const Conductor& negative);
    Switch(std::string name);
    Switch(std::string name, const bool status);
    Switch(std::string name, const Conductor& positive, const Conductor& negative);
    Switch(std::string name, const bool status, const Conductor& positive, const Conductor& negative);

    // Destructors
    ~Switch();

    // Operator overloading
    bool operator==(const Switch& peer) const;
    Switch operator+(const Switch& peer) const;
    Switch operator-(const Switch& peer) const;
    Switch operator*(const Switch& peer) const;
    Switch operator/(const Switch& peer) const;
    Switch operator%(const Switch& peer) const;

    // Getters
    bool getStatus() const { return status; }

    // Setters
    void setStatus(const bool flag) { this->status = flag; }

    // Additional methods
    virtual Circuit copy();
    virtual void clear();
    virtual std::string print();
public:
    static const bool DEFAULT_FLAG;
};

typedef std::vector<Switch > SwitchArray;

} // namespace ecn

#endif //ECN_SWITCH_H