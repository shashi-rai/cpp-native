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

#ifndef BIO_TISSUE_H
#define BIO_TISSUE_H

#include <string>
#include <vector>
#include "cell.h"
#include "../shp/shape.h"

namespace bio {

class Tissue : public shp::Shape {
    CellArray cells;
public:
    // Constructors
    Tissue();
    Tissue(std::string name);
    Tissue(std::string name, CellArray& objects);

    // Destructors
    ~Tissue();

    // Operator overloading
    bool operator==(const Tissue& peer) const;
    Tissue operator+(const Tissue& peer) const;
    Tissue operator-(const Tissue& peer) const;

    // Access operator
    Cell& operator()(int x) { return cells[x]; }
    const Cell& operator()(int x) const { return cells[x]; }

    // Getters
    CellArray getCells() const { return cells; }

    // Setters
    void setCells(const CellArray& objects) { this->cells = objects; }

    // Additional methods
    int getCellCount() const;
    Cell get(int index) const;
    void set(int index, const Cell& object);
    virtual Tissue copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Tissue > TissueArray;

} // namespace bio

#endif //BIO_TISSUE_H