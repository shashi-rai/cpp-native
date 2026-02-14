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

#ifndef GIS_EARTH_H
#define GIS_EARTH_H

#include "territory.h"
#include "../grt/planet.h"

namespace gis {

class Earth : public grt::Planet {
    TerritoryArray territories;
public:
    // Constructors
    Earth();
    Earth(const TerritoryArray& objects);
    Earth(const std::string name);
    Earth(const std::string name, const TerritoryArray& objects);

    // Destructors
    ~Earth();

    // Operator overloading
    bool operator==(const Earth& peer) const;
    Earth operator+(const Earth& peer) const;
    Earth operator-(const Earth& peer) const;

    // Access operator
    Territory operator()(const int x) { return territories[x]; }
    const Territory operator()(const int x) const { return territories[x]; }

    // Getters
    TerritoryArray getTerritories() const { return territories; }

    // Setters
    void setTerritories(const TerritoryArray& objects) { this->territories = objects; }

    // Additional methods
    int getTerritoryCount() const;
    Territory get(const int index) const;
    void set(const int index, const Territory& object);
    Earth copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printTerritories() const;
};

typedef std::vector<Earth > EarthArray;

} // namespace gis

#endif //GIS_EARTH_H