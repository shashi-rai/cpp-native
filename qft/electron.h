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

#ifndef QFT_ELECTRON_H
#define QFT_ELECTRON_H

#include <string>
#include <vector>
#include "energy.h"
#include "particle.h"
#include "photon.h"
#include "spin.h"
#include "../shp/wave.h"

namespace qft {

class Electron : public Particle {
    short int principal;
    short int azimuthal;
    short int magnetic;
public:
    // Constructors
    Electron();
    Electron(float polarization);
    Electron(float polarization, float azimuthal);
    Electron(std::string name);
    Electron(std::string name, float polarization);
    Electron(std::string name, float polarization, float azimuthal);
    Electron(const Energy& energy);
    Electron(std::string name, const Energy& energy);
    Electron(std::string name, const Spin& spin, const Energy& energy);
    Electron(const Mass& mass, const Charge& charge);
    Electron(std::string name, const Mass& mass, const Charge& charge);
    Electron(std::string name, const float spin, const float mass, const float charge);
    Electron(std::string name, const Spin& spin, const Mass& mass, const Charge& charge);
    Electron(short int principal, short int azimuthal,
        short int magnetic, float spin);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const Spin& spin,
        const Energy& energy);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const Spin& spin,
        const Mass& mass);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const Spin& spin,
        const Charge& charge);
    Electron(std::string name, short int principal, short int azimuthal,
        short int magnetic, const Spin& spin,
        const Mass& mass, const Charge& charge);

    // Destructors
    ~Electron();

    // Operator overloading
    bool operator==(const Electron& peer) const;
    Electron operator+(const Electron& peer) const;
    Electron operator-(const Electron& peer) const;
    Electron operator*(const Electron& peer) const;
    Electron operator/(const Electron& peer) const;
    Electron operator%(const Electron& peer) const;
    Electron operator+(const Photon& peer) const;
    Electron operator-(const Photon& peer) const;
    Electron operator*(const Photon& peer) const;
    Electron operator/(const Photon& peer) const;
    Electron operator%(const Photon& peer) const;

    // Getters
    short int getPrincipal() const { return principal; }
    short int getAzimuthal() const { return azimuthal; }
    short int getMagnetic() const { return magnetic; }

    // Setters
    void setPrincipal(const short int number) { this->principal = number; }
    void setAzimuthal(const short int number) { this->azimuthal = number; }
    void setMagnetic(const short int number) { this->magnetic = number; }

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();

public:
    static const short int DEFAULT_VALUE;
};

typedef std::vector<Electron > ElectronArray;

} // namespace qft

#endif //QFT_ELECTRON_H