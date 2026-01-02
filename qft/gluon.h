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

#ifndef QFT_GLUON_H
#define QFT_GLUON_H

#include <string>
#include <vector>
#include "energy.h"
#include "boson.h"
#include "colour.h"

namespace qft {

class Gluon : public Boson {
    Colour charge;
public:
    // Constructors
    Gluon();
    Gluon(std::string name);
    Gluon(const float wavelength);
    Gluon(std::string name, const float wavelength);
    Gluon(std::string name, const Energy& energy);
    Gluon(std::string name, const Spin& spin, const Energy& energy);
    Gluon(std::string name, const float spin, const float mass, const float charge);
    Gluon(std::string name, const Spin& spin, const Mass& mass, const Charge& charge);

    // Destructors
    ~Gluon();

    // Operator overloading
    bool operator==(const Gluon& peer) const;
    Gluon operator+(const Gluon& peer) const;
    Gluon operator-(const Gluon& peer) const;
    Gluon operator*(const Gluon& peer) const;
    Gluon operator/(const Gluon& peer) const;
    Gluon operator%(const Gluon& peer) const;

    // Getters
    Colour getCharge() const { return charge; }

    // Setters
    void setCharge(const Colour& object) { this->charge = object; }

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Gluon > GluonArray;

} // namespace qft

#endif //QFT_GLUON_H