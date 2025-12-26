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

#include "employee.h"

namespace act {

Employee::Employee() : Staff(), department() {

}

Employee::Employee(std::string identity)
        : Staff(identity), department() {

}

Employee::Employee(const Department& department)
        : Staff(), department(department) {

}

Employee::Employee(std::string identity, const Department& department)
        : Staff(identity), department(department) {

}

Employee::~Employee() {

}

bool Employee::operator==(const Employee& peer) const {
    return (static_cast<const Staff&>(*this) == static_cast<const Staff&>(peer))
        && (department == peer.department);
}

Person Employee::copy() {
    Employee fresh(getIdentity(), department);
    return fresh;
}

void Employee::clear() {
    Staff::clear();
    department.clear();
    return;
}

std::string Employee::print() {
    std::stringstream result;
    result << Staff::print() << ",";
    result << department.print();
	return result.str();
}

} // namespace act