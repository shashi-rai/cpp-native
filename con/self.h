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

#include <sstream>
#include <string>
#include <vector>

namespace con {

class Self {
    std::string name;
public:
    // Constructors
    Self();
    Self(std::string name);

    // Destructors
    ~Self();

    // Operator overloading
    bool operator==(const Self& peer) const;
    Self operator+(const Self& peer) const;
    Self operator-(const Self& peer) const;

    // Getters
    std::string getName() const { return name; }

    // Setters
    void setName(const std::string& name) { this->name = name; }

    // Additional methods
    int getDocumentCount() const;
    virtual Self copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Self > SelfArray;

} // namespace con

#endif //CON_SELF_H