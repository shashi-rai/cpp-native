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

#include "position.h"

namespace phy {

const double Position::ORIGIN = 0.0;                // 0.0 - Point of Origin
const double Position::DEGREE_QUADRANT_1 = 90.0;
const double Position::DEGREE_QUADRANT_2 = 180.0;
const double Position::DEGREE_QUADRANT_3 = 270.0;
const double Position::DEGREE_QUADRANT_4 = 360.0;

Position::Position()
        : x(Position::ORIGIN), y(Position::ORIGIN), z(Position::ORIGIN) {

}

Position::Position(const double x)
        : x(x), y(Position::ORIGIN), z(Position::ORIGIN) {

}

Position::Position(const double x, const double y)
        : x(x), y(y), z(Position::ORIGIN) {

}

Position::Position(const double x, const double y, const double z)
        : x(x), y(y), z(z) {

}

Position::~Position() {

}

bool Position::operator==(const Position& peer) const {
    return ((x == peer.x) && (y == peer.y) && (z == peer.z));
}

bool Position::operator<(const Position& peer) const {
    Position self = *this; bool result = false;   
    if (x < peer.x) {
        result = true;
    }
    if (y < peer.y) {
        result = true;
    }
    if (z < peer.z) {
        result = true;
    }
    return result;
}

bool Position::operator>(const Position& peer) const {
    Position self = *this; bool result = false;
    if (x > peer.x) {
        result = true;
    }
    if (y > peer.y) {
        result = true;
    }
    if (z > peer.z) {
        result = true;
    }
    return result;
}

bool Position::operator<=(const Position& peer) const {
    Position self = *this;
    return (self < peer) || (self == peer);
}

bool Position::operator>=(const Position& peer) const {
    Position self = *this;
    return (self > peer) || (self == peer);
}

Position Position::operator+(const Position& peer) const {
    return Position((x + peer.x), (y + peer.y), (z + peer.z));
}

Position Position::operator-(const Position& peer) const {
    return Position((x - peer.x), (y - peer.y), (z - peer.z));
}

Position Position::operator*(const Position& peer) const {
    return Position((x * peer.x), (y * peer.y), (z * peer.z));
}

Position Position::operator/(const Position& peer) const {
    return Position((x / peer.x), (y / peer.y), (z / peer.z));
}

Position Position::operator%(const Position& peer) const {
    double newx = fmod(x, peer.x);
    double newy = fmod(y, peer.y);
    double newz = fmod(z, peer.z);
    return Position(newx, newy, newz);
}

double Position::getDiagonal() const {
    return std::sqrt((x * x) + (y * y) + (z * z));
}

Position Position::copy() {
    Position fresh(x, y, z);
    return fresh;
}

void Position::clear() {
    x = y = z = Position::ORIGIN;
    return;
}

std::string Position::print() const {
    std::stringstream result;
    result << "(";
    result << std::setfill('0') << std::setprecision(10);
    result << x << ",";
	result << y << ",";
    result << z << ")";
	return result.str();
}

const long double Position::getPiValue() {
    return 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095;
}

const long double Position::toRadians(long double degree) {
    return (degree * Position::getPiValue()) / Position::DEGREE_QUADRANT_2;
}

const double Position::getAzimuthAngle(const Position& a, const Position& b) {
    return fmod(Position::DEGREE_QUADRANT_1 - getAzimuthDegrees(a, b) + Position::DEGREE_QUADRANT_4,
        Position::DEGREE_QUADRANT_4);
}

const double Position::getPolarAngle(const Position& a, const Position& b) {
    return fmod(Position::DEGREE_QUADRANT_1 - getPolarDegrees(a, b) + Position::DEGREE_QUADRANT_4,
        Position::DEGREE_QUADRANT_4);
}

const double Position::getAzimuthRadians(const Position& a, const Position& b) {
    return std::atan2((b.y - a.y), (b.x - a.x));
}

const double Position::getPolarRadians(const Position& a, const Position& b) {
    return std::atan2((b.z - a.z), (b.x - a.x));
}

const double Position::getAzimuthDegrees(const Position& a, const Position& b) {
    return (getAzimuthDegrees(a, b) * (Position::DEGREE_QUADRANT_2 / M_PI));
}

const double Position::getPolarDegrees(const Position& a, const Position& b) {
    return (getPolarDegrees(a, b) * (Position::DEGREE_QUADRANT_2 / M_PI));
}

} // namespace phy