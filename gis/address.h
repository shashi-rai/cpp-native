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

#ifndef GIS_ADDRESS_H
#define GIS_ADDRESS_H

#include "indoor.h"
#include "location.h"
#include "outdoor.h"

namespace gis {

class Address {
    std::shared_ptr<Location> location;
    Indoor indoor;
    Outdoor outdoor;

public:
    // Constructors
    Address();
    Address(const std::shared_ptr<Location> location);
    Address(const Indoor& indoor);
    Address(const Indoor& indoor, const std::shared_ptr<Location> location);
    Address(const Outdoor& outdoor);
    Address(const Outdoor& outdoor, const std::shared_ptr<Location> location);
    Address(const Indoor& indoor, const Outdoor& outdoor);
    Address(const Indoor& indoor, const Outdoor& outdoor, const std::shared_ptr<Location> location);

    // Destructors
    ~Address();

    // Operator overloading
    bool operator==(const Address& peer) const;

    // Getters
    std::shared_ptr<Location> getLocation() const { return location; }
    Indoor getIndoor() const { return indoor; }
    Outdoor getOutdoor() const { return outdoor; }

    // Setters
    void setLocation(const std::shared_ptr<Location> value) { this->location = value; }
    void setIndoor(const Indoor& object) { this->indoor = object; }
    void setOutdoor(const Outdoor& object) { this->outdoor = object; }

    // Additional methods
    bool isLocated() const;
    virtual Address copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string DEFAULT_VALUE;
};

typedef std::vector<Address > AddressArray;

} // namespace gis

#endif //GIS_ADDRESS_H