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

#include "orbital.h"

namespace che {

Orbital::Orbital() : Polygon("", 2), left(), right() {

}

Orbital::Orbital(Electron& left, Electron& right)
    : Polygon("", 2), left(left), right(right) {

}

Orbital::Orbital(std::string name, int limit)
    : Polygon(name, limit), left(), right() {

}

Orbital::Orbital(std::string name, float gradient, int limit)
    : Polygon(name, gradient, limit), left(), right() {

}

Orbital::Orbital(std::string name, int limit, Electron& left, Electron& right)
    : Polygon(name, limit), left(left), right(right) {

}

Orbital::~Orbital() {

}

int Orbital::getParticleCount() const {
    return this->getWaveCount();
}

void Orbital::clear() {
    Polygon::clear();
    return;
}

std::string Orbital::print() {
    std::stringstream result;
    result << "{O:";
	result << Polygon::print() << ",sz:";
    result << "}";
	return result.str();
}

} // namespace che