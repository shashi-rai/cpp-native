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

#include "resistor.h"

namespace ecn {

Resistor::Resistor()
        : Element() {

}

Resistor::Resistor(const std::string name)
        : Element(name) {

}

Resistor::Resistor(std::string name, const Resistance& resistance, const Capacitance& capacitance,
        const Inductance& inductance)
        : Element(name, resistance, capacitance, inductance) {

}

Resistor::~Resistor() {

}

bool Resistor::operator==(const Resistor& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer));
}

Resistor Resistor::operator+(const Resistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self + other);
    return Resistor("+", result.getResistance(), result.getCapacitance(), result.getInductance());
}

Resistor Resistor::operator-(const Resistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self - other);
    return Resistor("-", result.getResistance(), result.getCapacitance(), result.getInductance());
}

Resistor Resistor::operator*(const Resistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self * other);
    return Resistor("*", result.getResistance(), result.getCapacitance(), result.getInductance());
}

Resistor Resistor::operator/(const Resistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self / other);
    return Resistor("/", result.getResistance(), result.getCapacitance(), result.getInductance());
}

Resistor Resistor::operator%(const Resistor& peer) const {
    Element self = *this, other = peer;
    Element result = (self % other);
    return Resistor("%", result.getResistance(), result.getCapacitance(), result.getInductance());
}

Resistor Resistor::copy() {
    Resistor fresh(getName(), getResistance(), getCapacitance(), getInductance());
    return fresh;
}

void Resistor::clear() {
    Element::clear();
    return;
}

std::string Resistor::print() {
    std::stringstream result;
    result << Element::print();
	return result.str();
}

} // namespace ecn