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

#ifndef ACT_ASSET_H
#define ACT_ASSET_H

#include "amount.h"
#include "depreciation.h"
#include "../doc/document.h"

namespace act {

class Asset : public Amount {
    std::string name;
    doc::Document registration;
    Depreciation depreciation;
public:
    // Constructors
    Asset();
    Asset(const float value);
    Asset(const std::string name);
    Asset(const doc::Document& registration);
    Asset(const std::string name, const doc::Document& registration);
    Asset(const std::string name, const float value);
    Asset(const std::string name, const std::string remarks);
    Asset(const std::string name, const Currency& currency, const std::string remarks);
    Asset(const std::string name, const float value, const Currency& currency, const std::string remarks);
    Asset(const std::string name, const long datetime, const float value, const Currency& currency, const std::string remarks);

    // Destructors
    ~Asset();

    // Operator overloading
    bool operator==(const Asset& peer) const;
    Asset operator+(const Asset& peer) const;
    Asset operator-(const Asset& peer) const;
    Asset operator*(const Asset& peer) const;
    Asset operator/(const Asset& peer) const;
    Asset operator%(const Asset& peer) const;

    // Getters
    std::string getName() const { return name; }
    doc::Document getRegistration() const { return registration; }
    Depreciation getDepreciation() const { return depreciation; }

    // Setters
    void setName(const std::string name) { this->name = name; }
    void setRegistration(const doc::Document& document) { this->registration = document; }
    void setDepreciation(const Depreciation& valued) { this->depreciation = valued; }

    // Additional methods
    virtual Amount copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Asset > AssetArray;

} // namespace act

#endif //ACT_ASSET_H