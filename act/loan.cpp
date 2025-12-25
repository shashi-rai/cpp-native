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

#include "loan.h"

namespace act {

Loan::Loan() : Liability(), installments() {

}

Loan::Loan(std::string name)
        : Liability(name), installments() {

}

Loan::Loan(const CouponArray& installments)
        : Liability(), installments(installments) {

}

Loan::Loan(std::string name, const CouponArray& installments)
        : Liability(name), installments(installments) {

}

Loan::~Loan() {

}

bool Loan::operator==(const Loan& peer) const {
    return (static_cast<const Liability&>(*this) == static_cast<const Liability&>(peer))
        && (installments == peer.installments);
}

Loan Loan::operator+(const Loan& peer) const {
    CouponArray result(installments);
    result.insert(result.end(), peer.installments.begin(), peer.installments.end());
    return Loan("+", result);
}

Loan Loan::operator-(const Loan& peer) const {
    CouponArray result(installments);
    for (CouponArray::const_iterator it = peer.installments.begin(); it != peer.installments.end(); ++it) {
        CouponArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Loan("-", result);
}

int Loan::getInstallmentCount() const {
    return installments.size();
}

Coupon Loan::get(int index) const {
    Coupon result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(installments.size())) {
        return result;
    }
    return installments[index];
}

void Loan::set(int index, const Coupon& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(installments.size())) {
        // replace existing element
        installments[index] = object;
    } else if (index == static_cast<int>(installments.size())) {
        // append at end
        installments.push_back(object);
    } else {
        // index beyond current size: append at end
        installments.push_back(object);
    }
    return;
}

Amount Loan::copy() {
    Loan fresh(getName(), installments);
    return fresh;
}

void Loan::clear() {
    Liability::clear();
    installments.clear();
    return;
}

std::string Loan::print() {
    std::stringstream result;
    result << Liability::print() << ",sz:";
    result << installments.size();
	return result.str();
}

} // namespace act