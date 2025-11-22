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

#ifndef GIS_TERRITORY_H
#define GIS_TERRITORY_H

#include <string>
#include <vector>
#include "location.h"

namespace gis {

class Territory {
    std::string name;
    Location location;
public:
    // Constructors
    Territory();
    Territory(std::string name);
    Territory(std::string name, Location location);

    // Destructors
    ~Territory();

    // Getters
    std::string getName() const { return name; }
    Location getLocation() const { return location; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setLocation(Location value) { location = value; }
};

typedef std::vector<Territory > TerritoryArray;

} // namespace gis

#endif //GIS_TERRITORY_H