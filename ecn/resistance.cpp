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

#include "resistance.h"

namespace ecn {

const std::string Resistance::UNIT = "Ω";

Resistance::Resistance()
        : shp::Quantity(UNIT), threshold() {

}

Resistance::Resistance(const shp::Potential& threshold)
        : shp::Quantity(UNIT), threshold(threshold) {

}

Resistance::Resistance(const float magnitude)
        : shp::Quantity(magnitude, UNIT), threshold() {

}

Resistance::Resistance(const short int scaling)
        : shp::Quantity(scaling, UNIT), threshold() {

}

Resistance::Resistance(const std::string unit)
        : shp::Quantity(unit), threshold() {

}

Resistance::Resistance(const short int scaling, const std::string unit)
        : shp::Quantity(scaling, unit), threshold() {

}

Resistance::Resistance(const shp::Unit& unit)
        : shp::Quantity(unit), threshold() {

}

Resistance::Resistance(const short int scaling, const shp::Unit& unit)
        : shp::Quantity(scaling, unit), threshold() {

}

Resistance::Resistance(const float magnitude, const std::string unit)
        : shp::Quantity(magnitude, unit), threshold() {

}

Resistance::Resistance(const float magnitude, const shp::Unit& unit)
        : shp::Quantity(magnitude, unit), threshold() {

}

Resistance::Resistance(const float magnitude, const short int scaling)
        : shp::Quantity(magnitude, scaling, UNIT), threshold() {

}

Resistance::Resistance(const float magnitude, const short int scaling, const std::string unit)
        : shp::Quantity(magnitude, scaling, unit), threshold() {

}

Resistance::Resistance(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(magnitude, scaling, unit), threshold() {

}

Resistance::Resistance(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& threshold)
        : shp::Quantity(magnitude, scaling, unit), threshold(threshold) {

}

Resistance::~Resistance() {
    threshold.clear();
}

bool Resistance::operator==(const Resistance& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (threshold == peer.threshold);
}

Resistance Resistance::operator+(const Resistance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity resistance = (self + other);
    return Resistance(resistance.getMagnitude(), resistance.getScaling(), resistance.getUnit(),
        (threshold + peer.threshold));
}

Resistance Resistance::operator-(const Resistance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity resistance = (self - other);
    return Resistance(resistance.getMagnitude(), resistance.getScaling(), resistance.getUnit(),
        (threshold - peer.threshold));
}

Resistance Resistance::operator*(const Resistance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity resistance = (self * other);
    return Resistance(resistance.getMagnitude(), resistance.getScaling(), resistance.getUnit(),
        (threshold * peer.threshold));
}

Resistance Resistance::operator/(const Resistance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity resistance = (self / other);
    return Resistance(resistance.getMagnitude(), resistance.getScaling(), resistance.getUnit(),
        (threshold / peer.threshold));
}

Resistance Resistance::operator%(const Resistance& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity resistance = (self % other);
    return Resistance(resistance.getMagnitude(), resistance.getScaling(), resistance.getUnit(),
        (threshold % peer.threshold));
}

Resistance Resistance::copy() {
    Resistance fresh(getMagnitude(), getScaling(), getUnit(), threshold);
    return fresh;
}

void Resistance::clear() {
    shp::Quantity::clear();
    threshold.clear();
    return;
}

std::string Resistance::print() {
    std::stringstream result;
    result << shp::Quantity::print() << ",t:";
    result << threshold.print();
	return result.str();
}

} // namespace ecn