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

#ifndef FIN_OPTION_H
#define FIN_OPTION_H

#include <string>
#include <vector>
#include "securities.h"
#include "../act/asset.h"
#include "../act/price.h"

namespace fin {

class Option : public Securities {
    act::Asset underlying;
    act::Price strike;
public:
    // Constructors
    Option();
    Option(std::string name);
    Option(const act::Contract& contract);
    Option(const act::Asset& underlying);
    Option(const act::Price& strike);
    Option(const act::Asset& underlying, const act::Price& strike);
    Option(const act::Contract& contract, const act::Asset& underlying);
    Option(const act::Contract& contract, const act::Price& strike);
    Option(const act::Contract& contract, const act::Asset& underlying, const act::Price& strike);
    Option(std::string name, const act::Contract& contract);
    Option(std::string name, const act::Asset& underlying);
    Option(std::string name, const act::Price& strike);
    Option(std::string name, const act::Asset& underlying, const act::Price& strike);
    Option(std::string name, const act::Contract& contract, const act::Asset& underlying);
    Option(std::string name, const act::Contract& contract, const act::Price& strike);
    Option(std::string name, const act::Contract& contract, const act::Asset& underlying, const act::Price& strike);

    // Destructors
    ~Option();

    // Operator overloading
    bool operator==(const Option& peer) const;
    Option operator+(const Option& peer) const;
    Option operator-(const Option& peer) const;

    // Getters
    act::Asset getUnderlying() const { return underlying; }
    act::Price getStrike() const { return strike; }

    // Setters
    void setUnderlying(const act::Asset& asset) { this->underlying = asset; }
    void setStrike(const act::Price& price) { this->strike = price; }

    // Additional methods
    virtual act::Item copy();
    virtual void clear();
    virtual std::string print();
public:
    enum TYPE {
        CALL,   // buyer has right-to-buy Asset
        PUT,    // buyer has right-to-sell Asset
    };
};

typedef std::vector<Option > OptionArray;

} // namespace fin

#endif //FIN_OPTION_H