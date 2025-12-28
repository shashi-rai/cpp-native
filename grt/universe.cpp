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

#include "universe.h"

namespace grt {

const float Universe::RADIUS = 46.5f;       // 46.6 billion light year
const float Universe::MASS = 1.0f;          // 1.0x10^53 kg
const float Universe::DENSITY = 2.56f;      // 2.56x10^-27 kg/m^3
const float Universe::GRAVITY = 6.6743015f; // 6.6743015x10^-11 N.m²/kg²

Universe::Universe() : Celestial(), galaxies() {

}

Universe::Universe(std::string name) : Celestial(name), galaxies() {

}

Universe::Universe(std::string name, const GalaxyArray& galaxies)
    : Celestial(name), galaxies(galaxies) {

}

Universe::~Universe() {

}

bool Universe::operator==(const Universe& peer) const {
    return (galaxies == peer.galaxies);
}

Universe Universe::operator+(const Universe& peer) const {
    GalaxyArray result(galaxies);
    result.insert(result.end(), peer.galaxies.begin(), peer.galaxies.end());
    return Universe("+", result);
}

Universe Universe::operator-(const Universe& peer) const {
    GalaxyArray result(galaxies);
    for (GalaxyArray::const_iterator it = peer.galaxies.begin(); it != peer.galaxies.end(); ++it) {
        GalaxyArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Universe("-", result);
}

int Universe::getGalaxyCount() const {
    return galaxies.size();
}

Galaxy Universe::get(int index) const {
    Galaxy result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(galaxies.size())) {
        return result;
    }
    return galaxies[index];
}

void Universe::set(int index, const Galaxy& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(galaxies.size())) {
        // replace existing element
        galaxies[index] = object;
    } else if (index == static_cast<int>(galaxies.size())) {
        // append at end
        galaxies.push_back(object);
    } else {
        // index beyond current size: append at end
        galaxies.push_back(object);
    }
    return;
}

const shp::Distance Universe::getRadius() {
    shp::Distance lightyear = Celestial::getLightYear();
    float radius = (Universe::RADIUS * lightyear.getLength().getMagnitude());
    short int scaling = (9 + lightyear.getScaling());
    return shp::Distance(radius, scaling);
}

const qft::Mass Universe::getMass() {
    short int scaling = 53;
    return qft::Mass(Universe::MASS, scaling);
}

const qft::Density Universe::getDensity() {
    short int scaling = -27;
    return qft::Density(Universe::DENSITY, scaling, shp::Unit::getBaseSymbol(shp::Unit::MASS));
}

const shp::Potential Universe::getGravity() {
    float highGravity = Universe::GRAVITY, lowGravity = Celestial::GRAVITY_MIN;
    short int scaling = -11;
    return shp::Potential(highGravity, lowGravity, scaling, shp::Unit("N.m²/kg²"), getRadius());
}

Celestial Universe::copy() {
    Universe fresh(getName(), galaxies);
    return fresh;
}

void Universe::clear() {
	Celestial::clear();
	galaxies.clear();
    return;
}

std::string Universe::print() {
    std::stringstream result;
    result << "(U:";
	result << Celestial::print() << ",sz:";
	result << galaxies.size() << ")";
	return result.str();
}

} // namespace grt
