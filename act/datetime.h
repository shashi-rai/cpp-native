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

#ifndef ACT_DATETIME_H
#define ACT_DATETIME_H

#include <chrono>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

namespace act {

class DateTime {
    long value;
public:
    // Constructors
    DateTime();
    DateTime(long value);

    // Destructors
    ~DateTime();

    // Operator overloading
    bool operator==(const DateTime& peer) const;
    DateTime operator+(const DateTime& peer) const;
    DateTime operator-(const DateTime& peer) const;
    DateTime operator*(const DateTime& peer) const;
    DateTime operator/(const DateTime& peer) const;
    DateTime operator%(const DateTime& peer) const;

    // Getters
    long getValue() const { return value; }

    // Setters
    void setValue(const long time) { this->value = time; }

    // Additional methods
    virtual DateTime copy();
    virtual void clear();
    virtual std::string print();
public:
    static const long getCurrent();
public:
    static const long DEFAULT_VALUE;
};

typedef std::vector<DateTime > DateTimeArray;

} // namespace act

#endif //ACT_DATETIME_H