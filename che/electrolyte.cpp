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

#include "electrolyte.h"

namespace che {

Electrolyte::Electrolyte()
		: qft::Fluid() {

}

Electrolyte::Electrolyte(const qft::Energy& energy)
        : qft::Fluid(energy) {

}

Electrolyte::Electrolyte(const float parameter, const qft::Energy& energy)
        : qft::Fluid(parameter, energy) {

}

Electrolyte::Electrolyte(const float parameter, const short int scaling, const qft::Energy& energy)
        : qft::Fluid(parameter, scaling, energy) {

}

Electrolyte::Electrolyte(const float parameter, const short int scaling, const shp::Unit& unit,
        const qft::Energy& energy)
        : qft::Fluid(parameter, scaling, unit, energy) {

}

Electrolyte::Electrolyte(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const qft::Energy& energy)
        : qft::Fluid(parameter, scaling, unit, modulation, energy) {

}

Electrolyte::Electrolyte(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume, const qft::Energy& energy)
        : qft::Fluid(parameter, scaling, unit, modulation, volume, energy) {

}

Electrolyte::Electrolyte(const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Signal& volume, const qft::Energy& energy)
        : qft::Fluid(parameter, scaling, unit, modulation, volume, energy) {

}

Electrolyte::Electrolyte(const std::string name)
        : qft::Fluid(name) {

}

Electrolyte::Electrolyte(const std::string name, const qft::Energy& energy)
        : qft::Fluid(name, energy) {

}

Electrolyte::Electrolyte(const std::string name, const float parameter, const qft::Energy& energy)
        : qft::Fluid(name, parameter, energy) {

}

Electrolyte::Electrolyte(const std::string name, const float parameter, const short int scaling, const qft::Energy& energy)
        : qft::Fluid(name, parameter, scaling, energy) {

}

Electrolyte::Electrolyte(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const qft::Energy& energy)
        : qft::Fluid(name, parameter, scaling, unit, energy) {

}

Electrolyte::Electrolyte(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const qft::Energy& energy)
        : qft::Fluid(name, parameter, scaling, unit, modulation, energy) {

}

Electrolyte::Electrolyte(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Volume& volume, const qft::Energy& energy)
        : qft::Fluid(name, parameter, scaling, unit, modulation, volume, energy) {

}

Electrolyte::Electrolyte(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit,
        const shp::Signal& modulation, const shp::Signal& volume, const qft::Energy& energy)
        : qft::Fluid(name, parameter, scaling, unit, modulation, volume, energy) {

}

Electrolyte::~Electrolyte() {

}

bool Electrolyte::operator==(const Electrolyte& peer) const {
    return (static_cast<const qft::Fluid&>(*this) == static_cast<const qft::Fluid&>(peer));
}

Electrolyte Electrolyte::operator+(const Electrolyte& peer) const {
    return Electrolyte("+");
}

Electrolyte Electrolyte::operator-(const Electrolyte& peer) const {
    return Electrolyte("-");
}

Electrolyte Electrolyte::copy() {
    Electrolyte fresh(qft::Fluid::getName());
    return fresh;
}

void Electrolyte::clear() {
	qft::Fluid::clear();
    return;
}

std::string Electrolyte::print() const {
    std::stringstream result;
	result << qft::Fluid::print();
	return result.str();
}

} // namespace che