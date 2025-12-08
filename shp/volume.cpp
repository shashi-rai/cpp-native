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

#include "volume.h"

namespace shp {

Volume::Volume() : surface(), height() {

}

Volume::Volume(const Area& surface, const float height)
        : surface(surface), height(height) {

}

Volume::Volume(const Area& surface, const Quantity& height)
        : surface(surface), height(height) {

}

Volume::Volume(const float length, const float breadth, const float height)
        : surface(length, breadth), height(height) {

}

Volume::Volume(const Quantity& length, const Quantity& breadth, const Quantity& height)
        : surface(length, breadth), height(height) {

}

Volume::~Volume() {

}

bool Volume::operator==(const Volume& peer) const {
    return (surface == peer.surface) && (height == peer.height);
}

Volume Volume::operator+(const Volume& peer) const {
    float part = std::cbrt(getTotal() + peer.getTotal());
    return Volume(part, part, part);
}

Volume Volume::operator-(const Volume& peer) const {
    float part = std::cbrt(getTotal() - peer.getTotal());
    return Volume(part, part, part);
}

Volume Volume::operator*(const Volume& peer) const {
    float part = std::cbrt(getTotal() * peer.getTotal());
    return Volume(part, part, part);
}

Volume Volume::operator/(const Volume& peer) const {
    float part = std::cbrt(getTotal() / peer.getTotal());
    return Volume(part, part, part);
}

Volume Volume::operator%(const Volume& peer) const {
    float part = std::cbrt(fmod(getTotal(), peer.getTotal()));
    return Volume(part, part, part);
}

float Volume::getTotal() const {
    return (surface.getTotal() * height.getValue());
}

Volume Volume::copy() {
    Volume fresh(surface.getLength(), surface.getBreadth(), height);
    return fresh;
}

void Volume::clear() {
    surface.clear();
    height.clear();
    return;
}

std::string Volume::print() {
    std::stringstream result;
    result << "{";
    result << surface.print() << ",h:";
    result << height.print() << "}";
	return result.str();
}

} // namespace shp