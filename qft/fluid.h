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

#ifndef QFT_FLUID_H
#define QFT_FLUID_H

#include "../qft/energy.h"

namespace qft {

class Fluid : public qft::Density {
    qft::Energy energy;
public:
    // Constructors
    Fluid();
    Fluid(const qft::Energy& energy);
    Fluid(const float parameter, const qft::Energy& energy);
    Fluid(const float parameter, const short int scaling, const qft::Energy& energy);
    Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const qft::Energy& energy);
    Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const qft::Energy& energy);
    Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume, const qft::Energy& energy);
    Fluid(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Signal& volume, const qft::Energy& energy);
    Fluid(const std::string name);
    Fluid(const std::string name, const qft::Energy& energy);
    Fluid(const std::string name, const float parameter, const qft::Energy& energy);
    Fluid(const std::string name, const float parameter, const short int scaling, const qft::Energy& energy);
    Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const qft::Energy& energy);
    Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const qft::Energy& energy);
    Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume, const qft::Energy& energy);
    Fluid(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Signal& volume, const qft::Energy& energy);

    // Destructors
    ~Fluid();

    // Operator overloading
    bool operator==(const Fluid& peer) const;
    bool operator<(const Fluid& peer) const;
    bool operator>(const Fluid& peer) const;
    bool operator<=(const Fluid& peer) const;
    bool operator>=(const Fluid& peer) const;
    Fluid operator+(const Fluid& peer) const;
    Fluid operator-(const Fluid& peer) const;
    Fluid operator*(const Fluid& peer) const;
    Fluid operator/(const Fluid& peer) const;
    Fluid operator%(const Fluid& peer) const;

    // Getters
    qft::Energy getEnergy() const { return energy; }

    // Setters
    void setEnergy(const qft::Energy& vacuum) { this->energy = vacuum; }

    // Additional methods
    Fluid copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Fluid > FluidArray;

} // namespace qft

#endif //QFT_FLUID_H