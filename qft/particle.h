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
#include "energy.h"
#include "isospin.h"
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
    std::shared_ptr<shp::Shape> physical;
    Isospin isospin;
    Spin spin;
    Energy energy;
public:
    // Constructors
    Particle();
    Particle(const float spin);
    Particle(const Spin& spin);
    Particle(const std::string name);
    Particle(const std::string name, const float spin);
    Particle(const std::string name, const Spin& spin);
    Particle(const Energy& energy);
    Particle(const std::string name, const Energy& energy);
    Particle(const Spin& spin, const Energy& energy);
    Particle(const std::string name, const float spin, const float energy);
    Particle(const std::string name, const Spin& spin, const Energy& energy);
    Particle(const std::string name, const Isospin& isospin, const Spin& spin, const Energy& energy);
    Particle(const Mass& mass, const Charge& charge);
    Particle(const std::string name, const Mass& mass, const Charge& charge);
    Particle(const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(const std::string name, const float spin, const float mass, const float energy);
    Particle(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(const std::shared_ptr<shp::Shape> wave);
    Particle(const std::string name, const std::shared_ptr<shp::Shape> wave);
    Particle(const std::string name, const std::shared_ptr<shp::Shape> wave, const Spin& spin);
    Particle(const std::string name, const std::shared_ptr<shp::Shape> wave, const Spin& spin, const Energy& energy);
    Particle(const std::string name, const std::shared_ptr<shp::Shape> wave, const Isospin& isospin, const Spin& spin, const Energy& energy);
    Particle(const std::shared_ptr<shp::Shape> wave, const Spin& spin, const Energy& energy);
    Particle(const std::shared_ptr<shp::Shape> wave, const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(const std::string name, const std::shared_ptr<shp::Shape> wave, const Spin& spin, const Mass& mass, const Charge& charge);

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
    std::shared_ptr<shp::Shape> getPhysical() const { return physical; }
    Isospin getIsospin() const { return isospin; }
    Spin getSpin() const { return spin; }
    Energy getEnergy() const { return energy; }

    // Setters
    void setPhysical(std::shared_ptr<shp::Shape> description) { this->physical = description; }
    void setIsospin(const Isospin& value) { isospin = value; }
    void setSpin(const Spin& value) { spin = value; }
    void setEnergy(const Energy& value) { energy = value; }

    // Additional methods
    Mass getMass() const { return energy.getMass(); }
    Charge getCharge() const { return energy.getCharge(); }
    void setMass(const Mass& value) { energy.setMass(value); }
    void setCharge(const Charge& value) { energy.setCharge(value); }
    shp::Signal getFrequency() const;
    shp::Signal getWavelength() const;
    bool isStructured() const;
    shp::Distance getRadius() const;
    void setRadius(const shp::Distance& length);
    std::shared_ptr<Field> getMassField() const;
    void setMassField(const std::shared_ptr<Field> field);
    std::shared_ptr<Field> getChargeField() const;
    void setChargeField(const std::shared_ptr<Field> field);
    shp::Signal getTotal() const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
};

typedef std::vector<Particle > ParticleArray;

} // namespace qft

#endif //QFT_PARTICLE_H