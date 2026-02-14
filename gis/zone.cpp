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

#include "zone.h"

namespace gis {

Zone::Zone()
        : name(), halls() {

}

Zone::Zone(const HallArray& halls)
        : name(), halls(halls) {

}

Zone::Zone(const std::string name)
        : name(name), halls() {

}

Zone::Zone(const std::string name, const HallArray& halls)
        : name(name), halls(halls) {

}

Zone::~Zone() {

}

bool Zone::operator==(const Zone& peer) const {
    return (name == peer.name);
}

Zone Zone::operator+(const Zone& peer) const {
    HallArray result(halls);
    result.insert(result.end(), peer.halls.begin(), peer.halls.end());
    return Zone("+", result);
}

Zone Zone::operator-(const Zone& peer) const {
    HallArray result(halls);
    for (HallArray::const_iterator it = peer.halls.begin(); it != peer.halls.end(); ++it) {
        HallArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Zone("-", result);
}

int Zone::getHallCount() const {
    return halls.size();
}

Hall Zone::get(const int index) const {
    Hall result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(halls.size())) {
        return result;
    }
    return halls[index];
}

void Zone::set(const int index, const Hall& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(halls.size())) {
        // replace existing element
        halls[index] = object;
    } else if (index == static_cast<int>(halls.size())) {
        // append at end
        halls.push_back(object);
    } else {
        // index beyond current size: append at end
        halls.push_back(object);
    }
    return;
}

Zone Zone::copy() {
    Zone fresh(this->getName(),this->halls);
    return fresh;
}

void Zone::clear() {
    name.clear();
    halls.clear();
    return;
}

std::string Zone::print() const {
    std::stringstream result;
    result << name;
    result << printHalls();
	return result.str();
}

std::string Zone::printHalls() const {
    std::stringstream result; int size = halls.size();
    if (size > 0) {
        result << ",sz:";
	    result << halls.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << halls[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace gis