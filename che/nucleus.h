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
#include "../qft/charge.h"
#include "../qft/energy.h"
#include "../qft/mass.h"

namespace che {

class Nucleus {
    std::string symbol;
    short proton;
    short neutron;
    qft::Mass mass;
    qft::Charge charge;
    qft::Energy energy;
public:
    // Constructors
    Nucleus();
    Nucleus(short proton);
    Nucleus(std::string symbol);
    Nucleus(std::string symbol, short proton);
    Nucleus(std::string symbol, short proton, short neutron);
    Nucleus(std::string symbol, short proton, short neutron,
        qft::Mass& mass, qft::Charge& charge, qft::Energy& energy);

    // Destructors
    ~Nucleus();

    // Getters
    std::string getSymbol() const { return symbol; }
    short getProton() const { return proton; }
    short getNeutron() const { return neutron; }
    qft::Mass getMass() const { return mass; }
    qft::Charge getCharge() const { return charge; }
    qft::Energy getEnergy() const { return energy; }

    // Setters
    void setSymbol(const std::string& name) { this->symbol = name; }
    void setProton(short number) { this->proton = number; }
    void setNeutron(short number) { this->neutron = number; }
    void setMass(const qft::Mass& amount) { this->mass = amount; }
    void setCharge(const qft::Charge& amount) { this->charge = amount; }
    void setEnergy(const qft::Energy& amount) { this->energy = amount; }

    // Additional methods
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Nucleus > NucleusArray;

} // namespace che

#endif //CHE_NUCLEUS_H