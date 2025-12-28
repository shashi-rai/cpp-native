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

#include "orbit.h"

namespace grt {

Orbit::Orbit() : Shape(), major(), minor() {

}

Orbit::Orbit(std::string name) : Shape(name), major(), minor() {

}

Orbit::Orbit(const shp::Distance& major)
        : Shape(), major(major), minor() {

}

Orbit::Orbit(const shp::Distance& major, const shp::Distance& minor)
        : Shape(), major(major), minor(minor) {

}

Orbit::Orbit(std::string name, const shp::Distance& major)
        : Shape(name), major(major), minor() {

}

Orbit::Orbit(std::string name, const shp::Distance& major, const shp::Distance& minor)
        : Shape(name), major(major), minor(minor) {

}

Orbit::~Orbit() {

}

float Orbit::getEccentricity() const {
    return shp::Quantity::DEFAULT_VALUE;
}

float Orbit::getRotation() const {
    return shp::Quantity::DEFAULT_VALUE;
}

void Orbit::setRotation(const float value) {
    return;
}

float Orbit::getRevolution() const {
    return shp::Quantity::DEFAULT_VALUE;
}

void Orbit::setRevolution(const float value) {
    return;
}

Orbit Orbit::copy() {
    Orbit fresh(getName(), major, minor);
    return fresh;
}

void Orbit::clear() {
	Shape::clear();
	major.clear();
    minor.clear();
    return;
}

std::string Orbit::print() {
    std::stringstream result;
    result << "(O:";
	result << Shape::print() << ",l:";
    result << major.print() << ",b:";
	result << minor.print() << ")";
	return result.str();
}

} // namespace grt