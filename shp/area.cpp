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

const std::string Area::UNIT = "m²";        // System International
const short int Area::SCALING_FACTOR = 2;   // Mathematical Operator

Area::Area()
        : Quantity(UNIT),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const std::string unit)
        : Quantity(unit),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const Unit& unit)
        : Quantity(unit),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude)
        : Quantity(magnitude, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude, const std::string unit)
        : Quantity(magnitude, unit),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude, const Unit& unit)
        : Quantity(magnitude, unit),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude, const short int scaling)
        : Quantity(magnitude, scaling, UNIT),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude, const short int scaling, const std::string unit)
        : Quantity(magnitude, scaling, unit),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude, const short int scaling, const Unit& unit)
        : Quantity(magnitude, scaling, unit),
        length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const Signal& length)
    : Quantity(UNIT), length(length), breadth(length) {

}

Area::Area(const float magnitude, const short int scaling, std::string unit,
        const Signal& length)
    : Quantity(magnitude, scaling, unit),
    length(length), breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float magnitude, const short int scaling, const Unit& unit,
        const Signal& length)
    : Quantity(magnitude, scaling, unit),
    length(length), breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const Signal& length, const Signal& breadth)
    : Quantity(UNIT), length(length), breadth(breadth) {

}

Area::Area(const float magnitude, const short int scaling, std::string unit,
        const Signal& length, const Signal& breadth)
    : Quantity(magnitude, scaling, unit), length(length), breadth(breadth) {

}

Area::Area(const float magnitude, const short int scaling, const Unit& unit,
        const Signal& length, const Signal& breadth)
    : Quantity(magnitude, scaling, unit), length(length), breadth(breadth) {

}

Area::~Area() {

}

bool Area::operator==(const Area& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (length == peer.length) && (breadth == peer.breadth);
}

bool Area::operator<(const Area& peer) const {
    Area self = *this; bool result = false;
    if (static_cast<const Quantity&>(*this) < static_cast<const Quantity&>(peer)) {
        result = true;
    }    
    if (length < peer.length) {
        result = true;
    }
    if (breadth < peer.breadth) {
        result = true;
    }
    return result;
}

bool Area::operator>(const Area& peer) const {
    Area self = *this; bool result = false;
    if (static_cast<const Quantity&>(*this) > static_cast<const Quantity&>(peer)) {
        result = true;
    }
    if (length > peer.length) {
        result = true;
    }
    if (breadth > peer.breadth) {
        result = true;
    }
    return result;
}

bool Area::operator<=(const Area& peer) const {
    Area self = *this;
    return (self < peer) || (self == peer);
}

bool Area::operator>=(const Area& peer) const {
    Area self = *this;
    return (self > peer) || (self == peer);
}

