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

#include "circuit.h"

namespace ecn {

Circuit::Circuit()
        : Element(), elements() {

}

Circuit::Circuit(const ElementArray& elements)
        : Element(), elements() {

}

Circuit::Circuit(const Resistance& resistance, const ElementArray& elements)
        : Element(resistance), elements() {

}

Circuit::Circuit(const Resistance& resistance, const Capacitance& capacitance,
        const ElementArray& elements)
        : Element(resistance, capacitance), elements() {

}

Circuit::Circuit(const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance, const ElementArray& elements)
        : Element(resistance, capacitance, inductance), elements() {

}

Circuit::Circuit(const std::string name)
        : Element(name), elements() {

}

Circuit::Circuit(std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance)
        : Element(name, resistance, capacitance, inductance), elements() {

}

Circuit::Circuit(const std::string name, const ElementArray& elements)
        : Element(name), elements() {

}

Circuit::Circuit(const std::string name, const Resistance& resistance, const ElementArray& elements)
        : Element(name, resistance), elements() {

}

Circuit::Circuit(const std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const ElementArray& elements)
        : Element(name, resistance, capacitance), elements() {

}

Circuit::Circuit(const std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance, const ElementArray& elements)
        : Element(name, resistance, capacitance, inductance), elements() {

}

Circuit::~Circuit() {

}

bool Circuit::operator==(const Circuit& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
        && (elements == peer.elements);
}

Circuit Circuit::operator+(const Circuit& peer) const {
    Element self = *this, other = peer;
    Element base = (self + other);
    ElementArray result(elements);
    result.insert(result.end(), peer.elements.begin(), peer.elements.end());
    return Circuit("+", base.getResistance(), base.getCapacitance(), base.getInductance(), result);
}

Circuit Circuit::operator-(const Circuit& peer) const {
    Element self = *this, other = peer;
    Element base = (self - other);
    ElementArray result(elements);
    for (ElementArray::const_iterator it = peer.elements.begin(); it != peer.elements.end(); ++it) {
        ElementArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Circuit("-", base.getResistance(), base.getCapacitance(), base.getInductance(), result);
}

int Circuit::getElementCount() const {
    return elements.size();
}

Element Circuit::get(const int index) const {
    Element result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(elements.size())) {
        return result;
    }
    return elements[index];
}

void Circuit::set(const int index, const Element& object) {
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

Circuit Circuit::copy() {
    Circuit fresh(getName(), getResistance(), getCapacitance(), getInductance(), elements);
    return fresh;
}

void Circuit::clear() {
    Element::clear();
    elements.clear();
    return;
}

std::string Circuit::print() {
    std::stringstream result;
    result << Element::print() << ",";
	result << elements.size() << "[";
    for (int i = 0; i < elements.size(); i++) {
        result << "," << elements[i].print() << std::endl;
    }
    result << "]";
    return result.str();
}

} // namespace ecn