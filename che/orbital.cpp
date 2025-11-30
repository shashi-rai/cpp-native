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

const int Orbital::ELECTRON_MAX_LIMIT = 2;

Orbital::Orbital() : Polygon("", ELECTRON_MAX_LIMIT) {

}

Orbital::Orbital(std::string name) : Polygon(name, ELECTRON_MAX_LIMIT) {

}

Orbital::Orbital(Electron& left, Electron& right) : Polygon("", ELECTRON_MAX_LIMIT) {
    setLeftSpinor(left);
    setRightSpinor(right);
}

Orbital::Orbital(std::string name, int limit) : Polygon(name, limit) {

}

Orbital::Orbital(std::string name, float gradient, int limit)
    : Polygon(name, gradient, limit) {

}

Orbital::Orbital(std::string name, int limit, Electron& left, Electron& right)
    : Polygon(name, limit) {
    setLeftSpinor(left);
    setRightSpinor(right);
}

Orbital::~Orbital() {

}

int Orbital::getParticleCount() const {
    return this->getWaveCount();
}

Electron& Orbital::getElectron(int magnetic) const {
	shp::WaveArray waves = this->getWaves();
	Electron& result = static_cast<Electron&>(waves[magnetic]);
	return result;
}

void Orbital::setElectron(int magnetic, const Electron& object) {
	Polygon::set(magnetic, object);
	return;
}

void Orbital::clear() {
    Polygon::clear();
    return;
}

std::string Orbital::print() {
    std::stringstream result;
    result << "(O";
	result << Polygon::print() << ")";
	return result.str();
}

} // namespace che