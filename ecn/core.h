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

#ifndef ECN_CORE_H
#define ECN_CORE_H

#include <sstream>
#include <string>
#include <vector>
#include "element.h"
#include "reluctance.h"

namespace ecn {

class Core : public Element {
    Reluctance reluctance;
public:
    // Constructors
    Core();
    Core(const Reluctance& reluctance);
    Core(std::string name);
    Core(std::string name, const Reluctance& reluctance);

    // Destructors
    ~Core();

    // Operator overloading
    bool operator==(const Core& peer) const;
    Core operator+(const Core& peer) const;
    Core operator-(const Core& peer) const;
    Core operator*(const Core& peer) const;
    Core operator/(const Core& peer) const;
    Core operator%(const Core& peer) const;

    // Getters
    Reluctance getReluctance() const { return reluctance; }

    // Setters
    void setReluctance(const Reluctance& range) { this->reluctance = range; }

    // Additional methods
    Core copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Core > CoreArray;

} // namespace ecn

#endif //ECN_CORE_H