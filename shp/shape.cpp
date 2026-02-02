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

#include "shape.h"

namespace shp {

const std::string Shape::DEFAULT_TEXT = "";  // Empty

Shape::Shape()
        : name(Shape::DEFAULT_TEXT) {
    setPhysical(nullptr);
}

Shape::Shape(const std::string name)
        : name(name) {
    setPhysical(nullptr);
}

Shape::Shape(const std::shared_ptr<Angular> geometry)
        : name(Shape::DEFAULT_TEXT) {
    setPhysical(geometry);
}

Shape::Shape(const std::string name, const std::shared_ptr<Angular> geometry)
        : name(name) {
    setPhysical(geometry);
}

Shape::~Shape() {
    setPhysical(nullptr);
}

bool Shape::operator==(const Shape& peer) const {
    bool result = false;
    if (name == peer.name) {
        result = true;
    }
    if (isStructured()) {
        if (physical == peer.physical) {
            result = true;
        }
    }
    return result;
}

Shape Shape::operator+(const Shape& peer) const {
    Angular self = *this->physical, other = *peer.physical;
    Angular shape = (self + other);
    std::shared_ptr<Angular> result = std::make_shared<Angular>(
        shape.getRadius(), shape.getPolar(), shape.getAzimuth());
    return Shape("+", result);
}

Shape Shape::operator-(const Shape& peer) const {
    Angular self = *this->physical, other = *peer.physical;
    Angular shape = (self - other);
    std::shared_ptr<Angular> result = std::make_shared<Angular>(
        shape.getRadius(), shape.getPolar(), shape.getAzimuth());
    return Shape("-", result);
}

Shape Shape::operator*(const Shape& peer) const {
    Angular self = *this->physical, other = *peer.physical;
    Angular shape = (self * other);
    std::shared_ptr<Angular> result = std::make_shared<Angular>(
        shape.getRadius(), shape.getPolar(), shape.getAzimuth());
    return Shape("*", result);
}

Shape Shape::operator/(const Shape& peer) const {
    Angular self = *this->physical, other = *peer.physical;
    Angular shape = (self / other);
    std::shared_ptr<Angular> result = std::make_shared<Angular>(
        shape.getRadius(), shape.getPolar(), shape.getAzimuth());
    return Shape("/", result);
}

Shape Shape::operator%(const Shape& peer) const {
    Angular self = *this->physical, other = *peer.physical;
    Angular shape = (self % other);
    std::shared_ptr<Angular> result = std::make_shared<Angular>(
        shape.getRadius(), shape.getPolar(), shape.getAzimuth());
    return Shape("%", result);
}

bool Shape::isStructured() const {
    return (physical != nullptr);
}

void Shape::clear() {
    setPhysical(nullptr);
    name.clear();
    return;
}

std::string Shape::print() const {
    std::stringstream result;
    result << name;
	return result.str();
}

std::string Shape::printGeometry() const {
    std::stringstream result;
    if (isStructured()) {
        result << ",o:";
        result << physical->print();
    }
	return result.str();
}

} // namespace shp