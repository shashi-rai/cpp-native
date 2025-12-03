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

const double Position::ORIGIN = 0.0;        // 0.0 - Point of Origin

Position::Position() : x(ORIGIN), y(ORIGIN), z(ORIGIN) {

}

Position::Position(double x)
        : x(x), y(ORIGIN), z(ORIGIN) {

}

Position::Position(double x, double y)
        : x(x), y(y), z(ORIGIN) {

}

Position::Position(double x, double y, double z)
        : x(x), y(y), z(z) {

}

Position::~Position() {

}

bool Position::operator==(const Position& peer) const {
    return ((x == peer.x) && (y == peer.y) && (z == peer.z));
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

Position Position::copy() {
    Position fresh(x, y, z);
    return fresh;
}

void Position::clear() {
    x = y = z = ORIGIN;
    return;
}

std::string Position::print() {
    std::stringstream result;
    result << "(";
    result << x << ",";
	result << y << ",";
    result << z << ")";
	return result.str();
}

} // namespace phy