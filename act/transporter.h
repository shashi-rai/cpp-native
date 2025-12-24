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

#ifndef ACT_TRANSPORTER_H
#define ACT_TRANSPORTER_H

#include <sstream>
#include <string>
#include <vector>
#include "party.h"
#include "vehicle.h"

namespace act {

class Transporter : public Party {
    VehicleArray vehicles;
public:
    // Constructors
    Transporter();
    Transporter(std::string name);
    Transporter(const VehicleArray& vehicles);
    Transporter(std::string name, const VehicleArray& vehicles);

    // Destructors
    ~Transporter();

    // Operator overloading
    bool operator==(const Transporter& peer) const;
    Transporter operator+(const Transporter& peer) const;
    Transporter operator-(const Transporter& peer) const;

    // Access operator
    Vehicle& operator()(int x) { return vehicles[x]; }
    const Vehicle& operator()(int x) const { return vehicles[x]; }

    // Getters
    VehicleArray getVehicles() const { return vehicles; }

    // Setters
    void setVehicles(const VehicleArray& object) { this->vehicles = object; }

    // Additional methods
    int getVehicleCount() const;
    Vehicle get(int index) const;
    void set(int index, const Vehicle& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Transporter > TransporterArray;

} // namespace act

#endif //ACT_TRANSPORTER_H