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

#include "thermal.h"

namespace qft {

Thermal::Thermal()
        : Force(), heat() {
    setField(nullptr);
}

Thermal::Thermal(const Heat& heat)
        : Force(), heat(heat) {
    setField(nullptr);
}

Thermal::Thermal(const std::string name)
        : Force(name), heat() {
    setField(nullptr);
}

Thermal::Thermal(const std::string name, const Heat& heat)
        : Force(name), heat(heat) {
    setField(nullptr);
}

Thermal::Thermal(const std::shared_ptr<Field> field)
        : Force(), heat() {
    setField(field);
}

Thermal::Thermal(const Heat& heat, const std::shared_ptr<Field> field)
        : Force(), heat(heat) {
    setField(field);
}

Thermal::Thermal(const std::string name, const std::shared_ptr<Field> field)
        : Force(name), heat() {
    setField(field);
}

Thermal::Thermal(const std::string name, const Heat& heat, const std::shared_ptr<Field> field)
        : Force(name), heat(heat) {
    setField(field);
}

Thermal::Thermal(const float magnitude)
        : Force(magnitude), heat() {
    setField(nullptr);
}

Thermal::Thermal(const float magnitude, const std::shared_ptr<Field> field)
        : Force(magnitude), heat() {
    setField(field);
}

Thermal::Thermal(const float magnitude, const float direction)
        : Force(magnitude, direction), heat() {
    setField(nullptr);
}

Thermal::Thermal(const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction), heat() {
    setField(field);
}

Thermal::Thermal(const float magnitude, const float direction, const short int scaling)
        : Force(magnitude, direction, scaling), heat() {
    setField(nullptr);
}

Thermal::Thermal(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field)
        : Force(magnitude, direction, scaling), heat() {
    setField(field);
}

Thermal::Thermal(const std::string name, const float magnitude)
        : Force(name, magnitude), heat() {
    setField(nullptr);
}

Thermal::Thermal(const std::string name, const float magnitude,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude), heat() {
    setField(field);
}

Thermal::Thermal(const std::string name, const float magnitude, const float direction)
        : Force(name, magnitude, direction), heat() {
    setField(nullptr);
}

Thermal::Thermal(const std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction), heat() {
    setField(field);
}

Thermal::Thermal(const std::string name, const float magnitude, const float direction,
        const short int scaling)
        : Force(name, magnitude, direction, scaling), heat() {
    setField(nullptr);
}

Thermal::Thermal(const std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field)
        : Force(name, magnitude, direction, scaling), heat() {
    setField(field);
}

Thermal::~Thermal() {
    setField(nullptr);
}

bool Thermal::operator==(const Thermal& peer) const {
    return (static_cast<const Force&>(*this) == static_cast<const Force&>(peer))
        && (field == peer.field) && (heat == peer.heat);
}

bool Thermal::isOwned() const {
    return (field != nullptr);
}

const Thermal Thermal::getForce(const Thermal& force, const float multiplier) {
    Thermal fresh(force.getName(), Heat::getLooping(force.getHeat(), multiplier), force.field);
    return fresh;
}

Force Thermal::copy() const {
    Thermal fresh(getName(), heat, field);
    return fresh;
}

void Thermal::clear() {
    Force::clear();
    heat.clear();
    setField(nullptr);
    return;
}

std::string Thermal::print() {
    std::stringstream result;
    result << Force::print() << ",";
    result << heat.print() << ",";
    result << (isOwned() ? field->print() : "");
	return result.str();
}

} // namespace qft