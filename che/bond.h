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

#ifndef CHE_BOND_H
#define CHE_BOND_H

#include <string>
#include <vector>
#include "atom.h"
#include "electron.h"
#include "../qft/energy.h"

namespace che {

class Bond {
    std::string name;
    Atom left;
    Atom right;
    Electron electron;
    qft::Energy energy;
    double length;
    double angle;
public:
    // Constructors
    Bond();
    Bond(std::string name);
    Bond(std::string name, Atom& left, Atom& right);
    Bond(std::string name, Atom& left, Atom& right, Electron& electron,
        qft::Energy& energy, double length, double angle);

    // Destructors
    ~Bond();

    // Getters
    std::string getName() const { return name; }
    Atom getLeft() const { return left; }
    Atom getRight() const { return right; }
    Electron getElectron() const { return electron; }
    qft::Energy getEnergy() const { return energy; }
    double getLength() const { return length; }
    double getAngle() const { return angle; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setLeft(const Atom& atom) { this->left = atom; }
    void setRight(const Atom& atom) { this->right = atom; }
    void setElectron(const Electron& value) { this->electron = value; }
    void setEnergy(const qft::Energy& value) { this->energy = value; }
    void setLength(double value) { this->length = value; }
    void setAngle(double value) { this->angle = value; }
};

typedef std::vector<Bond > BondArray;

} // namespace che

#endif //CHE_BOND_H