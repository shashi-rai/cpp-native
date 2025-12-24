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

#ifndef ACT_FISCAL_H
#define ACT_FISCAL_H

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "datetime.h"

namespace act {

class Fiscal {
    short int year;
public:
    // Constructors
    Fiscal();
    Fiscal(const short int year);

    // Destructors
    ~Fiscal();

    // Operator overloading
    bool operator==(const Fiscal& peer) const;
    Fiscal operator+(const Fiscal& peer) const;
    Fiscal operator-(const Fiscal& peer) const;
    Fiscal operator%(const Fiscal& peer) const;
    Fiscal operator+(const short int number) const;
    Fiscal operator-(const short int number) const;

    // Getters
    short int getYear() const { return year; }

    // Setters
    void setYear(const short int number) { this->year = number; }

    // Additional methods
    std::string getName();
    virtual Fiscal copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string DEFAULT_SYMBOL;
    static const char DELIMITER;
    static const short int YEAR_WIDTH;
};

typedef std::vector<Fiscal > FiscalArray;

} // namespace act

#endif //ACT_FISCAL_H