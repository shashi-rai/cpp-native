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

#ifndef LAW_CASE_H
#define LAW_CASE_H

#include <sstream>
#include <string>
#include <vector>
#include "authority.h"
#include "claim.h"
#include "../act/party.h"
#include "../doc/document.h"

namespace law {

class Case : public doc::Document {
    std::string number;
    act::Party plaintiff;
    act::Party defendent;
    ClaimArray claims;
public:
    // Constructors
    Case();
    Case(const ClaimArray& claims);
    Case(std::string number);
    Case(const act::Party& defendent);
    Case(const act::Party& defendent, const ClaimArray& claims);
    Case(std::string number, const act::Party& defendent);
    Case(std::string number, const act::Party& defendent, const ClaimArray& claims);
    Case(const act::Party& plaintiff, const act::Party& defendent);
    Case(const act::Party& plaintiff, const act::Party& defendent, const ClaimArray& claims);
    Case(std::string number, const act::Party& plaintiff, const act::Party& defendent);
    Case(std::string number, const act::Party& plaintiff, const act::Party& defendent, const ClaimArray& claims);

    // Destructors
    ~Case();

    // Operator overloading
    bool operator==(const Case& peer) const;
    Case operator+(const Case& peer) const;
    Case operator-(const Case& peer) const;

    // Access operator
    Claim operator()(const int x) { return claims[x]; }
    const Claim operator()(const int x) const { return claims[x]; }

    // Getters
    std::string getNumber() const { return number; }
    act::Party getPlaintiff() const { return plaintiff; }
    act::Party getDefendent() const { return defendent; }
    ClaimArray getClaims() const { return claims; }

    // Setters
    void setNumber(const std::string& number) { this->number = number; }
    void setPlaintiff(const act::Party& party) { this->plaintiff = party; }
    void setDefendent(const act::Party& party) { this->defendent = party; }
    void setClaims(const ClaimArray& challenge) { this->claims = challenge; }

    // Additional methods
    int getClaimCount() const;
    Claim get(const int index) const;
    void set(const int index, const Claim& object);
    virtual doc::Document copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Case > CaseArray;

} // namespace law

#endif //LAW_CASE_H