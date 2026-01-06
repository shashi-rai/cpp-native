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

#ifndef ECN_SERIES_H
#define ECN_SERIES_H

#include <sstream>
#include <string>
#include <vector>
#include "circuit.h"

namespace ecn {

class Series : public Circuit {
    CircuitArray elements;
public:
    // Constructors
    Series();
    Series(const CircuitArray& elements);
    Series(const Conductor& positive, const Conductor& negative);
    Series(const Conductor& positive, const Conductor& negative, const CircuitArray& elements);
    Series(std::string name);
    Series(std::string name, const CircuitArray& elements);
    Series(std::string name, const Conductor& positive, const Conductor& negative);
    Series(std::string name, const Conductor& positive, const Conductor& negative, const CircuitArray& elements);

    // Destructors
    ~Series();

    // Operator overloading
    bool operator==(const Series& peer) const;
    Series operator+(const Series& peer) const;
    Series operator-(const Series& peer) const;

    // Access operator
    Circuit operator()(const int x) { return elements[x]; }
    const Circuit operator()(const int x) const { return elements[x]; }

    // Getters
    CircuitArray getElements() const { return elements; }

    // Setters
    void setElements(const CircuitArray& components) { this->elements = components; }

    // Additional methods
    shp::Potential getPotential() const;
    int getElementCount() const;
    Circuit get(const int index) const;
    void set(const int index, const Circuit& object);
    virtual Circuit copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Series > SeriesArray;

} // namespace ecn

#endif //ECN_SERIES_H