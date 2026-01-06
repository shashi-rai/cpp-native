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

#include "reluctance.h"

namespace ecn {

const std::string Reluctance::UNIT = "At/Wb";

Reluctance::Reluctance()
        : shp::Quantity(UNIT), threshold() {

}

Reluctance::Reluctance(const shp::Potential& threshold)
        : shp::Quantity(UNIT), threshold(threshold) {

}

Reluctance::Reluctance(const float magnitude)
        : shp::Quantity(magnitude, UNIT), threshold() {

}

Reluctance::Reluctance(const short int scaling)
        : shp::Quantity(scaling, UNIT), threshold() {

}

Reluctance::Reluctance(const std::string unit)
        : shp::Quantity(unit), threshold() {

}

Reluctance::Reluctance(const short int scaling, const std::string unit)
        : shp::Quantity(scaling, unit), threshold() {

}

Reluctance::Reluctance(const shp::Unit& unit)
        : shp::Quantity(unit), threshold() {

}

Reluctance::Reluctance(const short int scaling, const shp::Unit& unit)
        : shp::Quantity(scaling, unit), threshold() {

}

Reluctance::Reluctance(const float magnitude, const std::string unit)
        : shp::Quantity(magnitude, unit), threshold() {

}

Reluctance::Reluctance(const float magnitude, const shp::Unit& unit)
        : shp::Quantity(magnitude, unit), threshold() {

}

Reluctance::Reluctance(const float magnitude, const short int scaling)
        : shp::Quantity(magnitude, scaling, UNIT), threshold() {

}

Reluctance::Reluctance(const float magnitude, const short int scaling, const std::string unit)
        : shp::Quantity(magnitude, scaling, unit), threshold() {

}

Reluctance::Reluctance(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(magnitude, scaling, unit), threshold() {

}

Reluctance::Reluctance(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& threshold)
        : shp::Quantity(magnitude, scaling, unit), threshold(threshold) {

}

Reluctance::~Reluctance() {
    threshold.clear();
}

bool Reluctance::operator==(const Reluctance& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (threshold == peer.threshold);
}

Reluctance Reluctance::operator+(const Reluctance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity reluctance = (self + other);
    return Reluctance(reluctance.getMagnitude(), reluctance.getScaling(), reluctance.getUnit(),
        (threshold + peer.threshold));
}

Reluctance Reluctance::operator-(const Reluctance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity reluctance = (self - other);
    return Reluctance(reluctance.getMagnitude(), reluctance.getScaling(), reluctance.getUnit(),
        (threshold - peer.threshold));
}

Reluctance Reluctance::operator*(const Reluctance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity reluctance = (self * other);
    return Reluctance(reluctance.getMagnitude(), reluctance.getScaling(), reluctance.getUnit(),
        (threshold * peer.threshold));
}

Reluctance Reluctance::operator/(const Reluctance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity reluctance = (self / other);
    return Reluctance(reluctance.getMagnitude(), reluctance.getScaling(), reluctance.getUnit(),
        (threshold / peer.threshold));
}

Reluctance Reluctance::operator%(const Reluctance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity reluctance = (self % other);
    return Reluctance(reluctance.getMagnitude(), reluctance.getScaling(), reluctance.getUnit(),
        (threshold % peer.threshold));
}

Reluctance Reluctance::copy() {
    Reluctance fresh(getMagnitude(), getScaling(), getUnit(), threshold);
    return fresh;
}

void Reluctance::clear() {
    shp::Quantity::clear();
    threshold.clear();
    return;
}

std::string Reluctance::print() {
    std::stringstream result;
    result << shp::Quantity::print() << ",";
    result << threshold.print();
	return result.str();
}

} // namespace ecn