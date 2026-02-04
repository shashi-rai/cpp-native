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
		: shp::Medium(), energy(), location() {

}

Space::Space(const qft::Energy& energy, const Position& location)
        : shp::Medium(), energy(energy), location(location) {

}

Space::Space(const qft::Energy& energy)
		: shp::Medium(), energy(energy), location() {

}

Space::Space(const Position& location)
		: shp::Medium(), energy(), location(location) {

}

Space::Space(const qft::Energy& energy, const double x)
        : shp::Medium(), energy(energy), location(x) {

}

Space::Space(const qft::Energy& energy, const double x, const double y)
        : shp::Medium(), energy(energy), location(x, y) {

}

Space::Space(const qft::Energy& energy, const double x, const double y, const double z)
        : shp::Medium(), energy(energy), location(x, y, z) {

}

Space::~Space() {

}

shp::Distance Space::copy() {
    Space fresh(energy, location);
    return fresh;
}

void Space::clear() {
    energy.clear();
    location.clear();
    return;
}

std::string Space::print() {
    std::stringstream result;
    result << "(s:";
	result << shp::Medium().print() << ",";
    result << energy.print() << "!";
    result << location.print() << ")";
	return result.str();
}

} // namespace phy