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

#ifndef QFT_QUARK_H
#define QFT_QUARK_H

#include <string>
#include <vector>
#include "colour.h"
#include "energy.h"
#include "handed.h"
#include "particle.h"

namespace qft {

class Quark : public Particle {
    Colour colour;
    Handed handed;
public:
    // Constructors
    Quark();
    Quark(std::string name);
    Quark(const float wavelength);
    Quark(std::string name, const float wavelength);
    Quark(std::string name, const Energy& energy);
    Quark(std::string name, const Spin& spin, const Energy& energy);
    Quark(std::string name, const Mass& mass, const Charge& charge);
    Quark(std::string name, const float spin, const float mass, const float charge);
    Quark(std::string name, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Quark();

    // Operator overloading
    bool operator==(const Quark& peer) const;
    Quark operator+(const Quark& peer) const;
    Quark operator-(const Quark& peer) const;
    Quark operator*(const Quark& peer) const;
    Quark operator/(const Quark& peer) const;
    Quark operator%(const Quark& peer) const;

    // Getters
    Colour getColour() const { return colour; }
    Handed getHanded() const { return handed; }

    // Setters
    void setColour(const Colour& value) { colour = value; }
    void setHanded(const Handed& value) { handed = value; }

    // Additional methods
    shp::Quantity getWavelength() const;
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
public:
    static const Mass getMassLow(short int number);
    static const Mass getMassHigh(short int number);
    static const Charge getElectricCharge(short int number);
public:
    enum TYPE {
        UP, DOWN,           // First Generation
        CHARM, STRANGE,     // Second Generation
        TOP, BOTTOM,        // Third Generation
    };
    enum COLOUR {
        RED, GREEN, BLUE,
    };
    static const short int TYPE_MAX;
    static const short int COLOUR_MAX;
    static const short int GENERATION_MAX;
    static const float MASS_LOWER[];
     static const float MASS_HIGHER[];
    static const float ELECTRIC_CHARGE[];
    static const float DEFAULT_SPIN;
};

typedef std::vector<Quark > QuarkArray;

} // namespace qft

#endif //QFT_QUARK_H