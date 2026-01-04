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

const std::string Volume::UNIT = "m";			// System International
const short int Volume::SCALING_FACTOR = 2;		// Mathematical Operator

Volume::Volume()
		: surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const std::string unit) : surface(unit), depth(unit) {

}

Volume::Volume(const Area& surface) : surface(surface),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Area& surface, const std::string unit)
    : surface(surface), depth(unit) {

}

Volume::Volume(const Area& surface, const short int scaling, const std::string unit)
    : surface(surface), depth(scaling, unit) {

}

Volume::Volume(const Area& surface, const float depth)
        : surface(surface), depth(depth, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Area& surface, const float depth, const std::string unit)
        : surface(surface), depth(depth, unit) {

}

Volume::Volume(const Area& surface, const float depth, const short int scaling, const std::string unit)
        : surface(surface), depth(depth, scaling, unit) {

}

Volume::Volume(const Area& surface, const Quantity& depth)
        : surface(surface), depth(depth) {

}

Volume::Volume(const float length)
        : surface(length, length),
		depth(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float length, const std::string unit)
        : surface(length, length, unit),
		depth(length, unit) {

}

Volume::Volume(const float length, const short int scaling, const std::string unit)
        : surface(length, length, scaling, unit),
		depth(length, scaling, unit) {

}

Volume::Volume(const float length, const float breadth)
        : surface(length, breadth),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float length, const float breadth, const std::string unit)
        : surface(length, breadth, unit), depth(unit) {

}

Volume::Volume(const float length, const float breadth, const short int scaling, const std::string unit)
        : surface(length, breadth, scaling, unit), depth(scaling, unit) {

}

Volume::Volume(const float length, const float breadth, const float height)
        : surface(length, breadth),
		depth(height, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float length, const float breadth, const float height,
        const std::string unit)
        : surface(length, breadth, unit), depth(height, unit) {

}

Volume::Volume(const float length, const float breadth, const float height,
        const short int scaling)
        : surface(length, breadth, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
		depth(height, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float length, const float breadth, const float height,
        const short int scaling, const std::string unit)
        : surface(length, breadth, scaling, unit),
		depth(height, scaling, unit) {

}

Volume::Volume(const Quantity& length)
        : surface(length, length), depth(length) {

}

Volume::Volume(const Quantity& length, const Quantity& breadth)
        : surface(length, breadth),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

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
	Quantity realvolume = (getTotal() + peer.getTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()));
}

Volume Volume::operator-(const Volume& peer) const {
	Quantity realvolume = (getTotal() - peer.getTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()));
}

Volume Volume::operator*(const Volume& peer) const {
	Quantity realvolume = (getTotal() * peer.getTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()));
}

Volume Volume::operator/(const Volume& peer) const {
	Quantity realvolume = (getTotal() / peer.getTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()));
}

Volume Volume::operator%(const Volume& peer) const {
	Quantity realvolume = (getTotal() % peer.getTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()),
			Quantity(part, realvolume.getScaling(), getUnit()));
}

Quantity Volume::getTotal() const {
    Quantity volume = (surface.getTotal() * depth);
    return Quantity(volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

std::string Volume::getUnit() const {
    return depth.getUnit().getName();
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
    result << surface.print() << ",h:";
    result << depth.print();
	return result.str();
}

Quantity Volume::getComponent(float phase) const {
	Quantity volume = getTotal();
	return Quantity((volume.getMagnitude() * cos(phase)), volume.getScaling(), volume.getUnit());
}

} // namespace shp