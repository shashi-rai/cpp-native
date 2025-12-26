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

#include "staff.h"

namespace act {

Staff::Staff() : Person(), identity(), salary() {

}

Staff::Staff(std::string identity)
        : Person(), identity(identity), salary() {

}

Staff::Staff(const Amount& salary)
        : Person(), identity(), salary(salary) {

}

Staff::Staff(std::string identity, const Amount& salary)
        : Person(), identity(identity), salary(salary) {

}

Staff::~Staff() {

}

bool Staff::operator==(const Staff& peer) const {
    return (static_cast<const Person&>(*this) == static_cast<const Person&>(peer))
        && (identity == peer.identity) && (salary == peer.salary);
}

Person Staff::copy() {
    Staff fresh(identity, salary);
    return fresh;
}

void Staff::clear() {
    Person::clear();
    identity.clear();
    salary.clear();
    return;
}

std::string Staff::print() {
    std::stringstream result;
    result << identity << ",";
    result << Person::print();
	return result.str();
}

} // namespace act