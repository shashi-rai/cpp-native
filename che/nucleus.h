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
    short int proton;
    short int neutron;
    qft::Energy energy;
public:
    // Constructors
    Nucleus();
    Nucleus(short int proton);
    Nucleus(short int proton, short int neutron);
    Nucleus(std::string symbol);
    Nucleus(std::string symbol, short int proton);
    Nucleus(std::string symbol, short int proton, short int neutron);
    Nucleus(std::string symbol, short int proton, short int neutron,
        qft::Mass& mass);
    Nucleus(std::string symbol, short int proton, short int neutron,
        qft::Charge& charge);
    Nucleus(std::string symbol, short int proton, short int neutron,
        qft::Mass& mass, qft::Charge& charge);
    Nucleus(std::string symbol, short int proton, short int neutron,
        qft::Energy& energy);

    // Destructors
    ~Nucleus();

    // Operator overloading
    bool operator==(const Nucleus& peer) const;
    Nucleus operator+(const Nucleus& peer) const;
    Nucleus operator-(const Nucleus& peer) const;

    // Getters
    std::string getSymbol() const { return symbol; }
    short int getProton() const { return proton; }
    short int getNeutron() const { return neutron; }
    qft::Mass getMass() const { return energy.getMass(); }
    qft::Charge getCharge() const { return energy.getCharge(); }
    qft::Energy getEnergy() const { return energy; }

    // Setters
    void setSymbol(const std::string& name) { this->symbol = name; }
    void setProton(short int number) { this->proton = number; }
    void setNeutron(short int number) { this->neutron = number; }
    void setMass(const qft::Mass& amount) { this->energy.setMass(amount); }
    void setCharge(const qft::Charge& amount) { this->energy.setCharge(amount); }
    void setEnergy(const qft::Energy& amount) { this->energy = amount; }

    // Additional methods
    std::string getElementName() const;
    virtual Nucleus copy();
    virtual void clear();
    virtual std::string print();
public:
    static const std::string getSymbol(short int number);
    static const std::string getName(short int number);
public:
    static const int PROTON_MIN_LIMIT;
    static const int PROTON_MAX_LIMIT;
    static const int NEUTRON_MAX_LIMIT;
    static const std::string UNKNOWN;
    static const std::string ELEMENT_SYMBOL[];
    static const std::string ELEMENT_NAME[];
};

typedef std::vector<Nucleus > NucleusArray;

} // namespace che

#endif //CHE_NUCLEUS_H