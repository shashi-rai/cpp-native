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

#ifndef CON_CIRCUMSTANCE_H
#define CON_CIRCUMSTANCE_H

#include "behaviour.h"
#include "../shp/potential.h"

namespace con {

// To enable compiler resolve forward declarations
class Belief;

class Circumstance : protected Behaviour {
    shp::Potential confidence;
public:
    // Constructors
    Circumstance();
    Circumstance(const shp::Unit& unit);
    Circumstance(const shp::Potential& confidence);
    Circumstance(const shp::Distance& impact);
    Circumstance(const shp::Azimuth& azimuth);
    Circumstance(const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const shp::Polar& polar);
    Circumstance(const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const shp::Angular& knowledge);
    Circumstance(const float necessity);
    Circumstance(const float necessity, const std::string unit);
    Circumstance(const float necessity, const shp::Unit& unit);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Potential& confidence);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Distance& impact);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Polar& polar);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const shp::Unit& unit,
        const shp::Angular& knowledge);
    Circumstance(const float necessity, const short int scaling);
    Circumstance(const float necessity, const short int scaling, const std::string unit);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Potential& confidence);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Distance& impact);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Polar& polar);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
        const shp::Angular& knowledge);
    Circumstance(const shp::Signal& experience);
    Circumstance(const shp::Signal& experience, const std::string unit);
    Circumstance(const shp::Signal& experience, const shp::Unit& unit);
    Circumstance(const shp::Signal& experience, const float necessity);
    Circumstance(const shp::Signal& experience, const float necessity, const std::string unit);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Potential& confidence);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Polar& polar);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
        const shp::Angular& knowledge);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const std::string unit);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Potential& confidence);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Angular& knowledge);
    Circumstance(const std::string name);
    Circumstance(const std::string name, const std::string unit);
    Circumstance(const std::string name, const shp::Unit& unit);
    Circumstance(const std::string name, const shp::Potential& confidence);
    Circumstance(const std::string name, const shp::Distance& impact);
    Circumstance(const std::string name, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Polar& polar);
    Circumstance(const std::string name, const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Distance& impact,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Angular& knowledge);
    Circumstance(const std::string name, const float necessity);
    Circumstance(const std::string name, const float necessity, const std::string unit);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Potential& confidence);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Polar& polar);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
        const shp::Angular& knowledge);
    Circumstance(const std::string name, const float necessity, const short int scaling);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const std::string unit);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Potential& confidence);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const float necessity, const short int scaling,
        const shp::Unit& unit, const shp::Angular& knowledge);
    Circumstance(const std::string name, const shp::Signal& experience);
    Circumstance(const std::string name, const shp::Signal& experience, const std::string unit);
    Circumstance(const std::string name, const shp::Signal& experience, const shp::Unit& unit);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const std::string unit);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Potential& confidence);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Distance& impact);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Polar& polar);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const shp::Unit& unit, const shp::Angular& knowledge);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const std::string unit);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Potential& confidence);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Distance& impact);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Distance& impact,
        const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Polar& polar);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Distance& impact,
        const shp::Polar& polar);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Distance& impact,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
        const short int scaling, const shp::Unit& unit, const shp::Angular& knowledge);

    // Destructors
    ~Circumstance();

    // Operator overloading
    bool operator==(const Circumstance& peer) const;
    bool operator<(const Circumstance& peer) const;
    bool operator>(const Circumstance& peer) const;
    bool operator<=(const Circumstance& peer) const;
    bool operator>=(const Circumstance& peer) const;
    Circumstance operator+(const Circumstance& peer) const;
    Circumstance operator-(const Circumstance& peer) const;
    Circumstance operator*(const Circumstance& peer) const;
    Circumstance operator/(const Circumstance& peer) const;
    Circumstance operator%(const Circumstance& peer) const;

    // Access operator
    shp::Signal operator()(const Circumstance& peer,
        const shp::Distance& awareness, const shp::Distance& stance) const;
    shp::Signal operator()(const Circumstance& peerX, const Circumstance& peerY,
        const shp::Distance& awarenessX, const shp::Distance& awarenessY) const;

    // Getters
    shp::Potential getConfidence() const { return confidence; }

    // Setters
    void setConfidence(const shp::Potential& range) { this->confidence = range; }

    // Additional methods
    shp::Azimuth getExperienceChange() const;
    void setExperienceChange(const shp::Azimuth& moderation);
    void setExperienceChange(const float action, const shp::Azimuth& moderation);
    void setExperienceChange(const float action, const short int scale, const shp::Azimuth& moderation);
    void setExperienceChange(const float action, const short int scale, const std::string unit, const shp::Azimuth& moderation);
    void setExperienceChange(const float action, const short int scale, const shp::Unit& unit, const shp::Azimuth& moderation);
    shp::Azimuth getIntentionChange() const;
    void setIntentionChange(const shp::Azimuth& moderation);
    void setIntentionChange(const shp::Signal& signal);
    void setIntentionChange(const float intent);
    void setIntentionChange(const float intent, const short int scale);
    void setIntentionChange(const float intent, const short int scale, const std::string unit);
    void setIntentionChange(const float intent, const short int scale, const shp::Unit& unit);
    shp::Angular getContext() const;
    void setContext(const shp::Angular& knowledge);
    shp::Distance getCapability() const;
    void setCapability(const shp::Distance& knowledge);
    void setCapability(const float knowledge);
    void setCapability(const float knowledge, const short int scale);
    void setCapability(const float knowledge, const short int scale, const std::string unit);
    void setCapability(const float knowledge, const short int scale, const shp::Unit& unit);
    shp::Azimuth getCentral() const;
    void setCentral(const shp::Azimuth& impact);
    shp::Polar getPeripheral() const;
    void setPeripheral(const shp::Polar& impact);
    Circumstance getLevel() const;
    Circumstance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    Circumstance getFluctuation(const float phase) const;
public:
    static const std::shared_ptr<con::Circumstance> shareable(const std::string name,
        const float necessity, const short int scaling);
};

typedef std::vector<Circumstance > CircumstanceArray;

} // namespace con

#endif //CON_CIRCUMSTANCE_H