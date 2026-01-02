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

#include "colour.h"

namespace qft {

const float Colour::DEFAULT_VALUE = shp::Quantity::DEFAULT_VALUE;   // e.g., 0.0f 

Colour::Colour()
        : Charge(), colour() {

}

Colour::Colour(const std::shared_ptr<Field> field)
        : Charge(field), colour() {

}

Colour::Colour(const img::RGB& colour)
        : Charge(), colour(colour) {

}

Colour::Colour(const img::RGB& colour, const std::shared_ptr<Field> field)
        : Charge(field), colour(colour) {

}

Colour::Colour(std::string unit)
        : Charge(unit), colour() {

}

Colour::Colour(const shp::Unit& unit)
        : Charge(unit), colour() {

}

Colour::Colour(const img::RGB& colour, const shp::Unit& unit)
        : Charge(unit), colour(colour) {

}

Colour::Colour(const img::RGB& colour, const shp::Unit& unit, const std::shared_ptr<Field> field)
        : Charge(unit, field), colour(colour) {

}

Colour::Colour(const float magnitude)
        : Charge(magnitude), colour() {

}

Colour::Colour(const float magnitude, std::string unit)
        : Charge(magnitude, unit), colour() {

}

Colour::Colour(const float magnitude, const shp::Unit& unit)
        : Charge(magnitude, unit), colour() {

}

Colour::Colour(const img::RGB& colour,const float magnitude, const shp::Unit& unit)
        : Charge(magnitude, unit), colour(colour) {

}

Colour::Colour(const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field)
        : Charge(magnitude, unit, field), colour() {

}

Colour::Colour(const img::RGB& colour, const float magnitude, const shp::Unit& unit, const std::shared_ptr<Field> field)
        : Charge(magnitude, unit, field), colour(colour) {

}

Colour::Colour(const float magnitude, const short int scaling)
        : Charge(magnitude, scaling), colour() {

}

Colour::Colour(const img::RGB& colour, const float magnitude, const short int scaling)
        : Charge(magnitude, scaling), colour(colour) {

}

Colour::Colour(const float magnitude, const short int scaling, const std::shared_ptr<Field> field)
        : Charge(magnitude, scaling, field), colour() {

}

Colour::Colour(const img::RGB& colour, const float magnitude, const short int scaling, const std::shared_ptr<Field> field)
        : Charge(magnitude, scaling, field), colour(colour) {

}

Colour::Colour(const float magnitude, const short int scaling, std::string unit)
        : Charge(magnitude, scaling, shp::Unit(unit)), colour() {

}

Colour::Colour(const float magnitude, const short int scaling, const shp::Unit& unit)
        : Charge(magnitude, scaling, unit), colour() {

}

Colour::Colour(const img::RGB& colour, const float magnitude, const short int scaling, const shp::Unit& unit)
        : Charge(magnitude, scaling, unit), colour(colour) {

}

Colour::Colour(const float magnitude, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Field> field)
        : Charge(magnitude, scaling, unit, field), colour() {

}

Colour::Colour(const img::RGB& colour, const float magnitude, const short int scaling, const shp::Unit& unit,
        const std::shared_ptr<Field> field)
        : Charge(magnitude, scaling, unit, field), colour(colour) {

}

Colour::~Colour() {

}

bool Colour::operator==(const Colour& peer) const {
    return (static_cast<const Charge&>(*this) == static_cast<const Charge&>(peer))
        && (colour == peer.colour);
}

Colour Colour::operator+(const Colour& peer) const {
    Charge self = *this, other = peer;
    Charge result = (self + other);
    return Colour((colour + peer.colour),
        result.getMagnitude(), result.getScaling(), result.getUnit(), result.getField());
}

Colour Colour::operator-(const Colour& peer) const {
    Charge self = *this, other = peer;
    Charge result = (self - other);
    return Colour((colour - peer.colour),
        result.getMagnitude(), result.getScaling(), result.getUnit(), result.getField());
}

Colour Colour::operator*(const Colour& peer) const {
    Charge self = *this, other = peer;
    Charge result = (self * other);
    return Colour((colour * peer.colour),
        result.getMagnitude(), result.getScaling(), result.getUnit(), result.getField());
}

Colour Colour::operator/(const Colour& peer) const {
    Charge self = *this, other = peer;
    Charge result = (self / other);
    return Colour((colour / peer.colour),
        result.getMagnitude(), result.getScaling(), result.getUnit(), result.getField());
}

Colour Colour::operator%(const Colour& peer) const {
    Charge self = *this, other = peer;
    Charge result = (self % other);
    return Colour((colour % peer.colour),
        result.getMagnitude(), result.getScaling(), result.getUnit(), result.getField());
}

bool Colour::hasNoColour() const {
    return colour == colour.getWhiteColour();
}

float Colour::getRed() const {
    return colour.getRed();
}

void Colour::setRed(const float value) {
	colour.setRed(value);
}

float Colour::getGreen() const {
	return colour.getGreen();
}

void Colour::setGreen(const float value) {
	colour.setGreen(value);
}

float Colour::getBlue() const {
	return colour.getBlue();
}

void Colour::setBlue(const float value) {
	colour.setBlue(value);
}

Charge Colour::copy() {
    Colour fresh(colour, getMagnitude(), getScaling(), getUnit(), getField());
    return fresh;
}

void Colour::clear() {
    Charge::clear();
    colour.clear();
    return;
}

std::string Colour::print() {
    std::stringstream result;
    result << "|";
    if (hasNoColour())
        result << "Ψ";
    else
        result << (colour.toHex());
    result << "⟩";
	return result.str();
}

} // namespace qft