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

#ifndef ACT_CURRENCY_H
#define ACT_CURRENCY_H

#include <sstream>
#include <sstream>
#include <string>
#include <vector>

namespace act {

class Currency {
    std::string symbol;
    std::string name;
public:
    // Constructors
    Currency();
    Currency(std::string symbol);
    Currency(std::string symbol, std::string name);

    // Destructors
    ~Currency();

    // Operator overloading
    bool operator==(const Currency& peer) const;

    // Getters
    std::string getSymbol() const { return symbol; }
    std::string getName() const { return name; }

    // Setters
    void setSymbol(const std::string& name) { this->symbol = name; }
    void setName(const std::string& name) { this->name = name; }

    // Additional methods
    virtual Currency copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string DEFAULT_SYMBOL;
    static const std::string DEFAULT_NAME;
};

typedef std::vector<Currency > CurrencyArray;

} // namespace act

#endif //ACT_CURRENCY_H