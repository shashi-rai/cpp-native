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
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace act {

class DateTime {
    std::time_t value;
public:
    // Constructors
    DateTime();
    DateTime(const std::time_t value);

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
    std::time_t getValue() const { return value; }

    // Setters
    void setValue(const std::time_t time) { this->value = time; }

    // Additional methods
    const int getYear();
    const int getMonth();
    const int getDay();
    const int getHour();
    const int getMinute();
    const int getSecond();
    const long long getCurrent();
    const std::chrono::seconds getSeconds();
    const long long getMilliseconds();
    const long long getNanoseconds();
    virtual DateTime copy();
    virtual void clear();
    virtual std::string print();
public:
    static const std::time_t getSystem();
    static const std::time_t getFormat(const std::string& datetime, const std::string& format);
public:
    static const long DEFAULT_VALUE;
    static const short int YEAR_BASE;
    static const short int YEAR_MIN;
    static const short int YEAR_MAX;
    static const short int MONTH_MIN;
    static const short int MONTH_MAX;
    static const short int DAY_MIN;
    static const short int DAY_MAX;
    static const short int HOUR_MIN;
    static const short int HOUR_MAX;
    static const short int MINUTE_MIN;
    static const short int MINUTE_MAX;
    static const short int SECOND_MIN;
    static const short int SECOND_MAX;
};

typedef std::vector<DateTime > DateTimeArray;

} // namespace act

#endif //ACT_DATETIME_H