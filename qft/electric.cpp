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

#include "electric.h"
#include "acceleration.h"

namespace qft {

Electric::Electric() : Force() {
        setField(nullptr);
}

Electric::Electric(const std::string name)
        : Force(name) {
    setField(nullptr);
}

Electric::Electric(const std::shared_ptr<Field> field)
        : Force() {
    setField(field);
}

Electric::Electric(const std::string name, const std::shared_ptr<Field> field)
        : Force(name) {
    setField(field);
}

Electric::Electric(const float magnitude)
        : Force(magnitude) {
    setField(nullptr);
}

Electric::Electric(const float magnitude, const std::shared_ptr<Field> field)
        : Force(magnitude) {
    setField(field);
}

Electric::Electric(const float magnitude, const float direction)
        : Force(magnitude, direction) {
    setField(nullptr);
}

Electric::Electric(const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction) {
    setField(field);
}

Electric::Electric(const float magnitude, const float direction, const short int scaling)
        : Force(magnitude, direction, scaling) {
    setField(nullptr);
}

Electric::Electric(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction, scaling) {
    setField(field);
}

Electric::Electric(const std::string name, const float magnitude)
        : Force(name, magnitude) {
    setField(nullptr);
}

Electric::Electric(const std::string name, const float magnitude,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude) {
    setField(field);
}

Electric::Electric(const std::string name, const float magnitude, const float direction)
        : Force(name, magnitude, direction) {
    setField(nullptr);
}

Electric::Electric(const std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction) {
    setField(field);
}

Electric::Electric(const std::string name, const float magnitude, const float direction,
        const short int scaling)
        : Force(name, magnitude, direction, scaling) {
    setField(nullptr);
}

Electric::Electric(const std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction, scaling) {
    setField(field);
}

Electric::~Electric() {
    setField(nullptr);
}

bool Electric::operator==(const Electric& peer) const {
    return (static_cast<const Force&>(*this) == static_cast<const Force&>(peer))
        && (field == peer.field);
}

Electric Electric::operator()(const Charge& host, const Charge& peer, const shp::Distance& separation) const {
    shp::Potential potential_host = host.getField()->getPotential();
    shp::Potential potential_peer = peer.getField()->getPotential();
    shp::Signal difference = (potential_host.getDifference() - potential_peer.getDifference());
    shp::Distance distance(difference.getMagnitude(), difference.getScaling(), difference.getUnit());
    Force effect = host(peer, separation, distance);
    shp::Quantity force = effect.getMagnitude();
    return Electric(force.getMagnitude(), effect.getDirection().toRadians(), field);
}

Acceleration Electric::getAcceleration(const Charge& charge) const {
    Acceleration result;
    if (isOwned()) {
        shp::Quantity quantum = (this->getMagnitude() / charge.getMagnitude());
	    result.setDisplacement(quantum.getMagnitude(), quantum.getScaling(), quantum.getUnit());
    } else {
        shp::Quantity quantum = this->getMagnitude();
        result.setDisplacement(quantum.getMagnitude(), quantum.getScaling(), quantum.getUnit());
    }
	result.adjustScaling();
    return result;
}

bool Electric::isOwned() const {
    return (field != nullptr);
}

Force Electric::copy() {
    Electric fresh(getName(), field);
    return fresh;
}

void Electric::clear() {
    Force::clear();
    setField(nullptr);
    return;
}

std::string Electric::print() {
    std::stringstream result;
    result << Force::print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

} // namespace qft