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

#ifndef BIO_CHROMOSOME_H
#define BIO_CHROMOSOME_H

#include <sstream>
#include <string>
#include <vector>
#include "gene.h"
#include "../shp/shape.h"

namespace bio {

class Chromosome : public shp::Shape {
    GeneArray genes;
public:
    // Constructors
    Chromosome();
    Chromosome(std::string name);
    Chromosome(std::string name, GeneArray& objects);

    // Destructors
    ~Chromosome();

    // Operator overloading
    bool operator==(const Chromosome& peer) const;
    Chromosome operator+(const Chromosome& peer) const;
    Chromosome operator-(const Chromosome& peer) const;

    // Access operator
    Gene& operator()(int x) { return genes[x]; }
    const Gene& operator()(int x) const { return genes[x]; }

    // Getters
    GeneArray getGenes() const { return genes; }

    // Setters
    void setGenes(const GeneArray& sequence) { this->genes = sequence; }

    // Additional methods
    int getGeneCount() const;
    Gene get(int index) const;
    void set(int index, const Gene& object);
    virtual Chromosome copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Chromosome > ChromosomeArray;

} // namespace bio

#endif //BIO_CHROMOSOME_H