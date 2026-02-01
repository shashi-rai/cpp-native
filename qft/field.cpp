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

#include "field.h"

namespace qft {

Field::Field()
        : Time(), potential() {

}

Field::Field(const shp::Unit& unit)
        : Time(unit), potential() {

}

Field::Field(const shp::Potential& potential)
        : Time(), potential(potential) {

}

Field::Field(const shp::Distance& radius)
        : Time(), potential(radius) {

}

Field::Field(const shp::Azimuth& azimuth)
        : Time(), potential(azimuth) {

}

Field::Field(const shp::Polar& polar)
        : Time(), potential(polar) {

}

Field::Field(const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(), potential(polar, azimuth) {

}

Field::Field(const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(), potential(radius, polar, azimuth) {

}

Field::Field(const shp::Angular& origin)
        : Time(), potential(origin) {

}

Field::Field(const float magnitude)
        : Time(magnitude), potential() {

}

Field::Field(const float magnitude, const shp::Unit& unit)
        : Time(magnitude, unit), potential() {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Potential& potential)
        : Time(magnitude, unit), potential(potential) {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Distance& radius)
        : Time(magnitude, unit), potential(radius) {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(magnitude, unit), potential(azimuth) {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Polar& polar)
        : Time(magnitude, unit), potential(polar) {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(magnitude, unit), potential(polar, azimuth) {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(magnitude, unit), potential(radius, polar, azimuth) {

}

Field::Field(const float magnitude, const shp::Unit& unit, const shp::Angular& origin)
        : Time(magnitude, unit), potential(origin) {

}

Field::Field(const float magnitude, const short int scaling)
        : Time(magnitude, scaling), potential() {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit)
        : Time(magnitude, scaling, unit), potential() {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Potential& potential)
        : Time(magnitude,scaling, unit), potential(potential) {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius)
        : Time(magnitude,scaling, unit), potential(radius) {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(magnitude,scaling, unit), potential(azimuth) {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar)
        : Time(magnitude, scaling, unit), potential(polar) {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(magnitude, scaling, unit), potential(polar, azimuth) {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(magnitude, scaling, unit), potential(radius, polar, azimuth) {

}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Angular& origin)
        : Time(magnitude, scaling, unit), potential(origin) {

}

Field::Field(const shp::Signal& modulation)
        : Time(modulation), potential() {

}

Field::Field(const shp::Signal& modulation, const float magnitude)
        : Time(modulation, magnitude), potential() {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit)
        : Time(modulation, magnitude, unit), potential() {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Potential& potential)
        : Time(modulation, magnitude, unit), potential(potential) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Distance& radius)
        : Time(modulation, magnitude, unit), potential(radius) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(modulation, magnitude, unit), potential(azimuth) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Polar& polar)
        : Time(modulation, magnitude, unit), potential(polar) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(modulation, magnitude, unit), potential(polar, azimuth) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(modulation, magnitude, unit), potential(radius, polar, azimuth) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Angular& origin)
        : Time(modulation, magnitude, unit), potential(origin) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling)
        : Time(modulation, magnitude, scaling), potential() {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit)
        : Time(modulation, magnitude, scaling, unit), potential() {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Potential& potential)
        : Time(modulation, magnitude,scaling, unit), potential(potential) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius)
        : Time(modulation, magnitude,scaling, unit), potential(radius) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(modulation, magnitude,scaling, unit), potential(azimuth) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar)
        : Time(modulation, magnitude, scaling, unit), potential(polar) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(modulation, magnitude, scaling, unit), potential(polar, azimuth) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(modulation, magnitude, scaling, unit), potential(radius, polar, azimuth) {

}

Field::Field(const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Angular& origin)
        : Time(modulation, magnitude, scaling, unit), potential(origin) {

}

Field::Field(const std::string name, const shp::Unit& unit)
        : Time(name, unit), potential() {

}

Field::Field(const std::string name, const shp::Potential& potential)
        : Time(name), potential(potential) {

}

Field::Field(const std::string name, const shp::Distance& radius)
        : Time(name), potential(radius) {

}

Field::Field(const std::string name, const shp::Azimuth& azimuth)
        : Time(name), potential(azimuth) {

}

Field::Field(const std::string name, const shp::Polar& polar)
        : Time(name), potential(polar) {

}

Field::Field(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name), potential(polar, azimuth) {

}

Field::Field(const std::string name, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name), potential(radius, polar, azimuth) {

}

Field::Field(const std::string name, const shp::Angular& origin)
        : Time(name), potential(origin) {

}

Field::Field(const std::string name, const float magnitude)
        : Time(name, magnitude), potential() {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit)
        : Time(name, magnitude, unit), potential() {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Potential& potential)
        : Time(name, magnitude, unit), potential(potential) {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Distance& radius)
        : Time(name, magnitude, unit), potential(radius) {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(name, magnitude, unit), potential(azimuth) {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Polar& polar)
        : Time(name, magnitude, unit), potential(polar) {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, magnitude, unit), potential(polar, azimuth) {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, magnitude, unit), potential(radius, polar, azimuth) {

}

Field::Field(const std::string name, const float magnitude, const shp::Unit& unit, const shp::Angular& origin)
        : Time(name, magnitude, unit), potential(origin) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling)
        : Time(name, magnitude, scaling), potential() {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit)
        : Time(name, magnitude, scaling, unit), potential() {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Potential& potential)
        : Time(name, magnitude,scaling, unit), potential(potential) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius)
        : Time(name, magnitude,scaling, unit), potential(radius) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(name, magnitude,scaling, unit), potential(azimuth) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar)
        : Time(name, magnitude, scaling, unit), potential(polar) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, magnitude, scaling, unit), potential(polar, azimuth) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, magnitude, scaling, unit), potential(radius, polar, azimuth) {

}

