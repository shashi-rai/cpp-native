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

#ifndef ACT_PARTY_H
#define ACT_PARTY_H

#include <sstream>
#include <string>
#include <vector>
#include "balance.h"
#include "../gis/address.h"

namespace act {

class Party {
    std::string name;
    gis::Address address;
    Balance balance;
public:
    // Constructors
    Party();
    Party(std::string name);
    Party(const gis::Address& address);
    Party(const Balance& balance);
    Party(const gis::Address& address, const Balance& balance);
    Party(std::string name, const gis::Address& address);
    Party(std::string name, const Balance& balance);
    Party(std::string name, const gis::Address& address, const Balance& balance);

    // Destructors
    ~Party();

    // Operator overloading
    bool operator==(const Party& peer) const;
    Party operator+(const Party& peer) const;
    Party operator-(const Party& peer) const;

    // Getters
    std::string getName() const { return name; }
    gis::Address getAddress() const { return address; }
    Balance getBalance() const { return balance; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setAddress(const gis::Address& object) { this->address = object; }
    void setBalance(const Balance& object) { this->balance = object; }

    // Additional methods
    virtual Party copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Party > PartyArray;

} // namespace act

#endif //ACT_PARTY_H