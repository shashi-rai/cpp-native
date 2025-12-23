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

#ifndef ACT_COUNTRY_H
#define ACT_COUNTRY_H

#include <sstream>
#include <sstream>
#include <string>
#include <vector>
#include "currency.h"

namespace act {

class Country {
    std::string code;
    std::string name;
    Currency currency;
public:
    // Constructors
    Country();
    Country(std::string code);
    Country(std::string code, std::string name);
    Country(const Currency& currency);
    Country(std::string name, const Currency& currency);
    Country(std::string code, std::string name, const Currency& currency);

    // Destructors
    ~Country();

    // Operator overloading
    bool operator==(const Country& peer) const;

    // Getters
    std::string getCode() const { return code; }
    std::string getName() const { return name; }
    Currency getCurrency() const { return currency; }

    // Setters
    void setCode(const std::string& value) { this->code = value; }
    void setName(const std::string& name) { this->name = name; }
    void setCurrency(const Currency& object) { this->currency = object; }

    // Additional methods
    virtual Country copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string DEFAULT_CODE;
    static const std::string DEFAULT_NAME;
};

typedef std::vector<Country > CountryArray;

} // namespace act

#endif //ACT_COUNTRY_H