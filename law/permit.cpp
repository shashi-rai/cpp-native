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

#include "permit.h"

namespace law {

Permit::Permit() : Document(), number(), licensor(), licensee() {

}

Permit::Permit(std::string number)
        : Document(), number(), licensor(), licensee() {

}

Permit::Permit(const act::Party& licensee)
        : Document(), number(), licensor(), licensee(licensee) {

}

Permit::Permit(std::string number, const act::Party& licensee)
        : Document(), number(number), licensor(), licensee(licensee) {

}

Permit::Permit(const Authority& licensor, const act::Party& licensee)
        : Document(), number(), licensor(licensor), licensee(licensee) {

}

Permit::Permit(std::string number, const Authority& licensor, const act::Party& licensee)
        : Document(), number(number), licensor(licensor), licensee(licensee) {

}

Permit::~Permit() {

}

bool Permit::operator==(const Permit& peer) const {
    return (static_cast<const doc::Document&>(*this) == static_cast<const doc::Document&>(peer))
		&& (number == peer.number)
        && (licensor == peer.licensor)
        && (licensee == peer.licensee);
}

doc::Document Permit::copy() {
    Permit fresh(number, licensor, licensee);
    return fresh;
}

void Permit::clear() {
    number.clear();
    licensor.clear();
    licensee.clear();
    return;
}

std::string Permit::print() {
    std::stringstream result;
	result << "P(";
    result << number << ",a:";
    result << licensor.print() << ",p:";
    result << licensee.print() << ")";
	return result.str();
}

} // namespace law