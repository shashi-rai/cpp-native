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

#include "feedback.h"

namespace con {

Feedback::Feedback()
        : Behaviour(), modulation() {

}

Feedback::Feedback(const shp::Signal& modulation)
        : Behaviour(), modulation(modulation) {

}

Feedback::Feedback(const std::string name)
        : Behaviour(name), modulation() {

}

Feedback::Feedback(const std::string name, const shp::Signal& modulation)
        : Behaviour(name), modulation(modulation) {

}

Feedback::~Feedback() {

}

bool Feedback::operator==(const Feedback& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (modulation == peer.modulation);
}

Feedback Feedback::operator+(const Feedback& peer) const {
    return Feedback("+", (modulation + peer.modulation));
}

Feedback Feedback::operator-(const Feedback& peer) const {
    return Feedback("-", (modulation - peer.modulation));
}

Feedback Feedback::operator*(const Feedback& peer) const {
    return Feedback("*", (modulation * peer.modulation));
}

Feedback Feedback::operator/(const Feedback& peer) const {
    return Feedback("/", (modulation / peer.modulation));
}

Feedback Feedback::operator%(const Feedback& peer) const {
    return Feedback("%", (modulation % peer.modulation));
}

std::string Feedback::getName() const {
    return Behaviour::getName();
}

void Feedback::setName(const std::string name) {
    Behaviour::setName(name);
}

Feedback Feedback::copy() const {
    Feedback fresh(this->getName(), this->modulation);
    return fresh;
}

void Feedback::clear() {
    Behaviour::clear();
    modulation.clear();
    return;
}

std::string Feedback::print() const {
    std::stringstream result;
    result << "f:";
	result << Behaviour::print() << ",";
    result << modulation.print();
	return result.str();
}

} // namespace con