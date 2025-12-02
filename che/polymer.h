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

#ifndef CHE_POLYMER_H
#define CHE_POLYMER_H

#include <string>
#include <vector>
#include "molecule.h"

namespace che {

class Polymer : public shp::Point {
    MoleculeArray monomers;
public:
    // Constructors
    Polymer();
    Polymer(float gradient);
    Polymer(float amplitude, float gradient);
    Polymer(std::string name);
    Polymer(std::string name, float gradient);
    Polymer(std::string name, float amplitude, float gradient);
    Polymer(std::string name, const MoleculeArray& monomers);

    // Destructors
    ~Polymer();

    // Getters
    MoleculeArray getMonomers() const { return monomers; }

    // Setters
    void setMonomers(const MoleculeArray& value) { this->monomers = value; }

    // Additional methods
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Polymer > PolymerArray;

} // namespace che

#endif //CHE_POLYMER_H