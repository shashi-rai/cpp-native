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

#include "planet.h"

namespace grt {

const float Planet::EARTH_RADIUS = 6400.0f;     // 6,400 km
const float Planet::EARTH_MASS = 5.972f;        // 5.972x10^24 kg
const float Planet::EARTH_DENSITY = 5515.0f;    // 5,515 kg/m^3
const float Planet::EARTH_GRAVITY = 9.80665f;   // 9.80665 m/s²
const float Planet::EARTH_TO_SUN = 1.5f;        // 150 million km

Planet::Planet() : Celestial(), satellites() {

}

Planet::Planet(std::string name) : Celestial(name), satellites() {

}

Planet::Planet(std::string name, const SatelliteArray& satellites)
        : Celestial(name), satellites(satellites) {

}

Planet::~Planet() {

}

bool Planet::operator==(const Planet& peer) const {
    return (satellites == peer.satellites);
}

Planet Planet::operator+(const Planet& peer) const {
    SatelliteArray result(satellites);
    result.insert(result.end(), peer.satellites.begin(), peer.satellites.end());
    return Planet("+", result);
}

Planet Planet::operator-(const Planet& peer) const {
    SatelliteArray result(satellites);
    for (SatelliteArray::const_iterator it = peer.satellites.begin(); it != peer.satellites.end(); ++it) {
        SatelliteArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Planet("-", result);
}

int Planet::getSatelliteCount() const {
    return satellites.size();
}

Satellite Planet::get(int index) const {
    Satellite result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(satellites.size())) {
        return result;
    }
    return satellites[index];
}

void Planet::set(int index, const Satellite& object) {
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

const shp::Distance Planet::getEarthRadius() {
    return shp::Distance(Planet::EARTH_RADIUS, 3);
}

const qft::Mass Planet::getEarthMass() {
    return qft::Mass(Planet::EARTH_MASS, 24);
}

const qft::Density Planet::getEarthDensity() {
    return qft::Density(Planet::EARTH_DENSITY, shp::Unit::getBaseSymbol(shp::Unit::MASS));
}

const shp::Potential Planet::getEarthGravity() {
    return shp::Potential(Planet::EARTH_GRAVITY, Celestial::GRAVITY_MIN,
        shp::Unit(Celestial::GRAVITY_UNIT), getEarthRadius());
}

const shp::Distance Planet::getEarthToSun() {
    return shp::Distance(Planet::EARTH_TO_SUN, 11);
}

Celestial Planet::copy() {
    Planet fresh(getName(), satellites);
    return fresh;
}

void Planet::clear() {
	Celestial::clear();
	satellites.clear();
    return;
}

std::string Planet::print() {
    std::stringstream result;
    result << "(P:";
	result << Celestial::print() << ",sz:";
	result << satellites.size() << ")";
	return result.str();
}

} // namespace grt