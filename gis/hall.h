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

#ifndef GIS_HALL_H
#define GIS_HALL_H

#include "indoor.h"
#include "rack.h"

namespace gis {

class Hall : public Indoor {
    RackArray racks;
public:
    // Constructors
    Hall();
    Hall(const RackArray& racks);
    Hall(const std::string room);
    Hall(const std::string room, const std::string unit);
    Hall(const std::string room, const std::string unit, const std::string floor);
    Hall(const std::string room, const RackArray& racks);
    Hall(const std::string room, const std::string unit, const RackArray& racks);
    Hall(const std::string room, const std::string unit, const std::string floor, const RackArray& racks);

    // Destructors
    ~Hall();

    // Operator overloading
    bool operator==(const Hall& peer) const;
    Hall operator+(const Hall& peer) const;
    Hall operator-(const Hall& peer) const;

    // Access operator
    Rack operator()(const int x) { return racks[x]; }
    const Rack operator()(const int x) const { return racks[x]; }

    // Getters
    RackArray getRacks() const { return racks; }

    // Setters
    void setRacks(const RackArray& objects) { this->racks = objects; }

    // Additional methods
    int getRackCount() const;
    Rack get(const int index) const;
    void set(const int index, const Rack& object);
    Hall copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRacks() const;
};

typedef std::vector<Hall > HallArray;

} // namespace gis

#endif //GIS_HALL_H