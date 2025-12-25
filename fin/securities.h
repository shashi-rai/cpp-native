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

#include <sstream>
#include <string>
#include <vector>
#include "../act/contract.h"
#include "../act/coupon.h"
#include "../act/datetime.h"
#include "../act/item.h"

namespace fin {

class Securities : public act::Item {
    act::Contract contract;
    act::DateTime maturity;
    act::CouponArray coupons;
public:
    // Constructors
    Securities();
    Securities(std::string name);
    Securities(const act::Contract& contract);
    Securities(const act::DateTime& maturity);
    Securities(const act::CouponArray& coupons);
    Securities(const act::DateTime& maturity, const act::CouponArray& coupons);
    Securities(std::string name, const act::Contract& contract);
    Securities(std::string name, const act::DateTime& maturity);
    Securities(std::string name, const act::CouponArray& coupons);
    Securities(std::string name, const act::DateTime& maturity, const act::CouponArray& coupons);
    Securities(const act::Contract& contract, const act::DateTime& maturity);
    Securities(const act::Contract& contract, const act::CouponArray& coupons);
    Securities(const act::Contract& contract, const act::DateTime& maturity, const act::CouponArray& coupons);
    Securities(std::string name, const act::Contract& contract, const act::DateTime& maturity);
    Securities(std::string name, const act::Contract& contract, const act::CouponArray& coupons);
    Securities(std::string name, const act::Contract& contract, const act::DateTime& maturity, const act::CouponArray& coupons);

    // Destructors
    ~Securities();

    // Operator overloading
    bool operator==(const Securities& peer) const;
    Securities operator+(const Securities& peer) const;
    Securities operator-(const Securities& peer) const;

    // Access operator
    act::Coupon& operator()(int x) { return coupons[x]; }
    const act::Coupon& operator()(int x) const { return coupons[x]; }

    // Getters
    act::Contract getContract() const { return contract; }
    act::DateTime getMaturity() const { return maturity; }
    act::CouponArray getCoupons() const { return coupons; }

    // Setters
    void setContract(const act::Contract& object) { this->contract = object; }
    void setMaturity(const act::DateTime& object) { this->maturity = object; }
    void setCoupons(const act::CouponArray& object) { this->coupons = object; }

    // Additional methods
    int getCouponCount() const;
    act::Coupon get(int index) const;
    void set(int index, const act::Coupon& object);
    virtual Item copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Securities > SecuritiesArray;

} // namespace fin

#endif //FIN_SECURITIES_H