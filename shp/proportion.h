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

#ifndef SHP_PROPORTION_H
#define SHP_PROPORTION_H

#include <sstream>
#include <string>
#include <vector>
#include "quantity.h"

namespace shp {

class Proportion {
    Quantity numerator;
    Quantity denominator;
public:
    // Constructors
    Proportion();
    Proportion(const Quantity& numerator);
    Proportion(const float numerator);
    Proportion(const float numerator, short int scaling);
    Proportion(const float numerator, short int scaling, std::string unit);
    Proportion(const float numerator, short int scaling, const Unit& unit);
    Proportion(const Quantity& numerator, const Quantity& denominator);
    Proportion(const float numerator, const float denominator);
    Proportion(const float numerator, const float denominator, short int scaling);
    Proportion(const float numerator, const float denominator, short int scaling, std::string unit);
    Proportion(const float numerator, const float denominator, short int scaling, const Unit& unit);

    // Destructors
    ~Proportion();

    // Operator overloading
    bool operator==(const Proportion& peer) const;
    Proportion operator+(const Proportion& peer) const;
    Proportion operator-(const Proportion& peer) const;
    Proportion operator*(const Proportion& peer) const;
    Proportion operator/(const Proportion& peer) const;
    Proportion operator%(const Proportion& peer) const;

    // Getters
    Quantity getNumerator() const { return numerator; }
    Quantity getDenominator() const { return denominator; }

    // Setters
    void setNumerator(const Quantity& property) { this->numerator = property; }
    void setDenominator(const Quantity& property) { this->denominator = property; }

    // Additional methods
    Quantity getRatio() const;
    virtual Proportion copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Proportion > ProportionArray;

} // namespace shp

#endif //SHP_PROPORTION_H