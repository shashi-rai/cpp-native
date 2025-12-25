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

#ifndef ACT_GOVERNMENT_H
#define ACT_GOVERNMENT_H

#include <sstream>
#include <string>
#include <vector>
#include "agency.h"
#include "party.h"

namespace act {

class Government : public Party {
    AgencyArray agencies;
public:
    // Constructors
    Government();
    Government(std::string name);
    Government(const AgencyArray& agencies);
    Government(std::string name, const AgencyArray& agencies);

    // Destructors
    ~Government();

    // Operator overloading
    bool operator==(const Government& peer) const;
    Government operator+(const Government& peer) const;
    Government operator-(const Government& peer) const;

    // Access operator
    Party& operator()(int x) { return agencies[x]; }
    const Party& operator()(int x) const { return agencies[x]; }

    // Getters
    AgencyArray getAgencies() const { return agencies; }

    // Setters
    void setAgencies(const AgencyArray& object) { this->agencies = object; }

    // Additional methods
    int getAgencyCount() const;
    Agency get(int index) const;
    void set(int index, const Agency& object);
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Government > GovernmentArray;

} // namespace act

#endif //ACT_GOVERNMENT_H