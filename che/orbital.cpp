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
const int Orbital::ELECTRON_LIMIT[] = { 2, 6, 10, 14 };
const std::string Orbital::NAME[] = { "s", "p", "d", "f" };

Orbital::Orbital() : Polygon("", ELECTRON_MAX_LIMIT) {

}

Orbital::Orbital(std::string name) : Polygon(name, ELECTRON_MAX_LIMIT) {

}

Orbital::Orbital(
        const std::shared_ptr<che::Electron> left,
        const std::shared_ptr<che::Electron> right)
        : Polygon("", ELECTRON_MAX_LIMIT) {
    setLeftSpinor(left);
    setRightSpinor(right);
}

Orbital::Orbital(std::string name, int limit) : Polygon(name, limit) {

}

Orbital::Orbital(std::string name, float gradient, int limit)
    : Polygon(name, gradient, limit) {

}

Orbital::Orbital(std::string name, int limit,
        const std::shared_ptr<che::Electron> left,
        const std::shared_ptr<che::Electron> right)
        : Polygon(name, limit) {
    setLeftSpinor(left);
    setRightSpinor(right);
}

Orbital::~Orbital() {

}

bool Orbital::operator==(const Orbital& peer) const {
    Electron left = getLeftSpinor(),
        peerleft = peer.getLeftSpinor();
    Electron right = getRightSpinor(),
        peerright = peer.getRightSpinor();
    return (left == left) && (peerleft == peerright);
}

// TODO: Electron assignment to be corrected
Orbital Orbital::operator+(const Orbital& peer) const {
    std::shared_ptr<che::Electron> left =
        std::make_shared<che::Electron>(getLeftSpinor());
    std::shared_ptr<che::Electron> peerleft =
        std::make_shared<che::Electron>(peer.getLeftSpinor());
    std::shared_ptr<che::Electron> right =
        std::make_shared<che::Electron>(getRightSpinor());
    std::shared_ptr<che::Electron> peerright =
        std::make_shared<che::Electron>(peer.getRightSpinor());
    return Orbital("+", ELECTRON_MAX_LIMIT, left, peerright);
}

// TODO: Electron assignment to be corrected
Orbital Orbital::operator-(const Orbital& peer) const {
    std::shared_ptr<che::Electron> left =
        std::make_shared<che::Electron>(getLeftSpinor());
    std::shared_ptr<che::Electron> peerleft =
        std::make_shared<che::Electron>(peer.getLeftSpinor());
    std::shared_ptr<che::Electron> right =
        std::make_shared<che::Electron>(getRightSpinor());
    std::shared_ptr<che::Electron> peerright =
        std::make_shared<che::Electron>(peer.getRightSpinor());
    return Orbital("-", ELECTRON_MAX_LIMIT, left, peerright);
}

int Orbital::getParticleCount() const {
    return this->getWaveCount();
}

Electron Orbital::getElectron(int magnetic) const {
	Electron result;
	shp::WaveArray electrons = this->getWaves();
	if (this->getParticleCount() > 0) {
        result = static_cast<Electron&>(electrons[magnetic]);
	}
	return result;
}

void Orbital::setElectron(int magnetic, const std::shared_ptr<che::Electron> object) {
	Polygon::set(magnetic, *object);
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