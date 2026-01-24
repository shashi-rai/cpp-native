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
        : shp::Temporal(), potential(), orientation() {
    setPhysical(nullptr);
}

Field::Field(const std::string name)
        : shp::Temporal(), potential(), orientation() {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation() {
    setPhysical(physical);
}

Field::Field(const std::string name, const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation() {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const shp::Potential potential)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation() {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential potential,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation() {
    setPhysical(physical);
}

Field::Field(const float azimuth)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const float azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Azimuth& azimuth)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Polar& polar)
        : shp::Temporal(), potential(), orientation(polar) {
    setPhysical(nullptr);
}

Field::Field(const shp::Polar& polar,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(polar) {
    setPhysical(physical);
}

Field::Field(const shp::Polar& polar, const shp::Azimuth& azimuth)
        : shp::Temporal(), potential(), orientation(polar, azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(polar, azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Angular& orientation)
        : shp::Temporal(), potential(), orientation(orientation) {
    setPhysical(nullptr);
}

Field::Field(const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const float potential, const float azimuth)
        : shp::Temporal(potential), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const float potential, const float azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential), potential(potential), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Azimuth& azimuth)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar, azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar, azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Angular& orientation)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(orientation) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const shp::Signal& modulation,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(modulation, potential.getHigh()),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const shp::Signal& modulation, const shp::Azimuth& phase,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(modulation, phase, potential.getHigh()),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh(), unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(magnitude, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(magnitude, scaling, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(phase, magnitude, scaling, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const shp::Signal& modulation, const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(modulation, phase, magnitude, scaling, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const std::string name, const shp::Potential potential)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation() {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential potential,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation() {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const float azimuth)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Azimuth& azimuth)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Polar& polar)
        : shp::Temporal(), potential(), orientation(polar) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : shp::Temporal(), potential(), orientation(polar, azimuth) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const float azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(azimuth) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Polar& polar,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(polar) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(), potential(), orientation(polar, azimuth) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const float potential, const float azimuth)
        : shp::Temporal(potential), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Azimuth& azimuth)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const shp::Azimuth& azimuth)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar, azimuth) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const float potential, const float azimuth,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential), potential(potential), orientation(azimuth) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Azimuth& azimuth, const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(azimuth) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const shp::Azimuth& azimuth, const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(polar, azimuth) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Angular& orientation)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(orientation) {
    setPhysical(nullptr);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Potential& potential,
        const shp::Angular& orientation, const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh()), potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Signal& modulation,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(modulation, potential.getHigh()),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Signal& modulation, const shp::Azimuth& phase,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(modulation, phase, potential.getHigh()),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(potential.getHigh(), unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name,
        const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(magnitude, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(magnitude, scaling, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(phase, magnitude, scaling, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::Field(const std::string name, const shp::Signal& modulation, const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical)
        : shp::Temporal(modulation, phase, magnitude, scaling, unit),
        potential(potential), orientation(orientation) {
    setPhysical(physical);
    setFieldLabel(name);
}

Field::~Field() {
    setPhysical(nullptr);
}

bool Field::operator==(const Field& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (physical == peer.physical)
        && (potential == peer.potential)
        && (orientation == peer.orientation);
}

bool Field::operator<(const Field& peer) const {
    return (static_cast<const shp::Temporal&>(*this) < static_cast<const shp::Temporal&>(peer))
        && (potential < peer.potential)
        && (orientation < peer.orientation);
}

bool Field::operator>(const Field& peer) const {
    return (static_cast<const shp::Temporal&>(*this) > static_cast<const shp::Temporal&>(peer))
        && (potential > peer.potential)
        && (orientation > peer.orientation);
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
    shp::Temporal self = *this, other = peer;
    shp::Potential newpotential = (potential + peer.potential);
    shp::Angular neworientation = (orientation + peer.orientation);
    shp::Temporal field = (self + other);
    return Field("+", field.getWavelengthChange(), field.getAmplitudeChange(),
        field.getMagnitude(), field.getScaling(), field.getUnit(),
        newpotential, neworientation, this->physical);
}

Field Field::operator-(const Field& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Potential newpotential = (potential - peer.potential);
    shp::Angular neworientation = (orientation - peer.orientation);
    shp::Temporal field = (self - other);
    return Field("-", field.getWavelengthChange(), field.getAmplitudeChange(),
        field.getMagnitude(), field.getScaling(), field.getUnit(),
        newpotential, neworientation, this->physical);
}

Field Field::operator*(const Field& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Potential newpotential = (potential * peer.potential);
    shp::Angular neworientation = (orientation * peer.orientation);
    shp::Temporal field = (self * other);
    return Field("*", field.getWavelengthChange(), field.getAmplitudeChange(),
        field.getMagnitude(), field.getScaling(), field.getUnit(),
        newpotential, neworientation, this->physical);
}

Field Field::operator/(const Field& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Potential newpotential = (potential / peer.potential);
    shp::Angular neworientation = (orientation / peer.orientation);
    shp::Temporal field = (self / other);
    return Field("/", field.getWavelengthChange(), field.getAmplitudeChange(),
        field.getMagnitude(), field.getScaling(), field.getUnit(),
        newpotential, neworientation, this->physical);
}

Field Field::operator%(const Field& peer) const {
    shp::Temporal self = *this, other = peer;
    shp::Potential newpotential = (potential % peer.potential);
    shp::Angular neworientation = (orientation % peer.orientation);
    shp::Temporal field = (self % other);
    return Field("%", field.getWavelengthChange(), field.getAmplitudeChange(),
        field.getMagnitude(), field.getScaling(), field.getUnit(),
        newpotential, neworientation, this->physical);
}

shp::Point Field::operator()(const int x, const int y, const int z) {
    shp::Point result;
    if (isStructured()) {
        result = physical->get(x).get(y).get(z);
    }
    return result;
}

const shp::Point Field::operator()(const int x, const int y, const int z) const {
    shp::Point result;
    if (isStructured()) {
        result = physical->get(x).get(y).get(z);
    }
    return result;
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

std::string Field::getFieldLabel() const {
    std::string result;
    if (isStructured()) {
        result = physical->getName();
    }
    return result;
}

void Field::setFieldLabel(const std::string name) {
    if (isStructured()) {
        physical->setName(name);
    }
}

bool Field::isStructured() const {
    return physical != nullptr;
}

shp::Distance Field::getRadius() const {
    return orientation.getRadius().getMagnitude();
}

void Field::setRadius(const shp::Distance& length) {
    orientation.setRadius(length);
}

shp::Direction Field::getLinear() const {
    return orientation.getAzimuth();
}

void Field::setLinear(const shp::Direction& azimuth) {
    this->orientation.setAzimuth(azimuth);
}

shp::Direction Field::getCircular() const {
    return orientation.getPolar();
}

void Field::setCircular(const shp::Direction& azimuth) {
    this->orientation.setPolar(azimuth);
}

void Field::changePoint(const Action& action) {
    int x = action.getPosition().getX();
    int y = action.getPosition().getY();
    int z = action.getPosition().getZ();
    shp::Wave received = action.getWave();

    // simply replace the existing Point found at specific coordinates
    // with a new Point received from the Action item
    if (isStructured()) {
        physical->get(x).get(y).set(z, received);
    }
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
    shp::Signal difference = potential.getDifference();
    shp::Temporal result(difference.getMagnitude(), difference.getScaling(), difference.getUnit());
    return result;
}

shp::Temporal Field::copy() {
    shp::Temporal self = *this;
    Field fresh(this->getFieldLabel(), self.getWavelengthChange(), self.getAmplitudeChange(),
        self.getMagnitude(), self.getScaling(), self.getUnit(),
        this->potential, this->orientation, this->physical);
    return fresh;
}

void Field::clear() {
    shp::Temporal::clear();
    potential.clear();
    orientation.clear();
    setPhysical(nullptr);
    return;
}

std::string Field::print() const {
    std::stringstream result;
    result << "≡";
    result << potential.print() << ",";
    result << orientation.print() << ",";
    result << shp::Temporal::print();
	return result.str();
}

std::string Field::printRadians() const {
    std::stringstream result;
    result << "≡";
    result << potential.printRadians() << ",";
    result << orientation.printRadians() << ",";
    result << shp::Temporal::printRadians();
	return result.str();
}

shp::Temporal Field::getFluctuation(const float phase) const {
	shp::Temporal intensity = this->getTotal();
    intensity.setAmplitudeChange(phase);
	return shp::Temporal(intensity.getMagnitude(), intensity.getScaling(), intensity.getUnit());
}

std::shared_ptr<qft::Field> Field::shareable(const std::string name) {
    std::shared_ptr<qft::Field> result = std::make_shared<qft::Field>(name);
    return result;
}

} // namespace qft
