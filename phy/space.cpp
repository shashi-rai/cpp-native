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

#include "space.h"

namespace phy {

Space::Space()
		: qft::Fluid(), location() {

}

Space::Space(const qft::Energy& energy, const Position& location)
        : qft::Fluid(energy), location(location) {

}

Space::Space(const qft::Energy& energy)
		: qft::Fluid(energy), location() {

}

Space::Space(const Position& location)
		: qft::Fluid(), location(location) {

}

Space::Space(const qft::Energy& energy, const double x)
        : qft::Fluid(energy), location(x) {

}

Space::Space(const qft::Energy& energy, const double x, const double y)
        : qft::Fluid(energy), location(x, y) {

}

Space::Space(const qft::Energy& energy, const double x, const double y, const double z)
        : qft::Fluid(energy), location(x, y, z) {

}

Space::~Space() {

}

double Space::getX() const {
    return location.getX();
}

double Space::getY() const {
    return location.getY();
}

double Space::getZ() const {
    return location.getZ();
}

void Space::setX(const double value) {
    this->location.setX(value);
}

void Space::setY(const double value) {
    this->location.setY(value);
}

void Space::setZ(const double value) {
    this->location.setZ(value);
}

Space Space::copy() {
    Space fresh(qft::Fluid::getEnergy(), this->location);
    return fresh;
}

void Space::clear() {
    qft::Fluid::clear();
    location.clear();
    return;
}

std::string Space::print() const {
    std::stringstream result;
    result << "(s:";
	result << qft::Fluid().print() << ",";
    result << location.print() << ")";
	return result.str();
}

std::string Space::printRadians() const {
    std::stringstream result;
    result << "(s:";
	result << qft::Fluid().printRadians() << ",";
    result << location.print() << ")";
	return result.str();
}

} // namespace phy