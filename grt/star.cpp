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

#include "star.h"

namespace grt {

Star::Star() : Celestial(), planets() {

}

Star::Star(std::string name) : Celestial(name), planets() {

}

Star::Star(std::string name, const PlanetArray& planets)
        : Celestial(name), planets(planets) {

}

Star::~Star() {

}

bool Star::operator==(const Star& peer) const {
    return (planets == peer.planets);
}

Star Star::operator+(const Star& peer) const {
    PlanetArray result(planets);
    result.insert(result.end(), peer.planets.begin(), peer.planets.end());
    return Star("+", result);
}

Star Star::operator-(const Star& peer) const {
    PlanetArray result(planets);
    for (PlanetArray::const_iterator it = peer.planets.begin(); it != peer.planets.end(); ++it) {
        PlanetArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Star("-", result);
}

int Star::getPlanetCount() const {
    return planets.size();
}

Planet Star::get(int index) const {
    Planet result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(planets.size())) {
        return result;
    }
    return planets[index];
}

void Star::set(int index, const Planet& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(planets.size())) {
        // replace existing element
        planets[index] = object;
    } else if (index == static_cast<int>(planets.size())) {
        // append at end
        planets.push_back(object);
    } else {
        // index beyond current size: append at end
        planets.push_back(object);
    }
    return;
}

Celestial Star::copy() {
    Star fresh(getName(), planets);
    return fresh;
}

void Star::clear() {
	Celestial::clear();
	planets.clear();
    return;
}

std::string Star::print() {
    std::stringstream result;
    result << "(S:";
	result << Celestial::print() << ",sz:";
	result << planets.size() << ")";
	return result.str();
}

} // namespace grt