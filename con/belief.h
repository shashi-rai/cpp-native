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

#ifndef CON_BELIEF_H
#define CON_BELIEF_H

#include "circumstance.h"
#include "feeling.h"

namespace con {

// To enable compiler resolve forward declarations
class Circumstance;

class Belief : public shp::Temporal {
    std::shared_ptr<Circumstance> situation;
public:
    // Constructors
    Belief();
    Belief(const std::shared_ptr<Circumstance> situation);
    Belief(const std::string unit);
    Belief(const shp::Unit& unit);
    Belief(const shp::Unit& unit, const std::shared_ptr<Circumstance> situation);
    Belief(const float awareness);
    Belief(const float awareness, const std::shared_ptr<Circumstance> situation);
    Belief(const float awareness, const std::string unit);
    Belief(const float awareness, const shp::Unit& unit);
    Belief(const float awareness, const shp::Unit& unit, const std::shared_ptr<Circumstance> situation);
    Belief(const float awareness, const short int scaling);
    Belief(const float awareness, const short int scaling, const std::shared_ptr<Circumstance> situation);
    Belief(const float awareness, const short int scaling, const std::string unit);
    Belief(const float awareness, const short int scaling, const shp::Unit& unit);
    Belief(const float awareness, const short int scaling, const shp::Unit& unit, const std::shared_ptr<Circumstance> situation);

    // Destructors
    ~Belief();

    // Operator overloading
    bool operator==(const Belief& peer) const;
    bool operator<(const Belief& peer) const;
    bool operator>(const Belief& peer) const;
    bool operator<=(const Belief& peer) const;
    bool operator>=(const Belief& peer) const;
    Belief operator+(const Belief& peer) const;
    Belief operator-(const Belief& peer) const;
    Belief operator*(const Belief& peer) const;
    Belief operator/(const Belief& peer) const;
    Belief operator%(const Belief& peer) const;

    // Quantity operator
    Belief operator+(const shp::Quantity& peer) const;
    Belief operator-(const shp::Quantity& peer) const;
    Belief operator*(const shp::Quantity& peer) const;
    Belief operator/(const shp::Quantity& peer) const;
    Belief operator%(const shp::Quantity& peer) const;

    // Access operator
    shp::Signal operator()(const Belief& peer, const shp::Distance awareness,
        const shp::Distance stance) const;

    // Getters
    std::shared_ptr<Circumstance> getSituation() const { return situation; }

    // Setters
    void setSituation(std::shared_ptr<Circumstance> awareness) { this->situation = awareness; }

    // Additional methods
    bool isFamiliar() const;
    shp::Distance getTrustRadius() const;
    void setTrustRadius(const shp::Distance& awareness);
    void setTrustRadius(const float awareness);
    void setTrustRadius(const float awareness, const short int scale);
    void setTrustRadius(const float awareness, const short int scale, const std::string unit);
    void setTrustRadius(const float awareness, const short int scale, const shp::Unit& unit);
    short int getScaling() const;
    void setScaling(const short int factor);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& object);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    shp::Potential getConfidence() const;
    shp::Signal getFeeling() const;
    void setFeeling(const Feeling& feeling);
    std::shared_ptr<Circumstance> getOriginalSituation() const;
    virtual shp::Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Temporal getFluctuation(const float phase) const;
public:
    static const std::string UNIT;
    static const std::string KNOWLEDGE_FIELD;
    static const short int KNOWLEDGE_SCALE;
    static const float EMOTION;
};

typedef std::vector<Belief > BeliefArray;

} // namespace con

#endif //CON_BELIEF_H