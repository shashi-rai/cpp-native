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

#ifndef ACT_BATCH_H
#define ACT_BATCH_H

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "datetime.h"

namespace act {

class Batch {
    short int year;
    short int month;
    short int day;
    short int lot;
public:
    // Constructors
    Batch();
    Batch(const short int lot);
    Batch(const short int lot, const short int day);
    Batch(const short int lot, const short int day, const short int month);
    Batch(const short int lot, const short int day, const short int month, const short int year);

    // Destructors
    ~Batch();

    // Operator overloading
    bool operator==(const Batch& peer) const;
    Batch operator+(const Batch& peer) const;
    Batch operator-(const Batch& peer) const;
    Batch operator%(const Batch& peer) const;
    Batch operator+(const short int number) const;
    Batch operator-(const short int number) const;


    // Getters
    short int getYear() const { return year; }
    short int getMonth() const { return month; }
    short int getDay() const { return day; }
    short int getLot() const { return lot; }

    // Setters
    void setYear(const short int number) { this->year = number; }
    void setMonth(const short int number) { this->month = number; }
    void setDay(const short int number) { this->day = number; }
    void setLot(const short int number) { this->lot = number; }

    // Additional methods
    std::string getName();
    virtual Batch copy();
    virtual void clear();
    virtual std::string print();

public:
    static const char DELIMITER;
    static const short int YEAR_WIDTH;
    static const short int MONTH_WIDTH;
    static const short int DAY_WIDTH;
    static const short int HOUR_WIDTH;
    static const short int MINUTE_WIDTH;
    static const short int SECOND_WIDTH;
    static const short int LOT_WIDTH;
    static const short int LOT_MIN;
    static const short int LOT_MAX;
};

typedef std::vector<Batch > BatchArray;

} // namespace act

#endif //ACT_BATCH_H