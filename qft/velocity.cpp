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

#include "velocity.h"

namespace qft {

const std::string Velocity::UNIT = "m/s";

Velocity::Velocity() : name(), unit(UNIT), magnitude(), direction() {

}

Velocity::Velocity(std::string name) : name(name), unit(UNIT),
        magnitude(), direction() {

}

Velocity::Velocity(const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(), unit(UNIT), magnitude(magnitude), direction(direction) {

}

Velocity::Velocity(std::string name, const shp::Unit& unit) : name(name), unit(unit),
        magnitude(), direction() {

}

Velocity::Velocity(std::string name, const shp::Unit& unit,
        const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(name), unit(unit), magnitude(magnitude), direction(direction) {

}

Velocity::Velocity(std::string name,
        const shp::Quantity& magnitude, const shp::Direction& direction)
        : name(name), unit(UNIT), magnitude(magnitude), direction(direction) {

}

Velocity::~Velocity() {

}

bool Velocity::operator==(const Velocity& peer) const {
    return (magnitude == peer.magnitude) && (direction == peer.direction);
}

Velocity Velocity::operator+(const Velocity& peer) const {
    return Velocity("+", (magnitude + peer.magnitude), (direction + peer.direction));
}

Velocity Velocity::operator-(const Velocity& peer) const {
    return Velocity("-", (magnitude - peer.magnitude), (direction - peer.direction));
}

Velocity Velocity::operator*(const Velocity& peer) const {
    return Velocity("*", (magnitude * peer.magnitude), (direction * peer.direction));
}

Velocity Velocity::operator/(const Velocity& peer) const {
    return Velocity("/", (magnitude / peer.magnitude), (direction / peer.direction));
}

Velocity Velocity::operator%(const Velocity& peer) const {
    return Velocity("%", (magnitude % peer.magnitude), (direction % peer.direction));
}

float Velocity::getTotal() const {
    float result = (magnitude.getValue() * direction.toRadians());
    return result;
}

Velocity Velocity::copy() {
    Velocity fresh(name, unit, magnitude, direction);
    return fresh;
}

void Velocity::clear() {
	name = "";
    unit.clear();
    magnitude.clear();
    direction.clear();
    return;
}

std::string Velocity::print() {
    std::stringstream result;
    result << "[v:";
	result << name << ",";
    result << magnitude.print() << ",";
	result << direction.print() << " ";
    result << unit.print() << "]";
	return result.str();
}

} // namespace qft