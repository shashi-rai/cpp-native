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

#include "material.h"

namespace eco {

Material::Material()
        : Market() {

}

Material::Material(const Demand& demand)
        : Market(demand) {

}

Material::Material(const Supply& supply)
        : Market(supply) {

}

Material::Material(const Population& population)
        : Market(population) {

}

Material::Material(const Demand& demand, const Supply& supply)
        : Market(demand, supply) {

}

Material::Material(const Demand& demand, const Population& population)
        : Market(demand, population) {

}

Material::Material(const Supply& supply, const Population& population)
        : Market(supply, population) {

}

Material::Material(const Demand& demand, const Supply& supply, const Population& population)
        : Market(demand, supply, population) {

}

Material::Material(std::string name)
        : Market(name) {

}

Material::Material(std::string name, const Demand& demand)
        : Market(name, demand) {

}

Material::Material(std::string name, const Supply& supply)
        : Market(name, supply) {

}

Material::Material(std::string name, const Population& population)
        : Market(name, population) {

}

Material::Material(std::string name, const Demand& demand, const Supply& supply)
        : Market(name, demand, supply) {

}

Material::Material(std::string name, const Demand& demand, const Population& population)
        : Market(name, demand, population) {

}

Material::Material(std::string name, const Supply& supply, const Population& population)
        : Market(name, supply, population) {

}

Material::Material(std::string name, const Demand& demand, const Supply& supply, const Population& population)
        : Market(name, demand, supply, population) {

}

Material::~Material() {

}

bool Material::operator==(const Material& peer) const {
    return (static_cast<const Market&>(*this) == static_cast<const Market&>(peer));
}

Market Material::copy() {
    Material fresh(getName(), getDemand(), getSupply(), getPopulation());
    return fresh;
}

void Material::clear() {
    Market::clear();
    return;
}

std::string Material::print() {
    std::stringstream result;
    result << Market::print();
	return result.str();
}

} // namespace eco