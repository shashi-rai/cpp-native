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

#ifndef CON_MEMORY_H
#define CON_MEMORY_H

#include "strategy.h"

namespace con {

class Memory : private Strategy {
    StrategyMap activators;
public:
    // Constructors
    Memory();
    Memory(const StrategyMap& activators);
    Memory(const Stimulus& stimulus);
    Memory(const Stimulus& stimulus, const StrategyMap& activators);
    Memory(const Feedback& feedback);
    Memory(const Feedback& feedback, const StrategyMap& activators);
    Memory(const Response& response);
    Memory(const Response& response, const StrategyMap& activators);
    Memory(const Stimulus& stimulus, const Response& response);
    Memory(const Feedback& feedback, const Response& response);
    Memory(const Stimulus& stimulus, const Response& response, const StrategyMap& activators);
    Memory(const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Memory(const Stimulus& stimulus, const Feedback& feedback, const Response& response, const StrategyMap& activators);
    Memory(const std::string name);
    Memory(const std::string name, const StrategyMap& activators);
    Memory(const std::string name, const Stimulus& stimulus);
    Memory(const std::string name, const Stimulus& stimulus, const StrategyMap& activators);
    Memory(const std::string name, const Feedback& feedback);
    Memory(const std::string name, const Feedback& feedback, const StrategyMap& activators);
    Memory(const std::string name, const Response& response);
    Memory(const std::string name, const Response& response, const StrategyMap& activators);
    Memory(const std::string name, const Stimulus& stimulus, const Response& response);
    Memory(const std::string name, const Feedback& feedback, const Response& response);
    Memory(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Memory(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response, const StrategyMap& activators);

    // Destructors
    ~Memory();

    // Operator overloading
    bool operator==(const Memory& peer) const;
    Memory operator+(const Memory& peer) const;
    Memory operator-(const Memory& peer) const;

    // Access operator
    Strategy operator()(const std::string key) { return activators[key]; }

    // Getters
    StrategyMap getActivators() const;

    // Setters
    void setActivators(const StrategyMap& objects);

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    Stimulus getStimulus() const;
    void setStimulus(const Stimulus& input);
    Feedback getFeedback() const;
    void setFeedback(const Feedback& modifier);
    Response getResponse() const;
    void setResponse(const Response& output);
    bool isAware(const std::string word) const;
    Response getLearning(const std::string word) const;
    Response getLearning(const Stimulus& stimulus) const;
    Response getLearning(const Feedback& feedback) const;
    void setLearning(const std::string word, const Stimulus& stimulus, const Response& response);
    void setLearning(const std::string word, const Feedback& feedback, const Response& response);
    void setLearning(const std::string word, const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    int getActivatorCount() const;
    Strategy getActivator(const std::string word) const;
    void setActivator(const std::string word, const Strategy& object);
    Memory copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printActivators() const;
};

typedef std::vector<Memory > MemoryArray;

} // namespace con

#endif //CON_MEMORY_H