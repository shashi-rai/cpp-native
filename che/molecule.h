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

#ifndef CHE_MOLECULE_H
#define CHE_MOLECULE_H

#include "bond.h"
#include "../shp/shape.h"

namespace che {

class Molecule : public shp::Shape {
    std::string formulae;
    float potential;
    BondArray bonds;
public:
    // Constructors
    Molecule();
    Molecule(const std::string name);
    Molecule(const float potential);
    Molecule(const std::string name, const std::string formulae);
    Molecule(const std::string name, const std::string formulae, const float potential);
    Molecule(const BondArray& bonds);
    Molecule(const std::string name, const BondArray& bonds);
    Molecule(const std::string name, const float potential, const BondArray& bonds);
    Molecule(const std::string name, const std::string formulae, const float potential, const BondArray& bonds);

    // Destructors
    ~Molecule();

    // Operator overloading
    bool operator==(const Molecule& peer) const;
    Molecule operator+(const Molecule& peer) const;
    Molecule operator-(const Molecule& peer) const;

    // Access operator
    Bond& operator()(const int x) { return bonds[x]; }
    const Bond& operator()(const int x) const { return bonds[x]; }

    // Getters
    std::string getFormulae() const { return formulae; }
    float getPotential() const { return potential; }
    BondArray getBonds() const { return bonds; }

    // Setters
    void setFormulae(const std::string expression) { this->formulae = expression; }
    void setPotential(const float difference) { this->potential = difference; }
    void setBonds(const BondArray& objects) { this->bonds = objects; }

    // Additional methods
    int getBondCount() const;
    Bond get(const int index) const;
    void set(const int index, const Bond& object);
    Molecule copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printBonds() const;
};

typedef std::vector<Molecule > MoleculeArray;

} // namespace che

#endif //CHE_MOLECULE_H