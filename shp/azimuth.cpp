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

#include "azimuth.h"

namespace shp {

Azimuth::Azimuth()
        : Direction(), change(shp::Direction::DEFAULT_RADIANS) {

}

Azimuth::Azimuth(const float radians)
        : Direction(radians), change(shp::Direction::DEFAULT_RADIANS) {

}

Azimuth::Azimuth(const short int degrees)
        : Direction(degrees), change(shp::Direction::DEFAULT_RADIANS) {

}

Azimuth::Azimuth(const short int degrees, const short int minutes)
        : Direction(degrees, minutes), change(shp::Direction::DEFAULT_RADIANS) {

}

Azimuth::Azimuth(const short int degrees, const short int minutes, const short int seconds)
        : Direction(degrees, minutes, seconds), change(shp::Direction::DEFAULT_RADIANS) {

}

Azimuth::Azimuth(const Direction& change)
        : Direction(), change(change) {

}

Azimuth::Azimuth(const float radians, const Direction& change)
        : Direction(radians), change(change) {

}

Azimuth::Azimuth(const short int degrees, const Direction& change)
        : Direction(degrees), change(change) {

}

Azimuth::Azimuth(const short int degrees, const short int minutes, const Direction& change)
        : Direction(degrees, minutes), change(change) {

}

Azimuth::Azimuth(const short int degrees, const short int minutes, const short int seconds,
        const Direction& change)
        : Direction(degrees, minutes, seconds), change(change) {

}

Azimuth::~Azimuth() {

}

bool Azimuth::operator==(const Azimuth& peer) const {
    return (static_cast<const Direction&>(*this) == static_cast<const Direction&>(peer))
        && (change == peer.change);
}

Azimuth Azimuth::operator+(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction azimuth = (self + other);
    return Azimuth(azimuth.getDegrees(), azimuth.getMinutes(), azimuth.getSeconds(), change);
}

Azimuth Azimuth::operator-(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction azimuth = (self - other);
    return Azimuth(azimuth.getDegrees(), azimuth.getMinutes(), azimuth.getSeconds(), change);
}

Azimuth Azimuth::operator*(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction azimuth = (self * other);
    return Azimuth(azimuth.getDegrees(), azimuth.getMinutes(), azimuth.getSeconds(), change);
}

Azimuth Azimuth::operator/(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction azimuth = (self / other);
    return Azimuth(azimuth.getDegrees(), azimuth.getMinutes(), azimuth.getSeconds(), change);
}

Azimuth Azimuth::operator%(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction azimuth = (self % other);
    return Azimuth(azimuth.getDegrees(), azimuth.getMinutes(), azimuth.getSeconds(), change);
}

Direction Azimuth::copy() const {
    Direction self = *this;
    Azimuth fresh(self.getDegrees(), self.getMinutes(), self.getSeconds(), change);
    return fresh;
}

void Azimuth::clear() {
    Direction::clear();
    change.clear();
    return;
}

std::string Azimuth::print() {
    std::stringstream result;
    result << "𝜙";
    result << Direction::print() << "δ";
	result << change.print();
	return result.str();
}

} // namespace shp