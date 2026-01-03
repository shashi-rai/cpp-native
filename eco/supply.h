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

#ifndef ECO_SUPPLY_H
#define ECO_SUPPLY_H

#include <sstream>
#include <string>
#include <vector>
#include "growth.h"

namespace eco {

class Supply : public shp::Quantity {
    std::string name;
    Growth growth;
public:
    // Constructors
    Supply();
    Supply(const Growth& growth);
    Supply(const float quantity);
    Supply(const float quantity, const short int scaling);
    Supply(const float quantity, const shp::Unit& unit);
    Supply(const float quantity, const short int scaling, const shp::Unit& unit);
    Supply(const float quantity, const short int scaling, const shp::Unit& unit, const Growth& growth);
    Supply(std::string name);
    Supply(std::string name, const float quantity);
    Supply(std::string name, const float quantity, const short int scaling);
    Supply(std::string name, const float quantity, const shp::Unit& unit);
    Supply(std::string name, const float quantity, const short int scaling, const shp::Unit& unit);
    Supply(std::string name, const Growth& growth);
    Supply(std::string name, const float quantity, const short int scaling, const shp::Unit& unit, const Growth& growth);

    // Destructors
    ~Supply();

    // Operator overloading
    bool operator==(const Supply& peer) const;
    Supply operator+(const Supply& peer) const;
    Supply operator-(const Supply& peer) const;
    Supply operator*(const Supply& peer) const;
    Supply operator/(const Supply& peer) const;
    Supply operator%(const Supply& peer) const;

    // Getters
    std::string getName() const { return name; }
    Growth getGrowth() const { return growth; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setGrowth(const Growth& object) { this->growth = object; }

    // Additional methods
    virtual Supply copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Supply > SupplyArray;

} // namespace eco

#endif //ECO_SUPPLY_H