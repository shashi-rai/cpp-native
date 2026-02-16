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

#ifndef CON_STRATEGY_H
#define CON_STRATEGY_H

#include "pattern.h"

namespace con {

class Strategy : private Pattern {
    StimulusMap stimulators;
    FeedbackMap modulators;
public:
    // Constructors
    Strategy();
    Strategy(const StimulusMap& stimulii);
    Strategy(const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const Stimulus& stimulus);
    Strategy(const Stimulus& stimulus, const StimulusMap& stimulii);
    Strategy(const Stimulus& stimulus, const StimulusMap& stimulii,
        const FeedbackMap& modifiers);
    Strategy(const Feedback& feedback);
    Strategy(const Feedback& feedback, const StimulusMap& stimulii);
    Strategy(const Feedback& feedback, const StimulusMap& stimulii,
        const FeedbackMap& modifiers);
    Strategy(const Response& response);
    Strategy(const Response& response, const StimulusMap& stimulii);
    Strategy(const Response& response, const StimulusMap& stimulii,
        const FeedbackMap& modifiers);
    Strategy(const Stimulus& stimulus, const Feedback& feedback);
    Strategy(const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii);
    Strategy(const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const Feedback& feedback, const Response& response);
    Strategy(const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const Stimulus& stimulus, const Response& response);
    Strategy(const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Strategy(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name);
    Strategy(const std::string name, const StimulusMap& stimulii);
    Strategy(const std::string name, const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Stimulus& stimulus);
    Strategy(const std::string name, const Stimulus& stimulus,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Stimulus& stimulus,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Feedback& feedback);
    Strategy(const std::string name, const Feedback& feedback,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Response& response);
    Strategy(const std::string name, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback);
    Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Feedback& feedback, const Response& response);
    Strategy(const std::string name, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Stimulus& stimulus, const Response& response);
    Strategy(const std::string name, const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);
    Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii);
    Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers);

    // Destructors
    ~Strategy();

    // Operator overloading
    bool operator==(const Strategy& peer) const;
    Strategy operator+(const Strategy& peer) const;
    Strategy operator-(const Strategy& peer) const;

    // Access operator
    Pattern operator()(const std::string key) { return stimulators[key]; }

    // Getters
    StimulusMap getStimulators() const;
    FeedbackMap getModulators() const;

    // Setters
    void setStimulators(const StimulusMap& stimulii);
    void setModulators(const FeedbackMap& modifiers);

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    Stimulus getStimulus() const;
    void setStimulus(const Stimulus& input);
    Feedback getFeedback() const;
    void setFeedback(const Feedback& modifier);
    Response getResponse() const;
    void setResponse(const Response& output);
    bool isAware(const Stimulus& stimulus) const;
    Response getLearning(const Stimulus& stimulus) const;
    void setLearning(const Stimulus& stimulus, const Response& response);
    bool isAware(const Feedback& feedback) const;
    Response getLearning(const Feedback& feedback) const;
    void setLearning(const Feedback& feedback, const Response& response);
    int getStimulusCount() const;
    Pattern getStimulus(const std::string key) const;
    void setStimulus(const std::string key, const Pattern& object);
    int getFeedbackCount() const;
    Pattern getFeedback(const std::string key) const;
    void setFeedback(const std::string key, const Pattern& object);
    Strategy copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printSimulators() const;
    virtual std::string printModulators() const;
};

typedef std::map<std::string, Strategy > StrategyMap;

} // namespace con

#endif //CON_STRATEGY_H