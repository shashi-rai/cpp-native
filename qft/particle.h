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

#ifndef QFT_PARTICLE_H
#define QFT_PARTICLE_H

#include <vector>
#include "charge.h"
#include "energy.h"
#include "mass.h"
#include "spin.h"
#include "../shp/point.h"
#include "../shp/wave.h"

namespace qft {

// To enable compiler resolve forward declarations
class Photon;
class Neutrino;
class Quark;
class Proton;
class Neutron;
class Electron;

class Particle : public shp::Wave {
    shp::Shape* physical;
    Spin spin;
    Energy energy;
public:
    // Constructors
    Particle();
    Particle(const float spin);
    Particle(const Spin& spin);
    Particle(std::string name);
    Particle(std::string name, const float spin);
    Particle(std::string name, const Spin& spin);
    Particle(const Energy& energy);
    Particle(std::string name, const Energy& energy);
    Particle(const Spin& spin, const Energy& energy);
    Particle(std::string name, const float spin, const float energy);
    Particle(std::string name, const Spin& spin, const Energy& energy);
    Particle(const Mass& mass, const Charge& charge);
    Particle(std::string name, const Mass& mass, const Charge& charge);
    Particle(const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(std::string name, const float spin, const float mass, const float energy);
    Particle(std::string name, const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(shp::Shape* wave);
    Particle(std::string name, shp::Shape* wave);
    Particle(std::string name, shp::Shape* wave, const Spin& spin);
    Particle(std::string name, shp::Shape* wave, const Spin& spin, const Energy& energy);
    Particle(shp::Shape* wave, const Spin& spin, const Energy& energy);
    Particle(shp::Shape* wave, const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(std::string name, shp::Shape* wave, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Particle();

    // Operator overloading
    bool operator==(const Particle& peer) const;
    Particle operator+(const Particle& peer) const;
    Particle operator-(const Particle& peer) const;
    Particle operator*(const Particle& peer) const;
    Particle operator/(const Particle& peer) const;
    Particle operator%(const Particle& peer) const;

    // Getters
    shp::Shape* getPhysical() const { return physical; }
    Spin getSpin() const { return spin; }
    Energy getEnergy() const { return energy; }

    // Setters
    void setPhysical(shp::Shape* description) { this->physical = description; }
    void setSpin(const Spin& value) { spin = value; }
    void setEnergy(const Energy& value) { energy = value; }

    // Additional methods
    Mass getMass() const { return energy.getMass(); }
    Charge getCharge() const { return energy.getCharge(); }
    void setMass(const Mass& value) { energy.setMass(value); }
    void setCharge(const Charge& value) { energy.setCharge(value); }
    bool isStructured() const;
    float getTotal() const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Particle > ParticleArray;

} // namespace qft

#endif //QFT_PARTICLE_H