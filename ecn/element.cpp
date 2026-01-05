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

#include "element.h"

namespace ecn {

Element::Element()
        : name(), resistance(), capacitance(), inductance() {

}

Element::Element(const Resistance& resistance)
        : name(), resistance(resistance), capacitance(), inductance() {

}

Element::Element(const Resistance& resistance, const Capacitance& capacitance)
        : name(), resistance(resistance), capacitance(capacitance), inductance() {

}

Element::Element(const Resistance& resistance, const Capacitance& capacitance,
		const Inductance& inductance)
        : name(), resistance(resistance), capacitance(capacitance), inductance(inductance) {

}

Element::Element(std::string name)
        : name(name), resistance(), capacitance(), inductance() {

}

Element::Element(std::string name, const Resistance& resistance)
        : name(name), resistance(resistance), capacitance(), inductance() {

}

Element::Element(std::string name, const Resistance& resistance, const Capacitance& capacitance)
        : name(name), resistance(resistance), capacitance(capacitance), inductance() {

}

Element::Element(std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance)
        : name(name), resistance(resistance), capacitance(capacitance), inductance(inductance) {

}

Element::~Element() {

}

bool Element::operator==(const Element& peer) const {
    return (name == peer.name)
        && (resistance == peer.resistance)
        && (capacitance == peer.capacitance)
        && (inductance == peer.inductance);
}

Element Element::operator+(const Element& peer) const {
    return Element("+", (resistance + peer.resistance),
            (capacitance + peer.capacitance), (inductance + peer.inductance));
}

Element Element::operator-(const Element& peer) const {
    return Element("-", (resistance - peer.resistance),
            (capacitance - peer.capacitance), (inductance - peer.inductance));
}

Element Element::operator*(const Element& peer) const {
    return Element("*", (resistance * peer.resistance),
            (capacitance * peer.capacitance), (inductance * peer.inductance));
}

Element Element::operator/(const Element& peer) const {
    return Element("/", (resistance / peer.resistance),
            (capacitance / peer.capacitance), (inductance / peer.inductance));
}

Element Element::operator%(const Element& peer) const {
    return Element("%", (resistance % peer.resistance),
            (capacitance % peer.capacitance), (inductance % peer.inductance));
}

Element Element::copy() {
    Element fresh(name, resistance, capacitance, inductance);
    return fresh;
}

void Element::clear() {
    name.clear();
    resistance.clear();
    capacitance.clear();
    inductance.clear();
    return;
}

std::string Element::print() {
    std::stringstream result;
    result << "(";
	result << name << ",";
    result << resistance.print() << ",";
    result << capacitance.print() << ",";
    result << inductance.print();
    result << ")";
	return result.str();
}

} // namespace ecn