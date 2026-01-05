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

#ifndef LAW_CLAIM_H
#define LAW_CLAIM_H

#include <sstream>
#include <string>
#include <vector>
#include "fact.h"

namespace law {

class Claim {
    std::string name;
    FactArray facts;
public:
    // Constructors
    Claim();
    Claim(const FactArray& facts);
    Claim(std::string name);
    Claim(std::string name, const FactArray& facts);

    // Destructors
    ~Claim();

    // Operator overloading
    bool operator==(const Claim& peer) const;
    Claim operator+(const Claim& peer) const;
    Claim operator-(const Claim& peer) const;

    // Access operator
    Fact operator()(const int x) { return facts[x]; }
    const Fact operator()(const int x) const { return facts[x]; }

    // Getters
    std::string getName() const { return name; }
    FactArray getFacts() const { return facts; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setFacts(const FactArray& data) { this->facts = data; }

    // Additional methods
    int getFactCount() const;
    Fact get(const int index) const;
    void set(const int index, const Fact& object);
    virtual Claim copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Claim > ClaimArray;

} // namespace law

#endif //LAW_CLAIM_H