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

#include "pattern.h"

namespace con {

class Memory : private Pattern {
    PatternMap patterns;
public:
    // Constructors
    Memory();
    Memory(const PatternMap& patterns);
    Memory(const Stimulus& stimulus);
    Memory(const Stimulus& stimulus, const PatternMap& patterns);
    Memory(const Response& response);
    Memory(const Response& response, const PatternMap& patterns);
    Memory(const Stimulus& stimulus, const Response& response);
    Memory(const Stimulus& stimulus, const Response& response, const PatternMap& patterns);
    Memory(const std::string name);
    Memory(const std::string name, const PatternMap& patterns);
    Memory(const std::string name, const Stimulus& stimulus);
    Memory(const std::string name, const Stimulus& stimulus, const PatternMap& patterns);
    Memory(const std::string name, const Response& response);
    Memory(const std::string name, const Response& response, const PatternMap& patterns);
    Memory(const std::string name, const Stimulus& stimulus, const Response& response);
    Memory(const std::string name, const Stimulus& stimulus, const Response& response, const PatternMap& patterns);

    // Destructors
    ~Memory();

    // Operator overloading
    bool operator==(const Memory& peer) const;
    Memory operator+(const Memory& peer) const;
    Memory operator-(const Memory& peer) const;

    // Access operator
    Pattern operator()(const std::string key) { return patterns[key]; }

    // Getters
    PatternMap getPatterns() const;

    // Setters
    void setPatterns(const PatternMap& objects);

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    Stimulus getStimulus() const;
    void setStimulus(const Stimulus& input);
    Response getResponse() const;
    void setResponse(const Response& output);
    bool isAware(const Stimulus& stimulus) const;
    Response getLearning(const Stimulus& stimulus) const;
    void setLearning(const Stimulus& stimulus, const Response& response);
    int getPatternCount() const;
    Pattern get(const std::string key) const;
    void set(const std::string key, const Pattern& object);
    Memory copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printPatterns() const;
};

typedef std::vector<Memory > MemoryArray;

} // namespace con

#endif //CON_MEMORY_H