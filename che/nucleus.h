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

#ifndef CHE_NUCLEUS_H
#define CHE_NUCLEUS_H

#include <string>
#include <vector>
#include "charge.h"
#include "energy.h"
#include "mass.h"

namespace che {

class Nucleus {
    std::string symbol;
    short proton;
    short neutron;
    Mass mass;
    Charge charge;
    Energy energy;
public:
    // Constructors
    Nucleus();
    Nucleus(std::string symbol);
    Nucleus(std::string symbol, short proton, short neutron,
        Mass& mass, Charge& charge, Energy& energy);

    // Destructors
    ~Nucleus();

    // Getters
    std::string getSymbol() const { return symbol; }
    short getProton() const { return proton; }
    short getNeutron() const { return neutron; }
    Mass getMass() const { return mass; }
    Charge getCharge() const { return charge; }
    Energy getEnergy() const { return energy; }

    // Setters
    void setSymbol(const std::string& name) { this->symbol = name; }
    void setProton(short number) { this->proton = number; }
    void setNeutron(short number) { this->neutron = number; }
    void setMass(const Mass& amount) { this->mass = amount; }
    void setCharge(const Charge& amount) { this->charge = amount; }
    void setEnergy(const Energy& amount) { this->energy = amount; }
};

typedef std::vector<Nucleus > NucleusArray;

} // namespace che

#endif //CHE_NUCLEUS_H