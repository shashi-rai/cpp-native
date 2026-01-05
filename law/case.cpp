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

#include "case.h"

namespace law {

Case::Case() : Document(), number(), plaintiff(), defendent(), claims() {

}

Case::Case(const ClaimArray& claims)
        : Document(), number(), plaintiff(), defendent(), claims(claims) {

}

Case::Case(std::string number)
        : Document(), number(), plaintiff(), defendent(), claims() {

}

Case::Case(const act::Party& defendent)
        : Document(), number(), plaintiff(), defendent(defendent), claims() {

}

Case::Case(const act::Party& defendent, const ClaimArray& claims)
        : Document(), number(), plaintiff(), defendent(defendent), claims(claims) {

}

Case::Case(std::string number, const act::Party& defendent)
        : Document(), number(number), plaintiff(), defendent(defendent), claims() {

}

Case::Case(std::string number, const act::Party& defendent, const ClaimArray& claims)
        : Document(), number(number), plaintiff(), defendent(defendent), claims(claims) {

}

Case::Case(const act::Party& plaintiff, const act::Party& defendent)
        : Document(), number(), plaintiff(plaintiff), defendent(defendent), claims() {

}

Case::Case(const act::Party& plaintiff, const act::Party& defendent, const ClaimArray& claims)
        : Document(), number(), plaintiff(plaintiff), defendent(defendent), claims(claims) {

}

Case::Case(std::string number, const act::Party& plaintiff, const act::Party& defendent)
        : Document(), number(number), plaintiff(plaintiff), defendent(defendent), claims() {

}

Case::Case(std::string number, const act::Party& plaintiff, const act::Party& defendent, const ClaimArray& claims)
        : Document(), number(number), plaintiff(plaintiff), defendent(defendent), claims(claims) {

}

Case::~Case() {

}

bool Case::operator==(const Case& peer) const {
    return (static_cast<const doc::Document&>(*this) == static_cast<const doc::Document&>(peer))
		&& (number == peer.number)
        && (plaintiff == peer.plaintiff)
        && (defendent == peer.defendent)
		&& (claims == peer.claims);
}

Case Case::operator+(const Case& peer) const {
    ClaimArray result(claims);
    result.insert(result.end(), peer.claims.begin(), peer.claims.end());
    return Case("+", (plaintiff + peer.plaintiff), (defendent + peer.defendent), result);
}

Case Case::operator-(const Case& peer) const {
    ClaimArray result(claims);
    for (ClaimArray::const_iterator it = peer.claims.begin(); it != peer.claims.end(); ++it) {
        ClaimArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Case("-", (plaintiff - peer.plaintiff), (defendent - peer.defendent), result);
}

int Case::getClaimCount() const {
    return claims.size();
}

Claim Case::get(const int index) const {
    Claim result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(claims.size())) {
        return result;
    }
    return claims[index];
}

void Case::set(const int index, const Claim& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(claims.size())) {
        // replace existing element
        claims[index] = object;
    } else if (index == static_cast<int>(claims.size())) {
        // append at end
        claims.push_back(object);
    } else {
        // index beyond current size: append at end
        claims.push_back(object);
    }
    return;
}

doc::Document Case::copy() {
    Case fresh(number, plaintiff, defendent, claims);
    return fresh;
}

void Case::clear() {
    number.clear();
    plaintiff.clear();
    defendent.clear();
	claims.clear();
    return;
}

std::string Case::print() {
    std::stringstream result;
	result << "c:";
    result << number << ",p:";
    result << plaintiff.print() << ",d:";
    result << defendent.print() << ",sz:";
	result << claims.size() << "[";
    for (int i = 0; i < claims.size(); i++) {
        result << "," << claims[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace law