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

#ifndef ECN_RELUCTANCE_H
#define ECN_RELUCTANCE_H

#include <sstream>
#include <string>
#include <vector>
#include "../shp/potential.h"

namespace ecn {

class Reluctance : public shp::Quantity {
    shp::Potential threshold;
public:
    // Constructors
    Reluctance();
    Reluctance(const shp::Potential& threshold);
    Reluctance(const float magnitude);
    Reluctance(const short int scaling);
    Reluctance(const std::string unit);
    Reluctance(const short int scaling, const std::string unit);
    Reluctance(const shp::Unit& unit);
    Reluctance(const short int scaling, const shp::Unit& unit);
    Reluctance(const float magnitude, const std::string unit);
    Reluctance(const float magnitude, const shp::Unit& unit);
    Reluctance(const float magnitude, const short int scaling);
    Reluctance(const float magnitude, const short int scaling, const std::string unit);
    Reluctance(const float magnitude, const short int scaling, const shp::Unit& unit);
    Reluctance(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Potential& threshold);

    // Destructors
    ~Reluctance();

    // Operator overloading
    bool operator==(const Reluctance& peer) const;
    Reluctance operator+(const Reluctance& peer) const;
    Reluctance operator-(const Reluctance& peer) const;
    Reluctance operator*(const Reluctance& peer) const;
    Reluctance operator/(const Reluctance& peer) const;
    Reluctance operator%(const Reluctance& peer) const;

    // Getters
    shp::Potential getThreshold() const { return threshold; }

    // Setters
    void setThreshold(const shp::Potential& range) { this->threshold = range; }

    // Additional methods
    Reluctance copy();
    virtual void clear();
    virtual std::string print();
public:
    static const std::string UNIT;
};

typedef std::vector<Reluctance > ReluctanceArray;

} // namespace ecn

#endif //ECN_RELUCTANCE_H