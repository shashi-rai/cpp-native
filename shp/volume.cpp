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

Volume::Volume(const Unit& unit) : surface(unit), depth(unit) {

}

Volume::Volume(const Area& surface) : surface(surface),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Area& surface, const std::string unit)
    : surface(surface), depth(unit) {

}

Volume::Volume(const Area& surface, const Unit& unit)
    : surface(surface), depth(unit) {

}

Volume::Volume(const Area& surface, const short int scaling, const std::string unit)
    : surface(surface), depth(scaling, unit) {

}

Volume::Volume(const Area& surface, const short int scaling, const Unit& unit)
    : surface(surface), depth(scaling, unit) {

}

Volume::Volume(const Area& surface, const float depth)
        : surface(surface), depth(depth, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Area& surface, const float depth, const std::string unit)
        : surface(surface), depth(depth, unit) {

}

Volume::Volume(const Area& surface, const float depth, const Unit& unit)
        : surface(surface), depth(depth, unit) {

}

Volume::Volume(const Area& surface, const float depth, const short int scaling, const std::string unit)
        : surface(surface), depth(depth, scaling, unit) {

}

Volume::Volume(const Area& surface, const float depth, const short int scaling, const Unit& unit)
        : surface(surface), depth(depth, scaling, unit) {

}

Volume::Volume(const Area& surface, const Signal& depth)
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

Volume::Volume(const float length, const Unit& unit)
        : surface(length, length, unit),
		depth(length, unit) {

}

Volume::Volume(const float length, const short int scaling, const std::string unit)
        : surface(length, length, scaling, unit),
		depth(length, scaling, unit) {

}

Volume::Volume(const float length, const short int scaling, const Unit& unit)
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

Volume::Volume(const float length, const float breadth, const Unit& unit)
        : surface(length, breadth, unit), depth(unit) {

}

Volume::Volume(const float length, const float breadth, const short int scaling, const std::string unit)
        : surface(length, breadth, scaling, unit), depth(scaling, unit) {

}

Volume::Volume(const float length, const float breadth, const short int scaling, const Unit& unit)
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
        const Unit& unit)
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

Volume::Volume(const float length, const float breadth, const float height,
        const short int scaling, const Unit& unit)
        : surface(length, breadth, scaling, unit),
		depth(height, scaling, unit) {

}

Volume::Volume(const Signal& length)
        : surface(length, length), depth(length) {

}

Volume::Volume(const Signal& length, const Signal& breadth)
        : surface(length, breadth),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Signal& length, const Signal& breadth, const Signal& height)
        : surface(length, breadth), depth(height) {

}

Volume::~Volume() {

}

bool Volume::operator==(const Volume& peer) const {
    return (surface == peer.surface) && (depth == peer.depth);
}

bool Volume::operator<(const Volume& peer) const {
    return (surface < peer.surface) && (depth < peer.depth);
}

bool Volume::operator>(const Volume& peer) const {
    return (surface > peer.surface) && (depth > peer.depth);
}

bool Volume::operator<=(const Volume& peer) const {
    Volume self = *this;
    return (self < peer) || (self == peer);
}

bool Volume::operator>=(const Volume& peer) const {
    Volume self = *this;
    return (self > peer) || (self == peer);
}

Volume Volume::operator+(const Volume& peer) const {
	Signal realvolume = (getScalarTotal() + peer.getScalarTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Signal(part, realvolume.getScaling(), surface.getLengthUnit()),
			Signal(part, realvolume.getScaling(), surface.getBreadthUnit()),
			Signal(part, realvolume.getScaling(), depth.getUnit()));
}

Volume Volume::operator-(const Volume& peer) const {
	Signal realvolume = (getScalarTotal() - peer.getScalarTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Signal(part, realvolume.getScaling(), surface.getLengthUnit()),
			Signal(part, realvolume.getScaling(), surface.getBreadthUnit()),
			Signal(part, realvolume.getScaling(), depth.getUnit()));
}

Volume Volume::operator*(const Volume& peer) const {
	Signal realvolume = (getScalarTotal() * peer.getScalarTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Signal(part, realvolume.getScaling(), surface.getLengthUnit()),
			Signal(part, realvolume.getScaling(), surface.getBreadthUnit()),
			Signal(part, realvolume.getScaling(), depth.getUnit()));
}

Volume Volume::operator/(const Volume& peer) const {
	Signal realvolume = (getScalarTotal() / peer.getScalarTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Signal(part, realvolume.getScaling(), surface.getLengthUnit()),
			Signal(part, realvolume.getScaling(), surface.getBreadthUnit()),
			Signal(part, realvolume.getScaling(), depth.getUnit()));
}

