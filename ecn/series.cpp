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

#include "series.h"

namespace ecn {

Series::Series()
        : Circuit(), elements() {

}

Series::Series(const CircuitArray& elements)
        : Circuit(), elements(elements) {

}

Series::Series(const Conductor& positive, const Conductor& negative)
        : Circuit(positive, negative), elements() {

}

Series::Series(const Conductor& positive, const Conductor& negative, const CircuitArray& elements)
        : Circuit(positive, negative), elements(elements) {

}

Series::Series(const std::string name)
        : Circuit(name) {

}

Series::Series(const std::string name, const CircuitArray& elements)
        : Circuit(name), elements(elements) {

}

Series::Series(const std::string name, const Conductor& positive, const Conductor& negative)
        : Circuit(name, positive, negative), elements() {

}

Series::Series(const std::string name, const Conductor& positive, const Conductor& negative,
        const CircuitArray& elements)
        : Circuit(name, positive, negative), elements(elements) {

}

Series::~Series() {
    elements.clear();
}

bool Series::operator==(const Series& peer) const {
    return (static_cast<const Circuit&>(*this) == static_cast<const Circuit&>(peer))
        && (elements == peer.elements);
}

Series Series::operator+(const Series& peer) const {
    Circuit self = *this, other = peer;
    Circuit series = (self + other);
    CircuitArray result(elements);
    result.insert(result.end(), peer.elements.begin(), peer.elements.end());
    return Series("+", series.getPositive(), series.getNegative(), result);
}

Series Series::operator-(const Series& peer) const {
    Circuit self = *this, other = peer;
    Circuit series = (self - other);
    CircuitArray result(elements);
    for (CircuitArray::const_iterator it = peer.elements.begin(); it != peer.elements.end(); ++it) {
        CircuitArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Series("-", series.getPositive(), series.getNegative(), result);
}

int Series::getElementCount() const {
    return elements.size();
}

Circuit Series::get(const int index) const {
    Circuit result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(elements.size())) {
        return result;
    }
    return elements[index];
}

void Series::set(const int index, const Circuit& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(elements.size())) {
        // replace existing element
        elements[index] = object;
    } else if (index == static_cast<int>(elements.size())) {
        // append at end
        elements.push_back(object);
    } else {
        // index beyond current size: append at end
        elements.push_back(object);
    }
    return;
}

shp::Potential Series::getPotential() const {
    shp::Potential result;
    for (int i = 0; i < elements.size(); i++) {
        result = (result + elements[i].getVoltage());
    }
    shp::Potential fresh(result.getHigh(), result.getLow(), result.getScaling(), result.getUnit());
    return fresh;
}

Circuit Series::copy() {
    Series fresh(getName(), getPositive(), getNegative(), elements);
    return fresh;
}

void Series::clear() {
    Circuit::clear();
    elements.clear();
    return;
}

std::string Series::print() {
    std::stringstream result;
    result << Circuit::print() << ",Σ";
	result << elements.size() << "[";
    for (int i = 0; i < elements.size(); i++) {
        result << "," << elements[i].print() << std::endl;
    }
    result << "]";
    return result.str();
}

} // namespace ecn