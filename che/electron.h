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
#include "photon.h"
#include "../qft/energy.h"
#include "../qft/spin.h"
#include "../shp/wave.h"

namespace che {

class Electron : public shp::Wave {
    short int principal;
    short int azimuthal;
    short int magnetic;
    qft::Spin spin;
    qft::Energy energy;
public:
    // Constructors
    Electron();
    Electron(float polarization);
    Electron(float polarization, float azimuthal);
    Electron(std::string name);
    Electron(std::string name, float polarization);
    Electron(std::string name, float polarization, float azimuthal);
    Electron(const qft::Energy& energy);
    Electron(std::string name, const qft::Energy& energy);
    Electron(const qft::Mass& mass, const qft::Charge& charge);
    Electron(std::string name, const qft::Mass& mass, const qft::Charge& charge);
    Electron(short int principal, short int azimuthal,
        short int magnetic, float spin);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const qft::Spin& spin,
        const qft::Energy& energy);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const qft::Spin& spin,
        const qft::Mass& mass);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const qft::Spin& spin,
        const qft::Charge& charge);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const qft::Spin& spin,
        const qft::Mass& mass, const qft::Charge& charge);

    // Destructors
    ~Electron();

    // Operator overloading
    bool operator==(const Electron& peer) const;
    Electron operator+(const Photon& peer) const;
    Electron operator-(const Photon& peer) const;

    // Getters
    short int getPrincipal() const { return principal; }
    short int getAzimuthal() const { return azimuthal; }
    short int getMagnetic() const { return magnetic; }
    qft::Spin getSpin() const { return spin; }
    qft::Energy getEnergy() const { return energy; }

    // Setters
    void setPrincipal(const short int number) { this->principal = number; }
    void setAzimuthal(const short int number) { this->azimuthal = number; }
    void setMagnetic(const short int number) { this->magnetic = number; }
    void setSpin(const qft::Spin orientation) { this->spin = orientation; }
    void setEnergy(const qft::Energy& quantum) { this->energy = quantum; }

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();

public:
    static const short int DEFAULT_VALUE;
};

typedef std::vector<Electron > ElectronArray;

} // namespace che

#endif //CHE_ELECTRON_H