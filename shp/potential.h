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

#ifndef SHP_POTENTIAL_H
#define SHP_POTENTIAL_H

#include "angular.h"
#include "signal.h"

namespace shp {

/*
 * Divergent fields could be represented with Potential
 */
class Potential : protected Signal {
    float low;
    Angular origin;
public:
    // Constructors
    Potential();
    Potential(const Azimuth& phase);
    Potential(const Angular& origin);
    Potential(const Azimuth& phase, const Angular& origin);
    Potential(const float high);
    Potential(const float high, const Angular& origin);
    Potential(const Azimuth& phase, const float high, const Angular& origin);
    Potential(const float high, const float low);
    Potential(const float high, const float low, const Angular& origin);
    Potential(const Azimuth& phase, const float high, const float low, const Angular& origin);
    Potential(const std::string unit);
    Potential(const Unit& unit);
    Potential(const Unit& unit, const Angular& origin);
    Potential(const Azimuth& phase, const Unit& unit, const Angular& origin);
    Potential(const short int scaling, const std::string unit);
    Potential(const short int scaling, const Unit& unit);
    Potential(const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& phase, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const float high, const std::string unit, const Angular& origin);
    Potential(const Azimuth& phase, const float high, const std::string unit, const Angular& origin);
    Potential(const float high, const float low, const std::string unit);
    Potential(const float high, const float low, const std::string unit, const Angular& origin);
    Potential(const Azimuth& phase, const float high, const float low, const std::string unit, const Angular& origin);
    Potential(const float high, const float low, const Unit& unit);
    Potential(const float high, const float low, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& phase, const float high, const float low, const Unit& unit, const Angular& origin);
    Potential(const float high, const float low, const short int scaling);
    Potential(const float high, const float low, const short int scaling, const std::string unit);
    Potential(const float high, const float low, const short int scaling, const Unit& unit);
    Potential(const float phase, const float high, const float low, const short int scaling, const Unit& unit);
    Potential(const Azimuth& phase, const float high, const float low, const short int scaling, const Unit& unit);
    Potential(const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const float phase, const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& phase, const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin);

    // Destructors
    ~Potential();

    // Operator overloading
    bool operator==(const Potential& peer) const;
    Potential operator+(const Potential& peer) const;
    Potential operator-(const Potential& peer) const;
    Potential operator*(const Potential& peer) const;
    Potential operator/(const Potential& peer) const;
    Potential operator%(const Potential& peer) const;

    // Access operator
    Signal operator()(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal operator()(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    float getLow() const { return low; }
    Angular getOrigin() const { return origin; }

    // Setters
    void setLow(const float value) { this->low = value; }
    void setOrigin(const Angular& position) { this->origin = position; }

    // Additional methods
    Signal getLinearDisplacement(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getAngularDisplacement(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getLinearDisplacement(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getAngularDisplacement(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    float getHigh() const;
    void setHigh(const float value);
    void setRange(const float high, const float low);
    void setRange(const float high, const float low, const short int scale);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    Polar getPolar() const;
    void setPolar(const Polar& angle);
    Azimuth getAzimuth() const;
    void setAzimuth(const Azimuth& angle);
    Signal getDifference() const;
    Signal getDivergence() const;
    Signal getRelative(const Distance& location, const float angle) const;
    Signal getRelativeX(const Distance& location, const float angle) const;
    Signal getRelativeY(const Distance& location, const float angle) const;
    Signal getPolarRComponent(const Distance& location) const;
    Signal getPolarXComponent(const Distance& location) const;
    Signal getPolarZComponent(const Distance& location) const;
    Signal getAzimuthRComponent(const Distance& location) const;
    Signal getAzimuthXComponent(const Distance& location) const;
    Signal getAzimuthYComponent(const Distance& location) const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
};

typedef std::vector<Potential > PotentialArray;

} // namespace shp

#endif //SHP_POTENTIAL_H