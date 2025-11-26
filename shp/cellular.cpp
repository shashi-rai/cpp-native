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

#include "cellular.h"

namespace shp {

Cellular::Cellular() : Point(), planes() {

}

Cellular::Cellular(float gradient) : Point(gradient), planes() {

}

Cellular::Cellular(std::string name) : Point(name), planes() {

}

Cellular::Cellular(std::string name, float gradient) : Point(name, gradient), planes() {

}

Cellular::Cellular(std::string name, PlanarArray& planes)
        : Point(name), planes(planes) {

}

Cellular::Cellular(std::string name, PlanarArray& planes, float gradient)
        : Point(name, gradient), planes(planes) {

}

Cellular::~Cellular() {

}

bool Cellular::operator==(const Cellular& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (planes == peer.planes);
}

Cellular Cellular::operator+(const Cellular& peer) const {
    PlanarArray result(planes);
    result.insert(result.end(), peer.planes.begin(), peer.planes.end());
    return Cellular("+", result);
}

Cellular Cellular::operator-(const Cellular& peer) const {
    PlanarArray result(planes);
    for (PlanarArray::const_iterator it = peer.planes.begin(); it != peer.planes.end(); ++it) {
        PlanarArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Cellular("-", result);
}

int Cellular::getPlaneCount() const {
    return planes.size();
}

Planar Cellular::get(int index) const {
    Planar result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(planes.size())) {
        return result;
    }
    return planes[index];
}

void Cellular::set(int index, const Planar& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(planes.size())) {
        // replace existing element
        planes[index] = object;
    } else if (index == static_cast<int>(planes.size())) {
        // append at end
        planes.push_back(object);
    } else {
        // index beyond current size: append at end
        planes.push_back(object);
    }
    return;
}

Point Cellular::copy() {
    Cellular fresh(this->getName(), this->planes);
    return fresh;
}

void Cellular::clear() {
    Point::clear();
    planes.clear();
    return;
}

std::string Cellular::print() {
    std::stringstream result;
    result << "{ce";
	result << Point::print() << ",sz:";
	result << planes.size() << "}";
	return result.str();
}

} // namespace shp