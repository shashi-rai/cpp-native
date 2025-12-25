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

#include "datetime.h"

namespace act {

const long DateTime::DEFAULT_VALUE = 0L;
const short int DateTime::YEAR_BASE = 1900;
const short int DateTime::YEAR_MIN = 0;
const short int DateTime::YEAR_MAX = 99;
const short int DateTime::MONTH_MIN = 1;
const short int DateTime::MONTH_MAX = 12;
const short int DateTime::DAY_MIN = 1;
const short int DateTime::DAY_MAX = 31;
const short int DateTime::HOUR_MIN = 0;
const short int DateTime::HOUR_MAX = 24;
const short int DateTime::MINUTE_MIN = 0;
const short int DateTime::MINUTE_MAX = 60;
const short int DateTime::SECOND_MIN  = 0;
const short int DateTime::SECOND_MAX = 60;

DateTime::DateTime() : value(getSystem()) {

}

DateTime::DateTime(const std::time_t value) : value(value) {

}

DateTime::~DateTime() {

}

bool DateTime::operator==(const DateTime& peer) const {
    return (value == peer.value);
}

DateTime DateTime::operator+(const DateTime& peer) const {
    return DateTime((value + peer.value));
}

DateTime DateTime::operator-(const DateTime& peer) const {
    return DateTime((value - peer.value));
}

DateTime DateTime::operator*(const DateTime& peer) const {
    return DateTime((value * peer.value));
}

DateTime DateTime::operator/(const DateTime& peer) const {
    return DateTime((value / peer.value));
}

DateTime DateTime::operator%(const DateTime& peer) const {
    return DateTime((value % peer.value));
}

const int DateTime::getYear() {
    std::tm* local_tm = std::localtime(&value);
    return (YEAR_BASE + local_tm->tm_year);
}

const int DateTime::getMonth() {
    std::tm* local_tm = std::localtime(&value);
    return (MONTH_MIN + local_tm->tm_mon);
}

const int DateTime::getDay() {
    std::tm* local_tm = std::localtime(&value);
    return (local_tm->tm_mday);
}

const int DateTime::getHour() {
    std::tm* local_tm = std::localtime(&value);
    return (local_tm->tm_hour);
}

const int DateTime::getMinute() {
    std::tm* local_tm = std::localtime(&value);
    return (local_tm->tm_min);
}

const int DateTime::getSecond() {
    std::tm* local_tm = std::localtime(&value);
    return (local_tm->tm_sec);
}

const long long DateTime::getCurrent() {
    return static_cast<long long>(value);
}

const std::chrono::seconds DateTime::getSeconds() {
    std::chrono::seconds result(value);
    return result;
}

const long long DateTime::getMilliseconds() {
    std::chrono::milliseconds result =
        std::chrono::duration_cast<std::chrono::milliseconds>(getSeconds());
    return result.count();
}

const long long DateTime::getNanoseconds() {
    std::chrono::nanoseconds result =
        std::chrono::duration_cast<std::chrono::nanoseconds>(getSeconds());
    return result.count();
}

DateTime DateTime::copy() {
    DateTime fresh(value);
    return fresh;
}

void DateTime::clear() {
    value = DEFAULT_VALUE;
    return;
}

std::string DateTime::print() {
    std::stringstream result;
    result << std::put_time(std::localtime(&value), "[%Y-%m-%d %H:%M:%S]");
	return result.str();
}

const std::time_t DateTime::getSystem() {
    return std::time(nullptr);
}

/*
// datetime: "1976-09-15 07:30:00"
// format : "%Y-%m-%d %H:%M:%S"
*/
const std::time_t DateTime::getFormat(const std::string& datetime, const std::string& format) {
    std::tm time = {}; std::istringstream stream(datetime);
    stream >> std::get_time(&time, format.c_str());
    if (stream.fail()) {
        return -1;
    }
    return std::mktime(&time);
}

} // namespace act