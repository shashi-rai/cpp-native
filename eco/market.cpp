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

#include "market.h"

namespace eco {

Market::Market()
        : name(), demand(), supply(), population() {

}

Market::Market(const Demand& demand)
        : name(), demand(demand), supply(), population() {

}

Market::Market(const Supply& supply)
        : name(), demand(), supply(supply), population() {

}

Market::Market(const Population& population)
        : name(), demand(), supply(), population(population) {

}

Market::Market(const Demand& demand, const Supply& supply)
        : name(), demand(demand), supply(supply), population() {

}

Market::Market(const Demand& demand, const Population& population)
        : name(), demand(demand), supply(), population(population) {

}

Market::Market(const Supply& supply, const Population& population)
        : name(), demand(), supply(supply), population(population) {

}

Market::Market(const Demand& demand, const Supply& supply, const Population& population)
        : name(), demand(demand), supply(supply), population(population) {

}

Market::Market(const std::string name)
        : name(name), demand(), supply(), population() {

}

Market::Market(const std::string name, const Demand& demand)
        : name(name), demand(demand), supply(), population() {

}

Market::Market(const std::string name, const Supply& supply)
        : name(name), demand(), supply(supply), population() {

}

Market::Market(const std::string name, const Population& population)
        : name(name), demand(), supply(), population(population) {

}

Market::Market(const std::string name, const Demand& demand, const Supply& supply)
        : name(name), demand(demand), supply(supply), population() {

}

Market::Market(const std::string name, const Demand& demand, const Population& population)
        : name(name), demand(demand), supply(), population(population) {

}

Market::Market(const std::string name, const Supply& supply, const Population& population)
        : name(name), demand(), supply(supply), population(population) {

}

Market::Market(const std::string name, const Demand& demand, const Supply& supply, const Population& population)
        : name(name), demand(demand), supply(supply), population(population) {

}

Market::~Market() {

}

bool Market::operator==(const Market& peer) const {
    return (name == peer.name)
        && (demand == peer.demand)
        && (supply == peer.supply)
        && (population == peer.population);
}

Market Market::copy() {
    Market fresh(name, demand, supply, population);
    return fresh;
}

void Market::clear() {
    name.clear();
    demand.clear();
    supply.clear();
    population.clear();
    return;
}

std::string Market::print() {
    std::stringstream result;
    result << name << ",";
    result << demand.print() << ",";
    result << supply.print() << ",";
    result << population.print();
	return result.str();
}

} // namespace eco