Field::Field(const std::string name, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Angular& origin)
        : Time(name, magnitude, scaling, unit), potential(origin) {

}

Field::Field(const std::string name, const shp::Signal& modulation)
        : Time(name, modulation), potential() {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude)
        : Time(name, modulation, magnitude), potential() {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit)
        : Time(name, modulation, magnitude, unit), potential() {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Potential& potential)
        : Time(name, modulation, magnitude, unit), potential(potential) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Distance& radius)
        : Time(name, modulation, magnitude, unit), potential(radius) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(name, modulation, magnitude, unit), potential(azimuth) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Polar& polar)
        : Time(name, modulation, magnitude, unit), potential(polar) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, modulation, magnitude, unit), potential(polar, azimuth) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, modulation, magnitude, unit), potential(radius, polar, azimuth) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const shp::Unit& unit, const shp::Angular& origin)
        : Time(name, modulation, magnitude, unit), potential(origin) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling)
        : Time(name, modulation, magnitude, scaling), potential() {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit)
        : Time(name, modulation, magnitude, scaling, unit), potential() {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Potential& potential)
        : Time(name, modulation, magnitude,scaling, unit), potential(potential) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius)
        : Time(name, modulation, magnitude,scaling, unit), potential(radius) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Time(name, modulation, magnitude,scaling, unit), potential(azimuth) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar)
        : Time(name, modulation, magnitude, scaling, unit), potential(polar) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, modulation, magnitude, scaling, unit), potential(polar, azimuth) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Time(name, modulation, magnitude, scaling, unit), potential(radius, polar, azimuth) {

}

Field::Field(const std::string name, const shp::Signal& modulation, const float magnitude, const short int scaling, const shp::Unit& unit, const shp::Angular& origin)
        : Time(name, modulation, magnitude, scaling, unit), potential(origin) {

}

Field::~Field() {

}

