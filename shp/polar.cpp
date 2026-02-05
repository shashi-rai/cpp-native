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

#include "polar.h"

namespace shp {

Polar::Polar()
        : Direction(), shifting(shp::Direction::DEFAULT_RADIANS) {

}

Polar::Polar(const float radians)
        : Direction(radians), shifting(shp::Direction::DEFAULT_RADIANS) {

}

Polar::Polar(const std::complex<float> polar)
        : Direction(polar), shifting(shp::Direction::DEFAULT_RADIANS) {

}

Polar::Polar(const short int degrees)
        : Direction(degrees), shifting(shp::Direction::DEFAULT_RADIANS) {

}

Polar::Polar(const short int degrees, const short int minutes)
        : Direction(degrees, minutes), shifting(shp::Direction::DEFAULT_RADIANS) {

}

Polar::Polar(const short int degrees, const short int minutes, const short int seconds)
        : Direction(degrees, minutes, seconds), shifting(shp::Direction::DEFAULT_RADIANS) {

}

Polar::Polar(const Direction& change)
        : Direction(), shifting(change) {

}

Polar::Polar(const float radians, const Direction& change)
        : Direction(radians), shifting(change) {

}

Polar::Polar(const std::complex<float> polar, const Direction& change)
        : Direction(polar), shifting(change) {

}

Polar::Polar(const short int degrees, const Direction& change)
        : Direction(degrees), shifting(change) {

}

Polar::Polar(const short int degrees, const short int minutes, const Direction& change)
        : Direction(degrees, minutes), shifting(change) {

}

Polar::Polar(const short int degrees, const short int minutes, const short int seconds,
        const Direction& change)
        : Direction(degrees, minutes, seconds), shifting(change) {

}

Polar::~Polar() {

}

bool Polar::operator==(const Polar& peer) const {
    return (static_cast<const Direction&>(*this) == static_cast<const Direction&>(peer))
        && (shifting == peer.shifting);
}

bool Polar::operator<(const Polar& peer) const {
    Polar self = *this; bool result = false;
    if (static_cast<const Direction&>(*this) < static_cast<const Direction&>(peer)) {
        result = true;
    } else if (shifting < peer.shifting) {
        result = true;
    }
    return result;
}

bool Polar::operator>(const Polar& peer) const {
    Polar self = *this; bool result = false;
    if (static_cast<const Direction&>(*this) > static_cast<const Direction&>(peer)) {
        result = true;
    } else if (shifting > peer.shifting) {
        result = true;
    }
    return result;
}

bool Polar::operator<=(const Polar& peer) const {
    Polar self = *this;
    return (self < peer) || (self == peer);
}

bool Polar::operator>=(const Polar& peer) const {
    Polar self = *this;
    return (self > peer) || (self == peer);
}

Polar Polar::operator+(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction polar = (self + other);
    return Polar(polar.getDegrees(), polar.getMinutes(), polar.getSeconds(), shifting);
}

Polar Polar::operator-(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction polar = (self - other);
    return Polar(polar.getDegrees(), polar.getMinutes(), polar.getSeconds(), shifting);
}

Polar Polar::operator*(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction polar = (self * other);
    return Polar(polar.getDegrees(), polar.getMinutes(), polar.getSeconds(), shifting);
}

Polar Polar::operator/(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction polar = (self / other);
    return Polar(polar.getDegrees(), polar.getMinutes(), polar.getSeconds(), shifting);
}

Polar Polar::operator%(const Direction& peer) const {
    Direction self = *this, other = peer;
    Direction polar = (self % other);
    return Polar(polar.getDegrees(), polar.getMinutes(), polar.getSeconds(), shifting);
}

void Polar::setAngleShiftRate(const float degree) {
    this->shifting.setRotation(degree);
}

Direction Polar::getCurrent() const {
    Direction result(Direction::toRadians() + shifting.toRadians());
    return result;
}

Direction Polar::copy() const {
    Direction self = *this;
    Polar fresh(self.getDegrees(), self.getMinutes(), self.getSeconds(), shifting);
    return fresh;
}

void Polar::clear() {
    Direction::clear();
    shifting.clear();
    return;
}

std::string Polar::print() const {
    std::stringstream result;
    result << "𝜃";
    result << Direction::print() << "δ";
	result << shifting.print();
	return result.str();
}

std::string Polar::printRadians() const {
    std::stringstream result;
    result << "𝜃";
    result << Direction::printRadians() << "δ";
	result << shifting.printRadians();
	return result.str();
}

std::string Polar::printEuler() const { 
    std::stringstream result;
    result << "𝜃";
    result << Direction::printEuler() << "δ";
	result << shifting.printEuler();
	return result.str();
}

} // namespace shp