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

Planar::Planar()
        : Point(), lines() {

}

Planar::Planar(const float gradient)
        : Point(gradient), lines() {

}

Planar::Planar(std::string name)
        : Point(name), lines() {

}

Planar::Planar(std::string name, const float gradient)
        : Point(name, gradient), lines() {

}

Planar::Planar(std::string name, const LinearArray& lines)
        : Point(name), lines(lines) {

}

Planar::Planar(std::string name, const LinearArray& lines, const float gradient)
        : Point(name, gradient), lines(lines) {

}

Planar::~Planar() {

}

bool Planar::operator==(const Planar& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (lines == peer.lines);
}

Planar Planar::operator+(const Planar& peer) const {
    LinearArray result(lines);
    result.insert(result.end(), peer.lines.begin(), peer.lines.end());
    return Planar("+", result, (getGradient() + peer.getGradient()));
}

Planar Planar::operator-(const Planar& peer) const {
    LinearArray result(lines);
    for (LinearArray::const_iterator it = peer.lines.begin(); it != peer.lines.end(); ++it) {
        LinearArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Planar("-", result, (getGradient() - peer.getGradient()));
}

int Planar::getLineCount() const {
    return lines.size();
}

Linear Planar::get(int index) const {
    Linear result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(lines.size())) {
        return result;
    }
    return lines[index];
}

void Planar::set(int index, const Linear& object) {
    if (index < 0) {
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
    Planar fresh(getName(), lines, getGradient());
    return fresh;
}

void Planar::clear() {
    Point::clear();
    lines.clear();
    return;
}

std::string Planar::print() {
    std::stringstream result;
    result << "{pl";
	result << Point::print() << ",sz:";
	result << lines.size() << "}";
	return result.str();
}

} // namespace shp