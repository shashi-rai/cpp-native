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

const std::string Volume::UNIT = "m³";          // System International
const short int Volume::SCALING_FACTOR = 2;		// Mathematical Operator

Volume::Volume()
		: Quantity(UNIT),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const std::string unit)
        : Quantity(unit),
        surface(unit), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Unit& unit)
        : Quantity(unit),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude)
        : Quantity(magnitude, UNIT),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const std::string unit)
        : Quantity(magnitude, unit),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const Unit& unit)
        : Quantity(magnitude, unit),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling)
        : Quantity(magnitude, scaling, UNIT),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const std::string unit)
        : Quantity(magnitude, scaling, unit),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const Unit& unit)
        : Quantity(magnitude, scaling, unit),
        surface(), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Area& surface)
        : Quantity(UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const std::string unit, const Area& surface)
    : Quantity(unit),
    surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Unit& unit, const Area& surface)
    : Quantity(unit),
    surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const Area& surface)
        : Quantity(magnitude, UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const std::string unit, const Area& surface)
        : Quantity(magnitude, UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const Unit& unit, const Area& surface)
        : Quantity(magnitude, UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const Area& surface)
        : Quantity(magnitude, scaling, UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const std::string unit, const Area& surface)
        : Quantity(magnitude, scaling, UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const Unit& unit, const Area& surface)
        : Quantity(magnitude, scaling, UNIT),
        surface(surface), depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Distance& depth)
        : Quantity(UNIT), surface(), depth(depth) {

}

Volume::Volume(const std::string unit, const Distance& depth)
    : Quantity(unit), surface(), depth(depth) {

}

Volume::Volume(const Unit& unit, const Distance& depth)
    : Quantity(unit), surface(), depth(depth) {

}

Volume::Volume(const float magnitude, const Distance& depth)
        : Quantity(magnitude, UNIT), surface(), depth(depth) {

}

Volume::Volume(const float magnitude, const std::string unit, const Distance& depth)
        : Quantity(magnitude, UNIT), surface(), depth(depth) {

}

Volume::Volume(const float magnitude, const Unit& unit, const Distance& depth)
        : Quantity(magnitude, UNIT), surface(), depth(depth) {

}

Volume::Volume(const float magnitude, const short int scaling, const Distance& depth)
        : Quantity(magnitude, scaling, UNIT), surface(), depth(depth) {

}

Volume::Volume(const float magnitude, const short int scaling, const std::string unit, const Distance& depth)
        : Quantity(magnitude, scaling, UNIT), surface(), depth(depth) {

}

Volume::Volume(const float magnitude, const short int scaling, const Unit& unit, const Distance& depth)
        : Quantity(magnitude, scaling, UNIT), surface(), depth(depth) {

}

Volume::Volume(const Area& surface, const Distance& depth)
        : Quantity(UNIT), surface(surface), depth(depth) {

}

Volume::Volume(const float magnitude, const short int scaling, const std::string unit,
        const Area& surface, const Distance& depth)
        : Quantity(magnitude, scaling, unit), surface(surface), depth(depth) {

}

Volume::Volume(const float magnitude, const short int scaling, const Unit& unit,
        const Area& surface, const Distance& depth)
        : Quantity(magnitude, scaling, unit), surface(surface), depth(depth) {

}

Volume::Volume(const Distance& length, const Distance& breadth)
        : Quantity(UNIT), surface(length, breadth),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const std::string unit,
        const Distance& length, const Distance& breadth)
        : Quantity(magnitude, scaling, unit), surface(length, breadth),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const float magnitude, const short int scaling, const Unit& unit,
        const Distance& length, const Distance& breadth)
        : Quantity(magnitude, scaling, unit), surface(length, breadth),
		depth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Volume::Volume(const Distance& length, const Distance& breadth, const Distance& height)
        : Quantity(UNIT), surface(length, breadth), depth(height) {

}

Volume::Volume(const float magnitude, const short int scaling, const std::string unit,
        const Distance& length, const Distance& breadth, const Distance& height)
        : Quantity(magnitude, scaling, unit), surface(length, breadth), depth(height) {

}

Volume::Volume(const float magnitude, const short int scaling, const Unit& unit,
        const Distance& length, const Distance& breadth, const Distance& height)
        : Quantity(magnitude, scaling, unit), surface(length, breadth), depth(height) {

}

Volume::~Volume() {

}

bool Volume::operator==(const Volume& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (surface == peer.surface) && (depth == peer.depth);
}

bool Volume::operator<(const Volume& peer) const {
    Volume self = *this; bool result = false;
    if (static_cast<const Quantity&>(*this) < static_cast<const Quantity&>(peer)) {
        result = true;
    } 
    if (surface < peer.surface) {
        result = true;
    }
    if (depth < peer.depth) {
        result = true;
    }
    return result;
}

