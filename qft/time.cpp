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

#include "time.h"

namespace qft {

Time::Time() : unit(), quantity(0L) {

}

Time::Time(long time) : unit(), quantity(time) {

}

Time::Time(long quantity, const shp::Unit& unit) : unit(unit), quantity(quantity) {

}

Time::~Time() {

}

bool Time::operator==(const Time& peer) const {
    return (unit == peer.unit) && (quantity == peer.quantity);
}

Time Time::operator+(const Time& peer) const {
    return Time(quantity + peer.quantity);
}

Time Time::operator-(const Time& peer) const {
    return Time(quantity - peer.quantity);
}

Time Time::copy() {
    Time fresh(quantity, unit);
    return fresh;
}

void Time::clear() {
    unit.clear();
    quantity = 0L;
    return;
}

std::string Time::print() {
    std::stringstream result;
    result << "(t:";
    result << quantity;
    result << unit.print() << ")";
	return result.str();
}

} // namespace qft