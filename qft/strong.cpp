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

#include "strong.h"

namespace qft {

const short int Strong::RANGE_SCALE = -15;      // femtometer

Strong::Strong()
        : Nuclear() {
    setField(nullptr);
}

Strong::Strong(std::string name)
        : Nuclear(name) {
    setField(nullptr);
}

Strong::Strong(const std::shared_ptr<Field> field)
        : Nuclear() {
    setField(field);
}

Strong::Strong(std::string name, const std::shared_ptr<Field> field)
        : Nuclear(name) {
    setField(field);
}

Strong::Strong(const float magnitude)
        : Nuclear(magnitude) {
    setField(nullptr);
}

Strong::Strong(const float magnitude, const std::shared_ptr<Field> field)
        : Nuclear(magnitude) {
    setField(field);
}

Strong::Strong(const float magnitude, const float direction)
        : Nuclear(magnitude, direction) {
    setField(nullptr);
}

Strong::Strong(const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Nuclear(magnitude, direction) {
    setField(field);
}

Strong::Strong(const float magnitude, const float direction, const short int scaling)
        : Nuclear(magnitude, direction, scaling) {
    setField(nullptr);
}

Strong::Strong(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field)
        : Nuclear(magnitude, direction, scaling) {
    setField(field);
}

Strong::Strong(std::string name, const float magnitude)
        : Nuclear(name, magnitude) {
    setField(nullptr);
}

Strong::Strong(std::string name, const float magnitude, const std::shared_ptr<Field> field)
        : Nuclear(name, magnitude) {
    setField(field);
}

Strong::Strong(std::string name, const float magnitude, const float direction)
        : Nuclear(name, magnitude, direction) {
    setField(nullptr);
}

Strong::Strong(std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field)
        : Nuclear(name, magnitude, direction) {
    setField(field);
}

Strong::Strong(std::string name, const float magnitude, const float direction,
        const short int scaling)
        : Nuclear(name, magnitude, direction, scaling) {
    setField(nullptr);
}

Strong::Strong(std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field)
        : Nuclear(name, magnitude, direction, scaling) {
    setField(field);
}

Strong::~Strong() {
    setField(nullptr);
}

bool Strong::operator==(const Strong& peer) const {
    return (static_cast<const Nuclear&>(*this) == static_cast<const Nuclear&>(peer));
}

Strong Strong::operator()(const Proton& peerX, const Proton& peerY) const {
    return *this;
}

Strong Strong::operator()(const Neutron& peerX, const Neutron& peerY) const {
    return *this;
}

Strong Strong::operator()(const Proton& peerX, const Neutron& peerY) const {
    return *this;
}

Force Strong::copy() {
    Strong fresh(getName(), getField());
    return fresh;
}

void Strong::clear() {
    Nuclear::clear();
    return;
}

std::string Strong::print() {
    std::stringstream result;
    result << Nuclear::print();
	return result.str();
}

} // namespace qft