bool Volume::operator>(const Volume& peer) const {
    Volume self = *this; bool result = false;
    if (static_cast<const Quantity&>(*this) > static_cast<const Quantity&>(peer)) {
        result = true;
    } 
    if (surface > peer.surface) {
        result = true;
    }
    if (depth > peer.depth) {
        result = true;
    }
    return result;
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
    Quantity self = *this, other = peer, realpart = (self + other);
	Signal signal = (this->getImaginaryScalar() + peer.getImaginaryScalar());
    float part = std::cbrt(signal.getMagnitude());
	signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Volume(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
            Distance(part, signal.getScaling(), surface.getLengthUnit()),
			Distance(part, signal.getScaling(), surface.getBreadthUnit()),
			Distance(part, signal.getScaling(), depth.getUnit()));
}

Volume Volume::operator-(const Volume& peer) const {
    Quantity self = *this, other = peer, realpart = (self - other);
	Signal signal = (this->getImaginaryScalar() - peer.getImaginaryScalar());
    float part = std::cbrt(signal.getMagnitude());
	signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Volume(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
            Distance(part, signal.getScaling(), surface.getLengthUnit()),
			Distance(part, signal.getScaling(), surface.getBreadthUnit()),
			Distance(part, signal.getScaling(), depth.getUnit()));
}

Volume Volume::operator*(const Volume& peer) const {
    Quantity self = *this, other = peer, realpart = (self * other);
	Signal signal = (this->getImaginaryScalar() * peer.getImaginaryScalar());
    float part = std::cbrt(signal.getMagnitude());
	signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Volume(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
            Distance(part, signal.getScaling(), surface.getLengthUnit()),
			Distance(part, signal.getScaling(), surface.getBreadthUnit()),
			Distance(part, signal.getScaling(), depth.getUnit()));
}

Volume Volume::operator/(const Volume& peer) const {
    Quantity self = *this, other = peer, realpart = (self / other);
	Signal signal = (this->getImaginaryScalar() / peer.getImaginaryScalar());
    float part = std::cbrt(signal.getMagnitude());
	signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Volume(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
            Distance(part, signal.getScaling(), surface.getLengthUnit()),
			Distance(part, signal.getScaling(), surface.getBreadthUnit()),
			Distance(part, signal.getScaling(), depth.getUnit()));
}

Volume Volume::operator%(const Volume& peer) const {
    Quantity self = *this, other = peer, realpart = (self % other);
	Signal signal = (this->getImaginaryScalar() % peer.getImaginaryScalar());
    float part = std::cbrt(signal.getMagnitude());
	signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Volume(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
            Distance(part, signal.getScaling(), surface.getLengthUnit()),
			Distance(part, signal.getScaling(), surface.getBreadthUnit()),
			Distance(part, signal.getScaling(), depth.getUnit()));
}

Volume Volume::operator+(const Area& planar) const {
    Volume self = *this;
    Area changed = (self.surface + planar);
    return Volume(changed, self.depth);
}

Volume Volume::operator-(const Area& planar) const {
    Volume self = *this;
    Area changed = (self.surface - planar);
    return Volume(changed, self.depth);
}

Volume Volume::operator*(const Area& planar) const {
    Volume self = *this;
    Area changed = (self.surface * planar);
    return Volume(changed, self.depth);
}

Volume Volume::operator/(const Area& planar) const {
    Volume self = *this;
    Area changed = (self.surface / planar);
    return Volume(changed, self.depth);
}

Volume Volume::operator%(const Area& planar) const {
    Volume self = *this;
    Area changed = (self.surface % planar);
    return Volume(changed, self.depth);
}

Volume Volume::operator+(const Distance& height) const {
    Volume self = *this;
    Distance changed = (self.depth + height);
    return Volume(self.surface, changed);
}

Volume Volume::operator-(const Distance& height) const {
    Volume self = *this;
    Distance changed = (self.depth - height);
    return Volume(self.surface, changed);
}

Volume Volume::operator*(const Distance& height) const {
    Volume self = *this;
    Distance changed = (self.depth * height);
    return Volume(self.surface, changed);
}

Volume Volume::operator/(const Distance& height) const {
    Volume self = *this;
    Distance changed = (self.depth / height);
    return Volume(self.surface, changed);
}

Volume Volume::operator%(const Distance& height) const {
    Volume self = *this;
    Distance changed = (self.depth % height);
    return Volume(self.surface, changed);
}

void Volume::setMagnitude(const Signal& signal) {
    float side = std::cbrt(signal.getMagnitude());
    Distance length = Distance(side, signal.getScaling(), signal.getUnit(), signal.getOrientation());
    Distance breadth = Distance(side, signal.getScaling(), signal.getUnit(), signal.getOrientation());
    Distance height = Distance(side, signal.getScaling(), signal.getUnit(), signal.getOrientation());
    this->surface = Area(length, breadth); this->depth = height;
}

