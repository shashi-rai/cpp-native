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

#ifndef CON_BEHAVIOUR_H
#define CON_BEHAVIOUR_H

#include "../shp/temporal.h"

namespace con {

class Behaviour : private shp::Temporal {
    std::string name;
public:
    // Constructors
    Behaviour();
    Behaviour(const shp::Unit& unit);
    Behaviour(const float delay);
    Behaviour(const float delay, const std::string unit);
    Behaviour(const float delay, const shp::Unit& unit);
    Behaviour(const float delay, const short int scaling);
    Behaviour(const float delay, const short int scaling, const std::string unit);
    Behaviour(const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const shp::Intrinsic& intent, const float delay, const short int scaling);
    Behaviour(const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit);
    Behaviour(const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const shp::Signal& experience);
    Behaviour(const shp::Signal& experience, const std::string unit);
    Behaviour(const shp::Signal& experience, const shp::Unit& unit);
    Behaviour(const shp::Signal& experience, const float delay);
    Behaviour(const shp::Signal& experience, const float delay, const std::string unit);
    Behaviour(const shp::Signal& experience, const float delay, const shp::Unit& unit);
    Behaviour(const shp::Signal& experience, const float delay, const short int scaling);
    Behaviour(const shp::Signal& experience, const float delay, const short int scaling, const std::string unit);
    Behaviour(const shp::Signal& experience, const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling);
    Behaviour(const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit);
    Behaviour(const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const std::string name);
    Behaviour(const std::string name, const std::string unit);
    Behaviour(const std::string name, const shp::Unit& unit);
    Behaviour(const std::string name, const float delay);
    Behaviour(const std::string name, const float delay, const std::string unit);
    Behaviour(const std::string name, const float delay, const shp::Unit& unit);
    Behaviour(const std::string name, const float delay, const short int scaling);
    Behaviour(const std::string name, const float delay, const short int scaling, const std::string unit);
    Behaviour(const std::string name, const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const std::string name, const shp::Intrinsic& intent, const float delay, const short int scaling);
    Behaviour(const std::string name, const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit);
    Behaviour(const std::string name, const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const std::string name, const shp::Signal& experience);
    Behaviour(const std::string name, const shp::Signal& experience, const std::string unit);
    Behaviour(const std::string name, const shp::Signal& experience, const shp::Unit& unit);
    Behaviour(const std::string name, const shp::Signal& experience, const float delay);
    Behaviour(const std::string name, const shp::Signal& experience, const float delay, const std::string unit);
    Behaviour(const std::string name, const shp::Signal& experience, const float delay, const shp::Unit& unit);
    Behaviour(const std::string name, const shp::Signal& experience, const float delay, const short int scaling);
    Behaviour(const std::string name, const shp::Signal& experience, const float delay, const short int scaling, const std::string unit);
    Behaviour(const std::string name, const shp::Signal& experience, const float delay, const short int scaling, const shp::Unit& unit);
    Behaviour(const std::string name, const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling);
    Behaviour(const std::string name, const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const std::string unit);
    Behaviour(const std::string name, const shp::Signal& experience, const shp::Intrinsic& intent, const float delay, const short int scaling, const shp::Unit& unit);

    // Destructors
    ~Behaviour();

    // Operator overloading
    bool operator==(const Behaviour& peer) const;
    bool operator<(const Behaviour& peer) const;
    bool operator>(const Behaviour& peer) const;
    bool operator<=(const Behaviour& peer) const;
    bool operator>=(const Behaviour& peer) const;
    Behaviour operator+(const Behaviour& peer) const;
    Behaviour operator-(const Behaviour& peer) const;
    Behaviour operator*(const Behaviour& peer) const;
    Behaviour operator/(const Behaviour& peer) const;
    Behaviour operator%(const Behaviour& peer) const;

    // Getters
    std::string getName() const { return name; }

    // Setters
    void setName(const std::string name) { this->name = name; }

    // Additional methods
    shp::Signal getExperience() const;
    void setExperience(const shp::Signal& knowledge);
    void setDelay(const shp::Temporal& necessity);
    float getDelay() const;
    void setDelay(const float necessity);
    void setDelay(const float necessity, const short int scale);
    void setDelay(const float necessity, const short int scale, const std::string unit);
    void setDelay(const float necessity, const short int scale, const shp::Unit& unit);
    float getIntention() const;
    float getIntentionDrift() const;
    void setIntentionDrift(const shp::Intrinsic& moderation);
    float getExperienceShift() const;
    void setExperienceShift(const shp::Intrinsic& moderation);
    void setExperienceShift(const float action, const shp::Intrinsic& moderation);
    void setExperienceShift(const float action, const short int scale, const shp::Intrinsic& moderation);
    void setExperienceShift(const float action, const short int scale, const std::string unit, const shp::Intrinsic& moderation);
    void setExperienceShift(const float action, const short int scale, const shp::Unit& unit, const shp::Intrinsic& moderation);
    short int getScaling() const;
    void setScaling(const short int factor);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& object);
    shp::Quantity getDelayShift() const;
    shp::Signal getRepeating() const;
    shp::Signal getEndurance() const;
    Behaviour copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Behaviour > BehaviourArray;

} // namespace con

#endif //CON_BEHAVIOUR_H