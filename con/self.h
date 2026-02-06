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

namespace con {

class Self : private Memory {
    StimulusArray sensors;
public:
    // Constructors
    Self();
    Self(const StimulusArray& sensors);
    Self(const Stimulus& stimulus);
    Self(const Stimulus& stimulus, const StimulusArray& sensors);
    Self(const Response& response);
    Self(const Response& response, const StimulusArray& sensors);
    Self(const Stimulus& stimulus, const Response& response);
    Self(const Stimulus& stimulus, const Response& response, const StimulusArray& sensors);
    Self(const std::string name, const StimulusArray& sensors);
    Self(const std::string name);
    Self(const std::string name, const Stimulus& stimulus);
    Self(const std::string name, const Stimulus& stimulus, const StimulusArray& sensors);
    Self(const std::string name, const Response& response);
    Self(const std::string name, const Response& response, const StimulusArray& sensors);
    Self(const std::string name, const Stimulus& stimulus, const Response& response);
    Self(const std::string name, const Stimulus& stimulus, const Response& response, const StimulusArray& sensors);

    // Destructors
    ~Self();

    // Operator overloading
    bool operator==(const Self& peer) const;
    Self operator+(const Self& peer) const;
    Self operator-(const Self& peer) const;

    // Access operator
    Stimulus operator()(const int x) { return sensors[x]; }
    const Stimulus operator()(const int x) const { return sensors[x]; }

    // Getters
    StimulusArray getSensors() const { return sensors; }

    // Setters
    void setSensors(const StimulusArray& objects) { this->sensors = objects; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    Stimulus getStimulus() const;
    void setStimulus(const Stimulus& input);
    Response getResponse() const;
    void setResponse(const Response& output);
    int getSensorCount() const;
    Stimulus get(const int index) const;
    void set(const int index, const Stimulus& object);
    Self copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printSensors() const;
};

typedef std::vector<Self > SelfArray;

} // namespace con

#endif //CON_SELF_H