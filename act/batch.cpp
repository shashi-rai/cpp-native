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

#include "batch.h"

namespace act {

const char Batch::DELIMITER = '0';
const short int Batch::YEAR_WIDTH = 4;
const short int Batch::MONTH_WIDTH = 2;
const short int Batch::DAY_WIDTH = 2;
const short int Batch::HOUR_WIDTH = 2;
const short int Batch::MINUTE_WIDTH = 2;
const short int Batch::SECOND_WIDTH = 2;
const short int Batch::LOT_WIDTH = 4;
const short int Batch::LOT_MIN = 0;
const short int Batch::LOT_MAX = 9999;

Batch::Batch() : lot(LOT_MIN),
        day(DateTime::DAY_MIN), month(DateTime::MONTH_MIN), year(DateTime::YEAR_MIN) {

}

Batch::Batch(const short int lot) : lot(lot),
        day(DateTime::DAY_MIN), month(DateTime::MONTH_MIN), year(DateTime::YEAR_MIN) {

}

Batch::Batch(const short int lot, const short int day)
        : lot(lot), day(day), month(DateTime::MONTH_MIN), year(DateTime::YEAR_MIN) {

}

Batch::Batch(const short int lot, const short int day, const short int month)
        : lot(lot), day(day), month(month), year(DateTime::YEAR_MIN) {

}

Batch::Batch(const short int lot,
        const short int day, const short int month, const short int year)
        : lot(lot), day(day), month(month), year(year) {

}

Batch::~Batch() {

}

bool Batch::operator==(const Batch& peer) const {
    return (lot == peer.lot)
        && (day == peer.day)
        && (month == peer.month)
        && (year == peer.year);
}

Batch Batch::operator+(const Batch& peer) const {
    return Batch((lot + peer.lot), (day + peer.day), (month + peer.month), (year + peer.year));
}

Batch Batch::operator-(const Batch& peer) const {
    return Batch((lot - peer.lot), (day - peer.day), (month - peer.month), (year - peer.year));
}

Batch Batch::operator%(const Batch& peer) const {
    return Batch((lot % peer.lot), (day % peer.day), (month % peer.month), (year % peer.year));
}

Batch Batch::operator+(const short int number) const {
    short int newlot = lot + number;
    newlot = (newlot > LOT_MAX) ? (newlot - LOT_MAX - 1) : newlot;
    return Batch(newlot, day, month, year);
}

Batch Batch::operator-(const short int number) const {
    short int newlot = lot - number;
    newlot = (newlot < LOT_MIN) ? (LOT_MIN + newlot + 1) : newlot;
    return Batch(newlot, day, month, year);
}

std::string Batch::getName() {
    return print();
}

Batch Batch::copy() {
    Batch fresh(lot, day, month, year);
    return fresh;
}

void Batch::clear() {
    lot = LOT_MIN;
    day = DateTime::DAY_MIN;
    month = DateTime::MONTH_MIN;
    year = DateTime::YEAR_MIN;
    return;
}

std::string Batch::print() {
    std::stringstream result;
    result << std::setw(Batch::YEAR_WIDTH) << std::setfill(Batch::DELIMITER) << year;
    result << std::setw(Batch::MONTH_WIDTH) << std::setfill(Batch::DELIMITER) << month;
    result << std::setw(Batch::DAY_WIDTH) << std::setfill(Batch::DELIMITER) << day;
    result << std::setw(Batch::LOT_WIDTH) << std::setfill(Batch::DELIMITER) << lot;
	return result.str();
}

} // namespace act