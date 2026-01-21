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

Point::Point()
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, Quantity::DEFAULT_VALUE) {

}

Point::Point(const Unit& unit)
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, Quantity::DEFAULT_VALUE, unit) {

}

Point::Point(const float gradient)
        : Shape(),
        signal(gradient, Quantity::DEFAULT_VALUE) {

}

Point::Point(const Azimuth& gradient)
        : Shape(),
        signal(gradient, Quantity::DEFAULT_VALUE) {

}

Point::Point(const float magnitude, const float gradient)
        : Shape(),
        signal(gradient, magnitude) {

}

Point::Point(const float magnitude, const Azimuth& gradient)
        : Shape(),
        signal(gradient, magnitude) {

}

Point::Point(const float magnitude, const std::string unit)
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, magnitude, unit) {

}

Point::Point(const float magnitude, const std::string unit, const float gradient)
        : Shape(),
        signal(gradient, magnitude, unit) {

}

Point::Point(const float magnitude, const std::string unit, const Azimuth& gradient)
        : Shape(),
        signal(gradient, magnitude, unit) {

}

Point::Point(const float magnitude, const Unit& unit)
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, magnitude, unit) {

}

Point::Point(const float magnitude, const Unit& unit, const float gradient)
        : Shape(),
        signal(gradient, magnitude, unit) {

}

Point::Point(const float magnitude, const Unit& unit, const Azimuth& gradient)
        : Shape(),
        signal(gradient, magnitude, unit) {

}

Point::Point(const float magnitude, const short int scaling)
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, magnitude, scaling) {

}

Point::Point(const float magnitude, const short int scaling, const float gradient)
        : Shape(),
        signal(gradient, magnitude, scaling) {

}

Point::Point(const float magnitude, const short int scaling, const Azimuth& gradient)
        : Shape(),
        signal(gradient, magnitude, scaling) {

}

Point::Point(const float magnitude, const short int scaling, const std::string unit)
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, magnitude, scaling, unit) {

}

Point::Point(const float magnitude, const short int scaling, const std::string unit,
        const float gradient)
        : Shape(),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const float magnitude, const short int scaling, const std::string unit,
        const Azimuth& gradient)
        : Shape(),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const float magnitude, const short int scaling, const Unit& unit)
        : Shape(),
        signal(Direction::DEFAULT_RADIANS, magnitude, scaling, unit) {

}

Point::Point(const float magnitude, const short int scaling, const Unit& unit,
        const float gradient)
        : Shape(),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const float magnitude, const short int scaling, const Unit& unit,
        const Azimuth& gradient)
        : Shape(),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const std::string name)
        : Shape(name),
        signal(Direction::DEFAULT_RADIANS, Quantity::DEFAULT_VALUE) {

}

Point::Point(const std::string name, const float gradient)
        : Shape(name),
        signal(gradient, Quantity::DEFAULT_VALUE) {

}

Point::Point(const std::string name, const Azimuth& gradient)
        : Shape(name),
        signal(gradient, Quantity::DEFAULT_VALUE) {

}

Point::Point(const std::string name, const float magnitude, const float gradient)
        : Shape(name),
        signal(gradient, magnitude) {

}

Point::Point(const std::string name, const float magnitude, const Azimuth& gradient)
        : Shape(name),
        signal(gradient, magnitude) {

}

Point::Point(const std::string name, const float magnitude, const std::string unit)
        : Shape(name),
        signal(Direction::DEFAULT_RADIANS, magnitude, unit) {

}

Point::Point(const std::string name, const float magnitude, const std::string unit,
        const float gradient)
        : Shape(name),
        signal(gradient, magnitude, unit) {

}

Point::Point(const std::string name, const float magnitude, const std::string unit,
        const Azimuth& gradient)
        : Shape(name),
        signal(gradient, magnitude, unit) {

}

Point::Point(const std::string name, const float magnitude, const Unit& unit)
        : Shape(name),
        signal(Direction::DEFAULT_RADIANS, magnitude, unit) {

}

Point::Point(const std::string name, const float magnitude, const Unit& unit,
        const float gradient)
        : Shape(name),
        signal(gradient, magnitude, unit) {

}

Point::Point(const std::string name, const float magnitude, const Unit& unit,
        const Azimuth& gradient)
        : Shape(name),
        signal(gradient, magnitude, unit) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling)
        : Shape(name),
        signal(Direction::DEFAULT_RADIANS, magnitude, scaling) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
		const float gradient)
        : Shape(name),
        signal(gradient, magnitude, scaling) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
		const Azimuth& gradient)
        : Shape(name),
        signal(gradient, magnitude, scaling) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
        const std::string unit)
        : Shape(name),
        signal(Direction::DEFAULT_RADIANS, magnitude, scaling, unit) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
        const std::string unit, const float gradient)
        : Shape(name),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
        const std::string unit, const Azimuth& gradient)
        : Shape(name),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
        const Unit& unit)
        : Shape(name),
        signal(Direction::DEFAULT_RADIANS, magnitude, scaling, unit) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
        const Unit& unit, const float gradient)
        : Shape(name),
        signal(gradient, magnitude, scaling, unit) {

}

