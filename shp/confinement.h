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

#ifndef SHP_CONFINEMENT_H
#define SHP_CONFINEMENT_H

#include <cmath>
#include <sstream>
#include <vector>
#include "potential.h"

namespace shp {

class Confinement : protected Potential {

public:
    // Constructors
    Confinement();
    Confinement(const Angular& closure);
    Confinement(const float high);
    Confinement(const float high, const Angular& closure);
    Confinement(const float high, const float low);
    Confinement(const float high, const float low, const Angular& closure);
    Confinement(const std::string unit);
    Confinement(const Unit& unit);
    Confinement(const Unit& unit, const Angular& closure);
    Confinement(const short int scaling, const std::string unit);
    Confinement(const short int scaling, const Unit& unit);
    Confinement(const short int scaling, const Unit& unit, const Angular& closure);
    Confinement(const float high, const std::string unit, const Angular& closure);
    Confinement(const float high, const float low, const std::string unit);
    Confinement(const float high, const float low, const std::string unit, const Angular& closure);
    Confinement(const float high, const float low, const Unit& unit);
    Confinement(const float high, const float low, const Unit& unit, const Angular& closure);
    Confinement(const float high, const float low, const short int scaling);
    Confinement(const float high, const float low, const short int scaling, const std::string unit);
    Confinement(const float high, const float low, const short int scaling, const Unit& unit);
    Confinement(const float high, const float low, const short int scaling, const Unit& unit, const Angular& closure);

    // Destructors
    ~Confinement();

    // Operator overloading
    bool operator==(const Confinement& peer) const;
    Confinement operator+(const Confinement& peer) const;
    Confinement operator-(const Confinement& peer) const;
    Confinement operator*(const Confinement& peer) const;
    Confinement operator/(const Confinement& peer) const;
    Confinement operator%(const Confinement& peer) const;

    // Access operator
    Quantity operator()(const Confinement& peer,
        const Distance& separation, const Distance& position) const;
    Quantity operator()(const Confinement& peerX, const Confinement& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    float getHigh() const { return this->getHigh(); }
    float getLow() const { return this->getLow(); }
    Angular getClosure() const { return this->getOrigin(); }

    // Setters
    void setHigh(const float value) { this->setHigh(value); }
    void setLow(const float value) { this->setLow(value); }
    void setClosure(const Angular& position) { this->setOrigin(position); }

    // Additional methods
    Direction getPolar() const;
    void setPolar(const Direction& angle);
    Direction getAzimuthal() const;
    void setAzimuthal(const Direction& angle);
    Quantity getDifference() const;
    Quantity getRelative(const Distance& location, const float angle) const;
    Quantity getPolarComponent(const Distance& location) const;
    Quantity getAzimuthalComponent(const Distance& location) const;
    Confinement copy();
    void clear();
    std::string print();
};

typedef std::vector<Confinement > ConfinementArray;

} // namespace shp

#endif //SHP_CONFINEMENT_H