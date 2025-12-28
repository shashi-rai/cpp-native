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

#include "polygon.h"

namespace shp {

const int Polygon::DEFAULT_LIMIT = 0;

Polygon::Polygon()
        : Point(), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float gradient)
        : Point(gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(std::string name)
        : Point(name), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(std::string name, const int limit)
        : Point(name), waves(), limit(limit) {

}

Polygon::Polygon(std::string name, const float gradient)
        : Point(name, gradient), waves(), limit(0) {

}

Polygon::Polygon(std::string name, const float gradient, const int limit)
    : Point(name, gradient), waves(), limit(limit) {

}

Polygon::Polygon(std::string name, const WaveArray& waves)
        : Point(name), waves(waves), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(std::string name, const WaveArray& waves, const float gradient)
        : Point(name, gradient), waves(waves), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(std::string name, const WaveArray& waves, const float gradient, const int limit)
        : Point(name, gradient), waves(waves), limit(limit) {

}

Polygon::~Polygon() {

}

bool Polygon::operator==(const Polygon& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (waves == peer.waves) && (limit == peer.limit);
}

Polygon Polygon::operator+(const Polygon& peer) const {
    WaveArray result(waves);
    result.insert(result.end(), peer.waves.begin(), peer.waves.end());
    return Polygon("+", result, (getGradient() + peer.getGradient()), limit);
}

Polygon Polygon::operator-(const Polygon& peer) const {
    WaveArray result(waves);
    for (WaveArray::const_iterator it = peer.waves.begin(); it != peer.waves.end(); ++it) {
        WaveArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Polygon("-", result, (getGradient() - peer.getGradient()), limit);
}

int Polygon::getWaveCount() const {
    return waves.size();
}

Wave Polygon::get(int index) const {
    Wave result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(waves.size())) {
        return result;
    }
    return waves[index];
}

void Polygon::set(int index, const Wave& object) {
    if (index < 0 || index >= limit) {
        return;
    }
    if (index < static_cast<int>(waves.size())) {
        // replace existing element
        waves[index] = object;
    } else if (index == static_cast<int>(waves.size())) {
        // append at end
        waves.push_back(object);
    } else {
        // index beyond current size: append at end
        waves.push_back(object);
    }
    return;
}

Point Polygon::copy() {
    Polygon fresh(getName(), waves, getGradient(), limit);
    return fresh;
}

void Polygon::clear() {
    Point::clear();
    limit = DEFAULT_LIMIT;
    waves.clear();
    return;
}

std::string Polygon::print() {
    std::stringstream result;
    result << "{ψ:";
	result << Point::print() << ",l:";
    result << limit << ",sz:";
	result << waves.size() << "}\n{";
    for (int i = 0; i < waves.size(); i++) {
        result << "\t" << waves[i].print() << std::endl;
    }
    result << "}";
	return result.str();
}

} // namespace shp