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

#include "agency.h"

namespace act {

Agency::Agency() : Party(), departments() {

}

Agency::Agency(std::string name)
        : Party(name), departments() {

}

Agency::Agency(const DepartmentArray& departments)
        : Party(), departments(departments) {

}

Agency::Agency(std::string name, const DepartmentArray& departments)
        : Party(name), departments(departments) {

}

Agency::~Agency() {

}

bool Agency::operator==(const Agency& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (departments == peer.departments);
}

Agency Agency::operator+(const Agency& peer) const {
    DepartmentArray result(departments);
    result.insert(result.end(), peer.departments.begin(), peer.departments.end());
    return Agency("+", result);
}

Agency Agency::operator-(const Agency& peer) const {
    DepartmentArray result(departments);
    for (DepartmentArray::const_iterator it = peer.departments.begin(); it != peer.departments.end(); ++it) {
        DepartmentArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Agency("-", result);
}

int Agency::getDepartmentCount() const {
    return departments.size();
}

Department Agency::get(int index) const {
    Department result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(departments.size())) {
        return result;
    }
    return departments[index];
}

void Agency::set(int index, const Department& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(departments.size())) {
        // replace existing element
        departments[index] = object;
    } else if (index == static_cast<int>(departments.size())) {
        // append at end
        departments.push_back(object);
    } else {
        // index beyond current size: append at end
        departments.push_back(object);
    }
    return;
}

Party Agency::copy() {
    Agency fresh(getName(), departments);
    return fresh;
}

void Agency::clear() {
    Party::clear();
    departments.clear();
    return;
}

std::string Agency::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << departments.size();
	return result.str();
}

} // namespace act