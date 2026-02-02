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

#include "planar.h"

namespace shp {

const int Planar::DEFAULT_LIMIT = 0;

Planar::Planar()
        : Point(Direction::DEFAULT_RADIANS), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const Azimuth& gradient)
        : Point(gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude)
        : Point(magnitude, Direction::DEFAULT_RADIANS), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const short int scaling)
        : Point(magnitude, scaling, Direction::DEFAULT_RADIANS), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const short int scaling, const std::string unit)
        : Point(magnitude, scaling, unit), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const short int scaling, const Unit& unit)
        : Point(magnitude, scaling, unit), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const Azimuth& gradient)
        : Point(magnitude, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const short int scaling, const Azimuth& gradient)
        : Point(magnitude, scaling, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient)
        : Point(magnitude, scaling, unit, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient)
        : Point(magnitude, scaling, unit, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name)
        : Point(name), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const Azimuth& gradient)
        : Point(name, gradient), lines(), limit(0) {

}

Planar::Planar(const std::string name, const float magnitude)
        : Point(name, magnitude, Direction::DEFAULT_RADIANS), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const short int scaling)
        : Point(name, magnitude, scaling), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const short int scaling, const std::string unit)
        : Point(name, magnitude, scaling, unit), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const short int scaling, const Unit& unit)
        : Point(name, magnitude, scaling, unit), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const Azimuth& gradient)
        : Point(name, magnitude, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const short int scaling, const Azimuth& gradient)
        : Point(name, magnitude, scaling, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient)
        : Point(name, magnitude, scaling, unit, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient)
        : Point(name, magnitude, scaling, unit, gradient), lines(), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const Azimuth& gradient, const int limit)
        : Point(name, gradient), lines(), limit(limit) {

}

Planar::Planar(const std::string name, const LinearArray& lines)
        : Point(name), lines(lines), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const LinearArray& lines, const float gradient)
        : Point(name, gradient), lines(lines), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const LinearArray& lines, const Azimuth& gradient)
        : Point(name, gradient), lines(lines), limit(DEFAULT_LIMIT) {

}

Planar::Planar(const std::string name, const LinearArray& lines, const float gradient, const int limit)
        : Point(name, gradient), lines(lines), limit(limit) {

}

Planar::Planar(const std::string name, const LinearArray& lines, const Azimuth& gradient, const int limit)
        : Point(name, gradient), lines(lines), limit(limit) {

}

Planar::~Planar() {

}

bool Planar::operator==(const Planar& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (limit == peer.limit) && (lines == peer.lines);
}

bool Planar::operator<(const Planar& peer) const {
    return (static_cast<const Point&>(*this) < static_cast<const Point&>(peer))
        && (limit < peer.limit) && (lines < peer.lines);
}

bool Planar::operator>(const Planar& peer) const {
    return (static_cast<const Point&>(*this) > static_cast<const Point&>(peer))
        && (limit > peer.limit) && (lines > peer.lines);
}

bool Planar::operator<=(const Planar& peer) const {
    Planar self = *this;
    return (self < peer) || (self == peer);
}

bool Planar::operator>=(const Planar& peer) const {
    Planar self = *this;
    return (self > peer) || (self == peer);
}

Planar Planar::operator+(const Planar& peer) const {
    LinearArray result(lines);
    result.insert(result.end(), peer.lines.begin(), peer.lines.end());
    return Planar("+", result, (getGradient() + peer.getGradient()), limit);
}

Planar Planar::operator-(const Planar& peer) const {
    LinearArray result(lines);
    for (LinearArray::const_iterator it = peer.lines.begin(); it != peer.lines.end(); ++it) {
        LinearArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Planar("-", result, (getGradient() - peer.getGradient()), limit);
}

int Planar::getLineCount() const {
    return lines.size();
}

Linear Planar::get(const int index) const {
    Linear result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(lines.size())) {
        return result;
    }
    return lines[index];
}

void Planar::set(const int index, const Linear& object) {
    if (index < 0 || index >= limit) {
        return;
    }
    if (index < static_cast<int>(lines.size())) {
        // replace existing element
        lines[index] = object;
    } else if (index == static_cast<int>(lines.size())) {
        // append at end
        lines.push_back(object);
    } else {
        // index beyond current size: append at end
        lines.push_back(object);
    }
    return;
}

Point Planar::copy() {
    Point self = *this;
    Planar fresh(self.getName(), this->lines, self.getGradient(), this->limit);
    return fresh;
}

void Planar::clear() {
    Point::clear();
    limit = DEFAULT_LIMIT;
    lines.clear();
    return;
}

std::string Planar::print() const {
    std::stringstream result;
    result << "{□";
	result << Point::print() << "→";
    result << limit;
	result << "}";
    result << printLines();
	return result.str();
}

std::string Planar::printRadians() const {
    std::stringstream result;
    result << "{□";
	result << Point::printRadians() << "→";
    result << limit;
	result << "}";
    result << printLineRadians();
	return result.str();
}

std::string Planar::printLines() const {
    std::stringstream result; int size = lines.size();
    if (size > 0) {
        result << ",sz:";
	    result << lines.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << lines[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

std::string Planar::printLineRadians() const {
    std::stringstream result; int size = lines.size();
    if (size > 0) {
        result << ",sz:";
	    result << lines.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << lines[i].printRadians() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace shp