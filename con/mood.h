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

#ifndef CON_MOOD_H
#define CON_MOOD_H

#include "belief.h"

namespace con {

// To enable compiler resolve forward declarations
class Circumstance;

class Mood : protected Belief {
    con::Feeling feeling;
public:
    // Constructors
    Mood();
    Mood(const std::string name);
    Mood(const Belief& belief);
    Mood(const float belief);
    Mood(const float belief, const std::string unit);
    Mood(const float belief, const shp::Unit& unit);
    Mood(const float belief, const short int scaling);
    Mood(const float belief, const short int scaling, const std::string unit);
    Mood(const float belief, const short int scaling, const shp::Unit& unit);
    Mood(const Feeling& feeling);
    Mood(const std::string name, const Belief& belief);
    Mood(const std::string name, const float belief);
    Mood(const std::string name, const float belief, const std::string unit);
    Mood(const std::string name, const float belief, const shp::Unit& unit);
    Mood(const std::string name, const float belief, const short int scaling);
    Mood(const std::string name, const float belief, const short int scaling, const std::string unit);
    Mood(const std::string name, const float belief, const short int scaling, const shp::Unit& unit);
    Mood(const Belief& belief, const Feeling& feeling);
    Mood(const float belief, const float feeling);
    Mood(const std::string name, const float belief, const float feeling);

    // Destructors
    ~Mood();

    // Operator overloading
    bool operator==(const Mood& peer) const;
    bool operator<(const Mood& peer) const;
    bool operator>(const Mood& peer) const;
    bool operator<=(const Mood& peer) const;
    bool operator>=(const Mood& peer) const;
    Mood operator+(const Mood& peer) const;
    Mood operator-(const Mood& peer) const;
    Mood operator*(const Mood& peer) const;
    Mood operator/(const Mood& peer) const;
    Mood operator%(const Mood& peer) const;

    // Belief operator
    Mood operator+(const Belief& peer) const;
    Mood operator-(const Belief& peer) const;
    Mood operator*(const Belief& peer) const;
    Mood operator/(const Belief& peer) const;
    Mood operator%(const Belief& peer) const;

    // Feeling operator
    Mood operator+(const Feeling& peer) const;
    Mood operator-(const Feeling& peer) const;
    Mood operator*(const Feeling& peer) const;
    Mood operator/(const Feeling& peer) const;
    Mood operator%(const Feeling& peer) const;

    // Getters
    con::Feeling getFeeling() const { return feeling; }

    // Setters
    void setFeeling(const con::Feeling& object) { this->feeling = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    Belief getBelief() const;
    void setBelief(const Belief& object);
    shp::Quantity getSubstance();
    shp::Quantity getEmotions() const;
    void setEmotions(const int count);
    void changeFlowSpeed(const float drift);
    void changeFlowSpeed(const float drift, const short int scale);
    void changeIntensity(const float degree);
    shp::Signal getChallenge() const;
    shp::Signal getStrength(const shp::Temporal& interval) const;
    shp::Signal getForce(const shp::Temporal& interval) const;
    shp::Signal getPotential() const;
    shp::Signal getPotential(const shp::Signal& drift) const;
    shp::Signal getBeliefFlow() const;
    shp::Signal getBeliefFlow(const shp::Signal& drift) const;
    shp::Signal getThoughtful() const;
    shp::Signal getThoughtful(const shp::Signal& drift) const;
    shp::Signal getKnowledgeStrength() const;
    shp::Signal getKnowledgeDynamic() const;
    shp::Signal getEmotionalStrength() const;
    shp::Signal getEmotionalDynamic() const;
    shp::Signal getRateOfChange() const;
    std::shared_ptr<Circumstance> getKnowledgeSituation() const;
    std::shared_ptr<Circumstance> getEmotionalSituation() const;
    bool checkNonZero() const;
    virtual shp::Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const Mood getLooping(const Mood unitary, const float multiplier);
    static const shp::Quantity getEmotionCharges();
    static const shp::Quantity getEmotionFlowRate();
public:
    static const std::string UNIT;
    static const std::string EMOTION_SECOND;
    static const std::string KNOWLEDGE_FIELD;
    static const std::string EMOTIONAL_FIELD;
    static const float EMOTION_FLOW_RATE;
    static const short int EMOTION_FLOW_SCALE;
};

typedef std::vector<Mood > MoodArray;

} // namespace con

#endif //CON_MOOD_H