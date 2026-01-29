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

#include "earth.h"

namespace gis {

Earth::Earth() : grt::Planet(), territories() {

}

Earth::Earth(const std::string name) : grt::Planet(name), territories() {

}

Earth::Earth(const std::string name, const TerritoryArray& territories)
        : grt::Planet(name), territories(territories) {

}

Earth::~Earth() {

}

bool Earth::operator==(const Earth& peer) const {
    return (territories == peer.territories);
}

Earth Earth::operator+(const Earth& peer) const {
    TerritoryArray result(territories);
    result.insert(result.end(), peer.territories.begin(), peer.territories.end());
    return Earth("+", result);
}

Earth Earth::operator-(const Earth& peer) const {
    TerritoryArray result(territories);
    for (TerritoryArray::const_iterator it = peer.territories.begin(); it != peer.territories.end(); ++it) {
        TerritoryArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Earth("-", result);
}

int Earth::getTerritoryCount() const {
    return territories.size();
}

Territory Earth::get(const int index) const {
    Territory result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(territories.size())) {
        return result;
    }
    return territories[index];
}

void Earth::set(const int index, const Territory& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(territories.size())) {
        // replace existing element
        territories[index] = object;
    } else if (index == static_cast<int>(territories.size())) {
        // append at end
        territories.push_back(object);
    } else {
        // index beyond current size: append at end
        territories.push_back(object);
    }
    return;
}

grt::Celestial Earth::copy() {
    Earth fresh(getName(), territories);
    return fresh;
}

void Earth::clear() {
	grt::Planet::clear();
	territories.clear();
    return;
}

std::string Earth::print() {
    std::stringstream result;
    result << "(E:";
	result << grt::Planet::print() << ",sz:";
	result << territories.size() << ")";
	return result.str();
}

} // namespace gis