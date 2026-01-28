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

#ifndef QFT_NEUTRON_H
#define QFT_NEUTRON_H

#include "electron.h"
#include "energy.h"
#include "particle.h"
#include "quark.h"

namespace qft {

// To enable compiler resolve forward declarations
class Field;

class Neutron : public Particle {
    Quark up;
    Quark down[2];
public:
    // Constructors
    Neutron();
    Neutron(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Neutron(const std::string name);
    Neutron(const float wavelength);
    Neutron(const std::string name, const float wavelength);
    Neutron(const std::string name, const Energy& energy);
    Neutron(const std::string name, const Spin& spin, const Energy& energy);
    Neutron(const std::string name, const float spin, const float mass, const float charge);
    Neutron(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Neutron();

    // Operator overloading
    bool operator==(const Neutron& peer) const;
    Neutron operator+(const Neutron& peer) const;
    Neutron operator-(const Neutron& peer) const;
    Neutron operator*(const Neutron& peer) const;
    Neutron operator/(const Neutron& peer) const;
    Neutron operator%(const Neutron& peer) const;
    Proton operator-(const Electron& peer) const;

    // Getters
    Quark getUp() const;
    Quark getDown(const short int index) const;

    // Setters
    void setUp(const Quark& particle);
    void setDown(const Quark& particle, const short int index);

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
private:
    void initialize();
public:
    static const short int DOWN_MIN;
    static const short int DOWN_MAX;
    static const float DEFAULT_SPIN;
    static const float RADIUS;
    static const short int RADIUS_SCALE;
    static const float COMPTON_WAVELENGTH;
    static const short int WAVELENGTH_SCALE;
};

typedef std::vector<Neutron > NeutronArray;

} // namespace qft

#endif //QFT_NEUTRON_H