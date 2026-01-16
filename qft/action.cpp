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
		: Change(), name(), position(), wave() {

}

Action::Action(const std::string name)
        : Change(), name(name), position(), wave() {

}

Action::Action(const shp::Coordinate& location)
        : Change(), name(), position(location), wave() {

}

Action::Action(const shp::Coordinate& location, const shp::Wave& wave)
        : Change(), name(), position(location), wave(wave) {

}

Action::Action(const shp::Signal& potential)
        : Change(potential), name(), position(), wave() {

}

Action::Action(const shp::Signal& dynamical, const shp::Signal& potential)
        : Change(dynamical, potential), name(), position(), wave() {

}

Action::Action(const std::string name, const shp::Signal& potential)
        : Change(potential), name(name), position(), wave() {

}

Action::Action(const std::string name,
        const shp::Signal& dynamical, const shp::Signal& potential)
        : Change(dynamical, potential), name(name), position(), wave() {

}

Action::Action(const std::string name, const shp::Signal& dynamical, const shp::Signal& potential,
        const shp::Coordinate& location)
        : Change(dynamical, potential), name(name), position(location), wave() {

}

Action::Action(const std::string name, const shp::Signal& dynamical, const shp::Signal& potential,
        const shp::Coordinate& location, const shp::Wave& wave)
        : Change(dynamical, potential), name(name), position(location), wave(wave) {

}

Action::Action(const std::string name, const shp::Coordinate& location)
        : Change(), name(name), position(location), wave() {

}

Action::Action(const std::string name, const shp::Coordinate& location, const shp::Wave& wave)
        : Change(), name(name), position(location), wave(wave) {

}

Action::~Action() {

}

bool Action::operator==(const Action& peer) const {
    return (static_cast<const Change&>(*this) == static_cast<const Change&>(peer))
        && (position == peer.position) && (wave == peer.wave) && (name == peer.name);
}

Action Action::operator+(const Action& peer) const {
    shp::Signal dynamical = (getDynamical() + peer.getDynamical());
    shp::Signal potential = (getPotential() + peer.getPotential());
    Action result("+", dynamical, potential, (position + peer.position), (wave + peer.wave));
    return result;
}

Action Action::operator-(const Action& peer) const {
    shp::Signal dynamical = (getDynamical() - peer.getDynamical());
    shp::Signal potential = (getPotential() - peer.getPotential());
    Action result("-", dynamical, potential, (position - peer.position), (wave - peer.wave));
    return result;
}

shp::Signal Action::getTotal() const {
    shp::Signal delta = Change::getLagrangian();
    return shp::Signal(delta.getOrientation(), delta.getMagnitude(), delta.getScaling(), delta.getUnit());
}

shp::Change Action::copy() {
    Action fresh(name, getDynamical(), getPotential(), position, wave);
    return fresh;
}

void Action::clear() {
	shp::Change::clear();
    name.clear();
    position.clear();
    wave.clear();
    return;
}

std::string Action::print() {
    std::stringstream result;
    result << name << ",Δ:";
    result << Change::print() << ",r";
    result << position.print() << ",";
    result << wave.print();
	return result.str();
}

shp::Signal Action::getCosComponent(const float phase) const {
	shp::Signal action = this->getTotal();
	return shp::Signal(action.getOrientation(), action.getCosComponent(phase),
		action.getScaling(), action.getUnit());
}

shp::Signal Action::getSinComponent(const float phase) const {
	shp::Signal action = this->getTotal();
	return shp::Signal(action.getOrientation(), action.getSinComponent(phase),
		action.getScaling(), action.getUnit());
}

} // namespace qft