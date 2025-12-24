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

#ifndef ACT_SALE_H
#define ACT_SALE_H

#include <sstream>
#include <string>
#include <vector>
#include "discount.h"
#include "price.h"
#include "tax.h"

namespace act {

class Sale : public Price {
    std::string code;
    Discount discount;
    Tax tax;
public:
    // Constructors
    Sale();
    Sale(std::string code);
    Sale(const Discount& discount);
    Sale(std::string code, const Discount& discount);
    Sale(const Tax& tax);
    Sale(std::string code, const Tax& tax);
    Sale(std::string code, const Discount& discount, const Tax& tax);

    // Destructors
    ~Sale();

    // Operator overloading
    bool operator==(const Sale& peer) const;
    Sale operator+(const Sale& peer) const;
    Sale operator-(const Sale& peer) const;
    Sale operator*(const Sale& peer) const;
    Sale operator/(const Sale& peer) const;
    Sale operator%(const Sale& peer) const;

    // Getters
    std::string getCode() const { return code; }
    Discount getDiscount() const { return discount; }
    Tax getTax() const { return tax; }

    // Setters
    void setCode(const std::string& number) { this->code = number; }
    void setDiscount(const Discount& free) { this->discount = free; }
    void setTax(const Tax& vat) { this->tax = vat; }

    // Additional methods
    virtual Price copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Sale > SaleArray;

} // namespace act

#endif //ACT_SALE_H