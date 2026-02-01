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

namespace shp {

/*
 * Divergent fields could be represented with Potential
 * Low ~ High retains a range for potential difference
 * A spatial representation exists in the Angular class
 */
class Potential : protected Signal {
    Signal kinetic;     // high value exists in the parent class
    Angular origin;     // spatial description of field potential
public:
    // Constructors
    Potential();
    Potential(const Angular& origin);
    Potential(const Polar& polar);
    Potential(const Polar& polar, const Azimuth& azimuth);
    Potential(const Distance& radius);
    Potential(const Distance& radius, const Polar& polar);
    Potential(const Distance& radius, const Azimuth& azimuth);
    Potential(const Distance& radius, const Polar& polar, const Azimuth& azimuth);
    Potential(const Azimuth& potential);
    Potential(const Azimuth& potential, const Angular& origin);
    Potential(const Azimuth& potential, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const Angular& origin, const Azimuth& kinetic);
    Potential(const float high);
    Potential(const float high, const Angular& origin);
    Potential(const float high, const Angular& origin, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const Angular& origin);
    Potential(const Azimuth& potential, const float high, const Angular& origin, const Azimuth& kinetic);
    Potential(const float high, const float low);
    Potential(const float high, const float low, const Angular& origin);
    Potential(const float high, const float low, const Angular& origin, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const float low, const Angular& origin);
    Potential(const Azimuth& potential, const float high, const float low, const Angular& origin, const Azimuth& kinetic);
    Potential(const std::string unit);
    Potential(const Unit& unit);
    Potential(const Unit& unit, const Angular& origin);
    Potential(const Azimuth& potential, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& potential, const Unit& unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const short int scaling, const std::string unit);
    Potential(const short int scaling, const Unit& unit);
    Potential(const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& potential, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& potential, const short int scaling, const Unit& unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const float high, const std::string unit, const Angular& origin);
    Potential(const float high, const std::string unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const std::string unit, const Angular& origin);
    Potential(const Azimuth& potential, const float high, const std::string unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const float high, const float low, const std::string unit);
    Potential(const float high, const float low, const std::string unit, const Angular& origin);
    Potential(const float high, const float low, const std::string unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const float low, const std::string unit, const Angular& origin);
    Potential(const Azimuth& potential, const float high, const float low, const std::string unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const float high, const float low, const Unit& unit);
    Potential(const float high, const float low, const Unit& unit, const Angular& origin);
    Potential(const float high, const float low, const Unit& unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const float low, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& potential, const float high, const float low, const Unit& unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const float high, const float low, const short int scaling);
    Potential(const float high, const float low, const short int scaling, const std::string unit);
    Potential(const float high, const float low, const short int scaling, const Unit& unit);
    Potential(const float potential, const float high, const float low, const short int scaling, const Unit& unit);
    Potential(const float potential, const float high, const float low, const short int scaling, const Unit& unit, const float kinetic);
    Potential(const float potential, const float high, const float low, const short int scaling, const Unit& unit, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const float low, const short int scaling, const Unit& unit);
    Potential(const Azimuth& potential, const float high, const float low, const short int scaling, const Unit& unit, const Azimuth& kinetic);
    Potential(const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const float potential, const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const float potential, const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin, const Azimuth& kinetic);
    Potential(const Azimuth& potential, const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin);
    Potential(const Azimuth& potential, const float high, const float low, const short int scaling, const Unit& unit, const Angular& origin, const Azimuth& kinetic);

    // Destructors
    ~Potential();

    // Operator overloading
    bool operator==(const Potential& peer) const;
    bool operator<(const Potential& peer) const;
    bool operator>(const Potential& peer) const;
    bool operator<=(const Potential& peer) const;
    bool operator>=(const Potential& peer) const;
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
    Signal getKinetic() const { return kinetic; }
    Angular getOrigin() const { return origin; }

    // Setters
    void setKinetic(const Signal& action) { this->kinetic = action; }
    void setOrigin(const Angular& position) { this->origin = position; }

    // Additional methods
    Signal getLinearPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getLinearConvergence(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getLinearDivergence(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getAzimuthPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getAzimuthConvergence(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getAzimuthDivergence(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getPolarPotential(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getPolarConvergence(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getPolarDivergence(const Potential& peer,
        const Distance& separation, const Distance& position) const;
    Signal getLinearPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getLinearConvergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getLinearDivergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getAzimuthPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getAzimuthConvergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getAzimuthDivergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getPolarPotential(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getPolarConvergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Signal getPolarDivergence(const Potential& peerX, const Potential& peerY,
        const Distance& separationX, const Distance& separationY) const;
    float getKineticAmplitude() const;
    float getLow() const;
    void setKinetic(const float value);
    void setKinetic(const float value, const short int scale);
    void setKinetic(const float value, const short int scale, const std::string unit);
    void setKinetic(const float value, const short int scale, const Unit& unit);
    short int getKineticScaling() const;
    void setKineticScaling(const short int factor);
    Unit getKineticUnit() const;
    void setKineticUnit(const Unit& object);
    float getPotentialAmplitude() const;
    float getHigh() const;
    float getPotential() const;
    void setPotential(const float value);
    void setPotential(const float value, const short int scale);
    void setPotential(const float value, const short int scale, const std::string unit);
    void setPotential(const float value, const short int scale, const Unit& unit);
    short int getPotentialScaling() const;
    void setPotentialScaling(const short int factor);
    Unit getPotentialUnit() const;
    void setPotentialUnit(const Unit& object);
    void setRange(const float high, const float low);
    void setRange(const float high, const float low, const short int scale);
    float getRadius() const;
    void setRadius(const float length);
    void setRadius(const float length, const short int scale);
    void setRadius(const float length, const short int scale, const std::string unit);
    void setRadius(const float length, const short int scale, const Unit& unit);
    Azimuth getKineticPhase() const;
    void setKineticPhase(const Azimuth& orientation);
    Azimuth getPotentialPhase() const;
    void setPotentialPhase(const Azimuth& orientation);
    Polar getPolarOrientation() const;
    void setPolarOrientation(const Polar& angle);
    Azimuth getAzimuthOrientation() const;
    void setAzimuthOrientation(const Azimuth& angle);
    Signal getDifference() const;
    Signal getDivergence() const;
    Signal getRelative(const Distance& location) const;
    Signal getRelativeX(const Distance& location) const;
    Signal getRelativeY(const Distance& location) const;
    Signal getRelativeZ(const Distance& location) const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
protected:
    Signal getSpreadActive() const;
};

typedef std::vector<Potential > PotentialArray;

} // namespace shp

#endif //SHP_POTENTIAL_H