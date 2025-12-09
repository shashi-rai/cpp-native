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

const std::string Volume::UNIT = "m";       // System International

Volume::Volume() : surface(UNIT), depth(UNIT) {

}

Volume::Volume(const Area& surface) : surface(surface), depth(UNIT) {

}

Volume::Volume(const Area& surface, const std::string unit)
    : surface(surface), depth(unit) {

}

Volume::Volume(const Area& surface, short int scaling, const std::string unit)
    : surface(surface), depth(scaling, unit) {

}

Volume::Volume(const Area& surface, const float depth)
        : surface(surface), depth(depth, UNIT) {

}

Volume::Volume(const Area& surface, const float depth, const std::string unit)
        : surface(surface), depth(depth, unit) {

}

Volume::Volume(const Area& surface, const float depth, short int scaling, const std::string unit)
        : surface(surface), depth(depth, scaling, unit) {

}

Volume::Volume(const Area& surface, const Quantity& depth)
        : surface(surface), depth(depth) {

}

Volume::Volume(const float length)
        : surface(length, length, UNIT), depth(length, UNIT) {

}

Volume::Volume(const float length, const std::string unit)
        : surface(length, length, unit), depth(length, unit) {

}

Volume::Volume(const float length, short int scaling, const std::string unit)
        : surface(length, length, scaling, unit), depth(length, scaling, unit) {

}

Volume::Volume(const float length, const float breadth)
        : surface(length, breadth, UNIT), depth(UNIT) {

}

Volume::Volume(const float length, const float breadth, const std::string unit)
        : surface(length, breadth, unit), depth(unit) {

}

Volume::Volume(const float length, const float breadth, short int scaling, const std::string unit)
        : surface(length, breadth, scaling, unit), depth(scaling, unit) {

}

Volume::Volume(const float length, const float breadth, const float height)
        : surface(length, breadth, UNIT), depth(height, UNIT) {

}

Volume::Volume(const float length, const float breadth, const float height,
        const std::string unit)
        : surface(length, breadth, unit), depth(height, unit) {

}

Volume::Volume(const float length, const float breadth, const float height,
        short int scaling, const std::string unit)
        : surface(length, breadth, scaling, unit), depth(height, scaling, unit) {

}

Volume::Volume(const Quantity& length)
        : surface(length, length), depth(length) {

}

Volume::Volume(const Quantity& length, const Quantity& breadth)
        : surface(length, breadth), depth(UNIT) {

}

Volume::Volume(const Quantity& length, const Quantity& breadth, const Quantity& height)
        : surface(length, breadth), depth(height) {

}

Volume::~Volume() {

}

bool Volume::operator==(const Volume& peer) const {
    return (surface == peer.surface) && (depth == peer.depth);
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
    return (surface.getTotal() * depth.getValue());
}

std::string Volume::getUnit() const {
    return depth.getUnit().getName() + "^3";
}

Volume Volume::copy() {
    Volume fresh(surface.getLength(), surface.getBreadth(), depth);
    return fresh;
}

void Volume::clear() {
    surface.clear();
    depth.clear();
    return;
}

std::string Volume::print() {
    std::stringstream result;
    result << "{";
    result << surface.print() << ",h:";
    result << depth.print() << "}";
	return result.str();
}

float Volume::getComponent(float phase) const {
    return getTotal() * cos(phase);
}

} // namespace shp