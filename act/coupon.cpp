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

#include "coupon.h"

namespace act {

Coupon::Coupon() : Interest(), datetime() {

}

Coupon::Coupon(std::string name)
        : Interest(name), datetime() {

}

Coupon::Coupon(const DateTime& datetime)
        : Interest(), datetime(datetime) {

}

Coupon::Coupon(std::string name, const DateTime& datetime)
        : Interest(name), datetime(datetime) {

}

Coupon::~Coupon() {

}

bool Coupon::operator==(const Coupon& peer) const {
    return (static_cast<const Interest&>(*this) == static_cast<const Interest&>(peer))
            && (datetime == peer.datetime);
}

Coupon Coupon::operator+(const Coupon& peer) const {
    return Coupon("+", (datetime + peer.datetime));
}

Coupon Coupon::operator-(const Coupon& peer) const {
    return Coupon("-", (datetime - peer.datetime));
}

Coupon Coupon::operator*(const Coupon& peer) const {
    return Coupon("*", (datetime * peer.datetime));
}

Coupon Coupon::operator/(const Coupon& peer) const {
    return Coupon("/", (datetime / peer.datetime));
}

Coupon Coupon::operator%(const Coupon& peer) const {
    return Coupon("%", (datetime % peer.datetime));
}

Interest Coupon::copy() {
    Coupon fresh(getName(), datetime);
    return fresh;
}

void Coupon::clear() {
    Interest::clear();
    datetime.clear();
    return;
}

std::string Coupon::print() {
    std::stringstream result;
    result << Interest::print() << ",";
    result << datetime.print();
	return result.str();
}

} // namespace act