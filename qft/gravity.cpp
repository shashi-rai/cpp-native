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

#include "gravity.h"
#include "acceleration.h"

namespace qft {

Gravity::Gravity() : Force() {
    setField(nullptr);
}

Gravity::Gravity(const std::string name)
        : Force(name) {
    setField(nullptr);
}

Gravity::Gravity(const std::shared_ptr<Field> field)
        : Force() {
    setField(field);
}

Gravity::Gravity(const std::string name, const std::shared_ptr<Field> field)
        : Force(name) {
    setField(field);
}

Gravity::Gravity(const float magnitude) : Force(magnitude) {
    setField(nullptr);
}

Gravity::Gravity(const float magnitude, const std::shared_ptr<Field> field)
        : Force(magnitude) {
    setField(field);
}

Gravity::Gravity(const float magnitude, const float direction)
        : Force(magnitude, direction) {
    setField(nullptr);
}

Gravity::Gravity(const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction) {
    setField(field);
}

Gravity::Gravity(const float magnitude, const float direction, const short int scaling)
        : Force(magnitude, direction, scaling) {
    setField(nullptr);
}

Gravity::Gravity(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction, scaling) {
    setField(field);
}

Gravity::Gravity(const std::string name, const float magnitude)
        : Force(name, magnitude) {
    setField(nullptr);
}

Gravity::Gravity(const std::string name, const float magnitude,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude) {
    setField(field);
}

Gravity::Gravity(const std::string name, const float magnitude, const float direction)
        : Force(name, magnitude, direction) {
    setField(nullptr);
}

Gravity::Gravity(const std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction) {
    setField(field);
}

Gravity::Gravity(const std::string name, const float magnitude, const float direction,
        const short int scaling)
        : Force(name, magnitude, direction, scaling) {
    setField(nullptr);
}

Gravity::Gravity(const std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction, scaling) {
    setField(field);
}

Gravity::~Gravity() {
    setField(nullptr);
}

bool Gravity::operator==(const Gravity& peer) const {
    return (static_cast<const Force&>(*this) == static_cast<const Force&>(peer))
        && (field == peer.field);
}

Gravity Gravity::operator()(const Mass& host, const Mass& peer, const shp::Distance& separation) const {
    shp::Potential potential_host = host.getField()->getPotential();
    shp::Potential potential_peer = peer.getField()->getPotential();
    shp::Signal difference = (potential_host.getDifference() - potential_peer.getDifference());
    shp::Distance distance(difference.getMagnitude(), difference.getScaling(), difference.getUnit());
    Force effect = host(peer, separation, distance);
    shp::Quantity force = effect.getMagnitude();
    return Gravity(force.getMagnitude(), effect.getDirection().toRadians(), field);
}

Acceleration Gravity::getAcceleration(const Mass& mass) const {
    Acceleration result;
    if (isOwned()) {
	    result = Force::getAcceleration(mass);
    } else {
        result = Force::getAcceleration(0);
    }
	result.adjustScaling();
    return result;
}

bool Gravity::isOwned() const {
    return (field != nullptr);
}

Force Gravity::copy() {
    Gravity fresh(getName(), field);
    return fresh;
}

void Gravity::clear() {
    Force::clear();
    setField(nullptr);
    return;
}

std::string Gravity::print() {
    std::stringstream result;
    result << Force::print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

} // namespace qft