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

#include "frame.h"

namespace shp {

const int Frame::DEFAULT_LIMIT = 0;

Frame::Frame()
        : Point(Direction::DEFAULT_RADIANS), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const Azimuth& gradient)
        : Point(gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude)
        : Point(magnitude, Direction::DEFAULT_RADIANS), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const short int scaling)
        : Point(magnitude, scaling, Direction::DEFAULT_RADIANS), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const short int scaling, const std::string unit)
        : Point(magnitude, scaling, unit), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const short int scaling, const Unit& unit)
        : Point(magnitude, scaling, unit), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const Azimuth& gradient)
        : Point(magnitude, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const short int scaling, const Azimuth& gradient)
        : Point(magnitude, scaling, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient)
        : Point(magnitude, scaling, unit, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient)
        : Point(magnitude, scaling, unit, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name)
        : Point(name), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const Azimuth& gradient)
        : Point(name, gradient), planes(), limit(0) {

}

Frame::Frame(const std::string name, const float magnitude)
        : Point(name, magnitude, Direction::DEFAULT_RADIANS), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const short int scaling)
        : Point(name, magnitude, scaling), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const short int scaling, const std::string unit)
        : Point(name, magnitude, scaling, unit), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const short int scaling, const Unit& unit)
        : Point(name, magnitude, scaling, unit), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const Azimuth& gradient)
        : Point(name, magnitude, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const short int scaling, const Azimuth& gradient)
        : Point(name, magnitude, scaling, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient)
        : Point(name, magnitude, scaling, unit, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient)
        : Point(name, magnitude, scaling, unit, gradient), planes(), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const Azimuth& gradient, const int limit)
        : Point(name, gradient), planes(), limit(limit) {

}

Frame::Frame(const std::string name, const PlanarArray& planes)
        : Point(name), planes(planes), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const PlanarArray& planes, const float gradient)
        : Point(name, gradient), planes(planes), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const PlanarArray& planes, const Azimuth& gradient)
        : Point(name, gradient), planes(planes), limit(DEFAULT_LIMIT) {

}

Frame::Frame(const std::string name, const PlanarArray& planes, const float gradient, const int limit)
        : Point(name, gradient), planes(planes), limit(limit) {

}

Frame::Frame(const std::string name, const PlanarArray& planes, const Azimuth& gradient, const int limit)
        : Point(name, gradient), planes(planes), limit(limit) {

}

Frame::~Frame() {

}

bool Frame::operator==(const Frame& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (limit == peer.limit) && (planes == peer.planes);
}

bool Frame::operator<(const Frame& peer) const {
    return (static_cast<const Point&>(*this) < static_cast<const Point&>(peer))
        && (limit < peer.limit) && (planes < peer.planes);
}

bool Frame::operator>(const Frame& peer) const {
    return (static_cast<const Point&>(*this) > static_cast<const Point&>(peer))
        && (limit > peer.limit) && (planes > peer.planes);
}

bool Frame::operator<=(const Frame& peer) const {
    Frame self = *this;
    return (self < peer) || (self == peer);
}

bool Frame::operator>=(const Frame& peer) const {
    Frame self = *this;
    return (self > peer) || (self == peer);
}

Frame Frame::operator+(const Frame& peer) const {
    PlanarArray result(planes);
    result.insert(result.end(), peer.planes.begin(), peer.planes.end());
    return Frame("+", result, (getGradient() + peer.getGradient()), limit);
}

Frame Frame::operator-(const Frame& peer) const {
    PlanarArray result(planes);
    for (PlanarArray::const_iterator it = peer.planes.begin(); it != peer.planes.end(); ++it) {
        PlanarArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Frame("-", result, (getGradient() - peer.getGradient()), limit);
}

int Frame::getPlaneCount() const {
    return planes.size();
}

Planar Frame::get(const int index) const {
    Planar result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(planes.size())) {
        return result;
    }
    return planes[index];
}

void Frame::set(const int index, const Planar& object) {
    if (index < 0 || index >= limit) {
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

Point Frame::copy() {
    Point self = *this;
    Frame fresh(self.getName(), this->planes, self.getGradient(), this->limit);
    return fresh;
}

void Frame::clear() {
    Point::clear();
    limit = DEFAULT_LIMIT;
    planes.clear();
    return;
}

std::string Frame::print() const {
    std::stringstream result;
    result << "{※";
	result << Point::print();
    result << "}";
	result << printPlanes();
	return result.str();
}

std::string Frame::printRadians() const {
    std::stringstream result;
    result << "{※";
	result << Point::printRadians();
    result << "}";
	result << printPlaneRadians();
	return result.str();
}

std::string Frame::printPlanes() const {
    std::stringstream result; int size = planes.size();
    if (size > 0) {
        result << ",sz:";
	    result << planes.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << planes[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

std::string Frame::printPlaneRadians() const {
    std::stringstream result; int size = planes.size();
    if (size > 0) {
        result << ",sz:";
	    result << planes.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << planes[i].printRadians() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace shp