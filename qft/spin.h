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

#ifndef QFT_SPIN_H
#define QFT_SPIN_H

#include <cmath>
#include <sstream>
#include <vector>

namespace qft {

class Spin {
    float value;
public:
    // Constructors
    Spin();
    Spin(float value);

    // Destructors
    ~Spin();

    // Operator overloading
    bool operator==(const Spin& peer) const;
    Spin operator+(const Spin& peer) const;
    Spin operator-(const Spin& peer) const;
    Spin operator*(const Spin& peer) const;
    Spin operator/(const Spin& peer) const;
    Spin operator%(const Spin& peer) const;

    // Getters
    float getValue() const { return value; }

    // Setters
    void setValue(const float amount) { this->value = amount; }

    // Additional methods
    bool hasNoSpin() const { return value == 0; }
    bool isClockwise() const { return value < 0; }
    bool isAntiClockwise() const { return value > 0; }
    virtual Spin copy();
    virtual void clear();
    virtual std::string print();

public:
    static const float DEFAULT_VALUE;
};

typedef std::vector<Spin > SpinArray;

} // namespace qft

#endif //QFT_SPIN_H