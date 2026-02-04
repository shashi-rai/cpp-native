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

#include "core.h"

namespace ecn {

Core::Core()
        : qft::Density(), reluctance() {

}

Core::Core(const Reluctance& reluctance)
        : qft::Density(), reluctance(reluctance) {

}

Core::Core(const shp::Signal& modulation)
        : qft::Density(modulation), reluctance() {

}

Core::Core(const Reluctance& reluctance, const shp::Signal& modulation)
        : qft::Density(modulation), reluctance(reluctance) {

}

Core::Core(const std::string name)
        : qft::Density(name), reluctance() {

}

Core::Core(std::string name, const Reluctance& reluctance)
        : qft::Density(name), reluctance(reluctance) {

}

Core::Core(const std::string name, const shp::Signal& modulation)
        : qft::Density(name, modulation), reluctance() {

}

Core::Core(const std::string name, const Reluctance& reluctance, const shp::Signal& modulation)
        : qft::Density(name, modulation), reluctance(reluctance) {

}

Core::~Core() {

}

bool Core::operator==(const Core& peer) const {
    return (static_cast<const qft::Density&>(*this) == static_cast<const qft::Density&>(peer))
        && (reluctance == peer.reluctance);
}

Core Core::operator+(const Core& peer) const {
    return Core("+", (reluctance + peer.reluctance));
}

Core Core::operator-(const Core& peer) const {
    return Core("-", (reluctance - peer.reluctance));
}

Core Core::operator*(const Core& peer) const {
    return Core("*", (reluctance * peer.reluctance));
}

Core Core::operator/(const Core& peer) const {
    return Core("/", (reluctance / peer.reluctance));
}

Core Core::operator%(const Core& peer) const {
    return Core("%", (reluctance % peer.reluctance));
}

qft::Temperature Core::getTemperature() const {
    shp::Signal thermal = qft::Density::getThermal();
    qft::Temperature result(thermal.getMagnitude(), thermal.getScaling(), thermal.getUnit());
    return result;
}

void Core::setTemprature(const qft::Temperature& temperature) {
    qft::Density::setThermal(temperature.getTotal());
}

shp::Signal Core::getScalarFlux() {
    return qft::Density::getScalarFlux();
}

shp::Signal Core::getVectorFlux() {
    return qft::Density::getVectorFlux();
}

shp::Volume Core::getVolume() {
    return qft::Density::getVolume();
}

shp::Distance Core::copy() {
    shp::Signal self = qft::Density::getScalarTotal();
    Core fresh(qft::Density::getName(), this->reluctance, qft::Density::getThermal());
    return fresh;
}

void Core::clear() {
    shp::Medium::clear();
    reluctance.clear();
    return;
}

std::string Core::print() const {
    std::stringstream result;
	result << shp::Medium::print() << ",ℜ:";
    result << reluctance.print();
	return result.str();
}

} // namespace ecn