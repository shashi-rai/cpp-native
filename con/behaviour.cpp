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

#include "behaviour.h"

namespace con {

Behaviour::Behaviour()
        : shp::Temporal(), name() {

}

Behaviour::Behaviour(const shp::Unit& unit)
        : shp::Temporal(unit), name() {

}

Behaviour::Behaviour(const float magnitude)
        : shp::Temporal(magnitude), name() {

}

Behaviour::Behaviour(const float magnitude, const std::string unit)
        : shp::Temporal(magnitude, unit), name() {

}

Behaviour::Behaviour(const float magnitude, const shp::Unit& unit)
        : shp::Temporal(magnitude, unit), name() {

}

Behaviour::Behaviour(const float magnitude, const short int scaling)
        : shp::Temporal(magnitude, scaling), name() {

}

Behaviour::Behaviour(const float magnitude, const short int scaling, const std::string unit)
        : shp::Temporal(magnitude, scaling, unit), name() {

}

Behaviour::Behaviour(const float magnitude, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(magnitude, scaling, unit), name() {

}

Behaviour::Behaviour(const std::string name)
        : shp::Temporal(), name(name) {

}

Behaviour::Behaviour(const std::string name, const std::string unit)
        : shp::Temporal(unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const shp::Unit& unit)
        : shp::Temporal(unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float magnitude)
        : shp::Temporal(magnitude), name(name) {

}

Behaviour::Behaviour(const std::string name, const float magnitude, const std::string unit)
        : shp::Temporal(magnitude, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float magnitude, const shp::Unit& unit)
        : shp::Temporal(magnitude, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float magnitude, const short int scaling)
        : shp::Temporal(magnitude, scaling), name(name) {

}

Behaviour::Behaviour(const std::string name, const float magnitude, const short int scaling,
        const std::string unit)
        : shp::Temporal(magnitude, scaling, unit), name(name) {

}

Behaviour::Behaviour(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit)
        : shp::Temporal(magnitude, scaling, unit), name(name) {

}

Behaviour::~Behaviour() {

}

bool Behaviour::operator==(const Behaviour& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (name == peer.name);
}

Behaviour Behaviour::operator+(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, time = (self + other);
    return Behaviour("+", time.getMagnitude(), time.getScaling(), time.getUnit());
}

Behaviour Behaviour::operator-(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, time = (self - other);
    return Behaviour("-", time.getMagnitude(), time.getScaling(), time.getUnit());
}

Behaviour Behaviour::operator*(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, time = (self * other);
    return Behaviour("*", time.getMagnitude(), time.getScaling(), time.getUnit());
}

Behaviour Behaviour::operator/(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, time = (self / other);
    return Behaviour("/", time.getMagnitude(), time.getScaling(), time.getUnit());
}

Behaviour Behaviour::operator%(const Behaviour& peer) const {
    shp::Temporal self = *this, other = peer, time = (self % other);
    return Behaviour("%", time.getMagnitude(), time.getScaling(), time.getUnit());
}

void Behaviour::setDelay(const shp::Temporal& time) {
    shp::Temporal::setMagnitude(time.getMagnitude(), time.getScaling(), time.getUnit());
}

float Behaviour::getDelay() const {
    return shp::Temporal::getMagnitude();
}

void Behaviour::setDelay(const float value) {
    shp::Temporal::setMagnitude(value);
}

void Behaviour::setDelay(const float value, const short int scale) {
    shp::Temporal::setMagnitude(value, scale);
}

void Behaviour::setDelay(const float value, const short int scale, const std::string unit) {
    shp::Temporal::setMagnitude(value, scale, unit);
}

void Behaviour::setDelay(const float value, const short int scale, const shp::Unit& unit) {
    shp::Temporal::setMagnitude(value, scale, unit);
}

short int Behaviour::getScaling() const {
    return shp::Temporal::getScaling();
}

void Behaviour::setScaling(const short int factor) {
    shp::Temporal::setScaling(factor);
}

shp::Unit Behaviour::getUnit() const {
    return shp::Temporal::getUnit();
}

void Behaviour::setUnit(const shp::Unit& object) {
    shp::Temporal::setUnit(object);
}

Behaviour Behaviour::copy() {
    shp::Temporal self = *this;
    Behaviour fresh(this->getName(), self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Behaviour::clear() {
    shp::Temporal::clear();
    name.clear();
    return;
}

std::string Behaviour::print() const {
    std::stringstream result;
	result << name << ",";
    result << shp::Temporal::print();
	return result.str();
}

} // namespace con