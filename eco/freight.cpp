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

#include "freight.h"

namespace eco {

Freight::Freight()
        : Market() {

}

Freight::Freight(const Demand& demand)
        : Market(demand) {

}

Freight::Freight(const Supply& supply)
        : Market(supply) {

}

Freight::Freight(const Population& population)
        : Market(population) {

}

Freight::Freight(const Demand& demand, const Supply& supply)
        : Market(demand, supply) {

}

Freight::Freight(const Demand& demand, const Population& population)
        : Market(demand, population) {

}

Freight::Freight(const Supply& supply, const Population& population)
        : Market(supply, population) {

}

Freight::Freight(const Demand& demand, const Supply& supply, const Population& population)
        : Market(demand, supply, population) {

}

Freight::Freight(const std::string name)
        : Market(name) {

}

Freight::Freight(const std::string name, const Demand& demand)
        : Market(name, demand) {

}

Freight::Freight(const std::string name, const Supply& supply)
        : Market(name, supply) {

}

Freight::Freight(const std::string name, const Population& population)
        : Market(name, population) {

}

Freight::Freight(const std::string name, const Demand& demand, const Supply& supply)
        : Market(name, demand, supply) {

}

Freight::Freight(const std::string name, const Demand& demand, const Population& population)
        : Market(name, demand, population) {

}

Freight::Freight(const std::string name, const Supply& supply, const Population& population)
        : Market(name, supply, population) {

}

Freight::Freight(const std::string name, const Demand& demand, const Supply& supply, const Population& population)
        : Market(name, demand, supply, population) {

}

Freight::~Freight() {

}

bool Freight::operator==(const Freight& peer) const {
    return (static_cast<const Market&>(*this) == static_cast<const Market&>(peer));
}

Market Freight::copy() {
    Freight fresh(getName(), getDemand(), getSupply(), getPopulation());
    return fresh;
}

void Freight::clear() {
    Market::clear();
    return;
}

std::string Freight::print() {
    std::stringstream result;
    result << Market::print();
	return result.str();
}

} // namespace eco