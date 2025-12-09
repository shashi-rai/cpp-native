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

#ifndef BIO_MEMBRANE_H
#define BIO_MEMBRANE_H

#include <string>
#include <vector>
#include "protein.h"

namespace bio {

class Membrane {
    ProteinArray proteins;
    float voltage;
public:
    // Constructors
    Membrane();
    Membrane(std::string name);
    Membrane(std::string name, ProteinArray& objects);

    // Destructors
    ~Membrane();

    // Operator overloading
    bool operator==(const Membrane& peer) const;
    Membrane operator+(const Membrane& peer) const;
    Membrane operator-(const Membrane& peer) const;

    // Access operator
    Protein& operator()(int x) { return proteins[x]; }
    const Protein& operator()(int x) const { return proteins[x]; }

    // Getters
    ProteinArray getProteins() const { return proteins; }

    // Setters
    void setProteins(const ProteinArray& objects) { this->proteins = objects; }

    // Additional methods
    int getProteinCount() const;
    Protein get(int index) const;
    void set(int index, const Protein& object);
    virtual Membrane copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Membrane > MembraneArray;

} // namespace bio

#endif //BIO_MEMBRANE_H