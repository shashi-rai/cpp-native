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

#include "comet.h"

namespace grt {

Comet::Comet()
        : Celestial(), satellites() {

}

Comet::Comet(const SatelliteArray& satellites)
        : Celestial(), satellites(satellites) {

}

Comet::Comet(const std::string name)
        : Celestial(name), satellites() {

}

Comet::Comet(const std::string name, const SatelliteArray& satellites)
        : Celestial(name), satellites(satellites) {

}

Comet::~Comet() {

}

bool Comet::operator==(const Comet& peer) const {
    return (static_cast<const grt::Celestial&>(*this) == static_cast<const grt::Celestial&>(peer))
        && (satellites == peer.satellites);
}

Comet Comet::operator+(const Comet& peer) const {
    SatelliteArray result(satellites);
    result.insert(result.end(), peer.satellites.begin(), peer.satellites.end());
    return Comet("+", result);
}

Comet Comet::operator-(const Comet& peer) const {
    SatelliteArray result(satellites);
    for (SatelliteArray::const_iterator it = peer.satellites.begin(); it != peer.satellites.end(); ++it) {
        SatelliteArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Comet("-", result);
}

int Comet::getSatelliteCount() const {
    return satellites.size();
}

Satellite Comet::get(const int index) const {
    Satellite result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(satellites.size())) {
        return result;
    }
    return satellites[index];
}

void Comet::set(const int index, const Satellite& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(satellites.size())) {
        // replace existing element
        satellites[index] = object;
    } else if (index == static_cast<int>(satellites.size())) {
        // append at end
        satellites.push_back(object);
    } else {
        // index beyond current size: append at end
        satellites.push_back(object);
    }
    return;
}

Comet Comet::copy() {
    Comet fresh(Celestial::getName(), this->satellites);
    return fresh;
}

void Comet::clear() {
	Celestial::clear();
	satellites.clear();
    return;
}

std::string Comet::print() const {
    std::stringstream result;
    result << "(C:";
	result << Celestial::print();
	result << printSatellites() << ")";
	return result.str();
}

std::string Comet::printSatellites() const {
    std::stringstream result; int size = satellites.size();
    if (size > 0) {
        result << ",sz:";
	    result << satellites.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << satellites[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace grt