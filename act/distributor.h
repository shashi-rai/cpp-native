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

#ifndef ACT_DISTRIBUTOR_H
#define ACT_DISTRIBUTOR_H

#include <sstream>
#include <string>
#include <vector>
#include "party.h"
#include "retailer.h"

namespace act {

class Distributor : public Party {
    RetailerArray retailers;
public:
    // Constructors
    Distributor();
    Distributor(std::string name);
    Distributor(const RetailerArray& retailers);
    Distributor(std::string name, const RetailerArray& retailers);

    // Destructors
    ~Distributor();

    // Operator overloading
    bool operator==(const Distributor& peer) const;
    Distributor operator+(const Distributor& peer) const;
    Distributor operator-(const Distributor& peer) const;

    // Access operator
    Party& operator()(int x) { return retailers[x]; }
    const Party& operator()(int x) const { return retailers[x]; }

    // Getters
    RetailerArray getRetailers() const { return retailers; }

    // Setters
    void setRetailers(const RetailerArray& object) { this->retailers = object; }

    // Additional methods
    int getRetailerCount() const;
    Retailer get(int index) const;
    void set(int index, const Retailer& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Distributor > DistributorArray;

} // namespace act

#endif //ACT_DISTRIBUTOR_H