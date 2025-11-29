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
#include "period.h"
#include "../shp/cellular.h"

namespace che {

class Atom : public shp::Cellular {
    Nucleus nucleus;
    short int valency;
public:
    // Constructors
    Atom();
    Atom(std::string name);
    Atom(std::string name, float gradient);
    Atom(std::string name, Nucleus& nucleus);
    Atom(std::string name, float gradient, Nucleus& nucleus);
    Atom(std::string name, Nucleus& nucleus, short valency);
    Atom(std::string name, float gradient, Nucleus& nucleus, short valency);

    // Destructors
    ~Atom();

    // Getters
    Nucleus getNucleus() const { return nucleus; }
    short int getValency() const { return valency; }

    // Setters
    void setNucleus(const Nucleus& nucleus) { this->nucleus = nucleus; }
    void setValency(const short int electron) { this->valency = electron; }

    // Additional methods
    Period getPeriod(int primary) const;
    void setPeriod(int primary, const Period& object);
    Orbital getOrbital(int primary, int azimuthal) const;
    void setOrbital(int primary, int azimuthal, const Orbital& object);
    Electron getElectron(int primary, int azimuthal, int magnetic) const;
    void setElectron(int primary, int azimuthal, int magnetic, const Electron& object);
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Atom > AtomArray;

} // namespace che

#endif //CHE_ATOM_H