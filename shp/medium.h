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

#ifndef SHP_MEDIUM_H
#define SHP_MEDIUM_H

#include "distance.h"

namespace shp {

class Medium : protected Distance {     // spatial separation between two object
    std::string name;
public:
    // Constructors
    Medium();
    Medium(const std::string unit);
    Medium(const Unit& unit);
    Medium(const float separation);
    Medium(const float separation, const std::string unit);
    Medium(const float separation, const Unit& unit);
    Medium(const float separation, const short int scaling);
    Medium(const float separation, const short int scaling, const std::string unit);
    Medium(const float separation, const short int scaling, const Unit& unit);
    Medium(const Distance& separation);
    Medium(const float separation, const float orientation);
    Medium(const float separation, const std::string unit, const float orientation);
    Medium(const float separation, const std::string unit, const Azimuth& orientation);
    Medium(const float separation, const Unit& unit, const float orientation);
    Medium(const float separation, const Unit& unit, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const float orientation);
    Medium(const float separation, const short int scaling, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const std::string unit, const float orientation);
    Medium(const float separation, const short int scaling, const std::string unit, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const Unit& unit, const float orientation);
    Medium(const float separation, const short int scaling, const Unit& unit, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const std::string unit, const Polar& threshold);
    Medium(const float separation, const short int scaling, const Unit& unit, const Polar& threshold);
    Medium(const float separation, const Azimuth& orientation);
    Medium(const float separation, const Polar& threshold);
    Medium(const float separation, const Polar& threshold, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const Polar& threshold);
    Medium(const float separation, const short int scaling, const Polar& threshold, const Azimuth& orientation);
    Medium(const float separation, const float threshold, const float orientation);
    Medium(const float separation, const std::string unit, const float threshold, const float orientation);
    Medium(const float separation, const Unit& unit, const float threshold, const float orientation);
    Medium(const float separation, const Unit& unit, const Polar& threshold, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const float threshold, const float orientation);
    Medium(const float separation, const short int scaling, const std::string unit,
        const float threshold, const float orientation);
    Medium(const float separation, const short int scaling, const std::string unit,
        const Polar& threshold, const Azimuth& orientation);
    Medium(const float separation, const short int scaling, const Unit& unit,
        const float threshold, const float orientation);
    Medium(const float separation, const short int scaling, const Unit& unit,
        const Polar& threshold, const Azimuth& orientation);
    Medium(const Azimuth& orientation);
    Medium(const Polar& threshold);
    Medium(const Polar& threshold, const Azimuth& orientation);

    // Destructors
    ~Medium();

    // Operator overloading
    bool operator==(const Medium& peer) const;
    bool operator<(const Medium& peer) const;
    bool operator>(const Medium& peer) const;
    bool operator<=(const Medium& peer) const;
    bool operator>=(const Medium& peer) const;
    Medium operator+(const Medium& peer) const;
    Medium operator-(const Medium& peer) const;
    Medium operator*(const Medium& peer) const;
    Medium operator/(const Medium& peer) const;
    Medium operator%(const Medium& peer) const;

    // Distance operator
    Medium operator+(const Distance& separation) const;
    Medium operator-(const Distance& separation) const;
    Medium operator*(const Distance& separation) const;
    Medium operator/(const Distance& separation) const;
    Medium operator%(const Distance& separation) const;

    // Separation operator
    Medium operator+(const Azimuth& orientation) const;
    Medium operator-(const Azimuth& orientation) const;
    Medium operator*(const Azimuth& orientation) const;
    Medium operator/(const Azimuth& orientation) const;
    Medium operator%(const Azimuth& orientation) const;

    // Threshold operator
    Medium operator+(const Polar& threshold) const;
    Medium operator-(const Polar& threshold) const;
    Medium operator*(const Polar& threshold) const;
    Medium operator/(const Polar& threshold) const;
    Medium operator%(const Polar& threshold) const;

    // Access operator
    shp::Signal operator()(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal operator()(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    std::string getName() const { return name; }

    // Setters
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    shp::Signal getLinearDisplacement(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getSeparationDisplacement(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getSeparationConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getSeparationDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getThresholdDisplacement(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getThresholdConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getThresholdDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearDisplacement(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getLinearConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getLinearDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getSeparationDisplacement(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getSeparationConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getSeparationDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getThresholdDisplacement(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getThresholdConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getThresholdDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Distance getSeparation() const;
    void setSeparation(const Distance& length);
    void setSeparation(const float length);
    void setSeparation(const float length, const short int scaling);
    void setSeparation(const float length, const short int scaling, const std::string unit);
    void setSeparation(const float length, const short int scaling, const Unit& unit);
    Direction getStressFactor() const;
    void setStressFactor(const float orientation);
    void setStressFactor(const Azimuth& orientation);
    Direction getThresholdShift() const;
    void setThresholdShift(const float threshold);
    void setThresholdShift(const Polar& threshold);
    float getThresholdCyclingRate() const;
    float getThresholdTimePerCycle() const;
    Direction getThresholdTangent() const;
    Direction getThresholdRotation(const short int degree) const;
    void setThresholdRotation(const short int degree);
    Direction getThresholdChange() const;
    void setThresholdChange(const Direction& orientation);
    float getThresholdFraction(const Polar& peer) const;
    float getSeparationCyclingRate() const;
    float getSeparationTimePerCycle() const;
    Direction getSeparationTangent() const;
    Direction getSeparationRotation(const short int degree) const;
    void setSeparationRotation(const short int degree);
    Direction getSeparationChange() const;
    void setSeparationChange(const Direction& orientation);
    float getSeparationFraction(const Azimuth& peer) const;
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
};

typedef std::vector<Medium > MediumArray;

} // namespace shp

#endif //SHP_MEDIUM_H