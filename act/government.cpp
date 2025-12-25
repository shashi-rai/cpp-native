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

#include "government.h"

namespace act {

Government::Government() : Party(), agencies() {

}

Government::Government(std::string name)
        : Party(name), agencies() {

}

Government::Government(const AgencyArray& agencies)
        : Party(), agencies(agencies) {

}

Government::Government(std::string name, const AgencyArray& agencies)
        : Party(name), agencies(agencies) {

}

Government::~Government() {

}

bool Government::operator==(const Government& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (agencies == peer.agencies);
}

Government Government::operator+(const Government& peer) const {
    AgencyArray result(agencies);
    result.insert(result.end(), peer.agencies.begin(), peer.agencies.end());
    return Government("+", result);
}

Government Government::operator-(const Government& peer) const {
    AgencyArray result(agencies);
    for (AgencyArray::const_iterator it = peer.agencies.begin(); it != peer.agencies.end(); ++it) {
        AgencyArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Government("-", result);
}

int Government::getAgencyCount() const {
    return agencies.size();
}

Agency Government::get(int index) const {
    Agency result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(agencies.size())) {
        return result;
    }
    return agencies[index];
}

void Government::set(int index, const Agency& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(agencies.size())) {
        // replace existing element
        agencies[index] = object;
    } else if (index == static_cast<int>(agencies.size())) {
        // append at end
        agencies.push_back(object);
    } else {
        // index beyond current size: append at end
        agencies.push_back(object);
    }
    return;
}

Party Government::copy() {
    Government fresh(getName(), agencies);
    return fresh;
}

void Government::clear() {
    Party::clear();
    agencies.clear();
    return;
}

std::string Government::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << agencies.size();
	return result.str();
}

} // namespace act