Area Area::operator+(const Area& peer) const {
    Quantity self = *this, other = peer, realpart = (self + other);
    Signal signal = (getScalarTotal() + peer.getScalarTotal());
    std::complex<float> complexarea(signal.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Area(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
        Signal(std::abs(part), signal.getScaling(), length.getUnit()),
        Signal(std::abs(part), signal.getScaling(), breadth.getUnit()));
}

Area Area::operator-(const Area& peer) const {
    Quantity self = *this, other = peer, realpart = (self - other);
    Signal signal = (getScalarTotal() - peer.getScalarTotal());
    std::complex<float> complexarea(signal.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Area(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
        Signal(std::abs(part), signal.getScaling(), length.getUnit()),
        Signal(std::abs(part), signal.getScaling(), breadth.getUnit()));
}

Area Area::operator*(const Area& peer) const {
    Quantity self = *this, other = peer, realpart = (self * other);
    Signal signal = (getScalarTotal() * peer.getScalarTotal());
    std::complex<float> complexarea(signal.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Area(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
        Signal(std::abs(part), signal.getScaling(), length.getUnit()),
        Signal(std::abs(part), signal.getScaling(), breadth.getUnit()));
}

Area Area::operator/(const Area& peer) const {
    Quantity self = *this, other = peer, realpart = (self / other);
    Signal signal = (getScalarTotal() / peer.getScalarTotal());
    std::complex<float> complexarea(signal.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Area(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
        Signal(std::abs(part), signal.getScaling(), length.getUnit()),
        Signal(std::abs(part), signal.getScaling(), breadth.getUnit()));
}

Area Area::operator%(const Area& peer) const {
    Quantity self = *this, other = peer, realpart = (self % other);
    Signal signal = (fmod(getScalarTotal().getMagnitude(), peer.getScalarTotal().getMagnitude()));
    std::complex<float> complexarea(signal.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    signal.setScaling(signal.getScaling() / SCALING_FACTOR);
    return Area(realpart.getMagnitude(), realpart.getScaling(), realpart.getUnit(),
        Signal(std::abs(part), signal.getScaling(), length.getUnit()),
        Signal(std::abs(part), signal.getScaling(), breadth.getUnit()));
}

Area Area::operator+(const Signal& peer) const {
    Area self = *this;
    Signal width = (self.breadth + peer);
    return Area(self.length, width);
}

Area Area::operator-(const Signal& peer) const {
    Area self = *this;
    Signal width = (self.breadth - peer);
    return Area(self.length, width);
}

Area Area::operator*(const Signal& peer) const {
    Area self = *this;
    Signal width = (self.breadth * peer);
    return Area(self.length, width);
}

Area Area::operator/(const Signal& peer) const {
    Area self = *this;
    Signal width = (self.breadth / peer);
    return Area(self.length, width);
}

Area Area::operator%(const Signal& peer) const {
    Area self = *this;
    Signal width = (self.breadth % peer);
    return Area(self.length, width);
}

Signal Area::getScalarTotal() const {
    Signal area = (length.getDotProduct(breadth));
    return Signal(area.getOrientation(), area.getMagnitude(), area.getScaling(), area.getUnit());
}

Signal Area::getVectorTotal() const {
    Signal area = (length.getCrossProduct(breadth));
    return Signal(area.getOrientation(), area.getMagnitude(), area.getScaling(), area.getUnit());
}

Signal Area::getLengthRotation(const short int degree) const {
    Azimuth direction(length.getOrientation());
    Azimuth phase = direction.getRotation(degree);
    return Signal(phase, length.getMagnitude(), length.getScaling(), length.getUnit());
}

Direction Area::getLengthPhase() const {
    return Direction(length.getOrientation());
}

void Area::setLengthPhase(const float direction) {
    length.setOrientation(direction);
}

void Area::setLengthPhase(const Direction& direction) {
    length.setOrientation(direction.toRadians());
}

void Area::setLength(const float value) {
    length.setMagnitude(value);
}

void Area::setLength(const float value, const short int scale) {
    length.setMagnitude(value, scale);
}

void Area::setLength(const float value, const short int scale, const std::string unit) {
    length.setMagnitude(value, scale, unit);
}

void Area::setLength(const float value, const short int scale, const Unit& unit) {
    length.setMagnitude(value, scale, unit);
}

Signal Area::getBreadthRotation(const short int degree) const {
    Azimuth direction(breadth.getOrientation());
    Azimuth phase = direction.getRotation(degree);
    return Signal(phase, length.getMagnitude(), length.getScaling(), length.getUnit());
}

Direction Area::getBreadthPhase() const {
    return Direction(breadth.getOrientation());
}

void Area::setBreadthPhase(const float direction) {
    breadth.setOrientation(direction);
}

void Area::setBreadthPhase(const Direction& direction) {
    breadth.setOrientation(direction.toRadians());
}

void Area::setBreadth(const float value) {
    breadth.setMagnitude(value);
}

void Area::setBreadth(const float value, const short int scale) {
    breadth.setMagnitude(value, scale);
}

void Area::setBreadth(const float value, const short int scale, const std::string unit) {
    breadth.setMagnitude(value, scale, unit);
}

void Area::setBreadth(const float value, const short int scale, const Unit& unit) {
    breadth.setMagnitude(value, scale, unit);
}

short int Area::getLengthScaling() const {
    return length.getScaling();
}

void Area::setLengthScaling(const short int factor) {
    length.setScaling(factor);
}

short int Area::getBreadthScaling() const {
    return breadth.getScaling();
}

void Area::setBreadthScaling(const short int factor) {
    breadth.setScaling(factor);
}

std::string Area::getLengthUnit() const {
    return (length.getUnit().getName());
}

void Area::setLengthUnit(const Unit& object) {
    length.setUnit(object);
}

std::string Area::getBreadthUnit() const {
    return (breadth.getUnit().getName());
}

void Area::setBreadthUnit(const Unit& object) {
    breadth.setUnit(object);
}

Area Area::copy() {
    Area fresh(this->length, this->breadth);
    return fresh;
}

void Area::clear() {
    length.clear();
    breadth.clear();
    return;
}

std::string Area::print() const {
    std::stringstream result;
    result << Quantity::print() << ",l:";
    result << length.print() << ",b:";
    result << breadth.print();
	return result.str();
}

std::string Area::printRadians() const {
    std::stringstream result;
    result << Quantity::print() << ",l:";
    result << length.printRadians() << ",b:";
    result << breadth.printRadians();
	return result.str();
}

Signal Area::getCosComponent(const float phase) const {
    Signal area = this->getScalarTotal();
    return Signal(area.getOrientation(), area.getCosComponent(phase),
		area.getScaling(), area.getUnit());
}

Signal Area::getSinComponent(const float phase) const {
    Signal area = this->getScalarTotal();
    return Signal(area.getOrientation(), area.getSinComponent(phase),
		area.getScaling(), area.getUnit());
}

} // namespace shp