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

#include "angular.h"

namespace shp {

Angular::Angular() : radius(), polar(), azimuthal() {

}

Angular::Angular(int radius) : radius(radius), polar(), azimuthal() {

}

Angular::Angular(int radius, Direction& azimuthal)
		: radius(radius), polar(), azimuthal(azimuthal) {

}

Angular::Angular(int radius, Direction& polar, Direction& azimuthal)
		: radius(radius), polar(polar), azimuthal(azimuthal) {

}

Angular::~Angular() {

}

bool Angular::operator==(const Angular& peer) const {
    return (radius == peer.radius) &&
            (polar == peer.polar) &&
            (azimuthal == peer.azimuthal);
}

Angular Angular::operator+(const Angular& peer) const {
    Direction newPolar = polar + peer.polar;
    Direction newAzimuthal = azimuthal + peer.azimuthal;
    return Angular((radius + peer.radius), newPolar, newAzimuthal);
}

Angular Angular::operator-(const Angular& peer) const {
    Direction newPolar = polar - peer.polar;
    Direction newAzimuthal = azimuthal - peer.azimuthal;
    return Angular((radius - peer.radius), newPolar, newAzimuthal);
}

Angular Angular::copy() {
    Angular fresh(radius, polar, azimuthal);
    return fresh;
}

void Angular::clear() {
    radius = 0; polar = 0; azimuthal = 0;
    return;
}

std::string Angular::print() {
    std::stringstream result;
    result << "{r:";
    result << radius << ",𝜃:";
    result << polar.print() << ",𝜙:";
    result << azimuthal.print() << "}";
	return result.str();
}

} // namespace shp