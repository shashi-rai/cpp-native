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

#ifndef QFT_COLOUR_H
#define QFT_COLOUR_H

#include <cmath>
#include <sstream>
#include <vector>
#include "../shp/quantity.h"

namespace qft {

class Colour {
    float charge;
public:
    // Constructors
    Colour();
    Colour(const float charge);

    // Destructors
    ~Colour();

    // Operator overloading
    bool operator==(const Colour& peer) const;
    Colour operator+(const Colour& peer) const;
    Colour operator-(const Colour& peer) const;
    Colour operator*(const Colour& peer) const;
    Colour operator/(const Colour& peer) const;
    Colour operator%(const Colour& peer) const;

    // Getters
    float getCharge() const { return charge; }

    // Setters
    void setCharge(const float amount) { this->charge = amount; }

    // Additional methods
    bool hasNoColour() const;
    virtual Colour copy();
    virtual void clear();
    virtual std::string print();

public:
    enum TYPE { RED, GREEN, BLUE, };
    static const float DEFAULT_VALUE;
};

typedef std::vector<Colour > ColourArray;

} // namespace qft

#endif //QFT_COLOUR_H