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

#ifndef CHE_ELECTRON_H
#define CHE_ELECTRON_H

#include <string>
#include <vector>
#include "charge.h"

namespace che {

class Electron {
    std::string name;
    short int principal;
    short int azimuthal;
    short int magnetic;
    float spin;
    Charge charge;
public:
    // Constructors
    Electron();
    Electron(short int principal, short int azimuthal, short int magnetic, float spin);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, float spin, Charge& charge);

    // Destructors
    ~Electron();

    // Getters
    std::string getName() const { return name; }
    short int getPrincipal() const { return principal; }
    short int getAzimuthal() const { return azimuthal; }
    short int getMagnetic() const { return magnetic; }
    float getSpin() const { return spin; }
    Charge getCharge() const { return charge; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setPrincipal(const short int value) { this->principal = value; }
    void setAzimuthal(const short int value) { this->azimuthal = value; }
    void setMagnetic(const short int value) { this->magnetic = value; }
    void setSpin(float value) { this->spin = value; }
    void setCharge(const Charge& value) { this->charge = value; }
};

typedef std::vector<Electron > ElectronArray;

} // namespace che

#endif //CHE_ELECTRON_H