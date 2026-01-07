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

#ifndef ECN_TRANSFORMER_H
#define ECN_TRANSFORMER_H

#include <sstream>
#include <string>
#include <vector>
#include "coil.h"

namespace ecn {

class Transformer : public Element {
    Coil primary;
    Coil secondary;
public:
    // Constructors
    Transformer();
    Transformer(const Coil& primary);
    Transformer(const Coil& primary, const Coil& secondary);
    Transformer(std::string name);
    Transformer(std::string name, const Coil& primary);
    Transformer(std::string name, const Coil& primary, const Coil& secondary);

    // Destructors
    ~Transformer();

    // Operator overloading
    bool operator==(const Transformer& peer) const;
    Transformer operator+(const Transformer& peer) const;
    Transformer operator-(const Transformer& peer) const;
    Transformer operator*(const Transformer& peer) const;
    Transformer operator/(const Transformer& peer) const;
    Transformer operator%(const Transformer& peer) const;

    // Getters
    Coil getPrimary() const { return primary; }
    Coil getSecondary() const { return secondary; }

    // Setters
    void setPrimary(const Coil& coil) { this->primary = coil; }
    void setSecondary(const Coil& coil) { this->secondary = coil; }

    // Additional methods
    float getTurnsRatio() const;
    float getHighVoltageRatio() const;
    float getLowVoltageRatio() const;
    shp::Potential getSecondaryVoltage() const;
    virtual Transformer copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Transformer > TransformerArray;

} // namespace ecn

#endif //ECN_TRANSFORMER_H