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

#ifndef ECO_POPULATION_H
#define ECO_POPULATION_H

#include <sstream>
#include <string>
#include <vector>
#include "growth.h"
#include "../gis/territory.h"

namespace eco {

class Population : public shp::Quantity {
    std::string name;
    Growth growth;
    gis::Territory geography;
public:
    // Constructors
    Population();
    Population(const Growth& growth);
    Population(const gis::Territory& geography);
    Population(const Growth& growth, const gis::Territory& geography);
    Population(const float quantity);
    Population(const float quantity, const short int scaling);
    Population(const float quantity, const shp::Unit& unit);
    Population(const float quantity, const short int scaling, const shp::Unit& unit);
    Population(const float quantity, const short int scaling, const shp::Unit& unit, const gis::Territory& geography);
    Population(std::string name);
    Population(std::string name, const float quantity);
    Population(std::string name, const float quantity, const short int scaling);
    Population(std::string name, const float quantity, const shp::Unit& unit);
    Population(std::string name, const float quantity, const short int scaling, const shp::Unit& unit);
    Population(std::string name, const gis::Territory& geography);
    Population(std::string name, const float quantity, const short int scaling, const shp::Unit& unit, const gis::Territory& geography);
    Population(std::string name, const float quantity, const short int scaling, const shp::Unit& unit, const Growth& growth, const gis::Territory& geography);

    // Destructors
    ~Population();

    // Operator overloading
    bool operator==(const Population& peer) const;
    Population operator+(const Population& peer) const;
    Population operator-(const Population& peer) const;
    Population operator*(const Population& peer) const;
    Population operator/(const Population& peer) const;
    Population operator%(const Population& peer) const;

    // Getters
    std::string getName() const { return name; }
    Growth getGrowth() const { return growth; }
    gis::Territory getGeography() const { return geography; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setGrowth(const Growth& object) { this->growth = object; }
    void setGeography(const gis::Territory& object) { this->geography = object; }

    // Additional methods
    virtual Population copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Population > PopulationArray;

} // namespace eco

#endif //ECO_POPULATION_H