Volume Volume::operator%(const Volume& peer) const {
	Signal realvolume = (getScalarTotal() % peer.getScalarTotal());
    float part = std::cbrt(realvolume.getMagnitude());
	realvolume.setScaling(realvolume.getScaling() / SCALING_FACTOR);
    return Volume(Signal(part, realvolume.getScaling(), surface.getLengthUnit()),
			Signal(part, realvolume.getScaling(), surface.getBreadthUnit()),
			Signal(part, realvolume.getScaling(), depth.getUnit()));
}

Signal Volume::getScalarTotal() const {
    Signal volume = (surface.getScalarTotal().getDotProduct(depth));
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getScalarSurfaceTotal() const {
    Signal volume = surface.getScalarTotal();
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getVectorTotal() const {
    Signal volume = (surface.getVectorTotal().getCrossProduct(depth));
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getVectorSurfaceTotal() const {
    Signal volume = surface.getVectorTotal();
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getLengthRotation(const short int degree) const {
    return surface.getLengthRotation(degree);
}

Direction Volume::getLengthPhase() const {
    return surface.getLengthPhase();
}

void Volume::setLengthPhase(const Direction& direction) {
    surface.setBreadthPhase(direction);
}

void Volume::setLength(const float value) {
    surface.setLength(value);
}

void Volume::setLength(const float value, const short int scale) {
    surface.setLength(value, scale);
}

void Volume::setLength(const float value, const short int scale, const std::string unit) {
    surface.setLength(value, scale, unit);
}

Signal Volume::getBreadthRotation(const short int degree) const {
    return surface.getBreadthRotation(degree);
}

Direction Volume::getBreadthPhase() const {
    return surface.getBreadthPhase();
}

void Volume::setBreadthPhase(const Direction& direction) {
    surface.setBreadthPhase(direction);
}

void Volume::setBreadth(const float value) {
    surface.setBreadth(value);
}

void Volume::setBreadth(const float value, const short int scale) {
    surface.setBreadth(value, scale);
}

void Volume::setBreadth(const float value, const short int scale, const std::string unit) {
    surface.setBreadth(value, scale, unit);
}

Signal Volume::getHeight() const {
    return depth;
}

void Volume::setHeight(const Signal& height) {
    this->depth = height;
}

Signal Volume::getHeightRotation(const short int degree) const {
    Azimuth direction(depth.getOrientation());
    Azimuth phase = direction.getRotation(degree);
    return Signal(phase, depth.getMagnitude(), depth.getScaling(), depth.getUnit());
}

Direction Volume::getHeightPhase() const {
    return Direction(depth.getOrientation());
}

void Volume::setHeightPhase(const Direction& direction) {
    depth.setOrientation(direction.toRadians());
}

void Volume::setHeight(const float value) {
    depth.setMagnitude(value);
}

void Volume::setHeight(const float value, const short int scale) {
    depth.setMagnitude(value, scale);
}

void Volume::setHeight(const float value, const short int scale, const std::string unit) {
    depth.setMagnitude(value, scale);
    depth.setUnit(unit);
}

short int Volume::getLengthScaling() const {
    return surface.getLengthScaling();
}

void Volume::setLengthScaling(const short int factor) {
    surface.setLengthScaling(factor);
}

short int Volume::getBreadthScaling() const {
    return surface.getBreadthScaling();
}

void Volume::setBreadthScaling(const short int factor) {
    surface.setBreadthScaling(factor);
}

short int Volume::getHeightScaling() const {
    return depth.getScaling();
}

void Volume::setHeightScaling(const short int factor) {
    depth.setScaling(factor);
}

std::string Volume::getLengthUnit() const {
    return surface.getLengthUnit();
}

void Volume::setLengthUnit(const Unit& object) {
    surface.setLengthUnit(object);
}

std::string Volume::getBreadthUnit() const {
    return surface.getBreadthUnit();
}

void Volume::setBreadthUnit(const Unit& object) {
    surface.setBreadthUnit(object);
}

std::string Volume::getHeightUnit() const {
    return (depth.getUnit().getName());
}

void Volume::setHeightUnit(const Unit& object) {
    depth.setUnit(object);
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

std::string Volume::print() const {
    std::stringstream result;
    result << surface.print() << ",h:";
    result << depth.print();
	return result.str();
}

std::string Volume::printRadians() const {
    std::stringstream result;
    result << surface.printRadians() << ",h:";
    result << depth.printRadians();
	return result.str();
}

Signal Volume::getCosComponent(const float phase) const {
	Signal volume = this->getScalarTotal();
	return Signal(volume.getOrientation(), volume.getCosComponent(phase),
        volume.getScaling(), volume.getUnit());
}

Signal Volume::getSinComponent(const float phase) const {
	Signal volume = this->getScalarTotal();
	return Signal(volume.getOrientation(), volume.getSinComponent(phase),
        volume.getScaling(), volume.getUnit());
}

} // namespace shp