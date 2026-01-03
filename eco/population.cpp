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

#include "population.h"

namespace eco {

Population::Population()
        : shp::Quantity(), name(), growth(), geography() {

}

Population::Population(const Growth& growth)
        : shp::Quantity(), name(), growth(growth), geography() {

}

Population::Population(const gis::Territory& geography)
        : shp::Quantity(), name(), growth(), geography(geography) {

}

Population::Population(const Growth& growth, const gis::Territory& geography)
        : shp::Quantity(), name(), growth(growth), geography(geography) {

}

Population::Population(const float quantity)
        : shp::Quantity(quantity), name(), growth(), geography() {

}

Population::Population(const float quantity, const short int scaling)
        : shp::Quantity(quantity, scaling), name(), growth(), geography() {

}

Population::Population(const float quantity, const shp::Unit& unit)
        : shp::Quantity(quantity, unit), name(), growth(), geography() {

}

Population::Population(const float quantity, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(quantity, scaling, unit), name(), growth(), geography() {

}

Population::Population(const float quantity, const short int scaling,
        const shp::Unit& unit, const gis::Territory& geography)
        : shp::Quantity(quantity, scaling, unit), name(), growth(), geography(geography) {

}

Population::Population(std::string name)
        : shp::Quantity(), name(name), growth(), geography() {

}

Population::Population(std::string name, const gis::Territory& geography)
        : shp::Quantity(), name(name), growth(), geography(geography) {

}

Population::Population(std::string name,const float quantity)
        : shp::Quantity(quantity), name(name), growth(), geography() {

}

Population::Population(std::string name, const float quantity, const short int scaling)
        : shp::Quantity(quantity, scaling), name(name), growth(), geography() {

}

Population::Population(std::string name, const float quantity, const shp::Unit& unit)
        : shp::Quantity(quantity, unit), name(name), growth(), geography() {

}

Population::Population(std::string name, const float quantity, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(quantity, scaling, unit), name(name), growth(), geography() {

}

Population::Population(std::string name, const float quantity, const short int scaling,
        const shp::Unit& unit, const gis::Territory& geography)
        : shp::Quantity(quantity, scaling, unit), name(name), growth(), geography(geography) {

}

Population::Population(std::string name, const float quantity, const short int scaling,
        const shp::Unit& unit, const Growth& growth, const gis::Territory& geography)
        : shp::Quantity(quantity, scaling, unit), name(name), growth(growth), geography(geography) {

}

Population::~Population() {

}

bool Population::operator==(const Population& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (name == peer.name) && (growth == peer.growth) && (geography == peer.geography);
}

Population Population::operator+(const Population& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity population = (self + other);
    return Population("+", population.getMagnitude(), population.getScaling(), population.getUnit(),
			(growth + peer.growth), (geography + peer.geography));
}

Population Population::operator-(const Population& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity population = (self - other);
    return Population("-", population.getMagnitude(), population.getScaling(), population.getUnit(),
			(growth - peer.growth), (geography - peer.geography));
}

Population Population::operator*(const Population& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity population = (self * other);
    return Population("*", population.getMagnitude(), population.getScaling(), population.getUnit(),
			(growth * peer.growth), (geography * peer.geography));
}

Population Population::operator/(const Population& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity population = (self / other);
    return Population("/", population.getMagnitude(), population.getScaling(), population.getUnit(),
			(growth / peer.growth), (geography / peer.geography));
}

Population Population::operator%(const Population& peer) const {
    shp::Quantity self = *this, other = peer;
    shp::Quantity population = (self % other);
    return Population("%", population.getMagnitude(), population.getScaling(), population.getUnit(), 
			(growth % peer.growth), (geography % peer.geography));
}

Population Population::copy() {
    Population fresh(name, getMagnitude(), getScaling(), getUnit(), growth, geography);
    return fresh;
}

void Population::clear() {
    shp::Quantity::clear();
    name.clear();
	growth.clear();
    geography.clear();
    return;
}

std::string Population::print() {
    std::stringstream result;
    result << name << ",";
    result << shp::Quantity::print() << ",";
	result << growth.print();
    result << geography.print();
	return result.str();
}

} // namespace eco