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
        : Cellular(), potential(), direction() {
    setPhysical(nullptr);
}

Field::Field(std::string name)
        : Cellular(name), potential(), direction() {
    setPhysical(nullptr);
}

Field::Field(const std::shared_ptr<shp::Shape> physical)
        : Cellular(), potential(), direction() {
    setPhysical(physical);
}

Field::Field(std::string name, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), direction() {
    setPhysical(physical);
}

Field::Field(const float direction)
        : Cellular(), potential(), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(const shp::Direction& direction)
        : Cellular(), potential(), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(const float potential, const float direction)
        : Cellular(), potential(potential), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(const shp::Potential& potential, const shp::Direction& direction)
        : Cellular(), potential(potential), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float direction)
        : Cellular(name), potential(), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Direction& direction)
        : Cellular(name), potential(), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float direction, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), direction(direction) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Direction& direction, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(), direction(direction) {
    setPhysical(physical);
}

Field::Field(std::string name, const float potential, const float direction)
        : Cellular(name), potential(potential), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const shp::Potential& potential, const shp::Direction& direction)
        : Cellular(name), potential(potential), direction(direction) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float potential, const float direction, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), direction(direction) {
    setPhysical(physical);
}

Field::Field(std::string name, const shp::Potential& potential, const shp::Direction& direction, const std::shared_ptr<shp::Shape> physical)
        : Cellular(name), potential(potential), direction(direction) {
    setPhysical(physical);
}

Field::~Field() {
    setPhysical(nullptr);
}

bool Field::operator==(const Field& peer) const {
    return (static_cast<const Cellular&>(*this) == static_cast<const Cellular&>(peer))
        && (physical == peer.physical)
        && (potential == peer.potential)
        && (direction == peer.direction);
}

Field Field::operator+(const Field& peer) const {
    shp::Potential newpotential = (potential + peer.potential);
    shp::Direction newdirection = (direction + peer.direction);
    return Field("+", newpotential, newdirection);
}

Field Field::operator-(const Field& peer) const {
    shp::Potential newpotential = (potential - peer.potential);
    shp::Direction newdirection = (direction - peer.direction);
    return Field("-", newpotential, newdirection);
}

bool Field::isStructured() const {
    return physical != nullptr;
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

Particle* Field::getDivergence(const Action& action) const {
    // TODO: how is particle destroyed
    Particle* result = new Particle();
    result->setAmplitude(0);
    return result;
}

Particle* Field::getConvergence(const Action& action) const {
    // TODO: how is particle generated
    Particle* result = new Particle();
    return result;
}

shp::Quantity Field::getTotal() const {
    shp::Quantity difference = potential.getDifference();
    shp::Quantity result(difference.getValue(), difference.getScaling(), difference.getUnit());
    return result;
}

shp::Point Field::copy() {
    Field fresh(getName(), potential, direction, physical);
    return fresh;
}

void Field::clear() {
    Cellular::clear();
    potential.clear();
    direction.clear();
    return;
}

std::string Field::print() {
    std::stringstream result;
    result << "∇";
    result << Cellular::print() << ",";
    result << potential.print() << ",";
    result << direction.print();
	return result.str();
}

shp::Quantity Field::getComponent(float phase) const {
	shp::Quantity intensity = getTotal();
	return shp::Quantity((intensity.getValue() * cos(phase)), intensity.getScaling(), intensity.getUnit());
}

} // namespace qft
