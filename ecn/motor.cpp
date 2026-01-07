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

#include "motor.h"

namespace ecn {

Motor::Motor()
        : Element(), slip(shp::Quantity::DEFAULT_VALUE), stator(), rotor() {

}

Motor::Motor(const float slip)
        : Element(), slip(slip), stator(), rotor() {

}

Motor::Motor(const Coil& stator)
        : Element(), slip(shp::Quantity::DEFAULT_VALUE), stator(stator), rotor() {

}

Motor::Motor(const float slip, const Coil& stator)
        : Element(), slip(slip), stator(stator), rotor() {

}

Motor::Motor(const Coil& stator, const Coil& rotor)
        : Element(), slip(shp::Quantity::DEFAULT_VALUE), stator(stator), rotor(rotor) {

}

Motor::Motor(const float slip, const Coil& stator, const Coil& rotor)
        : Element(), slip(slip), stator(stator), rotor(rotor) {

}

Motor::Motor(const std::string name)
        : Element(name), slip(shp::Quantity::DEFAULT_VALUE), stator(), rotor() {

}

Motor::Motor(const std::string name, const float slip)
        : Element(name), slip(slip), stator(), rotor() {

}

Motor::Motor(const std::string name, const Coil& stator)
        : Element(name), slip(shp::Quantity::DEFAULT_VALUE), stator(stator), rotor() {

}

Motor::Motor(const std::string name, const float slip, const Coil& stator)
        : Element(name), slip(slip), stator(stator), rotor() {

}

Motor::Motor(const std::string name, const Coil& stator, const Coil& rotor)
        : Element(name), slip(shp::Quantity::DEFAULT_VALUE), stator(stator), rotor(rotor) {

}

Motor::Motor(const std::string name, const float slip, const Coil& stator, const Coil& rotor)
        : Element(name), slip(slip), stator(stator), rotor(rotor) {

}

Motor::~Motor() {

}

bool Motor::operator==(const Motor& peer) const {
    return (static_cast<const Element&>(*this) == static_cast<const Element&>(peer))
       && (slip == peer.slip) && (stator == peer.stator) && (rotor == peer.rotor);
}

Motor Motor::operator+(const Motor& peer) const {
    Element self = *this, other = peer;
    Element base = (self + other);
    return Motor("+", (slip + peer.slip), (stator + peer.stator), (rotor + peer.rotor));
}

Motor Motor::operator-(const Motor& peer) const {
    Element self = *this, other = peer;
    Element base = (self - other);
    return Motor("-", (slip - peer.slip), (stator - peer.stator), (rotor - peer.rotor));
}

Motor Motor::operator*(const Motor& peer) const {
    Element self = *this, other = peer;
    Element base = (self * other);
    return Motor("*", (slip * peer.slip), (stator * peer.stator), (rotor * peer.rotor));
}

Motor Motor::operator/(const Motor& peer) const {
    Element self = *this, other = peer;
    Element base = (self / other);
    return Motor("/", (slip / peer.slip), (stator / peer.stator), (rotor / peer.rotor));
}

Motor Motor::operator%(const Motor& peer) const {
    Element self = *this, other = peer;
    Element base = (self % other);
    return Motor("%", fmod(slip, peer.slip), (stator % peer.stator), (rotor % peer.rotor));
}

float Motor::getTurnsRatio() const {
    float ratio = stator.getLoopCount() / rotor.getLoopCount();
    return ratio;
}

float Motor::getHighVoltageRatio() const {
    float ratio = (stator.getVoltage() / rotor.getVoltage()).getHigh();
    return ratio;
}

float Motor::getLowVoltageRatio() const {
    float ratio = (stator.getVoltage() / rotor.getVoltage()).getLow();
    return ratio;
}

shp::Potential Motor::getRotorVoltage() const {
    float ratio = rotor.getLoopCount() / stator.getLoopCount();
    shp::Potential input = stator.getVoltage();
    short int scaling = input.getScaling();
    shp::Potential fresh((input.getHigh() * ratio * slip), (input.getLow() * ratio * slip),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

Motor Motor::copy() {
    Motor fresh(getName(), slip, stator, rotor);
    return fresh;
}

void Motor::clear() {
    Element::clear();
    slip = shp::Quantity::DEFAULT_VALUE;
    stator.clear();
    rotor.clear();
    return;
}

std::string Motor::print() {
    std::stringstream result;
    result << Element::print() << ",sl:";
    result << slip << ",st:";
    result << stator.print() << ",ro:";
    result << rotor.print();
    return result.str();
}

} // namespace ecn