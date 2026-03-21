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

#ifndef CON_INTENTION_H
#define CON_INTENTION_H

#include "pattern.h"
#include "../shp/distance.h"

namespace con {

class Intention : protected shp::Distance {
    std::shared_ptr<Pattern> training;
    std::string name;
public:
    // Constructors
    Intention();
    Intention(const std::shared_ptr<Pattern> context);
    Intention(const std::string name);
    Intention(const std::string name, const std::shared_ptr<Pattern> context);
    Intention(const shp::Unit& unit);
    Intention(const shp::Unit& unit, const std::shared_ptr<Pattern> context);
    Intention(const shp::Intrinsic& bias);
    Intention(const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment);
    Intention(const float commitment, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const std::string unit);
    Intention(const float commitment, const std::string unit,
        const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const shp::Unit& unit);
    Intention(const float commitment, const shp::Unit& unit,
        const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling);
    Intention(const float commitment, const float bias);
    Intention(const float commitment, const float bias,
        const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const shp::Intrinsic& bias);
    Intention(const float commitment, const shp::Intrinsic& bias,
        const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const std::string unit,
        const float bias);
    Intention(const float commitment, const std::string unit,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const std::string unit,
        const shp::Intrinsic& bias);
    Intention(const float commitment, const std::string unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const shp::Unit& unit,
        const shp::Intrinsic& bias);
    Intention(const float commitment, const shp::Unit& unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling, const std::string unit);
    Intention(const float commitment, const short int scaling, const std::string unit,
        const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling, const shp::Unit& unit);
    Intention(const float commitment, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling,
        const float bias);
    Intention(const float commitment, const short int scaling,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling,
        const shp::Intrinsic& bias);
    Intention(const float commitment, const short int scaling,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling, const std::string unit,
        const float bias);
    Intention(const float commitment, const short int scaling, const std::string unit,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const float commitment, const short int scaling, const std::string unit,
        const shp::Intrinsic& bias);
    Intention(const float commitment, const short int scaling, const std::string unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const std::string unit);
    Intention(const std::string name, const std::string unit, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const shp::Unit& unit);
    Intention(const std::string name, const shp::Unit& unit, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const shp::Intrinsic& bias);
    Intention(const std::string name,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment);
    Intention(const std::string name, const float commitment,
        const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const std::string unit);
    Intention(const std::string name, const float commitment, const std::string unit,
        const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const shp::Unit& unit);
    Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const short int scaling);
    Intention(const std::string name, const float commitment, const short int scaling,
        const std::string unit);
    Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Unit& unit);
    Intention(const std::string name, const float commitment, const float bias);
    Intention(const std::string name, const float commitment,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment,
        const shp::Intrinsic& bias);
    Intention(const std::string name, const float commitment,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const std::string unit,
        const float bias);
    Intention(const std::string name, const float commitment, const std::string unit,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const float bias);
    Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const shp::Intrinsic& bias);
    Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const short int scaling,
        const float bias);
    Intention(const std::string name, const float commitment, const short int scaling,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Intrinsic& bias);
    Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const short int scaling, const std::string unit,
        const float bias);
    Intention(const std::string name, const float commitment, const short int scaling, const std::string unit,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const short int scaling, const shp::Unit& unit,
        const float bias);
    Intention(const std::string name, const float commitment, const short int scaling, const shp::Unit& unit,
        const float bias, const std::shared_ptr<Pattern> context);
    Intention(const std::string name, const float commitment, const short int scaling, const shp::Unit& unit,
        const shp::Intrinsic& bias);
    Intention(const std::string name, const float commitment, const short int scaling, const shp::Unit& unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context);

    // Destructors
    ~Intention();

    // Operator overloading
    bool operator==(const Intention& peer) const;
    bool operator<(const Intention& peer) const;
    bool operator>(const Intention& peer) const;
    bool operator<=(const Intention& peer) const;
    bool operator>=(const Intention& peer) const;
    Intention operator+(const Intention& peer) const;
    Intention operator-(const Intention& peer) const;
    Intention operator*(const Intention& peer) const;
    Intention operator/(const Intention& peer) const;
    Intention operator%(const Intention& peer) const;

    // Scalar Commitment operator
    Intention operator+(const float influence) const;
    Intention operator-(const float influence) const;
    Intention operator*(const float influence) const;
    Intention operator/(const float influence) const;
    Intention operator%(const float influence) const;

    // Scalar Commitment operator
    Intention operator+(const shp::Quantity& influence) const;
    Intention operator-(const shp::Quantity& influence) const;
    Intention operator*(const shp::Quantity& influence) const;
    Intention operator/(const shp::Quantity& influence) const;
    Intention operator%(const shp::Quantity& influence) const;

    // Commitment Vector operator
    Intention operator+(const shp::Distance& influence) const;
    Intention operator-(const shp::Distance& influence) const;
    Intention operator*(const shp::Distance& influence) const;
    Intention operator/(const shp::Distance& influence) const;
    Intention operator%(const shp::Distance& influence) const;

    // Commitment Bias operator
    Intention operator+(const shp::Intrinsic& bias) const;
    Intention operator-(const shp::Intrinsic& bias) const;
    Intention operator*(const shp::Intrinsic& bias) const;
    Intention operator/(const shp::Intrinsic& bias) const;
    Intention operator%(const shp::Intrinsic& bias) const;

    // Commitment Saturation operator
    Intention operator+(const shp::Polar& fatigue) const;
    Intention operator-(const shp::Polar& fatigue) const;
    Intention operator*(const shp::Polar& fatigue) const;
    Intention operator/(const shp::Polar& fatigue) const;
    Intention operator%(const shp::Polar& fatigue) const;

    // Getters
    std::shared_ptr<Pattern> getTraining() const { return training; }
    std::string getName() const { return name; }

    // Setters
    void setTraining(const std::shared_ptr<Pattern> context) { this->training = context; }
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    shp::Distance getCommitment() const;
    void setCommitment(const shp::Quantity& desire, const shp::Intrinsic& bias);
    void setCommitment(const shp::Quantity& desire, const shp::Azimuth& clarity);
    void setCommitment(const shp::Quantity& desire, const shp::Polar& trust);
    void setCommitment(const shp::Distance& objective);
    void setCommitment(const float desire);
    void setCommitment(const float desire, const short int scale);
    void setCommitment(const float desire, const short int scale, const std::string unit);
    void setCommitment(const float desire, const short int scale, const shp::Unit& unit);
    short int getScaling() const;
    void setScaling(const short int factor);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& unit);
    shp::Intrinsic getBias() const;
    void setBias(const float intensity);
    void setBias(const shp::Intrinsic& intensity);
    void setChangeBias(const float degree);
    shp::Azimuth getClarityThought() const;
    void setClarityThought(const float deviation);
    void setClarityThought(const shp::Azimuth& deviation);
    void setChangeClarityThought(const float degree);
    void setChangeClarityShiftRate(const float degree);
    shp::Polar getTrustSaturation() const;
    void setTrustSaturation(const float fatigue);
    void setTrustSaturation(const shp::Polar& fatigue);
    void setChangeTrustSaturation(const float degree);
    void setChangeTrustShiftRate(const float degree);
    void setChangeCommitment(const float drift);
    void setChangeCommitment(const float drift, const short int scale);
    shp::Signal getAttitude() const;
    virtual shp::Signal getTrusted();
    virtual shp::Signal getTrusted(const Pattern& awareness);
    virtual shp::Signal getInfluenced();
    virtual shp::Signal getInfluenced(const shp::Direction& promotion);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    shp::Signal getScalarNegative() const;
    shp::Signal getVectorNegative() const;
    shp::Signal getScalarInverse() const;
    shp::Signal getVectorInverse() const;
    shp::Signal getScalarSquare() const;
    shp::Signal getVectorSquare() const;
    shp::Signal getScalarFraction(const float desire) const;
    shp::Signal getScalarFraction(const float desire, const short int scale) const;
    shp::Signal getScalarSquareFraction(const float desire) const;
    shp::Signal getScalarSquareFraction(const float desire, const short int scale) const;
    bool isTrained() const;
    virtual shp::Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printTraining() const;
    virtual std::string printRadians() const;
    virtual std::string printTrainingRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
    shp::Direction getBiasMoment(const Pattern& awareness) const;
    shp::Direction getClarityMoment(const Pattern& awareness) const;
    shp::Direction getTrustMoment(const Pattern& awareness) const;
protected:
    shp::Direction getBiasShiftRate() const;
    shp::Direction getClarityShiftRate() const;
    shp::Direction getTrustShiftRate() const;
    std::complex<float> toComplex(const float coefficient, const float change);
public:
    static const std::string UNIT;
};

typedef std::vector<Intention > IntentionArray;

} // namespace con

#endif //CON_INTENTION_H