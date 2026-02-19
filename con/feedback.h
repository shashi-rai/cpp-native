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

#ifndef CON_FEEDBACK_H
#define CON_FEEDBACK_H

#include "behaviour.h"
#include "../shp/frequency.h"

namespace con {

class Feedback : private Behaviour {
    shp::Signal adjustment;
    shp::Frequency threshold;
public:
    // Constructors
    Feedback();
    Feedback(const shp::Signal& adjustment);
    Feedback(const shp::Frequency& threshold);
    Feedback(const shp::Signal& adjustment, const shp::Frequency& threshold);
    Feedback(const std::string name);
    Feedback(const std::string name, const shp::Signal& adjustment);
    Feedback(const std::string name, const shp::Frequency& threshold);
    Feedback(const std::string name, const shp::Signal& adjustment, const shp::Frequency& threshold);

    // Destructors
    ~Feedback();

    // Operator overloading
    bool operator==(const Feedback& peer) const;
    Feedback operator+(const Feedback& peer) const;
    Feedback operator-(const Feedback& peer) const;
    Feedback operator*(const Feedback& peer) const;
    Feedback operator/(const Feedback& peer) const;
    Feedback operator%(const Feedback& peer) const;

    // Feedback Mixing operator
    shp::Signal operator()(const Feedback& feedback) const;

    // Getters
    shp::Signal getAdjustment() const { return adjustment; }
    shp::Frequency getThreshold() const { return threshold; }

    // Setters
    void setAdjustment(const shp::Signal& signal) { this->adjustment = signal; }
    void setThreshold(const shp::Frequency& object) { this->threshold = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    void setFrequencyThreshold(const shp::Frequency& repetition);
    float getFrequencyThreshold() const;
    void setFrequencyThreshold(const float value);
    void setFrequencyThreshold(const float value, const short int scale);
    void setFrequencyThreshold(const float value, const short int scale, const std::string unit);
    void setFrequencyThreshold(const float value, const short int scale, const shp::Unit& unit);
    short int getFrequencyScaling() const;
    void setFrequencyScaling(const short int factor);
    shp::Unit getFrequencyUnit() const;
    void setFrequencyUnit(const shp::Unit& object);
    void setTemporalDelay(const shp::Temporal& time);
    float getTemporalDelay() const;
    void setTemporalDelay(const float value);
    void setTemporalDelay(const float value, const short int scale);
    void setTemporalDelay(const float value, const short int scale, const std::string unit);
    void setTemporalDelay(const float value, const short int scale, const shp::Unit& unit);
    short int getTemporalScaling() const;
    void setTemporalScaling(const short int factor);
    shp::Unit getTemporalUnit() const;
    void setTemporalUnit(const shp::Unit& object);
    Feedback copy();
    virtual void clear();
    virtual std::string print() const;
};

typedef std::vector<Feedback > FeedbackArray;

} // namespace con

#endif //CON_FEEDBACK_H