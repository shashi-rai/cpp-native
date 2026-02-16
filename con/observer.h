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

#ifndef CON_OBSERVER_H
#define CON_OBSERVER_H

#include "stimulus.h"

namespace con {

class Observer : private Behaviour {
    StimulusArray stimulations;
public:
    // Constructors
    Observer();
    Observer(const StimulusArray& stimulations);
    Observer(const std::string name);
    Observer(const std::string name, const StimulusArray& stimulations);

    // Destructors
    ~Observer();

    // Operator overloading
    bool operator==(const Observer& peer) const;
    Observer operator+(const Observer& peer) const;
    Observer operator-(const Observer& peer) const;

    // Access operator
    Stimulus operator()(const int x) { return stimulations[x]; }
    const Stimulus operator()(const int x) const { return stimulations[x]; }

    // Getters
    StimulusArray getStimulations() const { return stimulations; }

    // Setters
    void setStimulations(const StimulusArray& objects) { this->stimulations = objects; }

    // Additional methods
    int getStimulationCount() const;
    Stimulus getStimulation(const int index) const;
    void setStimulation(const int index, const Stimulus& object);
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
    Observer copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printStimulations() const;
};

typedef std::vector<Observer > ObserverArray;

} // namespace con

#endif //CON_OBSERVER_H