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

#ifndef GRT_COMET_H
#define GRT_COMET_H

#include <string>
#include <vector>
#include "celestial.h"
#include "satellite.h"

namespace grt {

class Comet : public Celestial {
    SatelliteArray satellites;
public:
    // Constructors
    Comet();
    Comet(std::string name);
    Comet(std::string name, const SatelliteArray& objects);

    // Destructors
    ~Comet();

    // Operator overloading
    bool operator==(const Comet& peer) const;
    Comet operator+(const Comet& peer) const;
    Comet operator-(const Comet& peer) const;

    // Access operator
    Satellite& operator()(int x) { return satellites[x]; }
    const Satellite& operator()(int x) const { return satellites[x]; }

    // Getters
    SatelliteArray getSatellites() const { return satellites; }

    // Setters
    void setSatellites(const SatelliteArray& objects) { this->satellites = objects; }

    // Additional methods
    int getSatelliteCount() const;
    Satellite get(int index) const;
    void set(int index, const Satellite& object);
    virtual Celestial copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Comet > CometArray;

} // namespace grt

#endif //GRT_COMET_H