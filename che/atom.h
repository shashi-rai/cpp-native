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

#ifndef CHE_ATOM_H
#define CHE_ATOM_H

#include <string>
#include <vector>
#include "nucleus.h"
#include "orbital.h"

namespace che {

class Atom {
    std::string name;
    Nucleus nucleus;
    OrbitalArray orbitals;
    short valency;
public:
    // Constructors
    Atom();
    Atom(std::string name);
    Atom(std::string name, Nucleus& nucleus);
    Atom(std::string name, Nucleus& nucleus, OrbitalArray& orbitals, short valency);

    // Destructors
    ~Atom();

    // Getters
    std::string getName() const { return name; }
    Nucleus getNucleus() const { return nucleus; }
    OrbitalArray getOrbitals() const { return orbitals; }
    short getValency() const { return valency; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setNucleus(const Nucleus& nucleus) { this->nucleus = nucleus; }
    void setOrbitals(const OrbitalArray& orbitals) { this->orbitals = orbitals; }
    void setValency(const short electron) { this->valency = electron; }
};

typedef std::vector<Atom > AtomArray;

} // namespace che

#endif //CHE_ATOM_H