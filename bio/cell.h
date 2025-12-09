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

#ifndef BIO_CELL_H
#define BIO_CELL_H

#include <string>
#include <vector>
#include "membrane.h"

namespace bio {

class Cell {
    std::string name;
    MembraneArray membranes;
public:
    // Constructors
    Cell();
    Cell(std::string name);
    Cell(std::string name, MembraneArray& objects);

    // Destructors
    ~Cell();
    
    // Operator overloading
    bool operator==(const Cell& peer) const;
    Cell operator+(const Cell& peer) const;
    Cell operator-(const Cell& peer) const;

    // Access operator
    Membrane& operator()(int x) { return membranes[x]; }
    const Membrane& operator()(int x) const { return membranes[x]; }

    // Getters
    std::string getName() const { return name; }
    MembraneArray getMembranes() const { return membranes; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setMembranes(const MembraneArray& objects) { this->membranes = objects; }

    // Additional methods
    int getMembraneCount() const;
    Membrane get(int index) const;
    void set(int index, const Membrane& object);
    virtual Cell copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Cell > CellArray;

} // namespace bio

#endif //BIO_CELL_H