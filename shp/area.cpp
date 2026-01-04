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

const std::string Area::UNIT = "m";         // System International
const short int Area::SCALING_FACTOR = 2;   // Mathematical Operator

Area::Area()
        : length(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const std::string unit) : length(unit), breadth(unit) {

}

Area::Area(short int scaling, const std::string unit)
        : length(scaling, unit), breadth(scaling, unit) {

}

Area::Area(const float length)
        : length(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float length, const std::string unit)
        : length(length, unit), breadth(length, unit) {

}

Area::Area(const float length, short int scaling, const std::string unit)
        : length(length, scaling, unit), breadth(length, scaling, unit) {

}

Area::Area(const float length, const float breadth)
        : length(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(breadth, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float length, const float breadth, const std::string unit)
        : length(length, unit), breadth(breadth, unit) {

}

Area::Area(const float length, const float breadth, short int scaling)
        : length(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        breadth(breadth, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)) {

}

Area::Area(const float length, const float breadth, short int scaling, const std::string unit)
        : length(length, scaling, unit), breadth(breadth, scaling, unit) {

}

Area::Area(const Quantity& length)
    : length(length), breadth(length) {

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
    Quantity realarea = (getTotal() + peer.getTotal());
    std::complex<float> complexarea(realarea.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    realarea.setScaling(realarea.getScaling() / SCALING_FACTOR);
    return Area(Quantity(std::abs(part), realarea.getScaling(), getUnit()),
        Quantity(std::abs(part), realarea.getScaling(), getUnit()));
}

Area Area::operator-(const Area& peer) const {
    Quantity realarea = (getTotal() - peer.getTotal());
    std::complex<float> complexarea(realarea.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    realarea.setScaling(realarea.getScaling() / SCALING_FACTOR);
    return Area(Quantity(std::abs(part), realarea.getScaling(), getUnit()),
        Quantity(std::abs(part), realarea.getScaling(), getUnit()));
}

Area Area::operator*(const Area& peer) const {
    Quantity realarea = (getTotal() * peer.getTotal());
    std::complex<float> complexarea(realarea.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    realarea.setScaling(realarea.getScaling() / SCALING_FACTOR);
    return Area(Quantity(std::abs(part), realarea.getScaling(), getUnit()),
        Quantity(std::abs(part), realarea.getScaling(), getUnit()));
}

Area Area::operator/(const Area& peer) const {
    Quantity realarea = (getTotal() / peer.getTotal());
    std::complex<float> complexarea(realarea.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    realarea.setScaling(realarea.getScaling() / SCALING_FACTOR);
    return Area(Quantity(std::abs(part), realarea.getScaling(), getUnit()),
        Quantity(std::abs(part), realarea.getScaling(), getUnit()));
}

Area Area::operator%(const Area& peer) const {
    Quantity realarea = (fmod(getTotal().getMagnitude(), peer.getTotal().getMagnitude()));
    std::complex<float> complexarea(realarea.getMagnitude(), Quantity::DEFAULT_VALUE);
    std::complex<float> part = std::sqrt(complexarea);
    realarea.setScaling(realarea.getScaling() / SCALING_FACTOR);
    return Area(Quantity(std::abs(part), realarea.getScaling(), getUnit()),
        Quantity(std::abs(part), realarea.getScaling(), getUnit()));
}

Quantity Area::getTotal() const {
    Quantity area = (length * breadth);
    return Quantity(area.getMagnitude(), area.getScaling(), area.getUnit());
}

std::string Area::getUnit() const {
    return (length.getUnit().getName());
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
    result << "l:";
    result << length.print() << ",b:";
    result << breadth.print();
	return result.str();
}

Quantity Area::getComponent(float phase) const {
    Quantity area = getTotal();
    return Quantity((area.getMagnitude() * cos(phase)), area.getScaling(), area.getUnit());
}

} // namespace shp