bool Field::operator==(const Field& peer) const {
    return (static_cast<const Time&>(*this) == static_cast<const Time&>(peer))
        && (potential == peer.potential);
}

bool Field::operator<(const Field& peer) const {
    return (static_cast<const Time&>(*this) < static_cast<const Time&>(peer))
        && (potential < peer.potential);
}

bool Field::operator>(const Field& peer) const {
    return (static_cast<const Time&>(*this) > static_cast<const Time&>(peer))
        && (potential > peer.potential);
}

bool Field::operator<=(const Field& peer) const {
    Field self = *this;
    return (self < peer) || (self == peer);
}

bool Field::operator>=(const Field& peer) const {
    Field self = *this;
    return (self > peer) || (self == peer);
}

Field Field::operator+(const Field& peer) const {
    Time self = *this, other = peer, temporal = (self + other);
    shp::Potential newpotential = (potential + peer.potential);
    return Field("+", temporal.getEntropy(), temporal.getMagnitude(), temporal.getScaling(), temporal.getUnit(),
        newpotential);
}

Field Field::operator-(const Field& peer) const {
    Time self = *this, other = peer, temporal = (self - other);
    shp::Potential newpotential = (potential - peer.potential);
    return Field("-", temporal.getEntropy(), temporal.getMagnitude(), temporal.getScaling(), temporal.getUnit(),
        newpotential);
}

Field Field::operator*(const Field& peer) const {
    Time self = *this, other = peer, temporal = (self * other);
    shp::Potential newpotential = (potential * peer.potential);
    return Field("*", temporal.getEntropy(), temporal.getMagnitude(), temporal.getScaling(), temporal.getUnit(),
        newpotential);
}

Field Field::operator/(const Field& peer) const {
    Time self = *this, other = peer, temporal = (self / other);
    shp::Potential newpotential = (potential / peer.potential);
    return Field("/", temporal.getEntropy(), temporal.getMagnitude(), temporal.getScaling(), temporal.getUnit(),
        newpotential);
}

Field Field::operator%(const Field& peer) const {
    Time self = *this, other = peer, temporal = (self % other);
    shp::Potential newpotential = (potential % peer.potential);
    return Field("%", temporal.getEntropy(), temporal.getMagnitude(), temporal.getScaling(), temporal.getUnit(),
        newpotential);
}

shp::Signal Field::operator()(const Field& peer,
        const shp::Distance& separation, const shp::Distance& position) const {
    shp::Signal result = potential(peer.potential, separation, position);
    result.adjustScaling();
    return result;
}

