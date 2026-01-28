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

#include "magnetic.h"

namespace qft {

Magnetic::Magnetic()
        : Force(), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const Current& current)
        : Force(), current(current) {
    setField(nullptr);
}

Magnetic::Magnetic(const std::string name)
        : Force(name), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const std::string name, const Current& current)
        : Force(name), current(current) {
    setField(nullptr);
}

Magnetic::Magnetic(const std::shared_ptr<Field> field)
        : Force(), current() {
    setField(field);
}

Magnetic::Magnetic(const Current& current, const std::shared_ptr<Field> field)
        : Force(), current(current) {
    setField(field);
}

Magnetic::Magnetic(const std::string name, const std::shared_ptr<Field> field)
        : Force(name), current() {
    setField(field);
}

Magnetic::Magnetic(const std::string name, const Current& current, const std::shared_ptr<Field> field)
        : Force(name), current(current) {
    setField(field);
}

Magnetic::Magnetic(const float magnitude)
        : Force(magnitude), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const float magnitude, const std::shared_ptr<Field> field)
        : Force(magnitude), current() {
    setField(field);
}

Magnetic::Magnetic(const float magnitude, const float direction)
        : Force(magnitude, direction), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction), current() {
    setField(field);
}

Magnetic::Magnetic(const float magnitude, const float direction, const short int scaling)
        : Force(magnitude, direction, scaling), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction, scaling), current() {
    setField(field);
}

Magnetic::Magnetic(const std::string name, const float magnitude)
        : Force(name, magnitude), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const std::string name, const float magnitude,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude), current() {
    setField(field);
}

Magnetic::Magnetic(const std::string name, const float magnitude, const float direction)
        : Force(name, magnitude, direction), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction), current() {
    setField(field);
}

Magnetic::Magnetic(const std::string name, const float magnitude, const float direction,
        const short int scaling)
        : Force(name, magnitude, direction, scaling), current() {
    setField(nullptr);
}

Magnetic::Magnetic(const std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction, scaling), current() {
    setField(field);
}

Magnetic::~Magnetic() {
    setField(nullptr);
}

bool Magnetic::operator==(const Magnetic& peer) const {
    return (static_cast<const Force&>(*this) == static_cast<const Force&>(peer))
        && (field == peer.field) && (current == peer.current);
}

bool Magnetic::isOwned() const {
    return (field != nullptr);
}

const Magnetic Magnetic::getForce(const Magnetic& force, const float multiplier) {
    Magnetic fresh(force.getName(), Current::getLooping(force.getCurrent(), multiplier), force.field);
    return fresh;
}

Force Magnetic::copy() const {
    Magnetic fresh(getName(), current, field);
    return fresh;
}

void Magnetic::clear() {
    Force::clear();
    current.clear();
    setField(nullptr);
    return;
}

std::string Magnetic::print() {
    std::stringstream result;
    result << Force::print() << ",";
    result << current.print() << ",";
    result << (field != nullptr ? field->print() : "");
	return result.str();
}

} // namespace qft