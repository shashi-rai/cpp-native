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

#include "inductance.h"

namespace ecn {

const std::string Inductance::UNIT = "H";

Inductance::Inductance()
        : shp::Quantity(UNIT), threshold() {

}

Inductance::Inductance(const shp::Potential& threshold)
        : shp::Quantity(UNIT), threshold(threshold) {

}

Inductance::Inductance(const float magnitude)
        : shp::Quantity(magnitude, UNIT), threshold() {

}

Inductance::Inductance(const short int scaling)
        : shp::Quantity(scaling, UNIT), threshold() {

}

Inductance::Inductance(const std::string unit)
        : shp::Quantity(unit), threshold() {

}

Inductance::Inductance(const short int scaling, const std::string unit)
        : shp::Quantity(scaling, unit), threshold() {

}

Inductance::Inductance(const shp::Unit& unit)
        : shp::Quantity(unit), threshold() {

}

Inductance::Inductance(const short int scaling, const shp::Unit& unit)
        : shp::Quantity(scaling, unit), threshold() {

}

Inductance::Inductance(const float magnitude, const std::string unit)
        : shp::Quantity(magnitude, unit), threshold() {

}

Inductance::Inductance(const float magnitude, const shp::Unit& unit)
        : shp::Quantity(magnitude, unit), threshold() {

}

Inductance::Inductance(const float magnitude, const short int scaling)
        : shp::Quantity(magnitude, scaling, UNIT), threshold() {

}

Inductance::Inductance(const float magnitude, const short int scaling, const std::string unit)
        : shp::Quantity(magnitude, scaling, unit), threshold() {

}

Inductance::Inductance(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(magnitude, scaling, unit), threshold() {

}

Inductance::Inductance(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& threshold)
        : shp::Quantity(magnitude, scaling, unit), threshold(threshold) {

}

Inductance::~Inductance() {
    threshold.clear();
}

bool Inductance::operator==(const Inductance& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
		&& (threshold == peer.threshold);
}

Inductance Inductance::operator+(const Inductance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity inductance = (self + other);
    return Inductance(inductance.getMagnitude(), inductance.getScaling(), inductance.getUnit(),
        (threshold + peer.threshold));
}

Inductance Inductance::operator-(const Inductance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity inductance = (self - other);
    return Inductance(inductance.getMagnitude(), inductance.getScaling(), inductance.getUnit(),
        (threshold - peer.threshold));
}

Inductance Inductance::operator*(const Inductance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity inductance = (self * other);
    return Inductance(inductance.getMagnitude(), inductance.getScaling(), inductance.getUnit(),
        (threshold * peer.threshold));
}

Inductance Inductance::operator/(const Inductance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity inductance = (self / other);
    return Inductance(inductance.getMagnitude(), inductance.getScaling(), inductance.getUnit(),
        (threshold / peer.threshold));
}

Inductance Inductance::operator%(const Inductance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity inductance = (self % other);
    return Inductance(inductance.getMagnitude(), inductance.getScaling(), inductance.getUnit(),
        (threshold % peer.threshold));
}

Inductance Inductance::copy() {
    Inductance fresh(getMagnitude(), getScaling(), getUnit(), threshold);
    return fresh;
}

void Inductance::clear() {
	shp::Quantity::clear();
    threshold.clear();
    return;
}

std::string Inductance::print() {
    std::stringstream result;
	result << shp::Quantity::print() << ",t:";
    result << threshold.print();
	return result.str();
}

} // namespace ecn