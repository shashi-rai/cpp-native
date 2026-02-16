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

#ifndef CON_SELF_H
#define CON_SELF_H

#include "memory.h"
#include "observer.h"

namespace con {

class Self : private Memory {
    ObserverArray observers;
public:
    // Constructors
    Self();
    Self(const ObserverArray& observers);
    Self(const Stimulus& stimulus);
    Self(const Stimulus& stimulus, const ObserverArray& observers);
    Self(const Feedback& feedback);
    Self(const Feedback& feedback, const ObserverArray& observers);
    Self(const Response& response);
    Self(const Response& response, const ObserverArray& observers);
    Self(const Stimulus& stimulus, const Response& response);
    Self(const Stimulus& stimulus, const Response& response, const ObserverArray& observers);
    Self(const Feedback& feedback, const Response& response);
    Self(const Feedback& feedback, const Response& response, const ObserverArray& observers);
    Self(const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Self(const Stimulus& stimulus, const Feedback& feedback, const Response& response, const ObserverArray& observers);
    Self(const std::string name, const ObserverArray& observers);
    Self(const std::string name);
    Self(const std::string name, const Stimulus& stimulus);
    Self(const std::string name, const Stimulus& stimulus, const ObserverArray& observers);
    Self(const std::string name, const Feedback& feedback);
    Self(const std::string name, const Feedback& feedback, const ObserverArray& observers);
    Self(const std::string name, const Response& response);
    Self(const std::string name, const Response& response, const ObserverArray& observers);
    Self(const std::string name, const Stimulus& stimulus, const Response& response);
    Self(const std::string name, const Stimulus& stimulus, const Response& response, const ObserverArray& observers);
    Self(const std::string name, const Feedback& feedback, const Response& response);
    Self(const std::string name, const Feedback& feedback, const Response& response, const ObserverArray& observers);
    Self(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response);
    Self(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response, const ObserverArray& observers);

    // Destructors
    ~Self();

    // Operator overloading
    bool operator==(const Self& peer) const;
    Self operator+(const Self& peer) const;
    Self operator-(const Self& peer) const;

    // Access operator
    Observer operator()(const int x) { return observers[x]; }
    const Observer operator()(const int x) const { return observers[x]; }

    // Getters
    ObserverArray getObservers() const { return observers; }

    // Setters
    void setObservers(const ObserverArray& objects) { this->observers = objects; }

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
    shp::Signal getBehaviour(const Stimulus& stimulus) const;
    shp::Signal getBehaviour(const Feedback& feedback) const;
    void setBehaviour(const std::string word, const Stimulus& stimulus, const Response& response);
    void setBehaviour(const std::string word, const Feedback& feedback, const Response& response);
    int getObserverCount() const;
    Observer getObserver(const int index) const;
    void setObserver(const int index, const Observer& object);
    Self copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printObservers() const;
};

typedef std::vector<Self > SelfArray;

} // namespace con

#endif //CON_SELF_H