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

#ifndef ACT_BRANCH_H
#define ACT_BRANCH_H

#include <sstream>
#include <string>
#include <vector>
#include "document.h"
#include "../gis/address.h"

namespace act {

class Branch {
    std::string name;
    gis::Address address;
    Document certificate;
public:
    // Constructors
    Branch();
    Branch(std::string name);
    Branch(const gis::Address& address);
    Branch(const Document& certificate);
    Branch(const gis::Address& address, const Document& certificate);
    Branch(std::string name, const gis::Address& address);
    Branch(std::string name, const Document& certificate);
    Branch(std::string name, const gis::Address& address, const Document& certificate);

    // Destructors
    ~Branch();

    // Operator overloading
    bool operator==(const Branch& peer) const;

    // Getters
    std::string getName() const { return name; }
    gis::Address getAddress() const { return address; }
    Document getCertificate() const { return certificate; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setAddress(const gis::Address& object) { this->address = object; }
    void setCertificate(const Document& factory) { this->certificate = factory; }

    // Additional methods
    virtual Branch copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Branch > BranchArray;

} // namespace act

#endif //ACT_BRANCH_H