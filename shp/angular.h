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

#ifndef SHP_ANGULAR_H
#define SHP_ANGULAR_H

#include "distance.h"

namespace shp {

class Angular : protected Distance {    // r - radial distance from the origin
    Polar polar;                        // 𝜃 - polar zenith angle from Y axis
    Azimuth azimuth;                    // 𝜙 - angle within the XY plane only
public:
    // Constructors
    Angular();
    Angular(const std::string unit);
    Angular(const Unit& unit);
    Angular(const float radius);
    Angular(const float radius, const std::string unit);
    Angular(const float radius, const Unit& unit);
    Angular(const float radius, const short int scaling);
    Angular(const float radius, const short int scaling, const std::string unit);
    Angular(const float radius, const short int scaling, const Unit& unit);
    Angular(const Distance& radius);
    Angular(const float radius, const float azimuth);
    Angular(const float radius, const float azimuth, const std::string unit);
    Angular(const float radius, const float azimuth, const Unit& unit);
    Angular(const float radius, const short int scaling, const float azimuth);
    Angular(const float radius, const short int scaling, const std::string unit, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit, const Azimuth& azimuth);
    Angular(const float radius, const short int scaling, const std::string unit, const Polar& polar);
    Angular(const float radius, const short int scaling, const Unit& unit, const Polar& polar);
    Angular(const float radius, const Azimuth& azimuth);
    Angular(const float radius, const short int scaling, const Azimuth& azimuth);
    Angular(const Distance& radius, const Azimuth& azimuth);
    Angular(const float radius, const Polar& polar);
    Angular(const float radius, const short int scaling, const Polar& polar);
    Angular(const Distance& radius, const Polar& polar);
    Angular(const float radius, const Polar& polar, const Azimuth& azimuth);
    Angular(const float radius, const short int scaling, const Polar& polar, const Azimuth& azimuth);
    Angular(const float radius, const float polar, const float azimuth);
    Angular(const float radius, const std::string unit, const float polar, const float azimuth);
    Angular(const float radius, const Unit& unit, const float polar, const float azimuth);
    Angular(const float radius, const Unit& unit, const Polar& polar, const Azimuth& azimuth);
    Angular(const float radius, const short int scaling, const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, const std::string unit,
        const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, const std::string unit,
        const Polar& polar, const Azimuth& azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit,
        const float polar, const float azimuth);
    Angular(const float radius, const short int scaling, const Unit& unit,
        const Polar& polar, const Azimuth& azimuth);
    Angular(const Azimuth& azimuth);
    Angular(const Polar& polar);
    Angular(const Polar& polar, const Azimuth& azimuth);
    Angular(const Distance& radius, const Polar& polar, const Azimuth& azimuth);

    // Destructors
    ~Angular();

    // Operator overloading
    bool operator==(const Angular& peer) const;
    bool operator<(const Angular& peer) const;
    bool operator>(const Angular& peer) const;
    bool operator<=(const Angular& peer) const;
    bool operator>=(const Angular& peer) const;
    Angular operator+(const Angular& peer) const;
    Angular operator-(const Angular& peer) const;
    Angular operator*(const Angular& peer) const;
    Angular operator/(const Angular& peer) const;
    Angular operator%(const Angular& peer) const;

    // Distance operator
    Distance operator+(const Distance& separation) const;
    Distance operator-(const Distance& separation) const;
    Distance operator*(const Distance& separation) const;
    Distance operator/(const Distance& separation) const;
    Distance operator%(const Distance& separation) const;

    // Azimuth operator
    Angular operator+(const Azimuth& rotation) const;
    Angular operator-(const Azimuth& rotation) const;
    Angular operator*(const Azimuth& rotation) const;
    Angular operator/(const Azimuth& rotation) const;
    Angular operator%(const Azimuth& rotation) const;

    // Polar operator
    Angular operator+(const Polar& rotation) const;
    Angular operator-(const Polar& rotation) const;
    Angular operator*(const Polar& rotation) const;
    Angular operator/(const Polar& rotation) const;
    Angular operator%(const Polar& rotation) const;

    // Access operator
    shp::Signal operator()(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal operator()(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    Direction getPolar() const { return polar; }
    Direction getAzimuth() const { return azimuth; }

    // Setters
    void setPolar(const Polar& angle) { this->polar = angle; }
    void setAzimuth(const Azimuth& angle) { this->azimuth = angle; }

    // Additional methods
    shp::Signal getLinearDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getAzimuthDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getAzimuthConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getAzimuthDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getPolarDisplacement(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getPolarConvergence(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getPolarDivergence(const Angular& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getLinearConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getLinearDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getAzimuthDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getAzimuthConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getAzimuthDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getPolarDisplacement(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getPolarConvergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getPolarDivergence(const Angular& peerX, const Angular& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Distance getRadius() const;
    void setRadius(const Distance& length);
    void setRadius(const float length);
    void setRadius(const float length, const short int scaling);
    void setRadius(const float length, const short int scaling, const std::string unit);
    void setRadius(const float length, const short int scaling, const Unit& unit);
    Direction getRadiusChange() const;
    void setRadiusChange(const Azimuth& orientation);
    Direction getDopplerShift() const;
    void setDopplerShift(const Polar& orientation);
    float getPolarCyclingRate() const;
    float getPolarTimePerCycle() const;
    Direction getPolarTangent() const;
    Direction getPolarRotation(const short int degree) const;
    void setPolarRotation(const short int degree);
    Direction getPolarChange() const;
    void setPolarChange(const Direction& orientation);
    float getPolarFraction(const Polar& peer) const;
    float getAzimuthCyclingRate() const;
    float getAzimuthTimePerCycle() const;
    Direction getAzimuthTangent() const;
    Direction getAzimuthRotation(const short int degree) const;
    void setAzimuthRotation(const short int degree);
    Direction getAzimuthChange() const;
    void setAzimuthChange(const Direction& orientation);
    float getAzimuthFraction(const Azimuth& peer) const;
    shp::Signal getRelative(const Distance& position) const;
    shp::Signal getLinearX(const Distance& position) const;
    shp::Signal getLinearXConvergence(const Distance& position) const;
    shp::Signal getLinearXDivergence(const Distance& position) const;
    shp::Signal getLinearY(const Distance& position) const;
    shp::Signal getLinearYConvergence(const Distance& position) const;
    shp::Signal getLinearYDivergence(const Distance& position) const;
    shp::Signal getLinearZ(const Distance& position) const;
    shp::Signal getLinearZConvergence(const Distance& position) const;
    shp::Signal getLinearZDivergence(const Distance& position) const;
    virtual Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printEuler() const;
public:
    static const float DEFAULT_RADIUS;
    static const float DEFAULT_POLARITY;
    static const float DEFAULT_AZIMUTHAL;
};

typedef std::vector<Angular > AngularArray;

} // namespace shp

#endif //SHP_ANGULAR_H