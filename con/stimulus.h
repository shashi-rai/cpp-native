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

#ifndef CON_STIMULUS_H
#define CON_STIMULUS_H

#include "behaviour.h"

namespace con {

class Stimulus : private Behaviour {
    shp::Signal input;
public:
    // Constructors
    Stimulus();
    Stimulus(const shp::Unit& unit);
    Stimulus(const float delay);
    Stimulus(const float delay, const std::string unit);
    Stimulus(const float delay, const shp::Unit& unit);
    Stimulus(const float delay, const short int scaling);
    Stimulus(const float delay, const short int scaling, const std::string unit);
    Stimulus(const float delay, const short int scaling, const shp::Unit& unit);
    Stimulus(const shp::Signal& input);
    Stimulus(const float delay, const short int scaling, const shp::Unit& unit,
        const shp::Signal& input);
    Stimulus(const std::string name);
    Stimulus(const std::string name, const shp::Unit& unit);
    Stimulus(const std::string name, const float delay);
    Stimulus(const std::string name, const float delay, const std::string unit);
    Stimulus(const std::string name, const float delay, const shp::Unit& unit);
    Stimulus(const std::string name, const float delay, const short int scaling);
    Stimulus(const std::string name, const float delay, const short int scaling, const std::string unit);
    Stimulus(const std::string name, const float delay, const short int scaling, const shp::Unit& unit);
    Stimulus(const std::string name, const shp::Signal& input);
    Stimulus(const std::string name, const float delay, const short int scaling, const shp::Unit& unit,
        const shp::Signal& input);

    // Destructors
    ~Stimulus();

    // Operator overloading
    bool operator==(const Stimulus& peer) const;
    Stimulus operator+(const Stimulus& peer) const;
    Stimulus operator-(const Stimulus& peer) const;
    Stimulus operator*(const Stimulus& peer) const;
    Stimulus operator/(const Stimulus& peer) const;
    Stimulus operator%(const Stimulus& peer) const;

    // Stimulus Mixing operator
    shp::Signal operator()(const Stimulus& feedback) const;

    // Getters
    shp::Signal getInput() const { return input; }

    // Setters
    void setInput(const shp::Signal& action) { this->input = action; }

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
    Stimulus copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Stimulus > StimulusArray;

} // namespace con

#endif //CON_STIMULUS_H