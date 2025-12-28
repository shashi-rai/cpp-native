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

#include "shell.h"

namespace shp {

const int Shell::DEFAULT_LIMIT = 0;

Shell::Shell()
        : Point(), orbitals(), limit(DEFAULT_LIMIT) {

}

Shell::Shell(const float gradient)
        : Point(gradient), orbitals(), limit(DEFAULT_LIMIT) {

}

Shell::Shell(std::string name)
        : Point(name), orbitals(), limit(DEFAULT_LIMIT) {

}

Shell::Shell(std::string name, const int limit)
        : Point(name), orbitals(), limit(limit) {

}

Shell::Shell(std::string name, const float gradient)
        : Point(name, gradient), orbitals(), limit(DEFAULT_LIMIT) {

}

Shell::Shell(std::string name, const float gradient, const int limit)
    : Point(name, gradient), orbitals(), limit(limit) {

}

Shell::Shell(std::string name, const OrbitalArray& orbitals)
        : Point(name), orbitals(orbitals), limit(DEFAULT_LIMIT) {

}

Shell::Shell(std::string name, const OrbitalArray& orbitals, const float gradient)
        : Point(name, gradient), orbitals(orbitals), limit(DEFAULT_LIMIT) {

}

Shell::Shell(std::string name, const OrbitalArray& orbitals, const float gradient, const int limit)
        : Point(name, gradient), orbitals(orbitals), limit(limit) {

}

Shell::~Shell() {

}

bool Shell::operator==(const Shell& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (orbitals == peer.orbitals) && (limit == peer.limit);
}

Shell Shell::operator+(const Shell& peer) const {
    OrbitalArray result(orbitals);
    result.insert(result.end(), peer.orbitals.begin(), peer.orbitals.end());
    return Shell("+", result, (getGradient() + peer.getGradient()), limit);
}

Shell Shell::operator-(const Shell& peer) const {
    OrbitalArray result(orbitals);
    for (OrbitalArray::const_iterator it = peer.orbitals.begin(); it != peer.orbitals.end(); ++it) {
        OrbitalArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Shell("-", result, (getGradient() - peer.getGradient()), limit);
}

int Shell::getOrbitalCount() const {
    return orbitals.size();
}

Polygon Shell::get(int index) const {
    Polygon result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(orbitals.size())) {
        return result;
    }
    return orbitals[index];
}

void Shell::set(int index, const Polygon& object) {
    if (index < 0 || index >= limit) {
        return;
    }
    if (index < static_cast<int>(orbitals.size())) {
        // replace existing element
        orbitals[index] = object;
    } else if (index == static_cast<int>(orbitals.size())) {
        // append at end
        orbitals.push_back(object);
    } else {
        // index beyond current size: append at end
        orbitals.push_back(object);
    }
    return;
}

Point Shell::copy() {
    Shell fresh(getName(), orbitals, getGradient(), limit);
    return fresh;
}

void Shell::clear() {
    Point::clear();
    limit = DEFAULT_LIMIT;
    orbitals.clear();
    return;
}

std::string Shell::print() {
    std::stringstream result;
    result << "{sh:";
	result << Point::print() << ",l:";
    result << limit << ",sz:";
	result << orbitals.size() << "}\n{";
    for (int i = 0; i < orbitals.size(); i++) {
        result << "\t" << orbitals[i].print() << std::endl;
    }
    result << "}";
	return result.str();
}

} // namespace shp