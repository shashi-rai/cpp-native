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
        amplitude(Quantity::DEFAULT_VALUE),
        gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(const Unit& unit)
        : Shape(),
        amplitude(Quantity::DEFAULT_VALUE, unit),
        gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(const float gradient)
        : Shape(),
        amplitude(Quantity::DEFAULT_VALUE), gradient(gradient) {

}

Point::Point(const float amplitude, const float gradient)
        : Shape(),
        amplitude(amplitude), gradient(gradient) {

}

Point::Point(const float amplitude, const std::string unit)
        : Shape(),
        amplitude(amplitude, unit), gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(const float amplitude, const std::string unit, const float gradient)
        : Shape(),
        amplitude(amplitude, unit), gradient(gradient) {

}

Point::Point(const float amplitude, const Unit& unit)
        : Shape(),
        amplitude(amplitude, unit), gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(const float amplitude, const Unit& unit, const float gradient)
        : Shape(),
        amplitude(amplitude, unit), gradient(gradient) {

}

Point::Point(const float amplitude, const short int scaling, const std::string unit)
        : Shape(),
        amplitude(amplitude, scaling, unit), gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(const float amplitude, const short int scaling, const std::string unit,
        const float gradient)
        : Shape(),
        amplitude(amplitude, scaling, unit), gradient(gradient) {

}

Point::Point(const float amplitude, const short int scaling, const Unit& unit)
        : Shape(),
        amplitude(amplitude, scaling, unit), gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(const float amplitude, const short int scaling, const Unit& unit,
        const float gradient)
        : Shape(),
        amplitude(amplitude, scaling, unit), gradient(gradient) {

}

Point::Point(std::string name)
        : Shape(name),
        amplitude(Quantity::DEFAULT_VALUE),
        gradient(Quantity::DEFAULT_VALUE) {

}

Point::Point(std::string name, const float gradient)
        : Shape(name),
        amplitude(Quantity::DEFAULT_VALUE),
        gradient(gradient) {

}

Point::Point(std::string name, const float amplitude, const float gradient)
        : Shape(name),
        amplitude(amplitude), gradient(gradient) {

}

Point::Point(std::string name, const float amplitude, const std::string unit)
        : Shape(name),
        amplitude(amplitude, unit), gradient() {

}

Point::Point(std::string name, const float amplitude, const std::string unit,
        const float gradient)
        : Shape(name),
        amplitude(amplitude, unit), gradient(gradient) {

}

Point::Point(std::string name, const float amplitude, const Unit& unit)
        : Shape(name),
        amplitude(amplitude, unit), gradient() {

}

Point::Point(std::string name, const float amplitude, const Unit& unit,
        const float gradient)
        : Shape(name),
        amplitude(amplitude, unit), gradient(gradient) {

}

Point::Point(std::string name, const float amplitude, const short int scaling,
        const std::string unit)
        : Shape(name),
        amplitude(amplitude, scaling, unit), gradient() {

}

Point::Point(std::string name, const float amplitude, const short int scaling,
        const std::string unit, const float gradient)
        : Shape(name),
        amplitude(amplitude, scaling, unit), gradient(gradient) {

}

Point::Point(std::string name, const float amplitude, const short int scaling,
        const Unit& unit)
        : Shape(name),
        amplitude(amplitude, scaling, unit), gradient() {

}

Point::Point(std::string name, const float amplitude, const short int scaling,
        const Unit& unit, const float gradient)
        : Shape(name),
        amplitude(amplitude, scaling, unit), gradient(gradient) {

}

Point::~Point() {

}

bool Point::operator==(const Point& peer) const {
    return (static_cast<const Shape&>(*this) == static_cast<const Shape&>(peer))
        && (amplitude == peer.amplitude) && (gradient == peer.gradient);
}

Point Point::operator+(const Point& peer) const {
    Point self = *this, other = peer;
    std::complex<float>
        ap1 = self.toAzimuthalComplex(gradient),
        ap2 = other.toAzimuthalComplex(peer.gradient);
    std::complex<float> a_phasor = ap1 + ap2;
    return Point("+", std::abs(a_phasor), std::arg(a_phasor));
}

Point Point::operator-(const Point& peer) const {
    Point self = *this, other = peer;
    std::complex<float>
        ap1 = self.toAzimuthalComplex(gradient),
        ap2 = other.toAzimuthalComplex(peer.gradient);
    std::complex<float> a_phasor = ap1 - ap2;
    return Point("-", std::abs(a_phasor), std::arg(a_phasor));
}

void Point::setAmplitude(const float magnitude) {
    amplitude.setMagnitude(magnitude);
}

void Point::setAmplitude(const float magnitude, const short int scaling) {
    amplitude.setMagnitude(magnitude);
    amplitude.setScaling(scaling);
}

void Point::setAmplitude(const float magnitude, const short int scaling, const std::string unit) {
    amplitude.setMagnitude(magnitude);
    amplitude.setScaling(scaling);
    amplitude.setUnit(unit);
}

void Point::setAmplitude(const float magnitude, const short int scaling, const Unit& unit) {
    amplitude.setMagnitude(magnitude);
    amplitude.setScaling(scaling);
    amplitude.setUnit(unit);
}

void Point::setAzimuthal(const Direction& orientation) {
    gradient = orientation.toRadians();
}

Angular Point::getOrientation() const {
    Direction azimuth(gradient);
    Angular result(Distance(Angular::DEFAULT_RADIUS), azimuth);
    return result;
}

Point Point::copy() {
    Point fresh(getName(), amplitude.getMagnitude(),
        amplitude.getScaling(), amplitude.getUnit(), gradient);
    return fresh;
}

void Point::clear() {
    Shape::clear();
	amplitude.clear();
    gradient = Quantity::DEFAULT_VALUE;
    return;
}

std::string Point::print() {
    std::stringstream result;
    result << "{p:";
	result << Shape::print() << ",a:";
    result << amplitude.print() << ",𝜙:";
	result << gradient << "}";
	return result.str();
}

Quantity Point::getAmplitudeAzimuthal(float change) const {
    return Quantity((amplitude.getMagnitude() * cos(gradient + change)),
        amplitude.getScaling(), amplitude.getUnit());
}

std::complex<float> Point::toAzimuthalComplex(float change) {
    return std::complex<float>(
        amplitude.getMagnitude() * std::cos(change),
        amplitude.getMagnitude() * std::sin(change));
}

} // namespace shp