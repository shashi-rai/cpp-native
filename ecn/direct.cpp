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

#include "direct.h"

namespace ecn {

Direct::Direct()
        : Source() {

}

Direct::Direct(const Conductor& positive)
        : Source(positive) {

}

Direct::Direct(const Conductor& positive, const Conductor& negative)
        : Source(positive, negative) {

}

Direct::Direct(std::string name)
        : Source(name) {

}

Direct::Direct(std::string name, const Conductor& positive)
        : Source(name, positive) {

}

Direct::Direct(std::string name, const Conductor& positive, const Conductor& negative)
        : Source(name, positive, negative) {

}

Direct::~Direct() {

}

bool Direct::operator==(const Direct& peer) const {
    return (static_cast<const Source&>(*this) == static_cast<const Source&>(peer));
}

Direct Direct::operator+(const Direct& peer) const {
    Source self = *this, other = peer;
    Source source = (self + other);
    return Direct("+", source.getPositive(), source.getNegative());
}

Direct Direct::operator-(const Direct& peer) const {
    Source self = *this, other = peer;
    Source source = (self - other);
    return Direct("-", source.getPositive(), source.getNegative());
}

Direct Direct::operator*(const Direct& peer) const {
    Source self = *this, other = peer;
    Source source = (self * other);
    return Direct("*", source.getPositive(), source.getNegative());
}

Direct Direct::operator/(const Direct& peer) const {
    Source self = *this, other = peer;
    Source source = (self / other);
    return Direct("/", source.getPositive(), source.getNegative());
}

Direct Direct::operator%(const Direct& peer) const {
    Source self = *this, other = peer;
    Source source = (self % other);
    return Direct("%", source.getPositive(), source.getNegative());
}

Direct Direct::copy() {
    Direct fresh(getName(), getPositive(), getNegative());
    return fresh;
}

void Direct::clear() {
    Source::clear();
    return;
}

std::string Direct::print() {
    std::stringstream result;
    result << Source::print();
	return result.str();
}

} // namespace ecn