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

#ifndef QFT_BOSON_H
#define QFT_BOSON_H

#include "energy.h"
#include "handed.h"
#include "particle.h"

namespace qft {

class Boson : public Particle {
    Handed handed;
public:
    // Constructors
    Boson();
    Boson(const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Boson(const Spin& spin);
    Boson(const Spin& spin,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Boson(const std::string name);
    Boson(const std::string name,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Boson(const std::string name, const Spin& spin);
    Boson(const std::string name, const Spin& spin,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Boson(const float wavelength);
    Boson(const float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Boson(const std::string name, const float wavelength);
    Boson(const std::string name, const float wavelength,
        const std::shared_ptr<Field> mass, const std::shared_ptr<Field> charge);
    Boson(const std::string name, const Energy& energy);
    Boson(const std::string name, const Spin& spin, const Energy& energy);
    Boson(const std::string name, const float spin, const float mass, const float charge);
    Boson(const std::string name, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Boson();

    // Operator overloading
    bool operator==(const Boson& peer) const;
    Boson operator+(const Boson& peer) const;
    Boson operator-(const Boson& peer) const;
    Boson operator*(const Boson& peer) const;
    Boson operator/(const Boson& peer) const;
    Boson operator%(const Boson& peer) const;

    // Getters
    Handed getHanded() const { return handed; }

    // Setters
    void setHanded(const Handed& orientation) { this->handed = orientation; }

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
public:
    static const float DEFAULT_CHARGE;
    static const float DEFAULT_MASS;
    static const float DEFAULT_PARITY;
    static const float SCALAR_SPIN;
    static const float GUAGE_SPIN1;
    static const float GUAGE_SPIN2;
};

typedef std::vector<Boson > BosonArray;

} // namespace qft

#endif //QFT_BOSON_H