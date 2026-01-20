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

#include "coordinate.h"

namespace shp {

const float Coordinate::ORIGIN = 0.0f;
const float Coordinate::DEFAULT_VALUE = 0.0f;
const float Coordinate::UNIT_MAGNITUDE = 1e-9;

Coordinate::Coordinate()
        : x(ORIGIN), y(ORIGIN), z(ORIGIN) {

}

Coordinate::Coordinate(const float x)
        : x(x), y(ORIGIN), z(ORIGIN) {

}

Coordinate::Coordinate(const float x, const float y)
        : x(x), y(y), z(ORIGIN) {

}

Coordinate::Coordinate(const float x, const float y, const float z)
        : x(x), y(y), z(z) {

}

Coordinate::~Coordinate() {

}

bool Coordinate::operator==(const Coordinate& peer) const {
    return (x == peer.x) && (y == peer.y) && (z == peer.z);
}

Coordinate Coordinate::operator+(const Coordinate& peer) const {
    return Coordinate((x + peer.x), (y + peer.y), (z + peer.z));
}

Coordinate Coordinate::operator-(const Coordinate& peer) const {
    return Coordinate((x - peer.x), (y - peer.y), (z - peer.z));
}

Coordinate Coordinate::operator*(const Coordinate& peer) const {
    return Coordinate((x * peer.x), (y * peer.y), (z * peer.z));
}

Coordinate Coordinate::operator/(const Coordinate& peer) const {
    return Coordinate((x / peer.x), (y / peer.y), (z / peer.z));
}

Coordinate Coordinate::operator%(const Coordinate& peer) const {
    return Coordinate(fmod(x, peer.x), fmod(y, peer.y), fmod(z, peer.z));
}

float Coordinate::getMagnitude() const {
    return std::sqrt(((x * x) + (y * y) + (z * z)));
}

Coordinate Coordinate::getNormalize() const {
    float magnitude = getMagnitude();
    if (magnitude < UNIT_MAGNITUDE) {
        return Coordinate((x / magnitude), (y / magnitude), (z / magnitude));
    }
    return Coordinate(ORIGIN, ORIGIN, ORIGIN);;
}

Coordinate Coordinate::getField(const float intensity, const float conservable,
        const Coordinate& origin, const Coordinate& poi) const {
    Coordinate radial_vector = (origin - poi);
    float distance = radial_vector.getMagnitude();
    if (distance < UNIT_MAGNITUDE) {
        return Coordinate(ORIGIN, ORIGIN, ORIGIN);
    }
    float field_magnitude = (intensity * (std::abs(conservable) / (distance * distance)));
    Coordinate unit_vector = radial_vector.getNormalize();
    if (conservable < DEFAULT_VALUE) {
        field_magnitude *= -1; // sign reversal
    }
    Coordinate result = Coordinate((field_magnitude * unit_vector.x),
        (field_magnitude * unit_vector.y), (field_magnitude * unit_vector.z));
    return result;
}

Coordinate Coordinate::shiftX(const float step) const {
    return Coordinate((x + step), y, z);
}

Coordinate Coordinate::shiftY(const float step) const {
    return Coordinate(x, (y + step), z);
}

Coordinate Coordinate::shiftZ(const float step) const {
    return Coordinate(x, y, (z + step));
}

Coordinate Coordinate::copy() {
    Coordinate fresh(x, y, z);
    return fresh;
}

void Coordinate::clear() {
    x = y = z = ORIGIN;
    return;
}

std::string Coordinate::print() const {
    std::stringstream result;
    result << "(";
    result << x << ",";
    result << y << ",";
    result << z << ")";
	return result.str();
}

} // namespace shp