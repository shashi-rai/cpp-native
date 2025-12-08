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

#include "area.h"

namespace shp {

Area::Area() : length(), breadth() {

}

Area::Area(const float length, const float breadth)
        : length(length), breadth(breadth) {

}

Area::Area(const Quantity& length, const Quantity& breadth)
    : length(length), breadth(breadth) {

}

Area::~Area() {

}

bool Area::operator==(const Area& peer) const {
    return (length == peer.length) && (breadth == peer.breadth);
}

Area Area::operator+(const Area& peer) const {
    float realarea = (getTotal() + peer.getTotal());
    std::complex<float> complexarea(realarea, 0.0);
    std::complex<float> part = std::sqrt(complexarea);
    return Area(std::abs(part), std::abs(part));
}

Area Area::operator-(const Area& peer) const {
    float realarea = (getTotal() - peer.getTotal());
    std::complex<float> complexarea(realarea, 0.0);
    std::complex<float> part = std::sqrt(complexarea);
    return Area(std::abs(part), std::abs(part));
}

Area Area::operator*(const Area& peer) const {
    float realarea = (getTotal() * peer.getTotal());
    std::complex<float> complexarea(realarea, 0.0);
    std::complex<float> part = std::sqrt(complexarea);
    return Area(std::abs(part), std::abs(part));
}

Area Area::operator/(const Area& peer) const {
    float realarea = (getTotal() / peer.getTotal());
    std::complex<float> complexarea(realarea, 0.0);
    std::complex<float> part = std::sqrt(complexarea);
    return Area(std::abs(part), std::abs(part));
}

Area Area::operator%(const Area& peer) const {
    float realarea = (fmod(getTotal(), peer.getTotal()));
    std::complex<float> complexarea(realarea, 0.0);
    std::complex<float> part = std::sqrt(complexarea);
    return Area(std::abs(part), std::abs(part));
}

float Area::getTotal() const {
    return (length.getValue() * breadth.getValue());
}

Area Area::copy() {
    Area fresh(length, breadth);
    return fresh;
}

void Area::clear() {
    length.clear();
    breadth.clear();
    return;
}

std::string Area::print() {
    std::stringstream result;
    result << "(l:";
    result << length.print() << ",b:";
    result << breadth.print() << ")";
	return result.str();
}

} // namespace shp