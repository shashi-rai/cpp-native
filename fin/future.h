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

#ifndef FIN_FUTURE_H
#define FIN_FUTURE_H

#include "securities.h"
#include "../act/asset.h"
#include "../act/price.h"

namespace fin {

class Future : public Securities {
    act::Asset underlying;
    act::Price strike;
public:
    // Constructors
    Future();
    Future(const std::string name);
    Future(const act::Contract& contract);
    Future(const act::Asset& underlying);
    Future(const act::Price& strike);
    Future(const act::Asset& underlying, const act::Price& strike);
    Future(const act::Contract& contract, const act::Asset& underlying);
    Future(const act::Contract& contract, const act::Price& strike);
    Future(const act::Contract& contract, const act::Asset& underlying, const act::Price& strike);
    Future(const std::string name, const act::Contract& contract);
    Future(const std::string name, const act::Asset& underlying);
    Future(const std::string name, const act::Price& strike);
    Future(const std::string name, const act::Asset& underlying, const act::Price& strike);
    Future(const std::string name, const act::Contract& contract, const act::Asset& underlying);
    Future(const std::string name, const act::Contract& contract, const act::Price& strike);
    Future(const std::string name, const act::Contract& contract, const act::Asset& underlying, const act::Price& strike);

    // Destructors
    ~Future();

    // Operator overloading
    bool operator==(const Future& peer) const;
    Future operator+(const Future& peer) const;
    Future operator-(const Future& peer) const;

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
};

typedef std::vector<Future > FutureArray;

} // namespace fin

#endif //FIN_FUTURE_H