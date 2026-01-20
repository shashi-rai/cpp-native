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

Cellular::Cellular() : Point(), shells() {

}

Cellular::Cellular(const float gradient)
        : Point(gradient), shells() {

}

Cellular::Cellular(const Azimuth& gradient)
        : Point(gradient), shells() {

}

Cellular::Cellular(const std::string name)
        : Point(name), shells() {

}

Cellular::Cellular(const std::string name, const float gradient)
        : Point(name, gradient), shells() {

}

Cellular::Cellular(const std::string name, const Azimuth& gradient)
        : Point(name, gradient), shells() {

}

Cellular::Cellular(const std::string name, const ShellArray& shells)
        : Point(name), shells(shells) {

}

Cellular::Cellular(const std::string name, const ShellArray& shells, const float gradient)
        : Point(name, gradient), shells(shells) {

}

Cellular::Cellular(const std::string name, const ShellArray& shells, const Azimuth& gradient)
        : Point(name, gradient), shells(shells) {

}

Cellular::~Cellular() {

}

bool Cellular::operator==(const Cellular& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (shells == peer.shells);
}

Cellular Cellular::operator+(const Cellular& peer) const {
    ShellArray result(shells);
    result.insert(result.end(), peer.shells.begin(), peer.shells.end());
    return Cellular("+", result, (getGradient() + peer.getGradient()));
}

Cellular Cellular::operator-(const Cellular& peer) const {
    ShellArray result(shells);
    for (ShellArray::const_iterator it = peer.shells.begin(); it != peer.shells.end(); ++it) {
        ShellArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Cellular("-", result, (getGradient() - peer.getGradient()));
}

int Cellular::getShellCount() const {
    return shells.size();
}

Shell Cellular::get(const int index) const {
    Shell result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(shells.size())) {
        return result;
    }
    return shells[index];
}

void Cellular::set(const int index, const Shell& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(shells.size())) {
        // replace existing element
        shells[index] = object;
    } else if (index == static_cast<int>(shells.size())) {
        // append at end
        shells.push_back(object);
    } else {
        // index beyond current size: append at end
        shells.push_back(object);
    }
    return;
}

Point Cellular::copy() {
    Point self = *this;
    Cellular fresh(self.getName(), this->shells, self.getGradient());
    return fresh;
}

void Cellular::clear() {
    Point::clear();
    shells.clear();
    return;
}

std::string Cellular::print() const {
    std::stringstream result;
    result << "{ce";
	result << Point::print() << ",sz:";
	result << shells.size() << "}{";
    for (int i = 0; i < shells.size(); i++) {
        result << "\t" << shells[i].print() << std::endl;
    }
    result << "}";
    return result.str();
}

std::string Cellular::printRadians() const {
    std::stringstream result;
    result << "{ce";
	result << Point::printRadians() << ",sz:";
	result << shells.size() << "}{";
    for (int i = 0; i < shells.size(); i++) {
        result << "\t" << shells[i].print() << std::endl;
    }
    result << "}";
    return result.str();
}

} // namespace shp