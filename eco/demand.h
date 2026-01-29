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

#ifndef ECO_DEMAND_H
#define ECO_DEMAND_H

#include "growth.h"

namespace eco {

class Demand : public shp::Quantity {
    std::string name;
    Growth growth;
public:
    // Constructors
    Demand();
    Demand(const Growth& growth);
    Demand(const float quantity);
    Demand(const float quantity, const short int scaling);
    Demand(const float quantity, const shp::Unit& unit);
    Demand(const float quantity, const short int scaling, const shp::Unit& unit);
    Demand(const float quantity, const short int scaling, const shp::Unit& unit, const Growth& growth);
    Demand(const std::string name);
    Demand(const std::string name, const float quantity);
    Demand(const std::string name, const float quantity, const short int scaling);
    Demand(const std::string name, const float quantity, const shp::Unit& unit);
    Demand(const std::string name, const float quantity, const short int scaling, const shp::Unit& unit);
    Demand(const std::string name, const Growth& growth);
    Demand(const std::string name, const float quantity, const short int scaling, const shp::Unit& unit, const Growth& growth);

    // Destructors
    ~Demand();

    // Operator overloading
    bool operator==(const Demand& peer) const;
    Demand operator+(const Demand& peer) const;
    Demand operator-(const Demand& peer) const;
    Demand operator*(const Demand& peer) const;
    Demand operator/(const Demand& peer) const;
    Demand operator%(const Demand& peer) const;

    // Getters
    std::string getName() const { return name; }
    Growth getGrowth() const { return growth; }

    // Setters
    void setName(const std::string name) { this->name = name; }
    void setGrowth(const Growth& object) { this->growth = object; }

    // Additional methods
    virtual Demand copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Demand > DemandArray;

} // namespace eco

#endif //ECO_DEMAND_H