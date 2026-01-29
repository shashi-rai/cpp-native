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

#include "securities.h"

namespace fin {

Securities::Securities()
        : act::Item(), contract(), maturity(), coupons() {

}

Securities::Securities(const std::string name)
        : act::Item(name), contract(), maturity(), coupons() {

}

Securities::Securities(const act::Contract& contract)
        : act::Item(), contract(contract), maturity(), coupons() {

}

Securities::Securities(const act::DateTime& maturity)
        : act::Item(), contract(), maturity(maturity), coupons() {

}

Securities::Securities(const act::CouponArray& coupons)
        : act::Item(), contract(), maturity(), coupons(coupons) {

}

Securities::Securities(const act::DateTime& maturity, const act::CouponArray& coupons)
        : act::Item(), contract(), maturity(maturity), coupons(coupons) {

}

Securities::Securities(const std::string name, const act::Contract& contract)
        : act::Item(name), contract(contract), maturity(), coupons() {

}

Securities::Securities(const std::string name, const act::DateTime& maturity)
        : act::Item(name), contract(), maturity(maturity), coupons() {

}

Securities::Securities(const std::string name, const act::CouponArray& coupons)
        : act::Item(name), contract(), maturity(), coupons(coupons) {

}

Securities::Securities(const std::string name, const act::DateTime& maturity,
        const act::CouponArray& coupons)
        : act::Item(name), contract(), maturity(maturity), coupons(coupons) {

}

Securities::Securities(const act::Contract& contract, const act::DateTime& maturity)
        : act::Item(), contract(contract), maturity(maturity), coupons() {

}

Securities::Securities(const act::Contract& contract, const act::CouponArray& coupons)
        : act::Item(), contract(contract), maturity(), coupons(coupons) {

}

Securities::Securities(const act::Contract& contract, const act::DateTime& maturity,
        const act::CouponArray& coupons)
        : act::Item(), contract(contract), maturity(maturity), coupons(coupons) {

}

Securities::Securities(const std::string name, const act::Contract& contract, const act::DateTime& maturity)
        : act::Item(name), contract(contract), maturity(maturity), coupons() {

}

Securities::Securities(const std::string name, const act::Contract& contract, const act::CouponArray& coupons)
        : act::Item(name), contract(contract), maturity(), coupons(coupons) {

}

Securities::Securities(const std::string name, const act::Contract& contract, const act::DateTime& maturity,
        const act::CouponArray& coupons)
        : act::Item(name), contract(contract), maturity(maturity), coupons(coupons) {

}

Securities::~Securities() {

}

bool Securities::operator==(const Securities& peer) const {
    return (static_cast<const act::Item&>(*this) == static_cast<const act::Item&>(peer))
        && (contract == peer.contract)
        && (maturity == peer.maturity)
        && (coupons == peer.coupons);
}

Securities Securities::operator+(const Securities& peer) const {
    act::CouponArray result(coupons);
    result.insert(result.end(), peer.coupons.begin(), peer.coupons.end());
    return Securities("+", (contract + peer.contract), (maturity + peer.maturity), result);
}

Securities Securities::operator-(const Securities& peer) const {
    act::CouponArray result(coupons);
    for (act::CouponArray::const_iterator it = peer.coupons.begin(); it != peer.coupons.end(); ++it) {
        act::CouponArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Securities("-", (contract - peer.contract), (maturity - peer.maturity), result);
}

int Securities::getCouponCount() const {
    return coupons.size();
}

act::Coupon Securities::get(const int index) const {
    act::Coupon result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(coupons.size())) {
        return result;
    }
    return coupons[index];
}

void Securities::set(const int index, const act::Coupon& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(coupons.size())) {
        // replace existing element
        coupons[index] = object;
    } else if (index == static_cast<int>(coupons.size())) {
        // append at end
        coupons.push_back(object);
    } else {
        // index beyond current size: append at end
        coupons.push_back(object);
    }
    return;
}

act::Item Securities::copy() {
    Securities fresh(contract, maturity, coupons);
    return fresh;
}

void Securities::clear() {
    act::Item::clear();
    contract.clear();
    maturity.clear();
    coupons.clear();
    return;
}

std::string Securities::print() {
    std::stringstream result;
    result << act::Item::print() << ",";
    result << contract.print() << ",";
    result << maturity.print() << ",sz:";
    result << coupons.size();
	return result.str();
}

} // namespace fin