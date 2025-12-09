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

#ifndef BIO_PROTEIN_H
#define BIO_PROTEIN_H

#include <string>
#include <vector>
#include "gate.h"

namespace bio {

class Protein {
    GateArray gates;
public:
    // Constructors
    Protein();
    Protein(std::string name);
    Protein(std::string name, GateArray& objects);

    // Destructors
    ~Protein();

    // Operator overloading
    bool operator==(const Protein& peer) const;
    Protein operator+(const Protein& peer) const;
    Protein operator-(const Protein& peer) const;

    // Access operator
    Gate& operator()(int x) { return gates[x]; }
    const Gate& operator()(int x) const { return gates[x]; }

    // Getters
    GateArray getGates() const { return gates; }

    // Setters
    void setGates(const GateArray& objects) { this->gates = objects; }

    // Additional methods
    int getGateCount() const;
    Gate get(int index) const;
    void set(int index, const Gate& object);
    virtual Protein copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Protein > ProteinArray;

} // namespace bio

#endif //BIO_PROTEIN_H