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

#include "point.h"

namespace shp {

Point::Point() : Shape(), amplitude(0.0), gradient(0.0f) {

}

Point::Point(std::string name) : Shape(name), amplitude(0.0), gradient(0.0f) {

}

Point::Point(std::string name, float gradient)
        : Shape(name), amplitude(0.0), gradient(gradient) {

}

Point::Point(std::string name, double amplitude, float gradient)
        : Shape(name), amplitude(amplitude), gradient(gradient) {

}

Point::~Point() {

}

bool Point::operator==(const Point& peer) const {
    return (static_cast<const Shape&>(*this) == static_cast<const Shape&>(peer))
        && (amplitude == peer.amplitude) && (gradient == peer.gradient);
}

Angular Point::getOrientation() const {
    Direction azimuth(gradient);
    Angular result(0, azimuth);
    return result;
}

void Point::clear() {
    Shape::clear();
	amplitude = 0.0; gradient = 0.0f;
    return;
}

std::string Point::print() {
    std::stringstream result;
    result << "{";
	result << Shape::print() << ",a:";
    result << amplitude << ",g:";
	result << gradient << "}";
	return result.str();
}

} // namespace shp