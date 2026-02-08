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

class Medium : protected Distance { // spatial separation between two objects
    std::string name;
    shp::Signal transform;          // internal behavioural change controller
public:
    // Constructors
    Medium();
    Medium(const Unit& unit);
    Medium(const float parameter);
    Medium(const float parameter, const shp::Signal& transform);
    Medium(const float parameter, const std::string unit);
    Medium(const float parameter, const Unit& unit);
    Medium(const float parameter, const std::string unit, const shp::Signal& transform);
    Medium(const float parameter, const Unit& unit, const shp::Signal& transform);
    Medium(const float parameter, const short int scaling);
    Medium(const float parameter, const short int scaling, const shp::Signal& transform);
    Medium(const float parameter, const short int scaling, const std::string unit);
    Medium(const float parameter, const short int scaling, const Unit& unit);
    Medium(const float parameter, const short int scaling, const std::string unit, const shp::Signal& transform);
    Medium(const float parameter, const short int scaling, const Unit& unit, const shp::Signal& transform);
    Medium(const Distance& parameter);
    Medium(const float parameter, const float density);
    Medium(const float parameter, const std::string unit, const float density);
    Medium(const float parameter, const std::string unit, const Intrinsic& density);
    Medium(const float parameter, const Unit& unit, const float density);
    Medium(const float parameter, const Unit& unit, const Intrinsic& density);
    Medium(const float parameter, const short int scaling, const float density);
    Medium(const float parameter, const short int scaling, const Intrinsic& density);
    Medium(const float parameter, const short int scaling, const std::string unit, const float density);
    Medium(const float parameter, const short int scaling, const std::string unit, const Intrinsic& density);
    Medium(const float parameter, const short int scaling, const Unit& unit, const float density);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Intrinsic& density);
    Medium(const float parameter, const short int scaling, const std::string unit, const Azimuth& current);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Azimuth& current);
    Medium(const float parameter, const short int scaling, const std::string unit, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Intrinsic& density, const Azimuth& current);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Intrinsic& density, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Unit& unit, const Intrinsic& density, const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const Intrinsic& density);
    Medium(const float parameter, const Azimuth& current);
    Medium(const float parameter, const Polar& threshold);
    Medium(const float parameter, const Intrinsic& density, const Azimuth& current);
    Medium(const float parameter, const Intrinsic& density, const Polar& threshold);
    Medium(const float parameter, const Intrinsic& density, const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const std::string unit, const Azimuth& current);
    Medium(const float parameter, const Unit& unit, const Azimuth& current);
    Medium(const float parameter, const std::string unit, const Polar& threshold);
    Medium(const float parameter, const Unit& unit, const Polar& threshold);
    Medium(const float parameter, const std::string unit, const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const Unit& unit, const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const std::string unit, const Intrinsic& density, const Azimuth& current);
    Medium(const float parameter, const Unit& unit, const Intrinsic& density, const Azimuth& current);
    Medium(const float parameter, const std::string unit, const Intrinsic& density, const Polar& threshold);
    Medium(const float parameter, const Unit& unit, const Intrinsic& density, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Azimuth& current);
    Medium(const float parameter, const short int scaling, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Azimuth& current,
        const Polar& threshold);
    Medium(const float parameter, const short int scaling, const Intrinsic& density,
        const Azimuth& current);
    Medium(const float parameter, const short int scaling, const Intrinsic& density,
        const Polar& threshold);
    Medium(const float parameter, const short int scaling, const std::string unit,
        const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Azimuth& current);
    Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold);
    Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold,
        const shp::Signal& transform);
    Medium(const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold,
        const shp::Signal& transform);
    Medium(const shp::Signal& transform);
    Medium(const std::string name);
    Medium(const std::string name, const shp::Signal& transform);
    Medium(const std::string name, const std::string unit);
    Medium(const std::string name, const Unit& unit);
    Medium(const std::string name, const std::string unit, const shp::Signal& transform);
    Medium(const std::string name, const Unit& unit, const shp::Signal& transform);
    Medium(const std::string name, const float parameter, const shp::Signal& transform);
    Medium(const std::string name, const float parameter, const short int scaling);
    Medium(const std::string name, const float parameter, const short int scaling,
        const shp::Signal& transform);
    Medium(const std::string name, const float parameter, const short int scaling, const std::string unit);
    Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit);
    Medium(const std::string name, const float parameter, const short int scaling, const std::string unit,
        const shp::Signal& transform);
    Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit,
        const shp::Signal& transform);
    Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold,
        const shp::Signal& transform);
    Medium(const Intrinsic& density);
    Medium(const Azimuth& current);
    Medium(const Polar& threshold);
    Medium(const Intrinsic& density, const Azimuth& current);
    Medium(const Intrinsic& density, const Polar& threshold);
    Medium(const Intrinsic& density, const Azimuth& current, const Polar& threshold);

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

    // Parameter operator
    Medium operator+(const Distance& parameter) const;
    Medium operator-(const Distance& parameter) const;
    Medium operator*(const Distance& parameter) const;
    Medium operator/(const Distance& parameter) const;
    Medium operator%(const Distance& parameter) const;

    // Concentration operator
    Medium operator+(const Intrinsic& phase) const;
    Medium operator-(const Intrinsic& phase) const;
    Medium operator*(const Intrinsic& phase) const;
    Medium operator/(const Intrinsic& phase) const;
    Medium operator%(const Intrinsic& phase) const;

    // Threshold operator
    Medium operator+(const Polar& threshold) const;
    Medium operator-(const Polar& threshold) const;
    Medium operator*(const Polar& threshold) const;
    Medium operator/(const Polar& threshold) const;
    Medium operator%(const Polar& threshold) const;

    // Behavioral Property operator
    Medium operator+(const shp::Signal& modulation) const;
    Medium operator-(const shp::Signal& modulation) const;
    Medium operator*(const shp::Signal& modulation) const;
    Medium operator/(const shp::Signal& modulation) const;
    Medium operator%(const shp::Signal& modulation) const;

    // Access operator
    shp::Signal operator()(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal operator()(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;

    // Getters
    std::string getName() const { return name; }
    shp::Signal getTransform() const { return transform; }

    // Setters
    void setName(const std::string name) { this->name = name; }
    void setTransform(const shp::Signal& modulation) { this->transform = modulation; }

    // Additional methods
    shp::Signal getLinearDiffusion(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getIntensifiedDiffusion(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getIntensifiedConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getIntensifiedDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getThresholdDiffusion(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getThresholdConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getThresholdDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const;
    shp::Signal getLinearDiffusion(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getLinearConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getLinearDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getIntensifiedDiffusion(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getIntensifiedConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getIntensifiedDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getThresholdDiffusion(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getThresholdConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    shp::Signal getThresholdDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const;
    Distance getParameter() const;
    void setParameter(const Distance& value);
    void setParameter(const float value);
    void setParameter(const float value, const short int scaling);
    void setParameter(const float value, const short int scaling, const std::string unit);
    void setParameter(const float value, const short int scaling, const Unit& unit);
    Direction getDiffusionCurrent() const;
    void setDiffusionFactor(const float degree);
    void setDiffusionFactor(const Intrinsic& phase);
    Direction getThresholdCurrent() const;
    Direction getThresholdShift() const;
    void setThresholdShift(const float degree);
    void setThresholdShift(const Polar& threshold);
    float getThresholdCyclingRate() const;
    float getThresholdTimePerCycle() const;
    float getThresholdFraction(const Polar& peer) const;
    float getDiffusionCyclingRate() const;
    float getDiffusionTimePerCycle() const;
    Direction getDiffusionShift() const;
    void setDiffusionShift(const short int degree);
    float getDiffusionFraction(const Intrinsic& peer) const;
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
    shp::Signal getScalarParameter() const;
    shp::Signal getVectorParameter() const;
    shp::Signal getScalarFieldDrift() const;
    shp::Signal getScalarFieldTotal() const;
    shp::Signal getVectorFieldDrift() const;
    shp::Signal getVectorFieldTotal() const;
    virtual shp::Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Medium > MediumArray;

} // namespace shp

#endif //SHP_MEDIUM_H