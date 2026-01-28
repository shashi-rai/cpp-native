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

#include "power.h"

namespace qft {

const std::string Power::UNIT = "W";                // System International

Power::Power()
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::POWER)),
        energy(), interval() {

}

Power::Power(const std::string name)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::POWER)),
        energy(), interval() {

}

Power::Power(const float energy)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::POWER)),
        energy(energy), interval() {

}

Power::Power(const float energy, const float interval)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::PRESSURE)),
        energy(energy), interval(interval) {

}

Power::Power(const shp::Quantity& energy, const qft::Time& interval)
        : name(), unit(shp::Unit::getDerivedSymbol(shp::Unit::POWER)),
        energy(energy), interval(interval) {

}

Power::Power(const shp::Quantity& energy, const qft::Time& interval,
        const shp::Unit& unit)
        : name(), unit(unit), energy(energy), interval(interval) {

}

Power::Power(const std::string name, const shp::Unit& unit)
        : name(name), unit(unit),
        energy(), interval() {

}

Power::Power(const std::string name, const float energy, const float interval)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::POWER)),
        energy(energy), interval(interval) {

}

Power::Power(const std::string name, const float energy, const float interval,
        const std::string unit)
        : name(name), unit(unit), energy(energy), interval(interval) {

}

Power::Power(const std::string name, const shp::Quantity& energy, const qft::Time& interval)
        : name(name), unit(shp::Unit::getDerivedSymbol(shp::Unit::POWER)),
        energy(energy), interval(interval) {

}

Power::Power(const std::string name, const shp::Quantity& energy, const qft::Time& interval,
        const shp::Unit& unit)
        : name(name), unit(unit), energy(energy), interval(interval) {

}

Power::~Power() {

}

bool Power::operator==(const Power& peer) const {
    return (energy == peer.energy) && (interval == peer.interval) && (unit == peer.unit);
}

Power Power::operator+(const Power& peer) const {
    return Power("+", (energy + peer.energy), (interval + peer.interval), unit);
}

Power Power::operator-(const Power& peer) const {
    return Power("-", (energy - peer.energy), (interval - peer.interval), unit);
}

Power Power::operator*(const Power& peer) const {
    return Power("*", (energy * peer.energy), (interval * peer.interval), unit);
}

Power Power::operator/(const Power& peer) const {
    return Power("/", (energy / peer.energy), (interval / peer.interval), unit);
}

Power Power::operator%(const Power& peer) const {
    return Power("%", (energy % peer.energy), (interval % peer.interval), unit);
}

shp::Signal Power::getTotal() const {
    float power = (energy.getMagnitude() / interval.getMagnitude());
    short int scaling = (energy.getScaling() - interval.getScaling());
    shp::Signal result(power, scaling, unit);
    return result;
}

Power Power::copy() {
    Power fresh(name, energy, interval, unit);
    return fresh;
}

void Power::clear() {
    name.clear();
    unit.clear();
    energy.clear();
    interval.clear();
    return;
}

std::string Power::print() {
    std::stringstream result;
    result << "P:";
    result << name << ",";
    result << energy.print() << ",";
    result << interval.print() << ",";
    result << unit.print();
	return result.str();
}

shp::Signal Power::getCosComponent(const float phase) const {
	shp::Signal power = this->getTotal();
	return shp::Signal(power.getCosComponent(phase), power.getScaling(), power.getUnit());
}

shp::Signal Power::getSinComponent(const float phase) const {
	shp::Signal power = this->getTotal();
	return shp::Signal(power.getSinComponent(phase), power.getScaling(), power.getUnit());
}

} // namespace qft