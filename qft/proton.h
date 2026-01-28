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

#ifndef QFT_PROTON_H
#define QFT_PROTON_H

#include "electron.h"
#include "energy.h"
#include "particle.h"
#include "quark.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Proton : public Particle {
    Quark up[2];
    Quark down;
public:
    // Constructors
    Proton();
    Proton(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Proton(const std::string name);
    Proton(const float wavelength);
    Proton(const std::string name, const float wavelength);
    Proton(const std::string name, const Energy& energy);
    Proton(const std::string name, const Spin& spin, const Energy& energy);
    Proton(const std::string name, const float spin, const float mass, const float charge);
    Proton(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Proton();

    // Operator overloading
    bool operator==(const Proton& peer) const;
    Proton operator+(const Proton& peer) const;
    Proton operator-(const Proton& peer) const;
    Proton operator*(const Proton& peer) const;
    Proton operator/(const Proton& peer) const;
    Proton operator%(const Proton& peer) const;
    Neutron operator+(const Electron& peer) const;

    // Getters
    Quark getUp(const short int index) const;
    Quark getDown() const;

    // Setters
    void setUp(const Quark& particle, const short int index);
    void setDown(const Quark& particle);

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
private:
    void initialize();
public:
    static const short int UP_MIN;
    static const short int UP_MAX;
    static const float DEFAULT_SPIN;
    static const float RADIUS;
    static const short int RADIUS_SCALE;
    static const float COMPTON_WAVELENGTH;
    static const short int WAVELENGTH_SCALE;
};

typedef std::vector<Proton > ProtonArray;

} // namespace qft

#endif //QFT_PROTON_H