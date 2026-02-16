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
    Atom(const short int number);
    Atom(const short int number, const std::string name);
    Atom(const std::string name);
    Atom(const std::string symbol, const std::string name);
    Atom(const std::string name, const float gradient);
    Atom(const std::string name, const Nucleus& nucleus);
    Atom(const std::string name, const float gradient, const Nucleus& nucleus);
    Atom(const std::string name, const Nucleus& nucleus, const short int valency);
    Atom(const std::string name, const float gradient, Nucleus& nucleus, const short int valency);

    // Destructors
    ~Atom();

    // Operator overloading
    bool operator==(const Atom& peer) const;

    // Access operator
    Period operator()(const int x) { return getPeriod(x); }
    const Period operator()(const int x) const { return getPeriod(x); }
    Orbital operator()(const int x, const int y) { return getPeriod(x).getOrbital(y); }
    const Orbital operator()(const int x, const int y) const { return getPeriod(x).getOrbital(y); }
    qft::Electron operator()(const int x, const int y, const int z) { return getPeriod(x).getOrbital(y).getElectron(z); }
    const qft::Electron operator()(const int x, const int y, const int z) const { return getPeriod(x).getOrbital(y).getElectron(z); }

    // Getters
    Nucleus getNucleus() const { return nucleus; }
    short int getValency() const { return valency; }

    // Setters
    void setNucleus(const Nucleus& nucleus) { this->nucleus = nucleus; }
    void setValency(const short int electron) { this->valency = electron; }

    // Additional methods
    std::string getElementName() const;
    Period getPeriod(const short int primary) const;
    void setPeriod(const short int primary, const std::shared_ptr<che::Period> object);
    Orbital getOrbital(const short int primary, const short int azimuthal) const;
    void setOrbital(const short int primary, const short int azimuthal, const std::shared_ptr<che::Orbital> object);
    qft::Electron getElectron(const short int primary, const short int azimuthal, const short int magnetic) const;
    void setElectron(const short int primary, const short int azimuthal, const short int magnetic, const std::shared_ptr<qft::Electron> object);
    virtual void clear();
    virtual std::string print() const;
public:
    static const std::string getSymbol(const short int number);
    static const std::string getName(const short int number);
    static std::shared_ptr<che::Atom> initialize(short number, std::string name);
private:
    static void createPeriods(std::shared_ptr<che::Period> peer,
        std::string prefix, short int period, const short int capacity);
    static void createOrbitals(std::shared_ptr<che::Period> peer,
        std::string prefix, const short int period, const short int starting, const short int capacity);
public:
    static const int ELEMENT_MIN_LIMIT;
    static const int ELEMENT_MAX_LIMIT;
    static const int S_BLOCK[];
    static const int P_BLOCK[];
    static const int D_BLOCK[];
    static const int F_BLOCK[];
    static const int ALKALI_METAL[];
    static const int ALKALINE_METAL[];
    static const int SEMICONDUCTOR[];
    static const int HALOGEN_GAS[];
    static const int NOBLE_GAS[];
    static const int TRANSITION_METAL[];
    static const int POST_TRANSITION_METAL[];
    static const int NON_METAL[];
    static const int METALLOID[];
    static const int LANTHANIDE[];
    static const int ACTINIDE[];
};

typedef std::vector<Atom > AtomArray;

} // namespace che

#endif //CHE_ATOM_H