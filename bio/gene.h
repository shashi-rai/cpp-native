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

#ifndef BIO_GENE_H
#define BIO_GENE_H

#include <sstream>
#include <string>
#include <vector>
#include "nucleotide.h"
#include "../shp/shape.h"

namespace bio {

class Gene : public shp::Shape {
    NucleotideArray sequence;
public:
    // Constructors
    Gene();
    Gene(std::string name, NucleotideArray& codon);

    // Destructors
    ~Gene();

    // Operator overloading
    bool operator==(const Gene& peer) const;
    Gene operator+(const Gene& peer) const;
    Gene operator-(const Gene& peer) const;

    // Access operator
    Nucleotide& operator()(int x) { return sequence[x]; }
    const Nucleotide& operator()(int x) const { return sequence[x]; }

    // Getters
    NucleotideArray getSequence() const { return sequence; }

    // Setters
    void setSequence(const NucleotideArray& codon) { this->sequence = codon; }

    // Additional methods
    int getNucleotideCount() const;
    Nucleotide get(int index) const;
    void set(int index, const Nucleotide& object);
    virtual Gene copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Gene > GeneArray;

} // namespace bio

#endif //BIO_GENE_H