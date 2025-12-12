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
        : Cellular(), defaultSpin(), defaultMass(), defaultCharge() {
    setPhysical(nullptr);
}

Field::Field(const float spin)
        : Cellular(), defaultSpin(spin), defaultMass(), defaultCharge() {
    setPhysical(nullptr);
}

Field::Field(Spin& spin)
        : Cellular(), defaultSpin(spin), defaultMass(), defaultCharge() {
    setPhysical(nullptr);
}

Field::Field(std::string name)
        : Cellular(name), defaultSpin(), defaultMass(), defaultCharge() {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float spin)
        : Cellular(name), defaultSpin(spin), defaultMass(), defaultCharge() {
    setPhysical(nullptr);
}

Field::Field(std::string name, Spin& spin)
        : Cellular(name), defaultSpin(spin), defaultMass(), defaultCharge() {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float mass, const float charge)
        : Cellular(name), defaultSpin(), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(std::string name, Mass& mass, Charge& charge)
        : Cellular(name), defaultSpin(), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(const float mass, const float charge)
        : Cellular(), defaultSpin(), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(Mass& mass, Charge& charge)
        : Cellular(), defaultSpin(), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(const float spin, const float mass, const float charge)
        : Cellular(), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(Spin& spin, Mass& mass, Charge& charge)
        : Cellular(), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(std::string name, const float spin, const float mass, const float charge)
        : Cellular(name), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(std::string name, Spin& spin, Mass& mass, Charge& charge)
        : Cellular(name), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(nullptr);
}

Field::Field(shp::Shape* physical)
        : Cellular(), defaultSpin(), defaultMass(), defaultCharge() {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical)
        : Cellular(name), defaultSpin(), defaultMass(), defaultCharge() {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical, const float spin)
        : Cellular(name), defaultSpin(spin), defaultMass(), defaultCharge() {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical, Spin& spin)
        : Cellular(name), defaultSpin(spin), defaultMass(), defaultCharge() {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical, const float spin, const float mass)
        : Cellular(name), defaultSpin(spin), defaultMass(mass), defaultCharge() {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical, Spin& spin, Mass& mass)
        : Cellular(name), defaultSpin(spin), defaultMass(mass), defaultCharge() {
    setPhysical(physical);
}

Field::Field(shp::Shape* physical, const float spin, const float mass, const float charge)
        : Cellular(), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(physical);
}

Field::Field(shp::Shape* physical, Spin& spin, Mass& mass, Charge& charge)
        : Cellular(), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical, const float spin, const float mass, const float charge)
        : Cellular(name), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(physical);
}

Field::Field(std::string name, shp::Shape* physical, Spin& spin, Mass& mass, Charge& charge)
        : Cellular(name), defaultSpin(spin), defaultMass(mass), defaultCharge(charge) {
    setPhysical(physical);
}

Field::~Field() {
    setPhysical(nullptr);
}

bool Field::operator==(const Field& peer) const {
    return (static_cast<const Cellular&>(*this) == static_cast<const Cellular&>(peer))
        && (physical == peer.physical)
        && (defaultSpin == peer.defaultSpin)
        && (defaultMass == peer.defaultMass)
        && (defaultCharge == peer.defaultCharge);
}

Field Field::operator+(const Field& peer) const {
    Spin newspin = (defaultSpin + peer.defaultSpin);
    Mass newmass = (defaultMass + peer.defaultMass);
    Charge newcharge = (defaultCharge + peer.defaultCharge);
    return Field("+", newspin, newmass, newcharge);
}

Field Field::operator-(const Field& peer) const {
    Spin newspin = (defaultSpin - peer.defaultSpin);
    Mass newmass = (defaultMass - peer.defaultMass);
    Charge newcharge = (defaultCharge - peer.defaultCharge);
    return Field("-", newspin, newmass, newcharge);
}

bool Field::isStructured() const {
    return physical != nullptr;
}

void Field::changePoint(Action& action) {
    int x = action.getCoordinate().getX();
    int y = action.getCoordinate().getY();
    int z = action.getCoordinate().getZ();
    shp::Wave received = action.getWave();

    // simply replace the existing Point found at specific coordinates
    // with a new Point received from the Action item
    this->get(x).get(y).set(z, received);
    return;
}

Particle* Field::getDivergence(Action& action) const {
    Spin spin = defaultSpin;
    Mass mass = defaultMass;
    Charge charge = defaultCharge;
    // TODO: how is particle destroyed
    Particle* result = new Particle(spin, mass, charge);
    result->setAmplitude(0);
    return result;
}

Particle* Field::getConvergence(Action& action) const {
    Spin spin = defaultSpin;
    Mass mass = defaultMass;
    Charge charge = defaultCharge;
    // TODO: how is particle generated
    Particle* result = new Particle(spin, mass, charge);
    return result;
}

shp::Point Field::copy() {
    Field fresh(physical, defaultSpin, defaultMass, defaultCharge);
    return fresh;
}

void Field::clear() {
    Point::clear();
    defaultSpin.clear();
    defaultMass.clear();
    defaultCharge.clear();
    return;
}

std::string Field::print() {
    std::stringstream result;
    result << "∇";
    result << Cellular::print() << ",";
    result << defaultSpin.print() << ",";
    result << defaultMass.print() << ",";
    result << defaultCharge.print();
	return result.str();
}

} // namespace qft
