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

Linear::Linear()
        : Point(), points() {

}

Linear::Linear(const float gradient)
        : Point(gradient), points() {

}

Linear::Linear(const Azimuth& gradient)
        : Point(gradient), points() {

}

Linear::Linear(const std::string name)
        : Point(name), points() {

}

Linear::Linear(const std::string name, const float gradient)
        : Point(name, gradient), points() {

}

Linear::Linear(const std::string name, const Azimuth& gradient)
        : Point(name, gradient), points() {

}

Linear::Linear(const std::string name, const PointArray& objects)
        : Point(name), points(objects) {

}

Linear::Linear(const std::string name, const PointArray& objects, const float gradient)
        : Point(name, gradient), points(objects) {

}

Linear::Linear(const std::string name, const PointArray& objects, const Azimuth& gradient)
        : Point(name, gradient), points(objects) {

}

Linear::~Linear() {

}

bool Linear::operator==(const Linear& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (points == peer.points);
}

Linear Linear::operator+(const Linear& peer) const {
    PointArray result(points);
    result.insert(result.end(), peer.points.begin(), peer.points.end());
    return Linear("+", result, (getGradient() + peer.getGradient()));
}

Linear Linear::operator-(const Linear& peer) const {
    PointArray result(points);
    for (PointArray::const_iterator it = peer.points.begin(); it != peer.points.end(); ++it) {
        PointArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Linear("-", result, (getGradient() - peer.getGradient()));
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
    if (index < 0) {
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
    Linear fresh(self.getName(), this->points, self.getGradient());
    return fresh;
}

void Linear::clear() {
    Point::clear();
    points.clear();
    return;
}

std::string Linear::print() const {
    std::stringstream result;
    result << "{li";
	result << Point::print() << ",sz:";
	result << points.size() << "}";
	return result.str();
}

} // namespace shp