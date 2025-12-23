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

#ifndef FIN_SECURITIES_H
#define FIN_SECURITIES_H

#include <string>
#include <vector>
#include "../act/contract.h"

namespace fin {

class Securities {
    act::Contract contract;
public:
    // Constructors
    Securities();
    Securities(std::string name);
    Securities(const act::Contract& contract);

    // Destructors
    ~Securities();

    // Operator overloading
    bool operator==(const Securities& peer) const;
    Securities operator+(const Securities& peer) const;
    Securities operator-(const Securities& peer) const;

    // Getters
    std::string getName() const { return contract.getName(); }
    act::Contract getContract() const { return contract; }

    // Setters
    void setName(const std::string& name) { this->contract.setName(name); }
    void setContract(const act::Contract& object) { this->contract = object; }

    // Additional methods
    virtual Securities copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Securities > SecuritiesArray;

} // namespace fin

#endif //FIN_SECURITIES_H