shp::Signal Field::operator()(const Field& peerX, const Field& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const {
    shp::Signal result = potential(peerX.getPotential(), peerY.getPotential(), separationX, separationY);
    result.adjustScaling();
    return result;
}

shp::Azimuth Field::getSpatialChange() const {
    return Time::getDopplerShift();
}

void Field::setSpatialChange(const shp::Azimuth& curvature) {
    Time::setDopplerShift(curvature);
}

void Field::setSpatialChange(const float motion, const shp::Azimuth& curvature) {
    Time::setDopplerShift(motion, curvature);
}


void Field::setSpatialChange(const float motion, const short int scale,
        const shp::Azimuth& curvature) {
    Time::setDopplerShift(motion, scale, curvature);
}

void Field::setSpatialChange(const float motion, const short int scale, const std::string unit,
        const shp::Azimuth& curvature) {
    Time::setDopplerShift(motion, scale, unit, curvature);
}

void Field::setSpatialChange(const float motion, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& curvature) {
    Time::setDopplerShift(motion, scale, unit, curvature);
}

shp::Azimuth Field::getTemporalChange() const {
    return Time::getPeriodDrift();
}

void Field::setTemporalChange(const shp::Azimuth& phase) {
    Time::setPeriodDrift(phase);
}

void Field::setTemporalChange(const float magnitude) {
    Time::setMagnitude(magnitude);
}

void Field::setTemporalChange(const shp::Signal& signal) {
    Time::setEntropy(signal);
}

void Field::setTemporalChange(const float magnitude, const short int scale) {
    Time::setMagnitude(magnitude, scale);
}

void Field::setTemporalChange(const float magnitude, const short int scale, const std::string unit) {
    Time::setMagnitude(magnitude, scale, unit);
}

void Field::setTemporalChange(const float magnitude, const short int scale, const shp::Unit& unit) {
    Time::setMagnitude(magnitude, scale, unit);
}

shp::Angular Field::getOrigin() const {
    return potential.getOrigin();
}

void Field::setOrigin(const shp::Angular& source) {
    potential.setOrigin(source);
}

shp::Distance Field::getRadius() const {
    return potential.getRadius();
}

void Field::setRadius(const shp::Distance& length) {
    potential.setRadius(length.getMagnitude(), length.getScaling(), length.getUnit());
}

void Field::setRadius(const float length) {
    potential.setRadius(length);
}

void Field::setRadius(const float length, const short int scale) {
    potential.setRadius(length, scale);
}

void Field::setRadius(const float length, const short int scale, const std::string unit) {
    potential.setRadius(length, scale, unit);
}

void Field::setRadius(const float length, const short int scale, const shp::Unit& unit) {
    potential.setRadius(length, scale, unit);
}

shp::Azimuth Field::getLinear() const {
    return potential.getAzimuthOrientation();
}

void Field::setLinear(const shp::Azimuth& orientation) {
    this->potential.setAzimuthOrientation(orientation);
}

shp::Polar Field::getCircular() const {
    return potential.getPolarOrientation();
}

void Field::setCircular(const shp::Polar& orientation) {
    this->potential.setPolarOrientation(orientation);
}

void Field::changePoint(const Action& action) {
    shp::Distance x = action.getPosition().getX();
    shp::Distance y = action.getPosition().getY();
    shp::Distance z = action.getPosition().getZ();
    shp::Wave received = action.getWave();

    // simply replace the existing Point found at specific coordinates
    // with a new Point received from the Action item
    return;
}

std::shared_ptr<Particle> Field::getDivergence(const Action& action) const {
    // TODO: how is particle destroyed
    std::shared_ptr<Particle> result = std::make_shared<Particle>();
    result->setMagnitude(0);
    return result;
}

std::shared_ptr<Particle> Field::getConvergence(const Action& action) const {
    // TODO: how is particle generated
    std::shared_ptr<Particle> result = std::make_shared<Particle>();
    result->setMagnitude(0);
    return result;
}

shp::Temporal Field::getTotal() const {
	Time self = *this, difference = potential.getDifference();
    return shp::Temporal(difference.getPeriodDrift(), difference.getMagnitude(), difference.getScaling(), difference.getUnit());
}

Time Field::copy() {
    Time self = *this;
    Field fresh(Time::getName(), self.getEntropy(), self.getMagnitude(), self.getScaling(), self.getUnit(),
        this->potential);
    return fresh;
}

void Field::clear() {
    Time::clear();
    potential.clear();
    return;
}

std::string Field::print() const {
    std::stringstream result;
    result << "≡";
    result << potential.print() << ",";
    result << Time::print();
	return result.str();
}

std::string Field::printRadians() const {
    std::stringstream result;
    result << "≡";
    result << potential.printRadians() << ",";
    result << Time::printRadians();
	return result.str();
}

Time Field::getFluctuation(const float phase) const {
	shp::Temporal temporal = this->getTotal();
    temporal.setIntensityDrift(shp::Azimuth(phase));
	return Time(Time::getName(), temporal.getMagnitude(), temporal.getScaling(), temporal.getUnit());
}

std::shared_ptr<qft::Field> Field::shareable(const std::string name) {
    std::shared_ptr<qft::Field> result = std::make_shared<qft::Field>(name);
    return result;
}

} // namespace qft
