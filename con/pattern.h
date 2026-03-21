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

#ifndef CON_PATTERN_H
#define CON_PATTERN_H

#include <map>
#include "feedback.h"
#include "stimulus.h"
#include "response.h"

namespace con {

class Pattern : private Behaviour {
    Stimulus stimulus;
    Feedback feedback;
    Response response;
public:
    // Constructors
    Pattern();
    Pattern(const shp::Unit& unit);
    Pattern(const float delay);
    Pattern(const float delay, const std::string unit);
    Pattern(const float delay, const shp::Unit& unit);
    Pattern(const float delay, const short int scaling);
    Pattern(const float delay, const short int scaling, const std::string unit);
    Pattern(const float delay, const short int scaling, const shp::Unit& unit);
    Pattern(const Stimulus& stimulus);
    Pattern(const Feedback& feedback);
    Pattern(const Response& response);
    Pattern(const Stimulus& stimulus, const Feedback& feedback);
    Pattern(const Stimulus& stimulus, const Response& response);
    Pattern(const Feedback& feedback, const Response& response);
    Pattern(const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Pattern(const float delay, const short int scaling, const shp::Unit& unit,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Pattern(const std::string name);
    Pattern(const std::string name, const shp::Unit& unit);
    Pattern(const std::string name, const float delay);
    Pattern(const std::string name, const float delay, const std::string unit);
    Pattern(const std::string name, const float delay, const shp::Unit& unit);
    Pattern(const std::string name, const float delay, const short int scaling);
    Pattern(const std::string name, const float delay, const short int scaling, const std::string unit);
    Pattern(const std::string name, const float delay, const short int scaling, const shp::Unit& unit);
    Pattern(const std::string name, const Stimulus& stimulus);
    Pattern(const std::string name, const Feedback& feedback);
    Pattern(const std::string name, const Response& response);
    Pattern(const std::string name, const Stimulus& stimulus, const Feedback& feedback);
    Pattern(const std::string name, const Stimulus& stimulus, const Response& response);
    Pattern(const std::string name, const Feedback& feedback, const Response& response);
    Pattern(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Pattern(const std::string name, const float delay, const short int scaling, const shp::Unit& unit,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response);

    // Destructors
    ~Pattern();

    // Operator overloading
    bool operator==(const Pattern& peer) const;
    Pattern operator+(const Pattern& peer) const;
    Pattern operator-(const Pattern& peer) const;
    Pattern operator*(const Pattern& peer) const;
    Pattern operator/(const Pattern& peer) const;
    Pattern operator%(const Pattern& peer) const;

    // Getters
    Stimulus getStimulus() const { return stimulus; }
    Feedback getFeedback() const { return feedback; }
    Response getResponse() const { return response; }

    // Setters
    void setStimulus(const Stimulus& input) { this->stimulus = input; }
    void setFeedback(const Feedback& modifier) { this->feedback = modifier; }
    void setResponse(const Response& output) { this->response = output; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
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
    shp::Quantity getAgeShift() const;
    shp::Signal getIndicative() const;
    shp::Signal getMemorable() const;
    Pattern copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::map<std::string, Pattern > StimulusMap;
typedef std::map<std::string, Pattern > FeedbackMap;

} // namespace con

#endif //CON_PATTERN_H