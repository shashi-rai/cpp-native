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

#ifndef BIO_NUCLEOTIDE_H
#define BIO_NUCLEOTIDE_H

#include <string>
#include <vector>
#include "base.h"
#include "phosphate.h"
#include "sugar.h"
#include "../shp/shape.h"

namespace bio {

class Nucleotide : public shp::Shape {
    Base base;
    Sugar sugar;
    Phosphate phosphate;
public:
    // Constructors
    Nucleotide();
    Nucleotide(std::string name, Base& base, Sugar& sugar, Phosphate& phosphate);

    // Destructors
    ~Nucleotide();

    // Getters
    Base getBase() const { return base; }
    Sugar getSugar() const { return sugar; }
    Phosphate getPhosphate() const { return phosphate; }

    // Setters
    void setBase(const Base& molecule) { this->base = molecule; }
    void setSugar(const Sugar& molecule) { this->sugar = molecule; }
    void setPhosphate(const Phosphate& molecule) { this->phosphate = molecule; }
};

typedef std::vector<Nucleotide > NucleotideArray;

} // namespace bio

#endif //BIO_NUCLEOTIDE_H