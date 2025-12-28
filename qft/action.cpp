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

#include "action.h"

namespace qft {

Action::Action()
		: Change(), name(), coordinate(), wave() {

}

Action::Action(std::string name)
        : Change(), name(name), coordinate(), wave() {

}

Action::Action(const shp::Coordinate& location)
        : Change(), name(), coordinate(location), wave() {

}

Action::Action(const shp::Coordinate& location, const shp::Wave& wave)
        : Change(), name(), coordinate(location), wave(wave) {

}

Action::Action(const shp::Quantity& potential)
        : Change(potential), name(), coordinate(), wave() {

}

Action::Action(const shp::Quantity& dynamical, const shp::Quantity& potential)
        : Change(dynamical, potential), name(), coordinate(), wave() {

}

Action::Action(std::string name, const shp::Quantity& potential)
        : Change(potential), name(name), coordinate(), wave() {

}

Action::Action(std::string name,
        const shp::Quantity& dynamical, const shp::Quantity& potential)
        : Change(dynamical, potential), name(name), coordinate(), wave() {

}

Action::Action(std::string name, const shp::Quantity& dynamical, const shp::Quantity& potential,
        const shp::Coordinate& location)
        : Change(dynamical, potential), name(name), coordinate(location), wave() {

}

Action::Action(std::string name, const shp::Quantity& dynamical, const shp::Quantity& potential,
        const shp::Coordinate& location, const shp::Wave& wave)
        : Change(dynamical, potential), name(name), coordinate(location), wave(wave) {

}

Action::Action(std::string name, const shp::Coordinate& location)
        : Change(), name(name), coordinate(location), wave() {

}

Action::Action(std::string name, const shp::Coordinate& location, const shp::Wave& wave)
        : Change(), name(name), coordinate(location), wave(wave) {

}

Action::~Action() {

}

bool Action::operator==(const Action& peer) const {
    return (static_cast<const Change&>(*this) == static_cast<const Change&>(peer))
        && (coordinate == peer.coordinate) && (wave == peer.wave) && (name == peer.name);
}

Action Action::operator+(const Action& peer) const {
    shp::Quantity dynamical = (getDynamical() + peer.getDynamical());
    shp::Quantity potential = (getPotential() + peer.getPotential());
    Action result("+", dynamical, potential, (coordinate + peer.coordinate), (wave + peer.wave));
    return result;
}

Action Action::operator-(const Action& peer) const {
    shp::Quantity dynamical = (getDynamical() - peer.getDynamical());
    shp::Quantity potential = (getPotential() - peer.getPotential());
    Action result("-", dynamical, potential, (coordinate - peer.coordinate), (wave - peer.wave));
    return result;
}

shp::Quantity Action::getTotal() const {
    shp::Quantity delta = Change::getLagrangian();
    return shp::Quantity(delta.getMagnitude(), delta.getScaling(), delta.getUnit());
}

shp::Change Action::copy() {
    Action fresh(name, getDynamical(), getPotential(), coordinate, wave);
    return fresh;
}

void Action::clear() {
	shp::Change::clear();
    name.clear();
    coordinate.clear();
    wave.clear();
    return;
}

std::string Action::print() {
    std::stringstream result;
    result << name << ",Δ:";
    result << Change::print() << ",r";
    result << coordinate.print() << ",";
    result << wave.print();
	return result.str();
}

shp::Quantity Action::getComponent(float phase) const {
	shp::Quantity action = getTotal();
	return shp::Quantity((action.getMagnitude() * cos(phase)), action.getScaling(), action.getUnit());
}

} // namespace qft