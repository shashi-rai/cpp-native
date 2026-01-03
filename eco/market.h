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

#ifndef ECO_MARKET_H
#define ECO_MARKET_H

#include <sstream>
#include <string>
#include <vector>
#include "demand.h"
#include "supply.h"
#include "population.h"

namespace eco {

class Market {
    std::string name;
    Demand demand;
    Supply supply;
    Population population;
public:
    // Constructors
    Market();
    Market(const Demand& demand);
    Market(const Supply& supply);
    Market(const Population& population);
    Market(const Demand& demand, const Supply& supply);
    Market(const Demand& demand, const Population& population);
    Market(const Supply& supply, const Population& population);
    Market(const Demand& demand, const Supply& supply, const Population& population);
    Market(std::string name);
    Market(std::string name, const Demand& demand);
    Market(std::string name, const Supply& supply);
    Market(std::string name, const Population& population);
    Market(std::string name, const Demand& demand, const Supply& supply);
    Market(std::string name, const Demand& demand, const Population& population);
    Market(std::string name, const Supply& supply, const Population& population);
    Market(std::string name, const Demand& demand, const Supply& supply, const Population& population);

    // Destructors
    ~Market();

    // Operator overloading
    bool operator==(const Market& peer) const;

    // Getters
    std::string getName() const { return name; }
    Demand getDemand() const { return demand; }
    Supply getSupply() const { return supply; }
    Population getPopulation() const { return population; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setDemand(const Demand& object) { this->demand = object; }
    void setSupply(const Supply& object) { this->supply = object; }
    void setPopulation(const Population& object) { this->population = object; }

    // Additional methods
    virtual Market copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Market > MarketArray;

} // namespace eco

#endif //ECO_MARKET_H