Signal Volume::getRealScalar() const {
    Signal volume = ((surface.getRealScalar() * depth.getScalarTotal()));
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getRealVector() const {
    Signal volume = ((surface.getRealVector() * depth.getVectorTotal()));
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getImaginaryScalar() const {
    Signal volume = (surface.getImaginaryScalar().getDotProduct(depth.getVectorTotal()));
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getImaginaryVector() const {
    Signal volume = (surface.getImaginaryVector().getCrossProduct(depth.getVectorTotal()));
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getSurfaceRealScalar() const {
    Signal volume = surface.getRealScalar();
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getSurfaceRealVector() const {
    Signal volume = surface.getRealVector();
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getSurfaceImaginaryScalar() const {
    Signal volume = surface.getImaginaryScalar();
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getSurfaceImaginaryVector() const {
    Signal volume = surface.getImaginaryVector();
    return Signal(volume.getOrientation(), volume.getMagnitude(), volume.getScaling(), volume.getUnit());
}

Signal Volume::getLengthRotation(const short int degree) const {
    return surface.getLengthRotation(degree);
}

Intrinsic Volume::getLengthPhase() const {
    return surface.getLengthPhase();
}

void Volume::setLengthPhase(const float direction) {
    surface.setLengthPhase(direction);
}

void Volume::setLengthPhase(const Intrinsic& intrinsic) {
    surface.setLengthPhase(intrinsic);
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

void Volume::setLength(const float value, const short int scale, const Unit& unit) {
    surface.setLength(value, scale, unit);
}

Signal Volume::getBreadthRotation(const short int degree) const {
    return surface.getBreadthRotation(degree);
}

Intrinsic Volume::getBreadthPhase() const {
    return surface.getBreadthPhase();
}

void Volume::setBreadthPhase(const float direction) {
    surface.setBreadthPhase(direction);
}

void Volume::setBreadthPhase(const Intrinsic& intrinsic) {
    surface.setBreadthPhase(intrinsic);
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

void Volume::setBreadth(const float value, const short int scale, const Unit& unit) {
    surface.setBreadth(value, scale, unit);
}

void Volume::setSurface(const Distance& length, const Distance& breadth) {
    this->surface.setLength(length);
    this->surface.setBreadth(breadth);
}

void Volume::setSurface(const float length, const float breadth) {
    this->surface.setLength(length);
    this->surface.setBreadth(breadth);
}

void Volume::setSurface(const float length, const float breadth, const short int scale) {
    this->surface.setLength(length, scale);
    this->surface.setBreadth(breadth, scale);
}

void Volume::setSurface(const float length, const float breadth, const short int scale, const std::string unit) {
    this->surface.setLength(length, scale, unit);
    this->surface.setBreadth(breadth, scale, unit);
}

void Volume::setSurface(const float length, const float breadth, const short int scale, const Unit& unit) {
    this->surface.setLength(length, scale, unit);
    this->surface.setBreadth(breadth, scale, unit);
}

Distance Volume::getHeight() const {
    return depth;
}

void Volume::setHeight(const Distance& height) {
    this->depth = height;
}

Signal Volume::getHeightRotation(const short int degree) const {
    Intrinsic direction = depth.getIntrinsic();
    Intrinsic phase = direction.getRotation(degree);
    return Signal(phase, depth.getMagnitude(), depth.getScaling(), depth.getUnit());
}

Intrinsic Volume::getHeightPhase() const {
    return depth.getIntrinsic();
}

void Volume::setHeightPhase(const float direction) {
    depth.setIntrinsic(direction);
}

void Volume::setHeightPhase(const Intrinsic& intrinsic) {
    depth.setIntrinsic(intrinsic);
}

void Volume::setHeight(const float value) {
    depth.setMagnitude(value);
}

void Volume::setHeight(const float value, const short int scale) {
    depth.setMagnitude(value, scale);
}

void Volume::setHeight(const float value, const short int scale, const std::string unit) {
    depth.setMagnitude(value, scale, unit);
}

void Volume::setHeight(const float value, const short int scale, const Unit& unit) {
    depth.setMagnitude(value, scale, unit);
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
    result << Quantity::print() << ",a:";
    result << surface.print() << ",h:";
    result << depth.print();
	return result.str();
}

std::string Volume::printRadians() const {
    std::stringstream result;
    result << Quantity::print() << ",a:";
    result << surface.printRadians() << ",h:";
    result << depth.printRadians();
	return result.str();
}

Signal Volume::getCosComponent(const float phase) const {
	Signal volume = this->getRealScalar();
	return Signal(volume.getOrientation(), volume.getCosComponent(phase),
        volume.getScaling(), volume.getUnit());
}

Signal Volume::getSinComponent(const float phase) const {
	Signal volume = this->getRealScalar();
	return Signal(volume.getOrientation(), volume.getSinComponent(phase),
        volume.getScaling(), volume.getUnit());
}

} // namespace shp