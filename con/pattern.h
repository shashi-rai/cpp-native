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
#include "stimulus.h"
#include "response.h"

namespace con {

class Pattern : protected Behaviour {
    Stimulus stimulus;
    Response response;
public:
    // Constructors
    Pattern();
    Pattern(const Stimulus& stimulus);
    Pattern(const Response& response);
    Pattern(const Stimulus& stimulus, const Response& response);
    Pattern(const std::string name);
    Pattern(const std::string name, const Stimulus& stimulus);
    Pattern(const std::string name, const Response& response);
    Pattern(const std::string name, const Stimulus& stimulus, const Response& response);

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
    Response getResponse() const { return response; }

    // Setters
    void setStimulus(const Stimulus& input) { this->stimulus = input; }
    void setResponse(const Response& output) { this->response = output; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    Pattern copy() const;
    virtual void clear();
    virtual std::string print() const;
};

typedef std::map<const std::string, Pattern > PatternMap;

} // namespace con

#endif //CON_PATTERN_H