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

#ifndef CHE_REACTION_H
#define CHE_REACTION_H

#include <string>
#include <vector>
#include "energy.h"
#include "molecule.h"

namespace che {

class Reaction {
    std::string name;
    MoleculeArray reactants;
    MoleculeArray products;
    Energy change;
public:
    // Constructors
    Reaction();
    Reaction(std::string name);
    Reaction(std::string name, MoleculeArray& reactants, MoleculeArray& products, Energy& change);

    // Destructors
    ~Reaction();

    // Getters
    std::string getName() const { return name; }
    MoleculeArray getReactants() const { return reactants; }
    MoleculeArray getProducts() const { return products; }
    Energy getChange() const { return change; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setReactants(const MoleculeArray& reactants) { this->reactants = reactants; }
    void setProducts(const MoleculeArray& products) { this->products = products; }
    void setChange(const Energy& difference) { this->change = difference; }
};

typedef std::vector<Reaction > ReactionArray;

} // namespace che

#endif //CHE_REACTION_H