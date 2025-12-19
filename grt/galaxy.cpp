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

#include "galaxy.h"

namespace grt {

const float Galaxy::MILKYWAY_RADIUS = 129000.0f;    // 129,000 light year
const float Galaxy::MILKYWAY_MASS = 1.5f;           // 1.0~1.5x10^12 solar mass
const float Galaxy::MILKYWAY_DENSITY = 1.0f;        // 1.0x10^-21 kg/m^3
const float Galaxy::MILKYWAY_GRAVITY = 3.54f;       // 3.54x10^6 m/s²

Galaxy::Galaxy() : Celestial(), stars() {

}

Galaxy::Galaxy(std::string name) : Celestial(name), stars() {

}

Galaxy::Galaxy(std::string name, const StarArray& stars)
        : Celestial(name), stars(stars) {

}

Galaxy::~Galaxy() {

}

bool Galaxy::operator==(const Galaxy& peer) const {
    return (stars == peer.stars);
}

Galaxy Galaxy::operator+(const Galaxy& peer) const {
    StarArray result(stars);
    result.insert(result.end(), peer.stars.begin(), peer.stars.end());
    return Galaxy("+", result);
}

Galaxy Galaxy::operator-(const Galaxy& peer) const {
    StarArray result(stars);
    for (StarArray::const_iterator it = peer.stars.begin(); it != peer.stars.end(); ++it) {
        StarArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Galaxy("-", result);
}

int Galaxy::getStarCount() const {
    return stars.size();
}

Star Galaxy::get(int index) const {
    Star result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(stars.size())) {
        return result;
    }
    return stars[index];
}

void Galaxy::set(int index, const Star& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(stars.size())) {
        // replace existing element
        stars[index] = object;
    } else if (index == static_cast<int>(stars.size())) {
        // append at end
        stars.push_back(object);
    } else {
        // index beyond current size: append at end
        stars.push_back(object);
    }
    return;
}

const shp::Distance Galaxy::getMilkywayRadius() {
    shp::Distance lightyear = Celestial::getLightYear();
    float radius = (Galaxy::MILKYWAY_RADIUS * lightyear.getMagnitude().getValue());
    short int scaling = lightyear.getScaling();
    return shp::Distance(radius, scaling);
}

const qft::Mass Galaxy::getMilkywayMass() {
    qft::Mass solar = Star::getSunMass();
    float mass = (Galaxy::MILKYWAY_MASS * solar.getMagnitude().getValue());
    short int scaling = (12 + solar.getMagnitude().getScaling());
    return qft::Mass(mass, scaling);
}

const qft::Density Galaxy::getMilkywayDensity() {
    short int scaling = -21;
    return qft::Density(Galaxy::MILKYWAY_DENSITY, scaling, shp::Unit::getBaseSymbol(shp::Unit::MASS));
}

const shp::Potential Galaxy::getMilkywayGravity() {
    float highGravity = Galaxy::MILKYWAY_GRAVITY, lowGravity = Celestial::GRAVITY_MIN;
    short int scaling = 6;
    return shp::Potential(highGravity, lowGravity, scaling,
        shp::Unit(Celestial::GRAVITY_UNIT), getMilkywayRadius());
}

Celestial Galaxy::copy() {
    Galaxy fresh(getName(), stars);
    return fresh;
}

void Galaxy::clear() {
	Celestial::clear();
	stars.clear();
    return;
}

std::string Galaxy::print() {
    std::stringstream result;
    result << "(G:";
	result << Celestial::print() << ",sz:";
	result << stars.size() << ")";
	return result.str();
}

} // namespace grt