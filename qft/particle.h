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

#include "energy.h"
#include "isospin.h"
#include "spin.h"
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
    Isospin isospin;
    Spin spin;
    Energy energy;
public:
    // Constructors
    Particle();
    Particle(const std::string name);
    Particle(const float spin);
    Particle(const Spin& spin);
    Particle(const std::string name, const float spin);
    Particle(const std::string name, const Spin& spin);
    Particle(const Isospin& isospin);
    Particle(const std::string name, const Isospin& isospin);
    Particle(const std::string name, const Isospin& isospin, const Spin& spin);
    Particle(const Energy& energy);
    Particle(const std::string name, const Energy& energy);
    Particle(const Spin& spin, const Energy& energy);
    Particle(const std::string name, const float spin, const float energy);
    Particle(const std::string name, const Spin& spin, const Energy& energy);
    Particle(const Isospin& isospin, const Energy& energy);
    Particle(const std::string name, const Isospin& isospin, const Energy& energy);
    Particle(const Isospin& isospin, const Spin& spin, const Energy& energy);
    Particle(const std::string name, const Isospin& isospin, const Spin& spin, const Energy& energy);
    Particle(const Mass& mass, const Charge& charge);
    Particle(const std::string name, const Mass& mass, const Charge& charge);
    Particle(const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(const std::string name, const float spin, const float mass, const float energy);
    Particle(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge);
    Particle(const std::string name, const Isospin& isospin, const Mass& mass, const Charge& charge);
    Particle(const std::string name, const Isospin& isospin, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Particle();

    // Operator overloading
    bool operator==(const Particle& peer) const;
    bool operator<(const Particle& peer) const;
    bool operator>(const Particle& peer) const;
    bool operator<=(const Particle& peer) const;
    bool operator>=(const Particle& peer) const;
    Particle operator+(const Particle& peer) const;
    Particle operator-(const Particle& peer) const;
    Particle operator*(const Particle& peer) const;
    Particle operator/(const Particle& peer) const;
    Particle operator%(const Particle& peer) const;

    // Getters
    Isospin getIsospin() const { return isospin; }
    Spin getSpin() const { return spin; }
    Energy getEnergy() const { return energy; }

    // Setters
    void setIsospin(const Isospin& value) { isospin = value; }
    void setSpin(const Spin& value) { spin = value; }
    void setEnergy(const Energy& value) { energy = value; }

    // Additional methods
    Mass getMass() const;
    void setMass(const Mass& value);
    Charge getCharge() const;
    void setCharge(const Charge& value);
    Temperature getTemperature() const;
    void setTemperature(const Temperature& value);
    shp::Signal getFrequency() const;
    shp::Signal getWavelength() const;
    shp::Distance getMassFieldRadius() const;
    void setMassFieldRadius(const shp::Distance& radius);
    void setMassFluxChange(const shp::Azimuth& shift);
    void setMassFlowChange(const shp::Signal& motion);
    shp::Distance getChargeFieldRadius() const;
    void setChargeFieldRadius(const shp::Distance& radius);
    void setChargeFluxChange(const shp::Azimuth& shift);
    void setChargeFlowChange(const shp::Signal& motion);
    shp::Distance getThermalFieldRadius() const;
    void setThermalFieldRadius(const shp::Distance& radius);
    void setThermalFluxChange(const shp::Azimuth& shift);
    void setThermalFlowChange(const shp::Signal& motion);
    std::shared_ptr<Field> getMassField() const;
    void setMassField(const std::shared_ptr<Field> field);
    std::shared_ptr<Field> getChargeField() const;
    void setChargeField(const std::shared_ptr<Field> field);
    std::shared_ptr<Field> getThermalField() const;
    void setThermalField(const std::shared_ptr<Field> field);
    shp::Signal getTotal() const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
};

typedef std::vector<Particle > ParticleArray;

} // namespace qft

#endif //QFT_PARTICLE_H