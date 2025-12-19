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

#include "celestial.h"

namespace grt {

const std::string Celestial::GRAVITY_UNIT = "m/s²";     // m/s²
const float Celestial::GRAVITY_MIN = 0.0f;              // at infinite distance
const float Celestial::LIGHT_YEAR = 9.4607304725808f;   // 9,460,730,472,580.8 km
const short int Celestial::LIGHT_SCALE = 18;            // 10^18 m

Celestial::Celestial()
        : Shape(), mass(), gravity() {
    setOrbit(nullptr);
}

Celestial::Celestial(std::string name)
        : Shape(name), mass(), gravity() {
    setOrbit(nullptr);
}

Celestial::Celestial(std::shared_ptr<grt::Orbit> orbit)
        : Shape(), mass(), gravity() {
    setOrbit(orbit);
}

Celestial::Celestial(std::string name, std::shared_ptr<grt::Orbit> orbit)
        : Shape(name), mass(), gravity() {
    setOrbit(orbit);
}

Celestial::Celestial(const qft::Mass& mass)
        : Shape(), mass(mass), gravity() {
    setOrbit(nullptr);
}

Celestial::Celestial(const qft::Mass& mass, std::shared_ptr<grt::Orbit> orbit)
        : Shape(), mass(mass), gravity() {
    setOrbit(orbit);
}

Celestial::Celestial(std::string name, const qft::Mass& mass)
        : Shape(name), mass(mass), gravity() {
    setOrbit(nullptr);
}

Celestial::Celestial(std::string name, const qft::Mass& mass, std::shared_ptr<grt::Orbit> orbit)
        : Shape(name), mass(mass), gravity() {
    setOrbit(orbit);
}

Celestial::Celestial(const shp::Potential& gravity)
        : Shape(), mass(), gravity(gravity) {
    setOrbit(nullptr);
}

Celestial::Celestial(const shp::Potential& gravity, std::shared_ptr<grt::Orbit> orbit)
        : Shape(), mass(), gravity(gravity) {
    setOrbit(orbit);
}

Celestial::Celestial(std::string name, const shp::Potential& gravity)
        : Shape(name), mass(), gravity(gravity) {
    setOrbit(nullptr);
}

Celestial::Celestial(std::string name, const shp::Potential& gravity,
        std::shared_ptr<grt::Orbit> orbit)
        : Shape(name), mass(), gravity(gravity) {
    setOrbit(orbit);
}

Celestial::Celestial(std::string name, const qft::Mass& mass, const shp::Potential& gravity)
        : Shape(name), mass(mass), gravity(gravity) {
    setOrbit(nullptr);
}

Celestial::Celestial(std::string name, const qft::Mass& mass, const shp::Potential& gravity,
        std::shared_ptr<grt::Orbit> orbit)
        : Shape(name), mass(mass), gravity(gravity) {
    setOrbit(orbit);
}

Celestial::~Celestial() {
    setOrbit(nullptr);
}

shp::Distance Celestial::getRadius() const {
    return gravity.getOrigin().getRadius();
}

void Celestial::setRadius(const shp::Distance& length) {
    gravity.setOrigin(length);
}

float Celestial::getRotation() const {
    return orbit->getRotation();
}

void Celestial::setRotation(const float value) {
    orbit->setRotation(value);
}

float Celestial::getRevolution() const {
    return orbit->getRevolution();
}

void Celestial::setRevolution(const float value) {
    orbit->setRevolution(value);
}

const shp::Distance Celestial::getLightYear() {
    return shp::Distance(Celestial::LIGHT_YEAR, Celestial::LIGHT_SCALE);
}

Celestial Celestial::copy() {
    Celestial fresh(getName(), mass, gravity, orbit);
    return fresh;
}

void Celestial::clear() {
	Celestial::clear();
	mass.clear();
    gravity.clear();
    return;
}

std::string Celestial::print() {
    std::stringstream result;
    result << "(C:";
	result << Shape::print() << ",m:";
	result << mass.print() << ",g:";
    result << gravity.print() << ",";
    result << (orbit != nullptr ? orbit->print() : "");
    result << ")";
	return result.str();
}

} // namespace grt
