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

#include "satellite.h"

namespace grt {

const float Satellite::MOON_RADIUS = 1737.4f;       // 1,737.4 km
const float Satellite::MOON_MASS = 7.34767309f;     // 7.34767309x10^22 kg
const float Satellite::MOON_DENSITY = 3346.0f;      // 3,346 kg/m^3
const float Satellite::MOON_GRAVITY = 1.6205f;      // 1.6205 m/s²
const float Satellite::MOON_TO_EARTH = 384400.0f;   // 384,400 km

Satellite::Satellite() : Celestial(), celestials() {

}

Satellite::Satellite(std::string name) : Celestial(name), celestials() {

}

Satellite::Satellite(std::string name, const CelestialArray& celestials)
        : Celestial(name), celestials(celestials) {

}

Satellite::~Satellite() {

}

bool Satellite::operator==(const Satellite& peer) const {
    return (celestials == peer.celestials);
}

Satellite Satellite::operator+(const Satellite& peer) const {
    CelestialArray result(celestials);
    result.insert(result.end(), peer.celestials.begin(), peer.celestials.end());
    return Satellite("+", result);
}

Satellite Satellite::operator-(const Satellite& peer) const {
    CelestialArray result(celestials);
    for (CelestialArray::const_iterator it = peer.celestials.begin(); it != peer.celestials.end(); ++it) {
        CelestialArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Satellite("-", result);
}

int Satellite::getCelestialCount() const {
    return celestials.size();
}

Celestial Satellite::get(int index) const {
    Satellite result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(celestials.size())) {
        return result;
    }
    return celestials[index];
}

void Satellite::set(int index, const Celestial& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(celestials.size())) {
        // replace existing element
        celestials[index] = object;
    } else if (index == static_cast<int>(celestials.size())) {
        // append at end
        celestials.push_back(object);
    } else {
        // index beyond current size: append at end
        celestials.push_back(object);
    }
    return;
}

const shp::Distance Satellite::getMoonRadius() {
    return shp::Distance(Satellite::MOON_RADIUS, 3);
}

const qft::Mass Satellite::getMoonMass() {
    return qft::Mass(Satellite::MOON_MASS, 22);
}

const qft::Density Satellite::getMoonDensity() {
    return qft::Density(Satellite::MOON_DENSITY, shp::Unit::getBaseSymbol(shp::Unit::MASS));
}

const shp::Potential Satellite::getMoonGravity() {
    return shp::Potential(Satellite::MOON_GRAVITY, Celestial::GRAVITY_MIN,
        shp::Unit(Celestial::GRAVITY_UNIT), getMoonRadius());
}

const shp::Distance Satellite::getMoonToEarth() {
    return shp::Distance(Satellite::MOON_TO_EARTH, 3);
}

Celestial Satellite::copy() {
    Satellite fresh(getName(), celestials);
    return fresh;
}

void Satellite::clear() {
	Celestial::clear();
	celestials.clear();
    return;
}

std::string Satellite::print() {
    std::stringstream result;
    result << "(S:";
	result << Celestial::print() << ",sz:";
	result << celestials.size() << ")";
	return result.str();
}

} // namespace grt