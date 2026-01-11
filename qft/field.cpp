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
        : Cellular(), potential(), orientation() {
    setPhysical(nullptr);
}

Field::Field(std::string name)
        : Cellular(name), potential(), orientation() {
    setPhysical(nullptr);
}

Field::Field(const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), orientation() {
    setPhysical(physical);
}

Field::Field(std::string name, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), orientation() {
    setPhysical(physical);
}

Field::Field(shp::Potential potential)
        : Cellular(), potential(potential), orientation() {
    setPhysical(nullptr);
}

Field::Field(shp::Potential potential,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(potential), orientation() {
    setPhysical(physical);
}

Field::Field(const float azimuth)
        : Cellular(), potential(), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const float azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Azimuth& azimuth)
        : Cellular(), potential(), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Polar& polar)
        : Cellular(), potential(), orientation(polar) {
    setPhysical(nullptr);
}

Field::Field(const shp::Polar& polar,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), orientation(polar) {
    setPhysical(physical);
}

Field::Field(const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Cellular(), potential(), orientation(polar, azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), orientation(polar, azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Angular& orientation)
        : Cellular(), potential(), orientation(orientation) {
    setPhysical(nullptr);
}

Field::Field(const shp::Angular& orientation,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(const float potential, const float azimuth)
        : Cellular(), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const float potential, const float azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(potential), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Azimuth& azimuth)
        : Cellular(), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(potential), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar)
        : Cellular(), potential(potential), orientation(polar) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(potential), orientation(polar) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Cellular(), potential(potential), orientation(polar, azimuth) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(potential), orientation(polar, azimuth) {
    setPhysical(physical);
}

Field::Field(const shp::Potential& potential, const shp::Angular& orientation)
        : Cellular(), potential(potential), orientation(orientation) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Potential potential)
        : Cellular(name), potential(potential), orientation() {
    setPhysical(nullptr);
}

Field::Field(std::string name, shp::Potential potential,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), orientation() {
    setPhysical(physical);
}

Field::Field(std::string name, const float azimuth)
        : Cellular(name), potential(), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Azimuth& azimuth)
        : Cellular(name), potential(), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Polar& polar)
        : Cellular(name), potential(), orientation(polar) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Cellular(name), potential(), orientation(polar, azimuth) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Polar& polar,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), orientation(polar) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), orientation(polar, azimuth) {
    setPhysical(physical);
}

Field::Field(std::string name, const float potential, const float azimuth)
        : Cellular(name), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Azimuth& azimuth)
        : Cellular(name), potential(potential), orientation(azimuth) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Polar& polar)
        : Cellular(name), potential(potential), orientation(polar) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Cellular(name), potential(potential), orientation(polar, azimuth) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float potential, const float azimuth,
        const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Azimuth& azimuth, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), orientation(azimuth) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), orientation(polar) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const shp::Azimuth& azimuth, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), orientation(polar, azimuth) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Angular& orientation)
        : Cellular(name), potential(potential), orientation(orientation) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Potential& potential,
        const shp::Angular& orientation, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), orientation(orientation) {
    setPhysical(physical);
}

Field::~Field() {
    setPhysical(nullptr);
}

bool Field::operator==(const Field& peer) const {
    return (static_cast<const Cellular&>(*this) == static_cast<const Cellular&>(peer))
        && (physical == peer.physical)
        && (potential == peer.potential)
        && (orientation == peer.orientation);
}

Field Field::operator+(const Field& peer) const {
    shp::Potential newpotential = (potential + peer.potential);
    shp::Angular neworientation = (orientation + peer.orientation);
    return Field("+", newpotential, neworientation);
}

Field Field::operator-(const Field& peer) const {
    shp::Potential newpotential = (potential - peer.potential);
    shp::Angular neworientation = (orientation - peer.orientation);
    return Field("-", newpotential, neworientation);
}

Field Field::operator*(const Field& peer) const {
    shp::Potential newpotential = (potential * peer.potential);
    shp::Angular neworientation = (orientation * peer.orientation);
    return Field("*", newpotential, neworientation);
}

Field Field::operator/(const Field& peer) const {
    shp::Potential newpotential = (potential / peer.potential);
    shp::Angular neworientation = (orientation / peer.orientation);
    return Field("/", newpotential, neworientation);
}

Field Field::operator%(const Field& peer) const {
    shp::Potential newpotential = (potential % peer.potential);
    shp::Angular neworientation = (orientation % peer.orientation);
    return Field("%", newpotential, neworientation);
}

shp::Quantity Field::operator()(const Field& peer,
        const shp::Distance& separation, const shp::Distance& position) const {
    shp::Quantity result = potential(peer.potential, separation, position);
    result.adjustScaling();
    return result;
}

shp::Quantity Field::operator()(const Field& peerX, const Field& peerY,
    const shp::Distance& separationX, const shp::Distance& separationY) const {
    shp::Quantity result = potential(peerX.getPotential(), peerY.getPotential(), separationX, separationY);
    result.adjustScaling();
    return result;
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
    int x = action.getCoordinate().getX();
    int y = action.getCoordinate().getY();
    int z = action.getCoordinate().getZ();
    shp::Wave received = action.getWave();

    // simply replace the existing Point found at specific coordinates
    // with a new Point received from the Action item
    this->get(x).get(y).set(z, received);
    return;
}

std::shared_ptr<Particle> Field::getDivergence(const Action& action) const {
    // TODO: how is particle destroyed
    std::shared_ptr<Particle> result = std::make_shared<Particle>();
    result->setAmplitude(0);
    return result;
}

std::shared_ptr<Particle> Field::getConvergence(const Action& action) const {
    // TODO: how is particle generated
    std::shared_ptr<Particle> result = std::make_shared<Particle>();
    result->setAmplitude(0);
    return result;
}

shp::Temporal Field::getTotal() const {
    shp::Quantity difference = potential.getDifference();
    shp::Temporal result(difference.getMagnitude(), difference.getScaling(), difference.getUnit());
    return result;
}

shp::Point Field::copy() const {
    Field fresh(getName(), potential, orientation, physical);
    return fresh;
}

void Field::clear() {
    Cellular::clear();
    potential.clear();
    orientation.clear();
    return;
}

std::string Field::print() {
    std::stringstream result;
    result << "∇";
    result << potential.print() << ",";
    result << orientation.print() << ",";
    result << Cellular::print();
	return result.str();
}

shp::Temporal Field::getFluctuation(const float phase) const {
	shp::Temporal intensity = getTotal();
    intensity.setPhase(phase);
	return shp::Temporal(intensity.getMagnitude(), intensity.getScaling(), intensity.getUnit());
}

std::shared_ptr<qft::Field> Field::shareable(std::string name) {
    std::shared_ptr<qft::Field> result = std::make_shared<qft::Field>(name);
    return result;
}

} // namespace qft
