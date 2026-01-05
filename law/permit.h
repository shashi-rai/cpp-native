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

#ifndef LAW_PERMIT_H
#define LAW_PERMIT_H

#include <sstream>
#include <string>
#include <vector>
#include "authority.h"
#include "../act/party.h"
#include "../doc/document.h"

namespace law {

class Permit : public doc::Document {
    std::string number;
    Authority licensor;
    act::Party licensee;
public:
    // Constructors
    Permit();
    Permit(std::string number);
    Permit(const act::Party& licensee);
    Permit(std::string number, const act::Party& licensee);
    Permit(const Authority& licensor, const act::Party& licensee);
    Permit(std::string number, const Authority& licensor, const act::Party& licensee);

    // Destructors
    ~Permit();

    // Operator overloading
    bool operator==(const Permit& peer) const;

    // Getters
    std::string getNumber() const { return number; }
    Authority getLicensor() const { return licensor; }
    act::Party getLicensee() const { return licensee; }

    // Setters
    void setNumber(const std::string& number) { this->number = number; }
    void setLicensor(const Authority& agency) { this->licensor = agency; }
    void setLicensee(const act::Party& owner) { this->licensee = owner; }

    // Additional methods
    virtual doc::Document copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Permit > PermitArray;

} // namespace law

#endif //LAW_PERMIT_H