Point::Point(const std::string name, const float magnitude, const short int scaling,
        const Unit& unit, const Azimuth& gradient)
        : Shape(name),
        signal(gradient, magnitude, scaling, unit) {

}

Point::~Point() {

}

bool Point::operator==(const Point& peer) const {
    return (static_cast<const Shape&>(*this) == static_cast<const Shape&>(peer))
        && (signal == peer.signal);
}

bool Point::operator<(const Point& peer) const {
    return (static_cast<const Shape&>(*this) == static_cast<const Shape&>(peer))
        && (signal < peer.signal);
}

bool Point::operator>(const Point& peer) const {
    return (static_cast<const Shape&>(*this) == static_cast<const Shape&>(peer))
        && (signal > peer.signal);
}

bool Point::operator<=(const Point& peer) const {
    Point self = *this;
    return (self < peer) || (self == peer);
}

bool Point::operator>=(const Point& peer) const {
    Point self = *this;
    return (self > peer) || (self == peer);
}

Point Point::operator+(const Point& peer) const {
    Point self = *this, other = peer;
	Signal signal = (self.signal + other.signal);
    return Point("+", signal.getMagnitude(), signal.getScaling(), signal.getUnit(),
		signal.getOrientation());
}

Point Point::operator-(const Point& peer) const {
    Point self = *this, other = peer;
	Signal signal = (self.signal - other.signal);
    return Point("-", signal.getMagnitude(), signal.getScaling(), signal.getUnit(),
		signal.getOrientation());
}

Point Point::operator*(const Point& peer) const {
    Point self = *this, other = peer;
	Signal signal = (self.signal * other.signal);
    return Point("*", signal.getMagnitude(), signal.getScaling(), signal.getUnit(),
		signal.getOrientation());
}

Point Point::operator/(const Point& peer) const {
    Point self = *this, other = peer;
	Signal signal = (self.signal / other.signal);
    return Point("/", signal.getMagnitude(), signal.getScaling(), signal.getUnit(),
		signal.getOrientation());
}

Point Point::operator%(const Point& peer) const {
    Point self = *this, other = peer;
	Signal signal = (self.signal % other.signal);
    return Point("%", signal.getMagnitude(), signal.getScaling(), signal.getUnit(),
		signal.getOrientation());
}

float Point::getAmplitude() const {
	return signal.getAmplitude();
}

float Point::getMagnitude() const {
	return signal.getMagnitude();
}

void Point::setMagnitude(const float magnitude) {
	signal.setMagnitude(magnitude);
}

void Point::setMagnitude(const float magnitude, const short int scaling) {
    signal.setMagnitude(magnitude ,scaling);
}

void Point::setMagnitude(const float magnitude, const short int scaling, const std::string unit) {
    signal.setMagnitude(magnitude, scaling, unit);
}

void Point::setMagnitude(const float magnitude, const short int scaling, const Unit& unit) {
	signal.setMagnitude(magnitude, scaling, unit.getName());
}

short int Point::getScaling() const {
	return signal.getScaling();
}

void Point::setScaling(const short int scaling) {
	signal.setScaling(scaling);
}

Unit Point::getUnit() const {
	return signal.getUnit();
}

void Point::setUnit(const Unit& unit) {
	signal.setUnit(unit);
}

float Point::getAzimuthal() const {
    return signal.getOrientation();
}

void Point::setAzimuthal(const float radians) {
    signal.setOrientation(radians);
}

void Point::setAzimuthal(const Direction& orientation) {
    signal.setOrientation(orientation.toRadians());
}

float Point::getGradient() const {
    return signal.getOrientation();
}

void Point::setGradient(const float radians) {
    signal.setOrientation(radians);
}

void Point::setGradient(const Direction& orientation) {
    signal.setOrientation(orientation.toRadians());
}

Angular Point::getOrientation() const {
	Quantity radius = signal.getMagnitude();
    Azimuth azimuth(signal.getOrientation());
    Angular result(Distance(radius.getMagnitude(), radius.getScaling()), azimuth);
    return result;
}

Point Point::copy() const {
	Point self = *this;
    Point fresh(self.getName(), signal.getMagnitude(),
        signal.getScaling(), signal.getUnit(), signal.getOrientation());
    return fresh;
}

void Point::clear() {
    Shape::clear();
	signal.clear();
    return;
}

std::string Point::print() const {
    std::stringstream result;
    result << "{p:";
	result << Shape::print() << ",";
    result << signal.print() << "}";
	return result.str();
}

std::string Point::printRadians() const {
    std::stringstream result;
    result << "{p:";
	result << Shape::print() << ",";
    result << signal.printRadians() << "}";
	return result.str();
}

Quantity Point::getAzimuthCosComponent(const float change) const {
    return Quantity(signal.getCosComponent(change),
        signal.getScaling(), signal.getUnit());
}

Quantity Point::getAzimuthSinComponent(const float change) const {
    return Quantity(signal.getSinComponent(change),
        signal.getScaling(), signal.getUnit());
}

std::complex<float> Point::toComplexAzimuth(const float change) {
    return std::complex<float>(
        signal.getCosComponent(change),
        signal.getSinComponent(change));
}

} // namespace shp