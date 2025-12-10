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

#ifndef CHE_RING_H
#define CHE_RING_H

#include <string>
#include <vector>
#include "atom.h"
#include "molecule.h"

namespace che {

class Ring : public Molecule {
    AtomArray atoms;
public:
    // Constructors
    Ring();
    Ring(std::string name);
    Ring(std::string name, const AtomArray& atoms);

    // Destructors
    ~Ring();

    // Operator overloading
    bool operator==(const Ring& peer) const;
    Ring operator+(const Ring& peer) const;
    Ring operator-(const Ring& peer) const;

    // Access operator
    Atom& operator()(int x) { return atoms[x]; }
    const Atom& operator()(int x) const { return atoms[x]; }

    // Getters
    AtomArray getAtoms() const { return atoms; }

    // Setters
    void setAtoms(const AtomArray& value) { this->atoms = value; }

    // Additional methods
    int getAtomCount() const;
    Atom get(int index) const;
    void set(int index, const Atom& object);
    virtual Molecule copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Ring > RingArray;

} // namespace che

#endif //CHE_RING_H