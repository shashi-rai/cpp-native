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

DateTime::DateTime() : value(getCurrent()) {

}

DateTime::DateTime(const long value) : value(value) {

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
    result << value;
	return result.str();
}

const long DateTime::getCurrent() {
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    long ms_since_epoch = duration.count();
    return ms_since_epoch;
}

} // namespace act