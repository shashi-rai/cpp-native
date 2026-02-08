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

#include "linear.h"

namespace shp {

const int Linear::DEFAULT_LIMIT = 0;

Linear::Linear()
        : Point(Direction::DEFAULT_RADIANS), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const Intrinsic& gradient)
        : Point(gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude)
        : Point(magnitude, Direction::DEFAULT_RADIANS), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const short int scaling)
        : Point(magnitude, scaling, Direction::DEFAULT_RADIANS), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const short int scaling, const std::string unit)
        : Point(magnitude, scaling, unit), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const short int scaling, const Unit& unit)
        : Point(magnitude, scaling, unit), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const Intrinsic& gradient)
        : Point(magnitude, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const short int scaling, const Intrinsic& gradient)
        : Point(magnitude, scaling, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const short int scaling, const std::string unit, const Intrinsic& gradient)
        : Point(magnitude, scaling, unit, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const float magnitude, const short int scaling, const Unit& unit, const Intrinsic& gradient)
        : Point(magnitude, scaling, unit, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name)
        : Point(name), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const Intrinsic& gradient)
        : Point(name, gradient), points(), limit(0) {

}

Linear::Linear(const std::string name, const float magnitude)
        : Point(name, magnitude, Direction::DEFAULT_RADIANS), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const short int scaling)
        : Point(name, magnitude, scaling), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const short int scaling, const std::string unit)
        : Point(name, magnitude, scaling, unit), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const short int scaling, const Unit& unit)
        : Point(name, magnitude, scaling, unit), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const Intrinsic& gradient)
        : Point(name, magnitude, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const short int scaling, const Intrinsic& gradient)
        : Point(name, magnitude, scaling, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Intrinsic& gradient)
        : Point(name, magnitude, scaling, unit, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Intrinsic& gradient)
        : Point(name, magnitude, scaling, unit, gradient), points(), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const Intrinsic& gradient, const int limit)
        : Point(name, gradient), points(), limit(limit) {

}

Linear::Linear(const std::string name, const PointArray& points)
        : Point(name), points(points), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const PointArray& points, const float gradient)
        : Point(name, gradient), points(points), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const PointArray& points, const Intrinsic& gradient)
        : Point(name, gradient), points(points), limit(DEFAULT_LIMIT) {

}

Linear::Linear(const std::string name, const PointArray& points, const float gradient, const int limit)
        : Point(name, gradient), points(points), limit(limit) {

}

Linear::Linear(const std::string name, const PointArray& points, const Intrinsic& gradient, const int limit)
        : Point(name, gradient), points(points), limit(limit) {

}

Linear::~Linear() {

}

bool Linear::operator==(const Linear& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (limit == peer.limit) && (points == peer.points);
}

bool Linear::operator<(const Linear& peer) const {
    return (static_cast<const Point&>(*this) < static_cast<const Point&>(peer))
        && (limit < peer.limit) && (points < peer.points);
}

bool Linear::operator>(const Linear& peer) const {
    return (static_cast<const Point&>(*this) > static_cast<const Point&>(peer))
        && (limit > peer.limit) && (points > peer.points);
}

bool Linear::operator<=(const Linear& peer) const {
    Linear self = *this;
    return (self < peer) || (self == peer);
}

bool Linear::operator>=(const Linear& peer) const {
    Linear self = *this;
    return (self > peer) || (self == peer);
}

Linear Linear::operator+(const Linear& peer) const {
    PointArray result(points);
    result.insert(result.end(), peer.points.begin(), peer.points.end());
    return Linear("+", result, (getGradient() + peer.getGradient()), limit);
}

Linear Linear::operator-(const Linear& peer) const {
    PointArray result(points);
    for (PointArray::const_iterator it = peer.points.begin(); it != peer.points.end(); ++it) {
        PointArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Linear("-", result, (getGradient() - peer.getGradient()), limit);
}

int Linear::getPointCount() const {
    return points.size();
}

Point Linear::get(const int index) const {
    Point result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(points.size())) {
        return result;
    }
    return points[index];
}

void Linear::set(const int index, const Point& object) {
    if (index < 0 || index >= limit) {
        return;
    }
    if (index < static_cast<int>(points.size())) {
        // replace existing element
        points[index] = object;
    } else if (index == static_cast<int>(points.size())) {
        // append at end
        points.push_back(object);
    } else {
        // index beyond current size: append at end
        points.push_back(object);
    }
    return;
}

Point Linear::copy() {
    Point self = *this;
    Linear fresh(self.getName(), this->points, self.getGradient(), this->limit);
    return fresh;
}

void Linear::clear() {
    Point::clear();
    limit = DEFAULT_LIMIT;
    points.clear();
    return;
}

std::string Linear::print() const {
    std::stringstream result;
    result << "{｜";
	result << Point::print() << "→";
    result << limit;
	result << "}";
    result << printPoints();
	return result.str();
}

std::string Linear::printRadians() const {
    std::stringstream result;
    result << "{｜";
	result << Point::printRadians() << "→";
    result << limit;
	result << "}";
    result << printPointRadians();
	return result.str();
}

std::string Linear::printPoints() const {
    std::stringstream result; int size = points.size();
    if (size > 0) {
        result << ",sz:";
	    result << points.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << points[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

std::string Linear::printPointRadians() const {
    std::stringstream result; int size = points.size();
    if (size > 0) {
        result << ",sz:";
	    result << points.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << points[i].printRadians() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace shp