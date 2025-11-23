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

#ifndef CHE_ORBITAL_H
#define CHE_ORBITAL_H

#include <string>
#include <vector>
#include "electron.h"

namespace che {

class Orbital {
    short int n;
    short int l;
    short int m;
    short int s;
    Electron left;
    Electron right;
public:
    // Constructors
    Orbital();
    Orbital(short int n, short int l, short int m, short int s);
    Orbital(Electron& left, Electron& right);

    // Destructors
    ~Orbital();

    // Getters
    short int getN() const { return n; }
    short int getL() const { return l; }
    short int getM() const { return m; }
    short int getS() const { return s; }
    Electron getLeftSpinor() const { return left; }
    Electron getRightSpinor() const { return right; }

    // Setters
    void setN(const short int value) { this->n = value; }
    void setL(const short int value) { this->l = value; }
    void setM(const short int value) { this->m = value; }
    void setS(const short int value) { this->s = value; }
    void setLeftSpinor(const Electron& spinor) { this->left = spinor; }
    void setRightSpinor(const Electron& spinor) { this->right = spinor; }
};

typedef std::vector<Orbital > OrbitalArray;

} // namespace che

#endif //CHE_ORBITAL_H