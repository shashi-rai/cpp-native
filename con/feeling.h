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

#ifndef CON_FEELING_H
#define CON_FEELING_H

#include "behaviour.h"
#include "../shp/distance.h"

namespace con {

class Feeling : protected shp::Distance {
    std::shared_ptr<Behaviour> behaviour;
    std::string name;
public:
    // Constructors
    Feeling();
    Feeling(const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name);
    Feeling(const std::string name, const std::shared_ptr<Behaviour> realm);
    Feeling(const shp::Unit& unit);
    Feeling(const shp::Unit& unit, const std::shared_ptr<Behaviour> realm);
    Feeling(const shp::Intrinsic& direction);
    Feeling(const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse);
    Feeling(const float impulse, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const std::string unit);
    Feeling(const float impulse, const std::string unit,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const shp::Unit& unit);
    Feeling(const float impulse, const shp::Unit& unit,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling);
    Feeling(const float impulse, const float direction);
    Feeling(const float impulse, const float direction,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const shp::Intrinsic& direction);
    Feeling(const float impulse, const shp::Intrinsic& direction,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const std::string unit,
        const float direction);
    Feeling(const float impulse, const std::string unit,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const std::string unit,
        const shp::Intrinsic& direction);
    Feeling(const float impulse, const std::string unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const shp::Unit& unit,
        const shp::Intrinsic& direction);
    Feeling(const float impulse, const shp::Unit& unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling, const std::string unit);
    Feeling(const float impulse, const short int scaling, const std::string unit,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling, const shp::Unit& unit);
    Feeling(const float impulse, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling,
        const float direction);
    Feeling(const float impulse, const short int scaling,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling,
        const shp::Intrinsic& direction);
    Feeling(const float impulse, const short int scaling,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling, const std::string unit,
        const float direction);
    Feeling(const float impulse, const short int scaling, const std::string unit,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const float impulse, const short int scaling, const std::string unit,
        const shp::Intrinsic& direction);
    Feeling(const float impulse, const short int scaling, const std::string unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const std::string unit);
    Feeling(const std::string name, const std::string unit, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const shp::Unit& unit);
    Feeling(const std::string name, const shp::Unit& unit, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const shp::Intrinsic& direction);
    Feeling(const std::string name,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse);
    Feeling(const std::string name, const float impulse,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const std::string unit);
    Feeling(const std::string name, const float impulse, const std::string unit,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const shp::Unit& unit);
    Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const short int scaling);
    Feeling(const std::string name, const float impulse, const short int scaling,
        const std::string unit);
    Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Unit& unit);
    Feeling(const std::string name, const float impulse, const float direction);
    Feeling(const std::string name, const float impulse,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse,
        const shp::Intrinsic& direction);
    Feeling(const std::string name, const float impulse,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const std::string unit,
        const float direction);
    Feeling(const std::string name, const float impulse, const std::string unit,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const float direction);
    Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const shp::Intrinsic& direction);
    Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const short int scaling,
        const float direction);
    Feeling(const std::string name, const float impulse, const short int scaling,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Intrinsic& direction);
    Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const short int scaling, const std::string unit,
        const float direction);
    Feeling(const std::string name, const float impulse, const short int scaling, const std::string unit,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const short int scaling, const shp::Unit& unit,
        const float direction);
    Feeling(const std::string name, const float impulse, const short int scaling, const shp::Unit& unit,
        const float direction, const std::shared_ptr<Behaviour> realm);
    Feeling(const std::string name, const float impulse, const short int scaling, const shp::Unit& unit,
        const shp::Intrinsic& direction);
    Feeling(const std::string name, const float impulse, const short int scaling, const shp::Unit& unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm);

    // Destructors
    ~Feeling();

    // Operator overloading
    bool operator==(const Feeling& peer) const;
    bool operator<(const Feeling& peer) const;
    bool operator>(const Feeling& peer) const;
    bool operator<=(const Feeling& peer) const;
    bool operator>=(const Feeling& peer) const;
    Feeling operator+(const Feeling& peer) const;
    Feeling operator-(const Feeling& peer) const;
    Feeling operator*(const Feeling& peer) const;
    Feeling operator/(const Feeling& peer) const;
    Feeling operator%(const Feeling& peer) const;

    // Scalar Emotions operator
    Feeling operator+(const float emotion) const;
    Feeling operator-(const float emotion) const;
    Feeling operator*(const float emotion) const;
    Feeling operator/(const float emotion) const;
    Feeling operator%(const float emotion) const;

    // Scalar Emotions operator
    Feeling operator+(const shp::Quantity& emotion) const;
    Feeling operator-(const shp::Quantity& emotion) const;
    Feeling operator*(const shp::Quantity& emotion) const;
    Feeling operator/(const shp::Quantity& emotion) const;
    Feeling operator%(const shp::Quantity& emotion) const;

    // Emotional Vector operator
    Feeling operator+(const shp::Distance& emotion) const;
    Feeling operator-(const shp::Distance& emotion) const;
    Feeling operator*(const shp::Distance& emotion) const;
    Feeling operator/(const shp::Distance& emotion) const;
    Feeling operator%(const shp::Distance& emotion) const;

    // Emotional Intensity operator
    Feeling operator+(const shp::Intrinsic& intensity) const;
    Feeling operator-(const shp::Intrinsic& intensity) const;
    Feeling operator*(const shp::Intrinsic& intensity) const;
    Feeling operator/(const shp::Intrinsic& intensity) const;
    Feeling operator%(const shp::Intrinsic& intensity) const;

    // Emotional Drift operator
    Feeling operator+(const shp::Polar& moderation) const;
    Feeling operator-(const shp::Polar& moderation) const;
    Feeling operator*(const shp::Polar& moderation) const;
    Feeling operator/(const shp::Polar& moderation) const;
    Feeling operator%(const shp::Polar& moderation) const;

    // Getters
    std::shared_ptr<Behaviour> getBehaviour() const { return behaviour; }
    std::string getName() const { return name; }

    // Setters
    void setBehaviour(const std::shared_ptr<Behaviour> realm) { this->behaviour = realm; }
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    shp::Distance getEmotion() const;
    void setEmotion(const shp::Quantity& emotion, const shp::Intrinsic& direction);
    void setEmotion(const shp::Quantity& emotion, const shp::Polar& moderation);
    void setEmotion(const shp::Distance& emotion);
    void setEmotion(const float emotion);
    void setEmotion(const float emotion, const short int scale);
    void setEmotion(const float emotion, const short int scale, const std::string unit);
    void setEmotion(const float emotion, const short int scale, const shp::Unit& unit);
    short int getScaling() const;
    void setScaling(const short int factor);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& unit);
    shp::Intrinsic getIntensity() const;
    void setIntensity(const float intensity);
    void setIntensity(const shp::Intrinsic& intensity);
    void setChangeIntensity(const float degree);
    shp::Polar getSituationModeration() const;
    void setSituationModeration(const float moderation);
    void setSituationModeration(const shp::Polar& moderation);
    void setChangeSituationModeration(const float degree);
    void setChangeEmotion(const float drift);
    void setChangeEmotion(const float drift, const short int scale);
    shp::Signal getSummary() const;
    virtual shp::Signal getStandard();
    virtual shp::Signal getStandard(const Behaviour& instant);
    virtual shp::Signal getPragmatic();
    virtual shp::Signal getPragmatic(const shp::Direction& inclination);
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
    shp::Signal getScalarFraction(const float length) const;
    shp::Signal getScalarFraction(const float length, const short int scale) const;
    shp::Signal getScalarSquareFraction(const float length) const;
    shp::Signal getScalarSquareFraction(const float length, const short int scale) const;
    bool isTimeBoxed() const;
    virtual shp::Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printTimeBoxed() const;
    virtual std::string printRadians() const;
    virtual std::string printTimeBoxedRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
    shp::Direction getEmotionalFeeling(const Behaviour& instant) const;
    shp::Direction getSituationalFeeling(const Behaviour& instant) const;
protected:
    shp::Direction getEmotionalShiftRate() const;
    shp::Direction getSituationalShiftRate() const;
    std::complex<float> toComplex(const float coefficient, const float change);
public:
    static const std::string UNIT;
};

typedef std::vector<Feeling > FeelingArray;

} // namespace con

#endif //CON_FEELING_H